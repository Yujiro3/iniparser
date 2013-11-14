/**
 * ini_parse.h
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

#ifndef __INI_PARSE_H__
#define __INI_PARSE_H__

#include <map>
#include <string>

namespace ini {
    /**
     * �L�[�o�����[�z��
     * @typedef std::pair<std::string, std::string>
     */
    typedef std::map<std::string, std::string> values_t;

    /**
     * �t�@�C���ǂݍ���
     *
     * @access public
     * @param  string filename
     * @return bool
     */
    bool load(char* filename);

    /**
     * �f�[�^�̎擾
     *
     * @access public
     * @param  string filename
     * @return string
     */
    const char* get(std::string key);

    /**
     * �f�[�^�̎擾
     *
     * @access public
     * @param  string filename
     * @return int
     */
    const int value(std::string key);

    /**
     * �f�[�^�̃_���v
     *
     * @access public
     * @param  string filename
     * @return void
     */
    void dump();
} // namespace ini
#endif // #ifndef __INI_PARSE_H__
