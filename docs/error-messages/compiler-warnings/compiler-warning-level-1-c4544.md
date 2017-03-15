---
title: "Compilador aviso (nível 1) C4544 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4544
dev_langs:
- C++
helpviewer_keywords:
- C4544
ms.assetid: 11ee04df-41ae-435f-af44-881e801315a8
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
ms.openlocfilehash: 25f71c8fb56083135dd2cdf9645c9ef8dbfbd975
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4544"></a>Compilador C4544 de aviso (nível 1)
'declaração de ': argumento de modelo ignorado nesta declaração de modelo padrão  
  
 Um argumento de modelo padrão foi especificado em um local incorreto e foi ignorado. Um argumento de modelo padrão para um modelo de classe só pode ser especificado na declaração ou definição do modelo de classe e não em um membro do modelo de classe.  
  
 Este exemplo gera C4545 e o próximo exemplo mostra como corrigi-lo:  
  
```  
// C4544.cpp  
// compile with: /W1 /LD  
template <class T>   
struct S  
{  
   template <class T1>   
      struct S1;  
   void f();  
};  
  
template <class T=int>  
template <class T1>  
struct S<T>::S1 {};   // C4544  
```  
  
 Neste exemplo, o parâmetro padrão se aplica ao modelo de classe `S`:  
  
```  
// C4544b.cpp  
// compile with: /LD  
template <class T = int>   
struct S  
{  
   template <class T1>   
      struct S1;  
   void f();  
};  
  
template <class T>  
template <class T1>  
struct S<T>::S1 {};  
```
