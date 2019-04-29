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
ms.openlocfilehash: b34a6300473db94621360f1d04fd73ddd7e8bd69
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366453"
---
# <a name="csession-class"></a>Classe CSession

Representa uma sessão de acesso do banco de dados individual.

## <a name="syntax"></a>Sintaxe

```cpp
class CSession
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Anular](#abort)|Cancela (encerra) a transação.|
|[Fechar](#close)|Fecha a sessão.|
|[Confirmação](#commit)|Confirma a transação.|
|[GetTransactionInfo](#gettransactioninfo)|Retorna informações sobre uma transação.|
|[Abrir](#open)|Abre uma nova sessão para o objeto de fonte de dados.|
|[StartTransaction](#starttransaction)|Inicia uma nova transação para esta sessão.|

## <a name="remarks"></a>Comentários

Uma ou mais sessões podem ser associadas a cada conexão de provedor (fonte de dados), que é representada por uma [CDataSource](../../data/oledb/cdatasource-class.md) objeto. Para criar um novo `CSession` para um `CDataSource`, chame [csession:: Open](../../data/oledb/csession-open.md). Para iniciar uma transação de banco de dados, `CSession` fornece o `StartTransaction` método. Após uma transação é iniciada, você poderá confirmar a ele usando o `Commit` método, ou cancelá-la usando o `Abort` método.

## <a name="abort"></a> Csession:: Abort

Encerra a transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Abort(BOID* pboidReason = NULL,
   BOOL bRetaining = FALSE,
   BOOL bAsync = FALSE) const throw();
```

#### <a name="parameters"></a>Parâmetros

Ver [ITransaction:: Abort](/previous-versions/windows/desktop/ms709833(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

## <a name="close"></a> Csession:: Close

Fecha a sessão, que foi aberta pela [csession:: Open](../../data/oledb/csession-open.md).

### <a name="syntax"></a>Sintaxe

```cpp
void Close() throw();
```

### <a name="remarks"></a>Comentários

Versões de `m_spOpenRowset` ponteiro.

## <a name="commit"></a> Csession:: Commit

Confirma a transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Commit(BOOL bRetaining = FALSE,
   DWORD grfTC = XACTTC_SYNC,
   DWORD grfRM = 0) const throw();
```

#### <a name="parameters"></a>Parâmetros

Ver [ITransaction:: Commit](/previous-versions/windows/desktop/ms713008(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [ITransaction:: Commit](/previous-versions/windows/desktop/ms713008(v=vs.85)).

## <a name="gettransactioninfo"></a> CSession::GetTransactionInfo

Retorna informações sobre uma transação.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT GetTransactionInfo(XACTTRANSINFO* pInfo) const throw();
```

#### <a name="parameters"></a>Parâmetros

Ver [ITransaction::GetTransactionInfo](/previous-versions/windows/desktop/ms714975(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [ITransaction::GetTransactionInfo](/previous-versions/windows/desktop/ms714975(v=vs.85)) na *referência do programador DB OLE*.

## <a name="open"></a> Csession:: Open

Abre uma nova sessão para o objeto de fonte de dados.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Open(const CDataSource& ds,
   DBPROPSET *pPropSet = NULL,
   ULONG ulPropSets = 0) throw();
```

#### <a name="parameters"></a>Parâmetros

*ds*<br/>
[in] A fonte de dados para o qual a sessão for aberta.

*pPropSet*<br/>
[in] Um ponteiro para uma matriz de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas que contém as propriedades e valores a serem definidos. Ver [conjuntos de propriedades e grupos de propriedades](/previous-versions/windows/desktop/ms713696(v=vs.85)) na *referência do programador do OLE DB* no Windows SDK.

*ulPropSets*<br/>
[in] O número de [DBPROPSET](/previous-versions/windows/desktop/ms714367(v=vs.85)) estruturas passada a *pPropSet* argumento.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Você deve abrir o objeto de fonte de dados usando [cdatasource:: Open](../../data/oledb/cdatasource-open.md) antes de passá-lo para `CSession::Open`.

## <a name="starttransaction"></a> Csession:: Starttransaction

Inicia uma nova transação para esta sessão.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT StartTransaction(ISOLEVEL isoLevel = ISOLATIONLEVEL_READCOMMITTED,
   ULONG isoFlags = 0,
   ITransactionOptions* pOtherOptions = NULL,
   ULONG* pulTransactionLevel = NULL) const throw();
```

#### <a name="parameters"></a>Parâmetros

Ver [itransactionlocal:: Starttransaction](/previous-versions/windows/desktop/ms709786(v=vs.85)) na *referência do programador do OLE DB*.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [itransactionlocal:: Starttransaction](/previous-versions/windows/desktop/ms709786(v=vs.85)) na *referência do programador DB OLE*.

## <a name="see-also"></a>Consulte também

[CatDB](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)