---
title: Classe IRowsetLocateImpl
ms.date: 11/04/2016
f1_keywords:
- IRowsetLocateImpl
- ATL.IRowsetLocateImpl.Compare
- IRowsetLocateImpl::Compare
- IRowsetLocateImpl.Compare
- ATL::IRowsetLocateImpl::Compare
- GetRowsAt
- IRowsetLocateImpl.GetRowsAt
- ATL::IRowsetLocateImpl::GetRowsAt
- IRowsetLocateImpl::GetRowsAt
- ATL.IRowsetLocateImpl.GetRowsAt
- IRowsetLocateImpl::GetRowsByBookmark
- IRowsetLocateImpl.GetRowsByBookmark
- GetRowsByBookmark
- IRowsetLocateImpl::Hash
- IRowsetLocateImpl.Hash
- m_rgBookmarks
- IRowsetLocateImpl::m_rgBookmarks
- ATL.IRowsetLocateImpl.m_rgBookmarks
- ATL::IRowsetLocateImpl::m_rgBookmarks
- IRowsetLocateImpl.m_rgBookmarks
helpviewer_keywords:
- providers, bookmarks
- IRowsetLocateImpl class
- bookmarks, OLE DB
- Compare method
- GetRowsAt method
- GetRowsByBookmark method
- Hash method
- m_rgbookmarks
ms.assetid: a8aa3149-7ce8-4976-a680-2da193fd3234
ms.openlocfilehash: e3513084697a60a33b9fa2ab02222a9b332cce79
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59039813"
---
# <a name="irowsetlocateimpl-class"></a>Classe IRowsetLocateImpl

Implementa o OLE DB [IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85)) interface, que busca linhas arbitrárias em um conjunto de linhas.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   class T,
   class RowsetInterface,
   class RowClass = CSimpleRow,
   class MapClass = CAtlMap < RowClass::KeyType, RowClass* >,
   class BookmarkKeyType = LONG,
   class BookmarkType = LONG,
   class BookmarkMapClass = CAtlMap < RowClass::KeyType, RowClass* >>
class ATL_NO_VTABLE IRowsetLocateImpl : public IRowsetImpl<
       T,
       RowsetInterface,
       RowClass,
       MapClass>
```

### <a name="parameters"></a>Parâmetros

*T*<br/>
Uma classe derivada de `IRowsetLocateImpl`.

*RowsetInterface*<br/>
Uma classe derivada de `IRowsetImpl`.

*RowClass*<br/>
A unidade de armazenamento para o `HROW`.

*MapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

*BookmarkKeyType*<br/>
O tipo de indicador, como um longo período ou uma cadeia de caracteres. Indicadores comuns devem ter um comprimento de pelo menos dois bytes. (Comprimento de byte único é reservado para o banco de dados OLE [indicadores padrão](/previous-versions/windows/desktop/ms712954(v=vs.85))`DBBMK_FIRST`, `DBBMK_LAST`, e `DBBMK_INVALID`.)

*BookmarkType*<br/>
O mecanismo de mapeamento para manter as relações de dados de indicador.

*BookmarkMapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo indicador.

## <a name="requirements"></a>Requisitos

**Header**: atldb.h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

|||
|-|-|
|[Comparar](#compare)|Compara dois indicadores.|
|[GetRowsAt](#getrowsat)|Busca linhas começando com a linha especificada por um deslocamento de um indicador.|
|[GetRowsByBookmark](#getrowsbybookmark)|Busque as linhas que correspondem aos indicadores especificados.|
|[Hash](#hash)|Retorna o hash valores para os indicadores especificados.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[m_rgBookmarks](#rgbookmarks)|Uma matriz de indicadores.|

## <a name="remarks"></a>Comentários

`IRowsetLocateImpl` é a implementação de modelos OLE DB do [IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85)) interface. `IRowsetLocate` é usado para buscar linhas arbitrárias em um conjunto de linhas. Um conjunto de linhas que não implementa essa interface é um `sequential` conjunto de linhas. Quando `IRowsetLocate` está presente em um conjunto de linhas, a coluna 0 é o indicador das linhas; lendo esta coluna irá obter um valor de indicador que pode ser usado para reposicionar na mesma linha.

`IRowsetLocateImpl` é usado para implementar o suporte a indicadores em provedores. Os indicadores são espaços reservados (índices de um conjunto de linhas) que permitem que o consumidor retornar rapidamente a uma linha, permitindo o acesso aos dados de alta velocidade. O provedor determina o que é podem indicadores exclusivamente identificar uma linha. Usando `IRowsetLocateImpl` métodos, você pode comparar os indicadores, linhas de busca por deslocarem, em busca de linhas por indicador e retornam valores de hash de indicadores.

Para dar suporte a indicadores de OLE DB em um conjunto de linhas, verifique o conjunto de linhas herdam dessa classe.

Para obter informações sobre como implementar o suporte a indicadores, consulte [provedor oferecer suporte a indicadores](../../data/oledb/provider-support-for-bookmarks.md) na *guia do programador do Visual C++* e [indicadores](/previous-versions/windows/desktop/ms709728(v=vs.85)) no *Referência do programador do OLE DB* na plataforma do SDK.

## <a name="compare"></a> IRowsetLocateImpl::Compare

Compara dois indicadores.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Compare )(HCHAPTER /* hReserved */,
   DBBKMARK cbBookmark1,
   const BYTE* pBookmark1,
   DBBKMARK cbBookmark2,
   const BYTE* pBookmark2,
   DBCOMPARE* pComparison);
```

