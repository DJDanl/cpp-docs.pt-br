---
title: C3279 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3279
dev_langs:
- C++
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
caps.latest.revision: 9
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
ms.openlocfilehash: 79b2d44cdb55237f190195cd063b34d0b55d7293
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3279"></a>C3279 de erro do compilador
especializações parciais e explícitas bem como instanciações explícitas de templates de classe declaradas no namespace cli não são permitidas  
  
 O `cli` namespace é definida pela Microsoft e contém modelos pseudo. O compilador do Visual C++ não permite especializações definidas pelo usuário, parciais e explícitas e explícitas instanciações de modelos de classe neste namespace.  
  
 O exemplo a seguir gera C3279:  
  
```  
// C3279.cpp  
// compile with: /clr  
namespace cli {  
   template <> ref class array<int> {};   // C3279  
   template <typename T> ref class array<T, 2> {};   // C3279  
}  
```
