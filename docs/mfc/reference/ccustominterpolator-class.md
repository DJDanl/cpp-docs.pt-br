---
title: Classe CCustomInterpolator | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxanimationcontroller/CCustomInterpolator
- CCustomInterpolator
dev_langs:
- C++
helpviewer_keywords:
- CCustomInterpolator class
ms.assetid: 28d85595-989a-40a3-b003-e0e38437a94d
caps.latest.revision: 17
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
ms.sourcegitcommit: 73410ae17465880f455e5b15026f6cc010803c19
ms.openlocfilehash: 4d0b38543092dc68c2527f7e1385712164faf996
ms.lasthandoff: 02/25/2017

---
# <a name="ccustominterpolator-class"></a>Classe CCustomInterpolator
Implementa um interpolador básica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCustomInterpolator;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCustomInterpolator::CCustomInterpolator](#ccustominterpolator)|Sobrecarregado. Constrói um objeto personalizado interpolador e inicializa a duração e velocidade valores especificados.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCustomInterpolator::GetDependencies](#getdependencies)|Obtém as dependências do interpolador.|  
|[CCustomInterpolator::GetDuration](#getduration)|Obtém a duração do interpolador.|  
|[CCustomInterpolator::GetFinalValue](#getfinalvalue)|Obtém o valor final para o qual o interpolador leva.|  
|[CCustomInterpolator::Init](#init)|Inicializa a duração e o valor final.|  
|[CCustomInterpolator::InterpolateValue](#interpolatevalue)|Interpola o valor em um deslocamento especificado.|  
|[CCustomInterpolator::InterpolateVelocity](#interpolatevelocity)|Interpola a velocidade em um determinado deslocamento|  
|[CCustomInterpolator::SetDuration](#setduration)|Define a duração do interpolador.|  
|[CCustomInterpolator::SetInitialValueAndVelocity](#setinitialvalueandvelocity)|Define o valor inicial e a velocidade do interpolador.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCustomInterpolator::m_currentValue](#m_currentvalue)|O valor interpolado.|  
|[CCustomInterpolator::m_currentVelocity](#m_currentvelocity)|A velocidade interpolada.|  
|[CCustomInterpolator::m_duration](#m_duration)|A duração da transição.|  
|[CCustomInterpolator::m_finalValue](#m_finalvalue)|O valor final de uma variável no final da transição.|  
|[CCustomInterpolator::m_initialValue](#m_initialvalue)|O valor da variável no início da transição.|  
|[CCustomInterpolator::m_initialVelocity](#m_initialvelocity)|A velocidade da variável no início da transição.|  
  
## <a name="remarks"></a>Comentários  
 Derivar uma classe de CCustomInterpolator e substituir todos os métodos necessários para implementar um algoritmo de interpolação personalizada. Um ponteiro para essa classe deve ser passado como um parâmetro para CCustomTransition.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CCustomInterpolator`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-nameccustominterpolatora--ccustominterpolatorccustominterpolator"></a><a name="ccustominterpolator"></a>CCustomInterpolator::CCustomInterpolator  
 Constrói um objeto interpolador personalizados e define todos os valores para o padrão é 0.  
  
```  
CCustomInterpolator();

 
CCustomInterpolator(
    UI_ANIMATION_SECONDS duration,  
    DOUBLE finalValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
 `finalValue`  
  
### <a name="remarks"></a>Comentários  
 Use CCustomInterpolator::Init para inicializar a duração e o valor final posteriormente no código.  
  
##  <a name="a-namegetdependenciesa--ccustominterpolatorgetdependencies"></a><a name="getdependencies"></a>CCustomInterpolator::GetDependencies  
 Obtém as dependências do interpolador.  
  
```  
virtual BOOL GetDependencies(
    UI_ANIMATION_DEPENDENCIES* initialValueDependencies,  
    UI_ANIMATION_DEPENDENCIES* initialVelocityDependencies,  
    UI_ANIMATION_DEPENDENCIES* durationDependencies);
```  
  
### <a name="parameters"></a>Parâmetros  
 `initialValueDependencies`  
 Saída. Aspectos do interpolador que dependem do valor inicial é passado para SetInitialValueAndVelocity.  
  
 `initialVelocityDependencies`  
 Saída. Aspectos do interpolador que dependem da velocidade inicial passado para SetInitialValueAndVelocity.  
  
 `durationDependencies`  
 Saída. Aspectos que dependem da duração do interpolador passado para SetDuration.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-namegetdurationa--ccustominterpolatorgetduration"></a><a name="getduration"></a>CCustomInterpolator::GetDuration  
 Obtém a duração do interpolador.  
  
```  
virtual BOOL GetDuration(UI_ANIMATION_SECONDS* duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 Saída. A duração da transição, em segundos.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-namegetfinalvaluea--ccustominterpolatorgetfinalvalue"></a><a name="getfinalvalue"></a>CCustomInterpolator::GetFinalValue  
 Obtém o valor final para o qual o interpolador leva.  
  
```  
virtual BOOL GetFinalValue(DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value`  
 Saída. O valor final de uma variável no final da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-nameinita--ccustominterpolatorinit"></a><a name="init"></a>CCustomInterpolator::Init  
 Inicializa a duração e o valor final.  
  
```  
void Init(
    UI_ANIMATION_SECONDS duration,  
    DOUBLE finalValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
 `finalValue`  
 O valor final de uma variável no final da transição.  
  
##  <a name="a-nameinterpolatevaluea--ccustominterpolatorinterpolatevalue"></a><a name="interpolatevalue"></a>CCustomInterpolator::InterpolateValue  
 Interpola o valor em um deslocamento especificado.  
  
```  
virtual BOOL InterpolateValue(
    UI_ANIMATION_SECONDS */,  
    DOUBLE* value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `value`  
 Saída. O valor interpolado.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-nameinterpolatevelocitya--ccustominterpolatorinterpolatevelocity"></a><a name="interpolatevelocity"></a>CCustomInterpolator::InterpolateVelocity  
 Interpola a velocidade em um determinado deslocamento  
  
```  
virtual BOOL InterpolateVelocity(
    UI_ANIMATION_SECONDS */,  
    DOUBLE* velocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `velocity`  
 Saída. A velocidade da variável no deslocamento.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-namemcurrentvaluea--ccustominterpolatormcurrentvalue"></a><a name="m_currentvalue"></a>CCustomInterpolator::m_currentValue  
 O valor interpolado.  
  
```  
DOUBLE m_currentValue;  
```  
  
##  <a name="a-namemcurrentvelocitya--ccustominterpolatormcurrentvelocity"></a><a name="m_currentvelocity"></a>CCustomInterpolator::m_currentVelocity  
 A velocidade interpolada.  
  
```  
DOUBLE m_currentVelocity;  
```  
  
##  <a name="a-namemdurationa--ccustominterpolatormduration"></a><a name="m_duration"></a>CCustomInterpolator::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
##  <a name="a-namemfinalvaluea--ccustominterpolatormfinalvalue"></a><a name="m_finalvalue"></a>CCustomInterpolator::m_finalValue  
 O valor final de uma variável no final da transição.  
  
```  
DOUBLE m_finalValue;  
```  
  
##  <a name="a-nameminitialvaluea--ccustominterpolatorminitialvalue"></a><a name="m_initialvalue"></a>CCustomInterpolator::m_initialValue  
 O valor da variável no início da transição.  
  
```  
DOUBLE m_initialValue;  
```  
  
##  <a name="a-nameminitialvelocitya--ccustominterpolatorminitialvelocity"></a><a name="m_initialvelocity"></a>CCustomInterpolator::m_initialVelocity  
 A velocidade da variável no início da transição.  
  
```  
DOUBLE m_initialVelocity;  
```  
  
##  <a name="a-namesetdurationa--ccustominterpolatorsetduration"></a><a name="setduration"></a>CCustomInterpolator::SetDuration  
 Define a duração do interpolador.  
  
```  
virtual BOOL SetDuration(UI_ANIMATION_SECONDS duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 Implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
##  <a name="a-namesetinitialvalueandvelocitya--ccustominterpolatorsetinitialvalueandvelocity"></a><a name="setinitialvalueandvelocity"></a>CCustomInterpolator::SetInitialValueAndVelocity  
 Define o valor inicial e a velocidade do interpolador.  
  
```  
virtual BOOL SetInitialValueAndVelocity(
    DOUBLE initialValue,  
    DOUBLE initialVelocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `initialValue`  
 O valor da variável no início da transição.  
  
 `initialVelocity`  
 A velocidade da variável no início da transição.  
  
### <a name="return-value"></a>Valor de retorno  
 A implementação básica sempre retorna TRUE. Retornar FALSE de implementação substituída se desejar que o evento de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

