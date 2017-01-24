---
title: "Classe de CObList | Microsoft Docs"
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
  - "CObList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CObList"
  - "listas, object"
  - "objetos [C++], listas de"
ms.assetid: 80699c93-33d8-4f8b-b8cf-7b58aeab64ca
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CObList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O oferece suporte ordenaram listas de ponteiros nonunique de `CObject` acessíveis em seqüência ou pelo valor de ponteiro.  
  
## Sintaxe  
  
```  
class CObList : public CObject  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObList::CObList](../Topic/CObList::CObList.md)|Constrói uma lista vazia para ponteiros de `CObject` .|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CObList::AddHead](../Topic/CObList::AddHead.md)|Adiciona elemento \(ou todos os elementos em outros lista\) no início da lista \(faz um novo o início.\)|  
|[CObList::AddTail](../Topic/CObList::AddTail.md)|Adiciona elemento \(ou todos os elementos em outros lista\) ao final da lista \(faz uma nova parte final\).|  
|[CObList::Find](../Topic/CObList::Find.md)|Obtém a posição de um elemento especificado pelo valor de ponteiro.|  
|[CObList::FindIndex](../Topic/CObList::FindIndex.md)|Obtém a posição de um elemento especificado por um índice com base zero.|  
|[CObList::GetAt](../Topic/CObList::GetAt.md)|Obtém o elemento em uma posição determinada.|  
|[CObList::GetCount](../Topic/CObList::GetCount.md)|Retorna o número de elementos em esta lista.|  
|[CObList::GetHead](../Topic/CObList::GetHead.md)|Retorna o elemento principal de lista \(não pode ser deixado\).|  
|[CObList::GetHeadPosition](../Topic/CObList::GetHeadPosition.md)|Retorna a posição do elemento principal da lista.|  
|[CObList::GetNext](../Topic/CObList::GetNext.md)|Obtém o próximo elemento para iterar.|  
|[CObList::GetPrev](../Topic/CObList::GetPrev.md)|Obtém o elemento anterior para iterar.|  
|[CObList::GetSize](../Topic/CObList::GetSize.md)|Retorna o número de elementos em esta lista.|  
|[CObList::GetTail](../Topic/CObList::GetTail.md)|Retorna o elemento da parte final da lista \(não pode ser deixado\).|  
|[CObList::GetTailPosition](../Topic/CObList::GetTailPosition.md)|Retorna a posição do elemento da parte final da lista.|  
|[CObList::InsertAfter](../Topic/CObList::InsertAfter.md)|Insere um novo elemento após uma posição determinada.|  
|[CObList::InsertBefore](../Topic/CObList::InsertBefore.md)|Insere um novo elemento antes que uma posição determinada.|  
|[CObList::IsEmpty](../Topic/CObList::IsEmpty.md)|Testa a condição vazia de lista \(elementos\).|  
|[CObList::RemoveAll](../Topic/CObList::RemoveAll.md)|Remove todos os elementos de esta lista.|  
|[CObList::RemoveAt](../Topic/CObList::RemoveAt.md)|Remove um elemento de esta lista, por posição especificada.|  
|[CObList::RemoveHead](../Topic/CObList::RemoveHead.md)|Remove o elemento do início da lista.|  
|[CObList::RemoveTail](../Topic/CObList::RemoveTail.md)|Remove o elemento da parte final da lista.|  
|[CObList::SetAt](../Topic/CObList::SetAt.md)|Define o elemento em uma posição determinada.|  
  
## Comentários  
 As listas de`CObList` se comportam como listas vinculadas de.  
  
 Uma variável do tipo **POSIÇÃO** é uma chave para a lista.  Você pode usar uma variável de **POSIÇÃO** como um iterador para atravessar seqüencialmente uma lista e como um indicador para armazenar um local.  Uma posição não é a mesma que um índice, mas.  
  
 Inserção do elemento é muito rápido no início da lista, na parte final, e em **POSIÇÃO**conhecido.  Uma busca seqüencial é necessária para analisar um elemento por valor ou pelo índice.  Esta pesquisa pode ser lento se a lista é longa.  
  
 `CObList` inserir a macro de `IMPLEMENT_SERIAL` para oferecer suporte a serialização e a despejo de seus elementos.  Se uma lista de ponteiros de `CObject` é armazenada em um arquivo, com um operador sobrecarregado insert ou com a função de membro de `Serialize` , cada elemento de `CObject` é serializado por sua vez.  
  
 Se você precisar de um despejo dos elementos individuais de `CObject` na lista, você deve definir o tamanho do contexto de um despejo a 1 ou maior.  
  
 Quando um objeto de `CObList` é excluído, ou quando seus elementos são removidos, somente os ponteiros de `CObject` são removidos, não os objetos que referenciam.  
  
 Você pode derivar suas próprias classes de `CObList`.  A nova classe de lista, projetada para armazenar ponteiros para objetos derivados de `CObject`, adicionar novos membros de dados e novas funções de membro.  Observe que a lista resultante não é estritamente com segurança de tipos, pois ele permite a inserção de todo o ponteiro de `CObject` .  
  
> [!NOTE]
>  Você deve usar a macro de [IMPLEMENT\_SERIAL](../Topic/IMPLEMENT_SERIAL.md) na implementação da classe derivada se você pretende serializar a lista.  
  
 Para obter mais informações sobre como usar `CObList`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## Hierarquia de herança  
 [CObject](../Topic/CObject%20Class.md)  
  
 `CObList`  
  
## Requisitos  
 **Cabeçalho:** afxcoll.h  
  
## Consulte também  
 [Classe de CObject](../Topic/CObject%20Class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CStringList](../Topic/CStringList%20Class.md)   
 [Classe de CPtrList](../Topic/CPtrList%20Class.md)