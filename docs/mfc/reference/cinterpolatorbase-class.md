---
title: Classe CInterpolatorBase | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- CInterpolatorBase class
ms.assetid: bbc3dce7-8398-47f9-b97e-e4fd2d737232
caps.latest.revision: 19
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 44c67eef38b34a2a3cf677b42a40304c01668b42
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cinterpolatorbase-class"></a>Classe CInterpolatorBase
Implementa um retorno de chamada, que é chamado pela API de animação quando é preciso calcular um novo valor de uma variável de animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CInterpolatorBase : public CUIAnimationInterpolatorBase<CInterpolatorBase>;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterpolatorBase::CInterpolatorBase](#cinterpolatorbase)|Constrói o `CInterpolatorBase` objeto.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CInterpolatorBase::CreateInstance](#createinstance)|Cria uma instância de `CInterpolatorBase` e armazena um ponteiro para interpolador personalizado, que irá manipular eventos.|  
|[CInterpolatorBase::GetDependencies](#getdependencies)|Obtém as dependências do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDependencies`.)|  
|[CInterpolatorBase::GetDuration](#getduration)|Obtém a duração do interpolador. (Substitui `CUIAnimationInterpolatorBase::GetDuration`.)|  
|[CInterpolatorBase::GetFinalValue](#getfinalvalue)|Obtém o valor final para o qual o interpolador leva. (Substitui `CUIAnimationInterpolatorBase::GetFinalValue`.)|  
|[CInterpolatorBase::InterpolateValue](#interpolatevalue)|Interpola o valor em um determinado deslocamento (substituições `CUIAnimationInterpolatorBase::InterpolateValue`.)|  
|[CInterpolatorBase::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um determinado deslocamento (substituições `CUIAnimationInterpolatorBase::InterpolateVelocity`.)|  
|[CInterpolatorBase::SetCustomInterpolator](#setcustominterpolator)|Armazena um ponteiro para interpolador personalizado, que irá manipular eventos.|  
|[CInterpolatorBase::SetDuration](#setduration)|Define a duração do interpolador (substituições `CUIAnimationInterpolatorBase::SetDuration`.)|  
|[CInterpolatorBase::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador. (Substitui `CUIAnimationInterpolatorBase::SetInitialValueAndVelocity`.)|  
  
## <a name="remarks"></a>Comentários  
 Esse manipulador é criado e passado para `IUIAnimationTransitionFactory::CreateTransition` quando um `CCustomTransition` objeto está sendo criado como parte do processo de inicialização de animação (iniciado por `CAnimationController::AnimateGroup`). Normalmente você não precisa usar essa classe diretamente, ele simplesmente encaminha todos os eventos para um `CCustomInterpolator`-derivado cujo ponteiro é passado para o construtor da classe `CCustomTransition`.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CUIAnimationCallbackBase`  
  
 `CUIAnimationInterpolatorBase`  
  
 `CInterpolatorBase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="cinterpolatorbase"></a>CInterpolatorBase::CInterpolatorBase  
 Constrói o objeto CInterpolatorBase.  
  
```  
CInterpolatorBase();
```  
  
##  <a name="createinstance"></a>CInterpolatorBase::CreateInstance  
 Cria uma instância de CInterpolatorBase e armazena um ponteiro para interpolador personalizado, que irá manipular eventos.  
  
```  
static COM_DECLSPEC_NOTHROW HRESULT CreateInstance(
    CCustomInterpolator* pInterpolator,  
    IUIAnimationInterpolator** ppHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInterpolator`  
 Um ponteiro para interpolador personalizado.  
  
 `ppHandler`  
 Saída. Contém um ponteiro para a instância de CInterpolatorBase quando a função retorna.  
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="getdependencies"></a>CInterpolatorBase::GetDependencies  
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
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetDependencies.  
  
##  <a name="getduration"></a>CInterpolatorBase::GetDuration  
 Obtém a duração do interpolador.  
  
```  
IFACEMETHOD(GetDuration)(__out UI_ANIMATION_SECONDS* duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 Saída. A duração da transição, em segundos.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetDuration.  
  
##  <a name="getfinalvalue"></a>CInterpolatorBase::GetFinalValue  
 Obtém o valor final para o qual o interpolador leva.  
  
```  
IFACEMETHOD(GetFinalValue)(__out DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value`  
 Saída. O valor final de uma variável no final da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método GetFinalValue.  
  
##  <a name="interpolatevalue"></a>CInterpolatorBase::InterpolateValue  
 Interpola o valor em um determinado deslocamento  
  
```  
IFACEMETHOD(InterpolateValue)(
  __in UI_ANIMATION_SECONDS offset, 
  __out DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `offset`  
 O deslocamento do início da transição. O deslocamento é sempre maior que ou igual a zero e menor que a duração da transição. Esse método não é chamado se a duração da transição é zero.  
  
 `value`  
 Saída. O valor interpolado.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método InterpolateValue.  
  
##  <a name="interpolatevelocity"></a>CInterpolatorBase::InterpolateVelocity  
 Interpola a velocidade em um determinado deslocamento  
  
```  
IFACEMETHOD(InterpolateVelocity)(
  __in UI_ANIMATION_SECONDS offset,
  __out DOUBLE* velocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `offset`  
 O deslocamento do início da transição. O deslocamento é sempre maior que ou igual a zero e menor ou igual a duração da transição. Esse método não é chamado se a duração da transição é zero.  
  
 `velocity`  
 Saída. A velocidade da variável no deslocamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método InterpolateVelocity.  
  
##  <a name="setcustominterpolator"></a>CInterpolatorBase::SetCustomInterpolator  
 Armazena um ponteiro para interpolador personalizado, que irá manipular eventos.  
  
```  
void SetCustomInterpolator(CCustomInterpolator* pInterpolator);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pInterpolator`  
 Um ponteiro para interpolador personalizado.  
  
##  <a name="setduration"></a>CInterpolatorBase::SetDuration  
 Define a duração do interpolador  
  
```  
IFACEMETHOD(SetDuration)(__in UI_ANIMATION_SECONDS duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método SetDuration.  
  
##  <a name="setinitialvalueandvelocity"></a>CInterpolatorBase::SetInitialValueAndVelocity  
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
 Se o método for bem-sucedido, retornará S_OK. Retornará E_FAIL se CCustomInterpolator não está definida ou implementação personalizada retorna FALSE do método SetInitialValueAndVelocity.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

