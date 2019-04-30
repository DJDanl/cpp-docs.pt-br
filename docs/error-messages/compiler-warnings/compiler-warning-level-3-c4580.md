---
title: Compilador aviso (nível 3) C4580
ms.date: 11/04/2016
f1_keywords:
- C4580
helpviewer_keywords:
- C4580
ms.assetid: fef6e8e0-0d6a-44fa-b22a-2fe7ba2ef379
ms.openlocfilehash: bd2ecff5adc6538f75c61772b785acbfc89092ae
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401794"
---
# <a name="compiler-warning-level-3-c4580"></a>Compilador aviso (nível 3) C4580

[attribute] é preterido; em vez disso, especifique System::Attribute ou Platform:: Metadata como uma classe base

[[atributo](../../windows/attributes/attribute.md)] não é mais a sintaxe preferencial para a criação de atributos definidos pelo usuário. Para obter mais informações, consulte [atributos definidos pelo usuário](../../extensions/user-defined-attributes-cpp-component-extensions.md). Para o código do CLR, derivar atributos de `System::Attribute`. Para o código de tempo de execução do Windows, derivar atributos de `Platform::Metadata`.

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