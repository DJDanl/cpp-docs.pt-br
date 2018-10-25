---
title: Classe IGetDataSourceImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IGetDataSourceImpl
- ATL.IGetDataSourceImpl<T>
- ATL.IGetDataSourceImpl
- ATL::IGetDataSourceImpl
- ATL::IGetDataSourceImpl<T>
- GetDataSource
- IGetDataSourceImpl.GetDataSource
- IGetDataSourceImpl::GetDataSource
dev_langs:
- C++
helpviewer_keywords:
- IGetDataSourceImpl class
- GetDataSource method
ms.assetid: d63f3178-d663-4f01-8c09-8aab2dd6805a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 7467a658ca8739ba933f266f58e756b8f7a3ba02
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055444"
---
# <a name="igetdatasourceimpl-class"></a>Classe IGetDataSourceImpl

Fornece uma implementação de [IGetDataSource](/previous-versions/windows/desktop/ms709721) objeto.

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

Ver [IGetDataSource::GetDataSource](/previous-versions/windows/desktop/ms725443) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

É útil se você precisar acessar as propriedades no objeto de fonte de dados.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)