---
title: Classe CEnumerator
ms.date: 11/04/2016
f1_keywords:
- CEnumerator
- CEnumerator::Find
- ATL::CEnumerator::Find
- ATL.CEnumerator.Find
- CEnumerator.Find
- GetMoniker
- CEnumerator.GetMoniker
- CEnumerator::GetMoniker
- ATL.CEnumerator.GetMoniker
- ATL::CEnumerator::GetMoniker
- ATL.CEnumerator.Open
- CEnumerator::Open
- ATL::CEnumerator::Open
- CEnumerator.Open
helpviewer_keywords:
- CEnumerator class
- Find method
- GetMoniker method
- Open method
ms.assetid: 25805f1b-26e3-402f-af83-1b5fe5ddebf7
ms.openlocfilehash: d0fa5f381dba4f67934007d59dbdaf4450bcfb60
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211790"
---
# <a name="cenumerator-class"></a>Classe CEnumerator

Usa um objeto enumerador OLE DB, que expõe a interface [ISourcesRowset](/previous-versions/windows/desktop/ms715969(v=vs.85)) para retornar um conjunto de linhas que descreve todas as fontes de dados e enumeradores.

## <a name="syntax"></a>Sintaxe

```cpp
class CEnumerator :
   public CAccessorRowset< CAccessor <CEnumeratorAccessor >>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Localizar](#find)|Pesquisa por meio de provedores disponíveis (fontes de dados) procurando um com o nome especificado.|
|[GetMoniker](#getmoniker)|Recupera a interface `IMoniker` para o registro atual.|
|[Abrir](#open)|Abre o enumerador.|

## <a name="remarks"></a>Comentários

Você pode recuperar os dados de `ISourcesRowset` indiretamente dessa classe.

## <a name="cenumeratorfind"></a><a name="find"></a>CEnumerator:: find

Procura um nome especificado entre os provedores disponíveis.

### <a name="syntax"></a>Sintaxe

```cpp
bool Find(TCHAR* szSearchName) throw();
```

#### <a name="parameters"></a>parâmetros

*szSearchName*<br/>
no O nome a ser pesquisado.

### <a name="return-value"></a>Valor retornado

**true** se o nome foi encontrado. Caso contrário, **false**.

### <a name="remarks"></a>Comentários

Esse nome é mapeado para o membro `SOURCES_NAME` da interface [ISourcesRowset](/previous-versions/windows/desktop/ms715969(v=vs.85)) .

## <a name="cenumeratorgetmoniker"></a><a name="getmoniker"></a>CEnumerator:: GetMoniker

Analisa o nome de exibição para extrair o componente da cadeia de caracteres que pode ser convertida em um moniker.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetMoniker(LPMONIKER* ppMoniker) const throw();

HRESULT GetMoniker(LPMONIKER* ppMoniker,
   LPCTSTR lpszDisplayName) const throw();
```

#### <a name="parameters"></a>parâmetros

*ppMoniker*<br/>
fora O moniker analisado a partir do nome de exibição ([CEnumeratorAccessor:: m_szParseName](../../data/oledb/cenumeratoraccessor-m-szparsename.md)) da linha atual.

*lpszDisplayName*<br/>
no O nome de exibição a ser analisado.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="cenumeratoropen"></a><a name="open"></a>CEnumerator:: abrir

Associa o moniker para o enumerador, se um for especificado, recupera o conjunto de linhas para o enumerador chamando [ISourcesRowset:: GetSourcesRowset](/previous-versions/windows/desktop/ms711200(v=vs.85)).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(LPMONIKER pMoniker) throw();

HRESULT Open(const CLSID* pClsid = & CLSID_OLEDB_ENUMERATOR) throw();

HRESULT Open(const CEnumerator& enumerator) throw();
```

#### <a name="parameters"></a>parâmetros

*pMoniker*<br/>
no Um ponteiro para um moniker de um enumerador.

*pClsid*<br/>
no Um ponteiro para a `CLSID` de um enumerador.

*enumerator*<br/>
no Uma referência a um enumerador.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

## <a name="see-also"></a>Confira também

[DBViewer](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
