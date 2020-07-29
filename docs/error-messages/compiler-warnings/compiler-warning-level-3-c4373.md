---
title: Aviso do compilador (nível 3) C4373
ms.date: 11/04/2016
f1_keywords:
- C4373
helpviewer_keywords:
- C4373
ms.assetid: 670c0ba3-b7d6-4aed-b207-1cb84da3bcde
ms.openlocfilehash: b3ab8a0c5d826aa44eee3fea53908091ef0c6803
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225313"
---
# <a name="compiler-warning-level-3-c4373"></a>Aviso do compilador (nível 3) C4373

> '*Function*': a função virtual substitui '*base_function*', as versões anteriores do compilador não substituiram quando os parâmetros diferem apenas pelos qualificadores const/volatile

## <a name="remarks"></a>Comentários

Seu aplicativo contém um método em uma classe derivada que substitui um método virtual em uma classe base, e os parâmetros no método de substituição diferem apenas em um qualificador [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md) dos parâmetros do método virtual. Isso significa que o compilador deve associar uma referência de função ao método na classe base ou derivada.

As versões do compilador anteriores ao Visual Studio 2008 associam a função ao método na classe base e, em seguida, emitem uma mensagem de aviso. As versões subsequentes do compilador ignoram o **`const`** **`volatile`** qualificador ou, associam a função ao método na classe derivada e, em seguida, emitem **C4373**de aviso. Esse último comportamento está em conformidade com o padrão C++.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera o aviso C4373. Para resolver esse problema, você pode fazer com que a substituição use os mesmos qualificadores CV que a função membro base, ou se você não pretendia criar uma substituição, você pode dar à função na classe derivada um nome diferente.

```cpp
// c4373.cpp
// compile with: /c /W3
#include <stdio.h>
struct Base
{
    virtual void f(int i) {
        printf("base\n");
    }
};

struct Derived : Base
{
    void f(const int i) {  // C4373
        printf("derived\n");
    }
};

int main()
{
    Derived d;
    Base* p = &d;
    p->f(1);
}
```

```Output
derived
```
