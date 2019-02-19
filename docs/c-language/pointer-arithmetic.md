---
title: Ponteiro aritmético
ms.date: 11/04/2016
helpviewer_keywords:
- pointer arithmetic
- arithmetic pointer
ms.assetid: eb924a29-59d3-48a5-9d62-9424790730eb
ms.openlocfilehash: c1b3e31561bedece6a6180fbeb13473153a46ab6
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56152671"
---
# <a name="pointer-arithmetic"></a>Ponteiro aritmético

As operações de adição envolvendo um ponteiro e um inteiro fornecem resultados significativos apenas se o operando do ponteiro endereçar um membro de matriz e o valor inteiro produzir um deslocamento dentro dos limites da mesma matriz. Quando o valor inteiro é convertido em um deslocamento de endereço, o compilador pressupõe que somente as posições de memória do mesmo tamanho se encontram entre o endereço original e o endereço mais o deslocamento.

Esse pressuposto é válido para membros de matriz. Por definição, uma matriz é uma série de valores do mesmo tipo; seus elementos residem em locais de memória contíguos. Porém, o armazenamento para alguns tipos exceto elementos da matriz não têm garantia de preenchimento pelo mesmo tipo de identificadores. Ou seja, os espaços em branco podem aparecer entre as posições de memória, até mesmo posições do mesmo tipo. Consequentemente, os resultados da adição a ou da subtração de endereços de quaisquer valores que não os elementos da matriz serão indefinidos.

Da mesma forma, quando dois valores de ponteiro são subtraídos, a conversão pressupõe que somente valores do mesmo tipo, sem espaços em branco, se encontram entre os endereços dados pelos operandos.

## <a name="see-also"></a>Consulte também

[Operadores aditivos C](../c-language/c-additive-operators.md)
