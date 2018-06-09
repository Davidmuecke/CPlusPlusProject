#include "ProcessChain.h"
#include <string>


using namespace std;
ProcessChain::ProcessChain(std::string name) {
	currentProcesses = 0;
	ProcessChain::name = name;
}

ProcessChain::~ProcessChain() {
	delete pChain;
}

//Tiefe Kopie der gesamten Processkette erstellen.
ProcessChain::ProcessChain(const ProcessChain & other) {
	name = other.name;
	currentProcesses = other.currentProcesses;
	for (int i = 0; i < currentProcesses; i++) {
		pChain[i] = new Process(*other.pChain[i]);
	}
}

//Overloading des = Operators
ProcessChain & ProcessChain::operator= (const ProcessChain& other) {
	return *(new ProcessChain(other));
}

// Einfügen eines neuen Prozesses in die Prozesskette
// Prozess wird so eingefügt, dass die Prozesskette nach ID
// sortiert bleibt.
bool ProcessChain::Insert(const Process & arg) {
	if ((currentProcesses + 1) > MaxProcesses) {
		return false;
	}
	for (int i = 0; i < currentProcesses; i++) {
		if (pChain[i]->getID() == arg.getID) {
			return false;
		}
	}
	Process* pCopyChain[MaxProcesses];



	bool insertedFlag = false;
	if (currentProcesses == 0) {
		*pCopyChain[0] = arg;
		insertedFlag = true;
	}
	for (int i = 0; i < currentProcesses; i++) {
		if (!insertedFlag) {
			if (pChain[i]->getID() < arg.getID) {
				pCopyChain[i] = pChain[i];
			}
			else {
				*pCopyChain[i] = arg;
				insertedFlag = true;
			}
		}
		else {
			pCopyChain[i] = pChain[i];
		}
	}
	currentProcesses++;
	*pChain = *pCopyChain;
	return true;
}

//Ausgabe der gesammten Prozesskette
std::ostream& operator<<(std::ostream& os, const ProcessChain& arg) {
	os << "Name der Prozesskette: " << arg.name << "\n";
	for (int i = 0; i < arg.currentProcesses; i++) {
		os << "Prozess " << i << ":\n";
	}
	os << "Gesamtlänge" << arg.CalcChainDuration;
	return os;
}

Duration ProcessChain::CalcChainDuration()
{
	Duration totalDuration;
	for (int i = 0; i < currentProcesses; i++) {
		Duration tmpDuration = pChain[i]->TimeSpan();
		totalDuration = totalDuration + tmpDuration;
	}
	return totalDuration;
}