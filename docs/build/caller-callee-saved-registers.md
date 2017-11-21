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
ms.openlocfilehash: ebdcf30ea56587b71015a04b5e514dd9ff21aeba
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="callercallee-saved-registers"></a>Registros salvos de chamador/receptor
Destruído registra RAX RCX, RDX, R8, R9, R10, R11 são considerados volátil e deve ser considerado em chamadas de função (a menos que outra forma de segurança-provável pela análise de como a otimização de programa parcial).  
  
 Registra RBX, RBP, RDI, RSI, RSP, versão 12, R13, R14 e R15 é consideradas não volátil e deve ser salvo e restaurado por uma função que usa-los.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)