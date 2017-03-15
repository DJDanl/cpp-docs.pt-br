---
title: "Compilador aviso (nível 1) C4662 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4662
dev_langs:
- C++
helpviewer_keywords:
- C4662
ms.assetid: 7efda273-d04a-47b7-ad65-ff1ff94b5ffc
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 530e49e1d82cf635e84f21738fd26f6fa42eee78
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4662"></a>Compilador C4662 de aviso (nível 1)
instanciação explícita; classe de modelo 'identifier1' não tem nenhuma definição da qual specialize 'identifier2'  
  
 A classe de modelo especificada foi declarada, mas não definida.  
  
## <a name="example"></a>Exemplo  
  
```  
// C4662.cpp  
// compile with: /W1 /LD  
template<class T, int i> class MyClass; // no definition  
template MyClass< int, 1>;              // C4662  
```
