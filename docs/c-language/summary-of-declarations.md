---
title: Resumo de declarações
ms.date: 11/04/2016
ms.assetid: 53a5e9e5-1a33-40b5-9dea-7f669b479329
ms.openlocfilehash: e553f4bdfffcd4bba6a39b2d37af6ba25a3d65d9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170430"
---
# <a name="summary-of-declarations"></a>Resumo de declarações

*declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *atributo-Seq*<sub>opt</sub> *init-Declaration-List*<sub>opt</sub> **;**

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;declaração de *classe de armazenamento* - *especificadores*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração*<sub>opt</sub> *de tipo-* especificador<br/>
&nbsp;&nbsp;&nbsp;Declaração *de qualificador de tipo* de &nbsp;-<sub>aceitar</sub> *especificadores*

*Attribute-Seq* :&nbsp;&nbsp;&nbsp;&nbsp;/\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*attribute* *atributo de atributo-Seq*<sub>opt</sub>

*atributo* : um dos&nbsp;&nbsp;&nbsp;&nbsp;/\* específico da Microsoft \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[__asm](../assembler/inline/asm.md) [__clrcall](../cpp/clrcall.md) [__stdcall](../cpp/stdcall.md) [__based](../cpp/based-grammar.md) [__fastcall](../cpp/fastcall.md) [__thiscall](../cpp/thiscall.md) [__cdecl __inline](../cpp/cdecl.md) [__inline](../cpp/inline-functions-cpp.md) [__vectorcall](../cpp/vectorcall.md)

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-List* **,** *init-declarator*

*init-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarador* **=** *inicializador* /\* para inicialização escalar \*/

*storage-class-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**auto**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**register**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**static**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**extern**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**typedef**<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__declspec (** *Extended-decl-Modifier-Seq* **)**  /\* \*específicos da Microsoft /

*type-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**void**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**char**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**short**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**int**<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__int8** /\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__int16** /\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__int32** /\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__int64** /\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**long**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**float**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**double**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**signed**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**unsigned**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-or-union-specifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enum-specifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*typedef-name*

*type-qualifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**const**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**volatile**

*declarator*:<br/>
&nbsp;&nbsp;&nbsp;*Declarador de ponteiro de &nbsp;para* *pointer*<sub>consentimento</sub> direto

*direct-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **(** *Declarador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **[** *opt-expressão de constante*<sub>opt</sub> **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **(** *tipo de parâmetro-lista* **)**  /\* Declarador de novo estilo \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **(opcional do** *identificador-lista*<sub>opt</sub> **)**  /\* Declarador de estilo obsoleto \*/

*pointer*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;a<sub>opção</sub> <strong>\*</strong> *tipo-qualificador-lista*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;de <strong>\*</strong> *tipo-qualificador-listar*<sub>opt</sub> *ponteiros* de consentimento

*parameter-type-list*:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/\* A lista de parâmetros \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-list*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros* **,...**

*parameter-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parameter-declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parâmetro-List* **,** *declaração de parâmetro*

*type-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*tipo-qualificador-* *tipo de lista-qualificador*

*enum-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**enum** *identificador*de enumeração<sub>opcional</sub> **{** *enumerador-List* **}**<br/>
&nbsp;&nbsp;&nbsp;*identificador* de **Enumeração** &nbsp;

*enumerator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enumerator*<br/>
&nbsp;&nbsp;&nbsp;*enumerador &nbsp;-List* **,** *enumerador*

*enumerator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enumeration-constant*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Enumeração-constante* **=** *expressão constante*

*enumeration-constant*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*

*struct-or-union-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;o identificador *struct-ou-Union tem a* *identifier*<sub>opção</sub> **{** *struct-Declaration-List* **}**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador* *struct-ou-Union*

*struct-or-union*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**struct**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**union**

*struct-declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-declaration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-declaração-lista* *struct-declaração*

*struct-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador-qualificador-List* *struct-declarator-List* **;**

*specifier-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;especificador de *especificador de tipo* *-qualificador,* <sub>aceitar</sub> lista<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*tipo-* qualificador *especificador-qualificador-lista*de<sub>consentimento</sub>

*struct-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;struct *-* declarator *estrutura-Declaration-List* **,** *struct-declarator*

*struct-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador* *de tipo-especificado* <sub>opcional</sub> **:** *expressão de constante*

*parameter-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *declaradores* /\* declarador nomeado \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *abstract-declarator*<sub>opt</sub> /\* Declarador anônimo \*/

*identifier-list*: /\* Para declarador de estilo antigo \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*<br/>
&nbsp;&nbsp;&nbsp;*identificador de &nbsp;-lista* **,** *identificador*

*abstract-declarator*: /\* Usado com declaradores anônimos \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<br/>
&nbsp;&nbsp;&nbsp;o *Declarador* de *ponteiro*de &nbsp;para<sub>consentimento</sub> direto

*direct-abstract-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **(** *Resumo-Declarador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Direct-abstract-declarable*<sub>opt</sub> **[** *expressão constante*<sub>opt</sub> **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*a opção Direct-abstract-Declaration*<sub>opt</sub> **(** opt de *tipo de parâmetro-lista*<sub>opt</sub> **)**

*initializer*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assignment-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **{** *inicializador-lista* **}**  /\* para inicialização agregada \*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **{** *inicializador-lista* **,}**

*initializer-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*initializer*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inicializador-lista* **,** *inicializador*

*type-name*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador-qualificador-List* *Resumo-Declarador*<sub>opt</sub> de lista

*typedef-name*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier*

*Extended-decl-Modifier-Seq*:&nbsp;&nbsp;&nbsp;&nbsp;/\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Extended-decl-Modifier-Seq* *Extended-decl-Modifier*

*Extended-decl-Modifier*:&nbsp;&nbsp;&nbsp;&nbsp;/\* \*específicos da Microsoft /<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**thread**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**naked**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllimport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllexport**

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)<br/>
[Gramática de estrutura de frase](../c-language/phrase-structure-grammar.md)<br/>
[Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)
