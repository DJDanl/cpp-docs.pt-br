---
title: Classe ICommandImpl
ms.date: 11/04/2016
f1_keywords:
- ICommandImpl
- ICommandImpl::Cancel
- Cancel
- ICommandImpl.Cancel
- ICommandImpl::CancelExecution
- ATL::ICommandImpl::CancelExecution
- ATL.ICommandImpl.CancelExecution
- CancelExecution
- ICommandImpl.CancelExecution
- ICommandImpl::CreateRowset
- ICommandImpl.CreateRowset
- CreateRowset
- ICommandImpl::Execute
- ICommandImpl.Execute
- ICommandImpl::GetDBSession
- GetDBSession
- ICommandImpl.GetDBSession
- ATL.ICommandImpl.ICommandImpl
- ATL::ICommandImpl::ICommandImpl
- ICommandImpl::ICommandImpl
- ICommandImpl.ICommandImpl
- ICommandImpl::m_bCancel
- ICommandImpl.m_bCancel
- m_bCancel
- ATL::ICommandImpl::m_bCancel
- ATL.ICommandImpl.m_bCancel
- ICommandImpl::m_bCancelWhenExecuting
- ICommandImpl.m_bCancelWhenExecuting
- ATL::ICommandImpl::m_bCancelWhenExecuting
- m_bCancelWhenExecuting
- ATL.ICommandImpl.m_bCancelWhenExecuting
- ICommandImpl.m_bIsExecuting
- ATL::ICommandImpl::m_bIsExecuting
- m_bIsExecuting
- ATL.ICommandImpl.m_bIsExecuting
- ICommandImpl::m_bIsExecuting
helpviewer_keywords:
- ICommandImpl class
- Cancel method
- CancelExecution method
- CreateRowset method
- Execute method
- GetDBSession method
- ICommandImpl constructor
- ICommandImpl class, constructor
- m_bCancel
- m_bCancelWhenExecuting
- m_bIsExecuting
ms.assetid: ef285fef-0d66-45e6-a762-b03357098e3b
ms.openlocfilehash: c88554d717888719ad6d805a2871489ce4b0df32
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845582"
---
# <a name="icommandimpl-class"></a>Classe ICommandImpl

Fornece implementação para a interface [ICommand](/previous-versions/windows/desktop/ms709737(v=vs.85)) .

## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandBase = ICommand>
class ATL_NO_VTABLE ICommandImpl : public CommandBase
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Sua classe, derivada de `ICommandImpl` .

