---
title: Arrays (C++/CLI e C++/CX)
ms.date: 10/12/2018
ms.topic: reference
f1_keywords:
- cli::array
- details::array
- lang::array
helpviewer_keywords:
- array keyword [C++]
- arrays [C++], multidimensional
- multidimensional arrays
- arrays [C++]
ms.assetid: 49445812-d775-4db1-a231-869598dbb955
ms.openlocfilehash: e4173c16e13c08a54b36e42183e6e18b6ed4fdc2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "65516191"
---
# <a name="arrays-ccli-and-ccx"></a>Arrays (C++/CLI e C++/CX)

O tipo `Platform::Array<T>` em C++/CX, ou a palavra-chave **array** em C++/CLI, declara uma matriz de um tipo especificado e o valor inicial.

## <a name="all-platforms"></a>Todas as Plataformas

A matriz deve ser declarada usando o modificador handle-to-object (^) após o colchete angular de fechamento (>) na declaração.
O número de elementos da matriz não faz parte do tipo. Uma variável de matriz pode fazer referência a matrizes de tamanhos diferentes.

Ao contrário do C++ padrão, a subscrição não é um sinônimo para aritmética de ponteiro, e não é cumulativa.

Saiba mais sobre matrizes em:

- [Como: usar matrizes no C++/CLI](../dotnet/how-to-use-arrays-in-cpp-cli.md)

- [Listas de argumentos variáveis (...) (C++/CLI)](variable-argument-lists-dot-dot-dot-cpp-cli.md)

## <a name="windows-runtime"></a>Tempo de Execução do Windows

As matrizes são membros do namespace `Platform`. As matrizes só podem ser unidimensionais.

### <a name="syntax"></a>Sintaxe

O primeiro exemplo da sintaxe usa a palavra-chave agregada **ref new** para alocar uma matriz. O segundo exemplo declara uma matriz local.

```cpp
[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier =
    ref new[Platform::]Array<initialization-type> [{initialization-list [,...]}]

[qualifiers] [Platform::]Array<[qualifiers] array-type [,rank]>^ identifier =
    {initialization-list [,...]}
```

