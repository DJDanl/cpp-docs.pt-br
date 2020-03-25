---
title: Classe CTable
ms.date: 11/04/2016
f1_keywords:
- ATL::CTable
- ATL.CTable
- CTable
- ATL.CTable.Open
- ATL::CTable::Open
- CTable::Open
- CTable.Open
helpviewer_keywords:
- CTable class
- Open method
ms.assetid: f13fdaa3-e198-4557-977d-54b0bbc3454d
ms.openlocfilehash: 47c9899889bbbf9b09300779691085786db0e088
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211140"
---
# <a name="ctable-class"></a>Classe CTable

Fornece um meio de acessar diretamente um conjunto de linhas simples (um sem parâmetros).

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,
            template <typename T> class TRowset = CRowset>
class CTable :
   public CAccessorRowset <TAccessor, TRowset>
```

### <a name="parameters"></a>parâmetros

*TAccessor*<br/>
Uma classe de acessador.

*TRowset*<br/>
Uma classe de conjunto de linhas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Abrir](#open)|Abre a tabela.|

## <a name="remarks"></a>Comentários

Consulte [CCommand](../../data/oledb/ccommand-class.md) para obter informações sobre como executar um comando para acessar um conjunto de linhas.

## <a name="ctableopen"></a><a name="open"></a>CTable:: abrir

Abre a tabela.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CSession& session,
   LPCWSTR wszTableName,
   DBPROPSET* pPropSet = NULL,
   ULONG ulPropSets = 0) throw ();

HRESULT Open(const CSession& session,
   LPCSTR szTableName,
   DBPROPSET* pPropSet = NULL,
   ULONG ulPropSets = 0) throw ();

HRESULT Open(const CSession& session,
   DBID& dbid,
   DBPROPSET* pPropSet = NULL,
   ULONG ulPropSets = 0) throw ();
```

#### <a name="parameters"></a>parâmetros

*sessão*<br/>
no A sessão para a qual a tabela está aberta.

*wszTableName*<br/>
no O nome da tabela a ser aberta, passada como uma cadeia de caracteres Unicode.

*szTableName*<br/>
no O nome da tabela a ser aberta, passada como uma cadeia de caracteres ANSI.

*dbid*<br/>
no A `DBID` da tabela a ser aberta.

*pPropSet*<br/>
no Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que contém propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows. O valor padrão de NULL não especifica nenhuma propriedade.

*ulPropSets*<br/>
no O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passadas no argumento *pPropSet* .

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais detalhes, consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Confira também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
