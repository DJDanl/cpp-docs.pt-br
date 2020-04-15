---
title: Classe IRowsetUpdateImpl
ms.date: 11/04/2016
f1_keywords:
- IRowsetUpdateImpl
- ATL.IRowsetUpdateImpl
- ATL::IRowsetUpdateImpl
- IRowsetUpdateImpl::SetData
- IRowsetUpdateImpl.SetData
- ATL::IRowsetUpdateImpl::SetData
- ATL.IRowsetUpdateImpl.SetData
- ATL.IRowsetUpdateImpl.GetOriginalData
- IRowsetUpdateImpl.GetOriginalData
- ATL::IRowsetUpdateImpl::GetOriginalData
- IRowsetUpdateImpl::GetOriginalData
- IRowsetUpdateImpl::GetPendingRows
- GetPendingRows
- IRowsetUpdateImpl.GetPendingRows
- ATL::IRowsetUpdateImpl::GetPendingRows
- ATL.IRowsetUpdateImpl.GetPendingRows
- ATL.IRowsetUpdateImpl.GetRowStatus
- IRowsetUpdateImpl::GetRowStatus
- IRowsetUpdateImpl.GetRowStatus
- ATL::IRowsetUpdateImpl::GetRowStatus
- ATL.IRowsetUpdateImpl.Undo
- ATL::IRowsetUpdateImpl::Undo
- IRowsetUpdateImpl::Undo
- IRowsetUpdateImpl.Undo
- ATL::IRowsetUpdateImpl::Update
- IRowsetUpdateImpl::Update
- IRowsetUpdateImpl.Update
- ATL.IRowsetUpdateImpl.Update
- IRowsetUpdateImpl::IsUpdateAllowed
- IRowsetUpdateImpl.IsUpdateAllowed
- IsUpdateAllowed
- IRowsetUpdateImpl.m_mapCachedData
- IRowsetUpdateImpl::m_mapCachedData
- m_mapCachedData
helpviewer_keywords:
- providers, updatable
- IRowsetUpdateImpl class
- updatable providers, deferred update
- SetData method
- GetOriginalData method
- GetPendingRows method
- GetRowStatus method
- Undo method
- Update method
- IsUpdateAllowed method
- m_mapCachedData
ms.assetid: f85af76b-ab6f-4f8b-8f4a-337c9679d68f
ms.openlocfilehash: 6347a42b9065239f768c6b50c430946393358df1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370740"
---
# <a name="irowsetupdateimpl-class"></a>Classe IRowsetUpdateImpl

A implementação do OLE DB Templates da interface [IRowsetUpdate.](/previous-versions/windows/desktop/ms714401(v=vs.85))

## <a name="syntax"></a>Sintaxe

```cpp
template <
   class T,
   class Storage,
   class UpdateArray = CAtlArray<Storage>,
   class RowClass = CSimpleRow,
   class MapClass = CAtlMap <RowClass::KeyType, RowClass*>
>

class IRowsetUpdateImpl : public IRowsetChangeImpl<
   T,
   Storage,
   IRowsetUpdate,
   RowClass,
   MapClass>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetUpdateImpl`.

*Storage*<br/>
O registro do usuário.

*UpdateArray*<br/>
Uma matriz contendo dados armazenados em cache para atualizar o conjunto de linhas.

*Rowclass*<br/>
A unidade de `HROW`armazenamento para o .

*MapClass*<br/>
A unidade de armazenamento para todas as alças de linha mantidas pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)

