---
title: Objetos de função na Biblioteca Padrão C++
ms.date: 03/15/2019
helpviewer_keywords:
- functors
- C++ Standard Library, functors
- C++ Standard Library, function objects
- function objects
ms.assetid: 85f8a735-2c7b-4f10-9c4d-95c666ec4192
ms.openlocfilehash: ed413b2bcdcda8f65794b10c792b10358564420a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215732"
---
# <a name="function-objects-in-the-c-standard-library"></a>Objetos de função na Biblioteca Padrão C++

Um *objeto de função* ou *functor*, é qualquer tipo que implementa operator(). Esse operador é conhecido como *operador de chamada* ou, às vezes, *operador de aplicativo*. A Biblioteca Padrão C++ usa objetos de função principalmente como critérios de classificação para contêineres e em algoritmos.

Objetos de função fornecem duas vantagens principais com relação a uma chamada de função direta. A primeira é que um objeto de função pode conter o estado. A segunda é que um objeto de função é um tipo e, portanto, pode ser usado como um parâmetro de modelo.

## <a name="creating-a-function-object"></a>Criando um objeto de função

Para criar um objeto de função, crie um tipo e implemente operator(), como:

```cpp
class Functor
{
public:
    int operator()(int a, int b)
    {
        return a < b;
    }
};

int main()
{
    Functor f;
    int a = 5;
    int b = 7;
    int ans = f(a, b);
}
```

A última linha da função `main` mostra como chamar o objeto de função. Essa chamada é semelhante a uma chamada para uma função, mas ela está realmente chamando operator () do tipo functor. É dessa semelhança entre chamar um objeto de função e uma função que surgiu o termo objeto de função.

## <a name="function-objects-and-containers"></a>Contêineres e objetos de função

A biblioteca padrão C++ contém vários objetos de função no [\<functional>](../standard-library/functional.md) arquivo de cabeçalho. Um uso desses objetos de função é como critério de classificação para contêineres. Por exemplo, o contêiner `set` é declarado da seguinte maneira:

```cpp
template <class Key,
    class Traits=less<Key>,
    class Allocator=allocator<Key>>
class set
```

O segundo argumento de modelo é o objeto de função `less`. Esse objeto de função retorna **`true`** se o primeiro parâmetro é menor que o segundo parâmetro. Como alguns contêineres classificam seus elementos, o contêiner precisa de uma maneira de comparar dois elementos. A comparação é feita usando o objeto de função. Você pode definir seus próprios critérios de classificação para contêineres criando um objeto de função e especificando-o na lista de modelos para o contêiner.

## <a name="function-objects-and-algorithms"></a>Algoritmos e objetos de função

Outro uso dos objetos funcionais é em algoritmos. Por exemplo, o algoritmo `remove_if` é declarado da seguinte maneira:

```cpp
template <class ForwardIterator, class Predicate>
ForwardIterator remove_if(
    ForwardIterator first,
    ForwardIterator last,
    Predicate pred);
```

O último argumento para `remove_if` é um objeto de função que retorna um valor booliano (um *predicado*). Se o resultado do objeto de função for **`true`** , o elemento será removido do contêiner que está sendo acessado pelos iteradores `first` e `last` . Você pode usar qualquer um dos objetos de função declarados no [\<functional>](../standard-library/functional.md) cabeçalho para o argumento `pred` ou você pode criar o seu próprio.

## <a name="see-also"></a>Confira também

[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
