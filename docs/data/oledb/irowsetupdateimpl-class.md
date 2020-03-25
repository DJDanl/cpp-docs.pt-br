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
ms.openlocfilehash: 79d85e7d1c849bcaa7c2aa1b3f6d9d50a20d1b2a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210308"
---
# <a name="irowsetupdateimpl-class"></a>Classe IRowsetUpdateImpl

A implementação de modelos de OLE DB da interface [IRowsetUpdate](/previous-versions/windows/desktop/ms714401(v=vs.85)) .

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

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetUpdateImpl`.

*Storage*<br/>
O registro do usuário.

*UpdateArray*<br/>
Uma matriz que contém dados armazenados em cache para atualizar o conjunto de linhas.

*Classe de categoria*<br/>
A unidade de armazenamento para o `HROW`.

*MapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)

|||
|-|-|
|[SetData](#setdata)|Define valores de dados em uma ou mais colunas.|

### <a name="interface-methods-used-with-irowsetupdate"></a>Métodos de interface (usados com IRowsetUpdate)

|||
|-|-|
|[GetOriginalData](#getoriginaldata)|Obtém os dados transmitidos mais recentemente ou obtidos da fonte de dados, ignorando as alterações pendentes.|
|[GetPendingRows](#getpendingrows)|Retorna uma lista de linhas com alterações pendentes.|
|[GetRowStatus](#getrowstatus)|Retorna o status de linhas especificadas.|
|[Desfazer](#undo)|Desfaz qualquer alteração na linha desde a última busca ou atualização.|
|[Atualização](#update)|Transmite todas as alterações feitas na linha desde a última busca ou atualização.|

### <a name="implementation-methods-callback"></a>Métodos de implementação (retorno de chamada)

|||
|-|-|
|[IsUpdateAllowed](#isupdateallowed)|Usado para verificar a segurança, a integridade e assim por diante antes de permitir atualizações.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_mapCachedData](#mapcacheddata)|Contém os dados originais para a operação adiada.|

## <a name="remarks"></a>Comentários

Primeiro, leia e entenda a documentação do [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)), pois tudo o que é descrito aqui também se aplica aqui. Você também deve ler o capítulo 6 da *referência do programador de OLE DB* sobre a definição de dados.

`IRowsetUpdateImpl` implementa a interface de `IRowsetUpdate` de OLE DB, que permite que os consumidores adiem a transmissão de alterações feitas com `IRowsetChange` para a fonte de dados e desfazm alterações antes da transmissão.

> [!IMPORTANT]
>  É altamente recomendável que você leia a seguinte documentação antes de tentar implementar seu provedor:

- [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)

- Capítulo 6 da *referência do programador de OLE DB*

- Veja também como a classe `RUpdateRowset` é usada no exemplo [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV)

## <a name="irowsetupdateimplsetdata"></a><a name="setdata"></a>IRowsetUpdateImpl:: SetData

Define valores de dados em uma ou mais colunas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (SetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pSrcData);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetChange:: SetData](/previous-versions/windows/desktop/ms721232(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Esse método substitui o método [IRowsetChangeImpl:: SetData](../../data/oledb/irowsetchangeimpl-setdata.md) , mas inclui o cache de dados originais para permitir o processamento imediato ou adiado da operação.

## <a name="irowsetupdateimplgetoriginaldata"></a><a name="getoriginaldata"></a>IRowsetUpdateImpl::GetOriginalData

Obtém os dados transmitidos mais recentemente ou obtidos da fonte de dados, ignorando as alterações pendentes.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetOriginalData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pData);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetUpdate:: GetOriginalData](/previous-versions/windows/desktop/ms709947(v=vs.85)) na *referência do programador de OLE DB*.

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

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* em [IRowsetUpdate:: GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate:: GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [IRowsetUpdate:: GetPendingRows](/previous-versions/windows/desktop/ms719626(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetupdateimplgetrowstatus"></a><a name="getrowstatus"></a>IRowsetUpdateImpl::GetRowStatus

Retorna o status de linhas especificadas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowStatus )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBPENDINGSTATUS rgPendingStatus[]);
```

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* em [IRowsetUpdate:: GetRowStatus](/previous-versions/windows/desktop/ms724377(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate:: GetRowStatus](/previous-versions/windows/desktop/ms724377(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetupdateimplundo"></a><a name="undo"></a>IRowsetUpdateImpl:: desfazer

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

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* em [IRowsetUpdate:: Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)).

*pcRowsUndone*<br/>
fora Corresponde ao parâmetro *pcRows* em [IRowsetUpdate:: Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)).

*prgRowsUndone*<br/>
no Corresponde ao parâmetro *prgRows* em [IRowsetUpdate:: Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate:: Undo](/previous-versions/windows/desktop/ms719655(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetupdateimplupdate"></a><a name="update"></a>IRowsetUpdateImpl:: atualizar

Transmite todas as alterações feitas na linha desde a última busca ou atualização.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Update )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBCOUNTITEM* pcRows,
   HROW** prgRows,
   DBROWSTATUS** prgRowStatus);
```

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* em [IRowsetUpdate:: Update](/previous-versions/windows/desktop/ms719709(v=vs.85)).

Para outros parâmetros, consulte [IRowsetUpdate:: Update](/previous-versions/windows/desktop/ms719709(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

As alterações são transmitidas chamando [IRowsetChangeImpl:: FlushData](../../data/oledb/irowsetchangeimpl-flushdata.md). O consumidor deve chamar [CRowset:: Update](../../data/oledb/crowset-update.md) para que as alterações entrem em vigor. Defina *prgRowstatus* como um valor apropriado, conforme descrito em [Estados de linha](/previous-versions/windows/desktop/ms722752(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetupdateimplisupdateallowed"></a><a name="isupdateallowed"></a>IRowsetUpdateImpl::IsUpdateAllowed

Substitua esse método para verificar a segurança, a integridade e assim por diante antes das atualizações.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT IsUpdateAllowed(DBPENDINGSTATUS /* [in] */ /* status */,
   HROW /* [in] */ /* hRowUpdate */,
   DBROWSTATUS* /* [out] */ /* pRowStatus */);
```

#### <a name="parameters"></a>parâmetros

*status*<br/>
no O status das operações pendentes nas linhas.

*hRowUpdate*<br/>
no Identificador para as linhas que o usuário deseja atualizar.

*pRowStatus*<br/>
fora O status retornado ao usuário.

### <a name="remarks"></a>Comentários

Se você determinar que uma atualização deve ser permitida, o retornará S_OK; caso contrário, retorna E_FAIL. Se você permitir uma atualização, também precisará definir o `DBROWSTATUS` em [IRowsetUpdateImpl:: Update](../../data/oledb/irowsetupdateimpl-update.md) para um estado de [linha](/previous-versions/windows/desktop/ms722752(v=vs.85))apropriado.

## <a name="irowsetupdateimplm_mapcacheddata"></a><a name="mapcacheddata"></a>IRowsetUpdateImpl:: m_mapCachedData

Um mapa que contém os dados originais para a operação adiada.

### <a name="syntax"></a>Sintaxe

```cpp
CAtlMap<
   HROW hRow,
   Storage* pData
>
m_mapCachedData;
```

#### <a name="parameters"></a>parâmetros

*hRow*<br/>
Identificador para as linhas dos dados.

*pData*<br/>
Um ponteiro para os dados a serem armazenados em cache. Os dados são do tipo *armazenamento* (a classe de registro de usuário). Consulte o argumento de modelo de *armazenamento* na [classe IRowsetUpdateImpl](../../data/oledb/irowsetupdateimpl-class.md).

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)
