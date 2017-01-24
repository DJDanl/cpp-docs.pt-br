---
title: "Usando lambdas, objetos de fun&#231;&#227;o e fun&#231;&#245;es restritas | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 25346cc9-869d-4ada-aad3-e2228cad3d6c
caps.latest.revision: 10
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando lambdas, objetos de fun&#231;&#227;o e fun&#231;&#245;es restritas
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O código de C\+\+ AMP que você deseja executar no acelerador é especificado como um argumento na chamada ao método [parallel\_for\_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md).  Você pode fornecer uma expressão lambda ou um objeto de função \(functor\) como o argumento.  Além de isso, a expressão lambda ou objeto de função podem chamar a função restrita C\+\+ AMP.  Este tópico usa um algoritmo de adição de matriz para demonstrar lambdas, objetos de função e funções restritas.  O exemplo a seguir mostra o algoritmo sem código de C\+\+ AMP.  São criadas duas matrizes unidimensionais de tamanho igual.  Os elementos inteiros correspondentes são adicionados e armazenados em uma terceira matriz unidimensional.  O C\+\+ AMP não é usado.  
  
```cpp  
  
void CpuMethod() {  
  
    int aCPP[] = {1, 2, 3, 4, 5};  
    int bCPP[] = {6, 7, 8, 9, 10};  
    int sumCPP[5];  
  
    for (int idx = 0; idx < 5; idx++)  
    {  
        sumCPP[idx] = aCPP[idx] + bCPP[idx];  
    }  
  
    for (int idx = 0; idx < 5; idx++)  
    {  
        std::cout << sumCPP[idx] << "\n";  
    }  
}  
  
```  
  
## Expressão lambda  
 Usar uma expressão lambda é a forma mais direta de usar o C\+\+ AMP para reescrever o código.  
  
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
        }  
    );  
  
    for (int i = 0; i < 5; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
 A expressão lambda deve incluir um parâmetro indexação e deve incluir `restrict(amp)`.  No exemplo, o objeto [array\_view](../../parallel/amp/reference/array-view-class.md) `sum` tem classificação 1.  Portanto, o parâmetro para a instrução lambda é um objeto [índice](../../parallel/amp/reference/index-class.md) que possui a posição 1.  Em tempo de execução, a expressão lambda é executada uma vez para cada elemento no objeto [array\_view](../../parallel/amp/reference/array-view-class.md).  Para obter mais informações, consulte [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md).  
  
## Objeto de função  
 É possível incluir o código de aceleradores em um objeto de função.  
  
```cpp  
  
class AdditionFunctionObject  
{  
public:  
    AdditionFunctionObject(const array_view<int, 1>& a,  
        const array_view<int, 1>& b,  
        const array_view<int, 1>& sum  
    )  
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
        AdditionFunctionObject(a, b, sum)  
    );  
  
    for (int i = 0; i < 5; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
 O objeto de função deve incluir um construtor e incluir uma sobrecarga do operador de chamada de função.  O operador de chamada de função deve incluir um parâmetro indexação.  Uma instância do objeto de função é passada como o segundo argumento para o método [parallel\_for\_each](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md).  Nesse exemplo, três objetos [array\_view](../../parallel/amp/reference/array-view-class.md) são passados para o construtor do objeto de função.  O objeto `sum` [array\_view](../../parallel/amp/reference/array-view-class.md) tem classificação 1.  Portanto, o parâmetro para o operador de chamada de função é um objeto [índice](../../parallel/amp/reference/index-class.md) que possui a posição 1.  Em tempo de execução, a função é executada uma vez para cada elemento no objeto [array\_view](../../parallel/amp/reference/array-view-class.md).  Para obter mais informações, consulte [Chamada de função](../Topic/Function%20Call%20\(C++\).md) e [Objetos de função no STL](../../standard-library/function-objects-in-the-stl.md).  
  
## Função restrita C\+\+ AMP  
 Você ainda pode incluir o código de aceleradores criando uma função restrita e chamando a partir de uma expressão lambda ou de um objeto de função.  O exemplo de código a seguir demonstra como chamar uma função estritamente de uma expressão lambda.  
  
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
        }  
    );  
  
    for (int i = 0; i < 5; i++) {  
        std::cout << sum[i] << "\n";  
    }  
}  
  
```  
  
 A função estritamente deve incluir `restrict(amp)` e estar de acordo com as restrições que são descritas em [restrita \(C\+\+ AMP\)](../../cpp/restrict-cpp-amp.md).  
  
## Consulte também  
 [C\+\+ AMP \(C\+\+ Accelerated Massive Parallelism\)](../../parallel/amp/cpp-amp-cpp-accelerated-massive-parallelism.md)   
 [Sintaxe da expressão lambda](../../cpp/lambda-expression-syntax.md)   
 [Chamada de função](../Topic/Function%20Call%20\(C++\).md)   
 [Objetos de função no STL](../../standard-library/function-objects-in-the-stl.md)   
 [restrita \(C\+\+ AMP\)](../../cpp/restrict-cpp-amp.md)