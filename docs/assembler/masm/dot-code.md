---
title: .CODE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- .CODE
dev_langs:
- C++
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: de0a9b8930c04929b05b02931a1f796d28a78099
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="code"></a>.CODE
Quando usado com [. MODELO](../../assembler/masm/dot-model.md), indica o início de um segmento de código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
.CODE [[name]]  
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`name`|Parâmetro opcional que especifica o nome do segmento de código. O nome padrão é Text para pequeno, pequeno, compact e simples [modelos](../../assembler/masm/dot-model.md). O nome padrão é *modulename*Text para outros modelos.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)   
 [.DATA](../../assembler/masm/dot-data.md)