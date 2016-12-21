---
title: "Classe de CTypedPtrList | Microsoft Docs"
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
  - "CTypedPtrList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CTypedPtrList"
  - "listas vinculadas [C++]"
  - "listas [C++]"
  - "listas do ponteiro"
  - "classes de modelo, Classe de CTypedPtrList"
  - "coleções fortemente tipadas"
ms.assetid: c273096e-1756-4340-864b-4a08b674a65e
caps.latest.revision: 24
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CTypedPtrList
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Fornece um “wrapper” com segurança para objetos de classe `CPtrList`.  
  
## Sintaxe  
  
```  
template< class BASE_CLASS, class TYPE >  
class CTypedPtrList : public BASE_CLASS  
```  
  
#### Parâmetros  
 `BASE_CLASS`  
 Classe base de classe tipada de lista do ponteiro; deve ser uma classe de lista do ponteiro\(`CObList` ou `CPtrList`\).  
  
 `TYPE`  
 Tipo dos elementos armazenados na lista de classe base.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CTypedPtrList::AddHead](../Topic/CTypedPtrList::AddHead.md)|Adiciona elemento \(ou todos os elementos em outros lista\) no início da lista \(faz um novo o início.\)|  
|[CTypedPtrList::AddTail](../Topic/CTypedPtrList::AddTail.md)|Adiciona elemento \(ou todos os elementos em outros lista\) ao final da lista \(faz uma nova parte final\).|  
|[CTypedPtrList::GetAt](../Topic/CTypedPtrList::GetAt.md)|Obtém o elemento em uma posição determinada.|  
|[CTypedPtrList::GetHead](../Topic/CTypedPtrList::GetHead.md)|Retorna o elemento principal de lista \(não pode ser deixado\).|  
|[CTypedPtrList::GetNext](../Topic/CTypedPtrList::GetNext.md)|Obtém o próximo elemento para iterar.|  
|[CTypedPtrList::GetPrev](../Topic/CTypedPtrList::GetPrev.md)|Obtém o elemento anterior para iterar.|  
|[CTypedPtrList::GetTail](../Topic/CTypedPtrList::GetTail.md)|Retorna o elemento da parte final da lista \(não pode ser deixado\).|  
|[CTypedPtrList::RemoveHead](../Topic/CTypedPtrList::RemoveHead.md)|Remove o elemento do início da lista.|  
|[CTypedPtrList::RemoveTail](../Topic/CTypedPtrList::RemoveTail.md)|Remove o elemento da parte final da lista.|  
|[CTypedPtrList::SetAt](../Topic/CTypedPtrList::SetAt.md)|Define o elemento em uma posição determinada.|  
  
## Comentários  
 Quando você usa `CTypedPtrList` em vez de `CObList` ou `CPtrList`, ajuda de recurso de verificação de tipo C\+\+ elimina os erros causados por tipos incompatíveis do ponteiro.  
  
 Além de isso, o wrapper de `CTypedPtrList` executa grande parte da conversão que seria necessária se você usou `CObList` ou `CPtrList`.  
  
 Como todas as funções de `CTypedPtrList` são in\-line, o uso de esse modelo não afeta significativamente o tamanho ou velocidade do seu código.  
  
 As listas de `CObList` derivadas podem ser serializadas, mas essas derivadas de `CPtrList` não podem.  
  
 Quando um objeto de `CTypedPtrList` é excluído, ou quando seus elementos são removidos, somente os ponteiros são removidos, não as entidades que referenciam.  
  
 Para obter mais informações sobre como usar `CTypedPtrList`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base Modelo\-](../Topic/Template-Based%20Classes.md).  
  
## Exemplo  
 Este exemplo cria uma instância de `CTypedPtrList`, adiciona um objeto, serializa a lista no disco, e exclui no objeto:  
  
 [!code-cpp[NVC_MFCCollections#110](../../mfc/codesnippet/CPP/ctypedptrlist-class_1.cpp)]  
  
 [!code-cpp[NVC_MFCCollections#111](../../mfc/codesnippet/CPP/ctypedptrlist-class_2.cpp)]  
  
## Hierarquia de herança  
 `BASE_CLASS`  
  
 `_CTypedPtrList`  
  
 `CTypedPtrList`  
  
## Requisitos  
 **Cabeçalho:** afxtempl.h  
  
## Consulte também  
 [O exemplo COLETA MFC](../../top/visual-cpp-samples.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CPtrList](../Topic/CPtrList%20Class.md)   
 [Classe de CObList](../../mfc/reference/coblist-class.md)