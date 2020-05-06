---
title: Resumo de tokens
ms.date: 11/04/2016
ms.assetid: 2978cbf6-e66e-46fc-9938-caa052f2ccf7
ms.openlocfilehash: 4fdc1cf4c4e5a89cc9ecf029e64b6eb5422cd6a3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62345130"
---
# <a name="summary-of-tokens"></a>Resumo de tokens

*token*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*chaves*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*amortiza*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*literal de cadeia de caracteres*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*operador*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*punctuator*

*preprocessing-token*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*nome do cabeçalho*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*PP-Number*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*constante de caractere*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*literal de cadeia de caracteres*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*operator punctuator*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;cada caractere que não seja de espaço em branco que não pode ser um dos acima

*nome do cabeçalho*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**\<**  *caminho-especificação*  **>**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**"**  *especificação do caminho*  **"**

*caminho-especificação*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;Caminho de arquivo válido

*PP-Number*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**.** *digit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pp-number* *digit* <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pp-number* *nondigit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pp-number*  **e**  *sign*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pp-number*  **E**  *sign*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pp-number*  **.**

## <a name="see-also"></a>Confira também

[Gramática lexical](../c-language/lexical-grammar.md)
