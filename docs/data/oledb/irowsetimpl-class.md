---
title: Classe IRowsetImpl
ms.date: 11/04/2016
f1_keywords:
- IRowsetImpl
- IRowsetImpl::AddRefRows
- IRowsetImpl.AddRefRows
- ATL::IRowsetImpl::AddRefRows
- ATL.IRowsetImpl.AddRefRows
- IRowsetImpl.CreateRow
- ATL.IRowsetImpl.CreateRow
- ATL::IRowsetImpl::CreateRow
- CreateRow
- IRowsetImpl::CreateRow
- ATL.IRowsetImpl.GetData
- ATL::IRowsetImpl::GetData
- IRowsetImpl::GetData
- IRowsetImpl.GetData
- GetDBStatus
- IRowsetImpl.GetDBStatus
- IRowsetImpl::GetDBStatus
- GetNextRows
- ATL.IRowsetImpl.GetNextRows
- ATL::IRowsetImpl::GetNextRows
- IRowsetImpl::GetNextRows
- IRowsetImpl.GetNextRows
- IRowsetImpl.IRowsetImpl
- ATL::IRowsetImpl::IRowsetImpl
- ATL.IRowsetImpl.IRowsetImpl
- IRowsetImpl::IRowsetImpl
- ATL::IRowsetImpl::RefRows
- ATL.IRowsetImpl.RefRows
- IRowsetImpl.RefRows
- RefRows
- IRowsetImpl::RefRows
- ATL.IRowsetImpl.ReleaseRows
- IRowsetImpl::ReleaseRows
- ATL::IRowsetImpl::ReleaseRows
- IRowsetImpl.ReleaseRows
- ATL.IRowsetImpl.RestartPosition
- IRowsetImpl::RestartPosition
- RestartPosition
- ATL::IRowsetImpl::RestartPosition
- IRowsetImpl.RestartPosition
- IRowsetImpl.SetDBStatus
- IRowsetImpl::SetDBStatus
- SetDBStatus
- ATL.IRowsetImpl.m_bCanFetchBack
- ATL::IRowsetImpl::m_bCanFetchBack
- IRowsetImpl.m_bCanFetchBack
- IRowsetImpl::m_bCanFetchBack
- m_bCanFetchBack
- IRowsetImpl::m_bCanScrollBack
- ATL::IRowsetImpl::m_bCanScrollBack
- IRowsetImpl.m_bCanScrollBack
- ATL.IRowsetImpl.m_bCanScrollBack
- m_bCanScrollBack
- ATL.IRowsetImpl.m_bReset
- IRowsetImpl.m_bReset
- m_bReset
- IRowsetImpl::m_bReset
- ATL::IRowsetImpl::m_bReset
- IRowsetImpl::m_iRowset
- IRowsetImpl.m_iRowset
- ATL::IRowsetImpl::m_iRowset
- ATL.IRowsetImpl.m_iRowset
- m_iRowset
- IRowsetImpl::m_rgRowHandles
- IRowsetImpl.m_rgRowHandles
- m_rgRowHandles
- ATL::IRowsetImpl::m_rgRowHandles
- ATL.IRowsetImpl.m_rgRowHandles
helpviewer_keywords:
- IRowsetImpl class
- AddRefRows method
- CreateRow method
- GetData method [OLE DB]
- GetDBStatus method
- GetNextRows method
- IRowsetImpl constructor
- RefRows method
- ReleaseRows method
- RestartPosition method
- SetDBStatus method
- m_bCanFetchBack
- m_bCanScrollBack
- m_bReset
- m_iRowset
- m_rgRowHandles
ms.assetid: 6a9189af-7556-45b1-adcb-9d62bb36704c
ms.openlocfilehash: db12af1aecc094e6c04ab37b5a70a0acd97e39e9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80210404"
---
# <a name="irowsetimpl-class"></a>Classe IRowsetImpl

Fornece uma implementação da interface `IRowset`.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   class T,
   class RowsetInterface,
   class RowClass = CSimpleRow,
   class MapClass = CAtlMap <
      RowClass::KeyType,
      RowClass*>>
class ATL_NO_VTABLE IRowsetImpl : public RowsetInterface
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `IRowsetImpl`.

*RowsetInterface*<br/>
Uma classe derivada de `IRowsetImpl`.

*Classe de categoria*<br/>
Unidade de armazenamento para o `HROW`.

