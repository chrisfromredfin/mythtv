#!/usr/bin/env python
# -*- coding: utf-8 -*-
#-----------------------
# Name: cache_null.py
# Python Library
# Author: Raymond Wagner
# Purpose: Null caching engine for debugging purposes
#-----------------------

from cache_engine import CacheEngine

class NullEngine( CacheEngine ):
    """Non-caching engine for debugging."""
    name = 'null'
    def configure(self): pass
    def get(self, key): return None
    def put(self, key, value, lifetime): pass
    def expire(self, key): pass

