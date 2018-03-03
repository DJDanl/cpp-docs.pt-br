---
title: "Compilador aviso (nível 3) C4580 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4580
dev_langs:
- C++
helpviewer_keywords:
- C4580
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ed0391a1a31b4ab64efa01fc15622831de890489
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-3-c4580"></a>Compilador C4580 de aviso (nível 3)
[attribute] é preterido; em vez disso, especifique System::Attribute ou Platform:: Metadata como uma classe base  
  
[[atributo](../../windows/attribute.md)] não é mais a sintaxe preferencial para criar atributos definidos pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para o código CLR, derivar os atributos `System::Attribute`. Código de tempo de execução do Windows, derivar os atributos `Platform::Metadata`.  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3454 e mostra como corrigi-lo.  
  
```cpp  
// C4580.cpp  
// compile with: /W3 /c /clr  
[attribute]   // C4580  
public ref class Attr {  
public:  
   int m_t;  
};  
  
public ref class Attr2 : System::Attribute {  
public:  
   int m_t;  
};  
```