*qualificadores*<br/>
(Opcional) Um ou mais destes especificadores de classe de armazenamento: [mutable](../cpp/mutable-data-members-cpp.md), [volatile](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [static](../cpp/static-members-cpp.md).

*array-type*<br/>
O tipo de variável da matriz. Os tipos válidos são classes do Windows Runtime e tipos fundamentais, classes e structs ref, classes e structs value e ponteiros nativos (`type*`).

*rank*<br/>
(Opcional) O número de dimensões da matriz. Deve ser 1.

*identifier*<br/>
O nome da variável da matriz.

*initialization-type*<br/>
O tipo dos valores que inicializam a matriz. Normalmente, *array-type* e *initialization-type* são do mesmo tipo. No entanto, os tipos podem ser diferentes se houver uma conversão de *initialization-type* para *array-type*, por exemplo, se *initialization-type* deriva *array-type*.

*initialization-list*<br/>
(Opcional) Uma lista delimitada por vírgulas de valores entre colchetes que inicializam os elementos da matriz. Por exemplo, se *rank-size-list* fosse `(3)`, o que declara uma matriz unidimensional de três elementos, *initialization list* poderia ser `{1,2,3}`.

### <a name="remarks"></a>Comentários

Você pode detectar no tempo de compilação se um tipo é uma matriz de contagem de referência com `__is_ref_array(type)`. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/ZW`

### <a name="examples"></a>Exemplos

O exemplo a seguir cria uma matriz unidimensional com 100 elementos.

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

O primeiro exemplo da sintaxe usa a palavra-chave **gcnew** para alocar uma matriz. O segundo exemplo declara uma matriz local.

```cpp
[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier =
    gcnew [cli::]array<initialization-type[,rank]>(rank-size-list[,...]) [{initialization-list [,...]}]

[qualifiers] [cli::]array<[qualifiers] array-type [,rank]>^ identifier =
    {initialization-list [,...]}
```

*qualificadores*<br/>
(Opcional) Um ou mais destes especificadores de classe de armazenamento: [mutable](../cpp/mutable-data-members-cpp.md), [volatile](../cpp/volatile-cpp.md), [const](../cpp/const-cpp.md), [extern](../cpp/using-extern-to-specify-linkage.md), [static](../cpp/static-members-cpp.md).

*array-type*<br/>
O tipo de variável da matriz. Os tipos válidos são classes do Windows Runtime e tipos fundamentais, classes ref e structs, classes de valor e structs, ponteiros nativos (`type*`) e tipos POD (dados antigos simples) nativos.

*rank*<br/>
(Opcional) O número de dimensões da matriz. O padrão é 1; o máximo é 32. Cada dimensão da matriz é, por si só, uma matriz.

*identifier*<br/>
O nome da variável da matriz.

*initialization-type*<br/>
O tipo dos valores que inicializam a matriz. Normalmente, *array-type* e *initialization-type* são do mesmo tipo. No entanto, os tipos podem ser diferentes se houver uma conversão de *initialization-type* para *array-type*, por exemplo, se *initialization-type* deriva *array-type*.

*rank-size-list*<br/>
Uma lista delimitada por vírgula do tamanho de cada dimensão na matriz. Como alternativa, se o parâmetro *initialization-list* for especificado, o compilador poderá deduzir o tamanho de cada dimensão e *rank-size-list* poderá ser omitido.

*initialization-list*<br/>
(Opcional) Uma lista delimitada por vírgulas de valores entre colchetes que inicializam os elementos da matriz. Ou uma lista delimitada por vírgulas de itens *initialization-list* aninhados que inicializam os elementos em uma matriz multidimensional.

Por exemplo, se *rank-size-list* fosse `(3)`, o que declara uma matriz unidimensional de três elementos, *initialization list* poderia ser `{1,2,3}`. Se *rank-size-list* fosse `(3,2,4)`, o que declara uma matriz tridimensional de três elementos na primeira dimensão, dois elementos na segunda e quatro elementos na terceira, *initialization-list* poderia ser `{{1,2,3},{0,0},{-5,10,-21,99}}`).

### <a name="remarks"></a>Comentários

**array** está no namespace [Plataform, default e cli](platform-default-and-cli-namespaces-cpp-component-extensions.md).

Como o C++ padrão, os índices de uma matriz têm base em zero e uma matriz é subscrita usando colchetes ([]). Ao contrário do C++ padrão, os índices de uma matriz multidimensional são especificados em uma lista de índices para cada dimensão, em vez de um conjunto de operadores de colchete ([]) para cada dimensão. Por exemplo, *identifier*[*index1*, *index2*], em vez de *identifier*[*index1*] [ *index2*].

Todas as matrizes gerenciadas herdam de `System::Array`. Qualquer método ou propriedade de `System::Array` pode ser aplicado diretamente na variável da matriz.

Quando você aloca uma matriz, cujo tipo de elemento é o ponteiro, para uma classe gerenciada, os elementos são inicializados para 0.

Quando você aloca uma matriz cujo tipo de elemento é um tipo de valor `V`, o construtor padrão para `V` é aplicado a cada elemento da matriz. Saiba mais em [Equivalentes do .NET Framework aos tipos nativos do C++ (C++/CLI)](../dotnet/dotnet-framework-equivalents-to-cpp-native-types-cpp-cli.md).

Em tempo de compilação, você pode detectar se um tipo é uma matriz CLR (common language runtime) com `__is_ref_array(type)`. Saiba mais em [Suporte para compilador de traços de tipo](compiler-support-for-type-traits-cpp-component-extensions.md).

### <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

### <a name="examples"></a>Exemplos

O exemplo a seguir cria uma matriz unidimensional que tem 100 elementos e uma matriz tridimensional que tem três elementos na primeira dimensão, cinco elementos na segunda e seis elementos na terceira.

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

[Extensões de componentes para .NET e UWP](component-extensions-for-runtime-platforms.md)