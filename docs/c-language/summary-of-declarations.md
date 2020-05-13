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

*declaração*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *atributo-Seq*<sub>opt</sub> *init-Declaration-List*<sub>opt</sub> **;**

*declaration-specifiers*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*storage-class-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *declaration-specifiers*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *declaration-specifiers*<sub>opt</sub>

*atributo-Seq* &nbsp; &nbsp; &nbsp; &nbsp; :/ específico da Microsoft\*\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*attribute* *attribute-seq*<sub>opt</sub>

*atributo* : um dos&nbsp; &nbsp; &nbsp; &nbsp; / \* específicos da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[__asm](../assembler/inline/asm.md) [__clrcall](../cpp/clrcall.md) [__stdcall](../cpp/stdcall.md) [__based](../cpp/based-grammar.md) [__fastcall](../cpp/fastcall.md) [__thiscall](../cpp/thiscall.md) [__cdecl](../cpp/cdecl.md) [__inline](../cpp/inline-functions-cpp.md) [__vectorcall](../cpp/vectorcall.md)

*init-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*init-declarator-List*  **,**  *init-declarator*

*init-Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declarator***=**\* *inicializador*  / de Declarador para inicialização escalar    \*/

*storage-class-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Automático**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Registr**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**auto-estática**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**externo**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**typedef**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__declspec (** *Extended-decl-Modifier-Seq* **)**  / \* específico da Microsoft\*/

*type-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**livre**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**º**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**baixo**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**inteiro**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int8** / __int8\* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int16** / __int16\* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int32** / __int32\* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__int64** / __int64\* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Longas**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**barra**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Clique**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**inteiro**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**não assinados**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador struct-ou-Union-*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*especificador de enumeração*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*typedef-Name*

*qualificador de tipo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**const**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**volátil**

*Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**(** *Declarador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **[** *opt-expressão de constante*<sub>opt</sub> **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Declarador *direto* **(** *tipo de parâmetro-lista* **)**  / \* Declarador de novo estilo\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador direto* **(** *opção identificador-lista*<sub>opt</sub> **)**  / \* Declarador de estilo obsoleto\*/

*ponteiro*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opção</sub> *de qualificador de tipo-lista*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>\*</strong><sub>opt</sub> *ponteiro* de *tipo-qualificador de lista de tipos*

*tipo de parâmetro-lista*&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; :&nbsp; &nbsp; &nbsp; &nbsp; a lista de parâmetros&nbsp; &nbsp; / \*\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*lista de parâmetros* **,...**

*lista de parâmetros*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração de parâmetro*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*parâmetro-List* **,** *declaração de parâmetro*

*type-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*qualificador de tipo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier-list* *type-qualifier*

*enum-specifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**enum** *identificador*de enumeração<sub>opt</sub> **{** *enumerador-List* **}**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**enum** *identifier*

*enumerador-lista*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enumera*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*enumerador-lista* **,** *enumerador*

*enumerador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Enumeração-constante*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**=** *expressão Constant constante-* *constante*

*Enumeração-constante*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*

*especificador de struct-ou-Union*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador struct-or-Union* *identifier*<sub>opt</sub> **{** *struct-declaração-List* **}**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-or-union* *identifier*

*struct-or-union*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**struct**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**unida**

*struct-declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração de struct*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*struct-declaration-list* *struct-declaration*

*declaração de struct*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*specifier-qualifier-list* *struct-declarator-list* **;**

*specifier-qualifier-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-specifier* *specifier-qualifier-list*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*type-qualifier* *specifier-qualifier-list*<sub>opt</sub>

*struct-declarator-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;struct *-* Declarador *struct-declarator-List* **,** *struct-declarator*

*estrutura-declaradora*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Declarador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*tipo de* *Declarador*de especificador<sub>opt</sub> **:** *expressão Constant*

*parameter-declaration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *declaradores*  / \* denominado Declarador\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaração-especificadores* *abstract-Declarador de*<sub>consentimento anônimo opt</sub>  / \*\*/

*identificador-lista*:/\* para Declarador de estilo antigo\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador-lista* **,** *identificador*

*abstract-declarator*:/\* usado com declaradores anônimos\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*refere*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-abstract-declarator*

*direct-abstract-declarator*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**(** *Resumo-Declarador* **)**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Direct-abstract-declarable*<sub>opt</sub> **[** *constante-expressão*<sub>opt</sub> **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;opção *Direct-abstract-Declaration*<sub>opt</sub> **(** <sub>opt</sub> de *tipo de parâmetro-lista* **)**

*inicializador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *inicializador-lista* **}**  / \* para inicialização de agregação\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *inicializador-lista* **,}**

*initializer-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*initializer*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inicializador-lista* **,** *inicializador*

*nome do tipo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*specifier-qualifier-list* *abstract-declarator*<sub>opt</sub>

*typedef-Name*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*

*Extended-decl-Modifier-Seq*:&nbsp; &nbsp; &nbsp; &nbsp; / \* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*extended-decl-modifier-seq* *extended-decl-modifier*

*Extended-decl-Modifier*:&nbsp; &nbsp; &nbsp; &nbsp; / \* específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**processo**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**descoberto**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**DllImport**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**dllexport**

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)<br/>
[Gramática de estrutura da frase](../c-language/phrase-structure-grammar.md)<br/>
[Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)
