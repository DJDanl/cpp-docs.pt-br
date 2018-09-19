---
title: Erro do compilador C2316 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2316
dev_langs:
- C++
helpviewer_keywords:
- C2316
ms.assetid: 9ad08eb5-060b-4eb0-8d66-0dc134f7bf67
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2868d3a81fcbc94d8b20adcdc775363eb0a8eaeb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033011"
---
# <a name="compiler-error-c2316"></a>Erro do compilador C2316

> '*exceção*': não pode ser detectado porque o destruidor e/ou o construtor de cópia é inacessível

Uma exceção foi capturada por valor ou por referência, mas o construtor de cópia e/ou o operador de atribuição estava inacessível.

Esse código foi aceita por versões do Visual C++ anteriores ao Visual Studio 2003, mas agora retorna um erro.

Alterações de conformidade no Visual Studio 2015 feitas a esse erro se aplicam a instruções catch incorreta de exceções de MFC derivadas de `CException`. Porque `CException` tem um construtor de cópia privada herdada, a classe e seus derivados não podem ser copiados e não podem ser passados por valor, que também significa que eles não podem ser detectados pelo valor. Obter declarações que exceções de MFC capturadas por valor anteriormente levou a exceções não identificadas no tempo de execução, mas agora o compilador identifica corretamente essa situação e relatórios de erro C2316. Para corrigir esse problema, é recomendável que você use as macros MFC TRY/CATCH em vez de escrever seus próprios manipuladores de exceção, mas se não for apropriada para seu código, capturar exceções de MFC por referência em vez disso.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2316:

```
// C2316.cpp
// compile with: /EHsc
#include <stdio.h>

extern "C" int printf_s(const char*, ...);

struct B
{
public:
    B() {}
    // Delete the following line to resolve.
private:
    // copy constructor
    B(const B&)
    {
    }
};

void f(const B&)
{
}

int main()
{
    try
    {
        B aB;
        f(aB);
    }
    catch (B b) {   // C2316
        printf_s("Caught an exception!\n");
    }
}
```