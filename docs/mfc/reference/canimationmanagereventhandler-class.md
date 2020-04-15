---
title: Classe CAnimationManagerEventHandler
ms.date: 11/04/2016
f1_keywords:
- CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::CAnimationManagerEventHandler
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::CreateInstance
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::OnManagerStatusChanged
- AFXANIMATIONCONTROLLER/CAnimationManagerEventHandler::SetAnimationController
helpviewer_keywords:
- CAnimationManagerEventHandler [MFC], CAnimationManagerEventHandler
- CAnimationManagerEventHandler [MFC], CreateInstance
- CAnimationManagerEventHandler [MFC], OnManagerStatusChanged
- CAnimationManagerEventHandler [MFC], SetAnimationController
ms.assetid: 6089ec07-e661-4805-b227-823b4652aade
ms.openlocfilehash: a4e97c2a1188071b5bde0781630d0dfe52e8a72f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81369715"
---
# <a name="canimationmanagereventhandler-class"></a>Classe CAnimationManagerEventHandler

Implementa um retorno de chamada, que é chamado pela API de animação quando um status de um gerenciador de animação é alterado.

## <a name="syntax"></a>Sintaxe

```
class CAnimationManagerEventHandler : public CUIAnimationManagerEventHandlerBase<CAnimationManagerEventHandler>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationManagerManipulador de eventos::CAnimationManagerEventHandler](#canimationmanagereventhandler)|Constrói um objeto `CAnimationManagerEventHandler`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationManagerEventHandler::CreateInstance](#createinstance)|Cria uma `CAnimationManagerEventHandler` instância de objeto.|
|[CAnimationManagerEventHandler::OnManagerStatusChanged](#onmanagerstatuschanged)|Chamado quando um status de gerenciador de animação mudou. (Substitui `CUIAnimationManagerEventHandlerBase::OnManagerStatusChanged`.)|
|[CAnimationManagerEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para rodar eventos.|

## <a name="remarks"></a>Comentários

Este manipulador de eventos é criado e passado para o método IUIAnimationManager::SetManagerEventHandler, quando você chama CAnimationController::EnableAnimationManagerEvent.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationManagerEventHandlerBase`

`CAnimationManagerEventHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationmanagereventhandlercanimationmanagereventhandler"></a><a name="canimationmanagereventhandler"></a>CAnimationManagerManipulador de eventos::CAnimationManagerEventHandler

O Visual Studio 2010 SP1 é necessário.

Constrói um objeto CAnimationManagerEventHandler.

```
CAnimationManagerEventHandler();
```

## <a name="canimationmanagereventhandlercreateinstance"></a><a name="createinstance"></a>CAnimationManagerEventHandler::CreateInstance

O Visual Studio 2010 SP1 é necessário.

Cria uma instância do objeto CAnimationManagerEventHandler.

```
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,
    IUIAnimationManagerEventHandler** ppManagerEventHandler);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

*ppManagerEventHandler*<br/>
Saída. Se o método for bem-sucedido, ele contém um ponteiro para objeto COM que lidará com atualizações de status para um gerenciador de animação.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="canimationmanagereventhandleronmanagerstatuschanged"></a><a name="onmanagerstatuschanged"></a>CAnimationManagerEventHandler::OnManagerStatusChanged

O Visual Studio 2010 SP1 é necessário.

Chamado quando um status de gerenciador de animação mudou.

```
IFACEMETHOD(OnManagerStatusChanged)(
    UI_ANIMATION_MANAGER_STATUS newStatus,
    UI_ANIMATION_MANAGER_STATUS previousStatus);
```

### <a name="parameters"></a>Parâmetros

*newStatus*<br/>
Novo status.

*previousStatus*<br/>
Status anterior.

### <a name="return-value"></a>Valor retornado

A implementação atual sempre retorna S_OK;

## <a name="canimationmanagereventhandlersetanimationcontroller"></a><a name="setanimationcontroller"></a>CAnimationManagerEventHandler::SetAnimationController

O Visual Studio 2010 SP1 é necessário.

Armazena um ponteiro para o controlador de animação para rodar eventos.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
