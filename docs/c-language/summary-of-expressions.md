---
title: Resumo de expressões
ms.date: 06/14/2018
ms.assetid: ed448953-687a-4b57-a1cb-12967bd770ea
ms.openlocfilehash: 320baa51d54f00ac4fdb6633922a8bb36cf92a94
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157783"
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
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de sufixo*  **.**  *identificador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identificador de expressão***->***identifier* de sufixo    <br/>
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
&nbsp;&nbsp;&nbsp;&nbsp;expressão **sizeof***unário*  <br/>
&nbsp;&nbsp;&nbsp;&nbsp;**sizeof (**  *tipo-nome*  **)**

*unary-operator*: one of<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**&****&#42;** **+**&#42;**-** **!** ! **~**

*expressão CAST*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão unário*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão CAST* **(***nome-do-tipo***)**      

*multiplicativa-expressão*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*cast-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression*  **&#42;**  *cast-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression***/***expressão CAST* de multiplicativa-Expression    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression***%***expressão CAST* de multiplicativa-Expression    

*additive-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*multiplicative-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*additive-expression***+** expressão*multiplicativa de* expressão aditiva    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*additive-expression***-** expressão*multiplicativa de* expressão aditiva    

*expressão Shift*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão aditiva*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression***\<***expressão aditiva* de expressão Shift-Expression    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression***>>***expressão aditiva* de expressão Shift-Expression    

*expressão relacional*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*shift-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression***\<***expressão de alternância* de expressão relacional    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression***>***expressão de alternância* de expressão relacional    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression***\<***expressão de alternância* de expressão relacional    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression***>=***expressão de alternância* de expressão relacional    

*equality-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*relational-expression*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*equality-expression***==***expressão relacional de* expressão de igualdade    <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*equality-expression*  **!=**  *relational-expression*

*AND-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de igualdade*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*AND-expression***&***Expressão de igualdade* de expressão and-Expression    

*exclusive-OR-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Expressão AND*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*exclusive-OR-expression***^***expressão* or exclusiva.    

*expressão inclusiva ou*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão OR exclusiva*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;uma *expressão inclusiva ou* **&#124;** *exclusiva-ou-expressão*    

*expressão and lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*inclusivo-ou-expressão*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de lógica e de expressão*  **&&**  *inclusiva*

*expressão or lógica*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão AND lógica*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;expressão or *lógica* **&#124;&#124;** *lógica e expressão*    

## <a name="see-also"></a>Confira também

- [Gramática de estrutura da frase](../c-language/phrase-structure-grammar.md)