*MapClass*<br/>
Unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddRefRows](#addrefrows)|Adiciona uma contagem de referência em um identificador de linha existente.|
|[CreateRow](#createrow)|Chamado por [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) para alocar um novo `HROW`. Não chamado diretamente pelo usuário.|
|[GetData](#getdata)|Recupera dados da cópia do conjunto de linhas da linha.|
|[GetDBStatus](#getdbstatus)|Retorna o status do campo especificado.|
|[GetNextRows](#getnextrows)|Busca linhas sequencialmente, lembrando da posição anterior.|
|[IRowsetImpl](#irowsetimpl)|O construtor. Não chamado diretamente pelo usuário.|
|[RefRows](#refrows)|Chamado por [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e [ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md). Não chamado diretamente pelo usuário.|
|[ReleaseRows](#releaserows)|Libera linhas.|
|[RestartPosition](#restartposition)|Reposiciona a próxima posição de busca em sua posição inicial; ou seja, sua posição quando o conjunto de linhas foi criado pela primeira vez.|
|[SetDBStatus](#setdbstatus)|Define os sinalizadores de status para o campo especificado.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[m_bCanFetchBack](#bcanfetchback)|Indica se um provedor dá suporte à busca retroativa.|
|[m_bCanScrollBack](#bcanscrollback)|Indica se um provedor pode fazer com que o cursor faça a rolagem para trás.|
|[m_bReset](#breset)|Indica se um provedor redefiniu a posição do cursor. Isso tem um significado especial ao rolar para trás ou buscar para trás em [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md).|
|[m_iRowset](#irowset)|Um índice para o conjunto de linhas que representa o cursor.|
|[m_rgRowHandles](#rgrowhandles)|Uma lista de identificadores de linha.|

## <a name="remarks"></a>Comentários

[IRowset](/previous-versions/windows/desktop/ms720986(v=vs.85)) é a interface base do conjunto de linhas.

## <a name="irowsetimpladdrefrows"></a><a name="addrefrows"></a>IRowsetImpl::AddRefRows

Adiciona uma contagem de referência em um identificador de linha existente.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(AddRefRows )(DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBREFCOUNT rgRefCounts[],
   DBROWSTATUS rgRowStatus[]);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: AddRefRows](/previous-versions/windows/desktop/ms719619(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetimplcreaterow"></a><a name="createrow"></a>IRowsetImpl::CreateRow

Um método auxiliar chamado por [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) para alocar um novo `HROW`.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CreateRow(DBROWOFFSET lRowsOffset,
   DBCOUNTITEM& cRowsObtained,
   HROW* rgRows);
```

#### <a name="parameters"></a>parâmetros

*lRowsOffset*<br/>
Posição do cursor da linha que está sendo criada.

*cRowsObtained*<br/>
Uma referência passada de volta para o usuário indicando o número de linhas criadas.

*rgRows*<br/>
Uma matriz de `HROW`s retornada ao chamador com os identificadores de linha recém-criados.

### <a name="remarks"></a>Comentários

Se a linha existir, esse método chamará [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e retornará. Caso contrário, ele aloca uma nova instância da variável de modelo de classe e a adiciona ao [m_rgRowHandles](../../data/oledb/irowsetimpl-m-rgrowhandles.md).

## <a name="irowsetimplgetdata"></a><a name="getdata"></a>IRowsetImpl:: GetData

Recupera dados da cópia do conjunto de linhas da linha.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pDstData);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: GetData](/previous-versions/windows/desktop/ms716988(v=vs.85)) na *referência do programador de OLE DB*.

Alguns parâmetros correspondem a parâmetros de *referência do programador OLE DB* de nomes diferentes, que são descritos em `IRowset::GetData`:

|OLE DB parâmetros de modelo|Parâmetros *de referência do programador de OLE DB*|
|--------------------------------|------------------------------------------------|
|*pDstData*|*pData*|

### <a name="remarks"></a>Comentários

Também manipula a conversão de dados usando a DLL de conversão de dados OLE DB.

## <a name="irowsetimplgetdbstatus"></a><a name="getdbstatus"></a>IRowsetImpl::GetDBStatus

Retorna os sinalizadores de status DBSTATUS para o campo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual DBSTATUS GetDBStatus(RowClass* currentRow,
   ATLCOLUMNINFO* columnNames);
```

#### <a name="parameters"></a>parâmetros

*currentRow*<br/>
no A linha atual.

*columnNames*<br/>
no A coluna para a qual o status está sendo solicitado.

### <a name="return-value"></a>Valor retornado

Os sinalizadores [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) para a coluna.

## <a name="irowsetimplgetnextrows"></a><a name="getnextrows"></a>IRowsetImpl:: GetNextRows

Busca linhas sequencialmente, lembrando da posição anterior.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(GetNextRows )(HCHAPTER hReserved,
   DBROWOFFSET lRowsOffset,
   DBROWCOUNT cRows,
   DBCOUNTITEM* pcRowsObtained,
   HROW** prghRows);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: GetNextRows](/previous-versions/windows/desktop/ms709827(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetimplirowsetimpl"></a><a name="irowsetimpl"></a>IRowsetImpl::IRowsetImpl

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
IRowsetImpl();
```

### <a name="remarks"></a>Comentários

Normalmente, você não precisa chamar esse método diretamente.

## <a name="irowsetimplrefrows"></a><a name="refrows"></a>IRowsetImpl::RefRows

Chamado por [AddRefRows](../../data/oledb/irowsetimpl-addrefrows.md) e [ReleaseRows](../../data/oledb/irowsetimpl-releaserows.md) para incrementar ou liberar uma contagem de referência para um identificador de linha existente.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT RefRows(DBCOUNTITEM cRows,
   const HROWrghRows[],
   DBREFCOUNT rgRefCounts[],
   DBROWSTATUS rgRowStatus[],
   BOOL bAdd);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: AddRefRows](/previous-versions/windows/desktop/ms719619(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="irowsetimplreleaserows"></a><a name="releaserows"></a>IRowsetImpl:: ReleaseRows

Libera linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(ReleaseRows )(DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBROWOPTIONS rgRowOptions[],
   DBREFCOUNT rgRefCounts[],
   DBROWSTATUS rgRowStatus[]);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: ReleaseRows](/previous-versions/windows/desktop/ms719771(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetimplrestartposition"></a><a name="restartposition"></a>IRowsetImpl:: RestartPosition

Reposiciona a próxima posição de busca em sua posição inicial; ou seja, sua posição quando o conjunto de linhas foi criado pela primeira vez.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(RestartPosition )(HCHAPTER /* hReserved */);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowset:: RestartPosition](/previous-versions/windows/desktop/ms712877(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

A posição do conjunto de linhas é indefinida até que `GetNextRow` seja chamado. Você pode mover para trás em um rowet chamando `RestartPosition` e, em seguida, buscando ou rolando para trás.

## <a name="irowsetimplsetdbstatus"></a><a name="setdbstatus"></a>IRowsetImpl::SetDBStatus

Define os sinalizadores de status de DBSTATUS para o campo especificado.

### <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT SetDBStatus(DBSTATUS* statusFlags,
   RowClass* currentRow,
   ATLCOLUMNINFO* columnInfo);
```

#### <a name="parameters"></a>parâmetros

*statusFlags*<br/>
Os sinalizadores [DBSTATUS](/previous-versions/windows/desktop/ms722617(v=vs.85)) a serem definidos para a coluna.

*currentRow*<br/>
A linha atual.

*columnInfo*<br/>
A coluna para a qual o status está sendo definido.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

O provedor substitui essa função para fornecer processamento especial para DBSTATUS_S_ISNULL e DBSTATUS_S_DEFAULT.

## <a name="irowsetimplm_bcanfetchback"></a><a name="bcanfetchback"></a>IRowsetImpl:: m_bCanFetchBack

Indica se um provedor dá suporte à busca retroativa.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned m_bCanFetchBack:1;
```

### <a name="remarks"></a>Comentários

Vinculado à propriedade `DBPROP_CANFETCHBACKWARDS` no grupo de `DBPROPSET_ROWSET`. O provedor deve dar suporte a `DBPROP_CANFETCHBACKWARDS` para que `m_bCanFetchBackwards` seja **verdadeiro**.

## <a name="irowsetimplm_bcanscrollback"></a><a name="bcanscrollback"></a>IRowsetImpl:: m_bCanScrollBack

Indica se um provedor pode fazer com que o cursor faça a rolagem para trás.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned  m_bCanScrollBack:1;
```

### <a name="remarks"></a>Comentários

Vinculado à propriedade `DBPROP_CANSCROLLBACKWARDS` no grupo de `DBPROPSET_ROWSET`. O provedor deve dar suporte a `DBPROP_CANSCROLLBACKWARDS` para que `m_bCanFetchBackwards` seja **verdadeiro**.

## <a name="irowsetimplm_breset"></a><a name="breset"></a>IRowsetImpl:: m_bReset

Um sinalizador de bit usado para determinar se a posição do cursor está definida no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned m_bReset:1;
```

### <a name="remarks"></a>Comentários

Se o consumidor chamar [GetNextRows](../../data/oledb/irowsetimpl-getnextrows.md) com um `lOffset` negativo ou *galinha* e `m_bReset` for true, `GetNextRows` será movido para o final do conjunto de linhas. Se `m_bReset` for false, o consumidor receberá um código de erro, em conformidade com a especificação de OLE DB. O sinalizador `m_bReset` é definido como **true** quando o conjunto de linhas é criado pela primeira vez e quando o consumidor chama [IRowsetImpl:: RestartPosition](../../data/oledb/irowsetimpl-restartposition.md). Ele é definido como **false** quando você chama `GetNextRows`.

## <a name="irowsetimplm_irowset"></a><a name="irowset"></a>IRowsetImpl:: m_iRowset

Um índice para o conjunto de linhas que representa o cursor.

### <a name="syntax"></a>Sintaxe

```cpp
DBROWOFFSET m_iRowset;
```

## <a name="irowsetimplm_rgrowhandles"></a><a name="rgrowhandles"></a>IRowsetImpl:: m_rgRowHandles

Um mapa de identificadores de linha atualmente contidos pelo provedor em resposta a `GetNextRows`.

### <a name="syntax"></a>Sintaxe

```cpp
MapClass m_rgRowHandles;
```

### <a name="remarks"></a>Comentários

Os identificadores de linha são removidos chamando `ReleaseRows`. Consulte a [visão geral de IRowsetImpl](../../data/oledb/irowsetimpl-class.md) para a definição de *MapClass*.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[Classe CSimpleRow](../../data/oledb/csimplerow-class.md)
