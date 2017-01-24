---
title: "Como converter de um cont&#234;iner STL/CLR em uma cole&#231;&#227;o .NET | Microsoft Docs"
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
  - "STL/CLR, convertendo em coleções de .NET"
ms.assetid: 70b2dfd9-869c-4e0f-9a29-b1ee0cb0d107
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter de um cont&#234;iner STL/CLR em uma cole&#231;&#227;o .NET
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico mostra como converter contêiner de STL\/CLR às suas coleções equivalente do .NET.  Como exemplo, mostrarmos como converter um STL\/CLR [vetor](../dotnet/vector-stl-clr.md) a um .NET <xref:System.Collections.Generic.ICollection%601> e como converter um STL\/CLR [mapa](../dotnet/map-stl-clr.md) a um .NET <xref:System.Collections.Generic.IDictionary%602>, mas o procedimento é semelhante para todas as coleções e contêineres.  
  
### Para criar uma coleção de um contêiner  
  
1.  Use um dos seguintes métodos:  
  
    -   Para converter a parte de um contêiner, chame a função de [make\_collection](../dotnet/make-collection-stl-clr.md) , e passe o iterador de início e término do iterador do contêiner de STL\/CLR a ser copiado na coleção do .NET.  Essa função de modelo pega um iterador de STL\/CLR como um argumento do modelo.  O primeiro exemplo demonstra esse método.  
  
    -   Para converter um contêiner inteiro, converta o contêiner para uma interface da coleção .NET ou a uma coleção apropriado da interface.  O segundo exemplo demonstra esse método.  
  
## Exemplo  
 Neste exemplo, criamos um STL\/CLR `vector` e adicionamos\-lhe 5 elementos.  Em seguida, criarmos uma coleção de O chamando a função de `make_collection` .  Finalmente, é exibimos o conteúdo da coleção recém\-criada.  
  
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
  
  **O conteúdo de System::Collections::Generic::ICollection são:**  
**3**  
**5**  
**7**   
## Exemplo  
 Neste exemplo, criamos um STL\/CLR `map` e adicionamos\-lhe 5 elementos.  Em seguida, criamos um .NET <xref:System.Collections.Generic.IDictionary%602> e atribuímos\-lhe `map` diretamente.  Finalmente, é exibimos o conteúdo da coleção recém\-criada.  
  
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
  
  **O conteúdo de IDictionary são:**  
**Chave: 0,00 Valores: 0**  
**Chave: Valor 13,00: 13**  
**Chave: Valor 22,00: 22**  
**Chave: Valor 42,00: 42**  
**Chave: Valor 74,00: 74**   
## Consulte também  
 [Biblioteca STL\/CLR](../dotnet/stl-clr-library-reference.md)   
 [Como converter de um coleção .NET em um contêiner STL\/CLR](../dotnet/how-to-convert-from-a-dotnet-collection-to-a-stl-clr-container.md)   
 [range\_adapter](../dotnet/range-adapter-stl-clr.md)