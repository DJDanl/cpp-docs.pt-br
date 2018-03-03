---
title: Preciso derivar novas classes de CObject? | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- derived classes [MFC], from CObject
- CObject class [MFC], when to use
ms.assetid: 26021031-feaf-424c-80d1-9547c4409d6a
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c485bba4d62d279b0f17b887080284940a8bbdd5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="do-i-have-to-derive-new-classes-from-cobject"></a>Preciso derivar novas classes de CObject?
Não, não.  
  
 Derive uma classe de [CObject](../mfc/reference/cobject-class.md) quando precisar que os recursos que ele fornece, como a serialização ou creatability dinâmico. Muitas classes de dados precisam ser serializados para arquivos, portanto é sempre uma boa ideia para derivar de `CObject`. Para um exemplo de uma classe derivada de `CObject`, consulte o [Rabisco exemplo](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject: perguntas frequentes](../mfc/cobject-class-frequently-asked-questions.md)
