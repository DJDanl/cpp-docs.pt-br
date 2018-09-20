---
title: Alterações na ordem de inicialização do construtor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- constructors, C++
ms.assetid: 8892c38d-6bf7-4cf7-ac8f-15e052135a79
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fd54e9810131f3ddfabe458c70ddef081568a9cd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46397683"
---
# <a name="changes-in-constructor-initialization-order"></a>Alterações na ordem de inicialização de construtor

A ordem de inicialização para construtores de classe foi alterado de extensões gerenciadas para C++ no Visual C++.

## <a name="comparison-of-constructor-initialization-order"></a>Comparação de ordem de inicialização do construtor

Nas extensões gerenciadas para C++, a inicialização do construtor ocorreu na seguinte ordem:

1. O construtor da classe base, se houver, será invocado.

1. A lista de inicialização da classe é avaliada.

1. O corpo de código do construtor de classe é executado.

Essa ordem de execução segue as mesmas convenções de programação em C++ nativa. A nova linguagem Visual C++ prescreve a seguinte ordem de execução para classes CLR:

1. A lista de inicialização da classe é avaliada.

1. O construtor da classe base, se houver, será invocado.

1. O corpo de código do construtor de classe é executado.

Observe que essa alteração se aplica apenas às classes CLR; classes nativas do Visual C++ ainda seguem as convenções anteriores. Em ambos os casos, essas regras em cascata para cima em todo o grupo de toda a hierarquia de uma determinada classe.

Considere o seguinte exemplo de código usando extensões gerenciadas para C++:

```
__gc class A
{
public:
   A() : _n(1)
   {
   }

protected:
   int _n;
};

__gc class B : public A
{
public:
   B() : _m(_n)
   {
   }
private:
   int _m;
};
```

Seguindo a ordem de inicialização do construtor indicadas acima, devemos ver a seguinte ordem de execução quando novas instâncias da classe `B` são construídos:

1. O construtor da classe base `A` é invocado. O `_n` membro é inicializado como `1`.

1. A lista de inicialização para a classe `B` é avaliada. O `_m` membro é inicializado como `1`.

1. O corpo de código da classe `B` é executado.

Agora, considere o mesmo código na nova sintaxe Visual C++:

```
ref class A
{
public:
   A() : _n(1)
   {
   }

protected:
   int _n;
};

ref class B : A
{
public:
   B() : _m(_n)
   {
   }
private:
   int _m;
};
```

A ordem de execução quando novas instâncias da classe `B` são construídos na nova sintaxe é:

1. A lista de inicialização para a classe `B` é avaliada. O `_m` membro é inicializado como `0` (`0` é o valor não inicializado do `_m` membro de classe).

1. O construtor da classe base `A` é invocado. O `_n` membro é inicializado como `1`.

1. O corpo de código da classe `B` é executado.

Observe que uma sintaxe similar produz resultados diferentes para esses exemplos de código. O construtor da classe `B` depende de um valor de classe base `A` para inicializar seus membros. No entanto, o construtor da classe `A` ainda não foi invocado. Tal dependência pode ser especialmente perigosa quando a classe herdada depende de uma alocação de memória ou recursos ocorra no construtor da classe base.

## <a name="what-this-means-going-from-managed-extensions-for-c-to-visual-c-2010"></a>O que isso significa que vão do extensões gerenciadas para C++ para Visual C++ 2010

Em muitos casos as alterações para a ordem de execução dos construtores de classe deverá ser transparentes para o programador porque nenhuma noção de que o comportamento de classes herdadas de ter classes base. No entanto, como ilustram esses exemplos de código, os construtores de classes herdadas podem ser bastante afetados quando suas listas de inicialização dependem dos valores de membros de classe base. Quando você move o código de extensões gerenciadas para C++ para a nova sintaxe, considere a migração, essas construções ao corpo do construtor de classes, onde a execução é garantida para ocorrer pela última vez.

## <a name="see-also"></a>Consulte também

[Tipos gerenciados (C++ /CLI CL)](../dotnet/managed-types-cpp-cl.md)<br/>
[Construtores](../cpp/constructors-cpp.md)
