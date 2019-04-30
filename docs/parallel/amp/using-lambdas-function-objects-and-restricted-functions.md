---
title: Usando lambdas, objetos de função e funções restritas
ms.date: 11/04/2016
ms.assetid: 25346cc9-869d-4ada-aad3-e2228cad3d6c
ms.openlocfilehash: 0c72ae6f600fe73405481e34ab05b60f163e44d2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405320"
---
# <a name="using-lambdas-function-objects-and-restricted-functions"></a>Usando lambdas, objetos de função e funções restritas

O C++ código de AMP que você deseja executar no Acelerador é especificado como um argumento em uma chamada para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método. Você pode fornecer uma expressão lambda ou um objeto de função (functor) como o argumento. Além disso, o objeto de função ou expressão lambda pode chamar uma função restrita C++ AMP. Este tópico usa um algoritmo de adição de matriz para demonstrar lambdas, objetos de função e funções restritas. O exemplo a seguir mostra o algoritmo sem código de C++ AMP. São criadas duas matrizes dimensionais 1 de comprimento igual. Os elementos inteiros correspondentes são adicionados e armazenados em uma terceira matriz dimensional de 1. C++ AMP não é usado.

```cpp
void CpuMethod() {

    int aCPP[] = {1, 2, 3, 4, 5};
    int bCPP[] = {6, 7, 8, 9, 10};
    int sumCPP[5];

    for (int idx = 0; idx <5; idx++)
    {
        sumCPP[idx] = aCPP[idx] + bCPP[idx];
    }

    for (int idx = 0; idx <5; idx++)
    {
        std::cout <<sumCPP[idx] <<"\n";
    }
}
```

## <a name="lambda-expression"></a>Expressão lambda

Usando uma expressão lambda é a maneira mais direta para usar o C++ AMP para reescrever o código.

```cpp
void AddArraysWithLambda() {
    int aCPP[] = {1, 2, 3, 4, 5};
    int bCPP[] = {6, 7, 8, 9, 10};
    int sumCPP[5];

    array_view<const int, 1> a(5, aCPP);

    array_view<const int, 1> b(5, bCPP);

    array_view<int, 1> sum(5, sumCPP);

    sum.discard_data();

    parallel_for_each(
        sum.extent,
        [=](index<1> idx) restrict(amp)
        {
             sum[idx] = a[idx] + b[idx];
        });

    for (int i = 0; i <5; i++) {
        std::cout <<sum[i] <<"\n";
    }
}
```

A expressão lambda deve incluir um parâmetro indexação e deve incluir `restrict(amp)`. No exemplo, o [array_view](../../parallel/amp/reference/array-view-class.md) `sum` objeto tem classificação 1. Portanto, o parâmetro para a instrução lambda é uma [índice](../../parallel/amp/reference/index-class.md) objeto que possui a posição 1. Em tempo de execução, a expressão lambda é executada uma vez para cada elemento de [array_view](../../parallel/amp/reference/array-view-class.md) objeto. Para obter mais informações, consulte [sintaxe de expressão Lambda](../../cpp/lambda-expression-syntax.md).

## <a name="function-object"></a>Objeto Function

Você pode fatorar o código de aceleradores em um objeto de função.

```cpp
class AdditionFunctionObject
{
public:
    AdditionFunctionObject(const array_view<int, 1>& a,
    const array_view<int, 1>& b,
    const array_view<int, 1>& sum)
    : a(a), b(b), sum(sum)
    {
    }

    void operator()(index<1> idx) restrict(amp)
    {
        sum[idx] = a[idx] + b[idx];
    }

private:
    array_view<int, 1> a;
    array_view<int, 1> b;
    array_view<int, 1> sum;
};

void AddArraysWithFunctionObject() {
    int aCPP[] = {1, 2, 3, 4, 5};
    int bCPP[] = {6, 7, 8, 9, 10};
    int sumCPP[5];

    array_view<const int, 1> a(5, aCPP);

    array_view<const int, 1> b(5, bCPP);

    array_view<int, 1> sum(5, sumCPP);

    sum.discard_data();

    parallel_for_each(
        sum.extent,
        AdditionFunctionObject(a, b, sum));

    for (int i = 0; i <5; i++) {
        std::cout <<sum[i] <<"\n";
    }
}
```

O objeto de função deve incluir um construtor e deve incluir uma sobrecarga de operador de chamada de função. O operador de chamada de função deve incluir um parâmetro indexação. Uma instância do objeto de função é passada como segundo argumento para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método. Neste exemplo, três [array_view](../../parallel/amp/reference/array-view-class.md) objetos são passados para o construtor do objeto de função. O [array_view](../../parallel/amp/reference/array-view-class.md) objeto `sum` tem classificação 1. Portanto, o parâmetro para o operador de chamada de função é um [índice](../../parallel/amp/reference/index-class.md) objeto que possui a posição 1. Em tempo de execução, a função é executada uma vez para cada elemento de [array_view](../../parallel/amp/reference/array-view-class.md) objeto. Para obter mais informações, consulte [chamada de função](../../cpp/function-call-cpp.md) e [objetos de função na biblioteca padrão C++](../../standard-library/function-objects-in-the-stl.md).

## <a name="c-amp-restricted-function"></a>Função restrita por AMP do C++

Você ainda pode incluir o código de aceleradores criando uma função restrita e chamando-o em uma expressão lambda ou um objeto de função. O exemplo de código a seguir demonstra como chamar uma função estritamente de uma expressão lambda.

```cpp
void AddElementsWithRestrictedFunction(index<1> idx, array_view<int, 1> sum, array_view<int, 1> a, array_view<int, 1> b) restrict(amp)
{
    sum[idx] = a[idx] + b[idx];
}

void AddArraysWithFunction() {

    int aCPP[] = {1, 2, 3, 4, 5};
    int bCPP[] = {6, 7, 8, 9, 10};
    int sumCPP[5];

    array_view<int, 1> a(5, aCPP);

    array_view<int, 1> b(5, bCPP);

    array_view<int, 1> sum(5, sumCPP);

    sum.discard_data();

    parallel_for_each(
        sum.extent,
        [=](index<1> idx) restrict(amp)
        {
            AddElementsWithRestrictedFunction(idx, sum, a, b);
        });

    for (int i = 0; i <5; i++) {
        std::cout <<sum[i] <<"\n";
    }
}
```

A função estritamente deve incluir `restrict(amp)` e estão em conformidade com as restrições descritas [restrita (C++ AMP)](../../cpp/restrict-cpp-amp.md).

## <a name="see-also"></a>Consulte também

[C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)<br/>
[Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)<br/>
[Chamada de função](../../cpp/function-call-cpp.md)<br/>
[Objetos de função na Biblioteca Padrão C++](../../standard-library/function-objects-in-the-stl.md)<br/>
[restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)
