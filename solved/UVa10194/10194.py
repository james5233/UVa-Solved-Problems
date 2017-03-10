#!/usr/bin/env python3
import sys

T = int (sys.stdin.readline ())

for t in range (T):
    if t > 0:
        print ("")

    tournament = sys.stdin.readline ();
    tournament = tournament.rstrip ('\n');

    n_teams = int (sys.stdin.readline ())
    
    teams = []
    for n in range (n_teams):
        s = sys.stdin.readline ()
        s = s.rstrip ('\n')

        teams.append (s)
    
    points_earned = {}
    games_played = {}
    games_won = {}
    games_tied = {}
    games_lost = {}
    goals_scored = {}
    goals_against = {}

    for n in teams:
        points_earned[n] = 0
        games_played[n] = 0
        games_won[n] = 0
        games_tied[n] = 0
        games_lost[n] = 0
        goals_scored[n] = 0
        goals_against[n] = 0

    n_matches = int (sys.stdin.readline ())
    for n in range (n_matches):
        s = sys.stdin.readline ()
        s = s.rstrip ('\n')

        arr = list (s.split ("#"))
        side = [arr[0], arr[2]]
        score = [int (x) for x in arr[1].split ('@') ]

        games_played[side[0]] += 1
        games_played[side[1]] += 1
        
        goals_scored[side[0]] += score[0]
        goals_against[side[0]] += score[1]

        goals_scored[side[1]] += score[1]
        goals_against[side[1]] += score[0]

        if score[0] < score[1]:
            games_lost[side[0]] += 1
            games_won[side[1]] += 1
            points_earned[side[1]] += 3
        elif score[0] == score[1]:
            games_tied[side[0]] += 1
            games_tied[side[1]] += 1
            points_earned[side[0]] += 1
            points_earned[side[1]] += 1
        else:
            games_won[side[0]] += 1
            games_lost[side[1]] += 1
            points_earned[side[0]] += 3

    lst = []
    r = 0
    for n in teams:
        s = [-points_earned[n], -games_won[n], -goals_scored[n] \
        + goals_against[n], -goals_scored[n], games_played[n], \
        str(n).lower (), r]
        lst.append (s)
        r += 1

    lst.sort ()

    print (tournament)
    r = 0
    for n in lst:
        name = teams[n[6]]
        r += 1
        s = str (r) + ") " + name + " " + str (points_earned[name]) +\
        "p, " + str (games_played[name]) + "g (" + \
        str (games_won[name]) + "-" + str (games_tied[name]) + "-" +\
        str (games_lost[name]) + "), " + str (goals_scored[name] - \
        goals_against[name]) + "gd (" + str (goals_scored[name]) + "-"\
        + str (goals_against[name]) + ")"
        print (s)


