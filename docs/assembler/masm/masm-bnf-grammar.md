---
title: Gramática do Microsoft Macro Assembler BNF
description: BNF descrição de MASM para x64.
ms.date: 12/17/2019
helpviewer_keywords:
- MASM (Microsoft Macro Assembler), BNF reference
ms.openlocfilehash: 29eae0b110f99f1f417e153f18aa2ac3aff5c69b
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75322802"
---
# <a name="microsoft-macro-assembler-bnf-grammar"></a>Gramática do Microsoft Macro Assembler BNF

Esta página contém uma descrição BNF da gramática do MASM. Ele é fornecido como um suplemento para os tópicos de referência e não é garantido que esteja completo. Consulte os tópicos de referência para obter informações completas sobre palavras-chave, parâmetros, operações e assim por diante.

Para ilustrar o uso do BNF, o diagrama a seguir mostra a definição da diretiva TYPEDEF, começando com o *typedefDir*nonterminal.

![Exemplo de BNF de MASM](media/bnf.png)

As entradas em cada chave horizontal são terminais (como **NEAR16**, **NEAR32**, **FAR16**e **FAR32**) ou não-Terminals (como *qualificador*, *qualificador*, *distância*e *protoSpec*) que podem ser definidos ainda mais. Cada não terminal em itálico na definição de *typedefDir* também é uma entrada no bnf. Três pontos verticais indicam uma definição de ramificação para um não terminal que, para fins de simplicidade, essa figura não ilustra.

A gramática BNF permite definições recursivas. Por exemplo, a gramática usa qualificador como uma definição possível para qualifiedtype, que também é um componente da definição para qualificador. O símbolo "|" especifica uma opção entre expressões alternativas, por exemplo, *endOfLine* | *Comentário*. Chaves duplas especifique um parâmetro opcional, por exemplo, ⟦ *macroParmList* ⟧. Os colchetes não aparecem na verdade no código-fonte.

## <a name="masm-nonterminals"></a>MASM não terminais

*;;* \
&nbsp;&nbsp;&nbsp;&nbsp;*endOfLine* | *Comentário*

*= Dir*\
&nbsp;&nbsp;&nbsp;&nbsp;*id* = *immExpr* ;;

\ *addOp*
&nbsp;&nbsp;&nbsp;&nbsp;+ | -

\ *aExpr*
&nbsp;&nbsp;&nbsp;&nbsp;*prazo* | *aExpr* && *termo*

\ *altId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *arbitraryText*
&nbsp;&nbsp;&nbsp;&nbsp;*charlist*

\ *asmInstruction*
&nbsp;&nbsp;&nbsp;&nbsp;*mnemônico* ⟦ *exprlist* ⟧

\ *assumeDir*
&nbsp;&nbsp;&nbsp;&nbsp;**supor** a *presumir* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;| não **assuma nada** ;;

*presumir*\
&nbsp;&nbsp;&nbsp;&nbsp;*assumeRegister* | *presumir* , *assumeRegister*\

\ *assumeReg*
&nbsp;&nbsp;&nbsp;*registrar* &nbsp;: *assumeVal*

\ *assumeRegister*
&nbsp;&nbsp;&nbsp;&nbsp;*assumeSegReg* | *assumeReg*

\ *assumeSegReg*
&nbsp;&nbsp;&nbsp;&nbsp;*segmentRegister* : *assumeSegVal*

\ *assumeSegVal*
&nbsp;&nbsp;&nbsp;&nbsp;*frameExpr* | **nada** | **erro**

\ *assumeVal*
&nbsp;&nbsp;&nbsp;&nbsp;*qualifiedtype* | **nada** | **erro**

\ *bcdConst*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *Sign* ⟧ *decNumber*

\ *binaryOp*
&nbsp;&nbsp;&nbsp;&nbsp;= = |! = | > = | < = | > | < | &

\ *bitDef*
&nbsp;&nbsp;&nbsp;&nbsp;*bitFieldId* : *BitFieldSize* ⟦ = *constExpr* ⟧

\ *bitDefList*
&nbsp;&nbsp;&nbsp;&nbsp;*bitDef* | *bitDefList* , ⟦;; ⟧ *bitDef*

\ *bitFieldId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *bitFieldSize*
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ *blockStatements*
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva*\
&nbsp;&nbsp;&nbsp;&nbsp;|  **. CONTINUAR** **. SE** *cExpr* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. INTERROMPER** ⟦ **. SE** *cExpr* ⟧

*bool*\
&nbsp;&nbsp;&nbsp;&nbsp;**TRUE** | **false**

\ *byteRegister*
&nbsp;&nbsp;&nbsp;&nbsp;AL | AH | CL | CH | DL | DH | BL | BH | R8B | R9B | R10B | R11B | R12B | R13B | R14B | R15B

\ *cExpr*
&nbsp;&nbsp;&nbsp;&nbsp;*aExpr* | *cExpr* || *aExpr*

\ de *caracteres*
&nbsp;&nbsp;&nbsp;&nbsp;qualquer caractere com ordinal no intervalo de 0 a 255, exceto a alimentação de linha (10).

\ *charlist*
&nbsp;&nbsp; *&nbsp;caractere de &nbsp;caractere* | caracteres *charlist*

*className*\
&nbsp;&nbsp;&nbsp;&nbsp;*cadeia de caracteres*

\ *commDecl*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *nearfar* ⟧ ⟦ *LangType* ⟧ *ID* : *commtype*\
&nbsp;&nbsp;&nbsp;&nbsp;⟦: *constExpr* ⟧

\ *commDir*
&nbsp;&nbsp;&nbsp;&nbsp;**COMM**\
&nbsp;&nbsp;&nbsp;&nbsp;*commlist* ;;

*comentário*\
&nbsp;&nbsp;&nbsp;&nbsp;; *texto* ;;

\ *commentDir*
&nbsp;&nbsp;&nbsp;*delimitador* de **Comentário** &nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp;de *texto*\
&nbsp;&nbsp;&nbsp;*texto* *delimitador* de *texto* &nbsp;;;

\ de *commlist*
&nbsp;&nbsp;&nbsp;&nbsp;*commDecl* | *commlist* , *commDecl*

\ de *commtype*
&nbsp;&nbsp;&nbsp;*tipo* de &nbsp; | *constExpr*

