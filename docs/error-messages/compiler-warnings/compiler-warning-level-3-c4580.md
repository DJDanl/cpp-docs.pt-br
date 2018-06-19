---
title: Compilador aviso (nível 3) C4580 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4580
dev_langs:
- C++
helpviewer_keywords:
- C4580
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 89ad08af77b62cd0992e9415e2df8b31233e4e0d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33290976"
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