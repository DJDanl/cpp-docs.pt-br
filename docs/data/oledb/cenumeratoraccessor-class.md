---
title: Classe CEnumeratorAccessor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CEnumeratorAccessor
- CEnumeratorAccessor
- ATL.CEnumeratorAccessor
dev_langs:
- C++
helpviewer_keywords:
- CEnumeratorAccessor class
ms.assetid: 21e8e7ea-3511-4afe-b33f-d520f4ff82bb
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5b3efe610e53d591f17d3ce227c6dbc09f0e23ce
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="cenumeratoraccessor-class"></a>Classe CEnumeratorAccessor
Usado por [CEnumerator](../../data/oledb/cenumerator-class.md) para acessar os dados do conjunto de linhas do enumerador.  
  
## <a name="syntax"></a>Sintaxe

```cpp
class CEnumeratorAccessor  
```  
  
## <a name="members"></a>Membros  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bIsParent](../../data/oledb/cenumeratoraccessor-m-bisparent.md)|Uma variável que indica se o enumerador é um enumerador pai, se a linha é um enumerador.|  
|[m_nType](../../data/oledb/cenumeratoraccessor-m-ntype.md)|Uma variável que indica se a linha descreve uma fonte de dados ou um enumerador.|  
|[m_szDescription](../../data/oledb/cenumeratoraccessor-m-szdescription.md)|A descrição da fonte de dados ou do enumerador.|  
|[m_szName](../../data/oledb/cenumeratoraccessor-m-szname.md)|O nome da fonte de dados ou do enumerador.|  
|[m_szParseName](../../data/oledb/cenumeratoraccessor-m-szparsename.md)|Cadeia de caracteres para passar para [IParseDisplayName](http://msdn.microsoft.com/library/windows/desktop/ms680604) para obter um identificador de origem para a fonte de dados ou o enumerador.|  
  
## <a name="remarks"></a>Comentários  
 Esse conjunto de linhas consiste nas fontes de dados e enumeradores visíveis do enumerador atual.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)