*constante*\
&nbsp;&nbsp;&nbsp;&nbsp;*dígitos* ⟦ *radixOverride* ⟧

\ *constExpr*
&nbsp;&nbsp;&nbsp;*expr* &nbsp;

\ *contextDir*
&nbsp;&nbsp;&nbsp;&nbsp;**PUSHCONTEXT** *contextItemList* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;**POPCONTEXT** *contextItemList* ;;

\ *contextItem*
&nbsp;&nbsp;&nbsp;&nbsp;**presume** | **base** | **lista** | **CPU** | **todos**

\ *contextItemList*
&nbsp;&nbsp;&nbsp;&nbsp;*contextItem* | *contextItemList* , *contextItem*

\ *controlBlock*
&nbsp;&nbsp;&nbsp;&nbsp;*whileBlock* | *repeatBlock*

\ *controlDir*
&nbsp;&nbsp;&nbsp;&nbsp;*controlIf* | *controlBlock*

\ *controlElseif*
&nbsp;&nbsp;&nbsp;&nbsp; **. ELSEIF** &nbsp;&nbsp;&nbsp;&nbsp;*cExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva* \
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *controlElseif* ⟧

\ *controlIf*
&nbsp;&nbsp;&nbsp;&nbsp; **. SE** &nbsp;&nbsp;&nbsp;&nbsp;*cExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva*\
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *controlElseif* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;⟦ **. ELSE** ;; \
&nbsp;&nbsp;&nbsp;&nbsp;[*diretivolist*⟧ \
&nbsp;&nbsp;&nbsp;&nbsp; **. ENDIF** ;;

\ do *coprocessador*
&nbsp;&nbsp;&nbsp;&nbsp;. 8087 |. 287 |. 387 |. NO87

\ *crefDir*
&nbsp;&nbsp;&nbsp;&nbsp;*crefOption* ;;

\ *crefOption*
&nbsp;&nbsp;&nbsp;&nbsp; **.\ CREF**
&nbsp;&nbsp;&nbsp;&nbsp;|  **. XCREF** ⟦ *idList* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;|  **. Nocref** ⟦ *idList* ⟧

\ *cxzExpr*
&nbsp;&nbsp;&nbsp;&nbsp;*expr*\
&nbsp;&nbsp;&nbsp;&nbsp;|! *expr*\
&nbsp;&nbsp;&nbsp;&nbsp;| *expr* = = expr \
&nbsp;&nbsp;&nbsp;&nbsp;| *expr* ! = expr

\ *dataDecl*
&nbsp;&nbsp;&nbsp;&nbsp;DB | DW | DD | DF | DQ | DT | *tipo de dados* | *typeId*

\ *dataDir*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *ID* ⟧ *DataItem* ;;

\ de *DataItem*
&nbsp;&nbsp;&nbsp;&nbsp;*dataDecl* *scalarInstList*\
&nbsp;&nbsp;&nbsp;&nbsp;| *structTag* *structInstList*\
&nbsp;&nbsp;&nbsp;&nbsp;| *typeId* *structInstList*\
&nbsp;&nbsp;&nbsp;&nbsp;| *unionTag* *structInstList*\
&nbsp;&nbsp;&nbsp;&nbsp;| *recordTag* *recordInstList*

*tipo de dados*\
&nbsp;&nbsp;&nbsp;&nbsp;BYTE | SBYTE | PALAVRA | GUMES | DWORD | SDWORD | FWORD | QWORD | SQWORD | TBYTE | OWORD | REAL4 | REAL8 | REAL10 | MMWORD | XMMWORD | YMMWORD

\ *decdigit*
&nbsp;&nbsp;&nbsp;&nbsp;0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 99

\ *decNumber*
&nbsp;&nbsp;&nbsp;&nbsp;*decdigit*\
&nbsp;&nbsp;&nbsp;&nbsp;| *decNumber* *decdigit*

\ do *delimitador*
&nbsp;&nbsp;&nbsp;&nbsp;qualquer caractere, exceto *whiteSpaceCharacter*

*dígitos*\
&nbsp;&nbsp;&nbsp;&nbsp;*decdigit*\
&nbsp;&nbsp;&nbsp;&nbsp;*dígitos* de | *decdigit*\
&nbsp;&nbsp;&nbsp;&nbsp;*dígitos* de | hexdigit

\ de *diretiva*
&nbsp;&nbsp;&nbsp;&nbsp;*generalDir* | *segmentDef*

\ de *diretivas*
&nbsp; *&nbsp;&nbsp;diretiva &nbsp;diretiva* * | política* de *diretiva*

\ de *distância*
&nbsp;&nbsp;&nbsp;&nbsp;*nearfar* | **NEAR16** | **NEAR32** | **FAR16** | **FAR32**

\ *E01*
&nbsp;&nbsp;&nbsp;&nbsp;E01 *orOp* *E02* | *E02*

\ *E02*
&nbsp;&nbsp;&nbsp;&nbsp;E02 **e** *E03* | *E03*

\ *E03*
&nbsp;&nbsp;&nbsp;&nbsp;**não** *E04* | *E04*

\ *E04*
&nbsp;&nbsp;&nbsp;&nbsp;*E04* *relOp* *E05* | *E05*

\ *E05*
&nbsp;&nbsp;&nbsp;&nbsp;*E05* *addOp* *E06* | *E06*

\ *E06*
&nbsp;&nbsp;&nbsp;&nbsp;*E06* *mulOp* *e07* | *E06* *shiftOp* *E07* | *E07*

\ *E07*
&nbsp;&nbsp;&nbsp;&nbsp;*E07* *addOp* *E08* | *E08*

\ *E08*
&nbsp;&nbsp;&nbsp;&nbsp; *E09* alta\
&nbsp;&nbsp;&nbsp;&nbsp;|  *E09* baixo\
&nbsp;&nbsp;&nbsp;&nbsp;| **HIGHWORD** *E09*\
&nbsp;&nbsp;&nbsp;&nbsp;| **LOWWORD** *E09*\
&nbsp;&nbsp;&nbsp;&nbsp;| *E09*

\ *E09*
&nbsp;&nbsp;&nbsp;&nbsp;**offset** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| **seg** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| **LROFFSET** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| **tipo** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| **este** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| *E09* **PTR** *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| *E09* : *E10*\
&nbsp;&nbsp;&nbsp;&nbsp;| *E10*

\ *E10*
&nbsp;&nbsp;&nbsp;&nbsp;*E10* . \ *E11*
&nbsp;&nbsp;&nbsp;&nbsp;| *E10* ⟦ *expr* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;| *E11*

\ *E11*
&nbsp;&nbsp;&nbsp;&nbsp;( *expr* ) \
&nbsp;&nbsp;&nbsp;&nbsp;| ⟦ *expr* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;*ID* de **largura** | \
&nbsp;&nbsp;&nbsp;&nbsp;|  *id* da máscara\
&nbsp;&nbsp;&nbsp;&nbsp;| de **tamanho** *sizeArg*\
&nbsp;&nbsp;&nbsp;&nbsp;| **sizeof** *sizeArg*\
&nbsp;&nbsp;&nbsp;&nbsp;*ID* de **comprimento** | \
&nbsp;&nbsp;&nbsp;&nbsp;| **LENGTHOF** *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| *recordConst*\
&nbsp;&nbsp;&nbsp;&nbsp;*cadeia* de | \
&nbsp;&nbsp;&nbsp;&nbsp;| *constante*\
&nbsp;&nbsp;&nbsp;&nbsp;| *tipo*\
&nbsp;&nbsp;&nbsp;&nbsp;| *id*\
&nbsp;&nbsp;&nbsp;&nbsp;| **$**\
&nbsp;&nbsp;&nbsp;&nbsp;| *segmentRegister*\
&nbsp;&nbsp;&nbsp;&nbsp;| *registrar*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ST**\
&nbsp;&nbsp;&nbsp;&nbsp;| **St** ( *expr* )

\ *echoDir*
&nbsp;&nbsp;&nbsp;&nbsp;**ECHO**\
&nbsp;&nbsp;&nbsp;&nbsp;*arbitraryText* ;; \
%**out** *arbitraryText* ;; \

\ *elseifBlock*
&nbsp;&nbsp;&nbsp;&nbsp;*elseifStatement* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva*\
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *elseifBlock* ⟧ \

\ *elseifStatement*
&nbsp;&nbsp;&nbsp;&nbsp;**ElseIf** *constExpr*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ElseIf** *constExpr*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFB** *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFNB** *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFDEF** *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFNDEF** *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFDIF** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFDIFI** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFIDN** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIFIDNI** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIF1**\
&nbsp;&nbsp;&nbsp;&nbsp;| **ELSEIF2**

\ *endDir*
&nbsp;&nbsp;&nbsp;&nbsp;**end** ⟦ *immExpr* ⟧;;

\ *endpDir*
&nbsp;&nbsp;&nbsp;&nbsp;*procid* **ENDP** ;;

\ *endsDir*
&nbsp;&nbsp;&nbsp;*ID* de &nbsp;**termina** ;;

\ *equDir*
&nbsp;&nbsp;&nbsp;&nbsp;*Textmacroid* **equ** *equType* ;;

\ *equType*
&nbsp;&nbsp;&nbsp;&nbsp;*immExpr* | *textliteral*

\ *errorDir*
&nbsp;&nbsp;&nbsp;&nbsp;*errorOpt* ;;

\ *errorOpt*
&nbsp;&nbsp;&nbsp;&nbsp; **. ERR** ⟦ *textitem* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRE** *constExpr* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRNZ** *constExpr* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRB** *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRNB** *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRDEF** *ID* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRNDEF** *ID* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRDIF** *textitem* , *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRDIFI** *textitem* , *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRIDN** *textitem* , *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERRIDNI** *textitem* , *textitem* ⟦ *optText* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERR1** ⟦ *textitem* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. ERR2** ⟦ *textitem* ⟧

\ *exitDir*
&nbsp;&nbsp;&nbsp;&nbsp; **. EXIT** &nbsp;&nbsp;&nbsp;&nbsp;⟦ *expr* ⟧;;

\ *exitmDir*
&nbsp;&nbsp;&nbsp;&nbsp;: EXITe | SAIR do *textitem*

\ de *expoente*
&nbsp;&nbsp;&nbsp;&nbsp;*E ⟦ ⟧* *decNumber*

*expr*\
&nbsp;&nbsp;&nbsp;&nbsp; *E05* curto\
&nbsp;&nbsp;&nbsp;&nbsp;|  **. Digite** E01 \
&nbsp;&nbsp;&nbsp;&nbsp;| **OPATTR** *E01*\
&nbsp;&nbsp;&nbsp;&nbsp;| *E01*

*exprlist*\
&nbsp;&nbsp;&nbsp;&nbsp;*expr* | *exprlist* , *expr*

\ *externDef*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *LangType* ⟧ *ID* ⟦ ( *altId* ) ⟧: *externtype*

\ *externDir*
&nbsp;&nbsp;&nbsp;&nbsp;*externKey* *externlist* ;;

\ *externKey*
&nbsp;&nbsp;&nbsp;&nbsp;**EXTRN** | **externo** | **EXTERNDEF**

\ de *externlist*
&nbsp;&nbsp;&nbsp;&nbsp;*externDef* | *externlist* , ⟦;; ⟧ *externDef*

\ *externtype*
&nbsp;&nbsp;&nbsp;&nbsp;o **ABS** | *qualifiedtype*

\ *fieldAlign*
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ *fieldInit*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *initvalue* ⟧ | *structInstance*

\ *fieldInitList*
&nbsp;&nbsp;&nbsp;&nbsp;*fieldInit* | *fieldInitList* , ⟦;; ⟧ *fieldInit*

\ *Filechar*
&nbsp;&nbsp;&nbsp;*delimitador* &nbsp;

\ *Filecharlist*
&nbsp;&nbsp;&nbsp;&nbsp;*filechar* | *filecharlist* *filechar*

*filespec*\
&nbsp;&nbsp;&nbsp;&nbsp;*Filecharlist* | o *textliteral*

*flagname*\
&nbsp;&nbsp;&nbsp;&nbsp;**zero?** | **transportar?**Estouro de  |  **?** | **assinar?**Paridade de  |  **?**

\ *floatNumber*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *Sign* ⟧ *decNumber* . ⟦ *decNumber* ⟧ ⟦ *expoente* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;*dígitos* de | R | *dígitos* r

\ *forcDir*
&nbsp;&nbsp;&nbsp;&nbsp;**forçada** | **IRPC**

\ *forDir*
&nbsp;&nbsp;&nbsp;&nbsp;**para** | **IRP**

\ *forParm*
&nbsp;&nbsp;&nbsp;&nbsp;*ID* ⟦: *forParmType* ⟧

\ *forParmType*
&nbsp;&nbsp;&nbsp;&nbsp;**req** | = *Textliteral*

\ *fpuRegister*
&nbsp;&nbsp;&nbsp;&nbsp; *expr* de St

\ *frameExpr*
&nbsp;&nbsp;&nbsp;&nbsp; *ID* seg\
&nbsp;&nbsp;&nbsp;&nbsp;| **DGROUP** : *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| *segmentRegister* : *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;*ID* de | 

\ *generalDir*
&nbsp;&nbsp;&nbsp;&nbsp;*modelDir* | *segOrderDir* | *nameDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *includeLibDir* | *commentDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *groupDir* | *assumeDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *structDir* | *recordDir* | *typedefDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *externDir* | *publicDir* | *commDir* | *protoTypeDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *equDir* | = Dir |\ *textDir*
&nbsp;&nbsp;&nbsp;&nbsp;| *contextDir* | *optionDir* | *processorDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *radixDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *titleDir* | *pageDir* | *listDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *crefDir* | *echoDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *ifDir* | *errorDir* | *includeDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *macroDir* | *macroCall* | *macroRepeat* | *purgeDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *macroWhile* | *macroFor* | *macroForc*\
&nbsp;&nbsp;&nbsp;&nbsp;| *aliasDir*

\ *gpRegister*
&nbsp;&nbsp;&nbsp;&nbsp;AX | EAX | CX | ECX | DX | EDX | BX | EBX | DI | EDI | SI | ESI | BP | EBP | SP | ESP | RSP | R8W | R8D | R9W | R9D | R12D | R13W | R13D | R14W | R14D

\ *groupDir*
&nbsp;&nbsp; *&nbsp;&nbsp;GroupId* **Group** *segIdList*

\ *GroupId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *hexdigit*
&nbsp;&nbsp;&nbsp;&nbsp;um | b | c | d | e | f | A | B | C | D | E | Fixo

*id*\
&nbsp;&nbsp;&nbsp;&nbsp;o primeiro caractere do identificador pode ser um caractere alfabético de letras maiúsculas ou minúsculas (`[A–Za-z]`) ou qualquer um destes quatro caracteres: `@ _ $ ?` os caracteres restantes podem ser qualquer um dos mesmos caracteres ou um dígito decimal (`[0–9]`). O comprimento máximo é de 247 caracteres.

\ *idList*
&nbsp;&nbsp;&nbsp;&nbsp;*id* | *idList* , *ID*

\ *ifDir*
&nbsp;&nbsp;&nbsp;&nbsp;*ifStatement* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*diretiva*\
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *elseifBlock* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;⟦ **else** ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*diretivolist* ⟧;; \

\ *ifStatement*
&nbsp;&nbsp;&nbsp;&nbsp;**se** o *constExpr*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IFE** *constExpr*\
&nbsp;&nbsp;&nbsp;&nbsp;| de *Timeitem*\ **IFB**
&nbsp;&nbsp;&nbsp;&nbsp;| **IFNB** *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ifdef** *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| **ifndef** *ID*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IFDIF** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IFDIFI** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IFIDN** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IFIDNI** *textitem* , o *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **IF1**\
&nbsp;&nbsp;&nbsp;&nbsp;| **IF2**

\ *immExpr*
&nbsp;&nbsp;&nbsp;*expr* &nbsp;

\ *includeDir*
&nbsp;&nbsp;&nbsp;&nbsp;**incluir** *filespec* ;;

\ *includeLibDir*
&nbsp;&nbsp;&nbsp;&nbsp;**INCLUDELIB** *filespec* ;;

\ *initvalue*
&nbsp;&nbsp;&nbsp;&nbsp;*immExpr*\
&nbsp;&nbsp;&nbsp;&nbsp;*cadeia* de | \
&nbsp;&nbsp;&nbsp;&nbsp;|? \
&nbsp;&nbsp;&nbsp;&nbsp;| o **dup** de *constExpr* ( *scalarInstList* )
&nbsp;&nbsp;&nbsp;&nbsp;| *floatNumber*\
&nbsp;&nbsp;&nbsp;&nbsp;| *bcdConst*

\ *inSegDir*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *labelDef* ⟧ *inSegmentDir*

\ *inSegDirList*
&nbsp;&nbsp;&nbsp;&nbsp;*inSegDir* | *inSegDirList* *inSegDir*

\ *inSegmentDir*
&nbsp;&nbsp;&nbsp;*instrução* &nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp;| *dataDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *controlDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *startupDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *exitDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *offsetDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *labelDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *procDir* ⟦ *LocalDirList* ⟧ ⟦ *inSegDirList* ⟧ *endpDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *invokeDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *generalDir*

\ *instrPrefix*
&nbsp;&nbsp;&nbsp;&nbsp;**REP** | **REPE** | **REPZ** | **REPNE** | **REPNZ** | **Lock**

\ de *instruções*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *instrPrefix* ⟧ *asmInstruction*

\ *invokeArg*
&nbsp;&nbsp;&nbsp;&nbsp;*registrar* :: *registrar* | *expr* | o **endereço** *expr*

\ *invokeDir*
&nbsp;&nbsp;&nbsp;&nbsp;**invocar** *expr* ⟦, ⟦;; ⟧ *invokelist* ⟧;;

*invokelist*\
&nbsp;&nbsp;&nbsp;&nbsp;*invokeArg* | *invokelist* , ⟦;; ⟧ *invokeArg*

*palavra-chave*\
&nbsp;&nbsp;&nbsp;&nbsp;qualquer palavra reservada.

\ de *palavras-chave*
&nbsp;&nbsp; *&nbsp;&nbsp;palavra-chave* * | palavra-chave*

\ *labelDef*
&nbsp;&nbsp;&nbsp;*ID* de &nbsp;: | *ID* :: | @@:

\ *labelDir*
&nbsp;&nbsp;&nbsp;**rótulo** da *ID* de &nbsp;*qualificado* ;;

\ de *LangType*
&nbsp;&nbsp;&nbsp;&nbsp;**C** | **Pascal** | **Fortran** | **Basic** | **syscall** | **stdcall**

\ *listDir*
&nbsp;&nbsp;&nbsp;&nbsp;*listOption* ;;

\ *listOption*
&nbsp;&nbsp;&nbsp;&nbsp; **. LISTAr**\
&nbsp;&nbsp;&nbsp;&nbsp;|  **.** \ da lista
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ XLIST**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ LISTALL**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ LISTIF**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ LFCOND**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ NOLISTIF**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ SFCOND**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.\ TFCOND**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.**  | LISTMACROALL **.\ LALL**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.**  | NOLISTMACRO **.\ SALL**
&nbsp;&nbsp;&nbsp;&nbsp;|  **.**  | LISTMACRO **.\ XALL**

\ *localDef*
&nbsp;&nbsp;&nbsp;&nbsp;**local** *idList* ;;

\ *localDir*
&nbsp;&nbsp;&nbsp;&nbsp;**local** *ParmList* ;;

\ *localDirList*
&nbsp;&nbsp;&nbsp;&nbsp;*localDir* | *localDirList* *localDir*

\ *locallist*
&nbsp;&nbsp;&nbsp;&nbsp;*localDef* | *locallist* *localDef*

\ *macroArg*
 % \ *constExpr*
&nbsp;&nbsp;&nbsp;&nbsp;| %*Textmacroid*\
&nbsp;&nbsp;&nbsp;&nbsp;| %*macroFuncId* ( *macroArgList* ) \
&nbsp;&nbsp;&nbsp;&nbsp;*cadeia* de | \
&nbsp;&nbsp;&nbsp;&nbsp;| *arbitraryText*\
&nbsp;&nbsp;&nbsp;&nbsp;| < *arbitraryText* >

\ *macroArgList*
&nbsp;&nbsp;&nbsp;&nbsp;*macroArg* | *macroArgList* , *macroArg*

\ *macroBody*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *locallist* ⟧ *macroStmtList*

\ *macroCall*
&nbsp;&nbsp;&nbsp;&nbsp;*ID* *macroArgList* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*ID* do | ( *macroArgList* )

\ *macroDir*
&nbsp;&nbsp;&nbsp;**MACRO** &nbsp;*ID* ⟦ *macroParmList* ⟧;; \
&nbsp;&nbsp;&nbsp;&nbsp;*macroBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**ENDM** ;;

\ *macroFor*
&nbsp;&nbsp;&nbsp;&nbsp;*forDir* *ForParm* , < *macroArgList* >;; \
&nbsp;&nbsp;&nbsp;&nbsp;*macroBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**ENDM** ;;

\ *macroForc*
&nbsp;&nbsp;&nbsp;&nbsp; *ID* forcDir, *textliteral* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*macroBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**ENDM** ;;

\ *macroFuncId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ de *macroid*
&nbsp;&nbsp;&nbsp;&nbsp;*macroProcId* | *macroFuncId*

\ *macroIdList*
&nbsp;&nbsp;&nbsp;&nbsp;*macroid* | *macroIdList* , *nomedamacro*

\ *macroLabel*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *macroParm*
&nbsp;&nbsp;&nbsp;&nbsp;*ID* ⟦: *parmtype* ⟧

\ *macroParmList*
&nbsp;&nbsp;&nbsp;&nbsp;*macroParm* | *macroParmList* , ⟦;; ⟧ *macroParm*

\ *macroProcId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *macroRepeat*
&nbsp;&nbsp;&nbsp;&nbsp;*repeatDir* *constExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*macroBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**ENDM** ;;

\ *macroStmt*
&nbsp;&nbsp;&nbsp;*diretiva* &nbsp; \
&nbsp;&nbsp;&nbsp;&nbsp;| *exitmDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| : *macroLabel*\
&nbsp;&nbsp;&nbsp;&nbsp;| **GOTO**\
&nbsp;&nbsp;&nbsp;&nbsp;*macroLabel*

\ *macroStmtList*
&nbsp;&nbsp;&nbsp;&nbsp;*macroStmt* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;| *macroStmtList* *macroStmt* ;; \

\ *macroWhile*
&nbsp;&nbsp;&nbsp;&nbsp;**enquanto** *constExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*macroBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**ENDM** ;;

\ *mapType*
&nbsp;&nbsp;&nbsp;&nbsp;**tudo** | **nenhum** | não **público**

\ *memOption*
&nbsp;&nbsp;&nbsp;&nbsp;**TINY** | **Small** | **médio** | **Compact** | **grande** | **enorme** | **simples**

\ *mnemônico*
&nbsp;&nbsp;&nbsp;nome da instrução &nbsp;.

\ *modelDir*
&nbsp;&nbsp;&nbsp;&nbsp; **.** \ de modelo
&nbsp;&nbsp;&nbsp;&nbsp;*memOption* ⟦, *modelOptlist* ⟧;;

\ *modelOpt*
&nbsp;&nbsp;&nbsp;&nbsp;*langtype* | *stackOption*

\ *modelOptlist*
&nbsp;&nbsp;&nbsp;&nbsp;*modelOpt* | *modelOptlist* , *modelOpt*

\ de *módulo*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *diretivolist* ⟧ *endDir*

\ *mulOp*
&nbsp;&nbsp;&nbsp;&nbsp;\* | / | **Mod**

\ *nameDir*
&nbsp;&nbsp;&nbsp;**nome** do &nbsp;\
&nbsp;&nbsp;&nbsp;*ID* de &nbsp;;; \

\ *nearfar*
&nbsp;&nbsp;&nbsp;&nbsp;**próximo** | **longe**

\ *nestedStruct*
&nbsp;&nbsp;&nbsp;&nbsp;*structHdr* ⟦ *ID* ⟧;; \
&nbsp;&nbsp;&nbsp;&nbsp;*structBody*\
&nbsp;&nbsp;&nbsp;&nbsp;**termina** ;; \

\ *offsetDir*
&nbsp;&nbsp;&nbsp;&nbsp;*offsetDirType* ;;

\ *offsetDirType*
&nbsp;&nbsp;&nbsp;&nbsp;**até** | **org** *immExpr* | **alinhar** ⟦ *constExpr* ⟧

\ de *desloctype*
&nbsp;&nbsp;&nbsp;&nbsp;**grupo** | **segmento** | **simples**

\ *oldRecordFieldList*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *constExpr* ⟧ | *oldRecordFieldList* , ⟦ *constExpr* ⟧

\ *optionDir*
&nbsp;&nbsp;&nbsp;opção **&nbsp;optionlist** *;;*

\ *optionItem*
&nbsp;&nbsp;&nbsp;&nbsp;**CASEMAP** : *mapType*\
&nbsp;&nbsp;&nbsp;&nbsp;| **DOTNAME** | **NODOTNAME**\
&nbsp;&nbsp;&nbsp;&nbsp;| **Emulator** | **NOEMULATOR**\
&nbsp;&nbsp;&nbsp;&nbsp;| **epílogo** : *macroid*\
&nbsp;&nbsp;&nbsp;&nbsp;| **EXPR16** | **EXPR32**\
&nbsp;&nbsp;&nbsp;&nbsp;**linguagem** | : *LangType*\
&nbsp;&nbsp;&nbsp;&nbsp;| **LJMP**
| **NOLJMP**\
&nbsp;&nbsp;&nbsp;&nbsp;| **M510** | **NOM510**\
&nbsp;&nbsp;&nbsp;&nbsp;| **NOPALAVRA-chave** : < *keywordlist* >\
&nbsp;&nbsp;&nbsp;&nbsp;| **NOSIGNEXTEND**\
&nbsp;&nbsp;&nbsp;&nbsp;| **offset** : *desloctype*\
&nbsp;&nbsp;&nbsp;&nbsp;| **OLDMACROS** | **NOOLDMACROS**\
&nbsp;&nbsp;&nbsp;&nbsp;| **OLDSTRUCTS** | **NOOLDSTRUCTS**\
&nbsp;&nbsp;&nbsp;&nbsp;| **proc** : *oVisibility*\
&nbsp;&nbsp;&nbsp;&nbsp;**prólogo** de | : *macroid*\
&nbsp;&nbsp;&nbsp;&nbsp;| **READONLY** | **noreadonly**\
&nbsp;&nbsp;&nbsp;&nbsp;| com **escopo** | sem **escopo**\
&nbsp;&nbsp;&nbsp;&nbsp;**segmento** de | : *segSize*\
&nbsp;&nbsp;&nbsp;&nbsp;| **SETIF2** : bool

\ de *Opções*
&nbsp;&nbsp;&nbsp;&nbsp;*optionItem* | *optionlist* , ⟦;; ⟧ *optionItem*

\ *optText*
&nbsp;&nbsp;&nbsp;&nbsp;, *textitem*

\ *orOp*
&nbsp;&nbsp;&nbsp;&nbsp;**ou** | **XOR**

\ *oVisibility*
&nbsp;&nbsp;&nbsp;&nbsp;a **exportação** **pública** | **privada** | 

\ *pageDir*
&nbsp;&nbsp;&nbsp;&nbsp;**página** ⟦ *pageExpr* ⟧;;

\ *pageExpr*
&nbsp;&nbsp;&nbsp;&nbsp;\+ | ⟦ *pageLength* ⟧ ⟦, *PageWidth* ⟧

\ *pageLength*
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ *PageWidth*
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ de *parâmetros*
&nbsp;&nbsp;&nbsp;&nbsp;*parmid* ⟦: *qualificotype* ⟧ | *parmid* ⟦ *constExpr* ⟧ ⟦: *qualificotype* ⟧

\ de *parmid*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *ParmList*
&nbsp;&nbsp;&nbsp;&nbsp;*parm* | *ParmList* , ⟦;; ⟧ *Parm*

\ *parmtype*
&nbsp;&nbsp;&nbsp;&nbsp;**req** | = *textliteral* | **vararg**

\ *pOptions*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *Distance* ⟧ ⟦ *LangType* *⟧ ⟦ oVisibility ⟧*

\ *primário*
&nbsp;&nbsp; *&nbsp;&nbsp;expr* *binaryOp* *expr* | *sinalizename* | *expr*

\ *procDir*
&nbsp;&nbsp;&nbsp;&nbsp;*procid* **\**
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *pOptions* ⟧ ⟦ < *macroArgList* > ⟧
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *usesRegs* ⟧ ⟦ *procParmList* ⟧

\ do *processador*
&nbsp;&nbsp;&nbsp;&nbsp;|. 386 |. 386p |. 486 |. 486P \
&nbsp;&nbsp;&nbsp;&nbsp;|. 586 |. 586P |. 686 |. 686P |. 387

\ *processorDir*
&nbsp;&nbsp;&nbsp;*processador* &nbsp;;; \
&nbsp;&nbsp;&nbsp;&nbsp;*coprocessador* | ;;

*procid*\
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ do *incitem*
&nbsp;&nbsp;&nbsp;&nbsp;*instrPrefix* | *dataDir* | *labelDir* | *offsetDir* | *generalDir*

\ *procParmList*
&nbsp;&nbsp;&nbsp;&nbsp;⟦, ⟦;; ⟧ *ParmList* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;⟦, ⟦;; ⟧ *parmid* : vararg ⟧

\ *protoArg*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *ID* ⟧: *qualifiedtype*

\ *protoArgList*
&nbsp;&nbsp;&nbsp;&nbsp;⟦, ⟦;; ⟧ *protolist* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;⟦, ⟦;; ⟧ ⟦ *ID* ⟧: vararg ⟧

\ *protolist*
&nbsp;&nbsp;&nbsp;&nbsp;*protoArg*\
&nbsp;&nbsp;&nbsp;&nbsp;| *protolist* , ⟦;; ⟧ *protoArg*

\ *protoSpec*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *Distance* ⟧ ⟦ *LangType* *⟧ ⟦ protoArgList ⟧ |* *typeId*

\ *protoTypeDir*
&nbsp;&nbsp;&nbsp;*protoSpec* **proto** de *ID* de &nbsp;

\ *pubDef*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *LangType* ⟧ *ID*

\ *publicDir*
&nbsp;&nbsp;&nbsp;&nbsp;**pública** *pubList* ;;

\ *pubList*
&nbsp;&nbsp;&nbsp;&nbsp;*pubDef* | *pubList* , ⟦;; ⟧ *pubDef*

\ *purgeDir*
&nbsp;&nbsp;&nbsp;&nbsp;**limpar** *macroIdList*

\ *qualificadotype*
&nbsp;&nbsp;&nbsp;*tipo* de &nbsp;| ⟦ *Distance* ⟧ **PTR** ⟦ *qualificadotype* ⟧

*qualificador*\
&nbsp;&nbsp;&nbsp;&nbsp;*qualifiedtype* | **proto** *protoSpec*

\ de *cotação*
&nbsp;&nbsp;&nbsp;&nbsp;"|"

\ *qwordRegister*
&nbsp;&nbsp;&nbsp;&nbsp;RAX | RCX | RDX | RBX | RDI | RSI | RBP | R8 | R9 | R10 | R11 | R12 | R13 | R14 | R15

\ *radixDir*
&nbsp;&nbsp;&nbsp;&nbsp; **. RADIX** *constExpr* ;;

\ *radixOverride*
&nbsp;&nbsp;&nbsp;&nbsp;h | o | q | t | y | H | O | Q | T | Iar

\ *recordConst*
&nbsp;&nbsp;&nbsp;&nbsp;*recordTag* { *oldRecordFieldList* } | *recordTag* < *oldRecordFieldList* >

\ *recordDir*
&nbsp;&nbsp;&nbsp;&nbsp;*recordTag* **registro** *bitDefList* ;;

\ *recordFieldList*
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *constExpr* ⟧ | *recordFieldList* , ⟦;; ⟧ ⟦ *constExpr* ⟧

\ *recordInstance*
 {⟦;; ⟧ *recordFieldList* ⟦;; ⟧} \
&nbsp;&nbsp;&nbsp;&nbsp;| < *oldRecordFieldList* >\
&nbsp;&nbsp;&nbsp;&nbsp;| o **dup** de *constExpr* ( *recordInstance* )

\ *recordInstList*
&nbsp;&nbsp;&nbsp;&nbsp;*recordInstance* | *recordInstList* , ⟦;; ⟧ *recordInstance*

\ *recordTag*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

*registrar*\
&nbsp;&nbsp;&nbsp;&nbsp;*specialRegister* | *gpRegister* | *byteRegister* | *qwordRegister* |  *fpuRegister* | *SIMDRegister* | *segmentRegister*

\ *regList*
&nbsp;&nbsp;&nbsp;&nbsp;*registrar* |  *registro* regList

\ *relOp*
&nbsp;&nbsp;&nbsp;&nbsp;EQ | NE | LT | LE | GT | GE

\ *repeatBlock*
&nbsp;&nbsp;&nbsp;&nbsp; **. REPETIR** ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*blockStatements* ;; untilDir ;;

\ *repeatDir*
&nbsp;&nbsp;&nbsp;&nbsp;**repita** | **REPT**

\ *scalarInstList*
&nbsp;&nbsp;&nbsp;&nbsp;*initvalue* | *scalarInstList* , ⟦;; ⟧ *initvalue*

\ *segAlign*
&nbsp;&nbsp;&nbsp;&nbsp;**BYTE** | **palavra** | **DWORD** | **para** | **página**

\ *segAttrib*
&nbsp;&nbsp;&nbsp;&nbsp;**pilha** | **pública** | **memória** | **comum** | **em** *constExpr* | **privada**

\ *segDir*
&nbsp;&nbsp;&nbsp;&nbsp; **.** \ de código
&nbsp;&nbsp;&nbsp;&nbsp;⟦ *segId* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;|  **.** \ de dados
&nbsp;&nbsp;&nbsp;&nbsp;|   **. DADOS?** \
&nbsp;&nbsp;&nbsp;&nbsp;|  **. CONST**\
&nbsp;&nbsp;&nbsp;&nbsp;|  **. FARDATA**⟦ *segId* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;|   **. FARDATA?** ⟦ *segId* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;|  **. STACK** ⟦ *constExpr* ⟧

\ *segId*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *segIdList*
&nbsp;&nbsp;&nbsp;&nbsp;*segId*\
&nbsp;&nbsp;&nbsp;&nbsp;| *segIdList* , *segId*

\ *segmentDef*
&nbsp;&nbsp;&nbsp;&nbsp;*segmentDir* ⟦ *inSegDirList* ⟧ *endsDir* | *simpleSegDir* ⟦ *inSegDirList* ⟧ ⟦ *endsDir* ⟧

\ *segmentDir*
&nbsp;&nbsp;&nbsp;&nbsp;*segId* **Segment** ⟦ *segOptionList* ⟧;;

\ *segmentRegister*
&nbsp;&nbsp;&nbsp;&nbsp;**CS** | **DS** | **ES** | **FS** | **GS** | **SS**

\ *segOption*
&nbsp;&nbsp;&nbsp;&nbsp;*segAlign*\
&nbsp;&nbsp;&nbsp;&nbsp;| *segRO*\
&nbsp;&nbsp;&nbsp;&nbsp;| *segAttrib*\
&nbsp;&nbsp;&nbsp;&nbsp;| *segSize*\
&nbsp;&nbsp;&nbsp;&nbsp;*className* | 

\ *segOptionList*
&nbsp;&nbsp;&nbsp;&nbsp;*segOption* | *segOptionList* *segOption*

\ *segOrderDir*
&nbsp;&nbsp;&nbsp;&nbsp; **.**  | alfa **. SEQ** |  **. DOSSEG** | **DOSSEG**

\ *segRO*
&nbsp;&nbsp;&nbsp;&nbsp;**ReadOnly**

\ *segSize*
&nbsp;&nbsp;&nbsp;&nbsp;**USE16** | **USE32** | **simples**

\ *shiftOp*
&nbsp;&nbsp;&nbsp;&nbsp;**SHR** | **SHL**

*assinar*\
 - | +

\ *simdRegister*
&nbsp;&nbsp;&nbsp;&nbsp;MM0 | MM1 | MM2 | MM3 | MM4 | MM5 | MM6 | MM7 | xmmRegister | YMM0 | YMM1 | YMM2 | YMM3 | YMM4 | YMM5 | YMM6 | YMM7 | YMM8 | YMM9 | YMM10 | YMM11 | YMM12 | YMM13 | YMM14 | YMM15

\ *simpleExpr*
 ( *cExpr* ) | *primário*

\ *simpleSegDir*
&nbsp;&nbsp;&nbsp;&nbsp;*segDir* ;;

\ *sizeArg*
&nbsp;&nbsp;&nbsp;&nbsp;*id* | *tipo* | *E10*

\ *specialChars*
 : | . | ⟦ | ⟧ | ( | ) | < | > | { | } \
&nbsp;&nbsp;&nbsp;&nbsp;| + | - | / | * | & | % | !\
&nbsp;&nbsp;&nbsp;&nbsp;| ' | \ | = | ; | , | "\
&nbsp;&nbsp;&nbsp;&nbsp;| *whiteSpaceCharacter*\
&nbsp;&nbsp;&nbsp;&nbsp;| *endOfLine*

\ *specialRegister*
&nbsp;&nbsp;&nbsp;&nbsp;CR0 | CR2 | CR3 | DR0 | DR1 | DR2 | DR3 | DR6 | DR7 | TR3 | TR4 | TR5 | TR6 | TR7

\ *stackOption*
&nbsp;&nbsp;&nbsp;&nbsp;**NEARSTACK** | **FARSTACK**

\ *startupDir*
&nbsp;&nbsp;&nbsp;&nbsp; **. INICIALIZAÇÃO** ;;

\ *stext*
&nbsp;&nbsp;&nbsp;&nbsp;*stringChar* | *stext* *stringChar*

*string*\
&nbsp;&nbsp;&nbsp;&nbsp;*aspas* ⟦ *stext* ⟧

\ *stringChar*
&nbsp;&nbsp;&nbsp;*cotação* de *aspas* &nbsp;| Qualquer caractere, exceto aspas.

\ *structBody*
&nbsp;&nbsp;&nbsp;&nbsp;*structItem* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;| *structBody* *structItem* ;;

\ *structDir*
&nbsp;&nbsp;&nbsp;&nbsp;*structTag* *structHdr* ⟦ *fieldAlign* ⟧
&nbsp;&nbsp;&nbsp;&nbsp;⟦, ⟧ não **exclusivo** ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*structBody*\
&nbsp;&nbsp;&nbsp;&nbsp;*structTag*\
&nbsp;&nbsp;&nbsp;&nbsp;**termina** ;;

\ *structHdr*
&nbsp;&nbsp;&nbsp;&nbsp;**classe** | **struct** | **Union**

\ *structInstance*
 < ⟦ *fieldInitList* ⟧ > \
&nbsp;&nbsp;&nbsp;&nbsp;| {⟦;; ⟧ ⟦ *fieldInitList* ⟧ ⟦;; ⟧} \
&nbsp;&nbsp;&nbsp;&nbsp;| o **dup** de *constExpr* ( *structInstList* )

\ *structInstList*
&nbsp;&nbsp;&nbsp;&nbsp;*structInstance* | *structInstList* , ⟦;; ⟧ *structInstance*

\ *structItem*
&nbsp;&nbsp;&nbsp;&nbsp;*dataDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *generalDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *offsetDir*\
&nbsp;&nbsp;&nbsp;&nbsp;| *nestedStruct*

\ *structTag*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ de *termo*
&nbsp;&nbsp;&nbsp;&nbsp;*simpleExpr* |! *simpleExpr*

*text*\
&nbsp;&nbsp;&nbsp;&nbsp;*timeliteral* | caractere de *texto* |! *texto* de caractere | *caractere* |! *caractere* de

\ *textDir*
&nbsp;&nbsp;&nbsp;&nbsp;*ID* *textMacroDir* ;;

\ de *textitem*
&nbsp;&nbsp;&nbsp;&nbsp;*timeliteral* | *textmacroid* | % *constExpr*

\ *textLen*
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ de *Textlist*
&nbsp;&nbsp;&nbsp;&nbsp;*textitem* | *timelist* , ⟦;; *textitem* ⟧

\ *Textliteral*
&nbsp;&nbsp;&nbsp;&nbsp;< *text* >;;

\ *textMacroDir*
&nbsp;&nbsp;&nbsp;&nbsp;**CATSTR** ⟦ *textlist* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;| **TEXTEQU** ⟦ *textlist* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;| **SIZESTR** *textitem*\
&nbsp;&nbsp;&nbsp;&nbsp;| **subst** - *Item* , *textstart* ⟦, *textLen* ⟧ \
&nbsp;&nbsp;&nbsp;&nbsp;| **InStr** ⟦ *textstart* , ⟧ *textitem* e *textitem*

\ *Textmacroid*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

*Textstart*\
&nbsp;&nbsp;&nbsp;&nbsp;*constExpr*

\ *titleDir*
&nbsp;&nbsp;&nbsp;&nbsp;*títulotype* *arbitraryText* ;;

*títulotype*\
&nbsp;&nbsp;&nbsp;&nbsp;**título** | **subtítulo** | **SUBTTL**

*tipo*\
&nbsp;&nbsp;&nbsp;&nbsp;*structTag*\
&nbsp;&nbsp;&nbsp;&nbsp;| *unionTag*\
&nbsp;&nbsp;&nbsp;&nbsp;| *recordTag*\
&nbsp;&nbsp;&nbsp;&nbsp;| *distância*\
&nbsp;&nbsp;&nbsp;&nbsp;| *dataType*\
&nbsp;&nbsp;&nbsp;&nbsp;*typeId* | 

\ *typedefDir*
&nbsp;&nbsp;&nbsp;qualificador de **TYPEDEF** de *typeId* &nbsp;

*typeId*\
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *unionTag*
*ID* de &nbsp;de &nbsp;de &nbsp;de &nbsp;

\ *untilDir*
&nbsp;&nbsp;&nbsp;&nbsp; **. ATÉ** *cExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp; **. UNTILCXZ** ⟦ *cxzExpr* ⟧;

\ *usesRegs*
&nbsp;&nbsp;&nbsp;&nbsp;**usa** *regList*

\ *whileBlock*
&nbsp;&nbsp;&nbsp;&nbsp; **. ENQUANTO**\
&nbsp;&nbsp;&nbsp;&nbsp;*cExpr* ;; \
&nbsp;&nbsp;&nbsp;&nbsp;*blockStatements* ;; \
&nbsp;&nbsp;&nbsp;&nbsp; **. ENDW**

\ *whiteSpaceCharacter*
&nbsp;&nbsp;&nbsp;&nbsp;ASCII 8, 9, 11 – 13, 26, 32

\ *xmmRegister*
&nbsp;&nbsp;&nbsp;&nbsp;XMM0 | XMM1 | XMM2 | XMM3 | XMM4 | XMM5 | XMM6 | XMM7 | XMM8 | XMM9 | XMM10 | XMM11 | XMM12 | XMM13 | XMM14 | XMM15\

