/**
 * ini_parse.cpp
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
#include <fstream>
#include <string>
#include <map>

#include <cstring>
#include <cstdlib>

#include "ini_parse.h"

namespace ini {
    /**
     * �i�[
     * @var values_t
     */
    static values_t values;

    /**
     * �u������
     *
     * @access private
     * @param  string search
     * @param  string replace
     * @param  string subject
     * @return string
     */
    std::string _strReplace(std::string search, std::string replace, std::string subject) {
        std::string::size_type  pos(subject.find(search));

        while (pos != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos = subject.find(search, pos + replace.length());
        }

        return subject;
    }

    /**
     * �L�[�ƒl�̊i�[
     *
     * @access private
     * @param  string subject
     * @return void
     */
    void _parse(std::string subject) {
        std::string::size_type  pos(subject.find("="));

        if (pos != std::string::npos) {
            ini::values[subject.substr(0, pos)] = subject.substr(pos + 1);
        }
    }

    /**
     * ini�t�@�C���ǂݍ���
     *
     * @access public
     * @param  char* filename
     * @return bool
     */
    bool load(char* filename) {

        std::ifstream ifs(filename);
        std::string line;

        while (std::getline(ifs, line)) {
            if (line[0] == '[' || line[0] == '#' || line[0] == ';' || line.empty()) {
                continue;
            }

            line = _strReplace("\t", "", line);
            line = _strReplace(" ", "", line);

            _parse(line);
        }

        return true;
    }

    /**
     * �f�[�^�̎擾
     *
     * @access public
     * @param  string filename
     * @return string
     */
    const char* get(std::string key) {
        return values[key].c_str();
    }

    /**
     * ���l�̎擾
     *
     * @access public
     * @param  string filename
     * @return int
     */
    const int value(std::string key) {
        return atoi(values[key].c_str());
    }

    /**
     * �f�[�^�̃_���v
     *
     * @access public
     * @param  string filename
     * @return void
     */
    void dump() {
        ini::values_t::iterator rows;

        for (rows = ini::values.begin(); rows != ini::values.end(); rows++) {
            std::cout << (*rows).first << ":" << (*rows).second << std::endl;
        }
    }
} // namespace ini
