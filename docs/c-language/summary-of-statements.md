---
title: Resumo de instruções C
description: Um resumo da gramática da instrução na implementação do Microsoft C.
ms.date: 08/24/2020
ms.assetid: ce45d2fe-ec0e-459f-afb1-80ab6a7f0239
ms.openlocfilehash: 448aa7ccb8c78e20ef09f47f4a3c77f447c76f60
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898396"
---
# <a name="summary-of-c-statements"></a>Resumo de instruções C

*`statement`*:<br/>
&emsp;*`labeled-statement`*<br/>
&emsp;*`compound-statement`*<br/>
&emsp;*`expression-statement`*<br/>
&emsp;*`selection-statement`*<br/>
&emsp;*`iteration-statement`*<br/>
&emsp;*`jump-statement`*<br/>
&emsp;*`try-except-statement`* /\* Específico da Microsoft \*/<br/>
&emsp;*`try-finally-statement`* /\* Específico da Microsoft \*/

*`jump-statement`*:<br/>
&emsp;**`goto`** *`identifier`* **`;`**<br/>
&emsp;**`continue ;`**<br/>
&emsp;**`break ;`**<br/>
&emsp;**`return`***`expression`* <sub>aceitar</sub>**`;`**<br/>
&emsp;**`__leave ;`** /\*Específico da Microsoft<sup>1</sup>\*/

*`compound-statement`*:<br/>
&emsp;**`{`** optar por *`declaration-list`* <sub>aceitar</sub> *`statement-list`* <sub>opt</sub>**`}`**

*`declaration-list`*:<br/>
&emsp;*`declaration`*<br/>
&emsp;*`declaration-list`* *`declaration`*

*`statement-list`*:<br/>
&emsp;*`statement`*<br/>
&emsp;*`statement-list`* *`statement`*

*`expression-statement`*:<br/>
&emsp;*`expression`*<sub>aceitar</sub>**`;`**

*`iteration-statement`*:<br/>
&emsp;**`while (`** *`expression`* **`)`** *`statement`*<br/>
&emsp;**`do`** *`statement`* **`while (`** *`expression`* **`) ;`**<br/>
&emsp;**`for (`***`expression`* <sub>opt</sub> **`;`** aceitar *`expression`* <sub>aceitar</sub> **`;`** *`expression`* <sub>opt</sub> aceitar **`)`***`statement`*

*`selection-statement`*:<br/>
&emsp;**`if (`** *`expression`* **`)`** *`statement`*<br/>
&emsp;**`if (`** *`expression`* **`)`** *`statement`* **`else`** *`statement`*<br/>
&emsp;**`switch (`** *`expression`* **`)`** *`statement`*

*`labeled-statement`*:<br/>
&emsp;*`identifier`* **`:`** *`statement`*<br/>
&emsp;**`case`** *`constant-expression`* **`:`** *`statement`*<br/>
&emsp;**`default :`** *`statement`*

*`try-except-statement`*:/ \* Específico da Microsoft \*/<br/>
&emsp;**`__try`** *`compound-statement`* **`__except (`** *`expression`* **`)`** *`compound-statement`*

*`try-finally-statement`*:/ \* Específico da Microsoft \*/<br/>
&emsp;**`__try`** *`compound-statement`* **`__finally`** *`compound-statement`*

1 a **`__leave`** palavra-chave só é válida dentro do **`__try`** bloco de um *`try-except-statement`* ou de um *`try-finally-statement`* .

## <a name="see-also"></a>Confira também

[Gramática de estrutura de frase](../c-language/phrase-structure-grammar.md)
