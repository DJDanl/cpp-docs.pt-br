---
title: Classe CKeyFrame | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::CKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboard
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboardAfterTransition
- AFXANIMATIONCONTROLLER/CKeyFrame::AddToStoryboardAtOffset
- AFXANIMATIONCONTROLLER/CKeyFrame::GetExistingKeyframe
- AFXANIMATIONCONTROLLER/CKeyFrame::GetOffset
- AFXANIMATIONCONTROLLER/CKeyFrame::GetTransition
- AFXANIMATIONCONTROLLER/CKeyFrame::m_offset
- AFXANIMATIONCONTROLLER/CKeyFrame::m_pExistingKeyFrame
- AFXANIMATIONCONTROLLER/CKeyFrame::m_pTransition
dev_langs:
- C++
helpviewer_keywords:
- CKeyFrame [MFC], CKeyFrame
- CKeyFrame [MFC], AddToStoryboard
- CKeyFrame [MFC], AddToStoryboardAfterTransition
- CKeyFrame [MFC], AddToStoryboardAtOffset
- CKeyFrame [MFC], GetExistingKeyframe
- CKeyFrame [MFC], GetOffset
- CKeyFrame [MFC], GetTransition
- CKeyFrame [MFC], m_offset
- CKeyFrame [MFC], m_pExistingKeyFrame
- CKeyFrame [MFC], m_pTransition
ms.assetid: d050a562-20f6-4c65-8ce5-ccb3aef1a20e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9a9e9ff3d6e3e4bcccf8e9ebd46f791f60f1cc37
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="ckeyframe-class"></a>Classe CKeyFrame
Representa um quadro-chave de animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CKeyFrame : public CBaseKeyFrame;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::CKeyFrame](#ckeyframe)|Sobrecarregado. Constrói um quadro-chave que depende de outro quadro-chave.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave para um storyboard. (Substitui [CBaseKeyFrame::AddToStoryboard](../../mfc/reference/cbasekeyframe-class.md#addtostoryboard).)|  
|[CKeyFrame::AddToStoryboardAfterTransition](#addtostoryboardaftertransition)|Adiciona um quadro-chave para o storyboard após a transição.|  
|[CKeyFrame::AddToStoryboardAtOffset](#addtostoryboardatoffset)|Adiciona um quadro-chave para o storyboard no deslocamento.|  
|[CKeyFrame::GetExistingKeyframe](#getexistingkeyframe)|Retorna um ponteiro para um quadro-chave que este quadro-chave depende.|  
|[CKeyFrame::GetOffset](#getoffset)|Retorna um deslocamento de quadro-chave de outros.|  
|[CKeyFrame::GetTransition](#gettransition)|Retorna um ponteiro para uma transição que este quadro-chave depende.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::m_offset](#m_offset)|Especifica o deslocamento deste quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.|  
|[CKeyFrame::m_pExistingKeyFrame](#m_pexistingkeyframe)|Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionada ao storyboard com m_offset para o quadro-chave existente.|  
|[CKeyFrame::m_pTransition](#m_ptransition)|Armazena um ponteiro para transtion que começa neste quadro-chave.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe implementa um quadro-chave de animação. Um quadro-chave representa um momento específico dentro de um storyboard e pode ser usado para especificar os horários de início e término de transições. Um quadro chave pode ser baseado em outro quadro-chave e têm um deslocamento (em segundos), ou pode ser baseado em uma transição e representa um ponto no tempo quando essa transição termina.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseKeyFrame](../../mfc/reference/cbasekeyframe-class.md)  
  
 [CKeyFrame](../../mfc/reference/ckeyframe-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtostoryboard"></a>  CKeyFrame::AddToStoryboard  
 Adiciona um quadro-chave para um storyboard.  
  
```  
virtual BOOL AddToStoryboard(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Especifica se deseja adicionar o quadro-chave ou transição recursivamente.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona um quadro-chave para o storyboard. Se ele depende de outro quadro-chave ou uma transição e bDeepAdd for verdadeiro, esse método tentará para adicioná-los de forma recursiva.  
  
##  <a name="addtostoryboardaftertransition"></a>  CKeyFrame::AddToStoryboardAfterTransition  
 Adiciona um quadro-chave para o storyboard após a transição.  
  
```  
BOOL AddToStoryboardAfterTransition(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Especifica se deseja adicionar uma transição de forma recursiva.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pelo framework para adicionar um quadro-chave para o storyboard após a transição.  
  
##  <a name="addtostoryboardatoffset"></a>  CKeyFrame::AddToStoryboardAtOffset  
 Adiciona um quadro-chave para o storyboard no deslocamento.  
  
```  
virtual BOOL AddToStoryboardAtOffset(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Especifica se para adicionar um quadro-chave este quadro-chave dependem recursivamente.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pelo framework para adicionar um quadro-chave para o storyboard no deslocamento.  
  
##  <a name="ckeyframe"></a>  CKeyFrame::CKeyFrame  
 Constrói um quadro-chave que depende de uma transição.  
  
```  
CKeyFrame(CBaseTransition* pTransition);

 
CKeyFrame(
    CBaseKeyFrame* pKeyframe,  
    UI_ANIMATION_SECONDS offset = 0.0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pTransition`  
 Um ponteiro para uma transição.  
  
 `pKeyframe`  
 Um ponteiro de quadro-chave.  
  
 `offset`  
 Deslocamento, em segundos, de quadro-chave especificada pelo pKeyframe.  
  
### <a name="remarks"></a>Comentários  
 O quadro-chave construído representará um momento específico dentro de um storyboard quando termina a transição especificada.  
  
##  <a name="getexistingkeyframe"></a>  CKeyFrame::GetExistingKeyframe  
 Retorna um ponteiro para um quadro-chave que este quadro-chave depende.  
  
```  
CBaseKeyFrame* GetExistingKeyframe();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para o quadro-chave, ou nulo se este quadro-chave não é dependente de outro quadro-chave.  
  
### <a name="remarks"></a>Comentários  
 Este é um acessador para um quadro-chave que este quadro-chave depende.  
  
##  <a name="getoffset"></a>  CKeyFrame::GetOffset  
 Retorna um deslocamento de quadro-chave de outros.  
  
```  
UI_ANIMATION_SECONDS GetOffset();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um deslocamento em segundos de outro quadro-chave.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado para determinar um deslocamento em segundos de outro quadro-chave.  
  
##  <a name="gettransition"></a>  CKeyFrame::GetTransition  
 Retorna um ponteiro para uma transição que este quadro-chave depende.  
  
```  
CBaseTransition* GetTransition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para a transição, ou nulo se este quadro-chave não é dependente de transição.  
  
### <a name="remarks"></a>Comentários  
 Este é um acessador para uma transição que este quadro-chave depende.  
  
##  <a name="m_offset"></a>  CKeyFrame::m_offset  
 Especifica o deslocamento deste quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.  
  
```  
UI_ANIMATION_SECONDS m_offset;  
```  
  
##  <a name="m_pexistingkeyframe"></a>  CKeyFrame::m_pExistingKeyFrame  
 Armazena um ponteiro para um keframe existente. Este quadro-chave é adicionada ao storyboard com m_offset para o quadro-chave existente.  
  
```  
CBaseKeyFrame* m_pExistingKeyFrame;  
```  
  
##  <a name="m_ptransition"></a>  CKeyFrame::m_pTransition  
 Armazena um ponteiro para transtion que começa neste quadro-chave.  
  
```  
CBaseTransition* m_pTransition;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)
