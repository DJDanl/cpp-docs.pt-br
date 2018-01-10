---
title: Classe CAnimationPoint | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint::CAnimationPoint
- AFXANIMATIONCONTROLLER/CAnimationPoint::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetX
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetY
- AFXANIMATIONCONTROLLER/CAnimationPoint::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationPoint::m_xValue
- AFXANIMATIONCONTROLLER/CAnimationPoint::m_yValue
dev_langs: C++
helpviewer_keywords:
- CAnimationPoint [MFC], CAnimationPoint
- CAnimationPoint [MFC], AddTransition
- CAnimationPoint [MFC], GetDefaultValue
- CAnimationPoint [MFC], GetValue
- CAnimationPoint [MFC], GetX
- CAnimationPoint [MFC], GetY
- CAnimationPoint [MFC], SetDefaultValue
- CAnimationPoint [MFC], GetAnimationVariableList
- CAnimationPoint [MFC], m_xValue
- CAnimationPoint [MFC], m_yValue
ms.assetid: 5dc4d46f-e695-4681-b15c-544b78b3e317
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8ab685c223c4a86c35ba0feb578d93f58844734b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="canimationpoint-class"></a>Classe CAnimationPoint
Implementa a funcionalidade de um ponto de cujas coordenadas podem ser animadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationPoint : public CAnimationBaseObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::CAnimationPoint](#canimationpoint)|Sobrecarregado. Constrói um objeto CAnimationPoint.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::AddTransition](#addtransition)|Adiciona as transições de X e Y.|  
|[CAnimationPoint::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para X e Y.|  
|[CAnimationPoint::GetValue](#getvalue)|Retorna o valor atual.|  
|[CAnimationPoint::GetX](#getx)|Fornece acesso aos CAnimationVariable de coordenada X.|  
|[CAnimationPoint::GetY](#gety)|Fornece acesso a CAnimationVariable de coordenada de Y.|  
|[CAnimationPoint::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulada em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::operator CPoint](#operator_cpoint)|Converte um CAnimationPoint em um CPoint.|  
|[CAnimationPoint::operator =](#operator_eq)|Atribui ptSrc a CAnimationPoint.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::m_xValue](#m_xvalue)|A variável de animação encapsulada que representa X coordenadas de ponto de animação.|  
|[CAnimationPoint::m_yValue](#m_yvalue)|A variável de animação encapsulada que representa a coordenada Y do ponto de animação.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationPoint encapsula os dois objetos CAnimationVariable e pode representar em aplicativos de um ponto. Por exemplo, você pode usar esta classe para animar uma posição de qualquer objeto na tela (como cadeia de caracteres de texto, círculo, ponto etc.). Para usar essa classe no aplicativo, apenas instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado à coordenadas X e/ou Y.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 `CAnimationPoint`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtransition"></a>CAnimationPoint::AddTransition  
 Adiciona as transições de X e Y.  
  
```  
void AddTransition(
    CBaseTransition* pXTransition,  
    CBaseTransition* pYTransition);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pXTransition`  
 Um ponteiro para fazer a transição para coordenadas X.  
  
 `pYTransition`  
 Um ponteiro para fazer a transição para a Y coordenada.  
  
### <a name="remarks"></a>Comentários  
 Chamar essa função para adicionar as transições especificadas para a lista interna de transições para ser aplicados a variáveis de animação de X e Y. Quando você adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. Transições são aplicadas (adicionado a um storyboard para um determinado valor) quando você chama CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição de coordenadas, é possível passar NULL.  
  
##  <a name="canimationpoint"></a>CAnimationPoint::CAnimationPoint  
 Constrói um objeto CAnimationPoint.  
  
```  
CAnimationPoint();

 
CAnimationPoint(
    const CPoint& ptDefault,  
    UINT32 nGroupID,  
    UINT32 nObjectID = (UINT32)-1,  
    DWORD dwUserData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptDefault`  
 Especifica as coordenadas de ponto padrão.  
  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `nObjectID`  
 Especifica a ID de objeto.  
  
 `dwUserData`  
 Especifica os dados definidos pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Constrói um objeto CAnimationPoint com propriedades padrão: padrão de coordenadas de ponto, ID de grupo e a ID de objeto são definidos como 0.  
  
##  <a name="getanimationvariablelist"></a>CAnimationPoint::GetAnimationVariableList  
 Coloca as variáveis de animação encapsulada em uma lista.  
  
```  
virtual void GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Quando a função retornar, contém ponteiros para os dois objetos CAnimationVariable que representam as coordenadas X e Y.  
  
##  <a name="getdefaultvalue"></a>CAnimationPoint::GetDefaultValue  
 Retorna os valores padrão para X e Y.  
  
```  
CPoint GetDefaultValue();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão contendo ponto.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor padrão, que foi anteriormente definido pelo construtor ou SetDefaultValue.  
  
##  <a name="getvalue"></a>CAnimationPoint::GetValue  
 Retorna o valor atual.  
  
```  
BOOL GetValue(CPoint& ptValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptValue`  
 Saída. Quando este método retorna, contém o valor atual.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o valor atual foi recuperado com êxito. Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor atual do ponto de animação. Se esse método falhar ou subjacente COM objetos de X e Y coordenadas não foram inicializadas, ptValue contém o valor padrão, que foi definida anteriormente no construtor ou por SetDefaultValue.  
  
##  <a name="getx"></a>CAnimationPoint::GetX  
 Fornece acesso aos CAnimationVariable de coordenada X.  
  
```  
CAnimationVariable& GetX();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a encapsulada CAnimationVariable representar X coordenar.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa X coordenar.  
  
##  <a name="gety"></a>CAnimationPoint::GetY  
 Fornece acesso a CAnimationVariable de coordenada de Y.  
  
```  
CAnimationVariable& GetY();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulada que representa a coordenada Y.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada Y.  
  
##  <a name="m_xvalue"></a>CAnimationPoint::m_xValue  
 A variável de animação encapsulada que representa X coordenadas de ponto de animação.  
  
```  
CAnimationVariable m_xValue;  
```  
  
##  <a name="m_yvalue"></a>CAnimationPoint::m_yValue  
 A variável de animação encapsulada que representa a coordenada Y do ponto de animação.  
  
```  
CAnimationVariable m_yValue;  
```  
  
##  <a name="operator_cpoint"></a>CAnimationPoint::operator CPoint  
 Converte um CAnimationPoint em um CPoint.  
  
```  
operator CPoint();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de CAnimationPoint como CPoint.  
  
### <a name="remarks"></a>Comentários  
 Esta função chama internamente GetValue. Se falhar GetValue por algum motivo, o ponto retornado conterá valores padrão para X e Y.  
  
##  <a name="operator_eq"></a>CAnimationPoint::operator =  
 Atribui ptSrc a CAnimationPoint.  
  
```  
void operator=(const CPoint& ptSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptSrc`  
 Refere-se a CPoint ou ponto.  
  
### <a name="remarks"></a>Comentários  
 Atribui ptSrc a CAnimationPoint. É recomendável fazer que antes do início da animação, porque esse operador chama SetDefaultValue, que recria o subjacente COM objetos de coordenadas X e Y se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
##  <a name="setdefaultvalue"></a>CAnimationPoint::SetDefaultValue  
 Define o valor padrão.  
  
```  
void SetDefaultValue(const POINT& ptDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptDefault`  
 Especifica o valor de ponto padrão.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para definir um valor padrão para o objeto de animação. Esse padrão de atribui métodos valores para as coordenadas X e Y do ponto de animação. Ele também recria os objetos subjacentes se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
