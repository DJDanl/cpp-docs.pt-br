---
title: Usando abort | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- Abort
dev_langs:
- C++
helpviewer_keywords:
- abort function
ms.assetid: 3ba39b78-ef74-4a8d-8dee-2d62442de174
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 690e76eb3b83844e0fed81bf8d7bbd4c395abb14
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="using-abort"></a>Usando abort
Chamando o [anular](../c-runtime-library/reference/abort.md) função causa o encerramento imediato. Ignora o processo normal de destruição para objetos estáticos globais inicializados. Também ignora o processamento especial que foi especificado usando a função `atexit`.  
  
## <a name="see-also"></a>Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)
