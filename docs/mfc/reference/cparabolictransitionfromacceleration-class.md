---
title: Classe CParabolicTransitionFromAcceleration | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- afxanimationcontroller/CParabolicTransitionFromAcceleration
- CParabolicTransitionFromAcceleration
dev_langs:
- C++
helpviewer_keywords:
- CParabolicTransitionFromAcceleration class
ms.assetid: 1e59b86f-358b-4da0-a4fd-8eaf5e85e00f
caps.latest.revision: 18
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
ms.openlocfilehash: f0d3089a01cd244851be3d4bdf0453101a9c8274
ms.lasthandoff: 02/25/2017

---
# <a name="cparabolictransitionfromacceleration-class"></a>Classe CParabolicTransitionFromAcceleration
Encapsula uma transição de aceleração parabólico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CParabolicTransitionFromAcceleration : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CParabolicTransitionFromAcceleration::CParabolicTransitionFromAcceleration](#cparabolictransitionfromacceleration)|Constrói uma transição parabólico acceleration e o inicializa com parâmetros especificados.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CParabolicTransitionFromAcceleration::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulado COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CParabolicTransitionFromAcceleration::m_dblAcceleration](#m_dblacceleration)|A aceleração da variável de animação durante a transição.|  
|[CParabolicTransitionFromAcceleration::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|  
|[CParabolicTransitionFromAcceleration::m_dblFinalVelocity](#m_dblfinalvelocity)|A velocidade da variável de animação no final da transição.|  
  
## <a name="remarks"></a>Comentários  
 Durante uma transição de aceleração parabólico, o valor da variável de animação muda do valor inicial para o valor final, terminando com uma velocidade especificada. Você pode controlar como a variável de alcance rapidamente o valor final especificando a taxa de aceleração. Como todas as transições são limpas automaticamente, é recomendável para alocada-los usando o operador novo. O objeto IUIAnimationTransition COM encapsulado é criado por CAnimationController::AnimateGroup, até é NULL. Alterar as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CParabolicTransitionFromAcceleration](../../mfc/reference/cparabolictransitionfromacceleration-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-namecparabolictransitionfromaccelerationa--cparabolictransitionfromaccelerationcparabolictransitionfromacceleration"></a><a name="cparabolictransitionfromacceleration"></a>CParabolicTransitionFromAcceleration::CParabolicTransitionFromAcceleration  
 Constrói uma transição parabólico acceleration e o inicializa com parâmetros especificados.  
  
```  
CParabolicTransitionFromAcceleration(
    DOUBLE dblFinalValue,  
    DOUBLE dblFinalVelocity,  
    DOUBLE dblAcceleration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dblFinalValue`  
 O valor da variável de animação no final da transição.  
  
 `dblFinalVelocity`  
 A velocidade da variável de animação no final da transição.  
  
 `dblAcceleration`  
 A aceleração da variável de animação durante a transição.  
  
##  <a name="a-namecreatea--cparabolictransitionfromaccelerationcreate"></a><a name="create"></a>CParabolicTransitionFromAcceleration::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulado COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* /* not used */);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLibrary`  
 Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição é criada com êxito; Caso contrário, FALSE.  
  
##  <a name="a-namemdblaccelerationa--cparabolictransitionfromaccelerationmdblacceleration"></a><a name="m_dblacceleration"></a>CParabolicTransitionFromAcceleration::m_dblAcceleration  
 A aceleração da variável de animação durante a transição.  
  
```  
DOUBLE m_dblAcceleration;  
```  
  
##  <a name="a-namemdblfinalvaluea--cparabolictransitionfromaccelerationmdblfinalvalue"></a><a name="m_dblfinalvalue"></a>CParabolicTransitionFromAcceleration::m_dblFinalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_dblFinalValue;  
```  
  
##  <a name="a-namemdblfinalvelocitya--cparabolictransitionfromaccelerationmdblfinalvelocity"></a><a name="m_dblfinalvelocity"></a>CParabolicTransitionFromAcceleration::m_dblFinalVelocity  
 A velocidade da variável de animação no final da transição.  
  
```  
DOUBLE m_dblFinalVelocity;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

