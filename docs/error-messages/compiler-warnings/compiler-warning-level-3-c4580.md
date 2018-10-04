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
ms.openlocfilehash: 90cd0b401624ea6815b31b55a7da9c8796746ce8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789196"
---
# <a name="compiler-warning-level-3-c4580"></a>Compilador aviso (nível 3) C4580

[attribute] é preterido; em vez disso, especifique System::Attribute ou Platform:: Metadata como uma classe base

[[atributo](../../windows/attributes/attribute.md)] não é mais a sintaxe preferencial para a criação de atributos definidos pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md). Para o código do CLR, derivar atributos de `System::Attribute`. Para o código de tempo de execução do Windows, derivar atributos de `Platform::Metadata`.

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