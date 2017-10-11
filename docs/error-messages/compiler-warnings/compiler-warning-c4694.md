---
title: C4694 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 04754b1215cf3c4ee44554a253ef6d00b0b67f2b
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-c4694"></a>C4694 de aviso do compilador
'class_1': uma classe sealed abstract não pode ter uma classe base 'base_class'  
  
 Uma classe abstract e sealed não pode herdar de um tipo de referência. uma classe abstract e sealed não pode implementar as funções de classe base nem permitir que ela própria a ser usado como uma classe base.  
  
 Para obter mais informações, consulte [abstrata](../../windows/abstract-cpp-component-extensions.md), [lacrado](../../windows/sealed-cpp-component-extensions.md), e [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4694.  
  
```  
// C4694.cpp  
// compile with: /c /clr  
ref struct A {};  
ref struct B sealed abstract : A {};   // C4694  
```
