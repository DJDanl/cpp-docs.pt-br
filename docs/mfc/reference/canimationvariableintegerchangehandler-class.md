---
title: Classe CAnimationVariableIntegerChangeHandler
ms.date: 11/04/2016
f1_keywords:
- CAnimationVariableIntegerChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableIntegerChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableIntegerChangeHandler::CAnimationVariableIntegerChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableIntegerChangeHandler::CreateInstance
- AFXANIMATIONCONTROLLER/CAnimationVariableIntegerChangeHandler::OnIntegerValueChanged
- AFXANIMATIONCONTROLLER/CAnimationVariableIntegerChangeHandler::SetAnimationController
helpviewer_keywords:
- CAnimationVariableIntegerChangeHandler [MFC], CAnimationVariableIntegerChangeHandler
- CAnimationVariableIntegerChangeHandler [MFC], CreateInstance
- CAnimationVariableIntegerChangeHandler [MFC], OnIntegerValueChanged
- CAnimationVariableIntegerChangeHandler [MFC], SetAnimationController
ms.assetid: 6ac8e91b-e514-4ff6-babd-33f77c4b2b61
ms.openlocfilehash: 261f8eb17953c047fcc8ec05ae48dc369de4614c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377034"
---
# <a name="canimationvariableintegerchangehandler-class"></a>Classe CAnimationVariableIntegerChangeHandler

Implementa um retorno de chamada, que é chamado pela API de animação quando o valor de uma variável de animação muda.

## <a name="syntax"></a>Sintaxe

```
class CAnimationVariableIntegerChangeHandler : public CUIAnimationVariableIntegerChangeHandlerBase<CAnimationVariableIntegerChangeHandler>;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariableIntegerChangeHandler:CAnimationVariableIntegerChangeHandler](#canimationvariableintegerchangehandler)|Constrói um objeto `CAnimationVariableIntegerChangeHandler`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CAnimationVariableIntegerChangeHandler::CreateInstance](#createinstance)|Cria uma `CAnimationVariableIntegerChangeHandler` instância de retorno de chamada.|
|[CAnimationVariableIntegerChangeHandler:OnIntegerValueChanged](#onintegervaluechanged)|Chamado quando um valor de uma variável de animação mudou. (Substitui `CUIAnimationVariableIntegerChangeHandlerBase::OnIntegerValueChanged`.)|
|[CAnimationVariableIntegerChangeHandler::SetAnimationController](#setanimationcontroller)|Armazena um ponteiro para o controlador de animação para rodar eventos.|

## <a name="remarks"></a>Comentários

Este manipulador de eventos é criado e passado para o método IUIAnimationVariable::SetVariableIntegerChangeHandler method, quando você chama CAnimationVariable::EnableIntegerValueChangedEvent ou CAnimationBaseObject:EnableIntegerValueChangedEvent (que habilita esse evento para todas as variáveis de animação encapsuladas em um objeto de animação).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Classes do MFC](../../mfc/reference/mfc-classes.md)

`CUIAnimationCallbackBase`

`CUIAnimationVariableIntegerChangeHandlerBase`

`CAnimationVariableIntegerChangeHandler`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxanimationcontroller.h

## <a name="canimationvariableintegerchangehandlercanimationvariableintegerchangehandler"></a><a name="canimationvariableintegerchangehandler"></a>CAnimationVariableIntegerChangeHandler:CAnimationVariableIntegerChangeHandler

Constrói um objeto CAnimationVariableIntegerChangeHandler.

```
CAnimationVariableIntegerChangeHandler ();
```

## <a name="canimationvariableintegerchangehandlercreateinstance"></a><a name="createinstance"></a>CAnimationVariableIntegerChangeHandler::CreateInstance

Cria uma instância de retorno de chamada CAnimationVariableIntegerChangeHandler.

```
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CAnimationController* pAnimationController,
    IUIAnimationVariableIntegerChangeHandler** ppHandler);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

*ppHandler*

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="canimationvariableintegerchangehandleronintegervaluechanged"></a><a name="onintegervaluechanged"></a>CAnimationVariableIntegerChangeHandler:OnIntegerValueChanged

Chamado quando um valor de uma variável de animação mudou.

```
IFACEMETHOD(OnIntegerValueChanged) (
    __in IUIAnimationStoryboard* storyboard,
    __in IUIAnimationVariable* variable,
    __in INT32 newValue,
    __in INT32 previousValue);
```

### <a name="parameters"></a>Parâmetros

*Storyboard*<br/>
O storyboard que está animando a variável.

*variável*<br/>
A variável de animação que foi atualizada.

*newValue*<br/>
O novo valor arredondado.

*anteriorValor*<br/>
O valor arredondado anterior.

### <a name="return-value"></a>Valor retornado

S_OK se o método for bem sucedido; caso contrário, E_FAIL.

## <a name="canimationvariableintegerchangehandlersetanimationcontroller"></a><a name="setanimationcontroller"></a>CAnimationVariableIntegerChangeHandler::SetAnimationController

Armazena um ponteiro para o controlador de animação para rodar eventos.

```
void SetAnimationController(CAnimationController* pAnimationController);
```

### <a name="parameters"></a>Parâmetros

*pAnimationController*<br/>
Um ponteiro para o controlador de animação, que receberá eventos.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
