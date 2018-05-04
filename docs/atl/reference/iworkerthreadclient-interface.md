---
title: Interface IWorkerThreadClient | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IWorkerThreadClient
- ATLUTIL/ATL::IWorkerThreadClient
- ATLUTIL/ATL::CloseHandle
- ATLUTIL/ATL::Execute
dev_langs:
- C++
helpviewer_keywords:
- IWorkerThreadClient interface
ms.assetid: 56f4a2f5-007e-4a33-9e20-05187629f715
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8336edb07d02bbbcd5775eaf3ef8fe0f735d3adb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="iworkerthreadclient-interface"></a>Interface IWorkerThreadClient
`IWorkerThreadClient` é a interface implementada por clientes a [CWorkerThread](../../atl/reference/cworkerthread-class.md) classe.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
__interface IWorkerThreadClient
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CloseHandle](#closehandle)|Implemente esse método para fechar o identificador associado a este objeto.|  
|[Executar](#execute)|Implemente esse método para executar código quando um identificador associado a este objeto se torna sinalizado.|  
  
## <a name="remarks"></a>Comentários  
 Implemente esta interface quando você tiver um código que precisa para ser executado em um thread de trabalho em resposta a um identificador de se tornar sinalizado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="closehandle"></a>  IWorkerThreadClient::CloseHandle  
 Implemente esse método para fechar o identificador associado a este objeto.  
  
```
HRESULT CloseHandle(HANDLE  hHandle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hHandle*  
 O identificador a ser fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorne S_OK em caso de sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador passado para este método era anteriormente associado ao objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::CloseHandle`.  
  
 [!code-cpp[NVC_ATL_Utilities#135](../../atl/codesnippet/cpp/iworkerthreadclient-interface_1.cpp)]  
  
##  <a name="execute"></a>  IWorkerThreadClient::Execute  
 Implemente esse método para executar código quando um identificador associado a este objeto se torna sinalizado.  
  
```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwParam`  
 O parâmetro de usuário.  
  
 `hObject`  
 O identificador que tem tornou-se sinalizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorne S_OK em caso de sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador e DWORD/ponteiro passado para este método eram anteriormente associada ao objeto por uma chamada para [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::Execute`.  
  
 [!code-cpp[NVC_ATL_Utilities#136](../../atl/codesnippet/cpp/iworkerthreadclient-interface_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe CWorkerThread](../../atl/reference/cworkerthread-class.md)
