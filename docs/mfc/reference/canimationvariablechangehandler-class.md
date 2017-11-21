---
title: Classe CAnimationVariableChangeHandler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationVariableChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler::OnValueChanged
- AFXANIMATIONCONTROLLER/CAnimationVariableChangeHandler::SetAnimationController
dev_langs: C++
helpviewer_keywords:
- CAnimationVariableChangeHandler [MFC], OnValueChanged
- CAnimationVariableChangeHandler [MFC], SetAnimationController
ms.assetid: 2ea4996d-5c04-4dfc-be79-d42d55050795
caps.latest.revision: "19"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ef42f4ff5ae719ea84ef972b7462816f1f094d9b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="canimationvariablechangehandler-class"></a>Classe CAnimationVariableChangeHandler
Implementa um retorno de chamada, que é chamado pela API de animação quando o valor de uma variável de animação é alterado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationVariableChangeHandler : public CUIAnimationVariableChangeHandlerBase<CAnimationVariableChangeHandler>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
 Este manipulador de eventos é criado e transmitido para `IUIAnimationVariable::SetVariableChangeHandler` método, quando você chamar `CAnimationVariable::EnableValueChangedEvent` ou `CAnimationBaseObject::EnableValueChangedEvent` (que permite que esse evento para todas as variáveis de animação encapsulado em um objeto de animação).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationVariableChangeHandlerBase`  
  
 `CAnimationVariableChangeHandler`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="onvaluechanged"></a>CAnimationVariableChangeHandler::OnValueChanged  
 Chamado quando um valor de uma variável de animação é alterado.  
  
```  
IFACEMETHOD(OnValueChanged) (
    __in IUIAnimationStoryboard* storyboard,
    __in IUIAnimationVariable* variable,
    __in DOUBLE newValue,
    __in DOUBLE previousValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `storyboard`  
 O storyboard que é a variável de animação.  
  
 `variable`  
 A variável de animação que foi atualizada.  
  
 `newValue`  
 O novo valor.  
  
 `previousValue`  
 O valor anterior.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="setanimationcontroller"></a>CAnimationVariableChangeHandler::SetAnimationController  
 Armazena um ponteiro para o controlador de animação para eventos de rota.  
  
```  
void SetAnimationController(CAnimationController* pAnimationController);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pAnimationController`  
 Um ponteiro para o controlador de animação, que irá receber eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
