---
title: C3161 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3161
dev_langs:
- C++
helpviewer_keywords:
- C3161
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
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
ms.openlocfilehash: 0e12d426f689281f34a7680164a1197e4c7d94e3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3161"></a>C3161 de erro do compilador
'interface': aninhamento de classe, estrutura, união ou interface em uma interface é ilegal; interface aninhamento em uma classe, estrutura ou união é ilegal  
  
 Um [interface](../../cpp/interface.md) só pode aparecer no escopo global ou dentro de um namespace. Uma classe, estrutura ou união não pode aparecer em uma interface.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3161.  
  
```  
// C3161.cpp  
// compile with: /c  
__interface X {  
   __interface Y {};   // C3161 A nested interface  
};  
```
