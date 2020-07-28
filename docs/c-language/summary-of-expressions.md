---
title: Resumo de expressões
ms.date: 06/14/2018
ms.assetid: ed448953-687a-4b57-a1cb-12967bd770ea
ms.openlocfilehash: 1660690c6d36aa1dbdc025d6afe92e19ff941463
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220828"
---
# <a name="summary-of-expressions"></a>Resumo de expressões

*expressão primária*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*amortiza*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*literal de cadeia de caracteres*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**(**  *expressão*  **)**

*expressão*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão***,** expressão*de atribuição*    

*expressão de constante*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão condicional*

*expressão condicional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*logical-OR-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão or lógica*  **?**  *expression*  **:**  *expressão condicional*

*assignment-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão condicional*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*unary-expression* *assignment-operator* *assignment-expression*

*expressão de sufixo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*primary-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sufixo-expressão*  **[**  *expressão*  **]**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sufixo-expressão***(***opção de expressão de argumento-lista*<sub>opt</sub> **)**    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **.**  *ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão* **->** de sufixo *identificador* do    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **++**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **--**

*argument-expression-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*argumento-expressão-lista*  **,**  *expressão de atribuição*

*expressão unário*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**++**  *expressão unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**--**  *expressão unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*operador unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cast-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**`sizeof`**  *expressão unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**sizeof (**  *tipo-nome*  **)**

*unary-operator*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**&****&#42;** **+** **-** **~** **!**

*expressão CAST*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão-unária*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão CAST* **(***nome-do-tipo***)**      

*multiplicativa-expressão*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cast-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression*  **&#42;**  *cast-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicativa-expressão* **/** *expressão CAST*    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicativa-expressão* **%** *expressão CAST*    

*additive-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão aditiva* **+** *multiplicativa-expressão*    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão aditiva* **-** *multiplicativa-expressão*    

*expressão Shift*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão aditiva*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão Shift*   * *expressão Shift-Expression * aditivo \<\<**  *additive-expression*<br/> &nbsp; &nbsp; &nbsp; &nbsp; * **>>** *additive-expression*  

*expressão relacional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression* expressão relacional* \<=**  *shift-expression*<br/> &nbsp; &nbsp; - &nbsp; &nbsp; ** * \<**  *shift-expression*<br/> &nbsp; &nbsp; relacional-Expression * Shift-Expression relacional-expressão * * relacional-expressão * Shift-Expression &nbsp; &nbsp; * **>** *shift-expression* <br/> &nbsp; &nbsp; &nbsp; &nbsp;   * **>=** *shift-expression*    

*equality-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão* **==** de igualdade *expressão relacional*    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*equality-expression*  **!=**  *relational-expression*

*AND-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de igualdade*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Expressão and* **&** *expressão de igualdade*    

*exclusive-OR-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Expressão AND*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão* **^** or exclusiva *Expressão and*    

*expressão inclusiva ou*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão OR exclusiva*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;uma *expressão inclusiva ou* **&#124;** *exclusiva-ou-expressão*    

*expressão and lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inclusivo-ou-expressão*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão* **&&** and lógica *inclusivo-ou-expressão*    

*expressão or lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão AND lógica*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;expressão or *lógica* **&#124;&#124;** *lógica e expressão*    

## <a name="see-also"></a>Confira também

- [Gramática da estrutura da frase](../c-language/phrase-structure-grammar.md)
