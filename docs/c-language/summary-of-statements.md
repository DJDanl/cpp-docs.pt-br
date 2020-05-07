---
title: Resumo de instruções
ms.date: 11/04/2016
ms.assetid: ce45d2fe-ec0e-459f-afb1-80ab6a7f0239
ms.openlocfilehash: 1a230ca7d998316d2ec96e76b54ac60575acd2ee
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856989"
---
# <a name="summary-of-statements"></a>Resumo de instruções

*instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução rotulada*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução composta*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão-instrução*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de seleção*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução Iteration*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de salto*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução try-Except-*  / \* da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução try-finally-*  / \* da Microsoft\*/

*instrução de salto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**goto***identificador*GoTo **;**    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**continue ;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**break ;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**return** *expression*<sub>opt</sub> **;**

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
&nbsp;&nbsp;&nbsp;&nbsp;**do**  *statement*  **while (**  *expression*  **) ;**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **for (***expressão*<sub>opt</sub> **;** *expressão aceitar*<sub>opt</sub> **;** *expression*<sub>opt</sub> expressão opt **)**  

*selection-statement*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **If (***expression***)**      <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **If (***expression***)***Statement***else**          <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução* **switch (***expression***)**      

*rotulado-instrução*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador*  **:**  *instrução*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**case***expressão constante-* Case **:***instrução*      <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**default :**  *statement*

*instrução try-Except-Statement*:\* /específica da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__try**  *composição de instrução* **__except (**  *expressão*  **)**  *composta-instrução*

*instrução try-finally-Statement*:\* /específica da Microsoft\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**__try**  *compound-statement* **__finally**  *compound-statement*

## <a name="see-also"></a>Confira também

[Gramática de estrutura da frase](../c-language/phrase-structure-grammar.md)
