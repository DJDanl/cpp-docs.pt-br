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
ms.openlocfilehash: a45b7ef1a31c3ecf34b15ee35bce48559465a905
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840304"
---
# <a name="irowsetlocateimpl-class"></a>Classe IRowsetLocateImpl

Implementa a interface OLE DB [IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85)) , que busca linhas arbitrárias de um conjunto de linhas.

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

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetLocateImpl` .

*RowsetInterface*<br/>
Uma classe derivada de `IRowsetImpl` .

*Classe de categoria*<br/>
A unidade de armazenamento para o `HROW` .

*MapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

*BookmarkKeyType*<br/>
O tipo do indicador, como um longo ou uma cadeia de caracteres. Indicadores comuns devem ter um comprimento de pelo menos dois bytes. (O comprimento de byte único é reservado para os [indicadores padrão](/previous-versions/windows/desktop/ms712954(v=vs.85))de OLE DB `DBBMK_FIRST` , `DBBMK_LAST` e `DBBMK_INVALID` .)

*Bookmarktype*<br/>
O mecanismo de mapeamento para manter relações de indicador para dados.

*BookmarkMapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo indicador.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods"></a>Métodos de interface

| Nome | Descrição |
|-|-|
|[Comparar](#compare)|Compara dois indicadores.|
|[GetRowsAt](#getrowsat)|Busca linhas começando com a linha especificada por um deslocamento de um indicador.|
|[GetRowsByBookmark](#getrowsbybookmark)|Busca as linhas que correspondem aos indicadores especificados.|
|[Hash](#hash)|Retorna valores de hash para os indicadores especificados.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_rgBookmarks](#rgbookmarks)|Uma matriz de indicadores.|

## <a name="remarks"></a>Comentários

`IRowsetLocateImpl` é a implementação de modelos de OLE DB da interface [IRowsetLocate](/previous-versions/windows/desktop/ms721190(v=vs.85)) . `IRowsetLocate` é usado para buscar linhas arbitrárias de um conjunto de linhas. Um conjunto de linhas que não implementa essa interface é um `sequential` conjunto de linhas. Quando o `IRowsetLocate` estiver presente em um conjunto de linhas, a coluna 0 será o indicador das linhas; a leitura desta coluna obterá um valor de indicador que pode ser usado para reposicionar a mesma linha.

`IRowsetLocateImpl` é usado para implementar o suporte a indicadores em provedores. Indicadores são espaços reservados (índices em um conjunto de linhas) que permitem que o consumidor retorne rapidamente a uma linha, permitindo acesso de alta velocidade aos dados. O provedor determina quais indicadores podem identificar uma linha exclusivamente. Usando `IRowsetLocateImpl` métodos, você pode comparar indicadores, buscar linhas por deslocamento, buscar linhas por indicador e retornar valores de hash para indicadores.

Para dar suporte a OLE DB indicadores em um conjunto de linhas, faça com que o conjunto de linhas herde dessa classe.

Para obter informações sobre como implementar o suporte a indicadores, consulte [suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md) no *Guia do programador de Visual C++* e [indicadores](/previous-versions/windows/desktop/ms709728(v=vs.85)) na *referência do programador de OLE DB* no SDK da plataforma.

## <a name="irowsetlocateimplcompare"></a><a name="compare"></a> IRowsetLocateImpl:: Compare

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

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetLocate:: Compare](/previous-versions/windows/desktop/ms709539(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Qualquer um dos indicadores pode ser um [indicador padrão](/previous-versions/windows/desktop/ms712954(v=vs.85)) definido por OLE DB padrão ( `DBBMK_FIRST` , `DBBMK_LAST` ou `DBBMK_INVALID` ). O valor retornado em `pComparison` indica a relação entre os dois indicadores:

- DBCOMPARE_LT ( `cbBookmark1` está antes de `cbBookmark2` .)

- DBCOMPARE_EQ ( `cbBookmark1` é igual a `cbBookmark2` .)

- DBCOMPARE_GT ( `cbBookmark1` é posterior `cbBookmark2` .)

- DBCOMPARE_NE (os indicadores são iguais e não são ordenados.)

- DBCOMPARE_NOTCOMPARABLE (os indicadores não podem ser comparados.)

## <a name="irowsetlocateimplgetrowsat"></a><a name="getrowsat"></a> IRowsetLocateImpl:: GetRowsAt

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

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetLocate:: GetRowsAt](/previous-versions/windows/desktop/ms723031(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Para obter a posição do cursor em vez disso, use [IRowset:: GetRowsAt](/previous-versions/windows/desktop/ms723031(v=vs.85)).

`IRowsetLocateImpl::GetRowsAt` Não altera a posição do cursor.

## <a name="irowsetlocateimplgetrowsbybookmark"></a><a name="getrowsbybookmark"></a> IRowsetLocateImpl::GetRowsByBookmark

Busca uma ou mais linhas que correspondam aos indicadores especificados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetRowsByBookmark )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const DBBKMARK rgcbBookmarks[],
   const BYTE* rgpBookmarks,
   HROW rghRows[],
   DBROWSTATUS* rgRowStatus[]);
```

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* para [IRowsetLocate:: GetRowsByBookmark](/previous-versions/windows/desktop/ms725420(v=vs.85)).

Para outros parâmetros, consulte [IRowsetLocate:: GetRowsByBookmark](/previous-versions/windows/desktop/ms725420(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

O indicador pode ser um valor que você define ou um OLE DB [indicadores padrão](/previous-versions/windows/desktop/ms712954(v=vs.85)) ( `DBBMK_FIRST` ou `DBBMK_LAST` ). Não altera a posição do cursor.

## <a name="irowsetlocateimplhash"></a><a name="hash"></a> IRowsetLocateImpl:: hash

Retorna valores de hash para os indicadores especificados.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (Hash )(HCHAPTER /* hReserved */,
   DBBKMARK cbBookmarks,
   const DBBKMARK* rgcbBookmarks[],
   const BYTE* rgpBookmarks[],
   DBHASHVALUE rgHashValues[],
   DBROWSTATUS rgBookmarkStatus[]);
```

#### <a name="parameters"></a>parâmetros

*hReserved*<br/>
no Corresponde ao parâmetro *hChapter* para [IRowsetLocate:: hash](/previous-versions/windows/desktop/ms709697(v=vs.85)).

Para outros parâmetros, consulte [IRowsetLocate:: hash](/previous-versions/windows/desktop/ms709697(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetlocateimplm_rgbookmarks"></a><a name="rgbookmarks"></a> IRowsetLocateImpl:: m_rgBookmarks

Uma matriz de indicadores.

### <a name="syntax"></a>Sintaxe

```cpp
CAtlArray<DBROWCOUNT> m_rgBookmarks;
```

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
[IRowsetLocate: IRowset](/previous-versions/windows/desktop/ms721190(v=vs.85)) 
 [Suporte do provedor para indicadores](../../data/oledb/provider-support-for-bookmarks.md)<br/>
[Indicadores](/previous-versions/windows/desktop/ms709728(v=vs.85))
