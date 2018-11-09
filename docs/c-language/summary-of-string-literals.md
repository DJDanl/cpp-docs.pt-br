---
title: Resumo de literais da cadeia de caracteres
ms.date: 11/04/2016
ms.assetid: d2693900-f4e2-4820-b7de-085d51827aee
ms.openlocfilehash: 72f5aa6405ae97bfb6141db737affa0c3aca2a65
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50648117"
---
# <a name="summary-of-string-literals"></a>Resumo de literais da cadeia de caracteres

*string-literal*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**'** *s-char-sequence*<sub>opt</sub> **'**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**L'** *s-char-sequence*sub>opt</sub> **'**

*s-char-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*s-char*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*s-char-sequence* *s-char*

*s-char*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas duplas ("), a barra invertida (\\) ou escape-sequence de caractere de nova linha

## <a name="see-also"></a>Consulte também

[Gramática lexical](../c-language/lexical-grammar.md)