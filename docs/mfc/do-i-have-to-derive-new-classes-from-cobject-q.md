---
title: Preciso derivar novas classes de CObject? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 51904ac06ae6c2db5586f8dc405f85145c5b1f30
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?
Não, não.  
  
 Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto é sempre uma boa ideia para derivar de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [Rabisco exemplo](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
