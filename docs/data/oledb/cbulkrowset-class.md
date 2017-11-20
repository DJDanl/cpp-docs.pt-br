---
title: Classe CBulkRowset | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::CBulkRowset
- ATL.CBulkRowset
- ATL::CBulkRowset<TAccessor>
- CBulkRowset
- ATL.CBulkRowset<TAccessor>
dev_langs: C++
helpviewer_keywords: CBulkRowset class
ms.assetid: c6bde426-c543-4022-a98a-9519d9e2ae59
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 7208e2ecda79cf175f234499f6e69550693f182f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cbulkrowset-class"></a>Classe CBulkRowset
Busca e manipula as linhas para trabalhar nos dados em massa recuperando vários identificadores de linha com uma única chamada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class TAccessor>  
class CBulkRowset : public CRowset<TAccessor>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TAccessor`  
 Uma classe de acessador.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddRefRows](../../data/oledb/cbulkrowset-addrefrows.md)|Incrementa a contagem de referência.|  
|[CBulkRowset](../../data/oledb/cbulkrowset-cbulkrowset.md)|Construtor.|  
|[MoveFirst](../../data/oledb/cbulkrowset-movefirst.md)|Recupera a primeira linha de dados, executar uma busca em massa novo se necessário.|  
|[MoveLast](../../data/oledb/cbulkrowset-movelast.md)|Move para a última linha.|  
|[MoveNext](../../data/oledb/cbulkrowset-movenext.md)|Recupera a próxima linha de dados.|  
|[MovePrev](../../data/oledb/cbulkrowset-moveprev.md)|Move para a linha anterior.|  
|[MoveToBookmark](../../data/oledb/cbulkrowset-movetobookmark.md)|Busca a linha marcada por um indicador ou uma linha em um deslocamento especificado desse indicador.|  
|[MoveToRatio](../../data/oledb/cbulkrowset-movetoratio.md)|Busca de linhas a partir de uma posição fracionária no conjunto de linhas.|  
|[ReleaseRows](../../data/oledb/cbulkrowset-releaserows.md)|Define a linha atual (**m_nCurrentRow**) zero e versões todas as linhas.|  
|[SetRows](../../data/oledb/cbulkrowset-setrows.md)|Define o número de identificadores de linha a ser recuperado por uma chamada.|  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra o uso da `CBulkRowset` classe.  
  
 [!code-cpp[NVC_OLEDB_Consumer#1](../../data/oledb/codesnippet/cpp/cbulkrowset-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)