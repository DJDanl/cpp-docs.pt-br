---
title: "par (STL/CLR) | Microsoft Docs"
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
  - "cliext::pair"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classe de par [STL/CLR]"
ms.assetid: 3326b4d9-a52a-49e5-8103-9aa5e8b352de
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# par (STL/CLR)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do modelo descreve um objeto que encapsula um par de valores.  
  
## Sintaxe  
  
```  
template<typename Value1,  
    typename Value2>  
    ref class pair;  
```  
  
#### Parâmetros  
 Valor1  
 O tipo de valor primeiro envolvido.  
  
 Valor2  
 O tipo de segundo valor envolvido.  
  
## Membros  
  
|Definição de tipo|Descrição|  
|-----------------------|---------------|  
|[pair::first\_type](../dotnet/pair-first-type-stl-clr.md)|O tipo da primeira envolver o valor.|  
|[pair::second\_type](../dotnet/pair-second-type-stl-clr.md)|O tipo do segundo valor envolvido.|  
  
|Objeto de membro|Descrição|  
|----------------------|---------------|  
|[pair::first](../dotnet/pair-first-stl-clr.md)|O primeiro valor armazenado.|  
|[pair::second](../dotnet/pair-second-stl-clr.md)|O segundo valor armazenado.|  
  
|Função de membro|Descrição|  
|----------------------|---------------|  
|[pair::pair](../dotnet/pair-pair-stl-clr.md)|Cria um objeto do par.|  
|[pair::swap](../Topic/pair::swap%20\(STL-CLR\).md)|Alterna o conteúdo de dois pares.|  
  
|Operador|Descrição|  
|--------------|---------------|  
|[pair::operator\=](../dotnet/pair-operator-assign-stl-clr.md)|Substitui os pares de valores armazenados.|  
  
## Comentários  
 O objeto armazena um par de valores.  Você usa essa classe do modelo para combinar os dois valores em um único objeto.  Observe que os repositórios de `cliext::pair` \(descrito aqui apenas para tipos gerenciados\); para armazenar um par de tipos não gerenciado, use `std::pair`declarado em `<utility>`.  
  
## Requisitos  
 cliext \<\/utilitário de**Cabeçalho:** \>  
  
 cliext de**Namespace:**  
  
## Consulte também  
 [make\_pair](../dotnet/make-pair-stl-clr.md)