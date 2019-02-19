---
title: Estouro negativo de valores de ponto flutuante
ms.date: 11/04/2016
ms.assetid: 78af8016-643c-47db-b4f1-7f06cb4b243e
ms.openlocfilehash: 93230b50b81ede44a9c55406db1566df2660c1ba
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56149916"
---
# <a name="underflow-of-floating-point-values"></a>Estouro negativo de valores de ponto flutuante

**ANSI 4.5.1** Se as funções matemáticas definem a expressão de inteiro `errno` como o valor da macro `ERANGE` em erros de alcance de estouro negativo

Um estouro negativo de ponto flutuante não define a expressão `errno` como `ERANGE`. Quando um valor se aproxima de zero e acaba sofrendo um estouro negativo, o valor é definido como zero.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
