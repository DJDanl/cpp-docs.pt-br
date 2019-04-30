---
title: Compilador C4373 de aviso (nível 3)
ms.date: 11/04/2016
f1_keywords:
- C4373
helpviewer_keywords:
- C4373
ms.assetid: 670c0ba3-b7d6-4aed-b207-1cb84da3bcde
ms.openlocfilehash: 031b32a03d93a51f6fa00041a5b0bdf99e6eacf1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401989"
---
# <a name="compiler-warning-level-3-c4373"></a>Compilador C4373 de aviso (nível 3)

> '*função*': substituições de função virtual*base_function*', as versões anteriores do compilador não substituíam quando parâmetros diferiam apenas em qualificadores const/volatile

## <a name="remarks"></a>Comentários

Seu aplicativo contém um método em uma classe derivada que substitui um método virtual em uma classe base e os parâmetros no método de substituição diferem somente por um [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md) qualificador das parâmetros do método virtual. Isso significa que o compilador deve vincular uma referência de função para o método em qualquer uma base ou classe derivada.

Versões do compilador antes do Visual Studio 2008 associar a função para o método na classe base e, em seguida, emitem uma mensagem de aviso. As versões subsequentes do compilador ignorar os `const` ou `volatile` qualificador, associar a função para o método na classe derivada e, em seguida, emitir aviso **C4373**. Esse último comportamento está em conformidade com o padrão C++.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera o aviso C4373. Para resolver esse problema, você pode fazer a substituição de usar os qualificadores CV mesmos que a função de membro base ou, se você não pretendia criar uma substituição, você pode atribuir a função na classe derivada um nome diferente.

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

void main()
{
    Derived d;
    Base* p = &d;
    p->f(1);
}
```

```Output
derived
```