#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

class Candidate {
private:
    std::string name;
    int votes;

public:
    Candidate(const std::string& candidateName) : name(candidateName), votes(0) {}

    const std::string& getName() const {
        return name;
    }

    int getVotes() const {
        return votes;
    }

    void incrementVotes() {
        votes++;
    }
};

class VoteManagementSystem {
private:
    std::vector<Candidate> candidates;
    std::string fileName;

public:
    VoteManagementSystem(const std::string& filename) : fileName(filename) {
        loadCandidates();
    }

    ~VoteManagementSystem() {
        saveCandidates();
    }

    void addCandidate(const std::string& candidateName) {
        candidates.emplace_back(candidateName);
    }

    void voteForCandidate(const std::string& candidateName) {
        for (Candidate& candidate : candidates) {
            if (candidate.getName() == candidateName) {
                candidate.incrementVotes();
                return;
            }
        }
        throw std::invalid_argument("Invalid candidate name");
    }

    void displayCandidates() const {
        for (const Candidate& candidate : candidates) {
            std::cout << candidate.getName() << ": " << candidate.getVotes() << " votes\n";
        }
    }

private:
    void loadCandidates() {
        std::ifstream inFile(fileName);
        std::string candidateName;

        while (inFile >> candidateName) {
            candidates.emplace_back(candidateName);
        }

        inFile.close();
    }

    void saveCandidates() const {
        std::ofstream outFile(fileName);

        for (const Candidate& candidate : candidates) {
            outFile << candidate.getName() << " " << candidate.getVotes() << "\n";
        }

        outFile.close();
    }
};

int main() {
    VoteManagementSystem voteSystem("candidates.txt");

    while (true) {
        std::cout << "1. Add Candidate\n";
        std::cout << "2. Vote for Candidate\n";
        std::cout << "3. Display Candidates and Votes\n";
        std::cout << "4. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string candidateName;
                std::cout << "Enter candidate name: ";
                std::cin >> candidateName;
                voteSystem.addCandidate(candidateName);
                break;
            }
            case 2: {
                std::string candidateName;
                std::cout << "Enter candidate name: ";
                std::cin >> candidateName;
                try {
                    voteSystem.voteForCandidate(candidateName);
                    std::cout << "Vote recorded.\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                }
                break;
            }
            case 3:
                voteSystem.displayCandidates();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
