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
ms.openlocfilehash: a17649402fa6ebe9c98d768badcf36e5700f5b75
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33862716"
---
# <a name="arrays-c-component-extensions"></a>Matrizes (Extensões de Componentes C++)
O `Platform::Array<T>` tipo no C + + CX, ou o `array` palavra-chave em C + + CLI, declara uma matriz de um tipo especificado e o valor inicial.  
  
## <a name="all-platforms"></a>Todas as Plataformas  
 A matriz deve ser declarada usando o modificador handle-to-object (^) depois do colchete (>) na declaração.  
 O número de elementos da matriz não é parte do tipo. Uma variável de matriz pode se referir a matrizes de tamanhos diferentes.  
  
 Ao contrário de C++ padrão, subscrito não é um sinônimo para aritmética de ponteiro e não é comutativa.  
  
 Para obter mais informações sobre matrizes, consulte:  
  
-   [Como usar matrizes no C++/CLI](../dotnet/how-to-use-arrays-in-cpp-cli.md)  
    
-   [Listas de argumentos variáveis (...) (C++/CLI)](../windows/variable-argument-lists-dot-dot-dot-cpp-cli.md)  
  
## <a name="windows-runtime"></a>Tempo de Execução do Windows  
 Matrizes são membros de `Platform` namespace. Matrizes podem ser apenas unidimensionais.  
  
### <a name="syntax"></a>Sintaxe  
  
 O primeiro exemplo da sintaxe usa o `ref new` palavra-chave agregação para alocar uma matriz. O segundo exemplo declara uma matriz de local.  
  
```  
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = 
    ref new[Platform::]Array<initialization-type> [{initialization-list [,...]}]  
  
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier = 
    {initialization-list [,...]}  
```  
  
 *qualificadores* [opcional]  
 Um ou mais desses especificadores de classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [volátil](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estático](../cpp/static-members-cpp.md).  
  
 `array-type`  
 O tipo de variável de matriz. Os tipos válidos são classes de Windows Runtime e tipos fundamentais, classes ref e estruturas, classes de valor e structs e ponteiros nativos (`type*`).  
  
 `rank` [opcional]  
 O número de dimensões da matriz. Deve ser 1.  
  
 `identifier`  
 O nome da variável de matriz.  
  
 `initialization-type`  
 O tipo de valores que inicializar a matriz. Normalmente, `array-type` e `initialization-type` são do mesmo tipo. No entanto, os tipos podem ser diferentes se houver uma conversão de `initialization-type` para `array-type`— por exemplo, se `initialization-type` é derivado de `array-type`.  
  
 `initialization-list` [opcional]  
 Uma lista delimitada por vírgulas de valores de chaves que inicializar os elementos da matriz. Por exemplo, se `rank-size-list` foram `(3)`, que declara uma matriz unidimensional de 3 elementos, `initialization list` poderia ser `{1,2,3}`.  
  
### <a name="remarks"></a>Comentários  
  
 Você pode detectar no tempo de compilação se um tipo é uma matriz contado por referência com `__is_ref_array(type)`. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção do compilador: **/ZW**  
  
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
  
 O primeiro exemplo da sintaxe usa o `gcnew` palavra-chave para alocar uma matriz. O segundo exemplo declara uma matriz de local.  
  
```  
[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier = 
    gcnew [cli::]array<initialization-type[,rank]>(rank-size-list[,...]) [{initialization-list [,...]}]  
  
[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier = 
    {initialization-list [,...]}  
```  
  
 *qualificadores* [opcional]  
 Um ou mais desses especificadores de classe de armazenamento: [mutável](../cpp/mutable-data-members-cpp.md), [volátil](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [estático](../cpp/static-members-cpp.md).  
  
 `array-type`  
 O tipo de variável de matriz. Os tipos válidos são classes de Windows Runtime e tipos fundamentais, classes e estruturas, classes de valor e estruturas ref, ponteiros nativos (`type*`) e tipos nativos do POD (plain dados antigos).  
  
 `rank` [opcional]  
 O número de dimensões da matriz. O padrão é 1. o máximo é 32. Cada dimensão da matriz é uma matriz.  
  
 `identifier`  
 O nome da variável de matriz.  
  
 `initialization-type`  
 O tipo de valores que inicializar a matriz. Normalmente, `array-type` e `initialization-type` são do mesmo tipo. No entanto, os tipos podem ser diferentes se houver uma conversão de `initialization-type` para `array-type`— por exemplo, se `initialization-type` é derivado de `array-type`.  
  
 `rank-size-list`  
 Uma lista delimitada por vírgulas de tamanho de cada dimensão da matriz. Como alternativa, se o `initialization-list` parâmetro for especificado, o compilador pode deduzir o tamanho de cada dimensão e `rank-size-list` pode ser omitido. 
  
 `initialization-list` [opcional]  
 Uma lista delimitada por vírgulas de valores de chaves que inicializar os elementos da matriz. Ou uma lista delimitada por vírgulas de aninhados *lista de inicialização* itens que inicializar os elementos em uma matriz multidimensional.  
  
 Por exemplo, se `rank-size-list` foram `(3)`, que declara uma matriz unidimensional de 3 elementos, `initialization list` poderia ser `{1,2,3}`. Se `rank-size-list` foram `(3,2,4)`, que declara uma matriz tridimensional de 3 elementos na primeira dimensão, 2 elementos na segunda e 4 elementos no terceiro, `initialization-list` poderia ser `{{1,2,3},{0,0},{-5,10,-21,99}}`.)  
  
### <a name="remarks"></a>Comentários  
  
 `array` está no [plataforma, padrão e cli Namespaces](../windows/platform-default-and-cli-namespaces-cpp-component-extensions.md) namespace.  
  
 Como o C++ padrão, os índices de uma matriz são baseadas em zero, e uma matriz é subscrito usando colchetes ([]). Ao contrário de C++ padrão, os índices de uma matriz multidimensional são especificados em uma lista de índices para cada dimensão em vez de um conjunto de operadores de colchete ([]) para cada dimensão. Por exemplo, *identificador*[*index1*, *index2*] em vez de *identificador*[*index1*] [ *index2*].  
  
 Todas as matrizes gerenciadas herdam de `System::Array`. Qualquer método ou propriedade de `System::Array` pode ser aplicado diretamente à variável de matriz.  
  
 Quando você alocar uma matriz cujo tipo de elemento é o ponteiro-para uma classe gerenciada, os elementos são inicializados para 0.  
  
 Quando você alocar uma matriz cujo tipo de elemento é um tipo de valor `V`, o construtor padrão para `V` é aplicada a cada elemento da matriz. Para obter mais informações, consulte [equivalentes do .NET Framework para tipos nativos do C++ (C + + CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md).  
  
 Em tempo de compilação, você pode detectar se um tipo é uma matriz de tempo de execução (CLR) de linguagem comum com `__is_ref_array(type)`. Para obter mais informações, consulte [suporte para características do tipo de compilador](../windows/compiler-support-for-type-traits-cpp-component-extensions.md).  
  
### <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
### <a name="examples"></a>Exemplos  
 O exemplo a seguir cria uma matriz unidimensional que tem 100 elementos e uma matriz tridimensional com 3 elementos na primeira dimensão, 5 elementos na segunda e 6 elementos no terceiro.  
  
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