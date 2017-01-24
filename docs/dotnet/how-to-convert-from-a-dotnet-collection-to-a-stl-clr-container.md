---
title: "Como converter de um cole&#231;&#227;o .NET em um cont&#234;iner STL/CLR | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Contêineres STL/CLR [STL/CLR]"
  - "STL/CLR, convertendo de coleções de .NET"
ms.assetid: bb927c48-78e8-4150-bd0b-787c651f4a87
caps.latest.revision: 9
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter de um cole&#231;&#227;o .NET em um cont&#234;iner STL/CLR
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como converter coleções .NET a seus contêineres de equivalente STL\/CLR.  Como exemplo mostrarmos como converter um .NET <xref:System.Collections.Generic.List%601> a um STL\/CLR [vetor](../dotnet/vector-stl-clr.md) e como converter um .NET <xref:System.Collections.Generic.Dictionary%602> a um STL\/CLR [mapa](../dotnet/map-stl-clr.md), mas o procedimento é semelhante para todas as coleções e contêineres.  
  
### Para criar um contêiner de uma coleção  
  
1.  Para converter uma coleção inteira, crie um contêiner de STL\/CLR e passar a coleção para o construtor.  
  
     O primeiro exemplo demonstra esse procedimento.  
  
 \- OU\-  
  
1.  Crie um contêiner genérico de STL\/CLR criando um objeto de [collection\_adapter](../Topic/collection_adapter%20\(STL-CLR\).md) .  Essa classe do modelo usa uma interface da coleção do .NET como um argumento.  Para verificar se as interfaces são suportadas, consulte [collection\_adapter](../Topic/collection_adapter%20\(STL-CLR\).md).  
  
2.  Copiar o conteúdo da coleção de .NET para o contêiner.  Isso pode ser feito usando um STL\/CLR [algoritmo](../Topic/algorithm%20\(STL-CLR\).md), ou para iterar sobre a coleção de .NET e inserindo uma cópia de cada elemento no contêiner de STL\/CLR.  
  
     O segundo exemplo demonstra esse procedimento.  
  
## Exemplo  
 Neste exemplo, criamos <xref:System.Collections.Generic.List%601> genérico e adicionamos\-lhe 5 elementos.  Em seguida, criamos `vector` usando o construtor que usa <xref:System.Collections.Generic.IEnumerable%601> como um argumento.  
  
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
  
  **O conteúdo de cliext::vector são:**  
**2**  
**3**  
**5**  
**7**  
**11**   
## Exemplo  
 Neste exemplo, criamos <xref:System.Collections.Generic.Dictionary%602> genérico e adicionamos\-lhe 5 elementos.  Em seguida, criamos `collection_adapter` para incluir <xref:System.Collections.Generic.Dictionary%602> como um contêiner simples de STL\/CLR.  Finalmente, criamos `map` e copiamos o conteúdo de <xref:System.Collections.Generic.Dictionary%602> a `map` iterando sobre `collection_adapter`.  Durante esse processo, criamos um novo par usando a função de `make_pair` , e inserimos os novos pares diretamente em `map`.  
  
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
  
  **O conteúdo de cliext::map são:**  
**Chave: 0,00 Valores: 0**  
**Chave: Valor 13,00: 13**  
**Chave: Valor 22,00: 22**  
**Chave: Valor 42,00: 42**  
**Chave: Valor 74,00: 74**   
## Consulte também  
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)   
 [adapter](../dotnet/adapter-stl-clr.md)   
 [Como converter de um contêiner STL\/CLR em uma coleção .NET](../dotnet/how-to-convert-from-a-stl-clr-container-to-a-dotnet-collection.md)