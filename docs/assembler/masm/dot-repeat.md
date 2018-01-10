---
title: . REPITA | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .REPEAT
dev_langs: C++
helpviewer_keywords: .REPEAT directive
ms.assetid: cb8ad8c6-587b-42f9-a0ad-b5316a24918c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 46d6502b0fe69a81dd092c97c5d651a32a7fca5a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="repeat"></a>.REPEAT
Gera um código que repete a execução do bloco de *instruções* até `condition` se torne verdadeira. [. UNTILCXZ](../../assembler/masm/dot-untilcxz.md), que se torne verdadeiro quando CX for zero, pode ser substituído por [. ATÉ](../../assembler/masm/dot-until.md). O `condition` é opcional com **. UNTILCXZ**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
   .REPEAT  
statements  
.UNTIL condition  
```  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)