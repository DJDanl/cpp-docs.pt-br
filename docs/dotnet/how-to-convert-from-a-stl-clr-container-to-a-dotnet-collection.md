---
title: Como converter de um contêiner STL/CLR em uma coleção .NET
ms.date: 11/04/2016
helpviewer_keywords:
- STL/CLR Containers [STL/CLR]
- STL/CLR, converting to .NET collections
ms.assetid: 70b2dfd9-869c-4e0f-9a29-b1ee0cb0d107
ms.openlocfilehash: f7539b10ca6c503aede61d19de3d14fb9dcee8be
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988519"
---
# <a name="how-to-convert-from-a-stlclr-container-to-a-net-collection"></a>Como converter de um contêiner STL/CLR em uma coleção .NET

Este tópico mostra como converter contêineres STL/CLR em suas coleções .NET equivalentes. Como exemplo, mostramos como converter um [vetor](../dotnet/vector-stl-clr.md) STL/CLR em um <xref:System.Collections.Generic.ICollection%601> .net e como converter um [mapa](../dotnet/map-stl-clr.md) STL/CLR em um <xref:System.Collections.Generic.IDictionary%602>.net, mas o procedimento é semelhante para todas as coleções e contêineres.

### <a name="to-create-a-collection-from-a-container"></a>Para criar uma coleção a partir de um contêiner

1. Use um dos métodos a seguir:

   - Para converter parte de um contêiner, chame a função [make_collection](../dotnet/make-collection-stl-clr.md) e passe o iterador Begin e o iterador end do contêiner STL/CLR a ser copiado para a coleção .net. Essa função de modelo usa um iterador STL/CLR como um argumento de modelo. O primeiro exemplo demonstra esse método.

   - Para converter um contêiner inteiro, converta o contêiner em uma interface de coleção .NET ou coleção de interface apropriada. O segundo exemplo demonstra esse método.

## <a name="example"></a>Exemplo

Neste exemplo, criamos um `vector` STL/CLR e adicionamos cinco elementos a ele. Em seguida, criamos uma coleção .NET chamando a função `make_collection`. Por fim, exibimos o conteúdo da coleção recém-criada.

```cpp
// cliext_convert_vector_to_icollection.cpp
// compile with: /clr

#include <cliext/adapter>
#include <cliext/vector>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    cliext::vector<int> primeNumbersCont;
    primeNumbersCont.push_back(2);
    primeNumbersCont.push_back(3);
    primeNumbersCont.push_back(5);
    primeNumbersCont.push_back(7);
    primeNumbersCont.push_back(11);

    System::Collections::Generic::ICollection<int> ^iColl =
        make_collection<cliext::vector<int>::iterator>(
            primeNumbersCont.begin() + 1,
            primeNumbersCont.end() - 1);

    Console::WriteLine("The contents of the System::Collections::Generic::ICollection are:");
    for each (int i in iColl)
    {
        Console::WriteLine(i);
    }
}
```

```Output
The contents of the System::Collections::Generic::ICollection are:
3
5
7
```

## <a name="example"></a>Exemplo

Neste exemplo, criamos um `map` STL/CLR e adicionamos cinco elementos a ele. Em seguida, criamos um <xref:System.Collections.Generic.IDictionary%602> .NET e atribuímos o `map` diretamente a ele. Por fim, exibimos o conteúdo da coleção recém-criada.

```cpp
// cliext_convert_map_to_idictionary.cpp
// compile with: /clr

#include <cliext/adapter>
#include <cliext/map>

using namespace cliext;
using namespace System;
using namespace System::Collections::Generic;

int main(array<System::String ^> ^args)
{
    cliext::map<float, int> ^aMap = gcnew cliext::map<float, int>;
    aMap->insert(cliext::make_pair<float, int>(42.0, 42));
    aMap->insert(cliext::make_pair<float, int>(13.0, 13));
    aMap->insert(cliext::make_pair<float, int>(74.0, 74));
    aMap->insert(cliext::make_pair<float, int>(22.0, 22));
    aMap->insert(cliext::make_pair<float, int>(0.0, 0));

    System::Collections::Generic::IDictionary<float, int> ^iDict = aMap;

    Console::WriteLine("The contents of the IDictionary are:");
    for each (KeyValuePair<float, int> ^kvp in iDict)
    {
        Console::WriteLine("Key: {0:F} Value: {1}", kvp->Key, kvp->Value);
    }
}
```

```Output
The contents of the IDictionary are:
Key: 0.00 Value: 0
Key: 13.00 Value: 13
Key: 22.00 Value: 22
Key: 42.00 Value: 42
Key: 74.00 Value: 74
```

## <a name="see-also"></a>Consulte também

[Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)<br/>
[Como converter de um coleção .NET em um contêiner STL/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)<br/>
[range_adapter (STL/CLR)](../dotnet/range-adapter-stl-clr.md)
