---
title: "Compilador (nível 1) de aviso C4544 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4544
dev_langs:
- C++
helpviewer_keywords:
- C4544
ms.assetid: 11ee04df-41ae-435f-af44-881e801315a8
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5b84683c4b3fffcb9e23c6d80fb3f81684006f15
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4544"></a>Compilador C4544 de aviso (nível 1)
'declaração de ': argumento de template ignorado nessa declaração de template padrão  
  
 Um argumento de template padrão foi especificado em um local incorreto e foi ignorado. Um argumento de modelo padrão para um modelo de classe só pode ser especificado na declaração ou definição do modelo de classe e não em um membro do modelo de classe.  
  
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