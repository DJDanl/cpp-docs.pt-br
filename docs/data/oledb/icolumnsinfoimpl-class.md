---
title: Classe IColumnsInfoImpl
ms.date: 11/04/2016
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
helpviewer_keywords:
- IColumnsInfoImpl class
- GetColumnInfo method
- MapColumnIDs method
ms.assetid: ba74c1c5-2eda-4452-8b57-84919fa0d066
ms.openlocfilehash: 67052bdc5d49673146c036167c027d1efd882495
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556479"
---
# <a name="icolumnsinfoimpl-class"></a>Classe IColumnsInfoImpl

Fornece uma implementação de [IColumnsInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms724541(v=vs.85)) interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IColumnsInfoImpl :
   public IColumnsInfo, 
   public CDBIDOps
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
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

Ver [icolumnsinfo:: Getcolumninfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms722704(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="mapcolumnids"></a> Icolumnsinfoimpl:: Mapcolumnids

Retorna uma matriz de ordinais das colunas em um conjunto de linhas que são identificados pelas IDs de coluna especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (MapColumnIDs)(DBORDINAL cColumnIDs,
   const DBID rgColumnIDs[],
   DBORDINAL rgColumns[]);
```

#### <a name="parameters"></a>Parâmetros

Ver [IColumnsInfo::MapColumnIDs](https://docs.microsoft.com/previous-versions/windows/desktop/ms714200(v=vs.85)) na *referência do programador do OLE DB*.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)