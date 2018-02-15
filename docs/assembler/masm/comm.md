---
title: COMM | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- COMM
dev_langs:
- C++
helpviewer_keywords:
- COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6258a584d39f598b32c43affc0ef2569b77b2047
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="comm"></a>COMM
Cria uma variável pública com os atributos especificados no `definition`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
COMM definition [[, definition]] ...  
```  
  
## <a name="remarks"></a>Comentários  
 Cada `definition` tem a seguinte forma:  
  
 [[*langtype*]] [[**NEAR** &#124; **FAR**]] *label***:**`type`[[**:***count*]]  
  
 O *rótulo* é o nome da variável. O `type` pode ser qualquer especificador de tipo ([bytes](../../assembler/masm/byte-masm.md), [WORD](../../assembler/masm/word.md), e assim por diante) ou um inteiro que especifica o número de bytes. O *contagem* Especifica o número de objetos de dados (um é o padrão).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)