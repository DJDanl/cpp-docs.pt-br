---
title: "Como: converter de uma coleção .NET em um contêiner STL/CLR | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- STL/CLR, converting from .NET collections
- STL/CLR Containers [STL/CLR]
ms.assetid: bb927c48-78e8-4150-bd0b-787c651f4a87
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 6366dd10e60d8f2ea60811f74ba2b2e10457dd84
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-convert-from-a-net-collection-to-a-stlclr-container"></a>Como converter de um coleção .NET em um contêiner STL/CLR
Este tópico mostra como converter as coleções do .NET em seus contêineres STL/CLR equivalentes. Como um exemplo mostram como converter um .NET <xref:System.Collections.Generic.List%601> para um STL/CLR [vetor](../dotnet/vector-stl-clr.md) e como converter um .NET <xref:System.Collections.Generic.Dictionary%602> para um STL/CLR [mapa](../dotnet/map-stl-clr.md), mas o procedimento é semelhante para todos os contêineres e coleções .  
  
### <a name="to-create-a-container-from-a-collection"></a>Para criar um contêiner de uma coleção  
  
1.  Para converter uma coleção inteira, crie um contêiner STL/CLR e passa a coleção para o construtor.  
  
     O primeiro exemplo demonstra esse procedimento.  
  
 -OU-  
  
1.  Criar um contêiner STL/CLR genérico, criando um [collection_adapter](../dotnet/collection-adapter-stl-clr.md) objeto. Essa classe de modelo tem uma interface de coleção do .NET como um argumento. Para verificar quais interfaces são suportados, consulte [collection_adapter (STL/CLR)](../dotnet/collection-adapter-stl-clr.md).  
  
2.  Copie o conteúdo da coleção .NET para o contêiner. Isso pode ser feito usando um STL/CLR [algoritmo](../dotnet/algorithm-stl-clr.md), ou por iteração pela coleção .NET e inserindo uma cópia de cada elemento do contêiner STL/CLR.  
  
     O segundo exemplo demonstra esse procedimento.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, podemos criar um genérico <xref:System.Collections.Generic.List%601> e adicione 5 a ele. Em seguida, criamos um `vector` usando o construtor que recebe um <xref:System.Collections.Generic.IEnumerable%601> como um argumento.  
  
```  
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
  
## <a name="example"></a>Exemplo  
 Neste exemplo, podemos criar um genérico <xref:System.Collections.Generic.Dictionary%602> e adicione 5 a ele. Em seguida, criamos um `collection_adapter` para encapsular o <xref:System.Collections.Generic.Dictionary%602> como um contêiner STL/CLR simple. Finalmente, criamos um `map` e copie o conteúdo a <xref:System.Collections.Generic.Dictionary%602> para o `map` pela iteração no `collection_adapter`. Durante esse processo, criamos um novo par usando o `make_pair` de função e inserir o novo par diretamente para o `map`.  
  
```  
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
 [Referência de biblioteca STL/CLR](../dotnet/stl-clr-library-reference.md)   
 [adaptador (STL/CLR)](../dotnet/adapter-stl-clr.md)   
 [Como converter de um contêiner STL/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)