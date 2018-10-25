---
title: Classe IRowsetChangeImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL::IRowsetChangeImpl
- IRowsetChangeImpl
- ATL.IRowsetChangeImpl
- ATL.IRowsetChangeImpl.DeleteRows
- ATL::IRowsetChangeImpl::DeleteRows
- IRowsetChangeImpl.DeleteRows
- DeleteRows
- IRowsetChangeImpl::DeleteRows
- ATL.IRowsetChangeImpl.InsertRow
- InsertRow
- IRowsetChangeImpl.InsertRow
- ATL::IRowsetChangeImpl::InsertRow
- IRowsetChangeImpl::InsertRow
- SetData
- IRowsetChangeImpl::SetData
- ATL.IRowsetChangeImpl.SetData
- IRowsetChangeImpl.SetData
- ATL::IRowsetChangeImpl::SetData
- IRowsetChangeImpl::FlushData
- IRowsetChangeImpl.FlushData
- FlushData
dev_langs:
- C++
helpviewer_keywords:
- providers, updatable
- updatable providers, immediate update
- IRowsetChangeImpl class
- DeleteRows method
- InsertRow method
- SetData method
- FlushData method
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c8c0c2de0e5b19b9c5f40ed859c11158722c5019
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50080761"
---
# <a name="irowsetchangeimpl-class"></a>Classe IRowsetChangeImpl

A implementação de modelos OLE DB do [IRowsetChange](/previous-versions/windows/desktop/ms715790) interface na especificação do OLE DB.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   class T,
   class Storage,
   class BaseInterface = IRowsetChange,
   class RowClass = CSimpleRow,
   class MapClass = CAtlMap <RowClass::KeyType, RowClass*>>
class ATL_NO_VTABLE IRowsetChangeImpl : public BaseInterface
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetChangeImpl`.

*Armazenamento*<br/>
O registro do usuário.

*BaseInterface*<br/>
A classe base para a interface, tais como `IRowsetChange`.

*RowClass*<br/>
A unidade de armazenamento para o identificador de linha.

*MapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)

|||
|-|-|
|[DeleteRows](#deleterows)|Exclui linhas do conjunto de linhas.|
|[InsertRow](#insertrow)|Insere uma linha no conjunto de linhas.|
|[SetData](#setdata)|Define valores de dados em uma ou mais colunas.|

### <a name="implementation-method-callback"></a>Método de implementação (retorno de chamada)

|||
|-|-|
|[FlushData](#flushdata)|Ponto pelo provedor para confirmar dados para seu repositório.|

## <a name="remarks"></a>Comentários

Essa interface é responsável por operações de gravação de imediato para um armazenamento de dados. "Imediatas" significa que quando o usuário final (a pessoa que usa o consumidor) faz qualquer alteração, essas alterações são transmitidas imediatamente para os dados armazena (e não pode ser desfeita).

`IRowsetChangeImpl` implementa o OLE DB `IRowsetChange` interface, que permite atualização dos valores das colunas em linhas existentes, a exclusão de linhas e inserindo novas linhas.

A implementação de modelos OLE DB dá suporte a todos os métodos de base (`SetData`, `InsertRow`, e `DeleteRows`).

> [!IMPORTANT]
>  É altamente recomendável que você leia a documentação a seguir antes de tentar implementar seu provedor:

- [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)

- Capítulo 6 a *referência do programador do OLE DB*

- Consulte também como o `RUpdateRowset` classe é usada em de [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) exemplo.

## <a name="deleterows"></a> Irowsetchangeimpl:: DeleteRows

Exclui linhas do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (DeleteRows )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBROWSTATUS rgRowStatus[]);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetChange:: DeleteRows](/previous-versions/windows/desktop/ms724362(v%3dvs.85)) na *referência do programador do OLE DB*.

## <a name="insertrow"></a> Irowsetchangeimpl:: Insertrow

Cria e inicializa uma nova linha no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (InsertRow )(HCHAPTER /* hReserved */,
   HACCESSOR hAccessor,
   void* pData,
   HROW* phRow);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetChange:: Insertrow](/previous-versions/windows/desktop/ms716921) na *referência do programador do OLE DB*.

## <a name="setdata"></a> Irowsetchangeimpl:: SetData

Define valores de dados em uma ou mais colunas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (SetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pSrcData);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetChange:: SetData](/previous-versions/windows/desktop/ms721232) na *referência do programador do OLE DB*.

## <a name="flushdata"></a> Irowsetchangeimpl:: Flushdata

Ponto pelo provedor para confirmar dados para seu repositório.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT FlushData(HROW hRowToFlush,
   HACCESSOR hAccessorToFlush);
```

#### <a name="parameters"></a>Parâmetros

*hRowToFlush*<br/>
[in] Identificador para as linhas de dados. O tipo dessa linha é determinado a partir de *RowClass* argumento de modelo da `IRowsetImpl` classe (`CSimpleRow` por padrão).

*hAccessorToFlush*<br/>
[in] Identificador para o acessador, que contém informações de associação e informações de tipo em seu `PROVIDER_MAP` (consulte [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)).

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="see-also"></a>Consulte também

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)