---
title: Classe CAnimationPoint | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationPoint
- afxanimationcontroller/CAnimationPoint
dev_langs:
- C++
helpviewer_keywords:
- CAnimationPoint class
ms.assetid: 5dc4d46f-e695-4681-b15c-544b78b3e317
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
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: a6a59ad85928c199a8dd911b915076ffbd0b0e37
ms.lasthandoff: 02/25/2017

---
# <a name="canimationpoint-class"></a>Classe CAnimationPoint
Implementa a funcionalidade de um ponto cujas coordenadas podem ser animadas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationPoint : public CAnimationBaseObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::CAnimationPoint](#canimationpoint)|Sobrecarregado. Constrói um objeto CAnimationPoint.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::AddTransition](#addtransition)|Adiciona as transições de X e Y.|  
|[CAnimationPoint::GetDefaultValue](#getdefaultvalue)|Retorna os valores padrão para X e Y.|  
|[CAnimationPoint::GetValue](#getvalue)|Retorna o valor atual.|  
|[CAnimationPoint::GetX](#getx)|Fornece acesso a CAnimationVariable de coordenada X.|  
|[CAnimationPoint::GetY](#gety)|Fornece acesso ao CAnimationVariable coordenada Y.|  
|[CAnimationPoint::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::GetAnimationVariableList](#getanimationvariablelist)|Coloca as variáveis de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::operator CPoint](#operator_cpoint)|Converte uma CAnimationPoint uma CPoint.|  
|[CAnimationPoint::operator =](#operator_eq)|Atribui ptSrc a CAnimationPoint.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationPoint::m_xValue](#m_xvalue)|A variável de animação encapsulado que representa X coordenadas do ponto de animação.|  
|[CAnimationPoint::m_yValue](#m_yvalue)|A variável de animação encapsulado que representa a coordenada Y do ponto de animação.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationPoint encapsula os dois objetos CAnimationVariable e pode representar em aplicativos de um ponto. Por exemplo, você pode usar esta classe para animar uma posição de qualquer objeto na tela (como cadeia de caracteres de texto, círculo, ponto etc). Para usar essa classe no aplicativo, simplesmente instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado às coordenadas X e/ou Y.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 `CAnimationPoint`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-nameaddtransitiona--canimationpointaddtransition"></a><a name="addtransition"></a>CAnimationPoint::AddTransition  
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
 Coordenar um ponteiro para a transição para Y.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para adicionar as transições especificadas para a lista interna de transições a serem aplicadas às variáveis de animação para X e Y. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chamar CAnimationController::AnimateGroup. Se você não precisa aplicar uma transição de coordenadas, você pode passar NULL.  
  
##  <a name="a-namecanimationpointa--canimationpointcanimationpoint"></a><a name="canimationpoint"></a>CAnimationPoint::CAnimationPoint  
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
 Especifica a ID do objeto.  
  
 `dwUserData`  
 Especifica os dados definidos pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Constrói um objeto CAnimationPoint com propriedades padrão: coordenadas de ponto por padrão, a ID do grupo e ID de objeto são definidos como 0.  
  
##  <a name="a-namegetanimationvariablelista--canimationpointgetanimationvariablelist"></a><a name="getanimationvariablelist"></a>CAnimationPoint::GetAnimationVariableList  
 Coloca as variáveis de animação encapsulado em uma lista.  
  
```  
virtual void GetAnimationVariableList(CList<CAnimationVariable*, CAnimationVariable*>& lst);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Quando a função retorna, contém ponteiros para os dois objetos CAnimationVariable que representam as coordenadas X e Y.  
  
##  <a name="a-namegetdefaultvaluea--canimationpointgetdefaultvalue"></a><a name="getdefaultvalue"></a>CAnimationPoint::GetDefaultValue  
 Retorna os valores padrão para X e Y.  
  
```  
CPoint GetDefaultValue();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor padrão que contém ponto.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor padrão, que foi definida anteriormente pelo construtor ou SetDefaultValue.  
  
##  <a name="a-namegetvaluea--canimationpointgetvalue"></a><a name="getvalue"></a>CAnimationPoint::GetValue  
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
 Chame essa função para recuperar o valor atual do ponto de animação. Se esse método falhar ou subjacente COM objetos para X e as coordenadas Y não foram inicializadas, ptValue contém o valor padrão, que foi anteriormente definido no construtor ou por SetDefaultValue.  
  
##  <a name="a-namegetxa--canimationpointgetx"></a><a name="getx"></a>CAnimationPoint::GetX  
 Fornece acesso a CAnimationVariable de coordenada X.  
  
```  
CAnimationVariable& GetX();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulado representando X coordenada.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa X coordenada.  
  
##  <a name="a-namegetya--canimationpointgety"></a><a name="gety"></a>CAnimationPoint::GetY  
 Fornece acesso ao CAnimationVariable coordenada Y.  
  
```  
CAnimationVariable& GetY();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência a CAnimationVariable encapsulado que representa a coordenada Y.  
  
### <a name="remarks"></a>Comentários  
 Você pode chamar esse método para obter acesso direto ao CAnimationVariable subjacente que representa a coordenada Y.  
  
##  <a name="a-namemxvaluea--canimationpointmxvalue"></a><a name="m_xvalue"></a>CAnimationPoint::m_xValue  
 A variável de animação encapsulado que representa X coordenadas do ponto de animação.  
  
```  
CAnimationVariable m_xValue;  
```  
  
##  <a name="a-namemyvaluea--canimationpointmyvalue"></a><a name="m_yvalue"></a>CAnimationPoint::m_yValue  
 A variável de animação encapsulado que representa a coordenada Y do ponto de animação.  
  
```  
CAnimationVariable m_yValue;  
```  
  
##  <a name="a-nameoperatorcpointa--canimationpointoperator-cpoint"></a><a name="operator_cpoint"></a>CAnimationPoint::operator CPoint  
 Converte uma CAnimationPoint uma CPoint.  
  
```  
operator CPoint();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual de CAnimationPoint como CPoint.  
  
### <a name="remarks"></a>Comentários  
 Essa função chama internamente GetValue. Se falhar GetValue por algum motivo, o ponto retornado conterá valores padrão para X e Y.  
  
##  <a name="a-nameoperatoreqa--canimationpointoperator"></a><a name="operator_eq"></a>CAnimationPoint::operator =  
 Atribui ptSrc a CAnimationPoint.  
  
```  
void operator=(const CPoint& ptSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptSrc`  
 Refere-se à CPoint ou ponto.  
  
### <a name="remarks"></a>Comentários  
 Atribui ptSrc a CAnimationPoint. Recomenda-se fazer que antes do início da animação, porque esse operador chama SetDefaultValue, que recria o subjacente COM objetos de coordenadas X e Y se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
##  <a name="a-namesetdefaultvaluea--canimationpointsetdefaultvalue"></a><a name="setdefaultvalue"></a>CAnimationPoint::SetDefaultValue  
 Define o valor padrão.  
  
```  
void SetDefaultValue(const POINT& ptDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptDefault`  
 Especifica o valor de ponto padrão.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para definir um valor padrão para o objeto de animação. Esse padrão do métodos atribui valores a coordenadas X e Y do ponto de animação. Ele também recria os objetos subjacentes se eles foram criados. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

