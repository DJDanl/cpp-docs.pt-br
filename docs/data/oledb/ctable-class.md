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
ms.openlocfilehash: fab1ba2e496f4945eb56c0a67b833f6bf063404e
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59038756"
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

*DBID*<br/>
[in] O `DBID` da tabela para abrir.

*pPropSet*<br/>
[in] Um ponteiro para uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK. O valor padrão de NULL não especifica que nenhuma propriedade.

*ulPropSets*<br/>
[in] O número de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas passada a *pPropSet* argumento.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais detalhes, consulte [IOpenRowset:: OPENROWSET](/previous-versions/windows/desktop/ms716724(v=vs.85)) na *referência do programador DB OLE*.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)