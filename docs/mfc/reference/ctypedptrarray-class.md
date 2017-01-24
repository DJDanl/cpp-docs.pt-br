---
title: "Classe de CTypedPtrArray | Microsoft Docs"
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
  - "CTypedPtrArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTypedPtrArray"
  - "matrizes de ponteiro"
ms.assetid: e3ecdf1a-a889-4156-92dd-ddbd36ccd919
caps.latest.revision: 22
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTypedPtrArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece um “wrapper” com segurança para objetos de classe `CPtrArray` ou `CObArray`.  
  
## Sintaxe  
  
```  
template< class BASE_CLASS, class TYPE >  
class CTypedPtrArray : public BASE_CLASS  
```  
  
#### Parâmetros  
 `BASE_CLASS`  
 Classe base de classe tipada de matriz de ponteiro; deve ser uma classe de matriz \(`CObArray` ou `CPtrArray`\).  
  
 `TYPE`  
 Tipo dos elementos armazenados na matriz da classe base.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTypedPtrArray::Add](../Topic/CTypedPtrArray::Add.md)|Adiciona um novo elemento ao final de uma matriz.  Aumenta a matriz se necessário|  
|[CTypedPtrArray::Append](../Topic/CTypedPtrArray::Append.md)|Adiciona o conteúdo de uma matriz ao final da outra.  Aumenta a matriz se necessário|  
|[CTypedPtrArray::Copy](../Topic/CTypedPtrArray::Copy.md)|Copia uma matriz a outra matriz; aumenta a matriz se necessário.|  
|[CTypedPtrArray::ElementAt](../Topic/CTypedPtrArray::ElementAt.md)|Retorna uma referência temporária ao ponteiro de elemento dentro da matriz.|  
|[CTypedPtrArray::GetAt](../Topic/CTypedPtrArray::GetAt.md)|Retorna o valor em um índice especificado.|  
|[CTypedPtrArray::InsertAt](../Topic/CTypedPtrArray::InsertAt.md)|Insere elemento \(ou todos os elementos em outros matriz\) em um índice especificado.|  
|[CTypedPtrArray::SetAt](../Topic/CTypedPtrArray::SetAt.md)|Defina o valor para um índice dado; matriz não permitida crescer.|  
|[CTypedPtrArray::SetAtGrow](../Topic/CTypedPtrArray::SetAtGrow.md)|Defina o valor para um índice dado; aumenta a matriz se necessário.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTypedPtrArray::operator](../Topic/CTypedPtrArray::operator.md)|Obtém ou define o elemento no índice especificado.|  
  
## Comentários  
 Quando você usa `CTypedPtrArray` em vez de `CPtrArray` ou `CObArray`, ajuda de recurso de verificação de tipo C\+\+ elimina os erros causados por tipos incompatíveis do ponteiro.  
  
 Além de isso, o wrapper de `CTypedPtrArray` executa grande parte da conversão que seria necessária se você usou `CObArray` ou `CPtrArray`.  
  
 Como todas as funções de `CTypedPtrArray` são in\-line, o uso de esse modelo não afeta significativamente o tamanho ou velocidade do seu código.  
  
 Para obter mais informações sobre como usar `CTypedPtrArray`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base Modelo\-](../Topic/Template-Based%20Classes.md).  
  
## Hierarquia de herança  
 `BASE_CLASS`  
  
 `CTypedPtrArray`  
  
## Requisitos  
 **Cabeçalho:** afxtempl.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CPtrArray](../../mfc/reference/cptrarray-class.md)   
 [Classe de CObArray](../../mfc/reference/cobarray-class.md)