---
title: PUSHCONTEXT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- PUSHCONTEXT
dev_langs:
- C++
helpviewer_keywords:
- PUSHCONTEXT directive
ms.assetid: 18e528ee-df6c-4ce6-8823-b35b40f757fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3c16d0de0848a9ceb61330498b12a9a4322e6604
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32056373"
---
# <a name="pushcontext"></a>PUSHCONTEXT
Salva todo ou parte do atual `context`: presume que o registro de segmento, valor fracionário, sinalizadores de listagem e cref ou valores de processador/coprocessador. O `context` pode ser **SUPÕE**, `RADIX`, **listando**, **CPU**, ou **todos os**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
PUSHCONTEXT context  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)