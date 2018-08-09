---
title: Matrizes (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- cli::array
- details::array
- lang::array
dev_langs:
- C++
helpviewer_keywords:
- array keyword [C++]
- declaring arrays, about declaring arrays
- arrays [C++], multidimensional
- multidimensional arrays
- arrays [C++]
ms.assetid: 49445812-d775-4db1-a231-869598dbb955
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 58ba6d598223e63f5b28adcaedad653ffc6f386a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39645562"
---
# <a name="arrays-c-component-extensions"></a>Matrizes (Extensões de Componentes C++)
O `Platform::Array<T>` tipo no C + + c++ /CLI CX, ou o **matriz** palavra-chave no C + + c++ CLI, declara uma matriz de um tipo especificado e o valor inicial.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 A matriz deve ser declarada usando o modificador handle-to-object (^) após o colchete angular de fechamento (>) na declaração.  
 O número de elementos da matriz não é parte do tipo. Uma variável de matriz pode se referir a matrizes de tamanhos diferentes.  
  
 Ao contrário do C++ padrão, o subscrito não é um sinônimo de aritmética de ponteiro e não é comutativo.  
  
 Para obter mais informações sobre matrizes, consulte:  
  
-   [Como usar matrizes no C++/CLI](../dotnet/how-to-use-arrays-in-cpp-cli.md)  
    
-   [Listas de argumentos variáveis (...) (C++/CLI)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Matrizes são membros do `Platform` namespace. Matrizes podem ser apenas unidimensionais.  
  
### <a name="syntax"></a>Sintaxe  
  
 O primeiro exemplo da sintaxe usa o **ref novo** agregação palavra-chave para alocar uma matriz. O segundo exemplo declara uma matriz local.  
  
```cpp  
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = 
    ref new[Platform::]Array<initialization-type> [{initialization-list [,...]}]  
  
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = 
    {initialization-list [,...]}  
```  
  
 *qualificadores* [opcional]  
 Um ou mais destes especificadores de classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [volátil](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estático](../cpp/static-members-cpp.md).  
  
 *tipo de matriz*  
 O tipo de variável de matriz. Os tipos válidos são classes de tempo de execução do Windows e tipos fundamentais, classes de referência e estruturas, classes de valor e structs e ponteiros nativos (`type*`).  
  
 *classificação* [opcional]  
 O número de dimensões da matriz. Deve ser 1.  
  
 *identifier*  
 O nome da variável da matriz.  
  
 *tipo de inicialização*  
 O tipo dos valores que inicializar a matriz. Normalmente, *tipo de matriz* e *tipo de inicialização* são do mesmo tipo. No entanto, os tipos podem ser diferentes se há uma conversão de *tipo de inicialização* para *tipo de matriz*— por exemplo, se *tipo de inicialização* deriva *tipo de matriz*.  
  
 *lista de inicialização* [opcional]  
 Uma lista delimitada por vírgulas de valores entre colchetes que inicializar os elementos da matriz. Por exemplo, se *lista de tamanhos de classificação* foram `(3)`, que declara uma matriz unidimensional de elementos de 3 *lista de inicialização* poderia ser `{1,2,3}`.  
  
### <a name="remarks"></a>Comentários  
  
 Você pode detectar no tempo de compilação se um tipo é uma matriz de contagem de referência com `__is_ref_array(type)`. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/ZW`  
  
### <a name="examples"></a>Exemplos  
 O exemplo a seguir cria uma matriz unidimensional que tem 100 elementos.  
  
```cpp  
// cwr_array.cpp  
// compile with: /ZW  
using namespace Platform;  
ref class MyClass {};  
int main() {  
   // one-dimensional array  
   Array<MyClass^>^ My1DArray = ref new Array<MyClass^>(100);  
   My1DArray[99] = ref new MyClass();  
}  
```  
  
## <a name="common-language-runtime"></a>Common Language Runtime 
  
### <a name="syntax"></a>Sintaxe  
  
 O primeiro exemplo da sintaxe usa o **gcnew** palavra-chave para alocar uma matriz. O segundo exemplo declara uma matriz local.  
  
```cpp  
[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier = 
    gcnew [cli::]array<initialization-type[,rank]>(rank-size-list[,...]) [{initialization-list [,...]}]  
  
[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier = 
    {initialization-list [,...]}  
```  
  
 *qualificadores* [opcional]  
 Um ou mais destes especificadores de classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [volátil](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estático](../cpp/static-members-cpp.md).  
  
 *tipo de matriz*  
 O tipo de variável de matriz. Os tipos válidos são classes de tempo de execução do Windows e tipos fundamentais, classes e structs, classes de valor e estruturas ref, ponteiros nativos (`type*`) e tipos nativos do POD (dados antigos simples).  
  
 *classificação* [opcional]  
 O número de dimensões da matriz. O padrão é 1; o máximo é 32. Cada dimensão da matriz em si é uma matriz.  
  
 *identifier*  
 O nome da variável da matriz.  
  
 *tipo de inicialização*  
 O tipo dos valores que inicializar a matriz. Normalmente, *tipo de matriz* e *tipo de inicialização* são do mesmo tipo. No entanto, os tipos podem ser diferentes se há uma conversão de *tipo de inicialização* para *tipo de matriz*— por exemplo, se *tipo de inicialização* deriva *tipo de matriz*.  
  
 *lista de tamanho de classificação*  
 Uma lista delimitada por vírgula do tamanho de cada dimensão da matriz. Como alternativa, se o *lista de inicialização* parâmetro for especificado, o compilador pode deduzir o tamanho de cada dimensão e *lista de tamanhos de classificação* pode ser omitido. 
  
 *lista de inicialização* [opcional]  
 Uma lista delimitada por vírgulas de valores entre colchetes que inicializar os elementos da matriz. Ou uma lista delimitada por vírgulas de aninhados *lista de inicialização* itens que inicializar os elementos em uma matriz multidimensional.  
  
 Por exemplo, se *lista de tamanhos de classificação* foram `(3)`, que declara uma matriz unidimensional de elementos de 3 *lista de inicialização* poderia ser `{1,2,3}`. Se *lista de tamanhos de classificação* foram `(3,2,4)`, que declara uma matriz tridimensional de 3 elementos na primeira dimensão, 2 elementos no segundo e 4 elementos, o terceiro, *lista de inicialização* poderia ser `{{1,2,3},{0,0},{-5,10,-21,99}}`.)  
  
### <a name="remarks"></a>Comentários  
  
 **matriz** está no [plataforma, padrão e cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) namespace.  
  
 Como o C++ padrão, os índices de uma matriz são baseados em zero e uma matriz é Subscrita usando colchetes ([]). Ao contrário do C++ padrão, os índices de uma matriz multidimensional são especificados em uma lista de índices para cada dimensão, em vez de um conjunto de operadores de colchete ([]) para cada dimensão. Por exemplo, *identificador*[*index1*, *index2*], em vez de *identificador*[*index1*] [ *index2*].  
  
 Todas as matrizes gerenciadas herdam `System::Array`. Qualquer método ou propriedade de `System::Array` podem ser aplicadas diretamente a variável de matriz.  
  
 Quando você aloca uma matriz cujo tipo de elemento é o ponteiro-para uma classe gerenciada, os elementos são inicializados para 0.  
  
 Quando você aloca uma matriz cujo tipo de elemento é um tipo de valor `V`, o construtor padrão para `V` é aplicada a cada elemento da matriz. Para obter mais informações, consulte [equivalentes do .NET Framework para tipos nativos do C++ (C + + / CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md).  
  
 Em tempo de compilação, você pode detectar se um tipo é uma matriz de runtime (CLR) de linguagem comum com `__is_ref_array(type)`. Para obter mais informações, consulte [suporte do compilador para características de tipo](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: `/clr`  
  
### <a name="examples"></a>Exemplos  
 O exemplo a seguir cria uma matriz unidimensional que tem 100 elementos e uma matriz tridimensional que tem 6 elementos na terceira, 5 elementos no segundo e 3 elementos na primeira dimensão.  
  
```cpp  
// clr_array.cpp  
// compile with: /clr  
ref class MyClass {};  
int main() {  
   // one-dimensional array  
   array<MyClass ^> ^ My1DArray = gcnew array<MyClass ^>(100);  
   My1DArray[99] = gcnew MyClass();  
  
   // three-dimensional array  
   array<MyClass ^, 3> ^ My3DArray = gcnew array<MyClass ^, 3>(3, 5, 6);  
   My3DArray[0,0,0] = gcnew MyClass();  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)