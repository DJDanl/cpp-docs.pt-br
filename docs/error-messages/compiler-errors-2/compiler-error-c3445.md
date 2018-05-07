---
title: C3445 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 04/10/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3445
dev_langs:
- C++
helpviewer_keywords:
- C3445
ms.assetid: 0d272bfc-136b-4025-a9ba-5e4eea5f8215
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c37f04b907183b883772fd144ae0179683f088f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3445"></a>C3445 de erro do compilador

> Copy-list-initialization de '*tipo*' não é possível usar um construtor explícito

Acordo com o ISO C++ 17 padrão, o compilador é necessário considerar um construtor explícito para a resolução de sobrecarga na inicialização da lista de cópia, mas deve gerar um erro se essa sobrecarga é na verdade escolhida.

A partir do Visual Studio de 2017, o compilador encontra erros relacionados a criação do objeto usando uma lista de inicializadores não foram encontrados pelo Visual Studio 2015. Esses erros podem levar a falhas ou comportamento indefinido em tempo de execução.

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

Para corrigir o erro, use inicialização direta:

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
