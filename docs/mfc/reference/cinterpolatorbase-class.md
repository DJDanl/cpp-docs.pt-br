---
title: Classe CInterpolatorBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase::CInterpolatorBase
- AFXANIMATIONCONTROLLER/CInterpolatorBase::CreateInstance
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetDependencies
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetDuration
- AFXANIMATIONCONTROLLER/CInterpolatorBase::GetFinalValue
- AFXANIMATIONCONTROLLER/CInterpolatorBase::InterpolateValue
- AFXANIMATIONCONTROLLER/CInterpolatorBase::InterpolateVelocity
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetCustomInterpolator
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetDuration
- AFXANIMATIONCONTROLLER/CInterpolatorBase::SetInitialValueAndVelocity
dev_langs:
- C++
helpviewer_keywords:
- CInterpolatorBase [MFC], CInterpolatorBase
- CInterpolatorBase [MFC], CreateInstance
- CInterpolatorBase [MFC], GetDependencies
- CInterpolatorBase [MFC], GetDuration
- CInterpolatorBase [MFC], GetFinalValue
- CInterpolatorBase [MFC], InterpolateValue
- CInterpolatorBase [MFC], InterpolateVelocity
- CInterpolatorBase [MFC], SetCustomInterpolator
- CInterpolatorBase [MFC], SetDuration
- CInterpolatorBase [MFC], SetInitialValueAndVelocity
ms.assetid: bbc3dce7-8398-47f9-b97e-e4fd2d737232
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c0ca520fe89e04d984e6490c495f2622a6037c79
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cinterpolatorbase-class"></a>Classe CInterpolatorBase
Implementa um retorno de chamada, que é chamado pela API de animação quando ele tem que calcular um novo valor de uma variável de animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInterpolatorBase : public CUIAnimationInterpolatorBase<CInterpolatorBase>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterpolatorBase::CInterpolatorBase](#cinterpolatorbase)|Constrói o `CInterpolatorBase` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterpolatorBase::CreateInstance](#createinstance)|Cria uma instância de `CInterpolatorBase` e armazena um ponteiro para interpolador personalizado, que será manipulação de eventos.|  
|[CInterpolatorBase::GetDependencies](#getdependencies)|Obtém as dependências do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDependencies`.)|  
|[CInterpolatorBase::GetDuration](#getduration)|Obtém a duração do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDuration`.)|  
|[CInterpolatorBase::GetFinalValue](#getfinalvalue)|Obtém o valor final para o qual o interpolador clientes potenciais. (Substitui `CUIAnimationInterpolatorBase::GetFinalValue`.)|  
|[CInterpolatorBase::InterpolateValue](#interpolatevalue)|Interpola o valor em um determinado deslocamento (substitui `CUIAnimationInterpolatorBase::InterpolateValue`.)|  
|[CInterpolatorBase::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um determinado deslocamento (substitui `CUIAnimationInterpolatorBase::InterpolateVelocity`.)|  
|[CInterpolatorBase::SetCustomInterpolator](#setcustominterpolator)|Armazena um ponteiro para interpolador personalizado, que será manipulação de eventos.|  
|[CInterpolatorBase::SetDuration](#setduration)|Define a duração do interpolador (substitui `CUIAnimationInterpolatorBase::SetDuration`.)|  
|[CInterpolatorBase::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador. (Substitui `CUIAnimationInterpolatorBase::SetInitialValueAndVelocity`.)|  
  
## <a name="remarks"></a>Comentários  
 Esse manipulador é criado e transmitido para `IUIAnimationTransitionFactory::CreateTransition` quando um `CCustomTransition` objeto está sendo criado como parte do processo de inicialização de animação (iniciado por `CAnimationController::AnimateGroup`). Normalmente, você não precisa usar essa classe diretamente, ele apenas routs todos os eventos para um `CCustomInterpolator`-derivado da classe, cujo ponteiro é transmitido ao construtor de `CCustomTransition`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationInterpolatorBase`  
  
 `CInterpolatorBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="cinterpolatorbase"></a>  CInterpolatorBase::CInterpolatorBase  
 Constrói o objeto CInterpolatorBase.  
  
```  
CInterpolatorBase();
```  
  
##  <a name="createinstance"></a>  CInterpolatorBase::CreateInstance  
 Cria uma instância de CInterpolatorBase e armazena um ponteiro para interpolador personalizado, que será manipulação de eventos.  
  
```  
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CCustomInterpolator* pInterpolator,  
    IUIAnimationInterpolator** ppHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInterpolator`  
 Um ponteiro para interpolador personalizado.  
  
 `ppHandler`  
 Saída. Contém um ponteiro para a instância do CInterpolatorBase quando a função retorna.  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="getdependencies"></a>  CInterpolatorBase::GetDependencies  
 Obtém as dependências do interpolador.  
  
```  
IFACEMETHOD(GetDependencies)(
    __out UI_ANIMATION_DEPENDENCIES* initialValueDependencies,
    __out UI_ANIMATION_DEPENDENCIES* initialVelocityDependencies,
    __out UI_ANIMATION_DEPENDENCIES* durationDependencies);
```  
  
### <a name="parameters"></a>Parâmetros  
 `initialValueDependencies`  
 Saída. Aspectos do interpolador que dependem do valor inicial é passado para SetInitialValueAndVelocity.  
  
 `initialVelocityDependencies`  
 Saída. Aspectos do interpolador que dependem da velocidade inicial passado para SetInitialValueAndVelocity.  
  
 `durationDependencies`  
 Saída. Aspectos que dependem da duração do interpolador passado para SetDuration.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetDependencies.  
  
##  <a name="getduration"></a>  CInterpolatorBase::GetDuration  
 Obtém a duração do interpolador.  
  
```  
IFACEMETHOD(GetDuration)(__out UI_ANIMATION_SECONDS* duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 Saída. A duração da transição, em segundos.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetDuration.  
  
##  <a name="getfinalvalue"></a>  CInterpolatorBase::GetFinalValue  
 Obtém o valor final para o qual o interpolador clientes potenciais.  
  
```  
IFACEMETHOD(GetFinalValue)(__out DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value`  
 Saída. O valor final de uma variável no final da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetFinalValue.  
  
##  <a name="interpolatevalue"></a>  CInterpolatorBase::InterpolateValue  
 Interpola o valor em um determinado deslocamento  
  
```  
IFACEMETHOD(InterpolateValue)(
  __in UI_ANIMATION_SECONDS offset, 
  __out DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `offset`  
 O deslocamento do início da transição. O deslocamento é sempre maior que ou igual a zero e menor que a duração da transição. Este método não é chamado se a duração da transição é zero.  
  
 `value`  
 Saída. O valor interpolado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método InterpolateValue.  
  
##  <a name="interpolatevelocity"></a>  CInterpolatorBase::InterpolateVelocity  
 Interpola a velocidade em um determinado deslocamento  
  
```  
IFACEMETHOD(InterpolateVelocity)(
  __in UI_ANIMATION_SECONDS offset,
  __out DOUBLE* velocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `offset`  
 O deslocamento do início da transição. O deslocamento é sempre maior que ou igual a zero e menor ou igual a duração da transição. Este método não é chamado se a duração da transição é zero.  
  
 `velocity`  
 Saída. A velocidade da variável no deslocamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método InterpolateVelocity.  
  
##  <a name="setcustominterpolator"></a>  CInterpolatorBase::SetCustomInterpolator  
 Armazena um ponteiro para interpolador personalizado, que será manipulação de eventos.  
  
```  
void SetCustomInterpolator(CCustomInterpolator* pInterpolator);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInterpolator`  
 Um ponteiro para interpolador personalizado.  
  
##  <a name="setduration"></a>  CInterpolatorBase::SetDuration  
 Define a duração do interpolador  
  
```  
IFACEMETHOD(SetDuration)(__in UI_ANIMATION_SECONDS duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método SetDuration.  
  
##  <a name="setinitialvalueandvelocity"></a>  CInterpolatorBase::SetInitialValueAndVelocity  
 Define o valor inicial e a velocidade do interpolador.  
  
```  
IFACEMETHOD(SetInitialValueAndVelocity)(
  __in DOUBLE initialValue, 
  __in DOUBLE initialVelocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `initialValue`  
 O valor da variável no início da transição.  
  
 `initialVelocity`  
 A velocidade da variável no início da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Ele retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método SetInitialValueAndVelocity.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
