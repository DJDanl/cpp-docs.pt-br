---
title: Classe CAnimationColor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor::CAnimationColor
- AFXANIMATIONCONTROLLER/CAnimationColor::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationColor::GetB
- AFXANIMATIONCONTROLLER/CAnimationColor::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationColor::GetG
- AFXANIMATIONCONTROLLER/CAnimationColor::GetR
- AFXANIMATIONCONTROLLER/CAnimationColor::GetValue
- AFXANIMATIONCONTROLLER/CAnimationColor::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationColor::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationColor::m_bValue
- AFXANIMATIONCONTROLLER/CAnimationColor::m_gValue
- AFXANIMATIONCONTROLLER/CAnimationColor::m_rValue
dev_langs:
- C++
helpviewer_keywords:
- CAnimationColor [MFC], CAnimationColor
- CAnimationColor [MFC], AddTransition
- CAnimationColor [MFC], GetB
- CAnimationColor [MFC], GetDefaultValue
- CAnimationColor [MFC], GetG
- CAnimationColor [MFC], GetR
- CAnimationColor [MFC], GetValue
- CAnimationColor [MFC], SetDefaultValue
- CAnimationColor [MFC], GetAnimationVariableList
- CAnimationColor [MFC], m_bValue
- CAnimationColor [MFC], m_gValue
- CAnimationColor [MFC], m_rValue
ms.assetid: 88bfabd4-efeb-4652-87e8-304253d8e48c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f564b70e850f3020956711ef15ab1fe9285a6ae4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="canimationcolor-class"></a>Classe CAnimationColor
Implementa a funcionalidade de uma cor que podem ser animados cujos componentes vermelhos, verdes e azuis.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationColor : public CAnimationBaseObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationColor::CAnimationColor](#canimationcolor)|Sobrecarregado. Constrói um objeto de cor de animação.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationColor::AddTransition](#addtransition)|Adiciona as transições para componentes vermelho, verde e azul.|  
|[CAnimationColor::GetB](#getb)|Fornece acesso a CAnimationVariable que representa o componente azul.|  
|[CAnimationColor::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para componentes de cor.|  
|[CAnimationColor::GetG](#getg)|Fornece acesso a CAnimationVariable que representa o componente verde.|  
|[CAnimationColor::GetR](#getr)|Fornece acesso a CAnimationVariable que representa o componente vermelho.|  
|[CAnimationColor::GetValue](#getvalue)|Retorna o valor atual.|  
|[CAnimationColor::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationColor::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulada em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationColor::operator COLORREF](#operator_colorref)||  
|[CAnimationColor::operator =](#operator_eq)|Atribui a cor para CAnimationColor.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationColor::m_bValue](#m_bvalue)|A variável de animação encapsulada que representa o componente azul da cor de animação.|  
|[CAnimationColor::m_gValue](#m_gvalue)|A variável de animação encapsulada que representa o componente verde da cor de animação.|  
|[CAnimationColor::m_rValue](#m_rvalue)|A variável de animação encapsulada que representa o componente vermelho da cor de animação.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationColor encapsula três objetos CAnimationVariable e pode representar em aplicativos de uma cor. Por exemplo, você pode usar esta classe para animar cores de qualquer objeto na tela (como a cor do texto, cor do segundo plano etc). Para usar essa classe no aplicativo, basta instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado aos componentes vermelho, verde e azul.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 `CAnimationColor`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtransition"></a>  CAnimationColor::AddTransition  
 Adiciona as transições para componentes vermelho, verde e azul.  
  
```  
void AddTransition(
    CBaseTransition* pRTransition,  
    CBaseTransition* pGTransition,  
    CBaseTransition* pBTransition);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRTransition`  
 Transição para o componente vermelho.  
  
 `pGTransition`  
 Transição para o componente verde.  
  
 `pBTransition`  
 Transição para o componente azul.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para adicionar as transições especificadas para a lista interna de transições para ser aplicados a animação variáveis que representam componentes de cor. Quando você adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. Transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição de componentes de cor, é possível passar NULL.  
  
##  <a name="canimationcolor"></a>  CAnimationColor::CAnimationColor  
 Constrói um objeto CAnimationColor.  
  
```  
CAnimationColor();
 
CAnimationColor(
    COLORREF color,  
    UINT32 nGroupID,  
    UINT32 nObjectID = (UINT32)-1,  
    DWORD dwUserData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Especifica a cor padrão.  
  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `nObjectID`  
 Especifica a ID de objeto.  
  
 `dwUserData`  
 Especifica os dados definidos pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 O objeto for construído com valores padrão para vermelho, verde e azul, ID de objeto e identificação de grupo, que será definido como 0. Eles podem ser alterados posteriormente em tempo de execução usando SetDefaultValue e SetID.  
  
##  <a name="getanimationvariablelist"></a>  CAnimationColor::GetAnimationVariableList  
 Coloca as variáveis de animação encapsulada em uma lista.  
  
```  
virtual void GetAnimationVariableList(CList<CAnimationVariable*>& lst);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Quando a função retornar, contém ponteiros para três objetos CAnimationVariable que representam componentes vermelhos, verdes e azuis.  
  
##  <a name="getb"></a>  CAnimationColor::GetB  
 Fornece acesso a CAnimationVariable que representa o componente azul.  
  
```  
CAnimationVariable& GetB();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa o componente azul.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa o componente azul.  
  
##  <a name="getdefaultvalue"></a>  CAnimationColor::GetDefaultValue  
 Retorna os valores padrão para componentes de cor.  
  
```  
COLORREF GetDefaultValue();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor COLORREF que contém os padrões para componentes RGB.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.  
  
##  <a name="getg"></a>  CAnimationColor::GetG  
 Fornece acesso a CAnimationVariable que representa o componente verde.  
  
```  
CAnimationVariable& GetG();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência ao componente de verde representando encapsulado do CAnimationVariable.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao componente de verde representando subjacente do CAnimationVariable.  
  
##  <a name="getr"></a>  CAnimationColor::GetR  
 Fornece acesso a CAnimationVariable que representa o componente vermelho.  
  
```  
CAnimationVariable& GetR();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa o componente vermelho.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa o componente vermelho.  
  
##  <a name="getvalue"></a>  CAnimationColor::GetValue  
 Retorna o valor atual.  
  
```  
BOOL GetValue(COLORREF& color);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Saída. Quando este método retorna, contém o valor atual.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o valor atual foi recuperado com êxito. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor atual da cor de animação. Se esse método falhar ou não foram inicializados objetos subjacentes para componentes de cor, cor contém o valor padrão, que foi definida anteriormente no construtor ou por SetDefaultValue.  
  
##  <a name="m_bvalue"></a>  CAnimationColor::m_bValue  
 A variável de animação encapsulada que representa o componente azul da cor de animação.  
  
```  
CAnimationVariable m_bValue;  
```  
  
##  <a name="m_gvalue"></a>  CAnimationColor::m_gValue  
 A variável de animação encapsulada que representa o componente verde da cor de animação.  
  
```  
CAnimationVariable m_gValue;  
```  
  
##  <a name="m_rvalue"></a>  CAnimationColor::m_rValue  
 A variável de animação encapsulada que representa o componente vermelho da cor de animação.  
  
```  
CAnimationVariable m_rValue;  
```  
  
##  <a name="operator_colorref"></a>  CAnimationColor::operator COLORREF  
  
```  
operator COLORREF();
```   
  
### <a name="return-value"></a>Valor de retorno  
  
##  <a name="operator_eq"></a>  CAnimationColor::operator =  
 Atribui a cor para CAnimationColor.  
  
```  
void operator=(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Especifica o novo valor de cor de animação.  
  
### <a name="remarks"></a>Comentários  
 É recomendável fazer isso antes do início da animação, porque esse operador chama SetDefaultValue, que recria os objetos COM base para componentes de cor se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
##  <a name="setdefaultvalue"></a>  CAnimationColor::SetDefaultValue  
 Define o valor padrão.  
  
```  
void SetDefaultValue(COLORREF color);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Especifica os novos valores padrão para componentes vermelhos, verdes e azuis.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para definir um valor padrão para o objeto de animação. Esse método atribui valores padrão para componentes de cor da cor de animação. Ele também recria os objetos subjacentes se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
