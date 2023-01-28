#include <iostream>	
#include <fstream>
#include <list>
#include <sstream>
#include <defns.h>
#define N 2000
using namespace std;
int temp[N];



//merge sort
void Merge(int merge[], int l, int m, int r) {
	int p = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r) {
		if (merge[i] > merge[j])
			temp[p++] = merge[j++];
		else
			temp[p++] = merge[i++];
	}
	while (i <= m) temp[p++] = merge[i++];
	while (j <= r) temp[p++] = merge[j++];
	for (i = 0; i < p; i++)
		merge[l + i] = temp[i];
}

void MergeSort(int merge[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;

		MergeSort(merge, l, m);
		MergeSort(merge, m + 1, r);

		Merge(merge, l, m, r);
	}
}

void showInfoFatality(annual_storm* tempAnnualEvent, int z, int i) {
	cout << "	" << tempAnnualEvent[z].year << endl;
	cout << "		Event ID : " << tempAnnualEvent[z].fatality_events[i].event_id << endl;
	cout << "		Fatality Type : " << tempAnnualEvent[z].fatality_events[i].fatality_type << endl;
	cout << "		Fatality Date : " << tempAnnualEvent[z].fatality_events[i].fatality_date << endl;
}

void maxFatality(int n, int n_storm, int z, int maxNumber, annual_storm* tempAnnualEvent) {
	for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
		if (maxNumber == (tempAnnualEvent[z].storm_events[n_annual_storm_max].deaths_indirect + tempAnnualEvent[z].storm_events[n_annual_storm_max].deaths_direct)) {
			int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_max].event_id;
			for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
				if (tempAnnualEvent[z].fatality_events[i].event_id == eventIdMin) {
					showInfoFatality(tempAnnualEvent, z, i);
				}
			}
		}
	}

}

void minFatality(int n, int n_storm, int z, int minNumber, annual_storm* tempAnnualEvent) {
	for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
		if (minNumber == (tempAnnualEvent[z].storm_events[n_annual_storm_min].deaths_indirect + tempAnnualEvent[z].storm_events[n_annual_storm_min].deaths_direct)) {
			int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_min].event_id;
			for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
				if (tempAnnualEvent[z].fatality_events[i].event_id == eventIdMin) {
					showInfoFatality(tempAnnualEvent, z, i);
				}
			}
		}
	}
}

void kFatality(int n, int input_k, int n_storm, int z, deaths* tempdeaths, annual_storm* tempAnnualEvent) {

	for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
		if (tempdeaths[n_storm - input_k].total_deaths == (tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_indirect + tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_direct)) {
			int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_k].event_id;
			for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
				if (tempAnnualEvent[z].fatality_events[i].event_id == eventIdMin) {
					showInfoFatality(tempAnnualEvent, z, i);
				}
			}
		}
	}
}


void showInfoDamage(annual_storm* tempAnnualEvent, int z, int i) {
	cout << "	" << tempAnnualEvent[z].year << endl;
	cout << "		Event ID: " << tempAnnualEvent[z].storm_events[i].event_id << endl;
	cout << "		State: " << tempAnnualEvent[z].storm_events[i].state << endl;
	cout << "		Year: " << tempAnnualEvent[z].storm_events[i].year << endl;
	cout << "		Month: " << tempAnnualEvent[z].storm_events[i].month_name << endl;
	cout << "		Event Type: " << tempAnnualEvent[z].storm_events[i].event_type << endl;
	cout << "		County/Parish/Marine: " << tempAnnualEvent[z].storm_events[i].cz_type << endl;
	cout << "		County/Parish/Marine Name: " << tempAnnualEvent[z].storm_events[i].cz_name << endl;
	cout << "		Injuries Direct: " << tempAnnualEvent[z].storm_events[i].injuries_direct << endl;
	cout << "		Injuries Indirect: " << tempAnnualEvent[z].storm_events[i].injuries_indirect << endl;
	cout << "		Deaths Direct: " << tempAnnualEvent[z].storm_events[i].deaths_direct << endl;
	cout << "		Deaths Indirect: " << tempAnnualEvent[z].storm_events[i].deaths_indirect << endl;
	cout << "		Damage to Property: $" << tempAnnualEvent[z].storm_events[i].damage_property << endl;
	cout << "		Damage to Crops: $" << tempAnnualEvent[z].storm_events[i].damage_crops << endl;
}

