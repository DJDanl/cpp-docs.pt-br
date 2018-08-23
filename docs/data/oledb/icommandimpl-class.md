---
title: Classe ICommandImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
- ICommandImpl
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d6adec1a87463515f3fa87dfd4ca31fda650e902
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42572436"
---
# <a name="icommandimpl-class"></a>Classe ICommandImpl
Fornece implementação para o [ICommand](/previous-versions/windows/desktop/ms709737\(v=vs.85\)) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class CommandBase = ICommand>   
class ATL_NO_VTABLE ICommandImpl : public CommandBase  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `ICommandImpl`.  
  
 *CommandBase*  
 Uma interface de comando. O padrão é `ICommand`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Cancelar](#cancel)|Cancela a execução do comando atual.|  
|[CancelExecution](#cancelexecution)|Cancela a execução do comando atual.|  
|[CreateRowset](#createrowset)|Cria um objeto de conjunto de linhas.|  
|[Executar](#execute)|Executa o comando.|  
|[GetDBSession](#getdbsession)|Retorna um ponteiro de interface para a sessão que criou o comando.|  
|[ICommandImpl](#icommandimpl)|O construtor.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_bCancel](#bcancel)|Indica se o comando deve ser cancelada.|  
|[m_bCancelWhenExecuting](#bcancelwhenexecuting)|Indica se o comando deve ser cancelado durante a execução.|  
|[m_bIsExecuting](#bisexecuting)|Indica se o comando está em execução.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória no objeto de comando.  
  
## <a name="cancel"></a> Icommandimpl:: Cancel
Cancela a execução do comando atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(Cancel)();  
```  
  
### <a name="remarks"></a>Comentários  
 Ver [ICommand::Cancel](/previous-versions/windows/desktop/ms714402\(v=vs.85\)) na *referência do programador do OLE DB*.  

## <a name="cancelexecution"></a> Icommandimpl:: Cancelexecution
Cancela a execução do comando atual.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CancelExecution();  
```  

## <a name="createrowset"></a> Icommandimpl:: Createrowset
Chamado pelo [Execute](../../data/oledb/icommandimpl-execute.md) para criar um único conjunto de linhas.  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 *RowsetClass*  
 Um membro de classe de modelo que representa a classe de conjunto de linhas do usuário. Geralmente, gerado pelo assistente.  
  
 *pUnkOuter*  
 [in] Um ponteiro para o controle `IUnknown` interface se o conjunto de linhas estiver sendo criado como parte de uma agregação; caso contrário, ele será nulo.  
  
 *riid*  
 [in] Corresponde ao *riid* em `ICommand::Execute`.  
  
 *pParams*  
 [entrada/saída] Corresponde ao *pParams* em `ICommand::Execute`.  
  
 *pcRowsAffected*  
 Corresponde ao *pcRowsAffected* em `ICommand::Execute`.  
  
 *ppRowset*  
 [entrada/saída] Corresponde ao *ppRowset* em `ICommand::Execute`.  
  
 *pRowsetObj*  
 [out] Um ponteiro para um objeto de conjunto de linhas. Normalmente, esse parâmetro não for usado, mas ele pode ser usado se for preciso executar mais trabalho no conjunto de linhas antes de passá-lo para um objeto COM. O tempo de vida dos *pRowsetObj* estiver associado ao *ppRowset*.  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão de HRESULT. Consulte `ICommand::Execute` para obter uma lista de valores típicos.  
  
### <a name="remarks"></a>Comentários  
 Para criar mais de um conjunto de linhas, ou para fornecer suas próprias condições para a criação de diferentes conjuntos de linhas, coloque as diferentes chamadas para `CreateRowset` de dentro `Execute`.  
  
 Ver [ICommand:: execute](/previous-versions/windows/desktop/ms718095\(v=vs.85\)) no *referência do programador do OLE DB.*  

## <a name="execute"></a> Icommandimpl:: execute
Executa o comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Execute(IUnknown* pUnkOuter,  
   REFIID riid,  
   DBPARAMS* pParams,  
   DBROWCOUNT* pcRowsAffected,  
   IUnknown** ppRowset);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [ICommand:: execute](/previous-versions/windows/desktop/ms718095\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 A interface de saída solicitada será uma interface que adquiriu do objeto de conjunto de linhas que cria essa função.  
  
 `Execute` chamadas [CreateRowset](../../data/oledb/icommandimpl-createrowset.md). Substitua a implementação padrão para criar mais de um conjunto de linhas ou para fornecer suas próprias condições para a criação de diferentes conjuntos de linhas.  

## <a name="getdbsession"></a> Icommandimpl:: Getdbsession
Retorna um ponteiro de interface para a sessão que criou o comando.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (GetDBSession) (REFIID riid,  
   IUnknown** ppSession);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [ICommand::GetDBSession](/previous-versions/windows/desktop/ms719622\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 É útil para recuperar as propriedades da sessão.  

## <a name="icommandimpl"></a> Icommandimpl:: Icommandimpl
O construtor.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
ICommandImpl();  
```  

## <a name="bcancel"></a> Icommandimpl:: M_bcancel
Indica se o comando é cancelado.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
unsigned m_bCancel:1;  
```  
  
### <a name="remarks"></a>Comentários  
 Você pode recuperar essa variável no `Execute` método de sua classe de comando e Cancelar conforme apropriado. 

## <a name="bcancelwhenexecuting"></a> Icommandimpl:: M_bcancelwhenexecuting
Indica se o comando pode ser cancelado durante a execução.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
unsigned m_bCancelWhenExecuting:1;  
```  
  
### <a name="remarks"></a>Comentários  
 O padrão é **verdadeira** (pode ser cancelada).  

## <a name="bisexecuting"></a> Icommandimpl:: M_bisexecuting
Indica se o comando está em execução.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
unsigned m_bIsExecuting:1;  
```  
  
### <a name="remarks"></a>Comentários  
 O `Execute` método da classe do comando pode definir essa variável como **verdadeiro**. 
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)