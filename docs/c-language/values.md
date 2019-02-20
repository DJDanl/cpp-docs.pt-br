---
title: Valores
ms.date: 11/04/2016
ms.assetid: 24003f89-220f-4f93-be7a-b650c26157d7
ms.openlocfilehash: a745b9cc45ed3e58cab4ec7355707d93a0557c04
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56150032"
---
# <a name="values"></a>Valores

**ANSI 3.1.2.5** As representações e os conjuntos de valores de vários tipos de números de ponto flutuante

O tipo **float** contém 32 bits: 1 para o sinal, 8 para o expoente e 23 para a mantissa. O intervalo é +/- 3.4E38 com pelo menos 7 dígitos de precisão.

O tipo **double** contém 64 bits: 1 para o sinal, 11 para o expoente e 52 para a mantissa. O intervalo é +/- 1.7E308 com pelo menos 15 dígitos de precisão.

O tipo **long double** contém 80 bits: 1 para o sinal, 15 para o expoente e 64 para a mantissa. O intervalo é +/- 1.2E4932 com pelo menos 19 dígitos de precisão. Observe que, com o compilador Microsoft C, a representação do tipo **long double** é idêntico à do tipo **double**.

## <a name="see-also"></a>Consulte também

[Matemática de ponto flutuante](../c-language/floating-point-math.md)
