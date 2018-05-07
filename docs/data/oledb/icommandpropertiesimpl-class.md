---
title: Classe ICommandPropertiesImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ICommandPropertiesImpl
- ATL.ICommandPropertiesImpl
- ATL::ICommandPropertiesImpl
dev_langs:
- C++
helpviewer_keywords:
- ICommandPropertiesImpl class
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 25be1548bd41f832a007f102c138fc01f8818774
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="icommandpropertiesimpl-class"></a>Classe ICommandPropertiesImpl
Fornece uma implementação de [ICommandProperties](https://msdn.microsoft.com/en-us/library/ms723044.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
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