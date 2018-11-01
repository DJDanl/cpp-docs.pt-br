---
title: Como expor um contêiner STL/CLR a partir de um assembly
ms.date: 11/04/2016
helpviewer_keywords:
- STL/CLR Containers [STL/CLR]
- STL/CLR, cross-assembly issues
ms.assetid: 87efb41b-3db3-4498-a2e7-f3ef8a99f04d
ms.openlocfilehash: ba881210f7ee48acd0e92dce3432cae92f3072ee
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590080"
---
# <a name="how-to-expose-an-stlclr-container-from-an-assembly"></a>Como expor um contêiner STL/CLR a partir de um assembly

Contêineres STL/CLR, como `list` e `map` são implementados como classes de referência de modelo. Porque os modelos de C++ são instanciados em tempo de compilação, duas classes de modelo que tem exatamente a mesma assinatura mas em diferentes assemblies são realmente diferentes tipos. Isso significa que as classes de modelo não podem ser usadas em limites de assembly.

Para possibilitar o compartilhamento de entre os assemblies, contêineres STL/CLR implementam a interface genérica <xref:System.Collections.Generic.ICollection%601>. Ao usar essa interface genérica, todas as linguagens que dão suporte a genéricos, incluindo C++, c# e Visual Basic, podem acessar contêineres STL/CLR.

Este tópico mostra como exibir os elementos de vários contêineres STL/CLR escritos em um assembly C++ chamado `StlClrClassLibrary`. Mostramos dois assemblies acessem `StlClrClassLibrary`. O primeiro conjunto é escrito em C++ e o segundo em c#.

Se ambos os assemblies são escritos em C++, você pode acessar a interface genérica de um contêiner usando seu `generic_container` typedef. Por exemplo, se você tiver um contêiner do tipo `cliext::vector<int>`, em seguida, é sua interface genérica: `cliext::vector<int>::generic_container`. Da mesma forma, você pode obter um iterador na interface genérica, usando o `generic_iterator` typedef, como em: `cliext::vector<int>::generic_iterator`.

Uma vez que essas definições de tipo são declaradas nos arquivos de cabeçalho do C++, assemblies escritos em outras linguagens não é possível usá-los. Portanto, para acessar a interface genérica para `cliext::vector<int>` em c# ou qualquer outra linguagem .NET, use `System.Collections.Generic.ICollection<int>`. Para iterar sobre essa coleção, use um `foreach` loop.

A tabela a seguir lista a interface genérica que implementa cada contêiner STL/CLR:

|Contêiner STL/CLR|Interface genérica|
|------------------------|-----------------------|
|`deque<T>`|`ICollection<T>`|
|`hash_map<K, V>`|`IDictionary<K, V>`|
|`hash_multimap<K, V>`|`IDictionary<K, V>`|
|`hash_multiset<T>`|`ICollection<T>`|
|`hash_set<T>`|`ICollection<T>`|
|`list<T>`|`ICollection<T>`|
|`map<K, V>`|`IDictionary<K, V>`|
|`multimap<K, V>`|`IDictionary<K, V>`|
|`multiset<T>`|`ICollection<T>`|
|`set<T>`|`ICollection<T>`|
|`vector<T>`|`ICollection<T>`|

> [!NOTE]
> Porque o `queue`, `priority_queue`, e `stack` contêineres não dão suporte a iteradores, eles não implementam interfaces genéricas e não podem ser acessado entre os assemblies.

## <a name="example-1"></a>Exemplo 1

### <a name="description"></a>Descrição

Neste exemplo, podemos declarar uma classe C++ que contém dados de membro privados STL/CLR. Em seguida, podemos declarar métodos públicos para conceder acesso a coleções particulares da classe. Fazemos-la de duas maneiras diferentes, uma para clientes do C++ e outra para outros clientes .NET.

### <a name="code"></a>Código

