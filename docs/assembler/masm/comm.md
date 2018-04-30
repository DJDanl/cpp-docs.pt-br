---
title: COMM | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- COMM
dev_langs:
- C++
helpviewer_keywords:
- COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 111dac47089fea13febe787e5b73557b287beea8
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="comm"></a>COMM
Cria uma variável pública com os atributos especificados no `definition`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
COMM definition [[, definition]] ...  
```  
  
## <a name="remarks"></a>Comentários  
 Cada `definition` tem a seguinte forma:  
  
 [[*langtype*]] [[**NEAR** &#124; **FAR**]] *label ***:**`type`[[**:*** count*]]  
  
 O *rótulo* é o nome da variável. O `type` pode ser qualquer especificador de tipo ([bytes](../../assembler/masm/byte-masm.md), [WORD](../../assembler/masm/word.md), e assim por diante) ou um inteiro que especifica o número de bytes. O *contagem* Especifica o número de objetos de dados (um é o padrão).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)