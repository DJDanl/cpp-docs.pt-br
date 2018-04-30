---
title: .CODE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .CODE
dev_langs:
- C++
helpviewer_keywords:
- .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 59e376fc9c10ab8891b02e4da334341ae0534b73
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
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