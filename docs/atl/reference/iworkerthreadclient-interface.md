---
title: Interface IWorkerThreadClient
ms.date: 11/04/2016
f1_keywords:
- IWorkerThreadClient
- ATLUTIL/ATL::IWorkerThreadClient
- ATLUTIL/ATL::CloseHandle
- ATLUTIL/ATL::Execute
helpviewer_keywords:
- IWorkerThreadClient interface
ms.assetid: 56f4a2f5-007e-4a33-9e20-05187629f715
ms.openlocfilehash: 1fa8a5e42d002260076f737d3d33cfa191ff297a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62197400"
---
# <a name="iworkerthreadclient-interface"></a>Interface IWorkerThreadClient

`IWorkerThreadClient` é a interface implementada por clientes do [CWorkerThread](../../atl/reference/cworkerthread-class.md) classe.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
__interface IWorkerThreadClient
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[CloseHandle](#closehandle)|Implemente este método para fechar o identificador associado a este objeto.|
|[Executar](#execute)|Implemente este método para executar o código quando um identificador associado a este objeto é sinalizado.|

## <a name="remarks"></a>Comentários

Quando você tiver um código que precisa para ser executado em um thread de trabalho em resposta a um identificador se torne sinalizado, implemente essa interface.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil

##  <a name="closehandle"></a>  IWorkerThreadClient::CloseHandle

Implemente este método para fechar o identificador associado a este objeto.

```
HRESULT CloseHandle(HANDLE  hHandle);
```

### <a name="parameters"></a>Parâmetros

*hHandle*<br/>
O identificador seja fechado.

### <a name="return-value"></a>Valor de retorno

Retorne S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador passado para esse método era anteriormente associado ao objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples de `IWorkerThreadClient::CloseHandle`.

[!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iworkerthreadclient-interface_1.cpp)]

##  <a name="execute"></a>  IWorkerThreadClient::Execute

Implemente este método para executar o código quando um identificador associado a este objeto é sinalizado.

```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```

### <a name="parameters"></a>Parâmetros

*dwParam*<br/>
O parâmetro de usuário.

*hObject*<br/>
O identificador que foi sinalizado.

### <a name="return-value"></a>Valor de retorno

Retorne S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

O identificador e DWORD/ponteiro passado para esse método foram associada anteriormente com esse objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

### <a name="example"></a>Exemplo

O código a seguir mostra uma implementação simples de `IWorkerThreadClient::Execute`.

[!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iworkerthreadclient-interface_2.cpp)]

## <a name="see-also"></a>Consulte também

[Classes](../../atl/reference/atl-classes.md)<br/>
[Classe CWorkerThread](../../atl/reference/cworkerthread-class.md)
