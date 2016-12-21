---
title: "Classe tiled_index | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "amp/Concurrency::tiled_index"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe tiled_index"
ms.assetid: 0ce2ae26-f1bb-4436-b473-a9e1b619bb38
caps.latest.revision: 19
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe tiled_index
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Fornece um índice em um objeto [tiled\_extent](../../../parallel/amp/reference/tiled-extent-class.md).  Essa classe possui propriedades para acessar os elementos relacionados à origem do grupo local e relativo à origem global.  Para obter mais informações sobre espaços lado a lado, consulte [Usando blocos](../../../parallel/amp/using-tiles.md).  
  
## Sintaxe  
  
```  
template <  
   int _Dim0,  
   int _Dim1 = 0,  
   int _Dim2 = 0  
>  
class tiled_index : public _Tiled_index_base<3>;  
  
template <  
   int _Dim0,  
   int _Dim1  
>  
class tiled_index<_Dim0, _Dim1, 0> : public _Tiled_index_base<2>;  
  
template <  
   int _Dim0  
>  
class tiled_index<_Dim0, 0, 0> : public _Tiled_index_base<1>;  
```  
  
#### Parâmetros  
 `_Dim0`  
 O tamanho da dimensão mais significativa.  
  
 `_Dim1`  
 O tamanho de uma das dimensões mais significativas.  
  
 `_Dim2`  
 O tamanho da dimensão menos significativa.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor tiled\_index::tiled\_index](../Topic/tiled_index::tiled_index%20Constructor.md)|Inicializa uma nova instância da classe `tile_index`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método tiled\_index::get\_tile\_extent](../Topic/tiled_index::get_tile_extent%20Method.md)|Retorna um objeto [extent](../Topic/extent%20Class%20\(C++%20AMP\).md) que tem os valores dos argumentos de modelo [tiled\_index](../../../parallel/amp/reference/tiled-index-class.md) `_Dim0`, `_Dim1`, e `_Dim2`.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante tiled\_index::barrier](../Topic/tiled_index::barrier%20Constant.md)|Armazena um objeto [tile\_barrier](../Topic/tile_barrier%20Class.md) que representa uma barreira no quadro atual de segmentos.|  
|||  
|[Constante tiled\_index::global](../Topic/tiled_index::global%20Constant.md)|Armazena um objeto [índice](../../../parallel/amp/reference/index-class.md) de classificação, 1, 2 ou 3 que representa o índice global em um objeto [grid](http://msdn.microsoft.com/pt-br/f7d1b6a6-586c-4345-b09a-bfc26c492cb0).|  
|[Constante tiled\_index::local](../Topic/tiled_index::local%20Constant.md)|Armazena um objeto `index` de classificação, 2, 1 ou 3 que representa o índice relativa no quadro atual de um objeto [tiled\_extent](../../../parallel/amp/reference/tiled-extent-class.md).|  
|[Constante tiled\_index::rank](../Topic/tiled_index::rank%20Constant.md)|Armazena a classificação do objeto [tiled\_index](../../../parallel/amp/reference/tiled-index-class.md).|  
|[Constante tiled\_index::tile](../Topic/tiled_index::tile%20Constant.md)|Armazena um objeto `index` de classificação 1, 2 ou 3, que representa as coordenadas do quadro atual de um objeto `tiled_extent`.|  
|[Constante tiled\_index::tile\_dim0](../Topic/tiled_index::tile_dim0%20Constant.md)|Armazena o comprimento da dimensão mais significativa.|  
|[Constante tiled\_index::tile\_dim1](../Topic/tiled_index::tile_dim1%20Constant.md)|Armazena o comprimento de uma das dimensões mais significativas.|  
|[Constante tiled\_index::tile\_dim2](../Topic/tiled_index::tile_dim2%20Constant.md)|Armazena o comprimento da dimensão menos significativa.|  
|[Constante tiled\_index::tile\_origin](../Topic/tiled_index::tile_origin%20Constant.md)|Armazena um objeto `index` de classificação 1, 2 ou 3, que representa as coordenadas globais de origem do quadro atual em um objeto `tiled_extent`.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados tiled\_index::tile\_extent](../Topic/tiled_index::tile_extent%20Data%20Member.md)|Obtém um objeto [extent](../Topic/extent%20Class%20\(C++%20AMP\).md) \(extensão\) que possui os valores dos argumentos `_Dim0`, `_Dim1` e `_Dim2`, do modelo [tiled\_index](../../../parallel/amp/reference/tiled-index-class.md) e dos argumentos do modelo [tiled\_index](../../../parallel/amp/reference/tiled-index-class.md).|  
  
## Hierarquia de Herança  
 `_Tiled_index_base`  
  
 `tiled_index`  
  
## Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)