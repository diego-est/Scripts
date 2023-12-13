from os import system, popen
from time import sleep
from datetime import datetime
from calendar import timegm


def make_bar(start_t: int, end_t: int) -> str:
    bar_len: int = 46
    date = datetime.utcnow()
    now_t: int = timegm(date.utctimetuple())
    percent: float = ((now_t - start_t) / float(end_t - start_t))
    com_c: str = "#" * int(percent * bar_len)
    rem_c: str = "-" * (bar_len - len(com_c))
    seconds: int = (now_t - end_t) % 60
    minutes: int = (now_t - end_t) / 60
    return f"{minutes:0>2.0f}:{seconds:0>2} [{com_c}{rem_c}] {percent:>3.0%}"


rows, cols = popen('stty size', 'r').read().split()
date = datetime.utcnow()
utc_now = calendar.timegm(date.utctimetuple())
bar = make_bar(utc_now - 1800, utc_now).rjust(int(cols))
print(bar)
