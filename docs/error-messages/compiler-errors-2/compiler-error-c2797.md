---
title: Erro do compilador C2797 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2797
dev_langs:
- C++
helpviewer_keywords:
- C2797
ms.assetid: 9fb26d35-eb5c-46fc-9ff5-756fba5bdaff
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 701ec194c968b9f1d17269573b33e78d69fbb256
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46035364"
---
# <a name="compiler-error-c2797"></a>Erro do Compilador C2797

(Obsoleto) Inicialização de lista dentro da lista de inicializador de membro ou inicializador de membro de dados não estáticos não está implementada.

Esse aviso está obsoleto no Visual Studio 2015. No Visual Studio 2013 e versões anteriores, o compilador do Visual C++ não implementa a inicialização de lista dentro de uma lista de inicializadores de membro ou um inicializador de membro de dados não estáticos. Antes da Atualização 3 do Visual Studio 2013, ele era silenciosamente convertido em uma chamada de função, que pode levar a geração de código incorreto. A Atualização 3 do Visual Studio 2013 relata isso como um erro.

Esse exemplo gera C2797:

```
#include <vector>
struct S {
    S() : v1{1} {} // C2797, VS2013 RTM incorrectly calls 'vector(size_type)'

    std::vector<int> v1;
    std::vector<int> v2{1, 2}; // C2797, VS2013 RTM incorrectly calls 'vector(size_type, const int &)'
};

```

Esse exemplo também gera C2797:

```
struct S1 {
    int i;
};

struct S2 {
    S2() : s1{0} {} // C2797, VS2013 RTM interprets as S2() : s1(0) {} causing C2664
    S1 s1;
    S1 s2{0}; // C2797, VS2013 RTM interprets as S1 s2 = S1(0); causing C2664
};

```

Para corrigir esse problema, você pode usar a construção explícita de listas internas. Por exemplo:

```
#include <vector>
typedef std::vector<int> Vector;
struct S {
    S() : v1(Vector{1}) {}

    Vector v1;
    Vector v2 = Vector{1, 2};
};

```

Se você não necessitar de inicialização da lista:

```
struct S {
    S() : s1("") {}

    std::string s1;
    std::string s2 = std::string("");
};

```

(O compilador do Visual Studio 2013 faz isso implicitamente antes da Atualização 3 do Visual Studio 2013.)