---
title: Classe CAnimationTimerEventHandler | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxanimationcontroller/CAnimationTimerEventHandler
- CAnimationTimerEventHandler
dev_langs:
- C++
helpviewer_keywords:
- CAnimationTimerEventHandler class
ms.assetid: 188dea3b-4b5e-4f6b-8df9-09d993a21619
caps.latest.revision: 18
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 5412c215caf85440e923e8a083ed310f8960849a
ms.lasthandoff: 02/25/2017

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
|[CAnimationTimerEventHandler::OnPostUpdate](#onpostupdate)|Trata os eventos que ocorrem após uma atualização de animação. (Substitui `CUIAnimationTimerEventHandlerBase::OnPostUpdate`.)|  
|[CAnimationTimerEventHandler::OnPreUpdate](#onpreupdate)|Trata os eventos que ocorrem antes do início de uma atualização de animação. (Substitui `CUIAnimationTimerEventHandlerBase::OnPreUpdate`.)|  
|[CAnimationTimerEventHandler::OnRenderingTooSlow](#onrenderingtooslow)|Trata os eventos que ocorrem quando a taxa de quadros de renderização para uma animação cai abaixo a taxa de quadros desejável mínimo. (Substitui `CUIAnimationTimerEventHandlerBase::OnRenderingTooSlow`.)|  
|[CAnimationTimerEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|  
  
## <a name="remarks"></a>Comentários  
 Esse manipulador de eventos é criado e passado para IUIAnimationTimer::SetTimerEventHandler ao chamar CAnimationController::EnableAnimationTimerEventHandler.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationTimerEventHandlerBase`  
  
 `CAnimationTimerEventHandler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-namecreateinstancea--canimationtimereventhandlercreateinstance"></a><a name="createinstance"></a>CAnimationTimerEventHandler::CreateInstance  
 Cria uma instância de retorno de chamada CAnimationTimerEventHandler.  
  
```  
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,  
    IUIAnimationTimerEventHandler** ppTimerEventHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que receberá eventos.  
  
 `ppTimerEventHandler`  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="a-nameonpostupdatea--canimationtimereventhandleronpostupdate"></a><a name="onpostupdate"></a>CAnimationTimerEventHandler::OnPostUpdate  
 Trata os eventos que ocorrem após uma atualização de animação.  
  
```  
IFACEMETHOD(OnPostUpdate)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário, E_FAIL.  
  
##  <a name="a-nameonpreupdatea--canimationtimereventhandleronpreupdate"></a><a name="onpreupdate"></a>CAnimationTimerEventHandler::OnPreUpdate  
 Trata os eventos que ocorrem antes do início de uma atualização de animação.  
  
```  
IFACEMETHOD(OnPreUpdate)();
```  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário, E_FAIL.  
  
##  <a name="a-nameonrenderingtooslowa--canimationtimereventhandleronrenderingtooslow"></a><a name="onrenderingtooslow"></a>CAnimationTimerEventHandler::OnRenderingTooSlow  
 Trata os eventos que ocorrem quando a taxa de quadros de renderização para uma animação cai abaixo a taxa de quadros desejável mínimo.  
  
```  
IFACEMETHOD(OnRenderingTooSlow)(UINT32 fps);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fps`  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se o método for bem-sucedido; Caso contrário, E_FAIL.  
  
##  <a name="a-namesetanimationcontrollera--canimationtimereventhandlersetanimationcontroller"></a><a name="setanimationcontroller"></a>CAnimationTimerEventHandler::SetAnimationController  
 Armazena um ponteiro para o controlador de animação para eventos de rota.  
  
```  
void SetAnimationController(CAnimationController* pAnimationController);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que receberá eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

