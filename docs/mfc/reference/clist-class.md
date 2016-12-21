---
title: "Classe de CList | Microsoft Docs"
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
  - "CList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CList"
  - "listas"
  - "listas, classe base para"
ms.assetid: 6f6273c3-c8f6-47f5-ac2a-0a950379ae5d
caps.latest.revision: 23
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O oferece suporte ordenaram lista de objetos nonunique acessíveis em seqüência ou por valor.  
  
## Sintaxe  
  
```  
template< class TYPE, class ARG_TYPE = const TYPE& >   
class CList : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CList::CList](../Topic/CList::CList.md)|Constrói uma lista ordenada vazia.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CList::AddHead](../Topic/CList::AddHead.md)|Adiciona elemento \(ou todos os elementos em outros lista\) no início da lista \(faz um novo o início.\)|  
|[CList::AddTail](../Topic/CList::AddTail.md)|Adiciona elemento \(ou todos os elementos em outros lista\) ao final da lista \(faz uma nova parte final\).|  
|[CList::Find](../Topic/CList::Find.md)|Obtém a posição de um elemento especificado pelo valor de ponteiro.|  
|[CList::FindIndex](../Topic/CList::FindIndex.md)|Obtém a posição de um elemento especificado por um índice com base zero.|  
|[CList::GetAt](../Topic/CList::GetAt.md)|Obtém o elemento em uma posição determinada.|  
|[CList::GetCount](../Topic/CList::GetCount.md)|Retorna o número de elementos em esta lista.|  
|[CList::GetHead](../Topic/CList::GetHead.md)|Retorna o elemento principal de lista \(não pode ser deixado\).|  
|[CList::GetHeadPosition](../Topic/CList::GetHeadPosition.md)|Retorna a posição do elemento principal da lista.|  
|[CList::GetNext](../Topic/CList::GetNext.md)|Obtém o próximo elemento para iterar.|  
|[CList::GetPrev](../Topic/CList::GetPrev.md)|Obtém o elemento anterior para iterar.|  
|[CList::GetSize](../Topic/CList::GetSize.md)|Retorna o número de elementos em esta lista.|  
|[CList::GetTail](../Topic/CList::GetTail.md)|Retorna o elemento da parte final da lista \(não pode ser deixado\).|  
|[CList::GetTailPosition](../Topic/CList::GetTailPosition.md)|Retorna a posição do elemento da parte final da lista.|  
|[CList::InsertAfter](../Topic/CList::InsertAfter.md)|Insere um novo elemento após uma posição determinada.|  
|[CList::InsertBefore](../Topic/CList::InsertBefore.md)|Insere um novo elemento antes que uma posição determinada.|  
|[CList::IsEmpty](../Topic/CList::IsEmpty.md)|Testa a condição vazia de lista \(elementos\).|  
|[CList::RemoveAll](../Topic/CList::RemoveAll.md)|Remove todos os elementos de esta lista.|  
|[CList::RemoveAt](../Topic/CList::RemoveAt.md)|Remove um elemento de esta lista, por posição especificada.|  
|[CList::RemoveHead](../Topic/CList::RemoveHead.md)|Remove o elemento do início da lista.|  
|[CList::RemoveTail](../Topic/CList::RemoveTail.md)|Remove o elemento da parte final da lista.|  
|[CList::SetAt](../Topic/CList::SetAt.md)|Define o elemento em uma posição determinada.|  
  
#### Parâmetros  
 `TYPE`  
 Tipo de objeto armazenado na lista.  
  
 `ARG` *\_* `TYPE`  
 Tipo usado para referenciar os objetos armazenados na lista.  Pode ser uma referência.  
  
## Comentários  
 As listas de`CList` se comportam como listas vinculadas de.  
  
 Uma variável do tipo **POSIÇÃO** é uma chave para a lista.  Você pode usar uma variável de **POSIÇÃO** como um iterador para atravessar seqüencialmente uma lista e como um indicador para armazenar um local.  Uma posição não é a mesma que um índice, mas.  
  
 Inserção do elemento é muito rápido no início da lista, na parte final, e em **POSIÇÃO**conhecido.  Uma busca seqüencial é necessária para analisar um elemento por valor ou pelo índice.  Esta pesquisa pode ser lento se a lista é longa.  
  
 Se você precisar de um despejo dos elementos individuais na lista, você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Determinadas funções de membro de essa classe chamam funções auxiliares globais que devem ser personalizadas para a maioria dos usos da classe de `CList` .  Consulte [Auxiliares de classe de coleção](../../mfc/reference/collection-class-helpers.md) da seção “macros.” e de Globais  
  
 Para obter mais informações sobre como usar `CList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Exemplo  
 [!code-cpp[NVC_MFCCollections#35](../../mfc/codesnippet/CPP/clist-class_1.cpp)]  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CList`  
  
## Requisitos  
 **Cabeçalho:** afxtempl.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CMap](../../mfc/reference/cmap-class.md)   
 [Classe de CArray](../../mfc/reference/carray-class.md)