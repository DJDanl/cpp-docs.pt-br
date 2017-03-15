---
title: CAccelerateDecelerateTransition Class1 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAccelerateDecelerateTransition
- afxanimationcontroller/CAccelerateDecelerateTransition
dev_langs:
- C++
helpviewer_keywords:
- CAccelerateDecelerateTransition class
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
caps.latest.revision: 16
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
ms.openlocfilehash: f11dc96b48695b998fb17c33735e8f56bce517b7
ms.lasthandoff: 02/25/2017

---
# <a name="cacceleratedeceleratetransition-class"></a>Classe CAccelerateDecelerateTransition
Implementa uma aceleração-desacelerar a transição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAccelerateDecelerateTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::CAccelerateDecelerateTransition](#cacceleratedeceleratetransition)|Constrói um objeto de transição.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulado COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::m_accelerationRatio](#m_accelerationratio)|A proporção do tempo gasto para a duração de aceleração.|  
|[CAccelerateDecelerateTransition::m_decelerationRatio](#m_decelerationratio)|A proporção de tempo gasta desacelerando para a duração.|  
|[CAccelerateDecelerateTransition::m_duration](#m_duration)|A duração da transição.|  
|[CAccelerateDecelerateTransition::m_finalValue](#m_finalvalue)|O valor da variável de animação no final da transição.|  
  
## <a name="remarks"></a>Comentários  
 Durante uma aceleração-desacelerar a transição, a variável de animação acelera e reduz a velocidade ao longo da duração da transição, terminando com um valor especificado. Você pode controlar a rapidez a variável acelera e será desacelerado independentemente, especificando a aceleração diferente e taxas de desaceleração. Quando a velocidade inicial for zero, a taxa de aceleração é a fração da duração da variável será gasto acelerando; da mesma forma com a taxa de desaceleração. Se a velocidade inicial é diferente de zero, é a fração do tempo entre a velocidade chegar a zero e o fim da transição. A taxa de aceleração e a taxa de desaceleração devem somar um máximo de 1.0. Como todas as transições são limpas automaticamente, é recomendável para alocada-los usando o operador novo. O objeto IUIAnimationTransition COM encapsulado é criado por CAnimationController::AnimateGroup, até é NULL. Alterar as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 `CAccelerateDecelerateTransition`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-namecacceleratedeceleratetransitiona--cacceleratedeceleratetransitioncacceleratedeceleratetransition"></a><a name="cacceleratedeceleratetransition"></a>CAccelerateDecelerateTransition::CAccelerateDecelerateTransition  
 Constrói um objeto de transição.  
  
```  
CAccelerateDecelerateTransition(
    UI_ANIMATION_SECONDS duration,  
    DOUBLE finalValue,  
    DOUBLE accelerationRatio = 0.3,  
    DOUBLE decelerationRatio = 0.3);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
 `finalValue`  
 O valor da variável de animação no final da transição.  
  
 `accelerationRatio`  
 A proporção do tempo gasto para a duração de aceleração.  
  
 `decelerationRatio`  
 A proporção de tempo gasta desacelerando para a duração.  
  
##  <a name="a-namecreatea--cacceleratedeceleratetransitioncreate"></a><a name="create"></a>CAccelerateDecelerateTransition::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulado COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* *\not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
`pLibrary`  
 Um ponteiro para um [IUIAnimationTransitionLibrary interface](https://msdn.microsoft.com/library/windows/desktop/dd371897), que define uma biblioteca de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição é criada com êxito; Caso contrário, FALSE.  
  
##  <a name="a-namemaccelerationratioa--cacceleratedeceleratetransitionmaccelerationratio"></a><a name="m_accelerationratio"></a>CAccelerateDecelerateTransition::m_accelerationRatio  
 A proporção do tempo gasto para a duração de aceleração.  
  
```  
DOUBLE m_accelerationRatio;  
```  
  
##  <a name="a-namemdecelerationratioa--cacceleratedeceleratetransitionmdecelerationratio"></a><a name="m_decelerationratio"></a>CAccelerateDecelerateTransition::m_decelerationRatio  
 A proporção de tempo gasta desacelerando para a duração.  
  
```  
DOUBLE m_decelerationRatio;  
```  
  
##  <a name="a-namemdurationa--cacceleratedeceleratetransitionmduration"></a><a name="m_duration"></a>CAccelerateDecelerateTransition::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
##  <a name="a-namemfinalvaluea--cacceleratedeceleratetransitionmfinalvalue"></a><a name="m_finalvalue"></a>CAccelerateDecelerateTransition::m_finalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_finalValue;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

