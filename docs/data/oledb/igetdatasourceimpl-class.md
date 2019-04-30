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
ms.openlocfilehash: 2056b93fd6c1d32b72996970352e87670ff406de
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62408934"
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl

Fornece uma implementação de [IGetDataSource](/previous-versions/windows/desktop/ms709721(v=vs.85)) objeto.

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

## <a name="getdatasource"></a> IGetDataSourceImpl::GetDataSource

Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetDataSource)(REFIID riid,
   IUnknown ** ppDataSource);
```

#### <a name="parameters"></a>Parâmetros

Ver [IGetDataSource::GetDataSource](/previous-versions/windows/desktop/ms725443(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

É útil se você precisar acessar as propriedades no objeto de fonte de dados.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)