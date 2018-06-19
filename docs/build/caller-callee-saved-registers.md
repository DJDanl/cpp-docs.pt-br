---
title: Registros salvos de chamador receptor | Microsoft Docs
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
ms.openlocfilehash: 8f65e88c8609d6a2097e9e54c3f52cbd27dce36d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32366790"
---
# <a name="callercallee-saved-registers"></a>Registros salvos de chamador/receptor
Destruído registra RAX RCX, RDX, R8, R9, R10, R11 são considerados volátil e deve ser considerado em chamadas de função (a menos que outra forma de segurança-provável pela análise de como a otimização de programa parcial).  
  
 Registra RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 é consideradas não volátil e deve ser salvo e restaurado por uma função que usa-los.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)