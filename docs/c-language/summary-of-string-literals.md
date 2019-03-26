---
title: Resumo de literais da cadeia de caracteres
ms.date: 11/04/2016
ms.assetid: d2693900-f4e2-4820-b7de-085d51827aee
ms.openlocfilehash: a51c66f295a04b969d46d961f43517c0d7de5f6c
ms.sourcegitcommit: 90817d9d78fbaed8ffacde63f3add334842e596f
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/20/2019
ms.locfileid: "58278340"
---
# <a name="summary-of-string-literals"></a>Resumo de literais da cadeia de caracteres

*string-literal*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**"** *s-char-sequence*<sub>opt</sub> **"**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**L"** *s-char-sequence*<sub>opt</sub> **"**

*s-char-sequence*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*s-char*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*s-char-sequence* *s-char*

*s-char*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;qualquer membro do conjunto de caracteres de origem, exceto a marca de aspas duplas ("), a barra invertida (\\) ou escape-sequence de caractere de nova linha

## <a name="see-also"></a>Consulte também

[Gramática lexical](../c-language/lexical-grammar.md)
