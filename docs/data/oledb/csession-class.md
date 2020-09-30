---
title: Classe CSession
ms.date: 11/04/2016
f1_keywords:
- CSession
- ATL::CSession
- ATL.CSession
- CSession.Abort
- CSession::Abort
- ATL.CSession.Abort
- ATL::CSession::Abort
- CSession::Close
- ATL.CSession.Close
- CSession.Close
- ATL::CSession::Close
- CSession.Commit
- ATL.CSession.Commit
- ATL::CSession::Commit
- CSession::Commit
- GetTransactionInfo
- CSession.GetTransactionInfo
- ATL.CSession.GetTransactionInfo
- CSession::GetTransactionInfo
- ATL::CSession::GetTransactionInfo
- ATL::CSession::Open
- CSession::Open
- CSession.Open
- ATL.CSession.Open
- CSession::StartTransaction
- StartTransaction
- ATL.CSession.StartTransaction
- CSession.StartTransaction
- ATL::CSession::StartTransaction
helpviewer_keywords:
- CSession class
- Abort method
- Close method
- Commit method
- GetTransactionInfo method
- Open method
- StartTransaction method
ms.assetid: 83cd798f-b45d-4f11-a23c-29183390450c
ms.openlocfilehash: f507ed432e107f586d34bb6b08fa9d3f7dc509d8
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507245"
---
# <a name="csession-class"></a>Classe CSession

Representa uma sessão de acesso a banco de dados individual.

## <a name="syntax"></a>Sintaxe

```cpp
class CSession
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[Anular](#abort)|Cancela (encerra) a transação.|
|[Fechar](#close)|Fecha a sessão.|
|[Confirmar](#commit)|Confirma a transação.|
|[GetTransactionInfo](#gettransactioninfo)|Retorna informações sobre uma transação.|
|[Abrir](#open)|Abre uma nova sessão para o objeto de fonte de dados.|
|[StartTransaction](#starttransaction)|Inicia uma nova transação para esta sessão.|

## <a name="remarks"></a>Comentários

Uma ou mais sessões podem ser associadas a cada conexão de provedor (fonte de dados), que é representada por um objeto [CDataSource](../../data/oledb/cdatasource-class.md) . Para criar um novo `CSession` para um `CDataSource` , chame [CSession:: Open](#open). Para iniciar uma transação de banco de dados, `CSession` o fornece o `StartTransaction` método. Depois que uma transação é iniciada, você pode confirmá-la usando o `Commit` método ou cancelá-la usando o `Abort` método.

## <a name="csessionabort"></a><a name="abort"></a> CSession:: Abort

Encerra a transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Abort(BOID* pboidReason = NULL,
   BOOL bRetaining = FALSE,
   BOOL bAsync = FALSE) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ITransaction:: Abort](/previous-versions/windows/desktop/ms709833(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

## <a name="csessionclose"></a><a name="close"></a> CSession:: fechar

Fecha a sessão, que foi aberta por [CSession:: Open](#open).

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

### <a name="remarks"></a>Comentários

Libera o `m_spOpenRowset` ponteiro.

## <a name="csessioncommit"></a><a name="commit"></a> CSession:: Commit

Confirma a transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Commit(BOOL bRetaining = FALSE,
   DWORD grfTC = XACTTC_SYNC,
   DWORD grfRM = 0) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ITransaction:: Commit](/previous-versions/windows/desktop/ms713008(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [ITransaction:: Commit](/previous-versions/windows/desktop/ms713008(v=vs.85)).

## <a name="csessiongettransactioninfo"></a><a name="gettransactioninfo"></a> CSession:: GetTransactionInfo

Retorna informações sobre uma transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetTransactionInfo(XACTTRANSINFO* pInfo) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ITransaction:: GetTransactionInfo](/previous-versions/windows/desktop/ms714975(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [ITransaction:: GetTransactionInfo](/previous-versions/windows/desktop/ms714975(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="csessionopen"></a><a name="open"></a> CSession:: abrir

Abre uma nova sessão para o objeto de fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CDataSource& ds,
   DBPROPSET *pPropSet = NULL,
   ULONG ulPropSets = 0) throw();
```

#### <a name="parameters"></a>Parâmetros

*AD*<br/>
no A fonte de dados para a qual a sessão deve ser aberta.

*pPropSet*<br/>
no Um ponteiro para uma matriz de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) que contém propriedades e valores a serem definidos. Consulte [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador de OLE DB* no SDK do Windows.

*ulPropSets*<br/>
no O número de estruturas [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) passadas no argumento *pPropSet* .

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Você deve abrir o objeto de fonte de dados usando [CDataSource:: Open](./cdatasource-class.md#open) antes de passá-lo para `CSession::Open` .

## <a name="csessionstarttransaction"></a><a name="starttransaction"></a> CSession:: StartTransaction

Inicia uma nova transação para esta sessão.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT StartTransaction(ISOLEVEL isoLevel = ISOLATIONLEVEL_READCOMMITTED,
   ULONG isoFlags = 0,
   ITransactionOptions* pOtherOptions = NULL,
   ULONG* pulTransactionLevel = NULL) const throw();
```

#### <a name="parameters"></a>Parâmetros

Consulte [ITransactionLocal:: StartTransaction](/previous-versions/windows/desktop/ms709786(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [ITransactionLocal:: StartTransaction](/previous-versions/windows/desktop/ms709786(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="see-also"></a>Consulte também

[CatDB](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)
