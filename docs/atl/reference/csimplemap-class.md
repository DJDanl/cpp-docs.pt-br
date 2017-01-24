---
title: "Classe de CSimpleMap | Microsoft Docs"
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
  - "ATL::CSimpleMap"
  - "ATL.CSimpleMap"
  - "CSimpleMap"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleMap"
ms.assetid: 61b06eb4-ae73-44b0-a305-0afb5a33e8b1
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleMap
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece suporte para uma matriz simples de mapeamento.  
  
## Sintaxe  
  
```  
  
      template <   
   class TKey,  
   class TVal,  
   class TEqual = CSimpleMapEqualHelper< TKey, TVal >   
>   
class CSimpleMap  
```  
  
#### Parâmetros  
 `TKey`  
 o tipo de elemento chave.  
  
 `TVal`  
 O tipo de elemento de valor.  
  
 `TEqual`  
 Um objeto sublinhado, definindo o teste de igualdade para elementos do tipo `T`.  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleMap::\_ArrayElementType](../Topic/CSimpleMap::_ArrayElementType.md)|Typedef para o tipo de valor.|  
|[CSimpleMap::\_ArrayKeyType](../Topic/CSimpleMap::_ArrayKeyType.md)|Typedef para o tipo de chave.|  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleMap::CSimpleMap](../Topic/CSimpleMap::CSimpleMap.md)|o construtor.|  
|[CSimpleMap::~CSimpleMap](../Topic/CSimpleMap::~CSimpleMap.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleMap::Add](../Topic/CSimpleMap::Add.md)|Adiciona uma chave e um valor associado à matriz de mapa.|  
|[CSimpleMap::FindKey](../Topic/CSimpleMap::FindKey.md)|Localiza uma chave específica.|  
|[CSimpleMap::FindVal](../Topic/CSimpleMap::FindVal.md)|Localiza um valor específico.|  
|[CSimpleMap::GetKeyAt](../Topic/CSimpleMap::GetKeyAt.md)|Recupera a chave especificada.|  
|[CSimpleMap::GetSize](../Topic/CSimpleMap::GetSize.md)|Retorna o número de entradas na matriz de mapeamento.|  
|[CSimpleMap::GetValueAt](../Topic/CSimpleMap::GetValueAt.md)|Recupera o valor especificado.|  
|[CSimpleMap::Lookup](../Topic/CSimpleMap::Lookup.md)|Retorna o valor associado com a chave determinada.|  
|[CSimpleMap::Remove](../Topic/CSimpleMap::Remove.md)|Remove um valor da chave e de correspondência.|  
|[CSimpleMap::RemoveAll](../Topic/CSimpleMap::RemoveAll.md)|Remove todas as chaves e valores.|  
|[CSimpleMap::RemoveAt](../Topic/CSimpleMap::RemoveAt.md)|Remove um valor específico de chave e de correspondência.|  
|[CSimpleMap::ReverseLookup](../Topic/CSimpleMap::ReverseLookup.md)|Retorna a chave associada com o valor fornecido.|  
|[CSimpleMap::SetAt](../Topic/CSimpleMap::SetAt.md)|Defina o valor associado com a chave determinada.|  
|[CSimpleMap::SetAtIndex](../Topic/CSimpleMap::SetAtIndex.md)|Define a chave e o valor específico.|  
  
## Comentários  
 `CSimpleMap` fornece suporte para uma matriz simples de mapeamento de qualquer tipo determinado `T`, gerenciando uma matriz não ordenada de chaves elementos e seus valores associados.  
  
 O parâmetro `TEqual` fornece um meio para definir uma função de igualdade para dois elementos de tipo `T`.  Criando uma classe semelhante a [CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md), é possível alterar o comportamento de teste de igualdade para qualquer matriz fornecida.  Por exemplo, ao manipular uma matriz de ponteiros, pode ser útil para definir a igualdade como dependendo dos ponteiros referenciam.  A implementação padrão usa **operator\=\=\(\)**.  
  
 `CSimpleMap` e [CSimpleArray](../../atl/reference/csimplearray-class.md) são fornecidos para compatibilidade com versões anteriores de ATL, e as implementações mais completo e mais eficientes de coleção são fornecidas por [CAtlArray](../../atl/reference/catlarray-class.md) e por [CAtlMap](../../atl/reference/catlmap-class.md).  
  
 Diferentemente de outras coleções de mapa de ATL e em MFC, essa classe é implementada com uma matriz simples, e as pesquisas de pesquisa requerem uma pesquisa linear.  `CAtlMap` deve ser usado quando a matriz contém um grande número de elementos.  
  
## Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## Exemplo  
 [!CODE [NVC_ATL_Utilities#91](../CodeSnippet/VS_Snippets_Cpp/NVC_ATL_Utilities#91)]  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)