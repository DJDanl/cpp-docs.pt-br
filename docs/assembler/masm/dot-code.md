---
title: ". CÓDIGO | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .CODE
dev_langs: C++
helpviewer_keywords: .CODE directive
ms.assetid: 2b8c882c-c0d2-4fa3-8335-e6b12717a4f4
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 150b5a0c26be3c3c4d0412157179ebfcbec128e7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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