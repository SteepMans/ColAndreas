#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#ifdef WIN32
#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin);
#endif

#include "BuildManager.h"

void doWork(std::string gamePath, std::string outputPath, bool SAMPObjs, bool CustomObjs)
{
	BuildManager* thisBuild = new BuildManager(gamePath, outputPath, SAMPObjs, CustomObjs);

	std::cout << "Processing: Image files (.img)" << std::endl;
	thisBuild->ExtractImageFiles();
	std::cout << "Done.\n" << std::endl;

	std::cout << "Processing: Collision files (.col)" << std::endl;
	thisBuild->ExtractCollisionFiles();
	std::cout << "Done.\n" << std::endl;

	/*std::cout << "Processing: Item placement files (.ipl)" << std::endl;
	thisBuild->ExtractItemPlacementFiles();
	std::cout << "Done.\n" << std::endl;*/

	/*std::cout << "Processing: Item definition files (.ide)" << std::endl;
	thisBuild->ExtractItemDefinitionFiles();
	std::cout << "Done.\n" << std::endl;*/

	std::cout << "Preparing database structures, this may take some time." << std::endl;
	thisBuild->PrepareDatabaseStructures();
	std::cout << "Done.\n" << std::endl;

	std::cout << "Writing the database file." << std::endl;
	thisBuild->WriteBinaryFile(outputPath.c_str());
	std::cout << "Done.\n" << std::endl;

	std::cout << "All done!" << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "Start build file" << std::endl;
	doWork("C:/RADMIR_CRMP_TESTING", "C:/Users/steep/Desktop/work/radmir-crmp/scriptfiles/colandreas/ColAndreas.cadb", true, true);
	return 1;
}