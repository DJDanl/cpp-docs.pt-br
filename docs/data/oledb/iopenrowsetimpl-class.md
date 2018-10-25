---
title: Classe IOpenRowsetImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IOpenRowsetImpl
- IOpenRowsetImpl.CreateRowset
- IOpenRowsetImpl::CreateRowset
- CreateRowset
- OpenRowset
- IOpenRowsetImpl::OpenRowset
- IOpenRowsetImpl.OpenRowset
dev_langs:
- C++
helpviewer_keywords:
- IOpenRowsetImpl class
- CreateRowset method
- OpenRowset method
ms.assetid: d259cedc-1db4-41cf-bc9f-5030907ab486
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 72ca35ad6f2246a517c8a8d103c1a7f37e142534
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50063426"
---
# <a name="iopenrowsetimpl-class"></a>Classe IOpenRowsetImpl

Fornece implementação para o `IOpenRowset` interface.

## <a name="syntax"></a>Sintaxe

```cpp
template <class SessionClass>
class IOpenRowsetImpl : public IOpenRowset
```

### <a name="parameters"></a>Parâmetros

*SessionClass*<br/>
Sua classe, derivada de `IOpenRowsetImpl`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CreateRowset](#createrowset)|Cria um objeto de conjunto de linhas. Não é chamado diretamente pelo usuário.|
|[OpenRowset](#openrowset)|Abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice. (Não em ATLDB. H)|

## <a name="remarks"></a>Comentários

O [IOpenRowset](/previous-versions/windows/desktop/ms716946) interface é obrigatório para um objeto de sessão. Ele abre e retorna um conjunto de linhas que inclui todas as linhas de uma única tabela base ou índice.

## <a name="createrowset"></a> Iopenrowsetimpl:: Createrowset

Cria um objeto de conjunto de linhas. Não é chamado diretamente pelo usuário. Ver [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724) no *referência do programador do OLE DB.*

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

#### <a name="parameters"></a>Parâmetros

*RowsetClass*<br/>
Um membro de classe de modelo que representa a classe de conjunto de linhas do usuário. Geralmente, gerado pelo assistente.

*pRowsetObj*<br/>
[out] Um ponteiro para um objeto de conjunto de linhas. Normalmente, esse parâmetro não for usado, mas ele pode ser usado se for preciso executar mais trabalho no conjunto de linhas antes de passá-lo para um objeto COM. O tempo de vida dos *pRowsetObj* estiver associado ao *ppRowset*.

Para outros parâmetros, consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724) no *referência do programador DB OLE.*

## <a name="openrowset"></a> Iopenrowsetimpl:: OPENROWSET

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

#### <a name="parameters"></a>Parâmetros

Ver [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Esse método não é encontrado no ATLDB. H. Quando você cria um provedor, ele é criado pelo Assistente de objeto ATL.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)