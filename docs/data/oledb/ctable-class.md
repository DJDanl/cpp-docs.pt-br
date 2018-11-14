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
ms.openlocfilehash: 7605d78a140a0f5353a16b9e22d5d618d29ff327
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556673"
---
# <a name="ctable-class"></a>Classe CTable

Fornece um meio para acessar diretamente um conjunto de linhas simple (um sem parâmetros).

## <a name="syntax"></a>Sintaxe

```cpp
template <class TAccessor = CNoAccessor,
            template <typename T> class TRowset = CRowset>
class CTable :
   public CAccessorRowset <TAccessor, TRowset>
```

### <a name="parameters"></a>Parâmetros

*TAccessor*<br/>
Uma classe de acessador.

*TRowset*<br/>
Uma classe de conjunto de linhas.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Abrir](#open)|Abre a tabela.|

## <a name="remarks"></a>Comentários

Ver [CCommand](../../data/oledb/ccommand-class.md) para obter informações sobre como executar um comando para acessar um conjunto de linhas.

## <a name="open"></a> Ctable:: Open

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

#### <a name="parameters"></a>Parâmetros

*Sessão*<br/>
[in] A sessão para o qual a tabela é aberta.

*wszTableName*<br/>
[in] O nome da tabela para abrir, passado como uma cadeia de caracteres Unicode.

*szTableName*<br/>
[in] O nome da tabela para abrir, passado como uma cadeia de caracteres ANSI.

*dbid*<br/>
[in] O `DBID` da tabela para abrir.

*pPropSet*<br/>
[in] Um ponteiro para uma matriz de [DBPROPSET](https://docs.microsoft.com/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](https://docs.microsoft.com/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK. O valor padrão de NULL não especifica que nenhuma propriedade.

*ulPropSets*<br/>
[in] O número de [DBPROPSET](https://docs.microsoft.com/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas passada a *pPropSet* argumento.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais detalhes, consulte [IOpenRowset:: OPENROWSET](https://docs.microsoft.com/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador DB OLE*.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)