```cpp
// StlClrClassLibrary.h
#pragma once

#include <cliext/deque>
#include <cliext/list>
#include <cliext/map>
#include <cliext/set>
#include <cliext/stack>
#include <cliext/vector>

using namespace System;
using namespace System::Collections::Generic;
using namespace cliext;

namespace StlClrClassLibrary {

    public ref class StlClrClass
    {
    public:
        StlClrClass();

        // These methods can be called by a C++ class
        // in another assembly to get access to the
        // private STL/CLR types defined below.
        deque<wchar_t>::generic_container ^GetDequeCpp();
        list<float>::generic_container ^GetListCpp();
        map<int, String ^>::generic_container ^GetMapCpp();
        set<double>::generic_container ^GetSetCpp();
        vector<int>::generic_container ^GetVectorCpp();

        // These methods can be called by a non-C++ class
        // in another assembly to get access to the
        // private STL/CLR types defined below.
        ICollection<wchar_t> ^GetDequeCs();
        ICollection<float> ^GetListCs();
        IDictionary<int, String ^> ^GetMapCs();
        ICollection<double> ^GetSetCs();
        ICollection<int> ^GetVectorCs();

    private:
        deque<wchar_t> ^aDeque;
        list<float> ^aList;
        map<int, String ^> ^aMap;
        set<double> ^aSet;
        vector<int> ^aVector;
    };
}
```

## <a name="example-2"></a>Exemplo 2

### <a name="description"></a>Descrição

Neste exemplo, podemos implementar a classe declarada no exemplo 1. Para os clientes usarem essa biblioteca de classes, podemos usar a ferramenta de manifesto **mt.exe** para inserir o arquivo de manifesto na DLL. Para obter detalhes, consulte os comentários do código.

Para obter mais informações sobre a ferramenta de manifesto e assemblies lado a lado, consulte [criando aplicativos isolados do C/C++ e Assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md).

### <a name="code"></a>Código

```cpp
// StlClrClassLibrary.cpp
// compile with: /clr /LD /link /manifest
// post-build command: (attrib -r StlClrClassLibrary.dll & mt /manifest StlClrClassLibrary.dll.manifest /outputresource:StlClrClassLibrary.dll;#2 & attrib +r StlClrClassLibrary.dll)

#include "StlClrClassLibrary.h"

namespace StlClrClassLibrary
{
    StlClrClass::StlClrClass()
    {
        aDeque = gcnew deque<wchar_t>();
        aDeque->push_back(L'a');
        aDeque->push_back(L'b');

        aList = gcnew list<float>();
        aList->push_back(3.14159f);
        aList->push_back(2.71828f);

        aMap = gcnew map<int, String ^>();
        aMap[0] = "Hello";
        aMap[1] = "World";

        aSet = gcnew set<double>();
        aSet->insert(3.14159);
        aSet->insert(2.71828);

        aVector = gcnew vector<int>();
        aVector->push_back(10);
        aVector->push_back(20);
    }

    deque<wchar_t>::generic_container ^StlClrClass::GetDequeCpp()
    {
        return aDeque;
    }

    list<float>::generic_container ^StlClrClass::GetListCpp()
    {
        return aList;
    }

    map<int, String ^>::generic_container ^StlClrClass::GetMapCpp()
    {
        return aMap;
    }

    set<double>::generic_container ^StlClrClass::GetSetCpp()
    {
        return aSet;
    }

    vector<int>::generic_container ^StlClrClass::GetVectorCpp()
    {
        return aVector;
    }

    ICollection<wchar_t> ^StlClrClass::GetDequeCs()
    {
        return aDeque;
    }

    ICollection<float> ^StlClrClass::GetListCs()
    {
        return aList;
    }

    IDictionary<int, String ^> ^StlClrClass::GetMapCs()
    {
        return aMap;
    }

    ICollection<double> ^StlClrClass::GetSetCs()
    {
        return aSet;
    }

    ICollection<int> ^StlClrClass::GetVectorCs()
    {
        return aVector;
    }
}
```

## <a name="example-3"></a>Exemplo 3:

### <a name="description"></a>Descrição

Neste exemplo, podemos criar um cliente de C++ que usa a biblioteca de classes criada nos exemplos 1 e 2. Esse cliente usa o `generic_container` typedefs dos contêineres STL/CLR para iterar sobre os contêineres e exibir seu conteúdo.

### <a name="code"></a>Código

