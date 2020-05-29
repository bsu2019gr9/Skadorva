#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <math.h>
#include <limits>

using namespace std;

class Footballer {
private:
	char* name;
	char* team;
	short age;
	short games;
	short goals;
	short assists;
public:
	Footballer() : name(nullptr), team(nullptr), age(0), games(0), goals(0), assists(0) {
	};
	Footballer(const char Name[20], const char Team[20], short Age, short Games, short Goals, short Assists) : name(new (nothrow) char[strlen(Name) + 1]), team(new (nothrow) char[strlen(Team) + 1]) {
		strcpy(name, Name); strcpy(team, Team);
		age = Age; games = Games; goals = Goals; assists = Assists;
	}
	Footballer(const Footballer& footballer) : name(new (nothrow) char[strlen(footballer.name) + 1]), team(new (nothrow) char[strlen(footballer.team) + 1]), age(footballer.age), games(footballer.games), goals(footballer.goals), assists(footballer.assists) {
		strcpy(name, footballer.name);
		strcpy(team, footballer.team);
	}
	~Footballer() {
		delete[]name; name = nullptr;
		delete[]team; team = nullptr;
	}
	Footballer operator=(Footballer footballer) {
		if (!name) delete[]name; name = nullptr;
		if (!team) delete[]team; team = nullptr;
		name = new (nothrow) char[strlen(footballer.name) + 1]; strcpy(name, footballer.name);
		team = new (nothrow) char[strlen(footballer.team) + 1]; strcpy(team, footballer.team);
		age = footballer.age;
		games = footballer.games;
		goals = footballer.goals;
		assists = footballer.assists;
		return *this;
	}
	void printFootballer() const {
		if (!name || !team) return; cout.setf(ios::left);
		cout << setw(15) << name << "|" << setw(15) << team << "|" << setw(15) << age << "|" << setw(15) << games << "|" << setw(15) << goals << "|" << setw(15) << assists << "|";
	}
	char* getName() const { return name; }
	char* getTeam() const { return team; }
	short getAge() const { return age; }
	short getAssists() const { return assists; }
	short getGames() const { return games; }
	short getGoals() const { return goals; }
	void setName(const char newName[20]) {
		delete[]name; name = nullptr;
		name = new char[strlen(newName) + 1]; strcpy(name, newName);
	}
	void setTeam(const char newTeam[20]) {
		delete[]team; team = nullptr;
		team = new char[strlen(newTeam) + 1]; strcpy(team, newTeam);
	}
	void setAge(int Age) {Footballer NewFootballer; NewFootballer.age = Age;}
	void setAssists(int Assists) { Footballer NewFootballer; NewFootballer.assists = Assists; }
	void setGoals(int Goals) { Footballer NewFootballer; NewFootballer.goals = Goals; }
	void setGames(int Games) { Footballer NewFootballer; NewFootballer.games = Games; }

	friend std::istream& operator>> (std::istream& in, Footballer&);
	friend std::ostream& operator<< (std::ostream& out, const Footballer&);
	friend Footballer createFootballer(const char[20], const char[20], short, short, short, short);
	friend Footballer deleteFootballer(Footballer&);
	friend Footballer editName(Footballer&);
	friend Footballer editTeam(Footballer&);
	friend Footballer editAge(Footballer&);
	friend Footballer editAssists(Footballer&);
	friend Footballer editGoals(Footballer&);
	friend Footballer editGames(Footballer&);
	friend Footballer editFootballer(Footballer&, const char[7], int);
	friend Footballer* writeToFile(const char[30], Footballer*, int);
	friend Footballer* writeToFileBin (Footballer*, int, const char[30]);


};
std::istream& operator>> (std::istream& in, Footballer& footballer)
{
	char Name[30], Team[30];
	int Age, Games, Goals, Assists;

	cout << "Please, input name: ";
	in >> Name;
	delete[]footballer.name; footballer.name = nullptr;
	footballer.name = new (nothrow) char[strlen(Name) + 1];
	strcpy(footballer.name, Name);

	cout << "Please, input team: ";
	in >> Team;
	delete[]footballer.team; footballer.team = nullptr;
	footballer.team = new (nothrow) char[strlen(Team) + 1];
	strcpy(footballer.team, Team);

	cout << "Please, input age: ";
	in >> Age; footballer.age = Age;

	cout << "Please, input number of games: ";
	in >> Games; footballer.games = Games;
	
	cout << "Please, input number of goals: ";
	in >> Goals; footballer.goals = Goals;

	cout << "Please, input  number of assits: ";
	in >> Assists; footballer.assists = Assists;
	return in;
}
std::ostream& operator<< (std::ostream& out, const Footballer& footballer){
	cout.setf(ios::left);
	cout << setw(15) << "NAME" << "|" << setw(15) << "TEAM" << "|" << setw(15) << "AGE" << "|" << setw(15) << "GAMES" << "|" << setw(15) << "GOALS" << "|" << setw(15) << "ASSISTS" << "|\n";
	footballer.printFootballer(); return out;
}
std::ostream& operator<< (std::ostream& out, Footballer* Team)
{
	int N = *((size_t*)Team - 1);
	cout.setf(ios::left);
	cout << setw(15) << "NAME" << "|" << setw(15) << "TEAM" << "|" << setw(15) << "AGE" << "|" << setw(15) << "GAMES" << "|" << setw(15) << "GOALS" << "|" << setw(15) << "ASSISTS" << "|\n";
	for (int i(0); i < N; ++i) { Team[i].printFootballer();	cout << '\n';}
	return out;
}

