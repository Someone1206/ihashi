import os
import sys


def checkinargv(lst):
    for li in lst:
        if li in sys.argv:
            return True
    return False


def helpmode():
    print('Following are the valid args:')
    print('rel  -- compile for release')
    print('dbg  -- compile for debug')
    print('sta  -- compile static library')
    print('dyn  -- compile dynamic library')
    print('help -- help prompt')

    print('To compile dynamic and staic library for releases:')
    print(f'python .{os.sep}build rel sta dyn')
    print('To compile dynamic and staic library for releases and debug:')
    print('rel --- sta, dyn')
    print('dbg --- sta, dyn')
    print(f'python .{os.sep}build rel dbg sta dyn')

if __name__ == '__main__':

    osplat = sys.platform
    compilemode = []
    linkmode = []

    if checkinargv(['help', 'h']):
        helpmode()
        exit(0)

    if checkinargv(['rel']):
        compilemode.append('rel')

    if checkinargv(['dbg']):
        compilemode.append('debug')

    if checkinargv(['sta']):
        linkmode.append('static')

    if checkinargv(['dyn']):
        linkmode.append('dynamic')


    for cm in compilemode:
        pat = os.path.join('libs', osplat, cm)
        os.makedirs(pat, exist_ok=True)
        for lm in linkmode:
            pat = os.path.join('objs', osplat, cm, lm)
            os.makedirs(pat, exist_ok=True)

            os.system(\
                f'make PYCFG_FROM_PY=true PLATFORM={sys.platform} ' + \
                f'COMPILEMODE={cm} LINKMODE={lm}'
            )

    # main()
