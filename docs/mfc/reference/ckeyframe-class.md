---
title: Classe CKeyFrame | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
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
- CKeyFrame class
ms.assetid: d050a562-20f6-4c65-8ce5-ccb3aef1a20e
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: d8ecff2e36148fb114ee708712b6e8bd0fe558ed
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ckeyframe-class"></a>Classe CKeyFrame
Representa um quadro chave da animação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CKeyFrame : public CBaseKeyFrame;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::CKeyFrame](#ckeyframe)|Sobrecarregado. Constrói um quadro-chave que depende de outro quadro-chave.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::AddToStoryboard](#addtostoryboard)|Adiciona um quadro-chave a um storyboard. (Substitui [CBaseKeyFrame::AddToStoryboard](../../mfc/reference/cbasekeyframe-class.md#addtostoryboard).)|  
|[CKeyFrame::AddToStoryboardAfterTransition](#addtostoryboardaftertransition)|Adiciona um quadro-chave para criar um storyboard depois de transição.|  
|[CKeyFrame::AddToStoryboardAtOffset](#addtostoryboardatoffset)|Adiciona um quadro-chave para criar um storyboard no deslocamento.|  
|[CKeyFrame::GetExistingKeyframe](#getexistingkeyframe)|Retorna um ponteiro para um quadro-chave que depende de seu quadro-chave.|  
|[CKeyFrame::GetOffset](#getoffset)|Retorna um deslocamento de outro quadro-chave.|  
|[CKeyFrame::GetTransition](#gettransition)|Retorna um ponteiro para uma transição que depende de seu quadro-chave.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CKeyFrame::m_offset](#m_offset)|Especifica o deslocamento desse quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.|  
|[CKeyFrame::m_pExistingKeyFrame](#m_pexistingkeyframe)|Armazena um ponteiro para um keframe existente. Esse quadro-chave é adicionada ao storyboard com m_offset para o quadro-chave existente.|  
|[CKeyFrame::m_pTransition](#m_ptransition)|Armazena um ponteiro para transtion que começa em seu quadro-chave.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe implementa um quadro chave da animação. Um quadro-chave representa um momento específico em um storyboard e pode ser usado para especificar os horários de início e término de transições. Um quadro-chave pode ser baseado em outro quadro-chave e têm um deslocamento (em segundos), ou pode ser baseado em uma transição e representa um ponto no tempo em que essa transição termina.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CBaseKeyFrame](../../mfc/reference/cbasekeyframe-class.md)  
  
 [CKeyFrame](../../mfc/reference/ckeyframe-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxanimationcontroller.h  
  
##  <a name="addtostoryboard"></a>CKeyFrame::AddToStoryboard  
 Adiciona um quadro-chave a um storyboard.  
  
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
 Este método adiciona um quadro-chave para criar um storyboard. Se ele depende de outro quadro-chave ou a transição e bDeepAdd for TRUE, esse método tentará adicioná-los de maneira recursiva.  
  
##  <a name="addtostoryboardaftertransition"></a>CKeyFrame::AddToStoryboardAfterTransition  
 Adiciona um quadro-chave para criar um storyboard depois de transição.  
  
```  
BOOL AddToStoryboardAfterTransition(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Especifica se deseja adicionar uma transição recursivamente.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pela estrutura para adicionar um quadro-chave para criar um storyboard depois de transição.  
  
##  <a name="addtostoryboardatoffset"></a>CKeyFrame::AddToStoryboardAtOffset  
 Adiciona um quadro-chave para criar um storyboard no deslocamento.  
  
```  
virtual BOOL AddToStoryboardAtOffset(
    IUIAnimationStoryboard* pStoryboard,  
    BOOL bDeepAdd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStoryboard`  
 Um ponteiro para um storyboard.  
  
 `bDeepAdd`  
 Especifica se adicionar um quadro-chave esse quadro chave dependem recursivamente.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o quadro-chave foi adicionada com êxito.  
  
### <a name="remarks"></a>Comentários  
 Essa função é chamada pela estrutura para adicionar um quadro-chave para criar um storyboard no deslocamento.  
  
##  <a name="ckeyframe"></a>CKeyFrame::CKeyFrame  
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
 Um ponteiro para o quadro-chave.  
  
 `offset`  
 Deslocamento, em segundos, de quadro-chave especificada pelo pKeyframe.  
  
### <a name="remarks"></a>Comentários  
 O quadro-chave construído representará um momento específico em um storyboard quando termina a transição especificada.  
  
##  <a name="getexistingkeyframe"></a>CKeyFrame::GetExistingKeyframe  
 Retorna um ponteiro para um quadro-chave que depende de seu quadro-chave.  
  
```  
CBaseKeyFrame* GetExistingKeyframe();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para o quadro-chave ou NULL se esse quadro-chave não depende de outro quadro-chave.  
  
### <a name="remarks"></a>Comentários  
 Esse é um acessador para um quadro-chave que depende de seu quadro-chave.  
  
##  <a name="getoffset"></a>CKeyFrame::GetOffset  
 Retorna um deslocamento de outro quadro-chave.  
  
```  
UI_ANIMATION_SECONDS GetOffset();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um deslocamento em segundos desde a outro quadro-chave.  
  
### <a name="remarks"></a>Comentários  
 Esse método deve ser chamado para determinar um deslocamento em segundos desde a outro quadro-chave.  
  
##  <a name="gettransition"></a>CKeyFrame::GetTransition  
 Retorna um ponteiro para uma transição que depende de seu quadro-chave.  
  
```  
CBaseTransition* GetTransition();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro válido para transição ou NULL se esse quadro-chave não depende de transição.  
  
### <a name="remarks"></a>Comentários  
 Esse é um acessador para uma transição que depende de seu quadro-chave.  
  
##  <a name="m_offset"></a>CKeyFrame::m_offset  
 Especifica o deslocamento desse quadro-chave de um quadro-chave armazenado em m_pExistingKeyFrame.  
  
```  
UI_ANIMATION_SECONDS m_offset;  
```  
  
##  <a name="m_pexistingkeyframe"></a>CKeyFrame::m_pExistingKeyFrame  
 Armazena um ponteiro para um keframe existente. Esse quadro-chave é adicionada ao storyboard com m_offset para o quadro-chave existente.  
  
```  
CBaseKeyFrame* m_pExistingKeyFrame;  
```  
  
##  <a name="m_ptransition"></a>CKeyFrame::m_pTransition  
 Armazena um ponteiro para transtion que começa em seu quadro-chave.  
  
```  
CBaseTransition* m_pTransition;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