void maxDamage(int n_storm, int z, int maxNumber, int damage, int n_annual_storm_max, annual_storm* tempAnnualEvent) {
	if (maxNumber == damage) {
		int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_max].event_id;
		for (int i = 0; i < tempAnnualEvent[z].no_storms; i++) {
			if (tempAnnualEvent[z].storm_events[i].event_id == eventIdMin) {
				showInfoDamage(tempAnnualEvent, z, i);
			}
		}
	}
}

void minDamage(int n_storm, int z, int minNumber, int damage, int n_annual_storm_min, annual_storm* tempAnnualEvent) {
	if (minNumber == damage) {
		int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_min].event_id;
		for (int i = 0; i < tempAnnualEvent[z].no_storms; i++) {
			if (tempAnnualEvent[z].storm_events[i].event_id == eventIdMin) {
				showInfoDamage(tempAnnualEvent, z, i);
			}
		}
	}
}

void kDamage(int n_storm, int z, int kNumber, int damage, int n_annual_storm_k, annual_storm* tempAnnualEvent) {
	if (kNumber == damage) {
		int eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_k].event_id;
		for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
			if (tempAnnualEvent[z].storm_events[i].event_id == eventIdMin) {
				showInfoDamage(tempAnnualEvent, z, i);
			}
		}
	}
}