*CommandBase*<br/>
Uma interface de comando. O padrão é `ICommand`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[Cancelar](#cancel)|Cancela a execução do comando atual.|
|[CancelExecution](#cancelexecution)|Cancela a execução do comando atual.|
|[CreateRowset](#createrowset)|Cria um objeto de conjunto de linhas.|
|[Executar](#execute)|Executa o comando.|
|[GetDBSession](#getdbsession)|Retorna um ponteiro de interface para a sessão que criou o comando.|
|[ICommandImpl](#icommandimpl)|O construtor.|

### <a name="data-members"></a>Membros de dados

| Nome | Descrição |
|-|-|
|[m_bCancel](#bcancel)|Indica se o comando deve ser cancelado.|
|[m_bCancelWhenExecuting](#bcancelwhenexecuting)|Indica se o comando deve ser cancelado durante a execução.|
|[m_bIsExecuting](#bisexecuting)|Indica se o comando está em execução no momento.|

## <a name="remarks"></a>Comentários

Uma interface obrigatória no objeto Command.

## <a name="icommandimplcancel"></a><a name="cancel"></a> ICommandImpl:: Cancel

Cancela a execução do comando atual.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(Cancel)();
```

### <a name="remarks"></a>Comentários

Consulte [ICommand:: Cancel](/previous-versions/windows/desktop/ms714402(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="icommandimplcancelexecution"></a><a name="cancelexecution"></a> ICommandImpl::CancelExecution

Cancela a execução do comando atual.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CancelExecution();
```

## <a name="icommandimplcreaterowset"></a><a name="createrowset"></a> ICommandImpl:: CreateRowset

Chamado por [Execute](../../data/oledb/icommandimpl-execute.md) para criar um único conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
template template <class RowsetClass>
HRESULT CreateRowset(IUnknown* pUnkOuter,
   REFIID riid,
   DBPARAMS* pParams,
   DBROWCOUNT* pcRowsAffected,
   IUnknown** ppRowset,
   RowsetClass*& pRowsetObj);
```

#### <a name="parameters"></a>parâmetros

*RowsetClass*<br/>
Um membro de classe de modelo que representa a classe do conjunto de linhas do usuário. Geralmente gerado pelo assistente.

*pUnkOuter*<br/>
no Um ponteiro para a interface de controle `IUnknown` se o conjunto de linhas estiver sendo criado como parte de uma agregação; caso contrário, será nulo.

*riid*<br/>
no Corresponde a *riid* in `ICommand::Execute` .

*pParams*<br/>
[entrada/saída] Corresponde a *pParams* no `ICommand::Execute` .

*pcRowsAffected*<br/>
Corresponde a *pcRowsAffected* no `ICommand::Execute` .

*ppRowset*<br/>
[entrada/saída] Corresponde a *ppRowset* no `ICommand::Execute` .

*pRowsetObj*<br/>
fora Um ponteiro para um objeto de conjunto de linhas. Normalmente, esse parâmetro não é usado, mas pode ser usado se você precisar executar mais trabalho no conjunto de linhas antes de passá-lo para um objeto COM. O tempo de vida de *pRowsetObj* é associado por *ppRowset*.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão. Consulte `ICommand::Execute` para obter uma lista de valores típicos.

### <a name="remarks"></a>Comentários

Para criar mais de um conjunto de linhas ou para fornecer suas próprias condições para a criação de conjuntos de itens diferentes, coloque chamadas diferentes para `CreateRowset` de dentro `Execute` .

Consulte [ICommand:: execute](/previous-versions/windows/desktop/ms718095(v=vs.85)) na *referência do programador de OLE DB.*

## <a name="icommandimplexecute"></a><a name="execute"></a> ICommandImpl:: execute

Executa o comando.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT Execute(IUnknown* pUnkOuter,
   REFIID riid,
   DBPARAMS* pParams,
   DBROWCOUNT* pcRowsAffected,
   IUnknown** ppRowset);
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommand:: execute](/previous-versions/windows/desktop/ms718095(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

A interface de saída solicitada será uma interface adquirida do objeto de conjunto de linhas que essa função cria.

`Execute` chama [CreateRowset](../../data/oledb/icommandimpl-createrowset.md). Substitua a implementação padrão para criar mais de um conjunto de linhas ou para fornecer suas próprias condições para a criação de diferentes conjuntos de linhas.

## <a name="icommandimplgetdbsession"></a><a name="getdbsession"></a> ICommandImpl::GetDBSession

Retorna um ponteiro de interface para a sessão que criou o comando.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (GetDBSession) (REFIID riid,
   IUnknown** ppSession);
```

#### <a name="parameters"></a>parâmetros

Consulte [ICommand:: GetDBSession](/previous-versions/windows/desktop/ms719622(v=vs.85)) na *referência do programador de OLE DB*.

### <a name="remarks"></a>Comentários

Útil para recuperar propriedades da sessão.

## <a name="icommandimplicommandimpl"></a><a name="icommandimpl"></a> ICommandImpl::ICommandImpl

O construtor.

### <a name="syntax"></a>Sintaxe

```cpp
ICommandImpl();
```

## <a name="icommandimplm_bcancel"></a><a name="bcancel"></a> ICommandImpl:: m_bCancel

Indica se o comando foi cancelado.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned m_bCancel:1;
```

### <a name="remarks"></a>Comentários

Você pode recuperar essa variável no `Execute` método da sua classe de comando e cancelá-la conforme apropriado.

## <a name="icommandimplm_bcancelwhenexecuting"></a><a name="bcancelwhenexecuting"></a> ICommandImpl:: m_bCancelWhenExecuting

Indica se o comando pode ser cancelado durante a execução.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned m_bCancelWhenExecuting:1;
```

### <a name="remarks"></a>Comentários

O padrão é **`true`** (pode ser cancelado).

## <a name="icommandimplm_bisexecuting"></a><a name="bisexecuting"></a> ICommandImpl:: m_bIsExecuting

Indica se o comando está em execução no momento.

### <a name="syntax"></a>Sintaxe

```cpp
unsigned m_bIsExecuting:1;
```

### <a name="remarks"></a>Comentários

O `Execute` método da sua classe de comando pode definir essa variável como **`true`** .

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
