---
title: Resumo de declarações
ms.date: 11/04/2016
ms.assetid: 53a5e9e5-1a33-40b5-9dea-7f669b479329
ms.openlocfilehash: 894ed5e39ac8019048b6730d5e3b34de22f3a0c7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220841"
---
# <a name="summary-of-declarations"></a>Resumo de declarações

*`declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`* optar por *`attribute-seq`* <sub>aceitar</sub> *`init-declarator-list`* <sub>opt</sub>**`;`**

*`declaration-specifiers`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`storage-class-specifier`**`declaration-specifiers`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-specifier`**`declaration-specifiers`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier`**`declaration-specifiers`* <sub>aceitar</sub>

*`attribute-seq`*: &nbsp; &nbsp; &nbsp; &nbsp; / \* Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`attribute`**`attribute-seq`* <sub>aceitar</sub>

*`attribute`*: um dos &nbsp; &nbsp; &nbsp; &nbsp; / \* específicos da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;[`__asm`](../assembler/inline/asm.md) [`__clrcall`](../cpp/clrcall.md) [`__stdcall`](../cpp/stdcall.md) [`__based`](../cpp/based-grammar.md) [`__fastcall`](../cpp/fastcall.md) [`__thiscall`](../cpp/thiscall.md) [`__cdecl`](../cpp/cdecl.md) [`__inline`](../cpp/inline-functions-cpp.md) [`__vectorcall`](../cpp/vectorcall.md)

*`init-declarator-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`init-declarator-list`*  **`,`**  *`init-declarator`*

*`init-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`*  **`=`**  *`initializer`* /\*Para inicialização escalar\*/

*`storage-class-specifier`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`auto`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`register`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`static`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`extern`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`typedef`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__declspec (`***`extended-decl-modifier-seq`* **`)`** /\* Específico da Microsoft\*/

*`type-specifier`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`void`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`char`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`short`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`int`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int8`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int16`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int32`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`__int64`** /\*Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`long`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`float`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`double`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`signed`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`unsigned`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-or-union-specifier`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`enum-specifier`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`typedef-name`*

*`type-qualifier`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`const`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`volatile`**

*`declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`pointer`*<sub>aceitar</sub>*`direct-declarator`*

*`direct-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`identifier`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`(`** *`declarator`* **`)`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-declarator`***`[`** *`constant-expression`* <sub>aceitar</sub>**`]`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-declarator`***`(`** *`parameter-type-list`* **`)`** /\* Declarador de novo estilo\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-declarator`***`(`** *`identifier-list`* <sub>opt</sub> **`)`**  / \* Declarador de estilo obsoleto\*/

*`pointer`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>`*`</strong>*`type-qualifier-list`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>`*`</strong>*`type-qualifier-list`* <sub>aceitar</sub>*`pointer`*

*`parameter-type-list`*: &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; / \* A lista de parâmetros\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`* **`, ...`**

*`parameter-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-declaration`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`parameter-list`* **`,`** *`parameter-declaration`*

*`type-qualifier-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier-list`* *`type-qualifier`*

*`enum-specifier`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`enum`***`identifier`* <sub>opt</sub> **`{`** aceitar *`enumerator-list`***`}`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`enum`** *`identifier`*

*`enumerator-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`enumerator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`enumerator-list`* **`,`** *`enumerator`*

*`enumerator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`enumeration-constant`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`enumeration-constant`* **`=`** *`constant-expression`*

*`enumeration-constant`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`identifier`*

*`struct-or-union-specifier`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-or-union`**`identifier`* <sub>opt</sub> **`{`** aceitar *`struct-declaration-list`***`}`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-or-union`* *`identifier`*

*`struct-or-union`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`struct`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`union`**

*`struct-declaration-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-declaration`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-declaration-list`* *`struct-declaration`*

*`struct-declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`specifier-qualifier-list`* *`struct-declarator-list`* **`;`**

*`specifier-qualifier-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-specifier`**`specifier-qualifier-list`* <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-qualifier`**`specifier-qualifier-list`* <sub>aceitar</sub>

*`struct-declarator-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`struct-declarator`* *`struct-declarator-list`* **`,`** *`struct-declarator`*

*`struct-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declarator`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`type-specifier`**`declarator`* <sub>opt</sub> aceitar **`:`***`constant-expression`*

*`parameter-declaration`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`**`declarator`* /\* Declarador nomeado\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`declaration-specifiers`**`abstract-declarator`* <sub>opt</sub>  / aceitar \* Declarador anônimo\*/

*`identifier-list`*:/ \* Para Declarador de estilo antigo\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`identifier`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`identifier-list`* **`,`** *`identifier`*

*`abstract-declarator`*:/ \* Usado com declaradores anônimos\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`pointer`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`pointer`*<sub>aceitar</sub>*`direct-abstract-declarator`*

*`direct-abstract-declarator`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`(`** *`abstract-declarator`* **`)`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-abstract-declarator`*<sub>aceitar</sub> **`[`** *`constant-expression`* <sub>aceitar</sub>**`]`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`direct-abstract-declarator`*<sub>aceitar</sub> **`(`** *`parameter-type-list`* <sub>aceitar</sub>**`)`**

*`initializer`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`assignment-expression`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`{`***`initializer-list`* **`}`** /\* Para inicialização de agregação\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`{`** *`initializer-list`* **`, }`**

*`initializer-list`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`initializer`*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`initializer-list`* **`,`** *`initializer`*

*`type-name`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`specifier-qualifier-list`**`abstract-declarator`* <sub>aceitar</sub>

*`typedef-name`*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`identifier`*

*`extended-decl-modifier-seq`*: &nbsp; &nbsp; &nbsp; &nbsp; / \* Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`extended-decl-modifier`*<sub>opt</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;*`extended-decl-modifier-seq`* *`extended-decl-modifier`*

*`extended-decl-modifier`*: &nbsp; &nbsp; &nbsp; &nbsp; / \* Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`thread`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`naked`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllimport`**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`dllexport`**

## <a name="see-also"></a>Confira também

[Convenções de chamada](../cpp/calling-conventions.md)<br/>
[Gramática da estrutura da frase](../c-language/phrase-structure-grammar.md)<br/>
[Convenções de chamada obsoletas](../cpp/obsolete-calling-conventions.md)