int main() {
	system("title C++ STORM");	

	damage* tempdamage = new damage[2000];
	deaths* tempdeaths = new deaths[2000];
	annual_storm* tempAnnualEvent = new annual_storm[2000];
	storm_event* tempStormEvent = new storm_event[2000];
	fatality_event* tempFatalityEvent = new fatality_event[2000];

	int initYear = 1950;
	int numberOfYear;
	cout << "Please input the number of years: " << endl;
	cin >> numberOfYear;
	cout << "storm " << numberOfYear << " ";

	int n = 0;
	char M[] = "M";
	char K[] = "K";
	int judge = 0;

	for (int i = 0; i < numberOfYear; i++) {
		string InitYear = to_string(initYear);
		ifstream stromPath(".\\data\\details-" + InitYear + ".csv");
		string stormLine;
		ifstream fatalityPath(".\\data\\fatalities-" + InitYear + ".csv");
		string fatalityLine;

		if (stromPath.fail() || fatalityPath.fail()) {
			cout << '\n' << "Failed to read file" << endl;
			judge = 1;
			break;
		}

		cout << initYear << " ";
		getline(stromPath, stormLine);
		string storm[13];

		int si = 0;
		while (getline(stromPath, stormLine))
		{
			stringstream ss(stormLine);
			string storm_str;
			int x = 0;
			while (getline(ss, storm_str, ','))
			{
				storm[x] = storm_str;
				x++;
			}
			int event_id, year, injuries_direct, injuries_indirect, deaths_direct, deaths_indirect, damage_property, damage_crops;

			stringstream temp_event_id;
			temp_event_id << storm[0];
			temp_event_id >> event_id;
			tempStormEvent[si].event_id = event_id;

			tempStormEvent[si].state = storm[1];

			stringstream temp_year;
			temp_year << storm[2];
			temp_year >> year;
			tempStormEvent[si].year = year;

			tempStormEvent[si].month_name = storm[3];
			tempStormEvent[si].event_type = storm[4];
			tempStormEvent[si].cz_type = storm[5];
			tempStormEvent[si].cz_name = storm[6];

			stringstream temp_injuries_direct;
			temp_injuries_direct << storm[7];
			temp_injuries_direct >> injuries_direct;
			tempStormEvent[si].injuries_direct = injuries_direct;

			stringstream temp_injuries_indirect;
			temp_injuries_indirect << storm[8];
			temp_injuries_indirect >> injuries_indirect;
			tempStormEvent[si].injuries_indirect = injuries_indirect;

			stringstream temp_deaths_direct;
			temp_deaths_direct << storm[9];
			temp_deaths_direct >> deaths_direct;
			tempStormEvent[si].deaths_direct = deaths_direct;

			stringstream temp_deaths_indirect;
			temp_deaths_indirect << storm[10];
			temp_deaths_indirect >> deaths_indirect;
			tempStormEvent[si].deaths_indirect = deaths_indirect;

			//transform the value of damage_property
			if (storm[11][storm[11].length() - 1] == M[0]) {
				stringstream temp_damage_property;
				temp_damage_property << storm[11];
				temp_damage_property >> damage_property;
				tempStormEvent[si].damage_property = damage_property * 1000000;
			}
			else if (storm[11][storm[11].length() - 1] == K[0]) {
				stringstream temp_damage_property;
				temp_damage_property << storm[11];
				temp_damage_property >> damage_property;
				tempStormEvent[si].damage_property = damage_property * 1000;
			}
			else {
				stringstream temp_damage_property;
				temp_damage_property << storm[11];
				temp_damage_property >> damage_property;
				tempStormEvent[si].damage_property = damage_property * 1000;
			}

			stringstream temp_damage_crops;
			temp_damage_crops << storm[12];
			temp_damage_crops >> damage_crops;
			tempStormEvent[si].damage_crops = damage_crops;

			si++;
		}

		tempAnnualEvent[n].year = initYear;
		tempAnnualEvent[n].no_storms = si;
		tempAnnualEvent[n].storm_events = tempStormEvent;

		int fi = 0;
		string fatality[6];
		getline(fatalityPath, fatalityLine);
		while (getline(fatalityPath, fatalityLine))
		{
			stringstream ss(fatalityLine);
			string fatality_str;
			int x = 0;
			while (getline(ss, fatality_str, ','))
			{
				fatality[x] = fatality_str;
				x++;
			}

			int event_id, fatality_age;

			stringstream temp_event_id;
			temp_event_id << fatality[0];
			temp_event_id >> event_id;
			tempFatalityEvent[fi].event_id = event_id;

			tempFatalityEvent[fi].fatality_type = fatality[1];
			tempFatalityEvent[fi].fatality_date = fatality[2];

			stringstream temp_fatality_age;
			temp_fatality_age << fatality[0];
			temp_fatality_age >> fatality_age;
			tempFatalityEvent[fi].fatality_age = fatality_age;

			tempFatalityEvent[fi].fatality_sex = fatality[4];
			tempFatalityEvent[fi].fatality_location = fatality[5];

			fi++;
		}
		tempAnnualEvent[n].no_fatalities = fi;
		tempAnnualEvent[n].fatality_events = tempFatalityEvent;

		n++;
		initYear++;
	}

	if (judge == 0) {
		cout << endl;

		string search[5];
		string information;
		cout << "Query: ";
		cin >> information;
		getline(cin, information);
		stringstream ss(information);
		string inputLine;
		int x = 0;
		int data[500];

		while (getline(ss, inputLine, ' '))
		{
			search[x] = inputLine;
			x++;
		}
		if (search[3] == "fatality") {
			if (search[2] == "all") {
				int n_storm = 0;
				int n_annual = 0;
				int n_annual_storm = 0;
				for (int i = 0; i < n; i++) {
					n_storm = n_storm + tempAnnualEvent[i].no_storms;
				}
				for (int i = 0; i < n_storm; i++) {
					tempdeaths[i].index = i;
					tempdeaths[i].year = tempAnnualEvent[n_annual].year;
					tempdeaths[i].total_deaths = (tempAnnualEvent[n_annual].storm_events[n_annual_storm].deaths_indirect + tempAnnualEvent[n_annual].storm_events[n_annual_storm].deaths_direct);
					data[i] = (tempAnnualEvent[n_annual].storm_events[n_annual_storm].deaths_indirect + tempAnnualEvent[n_annual].storm_events[n_annual_storm].deaths_direct);
					n_annual_storm++;
					if (n_annual_storm >= tempAnnualEvent[n_annual].no_storms) {
						n_annual_storm = 0;
						n_annual++;
					}
				}

				if (search[4] == "insertion") {//select all fatality insertion
					//insertion sort
					for (int i = 1; i < n_storm; i++) {
						int key = tempdeaths[i].total_deaths;
						int j = i - 1;
						while ((j >= 0) && (key < tempdeaths[j].total_deaths)) {
							tempdeaths[j + 1].total_deaths = tempdeaths[j].total_deaths;
							j--;
						}
						tempdeaths[j + 1].total_deaths = key;
					}

					if (search[1] == "max") {
						for (int z = 0; z < n; z++) {
							maxFatality(n, n_storm, z, tempdeaths[n_storm - 1].total_deaths, tempAnnualEvent);
						}
					}
					else if (search[1] == "min") {
						for (int z = 0; z < n; z++) {
							minFatality(n, n_storm, z, tempdeaths[1].total_deaths, tempAnnualEvent);
						}
					}
					else {
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							kFatality(n, input_k, n_storm, z, tempdeaths, tempAnnualEvent);
						}
					}
				}
				else {//select all fatality merge
					//merge sort
					MergeSort(data, 0, n_storm - 1);
					int eventIdMin = 0;
					if (search[1] == "max") {
						for (int z = 0; z < n; z++) {
							maxFatality(n, n_storm, z, data[n_storm - 1], tempAnnualEvent);
						}
					}
					else if (search[1] == "min") {
						for (int z = 0; z < n; z++) {
							maxFatality(n, n_storm, z, data[1], tempAnnualEvent);
						}
					}
					else {
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
								if (data[n_storm - input_k] == (tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_indirect + tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_direct)) {
									eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_k].event_id;
									for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
										if (tempAnnualEvent[z].fatality_events[i].event_id == eventIdMin) {
											showInfoFatality(tempAnnualEvent, z, i);
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				int n_storm = 0;
				int x = 0;
				int y = 0;
				int year;
				stringstream temp_year;
				temp_year << search[2];
				temp_year >> year;
				int n_fatality = 0;

				for (int i = 0; i < n; i++) {
					if (tempAnnualEvent[i].year == year) {
						n_storm = n_storm + tempAnnualEvent[i].no_storms;
						n_fatality = n_storm + tempAnnualEvent[i].no_fatalities;
					}
				}
				for (int z = 0; z < n; z++) {
					if (tempAnnualEvent[z].year == year) {
						for (int i = 0; i < n_storm; i++) {
							tempdeaths[i].index = i;
							tempdeaths[i].year = tempAnnualEvent[z].year;
							tempdeaths[i].total_deaths = (tempAnnualEvent[z].storm_events[y].deaths_indirect + tempAnnualEvent[z].storm_events[y].deaths_direct);
							data[i] = (tempAnnualEvent[z].storm_events[y].deaths_indirect + tempAnnualEvent[z].storm_events[y].deaths_direct);
							y++;
						}
					}
				}
				if (search[4] == "insertion") {		//select YYYY fatality insertion
					//insertion sort
					for (int i = 1; i < n_storm; i++) {
						int key = tempdeaths[i].total_deaths;
						int j = i - 1;
						while ((j >= 0) && (key < tempdeaths[j].total_deaths)) {
							tempdeaths[j + 1].total_deaths = tempdeaths[j].total_deaths;
							j--;
						}
						tempdeaths[j + 1].total_deaths = key;
					}
					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								maxFatality(n, n_storm, z, tempdeaths[n_storm - 1].total_deaths, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								maxFatality(n, n_storm, z, tempdeaths[1].total_deaths, tempAnnualEvent);
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								kFatality(n, input_k, n_storm, z, tempdeaths, tempAnnualEvent);
							}
						}
					}
				}
				else {		//select YYYY fatality merge
					MergeSort(data, 0, n_storm - 1);

					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								maxFatality(n, n_storm, z, tempdeaths[n_storm - 1].total_deaths, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								maxFatality(n, n_storm, z, data[1], tempAnnualEvent);
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
									if (data[n_storm - input_k] == (tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_indirect + tempAnnualEvent[z].storm_events[n_annual_storm_k].deaths_direct)) {
										eventIdMin = tempAnnualEvent[z].storm_events[n_annual_storm_k].event_id;
										for (int i = 0; i < tempAnnualEvent[z].no_fatalities; i++) {
											if (tempAnnualEvent[z].fatality_events[i].event_id == eventIdMin) {
												showInfoFatality(tempAnnualEvent, z, i);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		else if (search[3] == "damage_property") {
			if (search[2] == "all") {
				int n_storm = 0;
				for (int i = 0; i < n; i++) {
					n_storm = n_storm + tempAnnualEvent[i].no_storms;
				}
				int x = 0;
				int y = 0;
				for (int i = 0; i < n_storm; i++) {
					tempdamage[i].index = i;
					tempdamage[i].year = tempAnnualEvent[x].year;
					tempdamage[i].damage_amount = tempAnnualEvent[x].storm_events[y].damage_property;
					data[i] = tempAnnualEvent[x].storm_events[y].damage_property;
					y++;
					if (y > tempAnnualEvent[x].no_storms) {
						y = 0;
						x++;
					}

				}
				if (search[4] == "insertion") {		//select all damage_property insertion
					//insertion sort
					for (int i = 1; i < n_storm; i++) {
						int key = tempdamage[i].damage_amount;
						int j = i - 1;
						while ((j >= 0) && (key < tempdamage[i].damage_amount)) {
							tempdamage[j + 1].damage_amount = tempdamage[j].damage_amount;
							j--;
						}
						tempdamage[j + 1].damage_amount = key;
					}
					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
								maxDamage(n_storm, z, tempdamage[n_storm - 1].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_property, n_annual_storm_max, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
								minDamage(n_storm, z, tempdamage[0].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_property, n_annual_storm_min, tempAnnualEvent);
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
								kDamage(n_storm, z, tempdamage[n_storm - input_k].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_property, n_annual_storm_k, tempAnnualEvent);
							}
						}
					}
				}
				else {		//select all damage_property merge
					MergeSort(data, 0, n_storm - 1);

					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
								maxDamage(n_storm, z, data[n_storm - 1], tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_property, n_annual_storm_max, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
								minDamage(n_storm, z, data[1], tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_property, n_annual_storm_min, tempAnnualEvent);

							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {

							for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
								kDamage(n_storm, z, data[n_storm - input_k], tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_property, n_annual_storm_k, tempAnnualEvent);
							}

						}
					}
				}
			}
			else {
				int n_storm = 0;
				int x = 0;
				int y = 0;
				int year;
				stringstream temp_year;
				temp_year << search[2];
				temp_year >> year;
				int n_fatality = 0;

				for (int i = 0; i < n; i++) {
					if (tempAnnualEvent[i].year == year) {
						n_storm = n_storm + tempAnnualEvent[i].no_storms;
					}
				}
				for (int z = 0; z < n; z++) {
					if (tempAnnualEvent[z].year == year) {
						for (int i = 0; i < n_storm; i++) {
							tempdamage[i].index = i;
							tempdamage[i].year = tempAnnualEvent[z].year;
							tempdamage[i].damage_amount = tempAnnualEvent[z].storm_events[y].damage_property;
							data[i] = tempAnnualEvent[z].storm_events[y].damage_property;
							y++;
						}
					}
				}
				if (search[4] == "insertion") {		//select YYYY damage_property insertion
					//insertion sort
					for (int i = 1; i < n_storm; i++) {
						int key = tempdamage[i].damage_amount;
						int j = i - 1;
						while ((j >= 0) && (key < tempdamage[j].damage_amount)) {
							tempdamage[j + 1].damage_amount = tempdamage[j].damage_amount;
							j--;
						}
						tempdamage[j + 1].damage_amount = key;
					}
					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
									maxDamage(n_storm, z, tempdamage[n_storm - 1].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_property, n_annual_storm_max, tempAnnualEvent);
								}
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
									minDamage(n_storm, z, tempdamage[0].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_property, n_annual_storm_min, tempAnnualEvent);
								}
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {

								for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
									kDamage(n_storm, z, tempdamage[n_storm - input_k].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_property, n_annual_storm_k, tempAnnualEvent);
								}

							}
						}
					}
				}
				else {		//select YYYY damage_property merge
					MergeSort(data, 0, n_storm - 1);

					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
									maxDamage(n_storm, z, data[n_storm - 1], tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_property, n_annual_storm_max, tempAnnualEvent);
								}
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
									minDamage(n_storm, z, data[1], tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_property, n_annual_storm_min, tempAnnualEvent);
								}
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {

								for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
									kDamage(n_storm, z, data[n_storm - input_k], tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_property, n_annual_storm_k, tempAnnualEvent);
								}

							}
						}
					}
				}
			}
		}
		else if (search[3] == "damage_crops") {
			if (search[2] == "all") {
				int n_storm = 0;
				for (int i = 0; i < n; i++) {
					n_storm = n_storm + tempAnnualEvent[i].no_storms;
				}
				int x = 0;
				int y = 0;
				for (int i = 0; i < n_storm; i++) {
					tempdamage[i].index = i;
					tempdamage[i].year = tempAnnualEvent[x].year;
					tempdamage[i].damage_amount = tempAnnualEvent[x].storm_events[y].damage_crops;
					data[i] = tempAnnualEvent[x].storm_events[y].damage_crops;
					y++;
					if (y > tempAnnualEvent[x].no_storms) {
						y = 0;
						x++;
					}
				}
				if (search[4] == "insertion") {		//select all damage_crops insertion
					//insertion sort
					for (int i = 1; i < n_storm; i++) {
						int key = tempdamage[i].damage_amount;
						int j = i - 1;
						while ((j >= 0) && (key < tempdamage[i].damage_amount)) {
							tempdamage[j + 1].damage_amount = tempdamage[j].damage_amount;
							j--;
						}
						tempdamage[j + 1].damage_amount = key;
					}
					if (search[1] == "max") {
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
								maxDamage(n_storm, z, tempdamage[n_storm - 1].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_crops, n_annual_storm_max, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
								minDamage(n_storm, z, tempdamage[0].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_crops, n_annual_storm_min, tempAnnualEvent);
							}
						}
					}
					else {
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {

							for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
								kDamage(n_storm, z, tempdamage[n_storm - input_k].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_crops, n_annual_storm_k, tempAnnualEvent);
							}

						}
					}
				}
				else {		//select all damage_crops merge
					MergeSort(data, 0, n_storm - 1);
					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
								maxDamage(n_storm, z, data[n_storm - 1], tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_crops, n_annual_storm_max, tempAnnualEvent);
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
								minDamage(n_storm, z, data[1], tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_crops, n_annual_storm_min, tempAnnualEvent);

							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {

							for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
								kDamage(n_storm, z, data[n_storm - input_k], tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_crops, n_annual_storm_k, tempAnnualEvent);
							}

						}
					}
				}
			}
			else {
				int n_storm = 0;
				int x = 0;
				int y = 0;
				int year;
				stringstream temp_year;
				temp_year << search[2];
				temp_year >> year;
				int n_fatality = 0;

				for (int i = 0; i < n; i++) {
					if (tempAnnualEvent[i].year == year) {
						n_storm = n_storm + tempAnnualEvent[i].no_storms;
					}
				}
				for (int z = 0; z < n; z++) {
					if (tempAnnualEvent[z].year == year) {
						for (int i = 0; i < n_storm; i++) {
							tempdamage[i].index = i;
							tempdamage[i].year = tempAnnualEvent[z].year;
							tempdamage[i].damage_amount = tempAnnualEvent[z].storm_events[y].damage_crops;
							data[i] = tempAnnualEvent[z].storm_events[y].damage_crops;
							y++;
						}
					}
				}

				if (search[4] == "insertion") {		//select YYYY damage_crops insertion
					for (int i = 1; i < n_storm; i++) {
						int key = tempdamage[i].damage_amount;
						int j = i - 1;
						while ((j >= 0) && (key < tempdamage[j].damage_amount)) {
							tempdamage[j + 1].damage_amount = tempdamage[j].damage_amount;
							j--;
						}
						tempdamage[j + 1].damage_amount = key;
					}
					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
									maxDamage(n_storm, z, tempdamage[n_storm - 1].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_crops, n_annual_storm_max, tempAnnualEvent);
								}
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
									minDamage(n_storm, z, tempdamage[0].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_property, n_annual_storm_min, tempAnnualEvent);
								}
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {

								for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
									kDamage(n_storm, z, tempdamage[n_storm - input_k].damage_amount, tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_crops, n_annual_storm_k, tempAnnualEvent);
								}

							}
						}
					}
				}
				else {		//select YYYY damage_crops merge
					MergeSort(data, 0, n_storm - 1);

					if (search[1] == "max") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_max = 0; n_annual_storm_max < n_storm; n_annual_storm_max++) {
									maxDamage(n_storm, z, data[n_storm - 1], tempAnnualEvent[z].storm_events[n_annual_storm_max].damage_crops, n_annual_storm_max, tempAnnualEvent);
								}
							}
						}
					}
					else if (search[1] == "min") {
						int eventIdMin = 0;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_min = 0; n_annual_storm_min < n_storm; n_annual_storm_min++) {
									minDamage(n_storm, z, data[1], tempAnnualEvent[z].storm_events[n_annual_storm_min].damage_crops, n_annual_storm_min, tempAnnualEvent);
								}
							}
						}
					}
					else {
						int eventIdMin = 0;
						int input_k;
						stringstream temp_k;
						temp_k << search[1];
						temp_k >> input_k;
						for (int z = 0; z < n; z++) {
							if (tempAnnualEvent[z].year == year) {
								for (int n_annual_storm_k = 0; n_annual_storm_k < n_storm; n_annual_storm_k++) {
									kDamage(n_storm, z, data[n_storm - input_k], tempAnnualEvent[z].storm_events[n_annual_storm_k].damage_crops, n_annual_storm_k, tempAnnualEvent);
								}

							}
						}
					}
				}
			}
		}
	}
	
	return 0;
}