```cpp
// CppConsoleApp.cpp
// compile with: /clr /FUStlClrClassLibrary.dll

#include <cliext/deque>
#include <cliext/list>
#include <cliext/map>
#include <cliext/set>
#include <cliext/vector>

using namespace System;
using namespace StlClrClassLibrary;
using namespace cliext;

int main(array<System::String ^> ^args)
{
    StlClrClass theClass;

    Console::WriteLine("cliext::deque contents:");
    deque<wchar_t>::generic_container ^aDeque = theClass.GetDequeCpp();
    for each (wchar_t wc in aDeque)
    {
        Console::WriteLine(wc);
    }
    Console::WriteLine();

    Console::WriteLine("cliext::list contents:");
    list<float>::generic_container ^aList = theClass.GetListCpp();
    for each (float f in aList)
    {
        Console::WriteLine(f);
    }
    Console::WriteLine();

    Console::WriteLine("cliext::map contents:");
    map<int, String ^>::generic_container ^aMap = theClass.GetMapCpp();
    for each (map<int, String ^>::value_type rp in aMap)
    {
        Console::WriteLine("{0} {1}", rp->first, rp->second);
    }
    Console::WriteLine();

    Console::WriteLine("cliext::set contents:");
    set<double>::generic_container ^aSet = theClass.GetSetCpp();
    for each (double d in aSet)
    {
        Console::WriteLine(d);
    }
    Console::WriteLine();

    Console::WriteLine("cliext::vector contents:");
    vector<int>::generic_container ^aVector = theClass.GetVectorCpp();
    for each (int i in aVector)
    {
        Console::WriteLine(i);
    }
    Console::WriteLine();

    return 0;
}
```

### <a name="output"></a>Saída

```Output
cliext::deque contents:
a
b

cliext::list contents:
3.14159
2.71828

cliext::map contents:
0 Hello
1 World

cliext::set contents:
2.71828
3.14159

cliext::vector contents:
10
20
```

## <a name="example-4"></a>Exemplo 4

### <a name="description"></a>Descrição

Neste exemplo, podemos criar um cliente c# que usa a biblioteca de classes criada nos exemplos 1 e 2. Esse cliente usa o <xref:System.Collections.Generic.ICollection%601> métodos dos contêineres STL/CLR para iterar sobre os contêineres e exibir seu conteúdo.

### <a name="code"></a>Código

```csharp
// CsConsoleApp.cs
// compile with: /r:Microsoft.VisualC.STLCLR.dll /r:StlClrClassLibrary.dll /r:System.dll

using System;
using System.Collections.Generic;
using StlClrClassLibrary;
using cliext;

namespace CsConsoleApp
{
    class Program
    {
        static int Main(string[] args)
        {
            StlClrClass theClass = new StlClrClass();

            Console.WriteLine("cliext::deque contents:");
            ICollection<char> iCollChar = theClass.GetDequeCs();
            foreach (char c in iCollChar)
            {
                Console.WriteLine(c);
            }
            Console.WriteLine();

            Console.WriteLine("cliext::list contents:");
            ICollection<float> iCollFloat = theClass.GetListCs();
            foreach (float f in iCollFloat)
            {
                Console.WriteLine(f);
            }
            Console.WriteLine();

            Console.WriteLine("cliext::map contents:");
            IDictionary<int, string> iDict = theClass.GetMapCs();
            foreach (KeyValuePair<int, string> kvp in iDict)
            {
                Console.WriteLine("{0} {1}", kvp.Key, kvp.Value);
            }
            Console.WriteLine();

            Console.WriteLine("cliext::set contents:");
            ICollection<double> iCollDouble = theClass.GetSetCs();
            foreach (double d in iCollDouble)
            {
                Console.WriteLine(d);
            }
            Console.WriteLine();

            Console.WriteLine("cliext::vector contents:");
            ICollection<int> iCollInt = theClass.GetVectorCs();
            foreach (int i in iCollInt)
            {
                Console.WriteLine(i);
            }
            Console.WriteLine();

            return 0;
        }
    }
}
```

### <a name="output"></a>Saída

```Output
cliext::deque contents:
a
b

cliext::list contents:
3.14159
2.71828

cliext::map contents:
0 Hello
1 World

cliext::set contents:
2.71828
3.14159

cliext::vector contents:
10
20
```

## <a name="see-also"></a>Consulte também

[Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)