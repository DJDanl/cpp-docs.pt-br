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
ms.openlocfilehash: 497b6e0f5bdeb817eccb0bb42f66763a97da2af0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50445728"
---
# <a name="canimationmanagereventhandler-class"></a>Classe CAnimationManagerEventHandler

Implementa um retorno de chamada, que é chamado pela API de animação quando um status de um Gerenciador de animação é alterado.

## <a name="syntax"></a>Sintaxe

```
class CAnimationManagerEventHandler : public CUIAnimationManagerEventHandlerBase<CAnimationManagerEventHandler>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationManagerEventHandler::CAnimationManagerEventHandler](#canimationmanagereventhandler)|Constrói um objeto `CAnimationManagerEventHandler`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationManagerEventHandler::CreateInstance](#createinstance)|Cria uma instância de `CAnimationManagerEventHandler` objeto.|
|[CAnimationManagerEventHandler::OnManagerStatusChanged](#onmanagerstatuschanged)|Chamado quando um status de Gerenciador de animação é alterado. (Substitui `CUIAnimationManagerEventHandlerBase::OnManagerStatusChanged`.)|
|[CAnimationManagerEventHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|

## <a name="remarks"></a>Comentários

Esse manipulador de eventos é criado e passado para o método IUIAnimationManager::SetManagerEventHandler, quando você chama CAnimationController::EnableAnimationManagerEvent.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationManagerEventHandlerBase`

`CAnimationManagerEventHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="canimationmanagereventhandler"></a>  CAnimationManagerEventHandler::CAnimationManagerEventHandler

O Visual Studio 2010 SP1 é necessário.

Constrói um objeto CAnimationManagerEventHandler.

```
CAnimationManagerEventHandler();
```

##  <a name="createinstance"></a>  CAnimationManagerEventHandler::CreateInstance

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
Saída. Se o método obtiver êxito ela contém um ponteiro para objeto COM que manipulará as atualizações de status para um Gerenciador de animação.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="onmanagerstatuschanged"></a>  CAnimationManagerEventHandler::OnManagerStatusChanged

O Visual Studio 2010 SP1 é necessário.

Chamado quando um status de Gerenciador de animação é alterado.

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

### <a name="return-value"></a>Valor de retorno

Sempre a implementação atual Retorna S_OK;

##  <a name="setanimationcontroller"></a>  CAnimationManagerEventHandler::SetAnimationController

O Visual Studio 2010 SP1 é necessário.

Armazena um ponteiro para o controlador de animação para eventos de rota.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
