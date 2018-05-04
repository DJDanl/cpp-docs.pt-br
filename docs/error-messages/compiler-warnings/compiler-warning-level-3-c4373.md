---
title: Compilador aviso (nível 3) C4373 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- C4373
dev_langs:
- C++
helpviewer_keywords:
- C4373
ms.assetid: 670c0ba3-b7d6-4aed-b207-1cb84da3bcde
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e1694c8d15ad65b39a27af8ae5aae02e9c729896
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="compiler-warning-level-3-c4373"></a>Compilador C4373 de aviso (nível 3)

> '*função*': substituições de função virtual*base_function*', versões anteriores do compilador não substituíam quando parâmetros diferiam apenas em qualificadores const/volatile

## <a name="remarks"></a>Comentários

Seu aplicativo contém um método em uma classe derivada que substitui um método virtual em uma classe base, e os parâmetros no método de substituição diferem somente por um [const](../../cpp/const-cpp.md) ou [volátil](../../cpp/volatile-cpp.md) qualificador das parâmetros do método virtual. Isso significa que o compilador deve associar uma referência de função para o método em uma base ou classe derivada.

Versões do compilador antes do Visual Studio 2008 associar a função para o método na classe base, em seguida, emitem uma mensagem de aviso. As versões subsequentes do compilador ignorar o `const` ou `volatile` qualificador, associar a função para o método na classe derivada, em seguida, emitir o aviso **C4373**. Esse último comportamento compatível com o padrão do C++.

## <a name="example"></a>Exemplo

O exemplo de código a seguir gera um aviso C4373. Para resolver esse problema, você pode fazer a substituição de usar os qualificadores de VC mesmo que a função de membro base ou, se você não pretendia criar uma substituição, você pode atribuir a função na classe derivada um nome diferente.

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