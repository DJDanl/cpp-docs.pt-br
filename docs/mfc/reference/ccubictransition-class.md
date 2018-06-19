---
title: Classe CCubicTransition | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition::CCubicTransition
- AFXANIMATIONCONTROLLER/CCubicTransition::Create
- AFXANIMATIONCONTROLLER/CCubicTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CCubicTransition::m_dblFinalVelocity
- AFXANIMATIONCONTROLLER/CCubicTransition::m_duration
dev_langs:
- C++
helpviewer_keywords:
- CCubicTransition [MFC], CCubicTransition
- CCubicTransition [MFC], Create
- CCubicTransition [MFC], m_dblFinalValue
- CCubicTransition [MFC], m_dblFinalVelocity
- CCubicTransition [MFC], m_duration
ms.assetid: 4fc30e9c-160c-45e1-bdbe-51adf8fee9c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 001a1e66707544f6446a5bc54e70269f94108654
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33351902"
---
# <a name="ccubictransition-class"></a>Classe CCubicTransition
Encapsula uma transição cúbica.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CCubicTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCubicTransition::CCubicTransition](#ccubictransition)|Constrói um objeto de transição e inicializa seus parâmetros.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCubicTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulados COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCubicTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|  
|[CCubicTransition::m_dblFinalVelocity](#m_dblfinalvelocity)|A velocidade da variável no final da transição.|  
|[CCubicTransition::m_duration](#m_duration)|A duração da transição.|  
  
## <a name="remarks"></a>Comentários  
 Durante a transição cúbica, o valor da variável de animação altera do seu valor inicial para um valor final especificado ao longo da duração da transição, terminando em uma velocidade especificada. Como todas as transições são limpos automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulados é criado pela CAnimationController::AnimateGroup, até que é NULL. Alterar as variáveis de membro após a criação do objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 `CCubicTransition`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="ccubictransition"></a>  CCubicTransition::CCubicTransition  
 Constrói um objeto de transição e inicializa seus parâmetros.  
  
```  
CCubicTransition(
    UI_ANIMATION_SECONDS duration,  
    DOUBLE finalValue,  
    DOUBLE finalVelocity);
```  
  
### <a name="parameters"></a>Parâmetros  
 `duration`  
 A duração da transição.  
  
 `finalValue`  
 O valor da variável de animação no final da transição.  
  
 `finalVelocity`  
 A velocidade da variável no final da transição.  
  
##  <a name="create"></a>  CCubicTransition::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulados COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* \*not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
`pLibrary`  
 Um ponteiro para um [IUIAnimationTransitionLibrary interface](https://msdn.microsoft.com/library/windows/desktop/dd371897), que define uma biblioteca de transições padrão.  

### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição será criada com êxito; Caso contrário, FALSE.  
  
##  <a name="m_dblfinalvalue"></a>  CCubicTransition::m_dblFinalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_dblFinalValue;  
```  
  
##  <a name="m_dblfinalvelocity"></a>  CCubicTransition::m_dblFinalVelocity  
 A velocidade da variável no final da transição.  
  
```  
DOUBLE m_dblFinalVelocity;  
```  
  
##  <a name="m_duration"></a>  CCubicTransition::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
