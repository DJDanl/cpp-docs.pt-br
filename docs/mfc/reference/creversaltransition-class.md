---
title: Classe CReversalTransition | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CReversalTransition
- AFXANIMATIONCONTROLLER/CReversalTransition
- AFXANIMATIONCONTROLLER/CReversalTransition::CReversalTransition
- AFXANIMATIONCONTROLLER/CReversalTransition::Create
- AFXANIMATIONCONTROLLER/CReversalTransition::m_duration
dev_langs: C++
helpviewer_keywords:
- CReversalTransition [MFC], CReversalTransition
- CReversalTransition [MFC], Create
- CReversalTransition [MFC], m_duration
ms.assetid: e89516be-2d07-4885-95a8-fc278f46e3ad
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: fdce13f41e95cda592fec03fcedb01984fb34ab9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creversaltransition-class"></a>Classe CReversalTransition
Encapsula uma transição de reversão.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CReversalTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReversalTransition::CReversalTransition](#creversaltransition)|Constrói um objeto de transição de reversão e inicializa sua duração.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReversalTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulados COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CReversalTransition::m_duration](#m_duration)|A duração da transição.|  
  
## <a name="remarks"></a>Comentários  
 Uma transição de reversão perfeitamente altera a direção em um período especificado. O valor final será o mesmo que o valor inicial e final velocidade será negativo da velocidade inicial. Como todas as transições são limpos automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulados é criado pela CAnimationController::AnimateGroup, até que é NULL. Alterar as variáveis de membro após a criação do objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CReversalTransition](../../mfc/reference/creversaltransition-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="create"></a>CReversalTransition::Create  
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
  
##  <a name="creversaltransition"></a>CReversalTransition::CReversalTransition  
 Constrói um objeto de transição de reversão e inicializa sua duração.  
  
```  
CReversalTransition(UI_ANIMATION_SECONDS duration);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
##  <a name="m_duration"></a>CReversalTransition::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
