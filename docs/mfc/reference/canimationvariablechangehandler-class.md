---
title: Classe CAnimationVariableChangeHandler
ms.date: 11/04/2016
f1_keywords:
- CAnimationVariableChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler::OnValueChanged
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler::SetAnimationController
helpviewer_keywords:
- CAnimationVariableChangeHandler [MFC], OnValueChanged
- CAnimationVariableChangeHandler [MFC], SetAnimationController
ms.assetid: 2ea4996d-5c04-4dfc-be79-d42d55050795
ms.openlocfilehash: 92189ce5ea76811496d4462aa4254bbd03ebb219
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257599"
---
# <a name="canimationvariablechangehandler-class"></a>Classe CAnimationVariableChangeHandler

Implementa um retorno de chamada, que é chamado pela API de animação quando o valor de uma variável de animação é alterado.

## <a name="syntax"></a>Sintaxe

```
class CAnimationVariableChangeHandler : public CUIAnimationVariableChangeHandlerBase<CAnimationVariableChangeHandler>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|`CAnimationVariableChangeHandler::CAnimationVariableChangeHandler`|Constrói um objeto `CAnimationVariableChangeHandler`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|`CAnimationVariableChangeHandler::CreateInstance`|Cria uma instância de `CAnimationVariableChangeHandler` objeto.|
|[CAnimationVariableChangeHandler::OnValueChanged](#onvaluechanged)|Chamado quando um valor de uma variável de animação é alterado. (Substitui `CUIAnimationVariableChangeHandlerBase::OnValueChanged`.)|
|[CAnimationVariableChangeHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para eventos de rota.|

## <a name="remarks"></a>Comentários

Esse manipulador de eventos é criado e passado para `IUIAnimationVariable::SetVariableChangeHandler` método, quando você chama `CAnimationVariable::EnableValueChangedEvent` ou `CAnimationBaseObject::EnableValueChangedEvent` (que permite que esse evento para todas as variáveis de animação encapsulado em um objeto de animação).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CUIAnimationCallbackBase`

`CUIAnimationVariableChangeHandlerBase`

`CAnimationVariableChangeHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

##  <a name="onvaluechanged"></a>  CAnimationVariableChangeHandler::OnValueChanged

Chamado quando um valor de uma variável de animação é alterado.

```
IFACEMETHOD(OnValueChanged) (
    __in IUIAnimationStoryboard* storyboard,
    __in IUIAnimationVariable* variable,
    __in DOUBLE newValue,
    __in DOUBLE previousValue);
```

### <a name="parameters"></a>Parâmetros

*storyboard*<br/>
O storyboard que estiver animando a variável.

*variable*<br/>
A variável de animação que foi atualizada.

*newValue*<br/>
O novo valor.

*previousValue*<br/>
O valor anterior.

### <a name="return-value"></a>Valor de retorno

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retornará um código de erro HRESULT.

##  <a name="setanimationcontroller"></a>  CAnimationVariableChangeHandler::SetAnimationController

Armazena um ponteiro para o controlador de animação para eventos de rota.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Consulte também

[Classes](../../mfc/reference/mfc-classes.md)
