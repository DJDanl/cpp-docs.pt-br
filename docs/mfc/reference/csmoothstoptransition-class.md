---
title: Classe CSmoothStopTransition | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::CSmoothStopTransition
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::Create
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::m_dblFinalValue
- AFXANIMATIONCONTROLLER/CSmoothStopTransition::m_maximumDuration
dev_langs:
- C++
helpviewer_keywords:
- CSmoothStopTransition [MFC], CSmoothStopTransition
- CSmoothStopTransition [MFC], Create
- CSmoothStopTransition [MFC], m_dblFinalValue
- CSmoothStopTransition [MFC], m_maximumDuration
ms.assetid: e1a4b476-6f96-43dd-90db-870a64406b85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 80f0c9802077b89ca5555dc476b1066f61e6c593
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37121484"
---
# <a name="csmoothstoptransition-class"></a>Classe CSmoothStopTransition
Encapsula uma transição suave parar.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CSmoothStopTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmoothStopTransition::CSmoothStopTransition](#csmoothstoptransition)|Constrói uma transição suave parada e inicializa sua duração máxima e o valor final.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmoothStopTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulados COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CSmoothStopTransition::m_dblFinalValue](#m_dblfinalvalue)|O valor da variável de animação no final da transição.|  
|[CSmoothStopTransition::m_maximumDuration](#m_maximumduration)|A duração máxima da transição.|  
  
## <a name="remarks"></a>Comentários  
 Uma transição suave parar lento como abordagens de um determinado valor final e chegar até ele com uma velocidade de zero. A duração da transição é determinada pela velocidade inicial, a diferença entre os valores inicias e finais e a duração máxima especificada. Se não houver nenhuma solução consiste em um único arco parabólico, esse método cria uma transição cúbica. Como todas as transições são limpos automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulados é criado pela CAnimationController::AnimateGroup, até que é NULL. Alterar as variáveis de membro após a criação do objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 [CSmoothStopTransition](../../mfc/reference/csmoothstoptransition-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="create"></a>  CSmoothStopTransition::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulados COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* \*not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pLibrary*  
 Um ponteiro para a biblioteca de transição, que é responsável pela criação de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição será criada com êxito; Caso contrário, FALSE.  
  
##  <a name="csmoothstoptransition"></a>  CSmoothStopTransition::CSmoothStopTransition  
 Constrói uma transição suave parada e inicializa sua duração máxima e o valor final.  
  
```  
CSmoothStopTransition(
    UI_ANIMATION_SECONDS maximumDuration,  
    DOUBLE dblFinalValue);
```  
  
### <a name="parameters"></a>Parâmetros  
 *maximumDuration*  
 A duração máxima da transição.  
  
 *dblFinalValue*  
 O valor da variável de animação no final da transição.  
  
##  <a name="m_dblfinalvalue"></a>  CSmoothStopTransition::m_dblFinalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_dblFinalValue;  
```  
  
##  <a name="m_maximumduration"></a>  CSmoothStopTransition::m_maximumDuration  
 A duração máxima da transição.  
  
```  
UI_ANIMATION_SECONDS m_maximumDuration;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
