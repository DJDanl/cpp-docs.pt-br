---
title: C.1 Notação
ms.date: 11/04/2016
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
ms.openlocfilehash: 593450b6dd7dcb30adbf8546ad96ff716c6fbc1c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50473977"
---
# <a name="c1-notation"></a>C.1 Notação

As regras de gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.

O termo de expressão sintática<sub>opt</sub> indica que o termo é opcional dentro da substituição.

A expressão sintática *termo*<sub>optseq</sub> é equivalente a *termo seq*<sub>aceitar</sub> com as seguintes regras adicionais:

*termo seq* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Termo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*termo-seq* *termo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*termo-seq* **,** *termo*