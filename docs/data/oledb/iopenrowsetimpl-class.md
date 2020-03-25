---
title: Classe IOpenRowsetImpl
ms.date: 11/04/2016
f1_keywords:
- IOpenRowsetImpl
- IOpenRowsetImpl.CreateRowset
- IOpenRowsetImpl::CreateRowset
- OpenRowset
- IOpenRowsetImpl::OpenRowset
- IOpenRowsetImpl.OpenRowset
helpviewer_keywords:
- IOpenRowsetImpl class
- CreateRowset method
- OpenRowset method
ms.assetid: d259cedc-1db4-41cf-bc9f-5030907ab486
ms.openlocfilehash: 8ecbcd46e534baa73574f0930e1cbac4dbc49dfb
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210529"
---
# <a name="iopenrowsetimpl-class"></a>Classe IOpenRowsetImpl

Fornece implementação para a interface `IOpenRowset`.

## <a name="syntax"></a>Sintaxe

```cpp
template <class SessionClass>
class IOpenRowsetImpl : public IOpenRowset
```

### <a name="parameters"></a>parâmetros

*SessionClass*<br/>
Sua classe, derivada de `IOpenRowsetImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CreateRowset](#createrowset)|Cria um objeto de conjunto de linhas. Não chamado diretamente pelo usuário.|
|[OpenRowset](#openrowset)|Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. (Não em ATLDB. T|

## <a name="remarks"></a>Comentários

A interface [IOpenRowset](/previous-versions/windows/desktop/ms716946(v=vs.85)) é obrigatória para um objeto de sessão. Ele é aberto e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice.

## <a name="iopenrowsetimplcreaterowset"></a><a name="createrowset"></a>IOpenRowsetImpl:: CreateRowset

Cria um objeto de conjunto de linhas. Não chamado diretamente pelo usuário. Consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador de OLE DB.*

### <a name="syntax"></a>Sintaxe

```cpp
template template <class RowsetClass>
HRESULT CreateRowset(IUnknown* pUnkOuter,
   DBID* pTableID,
   DBID* pIndexID,
   REFIID riid,
   ULONG cPropertySets,
   DBPROPSET rgPropertySets[],
   IUnknown** ppRowset,
   RowsetClass*& pRowsetObj);
```

#### <a name="parameters"></a>parâmetros

*RowsetClass*<br/>
Um membro de classe de modelo que representa a classe do conjunto de linhas do usuário. Geralmente gerado pelo assistente.

*pRowsetObj*<br/>
fora Um ponteiro para um objeto de conjunto de linhas. Normalmente, esse parâmetro não é usado, mas pode ser usado se você precisar executar mais trabalho no conjunto de linhas antes de passá-lo para um objeto COM. O tempo de vida de *pRowsetObj* é associado por *ppRowset*.

Para outros parâmetros, consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador de OLE DB.*

## <a name="iopenrowsetimplopenrowset"></a><a name="openrowset"></a>IOpenRowsetImpl:: OpenRowset

Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT OpenRowset(IUnknown* pUnkOuter,
   DBID* pTableID,
   DBID* pIndexID,
   REFIID riid,
   ULONG cPropertySets,
   DBPROPSET rgPropertySets[],
   IUnknown** ppRowset);
```

#### <a name="parameters"></a>parâmetros

Consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Este método não foi encontrado em ATLDB. T. Ele é criado pelo assistente de objeto ATL quando você cria um provedor.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
