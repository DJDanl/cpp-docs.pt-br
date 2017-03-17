---
title: Classe CDiscreteTransition | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition::CDiscreteTransition
- AFXANIMATIONCONTROLLER/CDiscreteTransition::Create
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_delay
- AFXANIMATIONCONTROLLER/CDiscreteTransition::m_hold
dev_langs:
- C++
helpviewer_keywords:
- CDiscreteTransition class
ms.assetid: b4d84fb3-ccaa-451c-a69b-6b50dcb9b9c8
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
ms.openlocfilehash: dcec642fede0ec6895c928925676232319099be7
ms.lasthandoff: 02/25/2017

---
# <a name="cdiscretetransition-class"></a>Classe CDiscreteTransition
Encapsula uma transição discreta.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDiscreteTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDiscreteTransition::CDiscreteTransition](#cdiscretetransition)|Constrói um objeto de transição discretos e inicializa seus parâmetros.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDiscreteTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulado COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDiscreteTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|  
|[CDiscreteTransition::m_delay](#m_delay)|O período de tempo pelo qual atrasar a opção de instantânea para o valor final.|  
|[CDiscreteTransition::m_hold](#m_hold)|O período de tempo pelo qual deseja armazenar a variável em seu valor final.|  
  
## <a name="remarks"></a>Comentários  
 Durante uma transição discreta, a variável de animação permanece no valor inicial para um tempo de espera especificado, então comutadores instantaneamente para um valor final especificado e permanecerá com esse valor por um período de retenção determinada. Como todas as transições são limpas automaticamente, é recomendável para alocada-los usando o operador novo. O objeto IUIAnimationTransition COM encapsulado é criado por CAnimationController::AnimateGroup, até é NULL. Alterar as variáveis de membro após a criação deste objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CDiscreteTransition](../../mfc/reference/cdiscretetransition-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="cdiscretetransition"></a>CDiscreteTransition::CDiscreteTransition  
 Constrói um objeto de transição discretos e inicializa seus parâmetros.  
  
```  
CDiscreteTransition(
    UI_ANIMATION_SECONDS delay,  
    DOUBLE dblFinalValue,  
    UI_ANIMATION_SECONDS hold);
```  
  
### <a name="parameters"></a>Parâmetros  
 `delay`  
 O período de tempo pelo qual atrasar a opção de instantânea para o valor final.  
  
 `dblFinalValue`  
 O valor da variável de animação no final da transição.  
  
 `hold`  
 O período de tempo pelo qual deseja armazenar a variável em seu valor final.  
  
##  <a name="create"></a>CDiscreteTransition::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulado COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* \*not used*\);
```  
  
`pLibrary`  
 Um ponteiro para um [IUIAnimationTransitionLibrary interface](https://msdn.microsoft.com/library/windows/desktop/dd371897), que define uma biblioteca de transições padrão.  

  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição é criada com êxito; Caso contrário, FALSE.  
  
##  <a name="m_dblfinalvalue"></a>CDiscreteTransition::m_dblFinalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_dblFinalValue;  
```  
  
##  <a name="m_delay"></a>CDiscreteTransition::m_delay  
 O período de tempo pelo qual atrasar a opção de instantânea para o valor final.  
  
```  
UI_ANIMATION_SECONDS m_delay;  
```  
  
##  <a name="m_hold"></a>CDiscreteTransition::m_hold  
 O período de tempo pelo qual deseja armazenar a variável em seu valor final.  
  
```  
UI_ANIMATION_SECONDS m_hold;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

