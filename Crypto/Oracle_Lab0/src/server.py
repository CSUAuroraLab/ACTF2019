from Crypto.Util.number import bytes_to_long
from secret import flag, d

n = 626442574871534480199805352060731917605905966527255767734754268955138446012132637596565270246387057067432470831444613839357887267314005960754242524612230176494896246138772417061405506920666164739971711002601986267582075484581829011309553814687074021692829883485121297043859448144073754065272292842925871872493999003871154905966404872892305724596656808800679163281907737952427012440432078143931078717683954059485747896605456325486473058957603492978425273202633252279631007322174560766706641076578821562826167138389839568476314182577741716240148867365320135603640470350090803513050800682579047063696140898646832700909092788905730160801328022337180603709822323338895611724249125219070350933091163486658425889315534751360022644827313555262338895438393918014199511504400801722233209080316673501836187335129188840052643610435425741039573796014200081161571748638107679172634120636176044480206800798158307043976465819557582866888098038472685988224337487913024170867546205052885404472748640603031021818372806166641324690234707553686016700551093110695044566094183051020657152752045110860607409334843741318922115057421930657202204889344169528962863476219313406426651162312996387682101389130078147452374648250705941823694405082925995262417492049
e = 0x10001


banner = """
 /$$      /$$           /$$                                                     /$$                
| $$  /$ | $$          | $$                                                    | $$                
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$        /$$$$$$    /$$$$$$   
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$      |_  $$_/   /$$__  $$  
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$        | $$    | $$  \ $$  
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/        | $$ /$$| $$  | $$  
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$        |  $$$$/|  $$$$$$/  
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/         \___/   \______/   
                                                                                                   
                                                                                                   
                                                                                                   
  /$$$$$$                               /$$                 /$$           /$$              /$$$$$$ 
 /$$__  $$                             | $$                | $$          | $$             /$$$_  $$
| $$  \ $$  /$$$$$$  /$$$$$$   /$$$$$$$| $$  /$$$$$$       | $$  /$$$$$$ | $$$$$$$       | $$$$\ $$
| $$  | $$ /$$__  $$|____  $$ /$$_____/| $$ /$$__  $$      | $$ |____  $$| $$__  $$      | $$ $$ $$
| $$  | $$| $$  \__/ /$$$$$$$| $$      | $$| $$$$$$$$      | $$  /$$$$$$$| $$  \ $$      | $$\ $$$$
| $$  | $$| $$      /$$__  $$| $$      | $$| $$_____/      | $$ /$$__  $$| $$  | $$      | $$ \ $$$
|  $$$$$$/| $$     |  $$$$$$$|  $$$$$$$| $$|  $$$$$$$      | $$|  $$$$$$$| $$$$$$$/      |  $$$$$$/
 \______/ |__/      \_______/ \_______/|__/ \_______/      |__/ \_______/|_______/        \______/ 
                                                                                                   
"""
helper = "Input cipher text and I'll tell you if the plaintext's hex value is even or not~\n"

print(banner)
print("The flag's cipher is encrypted with RSA and cipher is {}".format(
    pow(bytes_to_long(flag), e, n)))

while True:
    try:
        s = input(helper)
        a = int(s)
        if pow(a, d, n) % 2 == 0:
            print("Even!")
        else:
            print("Odd!")
    except:
        print("What's your mean by {}?".format(s))
        exit()
