---
title: Classe CSimpleRow | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CSimpleRow
- ATL::CSimpleRow
- ATL.CSimpleRow
dev_langs: C++
helpviewer_keywords: CSimpleRow class
ms.assetid: 06d9621d-60cc-4508-8b0c-528d1b1a809b
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8a5d8777a1219e204e0db1a16858ef30009dc67d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="csimplerow-class"></a>Classe CSimpleRow
Fornece uma implementação padrão para o identificador de linha, que é usado no [IRowsetImpl](../../data/oledb/irowsetimpl-class.md) classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSimpleRow  
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AddRefRow](../../data/oledb/csimplerow-addrefrow.md)|Adiciona uma contagem de referência em um identificador de linha existente.|  
|[Compare](../../data/oledb/csimplerow-compare.md)|Compara duas linhas para ver se elas se referem à mesma instância de linha.|  
|[CSimpleRow](../../data/oledb/csimplerow-csimplerow.md)|O construtor.|  
|[ReleaseRow](../../data/oledb/csimplerow-releaserow.md)|Libera linhas.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_dwRef](../../data/oledb/csimplerow-m-dwref.md)|Contagem de referência para um identificador de linha existente.|  
|[m_iRowset](../../data/oledb/csimplerow-m-irowset.md)|Um índice no conjunto de linhas que representa o cursor.|  
  
## <a name="remarks"></a>Comentários  
 Um identificador de linha é logicamente uma marca exclusiva para uma linha de resultado. `IRowsetImpl`cria um novo `CSimpleRow` para cada linha solicitada em [irowsetimpl:: GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md). `CSimpleRow`também pode ser substituído por sua própria implementação da alça da linha, que é um argumento de modelo padrão para `IRowsetImpl`. O único requisito para substituir essa classe é para que a classe de substituição fornece um construtor que aceita um único parâmetro do tipo **longo**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Classe IRowsetImpl](../../data/oledb/irowsetimpl-class.md)