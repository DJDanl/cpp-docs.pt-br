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
ms.openlocfilehash: 36b8b524591693775403d66fdc1f0754aaf67778
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364995"
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
|[CAnimationStoryboardEventHandler::CreateInstance](#createinstance)|Cria uma `CAnimationStoryboardEventHandler` instância de retorno de chamada.|
|[CAnimationStoryboardEventHandler::OnStoryboardStatusChanged](#onstoryboardstatuschanged)|Lida `OnStoryboardStatusChanged` com eventos, que ocorrem quando o status `CUIAnimationStoryboardEventHandlerBase::OnStoryboardStatusChanged`de um storyboard muda (Overrides .)|
|[CAnimationStoryboardEventHandler::OnStoryboardAtualizado](#onstoryboardupdated)|Lida `OnStoryboardUpdated` com eventos, que ocorrem quando um `CUIAnimationStoryboardEventHandlerBase::OnStoryboardUpdated`storyboard é atualizado (Overrides .)|
|[CAnimationStoryboardEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para rodar eventos.|

## <a name="remarks"></a>Comentários

Este manipulador de eventos é `IUIAnimationStoryboard::SetStoryboardEventHandler` criado e `CAnimationController::EnableStoryboardEventHandler`passado para o método, quando você chama .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationStoryboardEventHandlerBase`

`CAnimationStoryboardEventHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationstoryboardeventhandlercanimationstoryboardeventhandler"></a><a name="canimationstoryboardeventhandler"></a>CAnimationStoryboardEventHandler::CAnimationStoryboardEventHandler

Constrói um objeto CAnimationStoryboardEventHandler.

```
CAnimationStoryboardEventHandler();
```

## <a name="canimationstoryboardeventhandlercreateinstance"></a><a name="createinstance"></a>CAnimationStoryboardEventHandler::CreateInstance

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

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="canimationstoryboardeventhandleronstoryboardstatuschanged"></a><a name="onstoryboardstatuschanged"></a>CAnimationStoryboardEventHandler::OnStoryboardStatusChanged

Lida com onStoryboardEventosalterados, que ocorrem quando o status de um storyboard muda

```
IFACEMETHOD(OnStoryboardStatusChanged) (
    __in IUIAnimationStoryboard* storyboard,
    __in UI_ANIMATION_STORYBOARD_STATUS newStatus,
    __in UI_ANIMATION_STORYBOARD_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*Storyboard*<br/>
Um ponteiro para storyboard cujo status mudou.

*newStatus*<br/>
Especifica o novo status do storyboard.

*previousStatus*<br/>
Especifica o status do storyboard anterior.

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido; caso contrário, E_FAIL.

## <a name="canimationstoryboardeventhandleronstoryboardupdated"></a><a name="onstoryboardupdated"></a>CAnimationStoryboardEventHandler::OnStoryboardAtualizado

Lida com eventos onStoryboardAtualizado, que ocorrem quando um storyboard é atualizado

```
IFACEMETHOD(OnStoryboardUpdated) (__in IUIAnimationStoryboard* storyboard);
```

### <a name="parameters"></a>Parâmetros

*Storyboard*<br/>
Um ponteiro para storyboard, que foi atualizado.

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido; caso contrário, E_FAIL.

## <a name="canimationstoryboardeventhandlersetanimationcontroller"></a><a name="setanimationcontroller"></a>CAnimationStoryboardEventHandler::SetAnimationController

Armazena um ponteiro para o controlador de animação para rodar eventos.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
