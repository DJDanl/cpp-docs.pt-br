---
title: Classe CRestrictions | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CRestrictions
- CRestrictions
- ATL.CRestrictions
dev_langs:
- C++
helpviewer_keywords:
- CRestrictions class
ms.assetid: 0aaa2364-641c-4318-b110-7446aada4b4f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 8e68234f3a93cacf22c3abb0c4181a938b3f1dd6
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="crestrictions-class"></a>Classe CRestrictions
Uma classe genérica que permite especificar restrições para conjuntos de linhas de esquema.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, short nRestrictions, const GUID* pguid>  
class CRestrictions : 
        public CSchemaRowset <T, nRestrictions>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe usada para o acessador.  
  
 `nRestrictions`  
 O número de colunas de restrição de linhas do esquema.  
  
 `pguid`  
 Um ponteiro para o GUID para o esquema.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Abrir](../../data/oledb/crestrictions-open.md)|Retorna um resultado definido de acordo com as restrições de fornecido pelo usuário.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbsch.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)   
 [Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)