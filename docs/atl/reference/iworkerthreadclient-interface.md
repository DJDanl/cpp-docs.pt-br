---
title: Interface do cliente do iWorkerThread
ms.date: 11/04/2016
f1_keywords:
- IWorkerThreadClient
- ATLUTIL/ATL::IWorkerThreadClient
- ATLUTIL/ATL::CloseHandle
- ATLUTIL/ATL::Execute
helpviewer_keywords:
- IWorkerThreadClient interface
ms.assetid: 56f4a2f5-007e-4a33-9e20-05187629f715
ms.openlocfilehash: 6a68f25f153a0ad2cf42ebfaa374ff63c5746fcd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326306"
---
# <a name="iworkerthreadclient-interface"></a>Interface do cliente do iWorkerThread

`IWorkerThreadClient`é a interface implementada pelos clientes da classe [CWorkerThread.](../../atl/reference/cworkerthread-class.md)

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
__interface IWorkerThreadClient
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Closehandle](#closehandle)|Implemente este método para fechar a alça associada a este objeto.|
|[Executar](#execute)|Implemente este método para executar o código quando a alça associada a este objeto for sinalizada.|

## <a name="remarks"></a>Comentários

Implemente essa interface quando você tiver um código que precisa ser executado em um segmento de trabalhador em resposta a uma alça que está sendo sinalizada.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="iworkerthreadclientclosehandle"></a><a name="closehandle"></a>iWorkerThreadClient::CloseHandle

Implemente este método para fechar a alça associada a este objeto.

```
HRESULT CloseHandle(HANDLE  hHandle);
```

### <a name="parameters"></a>Parâmetros

*Hhandle*<br/>
A alça será fechada.

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

A alça passada para este método foi anteriormente associada a este objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir `IWorkerThreadClient::CloseHandle`mostra uma implementação simples de .

[!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iworkerthreadclient-interface_1.cpp)]

## <a name="iworkerthreadclientexecute"></a><a name="execute"></a>iWorkerThreadClient::execute

Implemente este método para executar o código quando a alça associada a este objeto for sinalizada.

```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```

### <a name="parameters"></a>Parâmetros

*Dwparam*<br/>
O parâmetro do usuário.

*Hobject*<br/>
A alça que se tornou sinalizada.

### <a name="return-value"></a>Valor retornado

O retorno S_OK no sucesso ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

A alça e o DWORD/ponteiro passados para este método foram previamente associados a este objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir `IWorkerThreadClient::Execute`mostra uma implementação simples de .

[!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iworkerthreadclient-interface_2.cpp)]

## <a name="see-also"></a>Confira também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CworkerThread](../../atl/reference/cworkerthread-class.md)