|||
|-|-|
|[Setdata](#setdata)|Define valores de dados em uma ou mais colunas.|

### <a name="interface-methods-used-with-irowsetupdate"></a>Métodos de interface (usados com iRowsetUpdate)

|||
|-|-|
|[Getoriginaldata](#getoriginaldata)|Obtém os dados mais recentemente transmitidos ou obtidos da fonte de dados, ignorando as alterações pendentes.|
|[GetPendingRows](#getpendingrows)|Retorna uma lista de linhas com alterações pendentes.|
|[Getrowstatus](#getrowstatus)|Retorna o status das linhas especificadas.|
|[Desfazer](#undo)|Desfaz qualquer alteração na linha desde a última busca ou atualização.|
|[Atualizar](#update)|Transmite quaisquer alterações feitas na linha desde a última busca ou atualização.|

### <a name="implementation-methods-callback"></a>Métodos de implementação (Callback)

|||
|-|-|
|[IsUpdateAllowed](#isupdateallowed)|Usado para verificar a segurança, integridade e assim por diante antes de permitir atualizações.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_mapCachedData](#mapcacheddata)|Contém os dados originais da operação diferida.|

## <a name="remarks"></a>Comentários

Você deve primeiro ler e entender a documentação do [IRowsetChange,](/previous-versions/windows/desktop/ms715790(v=vs.85))porque tudo descrito lá também se aplica aqui. Você também deve ler o capítulo 6 da *Referência do Programador OLE DB* sobre a definição de dados.

`IRowsetUpdateImpl`implementa a interface `IRowsetUpdate` OLE DB, que permite aos `IRowsetChange` consumidores retardar a transmissão de alterações feitas com a fonte de dados e desfazer alterações antes da transmissão.

> [!IMPORTANT]
> É recomendável que você leia a seguinte documentação ANTES de tentar implementar seu provedor:

- [Criando um provedor updatable](../../data/oledb/creating-an-updatable-provider.md)

- Capítulo 6 da *Referência do Programador OLE DB*

- Veja também `RUpdateRowset` como a classe é usada na amostra [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)

## <a name="irowsetupdateimplsetdata"></a><a name="setdata"></a>IRowsetUpdateImpl::SetData

Define valores de dados em uma ou mais colunas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (SetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pSrcData);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetChange::SetData](/previous-versions/windows/desktop/ms721232(v=vs.85)) na *referência do programador OLE DB*.

### <a name="remarks"></a>Comentários

Este método substitui o método [IRowsetChangeImpl::SetData,](../../data/oledb/irowsetchangeimpl-setdata.md) mas inclui cache de dados originais para permitir o processamento imediato ou diferido da operação.

## <a name="irowsetupdateimplgetoriginaldata"></a><a name="getoriginaldata"></a>IRowsetUpdateImpl::GetOriginalData

Obtém os dados mais recentemente transmitidos ou obtidos da fonte de dados, ignorando as alterações pendentes.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetOriginalData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pData);
```

#### <a name="parameters"></a>Parâmetros

Consulte [IRowsetUpdate::GetOriginalData](/previous-versions/windows/desktop/ms709947(v=vs.85)) na *referência do programador OLE DB*.

## <a name="irowsetupdateimplgetpendingrows"></a><a name="getpendingrows"></a>IRowsetUpdateImpl::GetPendingRows

Retorna uma lista de linhas com alterações pendentes.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetPendingRows )(HCHAPTER /* hReserved */,
   DBPENDINGSTATUS dwRowStatus,
   DBCOUNTITEM* pcPendingRows,
   HROW** prgPendingRows,
   DBPENDINGSTATUS** prgPendingStatus);
```

#### <a name="parameters"></a>Parâmetros

*hReservado*<br/>
[em] Corresponde ao parâmetro *hChapter* em [IRowsetUpdate::GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate::GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)) in *the OLE DB Programmer's Reference*.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IRowsetUpdate::GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)) in *the OLE DB Programmer's Reference*.

## <a name="irowsetupdateimplgetrowstatus"></a><a name="getrowstatus"></a>IRowsetUpdateImpl::GetRowStatus

Retorna o status das linhas especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowStatus )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBPENDINGSTATUS rgPendingStatus[]);
```

#### <a name="parameters"></a>Parâmetros

*hReservado*<br/>
[em] Corresponde ao parâmetro *hChapter* em [IRowsetUpdate::GetRowStatus](/previous-versions/windows/desktop/ms724377(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate::GetRowStatus](/previous-versions/windows/desktop/ms724377(v=vs.85)) na *referência do programador OLE DB*.

## <a name="irowsetupdateimplundo"></a><a name="undo"></a>IRowsetUpdateImpl::Undo

Desfaz qualquer alteração na linha desde a última busca ou atualização.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Undo )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[ ],
   DBCOUNTITEM* pcRowsUndone,
   HROW** prgRowsUndone,
   DBROWSTATUS** prgRowStatus);
```

#### <a name="parameters"></a>Parâmetros

*hReservado*<br/>
[em] Corresponde ao parâmetro *hChapter* em [IRowsetUpdate::Unfazer](/previous-versions/windows/desktop/ms719655(v=vs.85)).

*pcRowsUndone*<br/>
[fora] Corresponde ao parâmetro *pcRows* em [IRowsetUpdate::Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)).

*prgRowsUndone*<br/>
[em] Corresponde ao parâmetro *prgRows* em [IRowsetUpdate::Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate::Unfazer](/previous-versions/windows/desktop/ms719655(v=vs.85)) in the *OLE DB Programr's Reference*.

## <a name="irowsetupdateimplupdate"></a><a name="update"></a>IRowsetUpdateImpl::Atualização

Transmite quaisquer alterações feitas na linha desde a última busca ou atualização.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Update )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBCOUNTITEM* pcRows,
   HROW** prgRows,
   DBROWSTATUS** prgRowStatus);
