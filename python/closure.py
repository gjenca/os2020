
def get_adder(n):

    def to_ret(x):

        return n+x

    return to_ret

def add_debug(f):

    def to_ret(x):
        print(f'volane {f.__name__}({x})')
        return f(x)

    return to_ret
