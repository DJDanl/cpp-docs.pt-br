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
- ICommandPropertiesImpl::GetProperties
- ICommandPropertiesImpl.GetProperties
- GetProperties
- ICommandPropertiesImpl.SetProperties
- ICommandPropertiesImpl::SetProperties
- SetProperties
dev_langs:
- C++
helpviewer_keywords:
- ICommandPropertiesImpl class
- GetProperties method
- SetProperties method
ms.assetid: b3cf6aea-527e-4f0d-96e0-669178b021a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b360b56066ecbb5cc605012b234c0ac11afb2a11
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39339406"
---
# <a name="icommandpropertiesimpl-class"></a>Classe ICommandPropertiesImpl
Fornece uma implementação de [ICommandProperties](https://msdn.microsoft.com/library/ms723044.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>  
class ATL_NO_VTABLE ICommandPropertiesImpl   
   : public ICommandProperties, public CUtlProps<PropClass>  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de  
  
 *PropClass*  
 Sua classe de propriedades.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](#getproperties)|Retorna a lista de propriedades no grupo de propriedades do conjunto de linhas que atualmente são solicitadas para o conjunto de linhas.|  
|[SetProperties](#setproperties)|Define propriedades no grupo de propriedades do conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Isso é obrigatório em comandos. A implementação é fornecida por uma função estática definida pela [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md) macro.  

## <a name="getproperties"></a> Icommandpropertiesimpl:: GetProperties
Retorna todos os conjuntos de propriedade solicitada usando o mapa de propriedade do comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(GetProperties)(const ULONG cPropertyIDSets,   
   const DBPROPIDSET rgPropertyIDSets[],   
   ULONG * pcPropertySets,   
   DBPROPSET ** prgPropertySets);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [icommandproperties:: GetProperties](https://msdn.microsoft.com/library/ms723119.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Ver [BEGIN_PROPSET_MAP](../../data/oledb/begin-propset-map.md).  
  
## <a name="setproperties"></a> Icommandpropertiesimpl:: SetProperties
Define propriedades para o objeto de comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(SetProperties)(ULONG cPropertySets,   
   DBPROPSET rgPropertySets[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [icommandproperties:: SetProperties](https://msdn.microsoft.com/library/ms711497.aspx) na *referência do programador do OLE DB*.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)