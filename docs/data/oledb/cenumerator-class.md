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
ms.openlocfilehash: 2a54770e3c5c2bc3805024b237f9875bded1ab26
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772378"
---
# <a name="cenumerator-class"></a>Classe CEnumerator

Usa um objeto de enumerador OLE DB que expõe o [ISourcesRowset](/previous-versions/windows/desktop/ms715969(v=vs.85)) interface para retornar um conjunto de linhas que descrevem todas as fontes de dados e enumeradores.

## <a name="syntax"></a>Sintaxe

```cpp
class CEnumerator :
   public CAccessorRowset< CAccessor <CEnumeratorAccessor >>
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Find](#find)|Pesquisa por meio de provedores disponíveis (fontes de dados) procurando um com o nome especificado.|
|[GetMoniker](#getmoniker)|Recupera o `IMoniker` interface para o registro atual.|
|[Abrir](#open)|Abre o enumerador.|

## <a name="remarks"></a>Comentários

Você pode recuperar o `ISourcesRowset` dados indiretamente a partir dessa classe.

## <a name="find"></a> Cenumerator:: Find

Procura por um nome especificado entre os provedores disponíveis.

### <a name="syntax"></a>Sintaxe

```cpp
bool Find(TCHAR* szSearchName) throw();
```

#### <a name="parameters"></a>Parâmetros

*szSearchName*<br/>
[in] O nome a ser pesquisado.

### <a name="return-value"></a>Valor de retorno

**True** se o nome foi encontrado. Caso contrário, **falsos**.

### <a name="remarks"></a>Comentários

Esse nome é mapeado para o `SOURCES_NAME` membro a [ISourcesRowset](/previous-versions/windows/desktop/ms715969(v=vs.85)) interface.

## <a name="getmoniker"></a> CEnumerator::GetMoniker

Analisa o nome de exibição para extrair o componente da cadeia de caracteres que pode ser convertido em um identificador de origem.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetMoniker(LPMONIKER* ppMoniker) const throw();

HRESULT GetMoniker(LPMONIKER* ppMoniker,
   LPCTSTR lpszDisplayName) const throw();
```

#### <a name="parameters"></a>Parâmetros

*ppMoniker*<br/>
[out] O moniker analisada do nome de exibição ([cenumeratoraccessor:: M_szparsename](../../data/oledb/cenumeratoraccessor-m-szparsename.md)) da linha atual.

*lpszDisplayName*<br/>
[in] O nome de exibição para analisar.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="open"></a> Cenumerator:: Open

Associa o identificador de origem para o enumerador, se for especificado, então recupera o conjunto de linhas para o enumerador chamando [ISourcesRowset:: Getsourcesrowset](/previous-versions/windows/desktop/ms711200(v=vs.85)).

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(LPMONIKER pMoniker) throw();

HRESULT Open(const CLSID* pClsid = & CLSID_OLEDB_ENUMERATOR) throw();

HRESULT Open(const CEnumerator& enumerator) throw();
```

#### <a name="parameters"></a>Parâmetros

*pMoniker*<br/>
[in] Um ponteiro para um identificador de origem para um enumerador.

*pClsid*<br/>
[in] Um ponteiro para o `CLSID` de um enumerador.

*enumerator*<br/>
[in] Uma referência a um enumerador.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="see-also"></a>Consulte também

[DBViewer](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)