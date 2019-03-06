---
title: Classe IRowsetIdentityImpl
ms.date: 11/04/2016
f1_keywords:
- ATL::IRowsetIdentityImpl
- ATL.IRowsetIdentityImpl
- IRowsetIdentityImpl
- IsSameRow
- IRowsetIdentityImpl.IsSameRow
- ATL.IRowsetIdentityImpl.IsSameRow
- IRowsetIdentityImpl::IsSameRow
- ATL::IRowsetIdentityImpl::IsSameRow
helpviewer_keywords:
- IRowsetIdentityImpl class
- IsSameRow method
ms.assetid: 56821edf-e045-40c8-96bd-231552cd5799
ms.openlocfilehash: e70330a023dc48b7e763bfb874da5290f2fa519f
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57424516"
---
# <a name="irowsetidentityimpl-class"></a>Classe IRowsetIdentityImpl

Implementa o OLE DB [IRowsetIdentity](/previous-versions/windows/desktop/ms715913(v=vs.85)) interface, que permite o teste para a identidade de linha.

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class RowClass = CSimpleRow>
class ATL_NO_VTABLE IRowsetIdentityImpl
   : public IRowsetIdentity
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetIdentityImpl`.

*RowClass*<br/>
A unidade de armazenamento para o `HROW`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[IsSameRow](#issamerow)|Compara dois identificadores de linha para ver se eles se referem à mesma linha.|

## <a name="issamerow"></a> IRowsetIdentityImpl::IsSameRow

Compara dois identificadores de linha para ver se eles se referem à mesma linha.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(IsSameRow )(HROW hThisRow,
   HROW hThatRow);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetIdentity::IsSameRow](/previous-versions/windows/desktop/ms719629(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Para comparar identificadores de linha, este método converte o `HROW` lida com a `RowClass` membros e chamadas `memcmp` em ponteiros.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)