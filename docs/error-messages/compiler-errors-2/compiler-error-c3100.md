---
title: Compilador erro C3100 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3100
dev_langs:
- C++
helpviewer_keywords:
- C3100
ms.assetid: 7a9c9eaf-08ef-442d-94a0-e457beee8549
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 666bd441fa45b56f9dc572b01f9428ee48b8d1bf
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3100"></a>C3100 de erro do compilador
'target': qualificador de atributo desconhecido  
  
 Um destino de atributo inválido foi especificado.  
  
 Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3100.  
  
```  
// C3100.cpp  
// compile with: /clr /c  
using namespace System;  
[AttributeUsage(AttributeTargets::All)]  
public ref class Attr : public Attribute {  
public:  
   Attr(int t) : m_t(t) {}  
   int m_t;  
};  
  
[invalid_target:Attr(10)];   // C3100  
[assembly:Attr(10)];   // OK  
```
