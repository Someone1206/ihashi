import os
import os.path as osp
import glob
import sys



def ihashi():
    dirs = {
        'src': osp.join(osp.abspath(os.curdir), 'src'),
        'inc': osp.join(osp.abspath(os.curdir), 'inc'),
        'lib': osp.join(osp.abspath(os.curdir), 'libs', sys.platform),
        'obj': osp.join(osp.abspath(os.curdir), 'objs', sys.platform)
    }

    srcs = []
    objs = []
    maxlen = 0
    for filename in glob.iglob(dirs['src'] + '/**/*.c', recursive=True):
        srcs.append(filename)
        if len(filename) > maxlen:
            maxlen = len(filename)
        objname = filename.replace(dirs['src'], dirs['obj'])
        objname = objname.replace('.c', '.o')
        objs.append(objname)

    dirs['statlib'] = osp.join(dirs['lib'], globals()['cmode'], 'libihashi.a')
    dirs['dynlib'] = osp.join(dirs['lib'], globals()['cmode'], 'libihashi.so')

    print('Building library:')

    print('Creating dir: objs\n', dirs['obj'])
    os.makedirs(dirs['obj'], exist_ok=True)
    print('Creating dir: libs\n', dirs['lib'])
    os.makedirs(dirs['lib'], exist_ok=True);

    objstrslib = ''
    objsstrdll = ''

    for i in range(len(objs)):
        sobj = osp.join(osp.dirname(objs[i]), 'static', globals()['cmode'],  osp.basename(objs[i]))
        dobj = osp.join(osp.dirname(objs[i]), 'dynamic', globals()['cmode'], osp.basename(objs[i]))
        os.makedirs(osp.dirname(sobj), exist_ok=True)
        os.makedirs(osp.dirname(dobj), exist_ok=True)
        cmds = f'gcc -I{str(dirs["inc"])} -c '
        cmds += f'{str(srcs[i])}{" " * (maxlen - len(srcs[i]))}'

        if globals()['cmode'] == 'rel':
            cmds += ' -O3 '
        else:
            cmds += ' -g '

        cmdd = cmds
        cmds += f' -o {sobj}'
        cmdd += f' -fPIC -o {dobj}'

        print(f'\tStatic Obj:\n{cmds}')
        os.system(cmds)
        print(f'\tDynamic Obj:\n{cmdd}')
        os.system(cmdd)

        objstrslib += sobj + ' '
        objsstrdll += dobj + ' '


    os.makedirs(osp.dirname(dirs['statlib']), exist_ok=True)
    os.makedirs(osp.dirname(dirs['dynlib']), exist_ok=True)

    cmds = f'ar rvs {dirs["statlib"]} {objstrslib}'
    cmdd = f'gcc -shared -o {dirs["dynlib"]} {objsstrdll}'

    print('\nStatic Lib:\n' + cmds)
    os.system(cmds)
    print('\nDynamic Lib:\n' + cmdd)
    os.system(cmdd)

    print(f'\n\nIf success:\nStatic:  {dirs["statlib"]}\nDynamic: {dirs["dynlib"]}')


def teste(run: object) -> None:
    print('Tests not yet configured... Prolly will never be.')


def checkinargv(lst: list) -> bool:
    for lstmem in lst:
        if lstmem in sys.argv:
            return True
    return False


def main():

    #
    globals()['cmode'] = 'debug'

    arglib = ['i', 'ihashi', 'lib']
    argrel = ['rel', 'release']
    argtest = ['t', 'test']
    argtestr = ['tr', 'testr']
    arghelp = ['h', 'help']

    if checkinargv(arghelp):
        print('Used python instead of GNU Make... why not?')
        print('\'Tis a pretty smol lib, also wanted to test my python skills')
        print('Arguments:')
        print((', '.join(arglib)) + '\t to build ihashi (both dynamic and static)')
        print((', '.join(argrel)) + '\t build for release, default is debug')
        print((', '.join(argtest)) + '\t\t build test(if configured)')
        print((', '.join(argtestr)) + '\t build test(if configured) and run it')
        print(', '.join(arghelp) + '\t\t show this help pmpt')
        exit(0)

    if len(sys.argv) == 1 or checkinargv(arglib):
        ihashi()

    if checkinargv(argrel):
        globals()['cmode'] = 'rel'

    if checkinargv(argtest):
        teste(None)
    elif checkinargv(argtestr):
        teste(True)




if __name__ == '__main__':
    main()
