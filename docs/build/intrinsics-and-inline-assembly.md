---
title: Intrínsecos e assembly embutido
ms.date: 11/04/2016
ms.assetid: 8affd4bb-279d-46f3-851f-8be0a9c5ed3f
ms.openlocfilehash: 033225259c0a33414fe45eba313bb1f1c94eb379
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515096"
---
# <a name="intrinsics-and-inline-assembly"></a>Intrínsecos e assembly embutido

Uma das restrições para o x64 compilador é fazer com que não há suporte de assembler embutido. Isso significa que funções que não pode ser gravada em C ou C++ será terá que ser escrito como sub-rotinas ou funções intrínsecas suportadas pelo compilador. Determinadas funções são dependentes do desempenho, enquanto outros não são. Funções de diferenciação de desempenho devem ser implementadas como funções intrínsecas.

Os intrínsecos suportados pelo compilador são descritos em [intrínsecos do compilador](../intrinsics/compiler-intrinsics.md).

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)