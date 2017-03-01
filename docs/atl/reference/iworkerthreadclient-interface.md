---
title: Interface IWorkerThreadClient | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.IWorkerThreadClient
- ATL::IWorkerThreadClient
- IWorkerThreadClient
dev_langs:
- C++
helpviewer_keywords:
- IWorkerThreadClient interface
ms.assetid: 56f4a2f5-007e-4a33-9e20-05187629f715
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 2127d13dc11edb353ef27396f3457dd9abdc4a99
ms.lasthandoff: 02/25/2017

---
# <a name="iworkerthreadclient-interface"></a>Interface IWorkerThreadClient
`IWorkerThreadClient`é a interface implementada por clientes do [CWorkerThread](../../atl/reference/cworkerthread-class.md) classe.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
__interface IWorkerThreadClient
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CloseHandle](#closehandle)|Implemente esse método para fechar um identificador associado a este objeto.|  
|[Executar](#execute)|Implemente esse método para executar código quando um identificador associado a esse objeto se torna sinalizado.|  
  
## <a name="remarks"></a>Comentários  
 Implemente essa interface quando você tem código que precisa para ser executado em um thread de trabalho em resposta a um identificador de tornar-se sinalizado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlutil.h  
  
##  <a name="a-nameclosehandlea--iworkerthreadclientclosehandle"></a><a name="closehandle"></a>IWorkerThreadClient::CloseHandle  
 Implemente esse método para fechar um identificador associado a este objeto.  
  
```
HRESULT CloseHandle(HANDLE  hHandle);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hHandle*  
 O identificador seja fechado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador passado para esse método foi previamente associado a este objeto por uma chamada a [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::CloseHandle`.  
  
 [!code-cpp[NVC_ATL_Utilities&#135;](../../atl/codesnippet/cpp/iworkerthreadclient-interface_1.cpp)]  
  
##  <a name="a-nameexecutea--iworkerthreadclientexecute"></a><a name="execute"></a>IWorkerThreadClient::Execute  
 Implemente esse método para executar código quando um identificador associado a esse objeto se torna sinalizado.  
  
```
HRESULT Execute(DWORD_PTR dwParam, HANDLE hObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwParam`  
 O parâmetro de usuário.  
  
 `hObject`  
 O identificador que tornou-se sinalizado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no sucesso ou erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 O identificador e passado para este método DWORD/ponteiro foram previamente associado a este objeto por uma chamada a [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).  
  
### <a name="example"></a>Exemplo  
 O código a seguir mostra uma implementação simples de `IWorkerThreadClient::Execute`.  
  
 [!code-cpp[NVC_ATL_Utilities&#136;](../../atl/codesnippet/cpp/iworkerthreadclient-interface_2.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../atl/reference/atl-classes.md)   
 [Classe CWorkerThread](../../atl/reference/cworkerthread-class.md)

