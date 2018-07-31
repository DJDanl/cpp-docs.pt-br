---
title: Classe IColumnsInfoImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IColumnsInfoImpl<T>
- ATL::IColumnsInfoImpl
- IColumnsInfoImpl
- ATL.IColumnsInfoImpl
- ATL::IColumnsInfoImpl<T>
- GetColumnInfo
- ATL::IColumnsInfoImpl::GetColumnInfo
- ATL.IColumnsInfoImpl.GetColumnInfo
- ATL::IColumnsInfoImpl<T>::GetColumnInfo
- IColumnsInfoImpl::GetColumnInfo
- IColumnsInfoImpl<T>::GetColumnInfo
- IColumnsInfoImpl.GetColumnInfo
- IColumnsInfoImpl<T>::MapColumnIDs
- MapColumnIDs
- ATL::IColumnsInfoImpl::MapColumnIDs
- IColumnsInfoImpl.MapColumnIDs
- ATL::IColumnsInfoImpl<T>::MapColumnIDs
- IColumnsInfoImpl::MapColumnIDs
- ATL.IColumnsInfoImpl<T>.MapColumnIDs
- ATL.IColumnsInfoImpl.MapColumnIDs
dev_langs:
- C++
helpviewer_keywords:
- IColumnsInfoImpl class
- GetColumnInfo method
- MapColumnIDs method
ms.assetid: ba74c1c5-2eda-4452-8b57-84919fa0d066
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e95ab02abaf4dd536ad6a081708a76cf54cca6b0
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39337236"
---
# <a name="icolumnsinfoimpl-class"></a>Classe IColumnsInfoImpl
Fornece uma implementação de [IColumnsInfo](https://msdn.microsoft.com/library/ms724541.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>  
class ATL_NO_VTABLE IColumnsInfoImpl :   
   public IColumnsInfo,    
   public CDBIDOps  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IColumnsInfoImpl`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[GetColumnInfo](#getcolumninfo)|Retorna os metadados de coluna necessários para a maioria dos consumidores.|  
|[MapColumnIDs](#mapcolumnids)|Retorna uma matriz de ordinais das colunas em um conjunto de linhas que são identificados pelas IDs de coluna especificadas.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória nos conjuntos de linhas e comandos. Para modificar o comportamento do seu provedor `IColumnsInfo` implementação, você precisa modificar o mapa de coluna do provedor.  

## <a name="getcolumninfo"></a> Icolumnsinfoimpl:: Getcolumninfo
Retorna os metadados de coluna necessários para a maioria dos consumidores.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetColumnInfo)(DBORDINAL* pcColumns,  
   DBCOLUMNINFO** prgInfo,  
   OLECHAR** ppStringsBuffer);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [icolumnsinfo:: Getcolumninfo](https://msdn.microsoft.com/library/ms722704.aspx) na *referência do programador do OLE DB*.  

## <a name="mapcolumnids"></a> Icolumnsinfoimpl:: Mapcolumnids
Retorna uma matriz de ordinais das colunas em um conjunto de linhas que são identificados pelas IDs de coluna especificadas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (MapColumnIDs)(DBORDINAL cColumnIDs,  
   const DBID rgColumnIDs[],  
   DBORDINAL rgColumns[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IColumnsInfo::MapColumnIDs](https://msdn.microsoft.com/library/ms714200.aspx) na *referência do programador do OLE DB*.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)