---
title: Classe CAnimationTimerEventHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationTimerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler::CreateInstance
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler::OnPostUpdate
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler::OnPreUpdate
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler::OnRenderingTooSlow
- AFXANIMATIONCONTROLLER/CAnimationTimerEventHandler::SetAnimationController
dev_langs: C++
helpviewer_keywords:
- CAnimationTimerEventHandler [MFC], CreateInstance
- CAnimationTimerEventHandler [MFC], OnPostUpdate
- CAnimationTimerEventHandler [MFC], OnPreUpdate
- CAnimationTimerEventHandler [MFC], OnRenderingTooSlow
- CAnimationTimerEventHandler [MFC], SetAnimationController
ms.assetid: 188dea3b-4b5e-4f6b-8df9-09d993a21619
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1f47caa836a93ecce28e77f9bf768aeb4d1ea3d7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="canimationtimereventhandler-class"></a>Classe CAnimationTimerEventHandler
Implementa um retorno de chamada, que é chamado pela API de animação quando ocorrem eventos de tempo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationTimerEventHandler : public CUIAnimationTimerEventHandlerBase<CAnimationTimerEventHandler>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationTimerEventHandler::CreateInstance](#createinstance)|Cria uma instância de `CAnimationTimerEventHandler` retorno de chamada.|  
|[CAnimationTimerEventHandler::OnPostUpdate](#onpostupdate)|Trata os eventos que ocorrem após uma atualização de animação é concluída. (Substitui `CUIAnimationTimerEventHandlerBase::OnPostUpdate`.)|  
|[CAnimationTimerEventHandler::OnPreUpdate](#onpreupdate)|Trata os eventos que ocorrem antes do início de uma atualização de animação. (Substitui `CUIAnimationTimerEventHandlerBase::OnPreUpdate`.)|  
|[CAnimationTimerEventHandler::OnRenderingTooSlow](#onrenderingtooslow)|Trata os eventos que ocorrem quando a taxa de quadros de renderização para uma animação estiver abaixo a taxa de quadros desejável mínimo. (Substitui `CUIAnimationTimerEventHandlerBase::OnRenderingTooSlow`.)|  
|[CAnimationTimerEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|  
  
## <a name="remarks"></a>Comentários  
 Este manipulador de eventos é criado e transmitido para IUIAnimationTimer::SetTimerEventHandler quando você chamar CAnimationController::EnableAnimationTimerEventHandler.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationTimerEventHandlerBase`  
  
 `CAnimationTimerEventHandler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="createinstance"></a>CAnimationTimerEventHandler::CreateInstance  
 Cria uma instância de retorno de chamada CAnimationTimerEventHandler.  
  
```  
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,  
    IUIAnimationTimerEventHandler** ppTimerEventHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que irá receber eventos.  
  
 `ppTimerEventHandler`  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="onpostupdate"></a>CAnimationTimerEventHandler::OnPostUpdate  
 Trata os eventos que ocorrem após uma atualização de animação é concluída.  
  
```  
IFACEMETHOD(OnPostUpdate)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário E_FAIL.  
  
##  <a name="onpreupdate"></a>CAnimationTimerEventHandler::OnPreUpdate  
 Trata os eventos que ocorrem antes do início de uma atualização de animação.  
  
```  
IFACEMETHOD(OnPreUpdate)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário E_FAIL.  
  
##  <a name="onrenderingtooslow"></a>CAnimationTimerEventHandler::OnRenderingTooSlow  
 Trata os eventos que ocorrem quando a taxa de quadros de renderização para uma animação estiver abaixo a taxa de quadros desejável mínimo.  
  
```  
IFACEMETHOD(OnRenderingTooSlow)(UINT32 fps);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fps`  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário E_FAIL.  
  
##  <a name="setanimationcontroller"></a>CAnimationTimerEventHandler::SetAnimationController  
 Armazena um ponteiro para o controlador de animação para eventos de rota.  
  
```  
void SetAnimationController(CAnimationController* pAnimationController);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que irá receber eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
