---
title: "range_adapter (STL/CLR) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "cliext::range_adapter"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe range_adapter [STL/CLR]"
ms.assetid: 3fbe2a65-1216-46a0-a182-422816b80cfb
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# range_adapter (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe do modelo que envolve um par de iteradores que são usados para implementar vários a biblioteca \(BCL\) da classe base interfaces.  Você usa o range\_adapter para manipular um intervalo de STL\/CLR como se fosse uma coleção de BCL.  
  
## Sintaxe  
  
```  
template<typename Iter>  
    ref class range_adapter  
        :   public  
        System::Collections::IEnumerable,  
        System::Collections::ICollection,  
        System::Collections::Generic::IEnumerable<Value>,  
        System::Collections::Generic::ICollection<Value>  
    { ..... };  
```  
  
#### Parâmetros  
 ITER  
 O tipo associado aos iteradores ajustados.  
  
## Membros  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[range\_adapter::range\_adapter](../dotnet/range-adapter-range-adapter-stl-clr.md)|Cria um objeto do adaptador.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[range\_adapter::operator\=](../dotnet/range-adapter-operator-assign-stl-clr.md)|Substitui os pares armazenados de iterador.|  
  
## Interfaces  
  
|Interface|Descrição|  
|---------------|---------------|  
|<xref:System.Collections.IEnumerable>|Itera através dos elementos da coleção.|  
|<xref:System.Collections.ICollection>|Mantém um grupo de elementos.|  
|<xref:System.Collections.Generic.IEnumerable%601>|Itera através dos elementos digitados na coleção.|  
|<xref:System.Collections.Generic.ICollection%601>|Mantém um grupo de elementos de tipo.|  
  
## Comentários  
 O range\_adapter armazena um par de iteradores, que limitam por sua vez uma sequência de elementos.  O implementa de objeto de quatro BCL interfaces que permitem a você iterar pelos elementos, em ordem.  Você usa essa classe do modelo para manipular intervalos de STL\/CLR bem como contêineres de BCL.  
  
## Requisitos  
 cliext \<\/adaptador de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [collection\_adapter](../Topic/collection_adapter%20\(STL-CLR\).md)   
 [make\_collection](../dotnet/make-collection-stl-clr.md)