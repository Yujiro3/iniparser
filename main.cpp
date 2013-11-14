/**
 * main.cpp
 *
 * C++ versions 4.4.5
 *
 *      ini_parse : https://github.com/Yujiro3/iniparser
 *      Copyright (c) 2011-2013 sheeps.me All Rights Reserved.
 *
 * @package         ini_parse
 * @copyright       Copyright (c) 2011-2013 sheeps.me
 * @author          Yujiro Takahashi <yujiro3@gmail.com>
 * @filesource
 */

#include <iostream>
#include <string>

#include <event2/util.h>
#include <event2/event.h>

#include "ini_parse.h"

using namespace std;

/**
 * メイン関数
 *
 * @access public
 * @param int  argc
 * @param char **argv
 * @return int
 */
int main(int argc, char **argv) {
    char filename[] = "config.ini";
    ini::load(filename);
    
    cout << "Monitored file" << endl;
    cout << ini::get("path") << endl;

    cout << "Analysis format" << endl;
    cout << ini::get("format") << endl;

    cout << "Log file path" << endl;
    cout << ini::get("log") << endl;

    cout << "File for saving position" << endl;
    cout << ini::get("pos_file") << endl;

    return 0;
}