iniファイルパーサー
======================
設定ファイル解析

利用方法
------

### コンパイル ###
    
    $ make
    $ ./iniparser
        
### ソース ###

```cpp
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
```

### 結果 ###
```   
$ ./iniparser
Monitored file
/var/log/nginx/access.log
Analysis format
'/^(?<host>\S*)\S*\S*\[(?<time>[^\]]*)\]"GET+(?<path>\S*)+\S*"200\S*"(?<referer>[^\"]*)""(?<agent>[^\"]*)"$/'
Log file path
/var/log/php5-tail.log
File for saving position
/etc/php5-tail/cache/access.pos
```

ライセンス
----------
Copyright &copy; 2013 Yujiro Takahashi  
Licensed under the [MIT License][MIT].  
Distributed under the [MIT License][MIT].  

[MIT]: http://www.opensource.org/licenses/mit-license.php
