---
title: Classe ICommandPropertiesImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ICommandPropertiesImpl
- ATL.ICommandPropertiesImpl
- ATL::ICommandPropertiesImpl
dev_langs: C++
helpviewer_keywords: ICommandPropertiesImpl class
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5878e7fa6345e294025b45474b1b384d01283c49
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="icommandpropertiesimpl-class"></a>Classe ICommandPropertiesImpl
Fornece uma implementação de [ICommandProperties](https://msdn.microsoft.com/en-us/library/ms723044.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class T, class PropClass = T>  
class ATL_NO_VTABLE ICommandPropertiesImpl   
   : public ICommandProperties, public CUtlProps<PropClass>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de  
  
 `PropClass`  
 A classe de propriedades.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/icommandpropertiesimpl-getproperties.md)|Retorna a lista de propriedades no grupo de propriedades do conjunto de linhas que atualmente são solicitadas para o conjunto de linhas.|  
|[SetProperties](../../data/oledb/icommandpropertiesimpl-setproperties.md)|Define as propriedades do grupo de propriedade do conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Isso é obrigatório em comandos. A implementação é fornecida por uma função estática definida pelo [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) macro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)