n = 626442574871534480199805352060731917605905966527255767734754268955138446012132637596565270246387057067432470831444613839357887267314005960754242524612230176494896246138772417061405506920666164739971711002601986267582075484581829011309553814687074021692829883485121297043859448144073754065272292842925871872493999003871154905966404872892305724596656808800679163281907737952427012440432078143931078717683954059485747896605456325486473058957603492978425273202633252279631007322174560766706641076578821562826167138389839568476314182577741716240148867365320135603640470350090803513050800682579047063696140898646832700909092788905730160801328022337180603709822323338895611724249125219070350933091163486658425889315534751360022644827313555262338895438393918014199511504400801722233209080316673501836187335129188840052643610435425741039573796014200081161571748638107679172634120636176044480206800798158307043976465819557582866888098038472685988224337487913024170867546205052885404472748640603031021818372806166641324690234707553686016700551093110695044566094183051020657152752045110860607409334843741318922115057421930657202204889344169528962863476219313406426651162312996387682101389130078147452374648250705941823694405082925995262417492049
d = 42239494306381294047682070445036763109396195524420453142802983269187738116294827739127850362677333493766636992907117331524520558375583141440300863882409099438957329625818015945105069427688539023542960326540704904350903940771886146771700235090135039776929295743179440798889404479128765723399579810990576739926316151152885141667539605616843904923823587257430172613069720829634785967839073398508192881173160092602156338482071371932263064338215814508928716332490598315816857978801125837741682513960080755697221914102639746297462996060409244305739015287354466625455654645117281241499786200410711643414761838825706909155394025942704163489915642539910012372895407232356527255004041060722897555562295767264996613000383677652363869947449822247541367647151110564416010213383292547940472723642047959727749788196039162983588595064143392201999925510654574756831385146408940969082631588747600596399951329705775738651156514075648063000299553557759788881554927949139556650504155333040879921605217283273959664363818765175016066938607624644938558934524380439232856952263296404076278692282882839398989514669003132307721600982044424188813394525425123489575068065154973197676181332294464471365852618662535957752862951101586261145412194955360215705305041

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
helper = "Input cipher text and I'll tell you if the plaintext is even or not~\n"

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
