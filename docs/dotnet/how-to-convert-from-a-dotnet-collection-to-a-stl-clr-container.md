---
title: Como converter de um coleção .NET em um contêiner STL/CLR
ms.date: 11/04/2016
helpviewer_keywords:
- STL/CLR, converting from .NET collections
- STL/CLR Containers [STL/CLR]
ms.assetid: bb927c48-78e8-4150-bd0b-787c651f4a87
ms.openlocfilehash: 4993571d479924edc71a277887a8bd95fc4fd463
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91506435"
---
# <a name="how-to-convert-from-a-net-collection-to-a-stlclr-container"></a>Como converter de um coleção .NET em um contêiner STL/CLR

Este tópico mostra como converter coleções .NET em seus contêineres STL/CLR equivalentes. Como exemplo, mostramos como converter um .NET <xref:System.Collections.Generic.List%601> em um [vetor](../dotnet/vector-stl-clr.md) STL/CLR e como converter um .NET <xref:System.Collections.Generic.Dictionary%602> em um [mapa](../dotnet/map-stl-clr.md)STL/CLR, mas o procedimento é semelhante para todas as coleções e contêineres.

### <a name="to-create-a-container-from-a-collection"></a>Para criar um contêiner a partir de uma coleção

1. Para converter uma coleção inteira, crie um contêiner STL/CLR e passe a coleção para o construtor.

   O primeiro exemplo demonstra esse procedimento.

-OU-

1. Crie um contêiner STL/CLR genérico criando um objeto [collection_adapter](./adapter-stl-clr.md#collection_adapter) . Essa classe de modelo usa uma interface de coleção .NET como um argumento. Para verificar quais interfaces têm suporte, consulte [collection_adapter (STL/CLR)](./adapter-stl-clr.md#collection_adapter).

1. Copie o conteúdo da coleção .NET para o contêiner. Isso pode ser feito usando um [algoritmo](../dotnet/algorithm-stl-clr.md)STL/CLR ou Iterando na coleção .net e inserindo uma cópia de cada elemento no contêiner STL/CLR.

   O segundo exemplo demonstra esse procedimento.

## <a name="examples"></a>Exemplos

Neste exemplo, criamos um genérico <xref:System.Collections.Generic.List%601> e adicionamos 5 elementos a ele. Em seguida, criamos um `vector` usando o construtor que usa um <xref:System.Collections.Generic.IEnumerable%601> como argumento.

```cpp
// cliext_convert_list_to_vector.cpp
// compile with: /clr

#include <cliext/adapter>
#include <cliext/algorithm>
#include <cliext/vector>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    List<int> ^primeNumbersColl = gcnew List<int>();
    primeNumbersColl->Add(2);
    primeNumbersColl->Add(3);
    primeNumbersColl->Add(5);
    primeNumbersColl->Add(7);
    primeNumbersColl->Add(11);

    cliext::vector<int> ^primeNumbersCont =
        gcnew cliext::vector<int>(primeNumbersColl);

    Console::WriteLine("The contents of the cliext::vector are:");
    cliext::vector<int>::const_iterator it;
    for (it = primeNumbersCont->begin(); it != primeNumbersCont->end(); it++)
    {
        Console::WriteLine(*it);
    }
}
```

```Output
The contents of the cliext::vector are:
2
3
5
7
11
```

Neste exemplo, criamos um genérico <xref:System.Collections.Generic.Dictionary%602> e adicionamos 5 elementos a ele. Em seguida, criamos um `collection_adapter` para encapsular o <xref:System.Collections.Generic.Dictionary%602> como um contêiner STL/CLR simples. Por fim, criamos um `map` e copiamos o conteúdo do <xref:System.Collections.Generic.Dictionary%602> para o `map` Iterando sobre o `collection_adapter` . Durante esse processo, criamos um novo par usando a `make_pair` função e inserimos o novo par diretamente no `map` .

```cpp
// cliext_convert_dictionary_to_map.cpp
// compile with: /clr

#include <cliext/adapter>
#include <cliext/algorithm>
#include <cliext/map>

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    System::Collections::Generic::Dictionary<float, int> ^dict =
        gcnew System::Collections::Generic::Dictionary<float, int>();
    dict->Add(42.0, 42);
    dict->Add(13.0, 13);
    dict->Add(74.0, 74);
    dict->Add(22.0, 22);
    dict->Add(0.0, 0);

    cliext::collection_adapter<System::Collections::Generic::IDictionary<float, int>> dictAdapter(dict);
    cliext::map<float, int> aMap;
    for each (KeyValuePair<float, int> ^kvp in dictAdapter)
    {
        cliext::pair<float, int> aPair = cliext::make_pair(kvp->Key, kvp->Value);
        aMap.insert(aPair);
    }

    Console::WriteLine("The contents of the cliext::map are:");
    cliext::map<float, int>::const_iterator it;
    for (it = aMap.begin(); it != aMap.end(); it++)
    {
        Console::WriteLine("Key: {0:F} Value: {1}", it->first, it->second);
    }
}
```

```Output
The contents of the cliext::map are:
Key: 0.00 Value: 0
Key: 13.00 Value: 13
Key: 22.00 Value: 22
Key: 42.00 Value: 42
Key: 74.00 Value: 74
```

## <a name="see-also"></a>Consulte também

[Referência da biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)<br/>
[adapter (STL/CLR)](../dotnet/adapter-stl-clr.md)<br/>
[Como converter de um contêiner STL/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)
