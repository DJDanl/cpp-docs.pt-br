---
title: Classe IGetDataSourceImpl
ms.date: 11/04/2016
f1_keywords:
- IGetDataSourceImpl
- ATL.IGetDataSourceImpl<T>
- ATL.IGetDataSourceImpl
- ATL::IGetDataSourceImpl
- ATL::IGetDataSourceImpl<T>
- GetDataSource
- IGetDataSourceImpl.GetDataSource
- IGetDataSourceImpl::GetDataSource
helpviewer_keywords:
- IGetDataSourceImpl class
- GetDataSource method
ms.assetid: d63f3178-d663-4f01-8c09-8aab2dd6805a
ms.openlocfilehash: cd6b56f4281a2fdde77229ec54be6d6289a87148
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556563"
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl

Fornece uma implementação de [IGetDataSource](https://docs.microsoft.com/previous-versions/windows/desktop/ms709721(v=vs.85)) objeto.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IGetDataSourceImpl : public IGetDataSource
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de `IGetDataSourceImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetDataSource](#getdatasource)|Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.|

## <a name="remarks"></a>Comentários

Isso é uma interface obrigatória na sessão para a obtenção de um ponteiro de interface para o objeto de fonte de dados.

## <a name="getdatasource"></a> Igetdatasourceimpl:: Getdatasource

Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetDataSource)(REFIID riid,
   IUnknown ** ppDataSource);
```

#### <a name="parameters"></a>Parâmetros

Ver [IGetDataSource::GetDataSource](https://docs.microsoft.com/previous-versions/windows/desktop/ms725443(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

É útil se você precisar acessar as propriedades no objeto de fonte de dados.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)