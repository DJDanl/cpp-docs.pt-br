---
title: Resumo de instruções
ms.date: 11/04/2016
ms.assetid: ce45d2fe-ec0e-459f-afb1-80ab6a7f0239
ms.openlocfilehash: 122c79b53a8af8a384097dec51a14746a090b1cf
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220789"
---
# <a name="summary-of-statements"></a>Resumo de instruções

*instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução rotulada*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução composta*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão-instrução*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de seleção*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução Iteration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de salto*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;instrução try- *Except-*  / \* Específico da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*try-finally-statement*  / instrução \* try – finally Específico da Microsoft\*/

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`goto`**  *identificador*  **;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**continue ;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**break ;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`return`***expressão*<sub>opt</sub> **;**

*instrução composta*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *declaração-lista*de instruções<sub>opt</sub> *-lista*<sub>opt</sub> **}**

*declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*mesma*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-list* *declaration*

*statement-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*privacidade*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement-list* *statement*

*expressão-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expression*<sub>opt</sub> **;**

*instrução Iteration*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **while (***expressão***)**      <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`do`**  *instrução*  **while (**  *expressão*  **);**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **for (***expressão*<sub>opt</sub> **;** *expressão aceitar*<sub>opt</sub> **;** *expression*<sub>opt</sub> expressão opt **)**  

*selection-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **If (***expression***)**      <br/>
&nbsp;&nbsp;&nbsp;&nbsp;instrução de*instrução* **If (***expression***)** **`else`** *statement*          <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **switch (***expression***)**      

*rotulado-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador*  **:**  *instrução*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`case`**  *expressão Constant*  **:**  *instrução*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**default :**  *statement*

*instrução try-Except-Statement*:/ \* específica da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__try**  *composição de instrução* **__except (**  *expressão*  **)**  *composta-instrução*

*instrução try-finally-Statement*:/ \* específica da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__try**composição de*instrução* **`__finally`** *composta* -instrução    

## <a name="see-also"></a>Confira também

[Gramática da estrutura da frase](../c-language/phrase-structure-grammar.md)
