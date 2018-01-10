---
title: Registros salvos de chamador receptor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 0533bd4b-d6bb-4ce1-8201-495e16870cbb
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 61e8d57c177ded8102f257cf84adedc0de0e312a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="callercallee-saved-registers"></a>Registros salvos de chamador/receptor
Destruído registra RAX RCX, RDX, R8, R9, R10, R11 são considerados volátil e deve ser considerado em chamadas de função (a menos que outra forma de segurança-provável pela análise de como a otimização de programa parcial).  
  
 Registra RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 é consideradas não volátil e deve ser salvo e restaurado por uma função que usa-los.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)