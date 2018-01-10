---
title: "COMUNICAÇÃO | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: COMM
dev_langs: C++
helpviewer_keywords: COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ad12de948227f98ec73f779030b8e644dfad8b2c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comm"></a>COMM
Cria uma variável pública com os atributos especificados no `definition`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
COMM definition [[, definition]] ...  
```  
  
## <a name="remarks"></a>Comentários  
 Cada `definition` tem a seguinte forma:  
  
 [[*langtype*]] [[**NEAR** &#124; **EXTREMO**]] *rótulo***:**`type`[[**:***contagem*]]  
  
 O *rótulo* é o nome da variável. O `type` pode ser qualquer especificador de tipo ([bytes](../../assembler/masm/byte-masm.md), [WORD](../../assembler/masm/word.md), e assim por diante) ou um inteiro que especifica o número de bytes. O *contagem* Especifica o número de objetos de dados (um é o padrão).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)