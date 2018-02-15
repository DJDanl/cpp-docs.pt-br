---
title: Classe IRowsetImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- IRowsetImpl
dev_langs:
- C++
helpviewer_keywords:
- IRowsetImpl class
ms.assetid: 6a9189af-7556-45b1-adcb-9d62bb36704c
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 54b9fd321c4240e9ba02cc63d809a492ffa4d439
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="irowsetimpl-class"></a>Classe IRowsetImpl
Fornece uma implementação da interface `IRowset`.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <  
   class T,   
   class RowsetInterface,  
   class RowClass = CSimpleRow,  
   class MapClass = CAtlMap <  
      RowClass::KeyType,  
      RowClass*>>  
class ATL_NO_VTABLE IRowsetImpl : public RowsetInterface  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IRowsetImpl`.  
  
 `RowsetInterface`  
 Uma classe derivada de `IRowsetImpl`.  
  
 `RowClass`  
 Unidade de armazenamento para o **HROW**.  
  
 `MapClass`  
 Unidade de armazenamento para todos os identificadores de linha é mantido pelo provedor.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md)|Adiciona uma contagem de referência em um identificador de linha existente.|  
|[CreateRow](../../data/oledb/irowsetimpl-createrow.md)|Chamado pelo [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) para alocar um novo **HROW**. Não é chamado diretamente pelo usuário.|  
|[GetData](../../data/oledb/irowsetimpl-getdata.md)|Recupera dados da cópia do conjunto de linhas da linha.|  
|[GetDBStatus](../../data/oledb/irowsetimpl-getdbstatus.md)|Retorna o status para o campo especificado.|  
|[GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md)|Busca linhas sequencialmente, lembrando da posição anterior.|  
|[IRowsetImpl](../../data/oledb/irowsetimpl-class.md)|O construtor. Não é chamado diretamente pelo usuário.|  
|[RefRows](../../data/oledb/irowsetimpl-refrows.md)|Chamado pelo [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e [ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md). Não é chamado diretamente pelo usuário.|  
|[ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md)|Libera linhas.|  
|[RestartPosition](../../data/oledb/irowsetimpl-restartposition.md)|Reposiciona a próxima posição de busca na sua posição inicial; ou seja, sua posição quando o conjunto de linhas foi inicialmente criado.|  
|[SetDBStatus](../../data/oledb/irowsetimpl-setdbstatus.md)|Define os sinalizadores de status para o campo especificado.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bCanFetchBack](../../data/oledb/irowsetimpl-m-bcanfetchback.md)|Indica se um provedor dá suporte à busca com versões anteriores.|  
|[m_bCanScrollBack](../../data/oledb/irowsetimpl-m-bcanscrollback.md)|Indica se um provedor pode ter sua rolagem do cursor com versões anteriores.|  
|[m_bReset](../../data/oledb/irowsetimpl-m-breset.md)|Indica se um provedor redefiniu sua posição de cursor. Isso tem um significado especial quando com versões anteriores de rolagem ou busca com versões anteriores em [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md).|  
|[m_iRowset](../../data/oledb/irowsetimpl-m-irowset.md)|Um índice no conjunto de linhas, que representa o cursor.|  
|[m_rgRowHandles](../../data/oledb/irowsetimpl-m-rgrowhandles.md)|Uma lista de identificadores de linha.|  
  
## <a name="remarks"></a>Comentários  
 [IRowset](https://msdn.microsoft.com/en-us/library/ms720986.aspx) é a interface de conjunto de linhas de base.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)