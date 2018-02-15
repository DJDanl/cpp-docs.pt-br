---
title: BEGIN_PROPSET_MAP | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- BEGIN_PROPSET_MAP
dev_langs:
- C++
helpviewer_keywords:
- BEGIN_PROPSET_MAP macro
ms.assetid: c3a30618-6025-4d49-8688-a171294d2e93
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 41a19fb9104c5756693e8120f38d36ec882e43d4
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="beginpropsetmap"></a>BEGIN_PROPSET_MAP
As marcas de início da propriedade definir entradas do mapa.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
BEGIN_PROPSET_MAP(Class)  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *Class*  
 [in] A classe na qual essa propriedade definida é especificada. Um conjunto de propriedades pode ser especificado nos seguintes objetos OLE DB:  
  
-   [Objetos de fonte de dados](https://msdn.microsoft.com/en-us/library/ms721278.aspx)  
  
-   [Objetos de sessão](https://msdn.microsoft.com/en-us/library/ms711572.aspx)  
  
-   [Comandos](https://msdn.microsoft.com/en-us/library/ms724608.aspx)  
  
## <a name="example"></a>Exemplo  
 Aqui está um exemplo de mapa de conjunto de propriedade:  
  
 [!code-cpp[NVC_OLEDB_Provider#3](../../data/oledb/codesnippet/cpp/begin-propset-map_1.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Macros para modelos de provedor do OLE DB](../../data/oledb/macros-for-ole-db-provider-templates.md)   
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura do modelo de provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)   
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)