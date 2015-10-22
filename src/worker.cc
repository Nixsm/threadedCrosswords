#include "worker.h"

const Point2U NoDirection = Point2U(unsigned(-1), unsigned(-1));
const Point2U Up = Point2U(0, 1);
const Point2U Down = Point2U(0, -1);
const Point2U Right = Point2U(1, 0);
const Point2U Left = Point2U(-1, 0);
const Point2U UpRight = Up + Right;
const Point2U UpLeft = Up + Left;
const Point2U DownRight = Down + Right;
const Point2U DownLeft = Down + Left;

std::vector<Point2U> directions = {Up, Down, Right, Left, UpRight, UpLeft, DownLeft, DownRight};

Worker::Worker(const std::string& toSearch, const std::shared_ptr<Matrix<char> >& crossword)
    :_crossword(crossword), _visited(std::make_shared<Matrix<bool> >(crossword->rows(), crossword->cols())), _search(toSearch)
{
    for (auto i = 0u; i < crossword->rows(); ++i) {
        for (auto j = 0u; j < crossword->cols(); ++j) {
            _visited->set(i, j, false);
        }
    }
    
    _thread = std::thread(&Worker::work, this);

    //t.join();
}

Point2U findFirstLetter(const std::shared_ptr<Matrix<char> >& crossword, const std::shared_ptr<Matrix<bool> >& visited, const char& first) {
    Point2U curr(unsigned(-1), unsigned(-1)); // Returns unsgined(-1), unsigned(-1) if fails to find
    for (unsigned i = 0; i < crossword->rows(); ++i) {
        for (unsigned j = 0; j < crossword->cols(); ++j) {
            if (crossword->get(i, j) == first && !visited->get(i, j)) { // Check if we found our first letter
                curr.setX(i); curr.setY(j);
                return curr;
            }
        }
    }

    return curr;
}

Point2U getDirection(const Point2U& currPos, const std::string& word, const std::shared_ptr<Matrix<char> >& crossword) {
    for (auto dir : directions) {
        if (crossword->valid(currPos + dir)) {
            if (crossword->get(currPos + dir) == word.at(1)) { // get the direction related to the second letter of the word
                return dir;
            }
        }
    }
    return NoDirection;
}

void Worker::join() {
    _thread.join();
}

void Worker::work() {
    char letter = _search.at(0);

    Point2U first, curr;

    for (auto i = 0u; i < _crossword->rows(); ++i) {
        for (auto j = 0u; j < _crossword->cols(); ++j) {
            if (letter == std::tolower(_crossword->get(i, j))) {
                first = Point2U(i, j);

                std::vector<Point2U> letters;

                for (auto dir : directions) {
                    auto aux = first + dir;
                    if (_crossword->valid(aux))
                        if (std::tolower(_crossword->get(aux)) == _search.at(1)) { // Try against the second char
                            letters.push_back(first);
                            for (auto i = 1u; i < _search.size(); ++i) {
                                if (_crossword->valid(aux)) {
                                    if (std::tolower(_crossword->get(aux)) != _search.at(i)) {
                                        letters.clear();
                                        break;
                                    }
                                
                                    letters.push_back(aux);
                                }
                                aux = aux + dir;
                            }

                            if (letters.size() == _search.size()) { // Only execute toupper func if we have the same amount of chars
                                for (auto pos : letters) {
                                    auto toUpper = _crossword->get(pos);
                                    _crossword->set(pos, std::toupper(toUpper));
                                }
                                std::cout << "Found it! " << _search << std::endl; 
                            }
                            letters.clear();

                        }
                }

                
            }
        }
    }
}
