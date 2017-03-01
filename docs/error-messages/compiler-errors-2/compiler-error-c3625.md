---
title: C3625 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3625
dev_langs:
- C++
helpviewer_keywords:
- C3625
ms.assetid: fdf49f21-d6b1-42f4-9eec-23b04ae8b4aa
caps.latest.revision: 11
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
ms.sourcegitcommit: c243063a9770542f137d5950e8a269f771960f74
ms.openlocfilehash: bb9013e8560907ba06fefbf27e7d3da24c5d2759
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3625"></a>C3625 de erro do compilador
'native_type': um tipo nativo não pode derivar de gerenciada ou WinRT digite 'type'  
  
Uma classe nativa não pode herdar de gerenciada ou WinRT classe. Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3625:  
  
```  
// C3625.cpp  
// compile with: /clr /c  
ref class B {};  
class D : public B {};   // C3625 cannot inherit from a managed class  
```  

