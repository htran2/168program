/**
 * Follow Steps in "README" file.
 */

#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include "Route.h"
using namespace std;

/**
 * Assume that when we paste the input, we ordered smallest -> largest
 * the last element of the data vector will contain the longest route
*/
const double SUM_ROUTES = 168;

vector<double> readDouble();
Route * isSubsetSum(vector<double> data, int dataSize, double SUM, Route *route);

vector<double> updateData(vector<double>data, Route * routes);


int main(){
    vector<double> data = readDouble();

    //all the routes
    vector<Route*> results;
    
    //just 1 route
    Route * result = new Route();

    
    result = isSubsetSum(data, data.size(), SUM_ROUTES, result);
    //calculate until no routes left
    while(result->getBoolResult() == true){
        results.push_back(result);

        data = updateData(data, result);
        result = new Route();
        result = isSubsetSum(data, data.size(), SUM_ROUTES, result);
    }

    for(int i = 0; i < results.size(); i++){
        cout <<"Routes #" << i+1 << endl;
        results[i]->printData();
    }


    return 0;
}

//delete times in data that already in routes
vector<double> updateData(vector<double> data, Route *routes){
    for(int i = 0; i < routes->getRouteSize(); i ++){
        double currentRoute = routes->at(i);
        for(int j = 0; j < data.size(); j++){
            if(data[j] == currentRoute){
                data.erase(data.begin() + j);
                j = data.size() + 1;
            }
        }
    }
    return data;
}

/**
 * Read all the input, return vector of doubles
 */
vector<double> readDouble(){
    vector<double> timeVector;
    double time = 1;
    while (cin >> time && time > 0){
        timeVector.push_back(time);
    }
    return timeVector;
}

/**
 * recursive function to calculate route. For more information, Google: "Subset Sum Problem"
 * or visit: https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
 */
Route* isSubsetSum(vector<double> data, int dataSize, double SUM, Route * route){
    if(dataSize <= 0){
        route->setBoolResult(false);
        return route;
    }
    double maxDouble = data[dataSize-1];
    double minDouble = data[0];


    //Base Cases: sum <= maxDouble
    if (SUM <= 1 && SUM >= 0) 
    { //good enough
        route->setBoolResult(true);
        return route;
    }
    //if sum < smallest value -> false
    if(minDouble > SUM){
        route->setBoolResult(false);
        return route;
    }
    //there might be an xi = sum -> true
    else if (maxDouble >= SUM){
        for(int i = 0; i < dataSize; i++){
            if(data[i] == SUM){
                route->pushRoute(data[i]);
                route->setBoolResult(true);
                //clear data[i] here?
                data.erase(data.begin() + i);
                return route;
            }
        }
    }

    //not base case
    //SUM > maxDouble

    
    //if has last element
    //push last element to current route stack
    double lastElement = data[dataSize - 1];
    route->pushRoute(lastElement);
    //delete last element in data
    data.pop_back();
    //check if there is a solution
    route = isSubsetSum(data, dataSize - 1 , SUM - lastElement, route);
    if(route->getBoolResult()){//if true -> we have  a route list
        return route;
    }

    //last element should not be included
    //pop the last element out of the result route
    lastElement = route->popRoute();
    //push it backs into data
    data.push_back(lastElement);
    //check solution
    route = isSubsetSum(data, dataSize - 1, SUM, route);
    return route;

    
}

