---
title: Classe CSinusoidalTransitionFromVelocity | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CSinusoidalTransitionFromVelocity
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromVelocity
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromVelocity::Create
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromVelocity::m_duration
- AFXANIMATIONCONTROLLER/CSinusoidalTransitionFromVelocity::m_period
dev_langs:
- C++
helpviewer_keywords:
- CSinusoidalTransitionFromVelocity [MFC], CSinusoidalTransitionFromVelocity
- CSinusoidalTransitionFromVelocity [MFC], Create
- CSinusoidalTransitionFromVelocity [MFC], m_duration
- CSinusoidalTransitionFromVelocity [MFC], m_period
ms.assetid: cc885f17-b84b-45ee-8f1f-36a8bbb7adad
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 41011ad9814837d38a8d4e229123f447802b323d
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="csinusoidaltransitionfromvelocity-class"></a>Classe CSinusoidalTransitionFromVelocity
Encapsula uma transição de velocidade sinusoidal que tem uma amplitude que é determinada pela velocidade inicial da variável de animação.  
  
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
|[CSinusoidalTransitionFromVelocity::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulados COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSinusoidalTransitionFromVelocity::m_duration](#m_duration)|A duração da transição.|  
|[CSinusoidalTransitionFromVelocity::m_period](#m_period)|O período de oscilação do wave sinusoidal em segundos.|  
  
## <a name="remarks"></a>Comentários  
 O valor da variável de animação oscila ao redor do valor inicial em todo o período de transição de um intervalo sinusoidal. A amplitude da oscilação é determinada pela velocidade da variável de animação quando começa a transição. Como todas as transições são limpos automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulados é criado pela CAnimationController::AnimateGroup, até que é NULL. Alterar as variáveis de membro após a criação do objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CSinusoidalTransitionFromVelocity](../../mfc/reference/csinusoidaltransitionfromvelocity-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="create"></a>CSinusoidalTransitionFromVelocity::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulados COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* \*not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pLibrary`  
 Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição será criada com êxito; Caso contrário, FALSE.  
  
##  <a name="csinusoidaltransitionfromvelocity"></a>CSinusoidalTransitionFromVelocity::CSinusoidalTransitionFromVelocity  
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
 O período de oscilação do wave sinusoidal em segundos.  
  
##  <a name="m_duration"></a>CSinusoidalTransitionFromVelocity::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
##  <a name="m_period"></a>CSinusoidalTransitionFromVelocity::m_period  
 O período de oscilação do wave sinusoidal em segundos.  
  
```  
UI_ANIMATION_SECONDS m_period;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

