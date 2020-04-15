---
title: Classe IRowsetChangeImpl
ms.date: 11/04/2016
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
- IRowsetChangeImpl::SetData
- ATL.IRowsetChangeImpl.SetData
- IRowsetChangeImpl.SetData
- ATL::IRowsetChangeImpl::SetData
- IRowsetChangeImpl::FlushData
- IRowsetChangeImpl.FlushData
- FlushData
helpviewer_keywords:
- providers, updatable
- updatable providers, immediate update
- IRowsetChangeImpl class
- DeleteRows method
- InsertRow method
- SetData method
- FlushData method
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
ms.openlocfilehash: ae4ceea53ec91cc3f9593dd3789fcf61e0702274
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376942"
---
# <a name="irowsetchangeimpl-class"></a>Classe IRowsetChangeImpl

A implementação do OLE DB Templates da interface [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)) na especificação OLE DB.

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

*Storage*<br/>
O registro do usuário.

*Baseinterface*<br/>
A classe base para a `IRowsetChange`interface, tais como .

*Rowclass*<br/>
A unidade de armazenamento para o cabo de linha.

*MapClass*<br/>
A unidade de armazenamento para todas as alças de linha mantidas pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)

|||
|-|-|
|[Deleterows](#deleterows)|Exclui linhas do conjunto de linhas.|
|[InsertRow](#insertrow)|Insere uma linha no conjunto de linhas.|
|[Setdata](#setdata)|Define valores de dados em uma ou mais colunas.|

### <a name="implementation-method-callback"></a>Método de implementação (Callback)

|||
|-|-|
|[Flushdata](#flushdata)|Substituído pelo provedor para comprometer dados em sua loja.|

## <a name="remarks"></a>Comentários

Esta interface é responsável por operações de gravação imediatas para um armazenamento de dados. "Imediato" significa que quando o usuário final (a pessoa que usa o consumidor) faz qualquer alteração, essas alterações são imediatamente transmitidas para o armazenamento de dados (e não podem ser desfeitas).

`IRowsetChangeImpl`implementa a interface `IRowsetChange` OLE DB, que permite a atualização de valores de colunas em linhas existentes, excluindo linhas e inserindo novas linhas.

A implementação do OLE DB Templates`SetData`suporta `InsertRow`todos `DeleteRows`os métodos básicos ( , e ).

> [!IMPORTANT]
> É recomendável que você leia a seguinte documentação ANTES de tentar implementar seu provedor:

- [Criando um provedor updatable](../../data/oledb/creating-an-updatable-provider.md)

- Capítulo 6 da *Referência do Programador OLE DB*

- Veja também `RUpdateRowset` como a classe é usada na amostra [UpdatePV.](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)

## <a name="irowsetchangeimpldeleterows"></a><a name="deleterows"></a>IRowsetChangeImpl::DeleteRows

Exclui linhas do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (DeleteRows )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBROWSTATUS rgRowStatus[]);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetChange::DeleteRows](/previous-versions/windows/desktop/ms724362(v=vs.85)) na *referência do programador OLE DB*.

## <a name="irowsetchangeimplinsertrow"></a><a name="insertrow"></a>IRowsetChangeImpl::InsertRow

Cria e inicializa uma nova linha no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (InsertRow )(HCHAPTER /* hReserved */,
   HACCESSOR hAccessor,
   void* pData,
   HROW* phRow);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetChange::InsertRow](/previous-versions/windows/desktop/ms716921(v=vs.85)) na *referência do programador OLE DB*.

## <a name="irowsetchangeimplsetdata"></a><a name="setdata"></a>IRowsetChangeImpl::SetData

Define valores de dados em uma ou mais colunas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (SetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pSrcData);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetChange::SetData](/previous-versions/windows/desktop/ms721232(v=vs.85)) na *referência do programador OLE DB*.

## <a name="irowsetchangeimplflushdata"></a><a name="flushdata"></a>IRowsetChangeImpl::FlushData

Substituído pelo provedor para comprometer dados em sua loja.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT FlushData(HROW hRowToFlush,
   HACCESSOR hAccessorToFlush);
```

#### <a name="parameters"></a>Parâmetros

*hRowToFlush*<br/>
[em] Manuseie as linhas para os dados. O tipo dessa linha é determinado a partir `IRowsetImpl` do`CSimpleRow` argumento de modelo *RowClass* da classe (por padrão).

*hAccessorToFlush*<br/>
[em] Manuseie o acessório, que contém `PROVIDER_MAP` informações de vinculação e informações de tipo em seu (ver [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)).

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura do modelo do provedor OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
