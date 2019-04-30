---
title: 'Como: Converter de um contêiner STL/CLR em uma coleção .NET'
ms.date: 11/04/2016
helpviewer_keywords:
- STL/CLR Containers [STL/CLR]
- STL/CLR, converting to .NET collections
ms.assetid: 70b2dfd9-869c-4e0f-9a29-b1ee0cb0d107
ms.openlocfilehash: cf67e362751dd164916cc94cd644d55110d88a5f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62387520"
---
# <a name="how-to-convert-from-a-stlclr-container-to-a-net-collection"></a>Como: Converter de um contêiner STL/CLR em uma coleção .NET

Este tópico mostra como converter contêineres STL/CLR em suas coleções do .NET equivalentes. Por exemplo, vamos mostrar como converter um STL/CLR [vetor](../dotnet/vector-stl-clr.md) para um .NET <xref:System.Collections.Generic.ICollection%601> e como converter um STL/CLR [mapa](../dotnet/map-stl-clr.md) para um .NET <xref:System.Collections.Generic.IDictionary%602>, mas o procedimento é semelhante para todas as coleções e contêineres.

### <a name="to-create-a-collection-from-a-container"></a>Para criar uma coleção de um contêiner

1. Use um dos seguintes métodos:

   - Para converter a parte de um contêiner, chame o [make_collection](../dotnet/make-collection-stl-clr.md) de função e passar o iterador de início e o iterador de fim do contêiner STL/CLR a ser copiado para a coleção do .NET. Essa função de modelo usa um iterador STL/CLR como um argumento de modelo. O primeiro exemplo demonstra esse método.

   - Para converter um contêiner inteiro, converta o contêiner para uma interface de coleção apropriada do .NET ou a coleção de interface. O segundo exemplo demonstra esse método.

## <a name="example"></a>Exemplo

Neste exemplo, criamos um STL/CLR `vector` e adicionar elementos de 5 a ele. Em seguida, criamos uma coleção .NET chamando o `make_collection` função. Por fim, podemos exibir o conteúdo da coleção criada recentemente.

```
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

Neste exemplo, criamos um STL/CLR `map` e adicionar elementos de 5 a ele. Em seguida, criamos um .NET <xref:System.Collections.Generic.IDictionary%602> e atribua a `map` diretamente para ele. Por fim, podemos exibir o conteúdo da coleção criada recentemente.

```
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
[Como: converter de um coleção do .NET em um contêiner do STL/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)<br/>
[range_adapter (STL/CLR)](../dotnet/range-adapter-stl-clr.md)
