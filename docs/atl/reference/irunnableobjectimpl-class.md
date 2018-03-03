---
title: Classe IRunnableObjectImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IRunnableObjectImpl
- ATLCTL/ATL::IRunnableObjectImpl
- ATLCTL/ATL::IRunnableObjectImpl::GetRunningClass
- ATLCTL/ATL::IRunnableObjectImpl::IsRunning
- ATLCTL/ATL::IRunnableObjectImpl::LockRunning
- ATLCTL/ATL::IRunnableObjectImpl::Run
- ATLCTL/ATL::IRunnableObjectImpl::SetContainedObject
dev_langs:
- C++
helpviewer_keywords:
- containers, running controls
- IRunnableObjectImpl class
- IRunnableObject, ATL implementation
- controls [ATL], running
- controls [C++], container running in ATL
ms.assetid: 305c7c3b-889e-49dd-aca1-34379c1b9931
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b1ac939d723596f4b0fc3f1013dd3f02cf2aa06b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irunnableobjectimpl-class"></a>Classe IRunnableObjectImpl
Essa classe implementa **IUnknown** e fornece uma implementação padrão de [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) interface.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template<class T>  
class IRunnableObjectImpl
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IRunnableObjectImpl`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[IRunnableObjectImpl::GetRunningClass](#getrunningclass)|Retorna o CLSID do controle em execução. A implementação de ATL define o CLSID `GUID_NULL` e retorna **E_UNEXPECTED**.|  
|[IRunnableObjectImpl::IsRunning](#isrunning)|Determina se o controle está em execução. Retorna a implementação de ATL **TRUE**.|  
|[IRunnableObjectImpl::LockRunning](#lockrunning)|Bloqueia o controle para o estado de execução. Retorna a implementação de ATL `S_OK`.|  
|[IRunnableObjectImpl::Run](#run)|Força a execução do controle. Retorna a implementação de ATL `S_OK`.|  
|[IRunnableObjectImpl::SetContainedObject](#setcontainedobject)|Indica que o controle é inserido. Retorna a implementação de ATL `S_OK`.|  
  
## <a name="remarks"></a>Comentários  
 O [IRunnableObject](http://msdn.microsoft.com/library/windows/desktop/ms692783) interface permite que um contêiner determinar se um controle está em execução, forçá-lo a executar ou bloqueá-la no estado em execução. Classe `IRunnableObjectImpl` fornece uma implementação padrão dessa interface e implementa **IUnknown** enviando informações para o despejo compilações dispositivo na depuração.  
  
 **Artigos relacionados** [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md), [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IRunnableObject`  
  
 `IRunnableObjectImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="getrunningclass"></a>IRunnableObjectImpl::GetRunningClass  
 Retorna o CLSID do controle em execução.  
  
```
HRESULT GetRunningClass(LPCLSID lpClsid);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Os conjuntos de implementação de ATL \* *lpClsid* para `GUID_NULL` e retorna **E_UNEXPECTED**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IRunnableObject::GetRunningClass](http://msdn.microsoft.com/library/windows/desktop/ms693734) no SDK do Windows.  
  
##  <a name="isrunning"></a>IRunnableObjectImpl::IsRunning  
 Determina se o controle está em execução.  
  
```
virtual BOOL IsRunning();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação de ATL **TRUE**.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IRunnableObject::IsRunning](http://msdn.microsoft.com/library/windows/desktop/ms678496) no SDK do Windows.  
  
##  <a name="lockrunning"></a>IRunnableObjectImpl::LockRunning  
 Bloqueia o controle para o estado de execução.  
  
```
HRESULT LockRunning(BOOL fLock, BOOL fLastUnlockCloses);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação de ATL `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IRunnableObject::LockRunning](http://msdn.microsoft.com/library/windows/desktop/ms693361) no SDK do Windows.  
  
##  <a name="run"></a>IRunnableObjectImpl::Run  
 Força a execução do controle.  
  
```
HRESULT Run(LPBINDCTX lpbc);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação de ATL `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IRunnableObject::Run](http://msdn.microsoft.com/library/windows/desktop/ms694517) no SDK do Windows.  
  
##  <a name="setcontainedobject"></a>IRunnableObjectImpl::SetContainedObject  
 Indica que o controle é inserido.  
  
```
HRESULT SetContainedObject(BOOL fContained);
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a implementação de ATL `S_OK`.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IRunnableObject::SetContainedObject](http://msdn.microsoft.com/library/windows/desktop/ms693710) no SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
