---
title: Erro do compilador C3445
ms.date: 04/10/2017
f1_keywords:
- C3445
helpviewer_keywords:
- C3445
ms.assetid: 0d272bfc-136b-4025-a9ba-5e4eea5f8215
ms.openlocfilehash: 2eddeb5a56c953ca0864e29187fbe28c53bdee24
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62328625"
---
# <a name="compiler-error-c3445"></a>Erro do compilador C3445

> Copy-list-initialization de '*tipo*' não é possível usar um construtor explícito

Acordo com o ISO C++ 17 standard, o compilador é necessária para considerar um construtor explícito para resolução de sobrecarga em copy-list-initialization, mas deverá gerar um erro se essa sobrecarga for realmente escolhida.

A partir do Visual Studio 2017, o compilador encontrar erros relacionados à criação de objetos por meio de uma lista de inicializadores que não foram encontrados pelo Visual Studio 2015. Esses erros pode levar a falhas ou comportamento indefinido em tempo de execução.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3445.

```cpp
// C3445.cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    A a1 = { 1 };     // error C3445: copy-list-initialization of
                      //     'A' cannot use an explicit constructor
}
```

Para corrigir o erro, use em vez disso, a inicialização direta:

```cpp
// C3445b.cpp
struct A
{
    explicit A(int) {}
    A(double) {}
};

int main()
{
    A a1{ 1 };
}
```
