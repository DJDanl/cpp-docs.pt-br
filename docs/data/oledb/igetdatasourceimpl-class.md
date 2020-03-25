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
ms.openlocfilehash: 596dd2ea7f65040ae526662974d210c1f99a0cf2
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210607"
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl

Fornece uma implementação do objeto [IGetDataSource](/previous-versions/windows/desktop/ms709721(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T>
class ATL_NO_VTABLE IGetDataSourceImpl : public IGetDataSource
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IGetDataSourceImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[GetDataSource](#getdatasource)|Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.|

## <a name="remarks"></a>Comentários

Essa é uma interface obrigatória na sessão para obter um ponteiro de interface para o objeto de fonte de dados.

## <a name="igetdatasourceimplgetdatasource"></a><a name="getdatasource"></a>IGetDataSourceImpl:: getdataname

Retorna um ponteiro de interface no objeto de fonte de dados que criou a sessão.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetDataSource)(REFIID riid,
   IUnknown ** ppDataSource);
```

#### <a name="parameters"></a>parâmetros

Consulte [IGetDataSource:: Getdataname](/previous-versions/windows/desktop/ms725443(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Útil se você precisar acessar as propriedades no objeto de fonte de dados.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