#### <a name="parameters"></a>Parâmetros

Ver [IRowsetLocate::Compare](/previous-versions/windows/desktop/ms709539(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Qualquer um dos indicadores podem ser um padrão definido pelo OLE DB [indicador padrão](/previous-versions/windows/desktop/ms712954(v=vs.85)) (`DBBMK_FIRST`, `DBBMK_LAST`, ou `DBBMK_INVALID`). O valor retornado na `pComparison` indica a relação entre os dois indicadores:

- DBCOMPARE_LT (`cbBookmark1` está antes `cbBookmark2`.)

- DBCOMPARE_EQ (`cbBookmark1` é igual a `cbBookmark2`.)

- DBCOMPARE_GT (`cbBookmark1` após `cbBookmark2`.)

- DBCOMPARE_NE (os indicadores são iguais e não ordenados).

- DBCOMPARE_NOTCOMPARABLE (não não possível comparar os indicadores.)

## <a name="getrowsat"></a> IRowsetLocateImpl::GetRowsAt

Busca linhas começando com a linha especificada por um deslocamento de um indicador.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowsAt )(HWATCHREGION /* hReserved1 */,
   HCHAPTER hReserved2,
   DBBKMARK cbBookmark,
   const BYTE* pBookmark,
   DBROWOFFSET lRowsOffset,
   DBROWCOUNT cRows,
   DBCOUNTITEM* pcRowsObtained,
   HROW** prghRows);
```

#### <a name="parameters"></a>Parâmetros

Ver [irowsetlocate:: Getrowsat](/previous-versions/windows/desktop/ms723031(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="remarks"></a>Comentários

Para buscar da posição do cursor, em vez disso, use [IRowset::GetRowsAt](/previous-versions/windows/desktop/ms723031(v=vs.85)).

`IRowsetLocateImpl::GetRowsAt` não altera a posição do cursor.

## <a name="getrowsbybookmark"></a> IRowsetLocateImpl::GetRowsByBookmark

Busca de uma ou mais linhas que correspondem aos indicadores especificados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowsByBookmark )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const DBBKMARK rgcbBookmarks[],
   const BYTE* rgpBookmarks,
   HROW rghRows[],
   DBROWSTATUS* rgRowStatus[]);
```

#### <a name="parameters"></a>Parâmetros

*hReserved*<br/>
[in] Corresponde ao *hChapter* parâmetro [irowsetlocate:: Getrowsbybookmark](/previous-versions/windows/desktop/ms725420(v=vs.85)).

Para outros parâmetros, consulte [irowsetlocate:: Getrowsbybookmark](/previous-versions/windows/desktop/ms725420(v=vs.85)) na *referência do programador DB OLE*.

### <a name="remarks"></a>Comentários

O indicador pode ser um valor que você define ou OLE DB [indicadores padrão](/previous-versions/windows/desktop/ms712954(v=vs.85)) (`DBBMK_FIRST` ou `DBBMK_LAST`). não altera a posição do cursor.

## <a name="hash"></a> IRowsetLocateImpl::Hash

Retorna o hash valores para os indicadores especificados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Hash )(HCHAPTER /* hReserved */,
   DBBKMARK cbBookmarks,
   const DBBKMARK* rgcbBookmarks[],
   const BYTE* rgpBookmarks[],
   DBHASHVALUE rgHashValues[],
   DBROWSTATUS rgBookmarkStatus[]);
```

#### <a name="parameters"></a>Parâmetros

*hReserved*<br/>
[in] Corresponde ao *hChapter* parâmetro [IRowsetLocate::Hash](/previous-versions/windows/desktop/ms709697(v=vs.85)).

Para outros parâmetros, consulte [IRowsetLocate::Hash](/previous-versions/windows/desktop/ms709697(v=vs.85)) na *referência do programador DB OLE*.

## <a name="rgbookmarks"></a> IRowsetLocateImpl::m_rgBookmarks

Uma matriz de indicadores.

### <a name="syntax"></a>Sintaxe

```cpp
CAtlArray<DBROWCOUNT> m_rgBookmarks;
```

## <a name="see-also"></a>Consulte também

[Modelos de provedor de banco de dados OLE](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[IRowsetLocate:IRowset](/previous-versions/windows/desktop/ms721190(v=vs.85))
[suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)<br/>
[Indicadores](/previous-versions/windows/desktop/ms709728(v=vs.85))