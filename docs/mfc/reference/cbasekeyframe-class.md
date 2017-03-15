---
title: Classe CBaseKeyFrame | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CBaseKeyFrame
- afxanimationcontroller/CBaseKeyFrame
dev_langs:
- C++
helpviewer_keywords:
- CBaseKeyFrame class
ms.assetid: 285a2eff-e7c4-43be-b5aa-737727e6866d
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: cfbaac379097c89b5dcb52fa36c0cd1f6e3d2c7f
ms.lasthandoff: 02/25/2017

---
# <a name="cbasekeyframe-class"></a>Classe CBaseKeyFrame
Implementa a funcionalidade básica de um quadro-chave.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CBaseKeyFrame : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::CBaseKeyFrame](#cbasekeyframe)|Constrói um objeto de quadro-chave.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave para criar um storyboard.|  
|[CBaseKeyFrame::GetAnimationKeyframe](#getanimationkeyframe)|Retorna o valor subjacente de quadro-chave.|  
|[CBaseKeyFrame::IsAdded](#isadded)|Informa se um quadro-chave foi adicionado ao storyboard.|  
|[CBaseKeyFrame::IsKeyframeAtOffset](#iskeyframeatoffset)|Especifica se o quadro-chave deve ser adicionado ao storyboard em deslocamento ou após a transição.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CBaseKeyFrame::m_bAdded](#m_badded)|Especifica se esse quadro-chave foi adicionado a um storyboard.|  
|[CBaseKeyFrame::m_bIsKeyframeAtOffset](#m_biskeyframeatoffset)|Especifica se esse quadro-chave deve ser adicionada ao storyboard em um deslocamento do outro quadro-chave existente, ou no final de alguma transição.|  
|[CBaseKeyFrame::m_keyframe](#m_keyframe)|Representa um quadro-chave de API de animação do Windows. Quando um quadro-chave não é inicializado, ele é definido como o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.|  
  
## <a name="remarks"></a>Comentários  
 Encapsula a variável UI_ANIMATION_KEYFRAME. Serve como uma classe base para qualquer implementação de quadro-chave. Um quadro-chave representa um momento específico em um storyboard e pode ser usado para especificar os horários de início e término de transições. Há dois tipos de quadros-chave quadros-chave adicionados ao storyboard no deslocamento especificado (em hora) ou quadros-chave adicionados após a transição especificada. Porque as durações de algumas transições não podem ser conhecidas antes do início da animação, os valores reais de alguns quadros-chave são determinados em tempo de execução somente. Como quadros-chave podem depender de transições, que, em sua vez, dependem de quadros-chave, é importante evitar recursões infinitos quando criar cadeias de quadro-chave.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CBaseKeyFrame`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="a-nameaddtostoryboarda--cbasekeyframeaddtostoryboard"></a><a name="addtostoryboard"></a>CBaseKeyFrame::AddToStoryboard  
 Adiciona um quadro-chave para criar um storyboard.  
  
```  
virtual BOOL AddToStoryboard(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Se esse parâmetro for verdadeiro e o quadro-chave que está sendo adicionado depende de algum outro quadro-chave ou transição, esse método tenta adicionar esse quadro-chave ou a transição para o storyboard primeiro.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada ao storyboard com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método é chamado para adicionar um quadro-chave para criar um storyboard.  
  
##  <a name="a-namecbasekeyframea--cbasekeyframecbasekeyframe"></a><a name="cbasekeyframe"></a>CBaseKeyFrame::CBaseKeyFrame  
 Constrói um objeto de quadro-chave.  
  
```  
CBaseKeyFrame();
```  
  
##  <a name="a-namegetanimationkeyframea--cbasekeyframegetanimationkeyframe"></a><a name="getanimationkeyframe"></a>CBaseKeyFrame::GetAnimationKeyframe  
 Retorna o valor subjacente de quadro-chave.  
  
```  
UI_ANIMATION_KEYFRAME GetAnimationKeyframe() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um quadro-chave atual. O valor padrão é UI_ANIMATION_KEYFRAME_STORYBOARD_START.  
  
### <a name="remarks"></a>Comentários  
 Esse é um acessador para o valor subjacente de quadro-chave.  
  
##  <a name="a-nameisaddeda--cbasekeyframeisadded"></a><a name="isadded"></a>CBaseKeyFrame::IsAdded  
 Informa se um quadro-chave foi adicionado ao storyboard.  
  
```  
BOOL IsAdded() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se um quadro-chave for adicionado a um storyboard; Caso contrário FALSE.  
  
### <a name="remarks"></a>Comentários  
 Na classe base IsAdded sempre retorna TRUE, mas ele é substituído nas classes derivadas.  
  
##  <a name="a-nameiskeyframeatoffseta--cbasekeyframeiskeyframeatoffset"></a><a name="iskeyframeatoffset"></a>CBaseKeyFrame::IsKeyframeAtOffset  
 Especifica se o quadro-chave deve ser adicionado ao storyboard em deslocamento ou após a transição.  
  
```  
BOOL IsKeyframeAtOffset() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave deve ser adicionado ao storyboard em um deslocamento especificado. FALSE se o quadro-chave deve ser adicionado ao storyboard após alguma transição.  
  
### <a name="remarks"></a>Comentários  
 Especifica se o quadro-chave deve ser adicionado ao storyboard no deslocamento. O deslocamento ou transição deve ser especificada em uma classe derivada.  
  
##  <a name="a-namembaddeda--cbasekeyframembadded"></a><a name="m_badded"></a>CBaseKeyFrame::m_bAdded  
 Especifica se esse quadro-chave foi adicionado a um storyboard.  
  
```  
BOOL m_bAdded;  
```  
  
##  <a name="a-namembiskeyframeatoffseta--cbasekeyframembiskeyframeatoffset"></a><a name="m_biskeyframeatoffset"></a>CBaseKeyFrame::m_bIsKeyframeAtOffset  
 Especifica se esse quadro-chave deve ser adicionada ao storyboard em um deslocamento do outro quadro-chave existente, ou no final de alguma transição.  
  
```  
BOOL m_bIsKeyframeAtOffset;  
```  
  
##  <a name="a-namemkeyframea--cbasekeyframemkeyframe"></a><a name="m_keyframe"></a>CBaseKeyFrame::m_keyframe  
 Representa um quadro-chave de API de animação do Windows. Quando um quadro-chave não é inicializado, ele é definido como o valor predefinido UI_ANIMATION_KEYFRAME_STORYBOARD_START.  
  
```  
UI_ANIMATION_KEYFRAME m_keyframe;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

