---
title: CAccelerateDecelerateTransition Class1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CAccelerateDecelerateTransition
- afxanimationcontroller/CAccelerateDecelerateTransition
dev_langs:
- C++
helpviewer_keywords:
- CAccelerateDecelerateTransition class [MFC]
ms.assetid: b1f31ee8-bb11-4ccc-b124-365fb02b025c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d1dac40e91dd7b0a91c5d76b0d665d075e562267
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33357839"
---
# <a name="cacceleratedeceleratetransition-class"></a>Classe CAccelerateDecelerateTransition
Implementa um acelere-desacelerar a transição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CAccelerateDecelerateTransition : public CBaseTransition;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::CAccelerateDecelerateTransition](#cacceleratedeceleratetransition)|Constrói um objeto de transição.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::Create](#create)|Chama a biblioteca de transição para criar o objeto de transição encapsulados COM. (Substitui [CBaseTransition::Create](../../mfc/reference/cbasetransition-class.md#create).)|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAccelerateDecelerateTransition::m_accelerationRatio](#m_accelerationratio)|A razão do tempo gasto para a duração aceleração.|  
|[CAccelerateDecelerateTransition::m_decelerationRatio](#m_decelerationratio)|A razão do tempo gasto desacelerando para a duração.|  
|[CAccelerateDecelerateTransition::m_duration](#m_duration)|A duração da transição.|  
|[CAccelerateDecelerateTransition::m_finalValue](#m_finalvalue)|O valor da variável de animação no final da transição.|  
  
## <a name="remarks"></a>Comentários  
 Durante uma acelere-desacelerar a transição, a variável de animação acelera e reduz a velocidade ao longo da duração da transição, terminando com um valor especificado. Você pode controlar a rapidez a variável acelera e será desacelerado independentemente, especificando a aceleração diferente e taxas de desaceleração. Quando a velocidade inicial for zero, a taxa de aceleração é a fração da duração da variável gastam acelerando; da mesma forma com a taxa de desaceleração. Se a velocidade inicial for diferente de zero, é a fração de tempo entre a velocidade chegar a zero e o término da transição. A taxa de aceleração e a taxa de desaceleração devem somar até um máximo de 1.0. Como todas as transições são limpos automaticamente, é recomendável para alocado-los usando o operador novo. O objeto de IUIAnimationTransition COM encapsulados é criado pela CAnimationController::AnimateGroup, até que é NULL. Alterar as variáveis de membro após a criação do objeto COM não tem nenhum efeito.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseTransition](../../mfc/reference/cbasetransition-class.md)  
  
 `CAccelerateDecelerateTransition`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="cacceleratedeceleratetransition"></a>  CAccelerateDecelerateTransition::CAccelerateDecelerateTransition  
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
 A razão do tempo gasto para a duração aceleração.  
  
 `decelerationRatio`  
 A razão do tempo gasto desacelerando para a duração.  
  
##  <a name="create"></a>  CAccelerateDecelerateTransition::Create  
 Chama a biblioteca de transição para criar o objeto de transição encapsulados COM.  
  
```  
virtual BOOL Create(
    IUIAnimationTransitionLibrary* pLibrary,  
    IUIAnimationTransitionFactory* *\not used*\);
```  
  
### <a name="parameters"></a>Parâmetros  
`pLibrary`  
 Um ponteiro para um [IUIAnimationTransitionLibrary interface](https://msdn.microsoft.com/library/windows/desktop/dd371897), que define uma biblioteca de transições padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a transição será criada com êxito; Caso contrário, FALSE.  
  
##  <a name="m_accelerationratio"></a>  CAccelerateDecelerateTransition::m_accelerationRatio  
 A razão do tempo gasto para a duração aceleração.  
  
```  
DOUBLE m_accelerationRatio;  
```  
  
##  <a name="m_decelerationratio"></a>  CAccelerateDecelerateTransition::m_decelerationRatio  
 A razão do tempo gasto desacelerando para a duração.  
  
```  
DOUBLE m_decelerationRatio;  
```  
  
##  <a name="m_duration"></a>  CAccelerateDecelerateTransition::m_duration  
 A duração da transição.  
  
```  
UI_ANIMATION_SECONDS m_duration;  
```  
  
##  <a name="m_finalvalue"></a>  CAccelerateDecelerateTransition::m_finalValue  
 O valor da variável de animação no final da transição.  
  
```  
DOUBLE m_finalValue;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
