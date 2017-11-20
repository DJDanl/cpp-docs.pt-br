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
ms.openlocfilehash: b8feb74f1da11fb6c4205ec1d8381f78789f684f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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