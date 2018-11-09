---
title: Convertendo inteiros em valores de ponto flutuante
ms.date: 11/04/2016
helpviewer_keywords:
- integers, casting to floating-point values
ms.assetid: 81fd5b7d-15eb-4c11-a8c8-e1621ff54fd3
ms.openlocfilehash: d19544e3b4f0bf3978d296c996c204fc9d60fa0c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50667344"
---
# <a name="casting-integers-to-floating-point-values"></a>Convertendo inteiros em valores de ponto flutuante

**ANSI 3.2.1.3** A direção de truncamento quando um número integral é convertido em um número de ponto flutuante que não pode representar exatamente o valor original

Quando um número integral é convertido em um valor de ponto flutuante que não pode representar o valor com exatidão, o valor é arredondado (para cima ou para baixo) para o valor apropriado mais próximo.

Por exemplo, a conversão de **unsigned long** (com 32 bits de precisão) em um **float** (cuja mantissa tem 23 bits de precisão) arredondará o número para o múltiplo mais próximo de 256. Todos os valores de 4.294.966.913 a 4.294.967.167 de **long** serão arredondados para o valor 4.294.967.040 de **float**.

## <a name="see-also"></a>Consulte também

[Matemática de ponto flutuante](../c-language/floating-point-math.md)