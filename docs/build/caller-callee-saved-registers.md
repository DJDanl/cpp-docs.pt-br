---
title: Registros salvos de chamador / computador chamado
ms.date: 11/04/2016
ms.assetid: 0533bd4b-d6bb-4ce1-8201-495e16870cbb
ms.openlocfilehash: f34fbfff8e6c61b5d568c073f6b7da2a12e34535
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50654695"
---
# <a name="callercallee-saved-registers"></a>Registros salvos de chamador/receptor

Os registros RAX, RCX, RDX, R8, R9, R10, R11 são considerados voláteis e devem ser considerados destruídos em chamadas de função (a menos que caso contrário, segurança-possível prová-los por análise como otimização de programa inteiro).

Os registros RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 são considerados não-volátil e devem ser salvo e restaurado por uma função que usa-los.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)