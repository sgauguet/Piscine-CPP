#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : Form(copy) {
	*this = copy;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & b) {
	Form::operator=(b);
	return *this;
}

void ShrubberyCreationForm::executeAction(void) const {
	std::string filename(this->getTarget());
	filename += "_shrubbery";
	std::ofstream file(filename.data(), std::ofstream::out);
	if (!file.good()) {
		return ;
	}
	file << this->_content;
	file.close(); 
	return ;
}

 std::string const ShrubberyCreationForm::_content = 
"                                                   `.. / .-.                                        \n"
"                                           .` . . ``/::--/.                                         \n"
"                                  -:`    .//-`-:+ ..--d:/`` .``.`                                   \n"
"                             `  :.::.  ..`:://``/// .oh`/-/.++`/-`` `                               \n"
"                          `  `--`s/ --`.+-+-//.::-o `m-`/+/-h:.+.`:.: `                             \n"
"                        ``:` `./-m`-/: -./s:`//-.`//h:.:.+o.d:----/o-:` `                           \n"
"                        .-+:  .`/m`/.--y`.h/. o.::`m+:-y:/+.d:`.//-:``` : `                         \n"
"                         `.++`- `N/. ./h`.oy. +-/. N+/--yy.`+y o+-:-`/`:/`o/                        \n"
"                        .-:-:os/.N- .:-/o.-:++h`+.`N/ +oy:- sy/s-.s-:-./-s+.                        \n"
"                    `` `-``:-..:ody.--:/+d/+++m+-` N- h-`++oy:-`:`.s`.-o:h.``:`                     \n"
"                    ``+`-/ .-+--:.+yy- `:y --.:d`  N- m:..sh:-+-. +/:: +os`:/...`                   \n"
"                    `.-/-y./`++/+.`./hs.s/..:-`oo`-N./o...m:.h-.:`d-:` .m/`+//--`                   \n"
"                   `.`  .h/-`/+oso++//hdy`-.//+./ydy/o:``-N/+-.`--d:  `sh::-..:.                    \n"
"                  `.:-:-`sh-``:.:s:````om`+.`h:/`hNs-`::.:dy.--`  /o-oy+.-` .o.:`                   \n"
"                 `-:/:+:.-:oss/.`y:::. .N+-: d:`/Ns`: :o:.:do-.` `sds:-..--`++-.`                   \n"
"                  `.``-:::/+/+yh+s-o:o- hh`:+o  ym  :s/-`.`-mo` .yy:-//.`-:-h.-/:-``                \n"
"                  -/`` .:./ `..-ym.-/o:`/N/`y-.`yN  .h`+/:` -ms.dy:/++/o://yy+o+::-```              \n"
"                . -y-.`oo-`.`    om.-y`../dyd-  yM: sy:::..`./Nmy::-.  +:-:h:`/` -`::.              \n"
"               `o. h:.`-h .s:  .  hh`y-:` `oNy- +Ndsy` .s-:``+Mm`./ :-:--os---s` oo-:`              \n"
"                -+`h`/: y-o- ./.  :Mo: .`` --hNo`dMd  ``-d` `sN/`.+.s: /h: ..`y:.h`o:``             \n"
"            .    -y- ./-`yoo` +:. `Ns  :-. s``sNd+NN- .-/so.sNy .//y.``d:/./. h-+ys+.--`            \n"
"           `:: -  h``: .y` -d`.s`  No :-/  h: `oNNmNh` ``.dNNo`.`:d+`:.m`-y:` y-+s . `:.-`          \n"
"           .-soo`.y`.+o.h/::yysdo+/hd` .o`-y:/-`dNNNNy.-sNNhh:+.`+ds/.:y-+: ../hys /-:::.-`         \n"
"           `-`-/osy.  /:y`-`. `.``-odh` :+y:/-./+NNNNNmNNh-`ss-`sd/``.dh-``-`` /N-://+:-:-`         \n"
"         .-/:o../o+ho `-s/+-..:-:: --hm-/d/:.o-o`NmNNNNs--:+d:+ds-..:ds  /:../yhohs/--::`           \n"
"          `.///+..  /h..h::.:/..+/o++ +mmo---o:` hNNNNs.`-/myd+`.- +my/ohhydNhso:   ...`-           \n"
"            `//o/`.--od/y```.+/:-o./y +oomms-h:. sNNNN/ `:Nm+.:-/:yNNdo:```/:.`--..                 \n"
"           `. .--s    odo  -+//osy: /sm` -hNmy`  yMMMM-.sNd//yhyhNNN+...+so++os+++.  .`             \n"
"         .-.`/  `/o`  `ym` ``.` `y+  .d-`::oNN/ `NMMMM/mNNs//.`oNo`./yo/:--.-o-:`../+:-             \n"
"          `:+oooo/oo+hssdd+.     /o`-:/so+/ oNN/oNMMMMNN+`.- -hm/    ..-+////--:+o/.````            \n"
"         `..`..`.`.:+/---+yys/-` `y:``  `/h-`oNNNMMMMMN/ -/.+md+oyhssooho::/++h+--.::`.             \n"
"          .--/:::-.` /h:-.``./osssydsyso+::+soNMMMMMMN/  +smNhyo/.://+-.-+-..``:---.```             \n"
"          `.-:+``:/:/+/  `--:.--:::/dhsyhmms-`:NMMMMMs .omNd:`../-.  `:/`. /.` o:::--               \n"
"              ` :````:.   . :yo+oho+-`  `.sNm+oMMMMNM+omMMNhyyydy+-.-:../o+/::/-..`                 \n"
"                `    `..-::+o.  s.         +NNNMMMMMMNNNy/-..``-s:s+//:`.-.:o/-`                    \n"
"                      `..---..-oo           +NMMMMMMMNs-      `-s...-+::``  .:..                    \n"
"                        `-::-//-/`           oNNMMMMN/          :-`  `                              \n"
"                        ` ` -` -.            :MMMMMMM.           .                                  \n"
"                                             -MMMMMMM-                                              \n"
"                                             .MMMMMMN/                                              \n"
"                                             `NMMMMMMs                                              \n"
"                                              dMMMMMMh                                              \n"
"                                              yMMMMMMN`                                             \n"
"                                              oMMMMMMM:                                             \n"
"                                              :MMMMMMMy                                             \n"
"                                              `MMMMMMMN-                                            \n"
"                                               NMMMMMMMh                                            \n"
"                                              `NMMMMMMMN-                                           \n"
"                                              .MMMMMMMMMs                                           \n"
"                                              -ooooooooo+                                           \n";
