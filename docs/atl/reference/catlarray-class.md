---
title: "Classe de CAtlArray | Microsoft Docs"
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
  - "ATL::CAtlArray"
  - "ATL.CAtlArray"
  - "CAtlArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAtlArray"
ms.assetid: 0b503aa8-2357-40af-a326-6654bf1da098
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAtlArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe implementa um objeto de matriz.  
  
## Sintaxe  
  
```  
  
      template<   
   typename E,  
   class ETraits = CElementTraits< E >   
>  
class CAtlArray  
```  
  
#### Parâmetros  
 *e*  
 O tipo de dados a serem armazenados na matriz.  
  
 *ETraits*  
 O código usado para copiar ou mover elementos.  
  
## Membros  
  
### Métodos  
  
|||  
|-|-|  
|[Adicionar](../Topic/CAtlArray::Add.md)|Chamar este método para adicionar um elemento ao objeto de matriz.|  
|[Append](../Topic/CAtlArray::Append.md)|Chamar este método para adicionar o conteúdo de uma matriz ao final da outra.|  
|[AssertValid](../Topic/CAtlArray::AssertValid.md)|Chamar esse método para confirmar que o objeto matriz é válido.|  
|[CAtlArray](../Topic/CAtlArray::CAtlArray.md)|o construtor.|  
|[~CAtlArray](../Topic/CAtlArray::~CAtlArray.md)|O destrutor.|  
|[Copiar](../Topic/CAtlArray::Copy.md)|Chamar esse método para copiar os elementos de uma matriz a outra.|  
|[FreeExtra](../Topic/CAtlArray::FreeExtra.md)|Chamar esse método para remover alguns elementos vazios da matriz.|  
|[GetAt](../Topic/CAtlArray::GetAt.md)|Chamar esse método para recuperar um único elemento objeto de matriz.|  
|[GetCount](../Topic/CAtlArray::GetCount.md)|Chamar esse método para retornar o número de elementos armazenados na matriz.|  
|[GetData](../Topic/CAtlArray::GetData.md)|Chamar este método para retornar um ponteiro para o primeiro elemento na matriz.|  
|[InsertArrayAt](../Topic/CAtlArray::InsertArrayAt.md)|Chamar esse método para inserir uma matriz em outro.|  
|[InsertAt](../Topic/CAtlArray::InsertAt.md)|Chamar esse método para inserir um novo elemento \(ou várias cópias de um elemento\) no objeto de matriz.|  
|[IsEmpty](../Topic/CAtlArray::IsEmpty.md)|Chamar esse método para testar se a matriz está vazia.|  
|[RemoveAll](../Topic/CAtlArray::RemoveAll.md)|Chamar esse método para remover todos os elementos de objeto de matriz.|  
|[RemoveAt](../Topic/CAtlArray::RemoveAt.md)|Chamar esse método para remover um ou mais elementos da matriz.|  
|[SetAt](../Topic/CAtlArray::SetAt.md)|Chamar esse método para definir o valor de um elemento no objeto de matriz.|  
|[SetAtGrow](../Topic/CAtlArray::SetAtGrow.md)|Chamar esse método para definir o valor de um elemento no objeto de matriz, expanda a matriz conforme necessário.|  
|[SetCount](../Topic/CAtlArray::SetCount.md)|Chamar esse método para definir o tamanho do objeto de matriz.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador &#91;&#93;](../Topic/CAtlArray::operator.md)|Chame esse operador para retornar uma referência a um elemento na matriz.|  
  
### Typedefs  
  
|||  
|-|-|  
|[INARGTYPE](../Topic/CAtlArray::INARGTYPE.md)|O tipo de dados a ser usado para adicionar elementos na matriz.|  
|[OUTARGTYPE](../Topic/CAtlArray::OUTARGTYPE.md)|O tipo de dados a ser usado para recuperar os elementos da matriz.|  
  
## Comentários  
 **CAtlArray** fornece métodos para criar e gerenciar uma matriz de elementos de um tipo definido pelo usuário.  Embora semelhante a matrizes padrão de C, o objeto de **CAtlArray** pode crescer e reduz dinamicamente como necessário.  Índice de matriz de inicia sempre na posição 0, e o limite superior podem ser corrigidos, expanda ou permitido como os novos elementos são adicionados.  
  
 Para matrizes com um pequeno número de elementos, a classe [CSimpleArray](../../atl/reference/csimplearray-class.md) de ATL pode ser usada.  
  
 **CAtlArray** é intimamente relacionadas à classe de **CArray** MFC e trabalhar em um projeto MFC, embora sem suporte a serialização.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [exemplo de MMXSwarm](../../top/visual-cpp-samples.md)   
 [exemplo de DynamicConsumer](../../top/visual-cpp-samples.md)   
 [exemplo de UpdatePV](../../top/visual-cpp-samples.md)   
 [Exemplo de famoso](../../top/visual-cpp-samples.md)   
 [Classe de CArray](../../mfc/reference/carray-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)