Footballer createFootballer(const char Name[20], const char Team[20], short Age, short Games, short Goals, short Assists) {
	Footballer NewFootballer;
	NewFootballer.name = new (nothrow) char[strlen(Name) + 1];  strcpy(NewFootballer.name, Name);
	NewFootballer.team = new (nothrow) char[strlen(Team) + 1]; 	strcpy(NewFootballer.team, Team);
	NewFootballer.age = Age;
	NewFootballer.games = Games;
	NewFootballer.goals = Goals;
	NewFootballer.assists = Assists;
	return NewFootballer;
}
Footballer createFootballer() {
	Footballer NewFootballer;
	cin >> NewFootballer;
	return NewFootballer;
	}
Footballer deleteFootballer(Footballer& footballer) {
	delete[]footballer.name;	footballer.name = nullptr;
	delete[]footballer.team;	footballer.team = nullptr;
	footballer.age = 0;
	footballer.assists = 0;
	footballer.games = 0;
	footballer.goals = 0;
	return footballer;
}
Footballer editName(Footballer& footballer) {
	char New[15];
	cout << "Please, input new name: ";
	cin >> New;
	delete[]footballer.name; footballer.name = nullptr;
	footballer.name = new char[strlen(New) + 1];
	strcpy(footballer.name, New);
	return footballer;
}
Footballer editTeam(Footballer& footballer) {
	char New[15];
	cout << "Please, input new team: ";
	cin >> New;
	delete[]footballer.team; footballer.team = nullptr;
	footballer.team = new char[strlen(New) + 1];
	strcpy(footballer.team, New);
	return footballer;
}
Footballer editAge(Footballer& footballer) {
	int New;
	cout << "Please, input new age: "; cin >> New;
	footballer.age = New;
	return footballer;
}
Footballer editAssists(Footballer& footballer) {
	int New;
	cout << "Please, input new number of assists: "; cin >> New;
	footballer.assists = New;
	return footballer;
}
Footballer editGames(Footballer& footballer) {
	int New;
	cout << "Please, input new number of games: "; cin >> New;
	footballer.games = New;
	return footballer;
}
Footballer editGoals(Footballer& footballer) {
	int New;
	cout << "Please, input new number of goals: "; cin >> New;
	footballer.goals = New;
	cout << "Changes were completed: ";
	return footballer;
}
Footballer editFootballer(Footballer& footballer, const char change[7]) {
	switch (change[0]) {
	case 'n': editName(footballer); break;
	case 't': editTeam(footballer); break;
	case 'a': {
		if (change[1] == 'g') editAge(footballer);
		else editAssists(footballer);
	}
	case 'g': {
		if (change[1] == 'a') editGames(footballer);
		else editGoals(footballer);
	}
	default: break;
	}
	cout << "Changes have been completed successful";
	return footballer;
}
Footballer* createTeam(int Number) {
	Footballer* Team = new Footballer[Number];
	for (int i(0); i < Number; i++) {cin >> Team[i];}
	return Team;
}
Footballer* sortTeamByGoals(Footballer* Team) {
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			if (Team[j + 1].getGoals() > Team[j].getGoals()) swap(Team[j], Team[j + 1]);
		}
	}
	return Team;
}
Footballer* readFromFile(const char wayToFile[40]) {
	ifstream fin(wayToFile, ios::binary);//c:\\IT\\Team.txt
	if (!fin) { cout << "No file" << wayToFile << "Can't open\n"; exit(1); }
	Footballer* Team = nullptr; size_t count = 0;
	while (fin.ignore((numeric_limits<streamsize>::max)(), '\n')) count++;
	fin.close();
	Team = new Footballer[count];
	ifstream fin1(wayToFile);
	for (int i(0); i < count; ++i) {
		fin1 >> Team[i];
	}
	return Team;
}
Footballer* writeToFile(const char wayToFile[30], Footballer* Team, int N) {
	ofstream fout(wayToFile, ios::binary);
	if (!fout) { cout << "No  file"<< wayToFile<< ". Can't create\n"; exit(1); }
	if (N > *((size_t*)Team - 1)) N = *((size_t*)Team - 1);
	for (int i(0); i < N; ++i) {
		fout << Team[i].name << " " << Team[i].team << " " << Team[i].age << " " << Team[i].games << " " << Team[i].goals << " " << Team[i].assists << '\n';
	}
	return Team;
}
Footballer* readFromFileBin(Footballer* footballer, const int  size,const char wayToFile[30]) {
	ifstream fin(wayToFile, ios::binary);//c:\\IT\\Team.bin
	if (!fin) { cout << "No file" << wayToFile << "Can't open\n"; exit(1); }
	const int sizetmp(20);char ctmp[sizetmp];
	const int itmp(0);
	for (int i(0); i < size; i++) {
			fin.read((char*)&ctmp, sizetmp); if (fin.eof())break; footballer[count].setName(ctmp);
			fin.read((char*)&ctmp, sizetmp); footballer[count].setTeam(ctmp);
			fin.read((char*)&itmp, sizeof(int)); footballer[count].setAge(itmp);
			fin.read((char*)&itmp, sizeof(int)); footballer[count].setAssists(itmp);
			fin.read((char*)&itmp, sizeof(int)); footballer[count].setGames(itmp);
			fin.read((char*)&itmp, sizeof(int)); footballer[count].setGoals(itmp);
		}
	fin.close();
	return footballer;
}
Footballer* writeToFileBin(Footballer* footballer, const int  size, const char wayToFile[30]) {
	ofstream fout(wayToFile, ios::binary);
	if (!fout) { cout << "No  file" << wayToFile << ". Can't create\n"; exit(1); }
	const int sizetmp(20); char ctmp[sizetmp];   int itmp(0);
	for (int i(0); i < size;i++) {
		strcpy(ctmp, footballer[i].getName()); fout.write((char*)&ctmp, sizetmp);
		strcpy(ctmp, footballer[i].getTeam()); fout.write((char*)&ctmp, sizetmp);
		itmp = footballer[i].getAssists(); fout.write((char*)&itmp, sizeof(int));
		itmp = footballer[i].getAge(); fout.write((char*)&itmp, sizeof(int));
		itmp = footballer[i].getGoals(); fout.write((char*)&itmp, sizeof(int));
		itmp = footballer[i].getGames(); fout.write((char*)&itmp, sizeof(int));
	}
	return footballer;
}
Footballer* sortTeamByName(Footballer* Team) {
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j) 
		{
			if (strcmp(Team[j + 1].getName(), Team[j].getName()) < 0)
			{
				swap(Team[j], Team[j + 1]);
			}
		}
	}
	return Team;
}
Footballer* topSixPlayers(Footballer* Team) {
	sortTeamByGoals(Team);
	Footballer* topSixTeam = new Footballer[5];
	for (int i(0); i < 5;++i) topSixTeam[i] = Team[i];
	sortTeamByName(topSixTeam);
	return topSixTeam;
}
Footballer* sortTeamByAgeYongerThan(Footballer* Team, int Age) {
	int size = *((size_t*)Team - 1);
	Footballer* count_arr = new Footballer[size];
	int how_much(0);
	for (int i(0); i < size; ++i) {
		if (Team[i].getAge() < Age) {
			count_arr[how_much] = Team[i];
			++how_much;
		}
	}
	Footballer* younger_than = new Footballer[how_much];
	for (int i(0); i < how_much; ++i) {
		younger_than[i] = count_arr[i];
	}
	return younger_than;
}
Footballer* sortTeamByAgeOlderThan(Footballer* Team, int Age) {
	int size = *((size_t*)Team - 1);
	Footballer* count_arr = new Footballer[size];
	int how_much(0);
	for (int i(0); i < size; ++i) {
		if (Team[i].getAge() > Age) {
			count_arr[how_much] = Team[i];
			++how_much;
		}
	}
	Footballer* older_than = new Footballer[how_much];
	for (int i(0); i < how_much; ++i) {
		older_than[i] = count_arr[i];
	}
	return older_than;
}
int AverageAgeInTeam(Footballer* Team) {
	int average_age(0);
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)	average_age += Team[j].getAge();
	}
	average_age= average_age/size; return average_age;
}
int oldestFootballerInTeam(Footballer* Team) {
	int oldest(0);
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			if (Team[j].getAge() > oldest) oldest = Team[j].getAge();
		}
	}
	return oldest;
}
int youngestFootballerInTeam(Footballer* Team) {
	int youngest(100);
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			if (Team[j].getAge() < youngest) youngest = Team[j].getAge();
		}
	}
	return youngest;
}
int findTeamGoalsSum(Footballer* Team) {
	int sum(0);
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			sum += Team[j].getGoals();
		}
	}
	return sum;
}
int findTeamAssistsSum(Footballer* Team) {
	int sum(0);
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size - 1; ++i)
	{
		for (int j(0); j < size - 1; ++j)
		{
			sum += Team[j].getAssists();
		}
	}
	return sum;
}
void editFoundedFootballer(Footballer* Team, const  char* Name) {
	int size = *((size_t*)Team - 1);
	for (int i(0); i < size; ++i) {
		if (!(strcmp(Team[i].getName(), Name))) {
			cout << "Footballer was founded\nPlease, input what you want to change (name,goals,games,assists,age):\n  ";
			char change[7]; cin >> change;
			editFootballer(Team[i], change);
		}
		else {
			cout << "Footballer wasn't founded";
		}
	}
}
int main() {
	Footballer* Team1 = readFromFile("c:\\IT\\Team1.txt");
	start:
	cout << "Welcome!\n Skadorva Inc. present\n UEFA Team Manager v1.0\n Please, choose the option:\n1.Upload Team from a file\n2.Create team\n3.exit \n";
	int answer; cin >> answer;
	switch (answer) {
	case 1: {
		Footballer* Team1 = readFromFile("c:\\IT\\Team1.txt"); goto step2;
		break;
	}
	case 2: {
		create:
		cout << "Please, input number of members:\n ";
		int Num(0); cin >> Num;
		Footballer* Team1 = createTeam(Num);
		cout << "Do you want to save your team to a file (Y/N)?\n ";
		char write_or_not[2];
		cin >> write_or_not;
		const char* Yes = "Y";
		if (!strcmp(write_or_not, Yes)) {
			cout << "Please, input way to a file: \n";
			char wayToFile[30];
			cin >> wayToFile;
			writeToFile(wayToFile, Team1, Num);
		}
		else {
			cout << "Ok let's move on\n";
		} goto step2;
		break;
	}
	case 3: {
		cout << "See you soon\n";
		exit(0); break;
	}
	default:
		step2: while (1) {
		cout << "Choose an option:\n1. Statistic about your team \n2. Create new team \n 3.edit footballer in a team \n 4.Sort team \n5. Find top six players\n 6.Return to the previous step\n 7.exit\n";
		int answer2; cin >> answer2;
		switch (answer2) {
		case 1: {
			cout << "Choose an option:\n1. Find average age in your team\n 2.Find oldest footballer in your team \n 3.Find youngest footballer in your team \n 4. Find the total goals of this team \n 5.Find the total assists of this team\n";
			int answer3; cin >> answer3;
			switch (answer3) {
			case 1: {
				cout << AverageAgeInTeam(Team1) << "\n"; break;
			}
			case 2: {
				cout << oldestFootballerInTeam(Team1) << "\n"; break;
			}
			case 3: {
				cout << youngestFootballerInTeam(Team1) << "\n"; break;
			}
			case 4: {
				cout << findTeamGoalsSum(Team1) << "\n"; break;
			}
			case 5: {
				cout << findTeamAssistsSum(Team1) << "\n"; break;
			}
			default:
				break;
			}
			break;
		}
		case 2: {
			goto create; break;
		}
		case 3: {
			cout << " Please, input who is your footballer (name):<<\n";
			char name[30]; cin >> name;
			editFoundedFootballer(Team1, name);	break;
		}
		case 4: {
			cout << "Choose an option:\n1. Sort team by name\n 2.Sort team by goals \n 3.Sort team by age older than someone \n 4. Sort team by age younger than someone\n";
			int answer3; cin >> answer3;
			switch (answer3) {
			case 1: {
				cout << sortTeamByName(Team1) << "\n"; break;
			}
			case 2: {
				cout << sortTeamByGoals(Team1) << "\n"; break;
			}
			case 3: {
				cout << "Please, input age for sort: \n";
				int Age; cin >> Age;
				cout << sortTeamByAgeYongerThan(Team1, Age) << "\n"; break;
			}
			case 4: {
				cout << "Please, input age for sort:\n";
				int Age; cin >> Age;
				cout << sortTeamByAgeYongerThan(Team1, Age) << "\n"; break;
			}

			default:
				break;
			}
			break;
		}
		case 5: {
			cout << topSixPlayers(Team1) << "\n"; break;
		}
		case 6: {
			goto start; break;
		}
		case 7: {
			cout << "See you soon\n";
			exit(0); break;
		}
		}
	}break;
	}
}
