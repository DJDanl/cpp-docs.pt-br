---
title: Usando Lambdas, objetos de função e funções restritas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-amp
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 25346cc9-869d-4ada-aad3-e2228cad3d6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5e3e5ab742335cfd6bb47a5105995d7339c7c36a
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33687446"
---
# <a name="using-lambdas-function-objects-and-restricted-functions"></a>Usando lambdas, objetos de função e funções restritas
O código C++ AMP que você deseja executar o Accelerator é especificado como um argumento em uma chamada para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método. Você pode fornecer uma expressão lambda ou um objeto de função (functor) como argumento. Além disso, o objeto de função ou expressão lambda pode chamar uma função C++ AMP-restrita. Este tópico usa um algoritmo de adição de matriz para demonstrar lambdas, objetos de função e funções restritas. O exemplo a seguir mostra o algoritmo sem código C++ AMP. Duas matrizes dimensionais 1 de comprimento igual são criados. Os elementos de inteiro correspondente são adicionados e armazenados em uma terceira matriz em 1 dimensão. C++ AMP não é usado.  
  
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
 Usar uma expressão lambda é a maneira mais direta para usar o C++ AMP para reescrever o código.  
  
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
  
 A expressão lambda deve incluir um parâmetro de indexação e deve incluir `restrict(amp)`. No exemplo, o [array_view](../../parallel/amp/reference/array-view-class.md) `sum` objeto tem uma classificação 1. Portanto, o parâmetro para a declaração de lambda é um [índice](../../parallel/amp/reference/index-class.md) objeto com classificação 1. Em tempo de execução, a expressão lambda é executada uma vez para cada elemento de [array_view](../../parallel/amp/reference/array-view-class.md) objeto. Para obter mais informações, consulte [sintaxe da expressão Lambda](../../cpp/lambda-expression-syntax.md).  
  
## <a name="function-object"></a>Objeto Function  
 Você pode influenciar o código de aceleração um objeto de função.  
  
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

 O objeto de função deve incluir um construtor e deve incluir uma sobrecarga de operador de chamada de função. O operador de chamada de função deve incluir um parâmetro de indexação. Uma instância do objeto de função é passada como o segundo argumento para o [parallel_for_each](reference/concurrency-namespace-functions-amp.md#parallel_for_each) método. Neste exemplo, três [array_view](../../parallel/amp/reference/array-view-class.md) objetos são passados para o construtor do objeto de função. O [array_view](../../parallel/amp/reference/array-view-class.md) objeto `sum` tem uma classificação 1. Portanto, o parâmetro para o operador de chamada de função é um [índice](../../parallel/amp/reference/index-class.md) objeto com classificação 1. Em tempo de execução, a função é executada uma vez para cada elemento de [array_view](../../parallel/amp/reference/array-view-class.md) objeto. Para obter mais informações, consulte [chamada de função](../../cpp/function-call-cpp.md) e [objetos de função na biblioteca padrão C++](../../standard-library/function-objects-in-the-stl.md).  
  
## <a name="c-amp-restricted-function"></a>Função restrita AMP do C++  
 Ainda mais, você pode considerar o código de acelerador criando uma função restrita e chamando-o em uma expressão lambda ou um objeto de função. O exemplo de código a seguir demonstra como chamar uma função restrita de uma expressão lambda.  
  
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
  
 A função restrita deve incluir `restrict(amp)` e estar de acordo com as restrições descritas [restrita (C++ AMP)](../../cpp/restrict-cpp-amp.md).  
  
## <a name="see-also"></a>Consulte também  
 [C++ AMP (C++ Accelerated Massive Parallelism)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)   
 [Chamada de função](../../cpp/function-call-cpp.md)   
 [Objetos de função na biblioteca C++ padrão](../../standard-library/function-objects-in-the-stl.md)   
 [restrict (C++ AMP)](../../cpp/restrict-cpp-amp.md)

