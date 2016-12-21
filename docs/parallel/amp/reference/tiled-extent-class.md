---
title: "Classe tiled_extent | Microsoft Docs"
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
  - "amp/Concurrency::tiled_extent"
dev_langs: 
  - "C++"
ms.assetid: 671ecaf8-c7b0-4ac8-bbdc-e30bd92da7c0
caps.latest.revision: 9
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe tiled_extent
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Um objeto `tiled_extent` é um objeto `extent` de uma das três dimensões que subdividem o espaço de extensão em blocos de uma, duas ou três dimensões.  
  
## Sintaxe  
  
```  
template <  
   int _Dim0,  
   int _Dim1,  
   int _Dim2  
>  
class tiled_extent : public Concurrency::extent<3>;  
  
template <  
   int _Dim0,  
   int _Dim1  
>  
class tiled_extent<_Dim0, _Dim1, 0> : public Concurrency::extent<2>;  
  
template <  
   int _Dim0  
>  
class tiled_extent<_Dim0, 0, 0> : public Concurrency::extent<1>;  
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
|[Construtor tiled\_extent::tiled\_extent](../Topic/tiled_extent::tiled_extent%20Constructor.md)|Inicializa uma nova instância da classe `tiled_extent`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método tiled\_extent::get\_tile\_extent](../Topic/tiled_extent::get_tile_extent%20Method.md)|Retorna um objeto `extent` que captura o valor dos argumentos de modelo `tiled_extent` `_Dim0`, `_Dim1`, e `_Dim2`.|  
|[Método tiled\_extent::pad](../Topic/tiled_extent::pad%20Method.md)|Retorna um novo objeto `tiled_extent` com as extensões ajustadas para ser igualmente divisível pelas dimensões do bloco.|  
|[Método tiled\_extent::truncate](../Topic/tiled_extent::truncate%20Method.md)|Retorna um novo objeto `tiled_extent` com as extensões ajustadas para baixo para ser igualmente divisível pelas dimensões do bloco.|  
  
### Operadores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Operador tiled\_extent::operator\=](../Topic/tiled_extent::operator=%20Operator.md)|Copia o conteúdo do objeto `tiled_index` especificado para esse outro.|  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante tiled\_extent::tile\_dim0](../Topic/tiled_extent::tile_dim0%20Constant.md)|Armazena o comprimento da dimensão mais significativa.|  
|[Constante tiled\_extent::tile\_dim1](../Topic/tiled_extent::tile_dim1%20Constant.md)|Armazena o comprimento de uma das dimensões mais significativas.|  
|[Constante tiled\_extent::tile\_dim2](../Topic/tiled_extent::tile_dim2%20Constant.md)|Armazena o comprimento da dimensão menos significativa.|  
  
### Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Membro de dados tiled\_extent::tile\_extent](../Topic/tiled_extent::tile_extent%20Data%20Member.md)|Obtém um objeto `extent` que captura os valores dos argumentos de modelo `tiled_extent` `_Dim0`, `_Dim1`, e `_Dim2`.|  
  
## Hierarquia de Herança  
 `extent`  
  
 `tiled_extent`  
  
## Requisitos  
 **Cabeçalho:** amp.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)