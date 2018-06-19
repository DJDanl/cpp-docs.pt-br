---
title: Classe CBaseKeyFrame | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::CBaseKeyFrame
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::AddToStoryboard
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::GetAnimationKeyframe
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::IsAdded
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::IsKeyframeAtOffset
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_bAdded
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_bIsKeyframeAtOffset
- AFXANIMATIONCONTROLLER/CBaseKeyFrame::m_keyframe
dev_langs:
- C++
helpviewer_keywords:
- CBaseKeyFrame [MFC], CBaseKeyFrame
- CBaseKeyFrame [MFC], AddToStoryboard
- CBaseKeyFrame [MFC], GetAnimationKeyframe
- CBaseKeyFrame [MFC], IsAdded
- CBaseKeyFrame [MFC], IsKeyframeAtOffset
- CBaseKeyFrame [MFC], m_bAdded
- CBaseKeyFrame [MFC], m_bIsKeyframeAtOffset
- CBaseKeyFrame [MFC], m_keyframe
ms.assetid: 285a2eff-e7c4-43be-b5aa-737727e6866d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f538874b1690be920e9c7a3b3f494ca6851c532
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33353919"
---
# <a name="cbasekeyframe-class"></a>Classe CBaseKeyFrame
Implementa a funcionalidade básica de um quadro-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBaseKeyFrame : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::CBaseKeyFrame](#cbasekeyframe)|Constrói um objeto de quadro-chave.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave para o storyboard.|  
|[CBaseKeyFrame::GetAnimationKeyframe](#getanimationkeyframe)|Retorna o valor subjacente de quadro-chave.|  
|[CBaseKeyFrame::IsAdded](#isadded)|Informa se um quadro-chave foi adicionado ao storyboard.|  
|[CBaseKeyFrame::IsKeyframeAtOffset](#iskeyframeatoffset)|Especifica se o quadro-chave deve ser adicionado ao storyboard no deslocamento ou após a transição.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::m_bAdded](#m_badded)|Especifica se este quadro-chave foi adicionada a um storyboard.|  
|[CBaseKeyFrame::m_bIsKeyframeAtOffset](#m_biskeyframeatoffset)|Especifica se este quadro-chave deve ser adicionada ao storyboard em um deslocamento de quadro-chave existente outro, ou no final de alguns transição.|  
|[CBaseKeyFrame::m_keyframe](#m_keyframe)|Representa um quadro-chave de API de animação do Windows. Quando um quadro-chave não é inicializado, ele é definido como o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.|  
  
## <a name="remarks"></a>Comentários  
 Encapsula a variável UI_ANIMATION_KEYFRAME. Serve como uma classe base para qualquer implementação de quadro-chave. Um quadro-chave representa um momento específico dentro de um storyboard e pode ser usado para especificar os horários de início e término de transições. Há dois tipos de quadros-chave - quadros-chave adicionados ao storyboard no deslocamento especificado (em hora) ou quadros-chave adicionados após a transição especificada. Como as durações de algumas transições não podem ser conhecidas antes do início da animação, os valores reais de alguns quadros-chave são determinados em tempo de execução apenas. Porque quadros-chave podem depender de transições, que por sua vez, seus dependem de quadros-chave, é importante evitar recursões infinitos ao criar cadeias de quadro-chave.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CBaseKeyFrame`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtostoryboard"></a>  CBaseKeyFrame::AddToStoryboard  
 Adiciona um quadro-chave para o storyboard.  
  
```  
virtual BOOL AddToStoryboard(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Se esse parâmetro for TRUE e o quadro-chave que está sendo adicionado depende de outro quadro-chave ou transição, esse método tenta adicionar este quadro-chave ou a transição para o storyboard primeiro.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada ao storyboard com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado para adicionar um quadro-chave para o storyboard.  
  
##  <a name="cbasekeyframe"></a>  CBaseKeyFrame::CBaseKeyFrame  
 Constrói um objeto de quadro-chave.  
  
```  
CBaseKeyFrame();
```  
  
##  <a name="getanimationkeyframe"></a>  CBaseKeyFrame::GetAnimationKeyframe  
 Retorna o valor subjacente de quadro-chave.  
  
```  
UI_ANIMATION_KEYFRAME GetAnimationKeyframe() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um quadro-chave atual. O valor padrão é UI_ANIMATION_KEYFRAME_STORYBOARD_START.  
  
### <a name="remarks"></a>Comentários  
 Este é um acessador para o valor subjacente de quadro-chave.  
  
##  <a name="isadded"></a>  CBaseKeyFrame::IsAdded  
 Informa se um quadro-chave foi adicionado ao storyboard.  
  
```  
BOOL IsAdded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se um quadro-chave for adicionado a um storyboard; Caso contrário FALSE.  
  
### <a name="remarks"></a>Comentários  
 A classe base IsAdded sempre retorna TRUE, mas ele é substituído nas classes derivadas.  
  
##  <a name="iskeyframeatoffset"></a>  CBaseKeyFrame::IsKeyframeAtOffset  
 Especifica se o quadro-chave deve ser adicionado ao storyboard no deslocamento ou após a transição.  
  
```  
BOOL IsKeyframeAtOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave deve ser adicionado ao storyboard em alguns deslocamento especificado. FALSE se o quadro-chave deve ser adicionado ao storyboard após alguns transição.  
  
### <a name="remarks"></a>Comentários  
 Especifica se o quadro-chave deve ser adicionado ao storyboard no deslocamento. O deslocamento ou transição deve ser especificada em uma classe derivada.  
  
##  <a name="m_badded"></a>  CBaseKeyFrame::m_bAdded  
 Especifica se este quadro-chave foi adicionada a um storyboard.  
  
```  
BOOL m_bAdded;  
```  
  
##  <a name="m_biskeyframeatoffset"></a>  CBaseKeyFrame::m_bIsKeyframeAtOffset  
 Especifica se este quadro-chave deve ser adicionada ao storyboard em um deslocamento de quadro-chave existente outro, ou no final de alguns transição.  
  
```  
BOOL m_bIsKeyframeAtOffset;  
```  
  
##  <a name="m_keyframe"></a>  CBaseKeyFrame::m_keyframe  
 Representa um quadro-chave de API de animação do Windows. Quando um quadro-chave não é inicializado, ele é definido como o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.  
  
```  
UI_ANIMATION_KEYFRAME m_keyframe;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
