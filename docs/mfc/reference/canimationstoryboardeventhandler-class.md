---
title: Classe CAnimationStoryboardEventHandler
ms.date: 11/04/2016
f1_keywords:
- CAnimationStoryboardEventHandler
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler::CreateInstance
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler::OnStoryboardStatusChanged
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler::OnStoryboardUpdated
- AFXANIMATIONCONTROLLER/CAnimationStoryboardEventHandler::SetAnimationController
helpviewer_keywords:
- CAnimationStoryboardEventHandler [MFC], CAnimationStoryboardEventHandler
- CAnimationStoryboardEventHandler [MFC], CreateInstance
- CAnimationStoryboardEventHandler [MFC], OnStoryboardStatusChanged
- CAnimationStoryboardEventHandler [MFC], OnStoryboardUpdated
- CAnimationStoryboardEventHandler [MFC], SetAnimationController
ms.assetid: 10a7e86b-c02d-4124-9a2e-61ecf8ac62fc
ms.openlocfilehash: d12f38491cf3aafca41756ce97e1cad44deb67d5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62338253"
---
# <a name="canimationstoryboardeventhandler-class"></a>Classe CAnimationStoryboardEventHandler

Implementa um retorno de chamada, que é chamado pela API de animação quando o status de um storyboard é alterado ou um storyboard é atualizado.

## <a name="syntax"></a>Sintaxe

```
class CAnimationStoryboardEventHandler : public CUIAnimationStoryboardEventHandlerBase<CAnimationStoryboardEventHandler>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler](#canimationstoryboardeventhandler)|Constrói um objeto `CAnimationStoryboardEventHandler`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationStoryboardEventHandler::CreateInstance](#createinstance)|Cria uma instância de `CAnimationStoryboardEventHandler` retorno de chamada.|
|[CAnimationStoryboardEventHandler::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Manipula `OnStoryboardStatusChanged` eventos que ocorrem quando status de um storyboard é alterado (substitui `CUIAnimationStoryboardEventHandlerBase::OnStoryboardStatusChanged`.)|
|[CAnimationStoryboardEventHandler::OnStoryboardUpdated](#onstoryboardupdated)|Manipula `OnStoryboardUpdated` eventos que ocorrem quando um storyboard é atualizado (substitui `CUIAnimationStoryboardEventHandlerBase::OnStoryboardUpdated`.)|
|[CAnimationStoryboardEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|

## <a name="remarks"></a>Comentários

Esse manipulador de eventos é criado e passado para `IUIAnimationStoryboard::SetStoryboardEventHandler` método, quando você chama `CAnimationController::EnableStoryboardEventHandler`.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationStoryboardEventHandlerBase`

`CAnimationStoryboardEventHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="canimationstoryboardeventhandler"></a>  CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler

Constrói um objeto CAnimationStoryboardEventHandler.

```
CAnimationStoryboardEventHandler();
```

##  <a name="createinstance"></a>  CAnimationStoryboardEventHandler::CreateInstance

Cria uma instância de retorno de chamada CAnimationStoryboardEventHandler.

```
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,
    IUIAnimationStoryboardEventHandler** ppHandler);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

*ppHandler*

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="onstoryboardstatuschanged"></a>  CAnimationStoryboardEventHandler::OnStoryboardStatusChanged

Manipula eventos OnStoryboardStatusChanged, que ocorrem quando status de um storyboard é alterado

```
IFACEMETHOD(OnStoryboardStatusChanged) (
    __in IUIAnimationStoryboard* storyboard,
    __in UI_ANIMATION_STORYBOARD_STATUS newStatus,
    __in UI_ANIMATION_STORYBOARD_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*storyboard*<br/>
Um ponteiro para o storyboard cujo status foi alterado.

*newStatus*<br/>
Especifica o novo status de storyboard.

*previousStatus*<br/>
Especifica o status anterior do storyboard.

### <a name="return-value"></a>Valor de retorno

S_OK se o método for bem-sucedido; Caso contrário, E_FAIL.

##  <a name="onstoryboardupdated"></a>  CAnimationStoryboardEventHandler::OnStoryboardUpdated

Manipula eventos OnStoryboardUpdated, que ocorrem quando um storyboard é atualizado

```
IFACEMETHOD(OnStoryboardUpdated) (__in IUIAnimationStoryboard* storyboard);
```

### <a name="parameters"></a>Parâmetros

*storyboard*<br/>
Um ponteiro para criar um storyboard, que foi atualizado.

### <a name="return-value"></a>Valor de retorno

S_OK se o método for bem-sucedido; Caso contrário, E_FAIL.

##  <a name="setanimationcontroller"></a>  CAnimationStoryboardEventHandler::SetAnimationController

Armazena um ponteiro para o controlador de animação para eventos de rota.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
