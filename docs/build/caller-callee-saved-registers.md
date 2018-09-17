---
title: Registros salvos de chamador / computador chamado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 0533bd4b-d6bb-4ce1-8201-495e16870cbb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e8e877387dbb5b0be865e11017a3ac71a0c38faa
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707649"
---
# <a name="callercallee-saved-registers"></a>Registros salvos de chamador/receptor

Os registros RAX, RCX, RDX, R8, R9, R10, R11 são considerados voláteis e devem ser considerados destruídos em chamadas de função (a menos que caso contrário, segurança-possível prová-los por análise como otimização de programa inteiro).

Os registros RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 são considerados não-volátil e devem ser salvo e restaurado por uma função que usa-los.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)