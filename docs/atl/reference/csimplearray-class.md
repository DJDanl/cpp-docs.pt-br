---
title: "Classe de CSimpleArray | Microsoft Docs"
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
  - "ATL.CSimpleArray"
  - "ATL::CSimpleArray"
  - "CSimpleArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleArray"
ms.assetid: ee0c9f39-b61c-4c18-bc43-4eada21dca3a
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para gerenciar uma matriz simples.  
  
## Sintaxe  
  
```  
  
      template <  
   class T,  
   class TEqual = CSimpleArrayEqualHelper< T >  
>   
class CSimpleArray  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados para armazenar na matriz.  
  
 `TEqual`  
 Um objeto sublinhado, definindo o teste de igualdade para elementos do tipo `T`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleArray::CSimpleArray](../Topic/CSimpleArray::CSimpleArray.md)|o construtor para a matriz simples.|  
|[CSimpleArray::~CSimpleArray](../Topic/CSimpleArray::~CSimpleArray.md)|O destrutor para a matriz simples.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleArray::Add](../Topic/CSimpleArray::Add.md)|Adiciona um novo elemento na matriz.|  
|[CSimpleArray::Find](../Topic/CSimpleArray::Find.md)|Localizar um elemento na matriz.|  
|[CSimpleArray::GetData](../Topic/CSimpleArray::GetData.md)|Retorna um ponteiro para dados armazenados na matriz.|  
|[CSimpleArray::GetSize](../Topic/CSimpleArray::GetSize.md)|Retorna o número de elementos armazenados na matriz.|  
|[CSimpleArray::Remove](../Topic/CSimpleArray::Remove.md)|Remove um determinado elemento da matriz.|  
|[CSimpleArray::RemoveAll](../Topic/CSimpleArray::RemoveAll.md)|Remove todos os elementos da matriz.|  
|[CSimpleArray::RemoveAt](../Topic/CSimpleArray::RemoveAt.md)|Remove o elemento especificado na matriz.|  
|[CSimpleArray::SetAtIndex](../Topic/CSimpleArray::SetAtIndex.md)|Define o elemento especificado na matriz.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleArray::operator](../Topic/CSimpleArray::operator.md)|Recupera um elemento de matriz.|  
|[CSimpleArray::operator \=](../Topic/CSimpleArray::operator%20=.md)|Operador de atribuição.|  
  
## Comentários  
 `CSimpleArray` fornece métodos para criar e gerenciar uma matriz simples, de qualquer tipo determinado `T`.  
  
 O parâmetro `TEqual` fornece um meio para definir uma função de igualdade para dois elementos de tipo `T`.  Criando uma classe semelhante a [CSimpleArrayEqualHelper](../../atl/reference/csimplearrayequalhelper-class.md), é possível alterar o comportamento de teste de igualdade para qualquer matriz fornecida.  Por exemplo, ao manipular uma matriz de ponteiros, pode ser útil para definir a igualdade como dependendo dos ponteiros referenciam.  A implementação padrão usa **operator\=\(\)**.  
  
 `CSimpleArray` e [CSimpleMap](../../atl/reference/csimplemap-class.md) são criados para um pequeno número de elementos.  [CAtlArray](../../atl/reference/catlarray-class.md) e [CAtlMap](../../atl/reference/catlmap-class.md) devem ser usados quando a matriz contém um grande número de elementos.  
  
## Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## Exemplo  
 [!CODE [NVC_ATL_Utilities#86](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#86)]  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)