```

#### <a name="parameters"></a>Parâmetros

*hReservado*<br/>
[em] Corresponde ao parâmetro *hChapter* em [IRowsetUpdate::Update](/previous-versions/windows/desktop/ms719709(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate::Update](/previous-versions/windows/desktop/ms719709(v=vs.85)) in *the OLE DB Programr's Reference*.

### <a name="remarks"></a>Comentários

As alterações são transmitidas chamando [iRowsetChangeImpl::FlushData](../../data/oledb/irowsetchangeimpl-flushdata.md). O consumidor deve ligar para [CRowset::Atualizar](../../data/oledb/crowset-update.md) para que as alterações entrem em vigor. Defina *prgRowstatus* para um valor apropriado conforme descrito em [Estados de linha](/previous-versions/windows/desktop/ms722752(v=vs.85)) na referência do *programador OLE DB*.

## <a name="irowsetupdateimplisupdateallowed"></a><a name="isupdateallowed"></a>IRowsetUpdateImpl::IsUpdateAllowed

Anule este método para verificar se há segurança, integridade e assim por diante antes das atualizações.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT IsUpdateAllowed(DBPENDINGSTATUS /* [in] */ /* status */,
   HROW /* [in] */ /* hRowUpdate */,
   DBROWSTATUS* /* [out] */ /* pRowStatus */);
```

#### <a name="parameters"></a>Parâmetros

*status*<br/>
[em] O status das operações pendentes nas linhas.

*hRowUpdate*<br/>
[em] Manuseie as linhas que o usuário deseja atualizar.

*pRowStatus*<br/>
[fora] O status voltou para o usuário.

### <a name="remarks"></a>Comentários

Se você determinar que uma atualização deve ser permitida, retorna S_OK; caso contrário, retorna E_FAIL. Se você permitir uma atualização, você `DBROWSTATUS` também precisa definir o [in IRowsetUpdateImpl::Update](../../data/oledb/irowsetupdateimpl-update.md) para um [estado de linha](/previous-versions/windows/desktop/ms722752(v=vs.85))apropriado .

## <a name="irowsetupdateimplm_mapcacheddata"></a><a name="mapcacheddata"></a>IRowsetUpdateImpl::m_mapCachedData

Um mapa contendo os dados originais da operação diferida.

### <a name="syntax"></a>Sintaxe

```cpp
CAtlMap<
   HROW hRow,
   Storage* pData
>
m_mapCachedData;
```

#### <a name="parameters"></a>Parâmetros

*Hrow*<br/>
Manuseie as linhas para os dados.

*Pdata*<br/>
Um ponteiro para os dados a serem armazenados em cache. Os dados são do tipo *Armazenamento* (a classe de registro do usuário). Consulte o argumento do modelo *de armazenamento* em [IRowsetUpdateImpl Class](../../data/oledb/irowsetupdateimpl-class.md).

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura do modelo do provedor OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Criando um provedor updatable](../../data/oledb/creating-an-updatable-provider.md)
