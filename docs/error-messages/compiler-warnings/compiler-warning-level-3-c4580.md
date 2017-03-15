---
title: "Compilador aviso (nível 3) C4580 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4580
dev_langs:
- C++
helpviewer_keywords:
- C4580
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
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
ms.sourcegitcommit: b551b1a7e0ae03a7de5108a1d114155786972847
ms.openlocfilehash: c8cebbda1d3472a2efda43f816e7a13f2f460408
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4580"></a>Compilador C4580 de aviso (nível 3)
[atributo] é substituído; em vez disso, especifique System::Attribute ou Platform:: Metadata como uma classe base  
  
[[atributo](../../windows/attribute.md)] não é mais a sintaxe preferencial para a criação de atributos definidos pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para o código CLR, derivar atributos de `System::Attribute`. Para o código de tempo de execução do Windows, derivar atributos de `Platform::Metadata`.  
  
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
