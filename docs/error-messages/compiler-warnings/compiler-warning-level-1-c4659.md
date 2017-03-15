---
title: "Compilador aviso (nível 1) C4659 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4659
dev_langs:
- C++
helpviewer_keywords:
- C4659
ms.assetid: e29ba8db-7917-43f6-8e34-868b752279ae
caps.latest.revision: 7
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 22cf922c9da26d81452f0939aad6202479340ad5
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4659"></a>Compilador C4659 de aviso (nível 1)
\#pragma 'pragma': uso de segmento reservado 'segmento' tem um comportamento indefinido, use #pragma comment (linker...)  
  
 A opção .drectve foi usada para passar uma opção para o vinculador. Em vez disso, usar o pragma [comentário](../../preprocessor/comment-c-cpp.md) para passar uma opção de vinculador.  
  
```  
// C4659.cpp  
// compile with: /W1 /LD  
#pragma code_seg(".drectve")   // C4659  
```
