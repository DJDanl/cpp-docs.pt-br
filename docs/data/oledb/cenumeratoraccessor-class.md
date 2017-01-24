---
title: "Classe CEnumeratorAccessor | Microsoft Docs"
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
  - "ATL::CEnumeratorAccessor"
  - "CEnumeratorAccessor"
  - "ATL.CEnumeratorAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CEnumeratorAccessor"
ms.assetid: 21e8e7ea-3511-4afe-b33f-d520f4ff82bb
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe CEnumeratorAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usado por [CEnumerator](../../data/oledb/cenumerator-class.md) para acessar os dados do conjunto de linhas do enumerador.  
  
## Sintaxe  
  
```  
class CEnumeratorAccessor  
```  
  
## Membros  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_bIsParent](../../data/oledb/cenumeratoraccessor-m-bisparent.md)|Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.|  
|[m\_nType](../../data/oledb/cenumeratoraccessor-m-ntype.md)|Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.|  
|[m\_szDescription](../Topic/CEnumeratorAccessor::m_szDescription.md)|A descrição da fonte de dados ou do enumerador.|  
|[m\_szName](../../data/oledb/cenumeratoraccessor-m-szname.md)|O nome da fonte de dados ou do enumerador.|  
|[m\_szParseName](../../data/oledb/cenumeratoraccessor-m-szparsename.md)|Cadeia de caracteres a ser passada a [IParseDisplayName](http://msdn.microsoft.com/library/windows/desktop/ms680604) para obter um moniker para a fonte de dados ou o enumerador.|  
  
## Comentários  
 Esse conjunto de linhas consiste em fontes de dados e nos enumeradores visíveis do enumerador atual.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)