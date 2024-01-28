#ifndef BASICS
#define BASICS
class Cruise;
class Accomodations;
class FileManager;
class WaitingList;
using namespace std;
enum class TicketStatus{
    BOOKED,
    IDLE,
    WAITINGLIST
};
enum class SeatingClass{
    BUSINESS,
    ECONOMIC,
    IDLE
};
#include <bits/stdc++.h>
#include <sys/ioctl.h>
#include "GUIHelpers.h"
#include "Accomodations.h"
#include "WaitingList.h"
#include "Cruise.h"
#include "User.h"
#include "FileManagement.h"
#include "BookShedule.h"
#endif