---
title: C4694 de aviso do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4694
dev_langs:
- C++
helpviewer_keywords:
- C4694
ms.assetid: 5ca122bb-34f3-43ee-a21f-95802cd515f7
caps.latest.revision: 3
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
ms.openlocfilehash: ae91c5b8af97d02223e1d7154d1cf029493cdc7c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4694"></a>C4694 de aviso do compilador
'class_1': uma classe abstrata lacrada não pode ter uma classe base 'base_class'  
  
 Uma classe abstract e sealed não pode herdar de um tipo de referência. uma classe abstract e sealed não pode implementar as funções de classe base nem permitir que ela própria ser usada como uma classe base.  
  
 Para obter mais informações, consulte [abstrato](../../windows/abstract-cpp-component-extensions.md), [lacrado](../../windows/sealed-cpp-component-extensions.md), e [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4694.  
  
```  
// C4694.cpp  
// compile with: /c /clr  
ref struct A {};  
ref struct B sealed abstract : A {};   // C4694  
```
