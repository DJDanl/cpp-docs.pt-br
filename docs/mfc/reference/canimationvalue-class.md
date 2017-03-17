---
title: Classe CAnimationValue | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue::CAnimationValue
- AFXANIMATIONCONTROLLER/CAnimationValue::AddTransition
- AFXANIMATIONCONTROLLER/CAnimationValue::GetValue
- AFXANIMATIONCONTROLLER/CAnimationValue::GetVariable
- AFXANIMATIONCONTROLLER/CAnimationValue::SetDefaultValue
- AFXANIMATIONCONTROLLER/CAnimationValue::GetAnimationVariableList
- AFXANIMATIONCONTROLLER/CAnimationValue::m_value
dev_langs:
- C++
helpviewer_keywords:
- CAnimationValue class
ms.assetid: 78c5ae19-ede5-4f20-bfbe-68b467b603c2
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 083c8be9a0d9d518d5353b6d02c0050944312805
ms.lasthandoff: 02/25/2017

---
# <a name="canimationvalue-class"></a>Classe CAnimationValue
Implementa a funcionalidade do objeto de animação que tem um valor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAnimationValue : public CAnimationBaseObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationValue::CAnimationValue](#canimationvalue)|Sobrecarregado. Constrói um objeto CAnimationValue.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationValue::AddTransition](#addtransition)|Adiciona uma transição para ser aplicado a um valor.|  
|[CAnimationValue::GetValue](#getvalue)|Sobrecarregado. Recupera o valor atual.|  
|[CAnimationValue::GetVariable](#getvariable)|Fornece acesso à variável de animação encapsulado.|  
|[CAnimationValue::SetDefaultValue](#setdefaultvalue)|Define o valor padrão.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationValue::GetAnimationVariableList](#getanimationvariablelist)|Coloca a variável de animação encapsulado em uma lista. (Substitui [CAnimationBaseObject::GetAnimationVariableList](../../mfc/reference/canimationbaseobject-class.md#getanimationvariablelist).)|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationValue::operator dupla](#operator_double)|Fornece conversão entre CAnimationValue e DOUBLE.|  
|[CAnimationValue::operator INT32](#operator_int32)|Fornece conversão entre CAnimationValue e INT32.|  
|[CAnimationValue::operator =](#operator_eq)|Sobrecarregado. Atribui um valor INT32 para CAnimationValue.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAnimationValue::m_value](#m_value)|A variável de animação encapsulado que representa o valor da animação.|  
  
## <a name="remarks"></a>Comentários  
 A classe CAnimationValue encapsula um único objeto CAnimationVariable e pode representar em aplicativos de um único valor animado. Por exemplo, você pode usar esta classe para transparência animada (efeito de esmaecimento), ângulo (para girar objetos), ou para qualquer outro caso, quando você precisa criar uma animação dependendo de um único valor animado. Para usar essa classe no aplicativo, simplesmente instanciar um objeto dessa classe, adicioná-lo ao controlador de animação usando CAnimationController::AddAnimationObject e chamar AddTransition para cada transição a ser aplicado ao valor.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CAnimationBaseObject](../../mfc/reference/canimationbaseobject-class.md)  
  
 `CAnimationValue`
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtransition"></a>CAnimationValue::AddTransition  
 Adiciona uma transição para ser aplicado a um valor.  
  
```  
void AddTransition(CBaseTransition* pTransition);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTransition`  
 Um ponteiro para o objeto de transição.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para adicionar uma transição a lista interna de transições a serem aplicadas a uma variável de animação. Ao adicionar transições, eles não são aplicados imediatamente e armazenados em uma lista interna. As transições são aplicadas (adicionadas a um storyboard para um determinado valor) quando você chamar CAnimationController::AnimateGroup.  
  
##  <a name="canimationvalue"></a>CAnimationValue::CAnimationValue  
 Constrói um objeto CAnimationValue.  
  
```  
CAnimationValue();

 
CAnimationValue(
    DOUBLE dblDefaultValue,  
    UINT32 nGroupID,  
    UINT32 nObjectID = (UINT32)-1,  
    DWORD dwUserData = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblDefaultValue`  
 Especifica o valor padrão.  
  
 `nGroupID`  
 Especifica a ID do grupo.  
  
 `nObjectID`  
 Especifica a ID do objeto.  
  
 `dwUserData`  
 Especifica os dados definidos pelo usuário.  
  
### <a name="remarks"></a>Comentários  
 Constrói um objeto CAnimationValue com propriedades padrão: valor padrão, o ID do grupo e ID de objeto são definidos como 0.  
  
##  <a name="getanimationvariablelist"></a>CAnimationValue::GetAnimationVariableList  
 Coloca a variável de animação encapsulado em uma lista.  
  
```  
virtual void GetAnimationVariableList(
    CList<CAnimationVariable*, 
    CAnimationVariable*>& lst);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lst`  
 Quando a função retorna, ele contém um ponteiro para CAnimationVariable que representa o valor animado.  
  
##  <a name="getvalue"></a>CAnimationValue::GetValue  
 Recupera o valor atual.  
  
```  
BOOL GetValue(DOUBLE& dblValue);  
BOOL GetValue(INT32& nValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblValue`  
 Saída. Quando a função retorna, ele contém um valor atual da variável de animação.  
  
 `nValue`  
 Saída. Quando a função retorna, ele contém um valor atual da variável de animação.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o valor atual foi recuperado com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para recuperar o valor atual. Essa implementação chama o objeto COM encapsulado, e se a chamada falhar, esse método retorna o valor padrão que foi anteriormente definido no construtor ou com SetDefaultValue.  
  
##  <a name="getvariable"></a>CAnimationValue::GetVariable  
 Fornece acesso à variável de animação encapsulado.  
  
```  
CAnimationVariable& GetVariable();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma referência à variável de animação encapsulado.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para acessar a variável de animação encapsulado. Do CAnimationVariable, você obterá acesso ao objeto subjacente de IUIAnimationVariable, cujo ponteiro pode ser NULL se não tiver sido criada uma variável de animação.  
  
##  <a name="m_value"></a>CAnimationValue::m_value  
 A variável de animação encapsulado que representa o valor da animação.  
  
```  
CAnimationVariable m_value;  
```  
  
##  <a name="operator_double"></a>CAnimationValue::operator dupla  
 Fornece conversão entre CAnimationValue e DOUBLE.  
  
```  
operator DOUBLE();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do valor de animação.  
  
### <a name="remarks"></a>Comentários  
 Fornece conversão entre CAnimationValue e DOUBLE. Esse método internamente chamasse GetValue e verifique se não há erros. Se GetValue falhar, o valor retornado conterá um valor padrão definido anteriormente no construtor ou com SetDefaultValue.  
  
##  <a name="operator_int32"></a>CAnimationValue::operator INT32  
 Fornece conversão entre CAnimationValue e INT32.  
  
```  
operator INT32();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Valor atual do valor de animação como inteiro.  
  
### <a name="remarks"></a>Comentários  
 Fornece conversão entre CAnimationValue e INT32. Esse método internamente chamasse GetValue e verifique se não há erros. Se GetValue falhar, o valor retornado conterá um valor padrão definido anteriormente no construtor ou com SetDefaultValue.  
  
##  <a name="operator_eq"></a>CAnimationValue::operator =  
 Atribui um valor duplo para CAnimationValue.  
  
```  
void operator=(DOUBLE dblVal);  
void operator=(INT32 nVal);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblVal`  
 Especifica o valor a ser atribuído ao valor da animação.  
  
 `nVal`  
 Especifica o valor a ser atribuído ao valor da animação.  
  
### <a name="remarks"></a>Comentários  
 Atribui um valor duplo para CAnimationValue. Esse valor é definido como um valor padrão para a variável de animação encapsulado. Se você se inscreveu nesse objeto de animação para eventos (ValueChanged ou IntegerValueChanged), você precisa habilitar novamente esses eventos.  
  
##  <a name="setdefaultvalue"></a>CAnimationValue::SetDefaultValue  
 Define o valor padrão.  
  
```  
void SetDefaultValue(DOUBLE dblDefaultValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblDefaultValue`  
 Especifica o valor padrão.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir um valor padrão. Um valor padrão é retornado ao aplicativo quando animação não foi iniciada e/ou objeto COM base não foi criado. Se o objeto COM subjacente encapsulado em CAnimationVarible já foi criado, este método recria, portanto, talvez você precise chamar métodos EnableValueChanged/EnableIntegerValueChanged novamente.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

