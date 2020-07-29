---
title: Convertendo inteiros em valores de ponto flutuante
ms.date: 11/04/2016
helpviewer_keywords:
- integers, casting to floating-point values
ms.assetid: 81fd5b7d-15eb-4c11-a8c8-e1621ff54fd3
ms.openlocfilehash: b3c65beee0cef4eb74d1bad3c03e5a9c11efae27
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227914"
---
# <a name="casting-integers-to-floating-point-values"></a>Convertendo inteiros em valores de ponto flutuante

**ANSI 3.2.1.3** A direção de truncamento quando um número integral é convertido em um número de ponto flutuante que não pode representar exatamente o valor original

Quando um número integral é convertido em um valor de ponto flutuante que não pode representar o valor com exatidão, o valor é arredondado (para cima ou para baixo) para o valor apropriado mais próximo.

Por exemplo, a conversão de um **`unsigned long`** (com 32 bits de precisão) em um **`float`** (cujo mantissa tem 23 bits de precisão) arredonda o número para o múltiplo mais próximo de 256. Os **`long`** valores de 4.294.966.913 a 4.294.967.167 são todos arredondados para o **`float`** valor 4.294.967.040.

## <a name="see-also"></a>Confira também

[Matemática de ponto flutuante](../c-language/floating-point-math.md)
