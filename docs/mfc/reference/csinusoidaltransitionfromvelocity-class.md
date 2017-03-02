---
title: Classe CSinusoidalTransitionFromVelocity | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSinusoidalTransitionFromVelocity
- afxanimationcontroller/CSinusoidalTransitionFromVelocity
dev_langs:
- C++
helpviewer_keywords:
- CSinusoidalTransitionFromVelocity class
ms.assetid: cc885f17-b84b-45ee-8f1f-36a8bbb7adad
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
ms.openlocfilehash: 035c92a807fdbe9028547472a3dc816995b95c91
ms.lasthandoff: 02/25/2017

---
# <a name="csinusoidaltransitionfromvelocity-class"></a>Classe CSinusoidalTransitionFromVelocity
Encapsula uma transição de velocidade sinusoidal que tem uma amplitude é determinada pela velocidade inicial da variável de animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSinusoidalTransitionFromVelocity : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity](#csinusoidaltransitionfromvelocity)|Constrói um objeto de transição.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSinusoidalTransitionFromVelocity::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulado COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSinusoidalTransitionFromVelocity::m_duration](#m_duration)|A duração da transição.|  
|[CSinusoidalTransitionFromVelocity::m_period](#m_period)|O período de oscilação da onda sinusoidal em segundos.|  
  
## <a name="remarks"></a>Comentários  
 O valor da variável de animação oscila ao redor do valor inicial ao longo de todo o período de transição de um intervalo sinusoidal. A amplitude da oscilação é determinada pela velocidade da variável de animação quando começa a transição. Como todas as transições são limpas automaticamente, é recomendável para alocada-los usando o operador novo. O objeto IUIAnimationTransition COM encapsulado é criado por CAnimationController::AnimateGroup, até é NULL. Alterar as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CSinusoidalTransitionFromVelocity](../../mfc/reference/csinusoidaltransitionfromvelocity-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-namecreatea--csinusoidaltransitionfromvelocitycreate"></a><a name="create"></a>CSinusoidalTransitionFromVelocity::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulado COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* \*not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLibrary`  
 Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição é criada com êxito; Caso contrário, FALSE.  
  
##  <a name="a-namecsinusoidaltransitionfromvelocitya--csinusoidaltransitionfromvelocitycsinusoidaltransitionfromvelocity"></a><a name="csinusoidaltransitionfromvelocity"></a>CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity  
 Constrói um objeto de transição.  
  
```  
CSinusoidalTransitionFromVelocity(
    UI_ANIMATION_SECONDS duration,  
    UI_ANIMATION_SECONDS period);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
 `period`  
 O período de oscilação da onda sinusoidal em segundos.  
  
##  <a name="a-namemdurationa--csinusoidaltransitionfromvelocitymduration"></a><a name="m_duration"></a>CSinusoidalTransitionFromVelocity::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
##  <a name="a-namemperioda--csinusoidaltransitionfromvelocitymperiod"></a><a name="m_period"></a>CSinusoidalTransitionFromVelocity::m_period  
 O período de oscilação da onda sinusoidal em segundos.  
  
```  
UI_ANIMATION_SECONDS m_period;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

