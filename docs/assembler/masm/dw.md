---
title: DW | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- DW
dev_langs:
- C++
helpviewer_keywords:
- DW directive
ms.assetid: 451d0e24-b65b-4cbb-b81d-ea27680feaf3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77e0127ccec8aaac43955087ee4a4b0e8fdbcad5
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="dw"></a>DW
Aloca e, opcionalmente, inicializa uma palavra (2 bytes) de armazenamento para cada `initializer`. Também pode ser usado como um especificador de tipo em qualquer lugar, um tipo é legal. `DW` é um sinônimo do [WORD](../../assembler/masm/word.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[[name]] DW initializer [[, initializer]]...  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)   
 [SWORD](../../assembler/masm/sword.md)