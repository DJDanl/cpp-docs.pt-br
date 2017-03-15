---
title: "Classe IRowsetLocateImpl | Microsoft Docs"
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
  - "IRowsetLocateImpl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "indicadores, OLE DB"
  - "Classe IRowsetLocateImpl"
  - "provedores, indicadores"
ms.assetid: a8aa3149-7ce8-4976-a680-2da193fd3234
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe IRowsetLocateImpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Implementa a interface OLE DB [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) , que busca linhas arbitrárias de um conjunto de linhas.  
  
## Sintaxe  
  
```  
template <  
   class T,   
   class RowsetInterface,   
   class RowClass = CSimpleRow,   
   class MapClass = CAtlMap < RowClass::KeyType, RowClass* >,   
   class BookmarkKeyType = LONG,   
   class BookmarkType = LONG,   
   class BookmarkMapClass = CAtlMap < RowClass::KeyType, RowClass* >  
>  
class ATL_NO_VTABLE IRowsetLocateImpl : public IRowsetImpl<  
   T,   
   RowsetInterface,   
   RowClass,   
   MapClass  
>  
```  
  
#### Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetLocateImpl`.  
  
 `RowsetInterface`  
 Uma classe derivada de `IRowsetImpl`.  
  
 `RowClass`  
 A unidade de armazenamento para **HROW**.  
  
 `MapClass`  
 A unidade de armazenamento para todas as alças de linha mantidos pelo provedor.  
  
 `BookmarkKeyType`  
 O tipo de medidor, como um LONG ou uma cadeia de caracteres.  Os indicadores similares devem ter um comprimento de pelo menos dois bytes. \(comprimento de byte único é reservado para OLE DB [indicadores padrão](https://msdn.microsoft.com/en-us/library/ms712954.aspx)**DBBMK\_FIRST**, **DBBMK\_LAST**, e **DBBMK\_INVALID**.\)  
  
 `BookmarkType`  
 O mecanismo de mapeamento para relações de manutenção de indicador\-à\- dados.  
  
 `BookmarkMapClass`  
 A unidade de armazenamento para todas as alças de linha mantidos pelo indicador.  
  
## Membros  
  
### Métodos da interface  
  
|||  
|-|-|  
|[Comparar](../../data/oledb/irowsetlocateimpl-compare.md)|Compara dois medidores.|  
|[GetRowsAt](../../data/oledb/irowsetlocateimpl-getrowsat.md)|Buscar linhas iniciar com a linha especificada por um deslocamento de um indicador.|  
|[GetRowsByBookmark](../../data/oledb/irowsetlocateimpl-getrowsbybookmark.md)|Pesquisa linhas que correspondam aos indicadores especificados.|  
|[Hash](../../data/oledb/irowsetlocateimpl-hash.md)|Retorna valores de hash dos indicadores especificados.|  
  
### Membros de dados  
  
|||  
|-|-|  
|[m\_rgBookmarks](../Topic/IRowsetLocateImpl::m_rgBookmarks.md)|Uma matriz de indicadores.|  
  
## Comentários  
 `IRowsetLocateImpl` é a implementação de modelos OLE DB da interface de [IRowsetLocate](https://msdn.microsoft.com/en-us/library/ms721190.aspx) .  `IRowsetLocate` é usado para buscar linhas arbitrárias de um conjunto de linhas.  Um conjunto de linhas que não implementa esta interface é um conjunto de linhas de `sequential` .  Quando `IRowsetLocate` presentes em um conjunto de linhas, a coluna 0 é o indexador das linhas; leia esta coluna terá um valor do medidor que pode ser usado para reposicionar à mesma linha.  
  
 `IRowsetLocateImpl` é usado para implementar o suporte do medidor em provedores.  Os indicadores são espaços reservados \(índices em um conjunto de linhas\) que habilita o consumidor para retornar rapidamente em uma linha, permitindo o acesso aos dados em alta velocidade.  O provedor determina que os indicadores podem identificar uma linha.  Usando métodos de `IRowsetLocateImpl` , você pode comparar indicadores, buscar linhas pelo deslocamento, buscar linhas por indicador, e retornam valores de hash de indicadores.  
  
 Para oferecer suporte a indicadores do OLE DB em um conjunto de linhas, faça o conjunto de linhas herdar dessa classe.  
  
 Para obter informações sobre como implementar o suporte do medidor, consulte [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md) em *Visual C\+\+ Programmer's Guide* e [Indicadores](https://msdn.microsoft.com/en-us/library/ms709728.aspx) em *OLE DB Programmer's Reference* em`Platform``SDK`.  
  
## Requisitos  
 **Cabeçalho**: atldb.h  
  
## Consulte também  
 [Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)   
 [IRowsetLocate:IRowset](https://msdn.microsoft.com/en-us/library/ms721190.aspx)   
 [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)   
 [Bookmarks](https://msdn.microsoft.com/en-us/library/ms709728.aspx)