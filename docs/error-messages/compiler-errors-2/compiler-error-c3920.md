---
title: C3920 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3920
dev_langs:
- C++
helpviewer_keywords:
- C3920
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
caps.latest.revision: 8
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
ms.openlocfilehash: 2acdf4b372abcade3a0dc83e86e9e27f80ef1f75
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3920"></a>C3920 de erro do compilador
' operador ': não é possível definir um operador CLR chamando o sufixo ou sufixo incrementar/diminuir WinRT operador WinRT ou CLR chamará o prefixo correspondente WinRT ou CLR operador (op_Increment op_Decrement), mas semântica de sufixo  
  
 O tempo de execução do Windows e o CLR não dão suporte para o operador de sufixo e operadores de sufixo definida pelo usuário não são permitidas.  Você pode definir um operador de prefixo e o operador de prefixo será usado para operações de pré e pós-incrementos.  
  
 O exemplo a seguir gera C3920 e mostra como corrigi-lo:  
  
```  
// C3920.cpp  
// compile with: /clr /LD  
public value struct V {  
   static V operator ++(V me, int)  
   // try the following line instead  
   // static V operator ++(V me)  
   {   // C3920  
      me.m_i++;  
      return me;  
   }  
  
   int m_i;  
};  
  
```
