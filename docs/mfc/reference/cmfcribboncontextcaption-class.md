---
title: Classe CMFCRibbonContextCaption | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonContextCaption
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonContextCaption class
ms.assetid: cce2c0a2-8370-4266-997e-f8d0eeb3d616
caps.latest.revision: 24
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
ms.openlocfilehash: 54f71af5ec46a8ddac4459e9ffdbc5b10f3106d4
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcribboncontextcaption-class"></a>Classe CMFCRibbonContextCaption
Implementa uma legenda de cor que aparece na parte superior de uma categoria de faixa de opções ou um contexto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonContextCaption : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonContextCaption::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|[CMFCRibbonContextCaption::GetColor](#getcolor)|Retorna a cor da legenda.|  
|[CMFCRibbonContextCaption::GetRightTabX](#getrighttabx)||  
|`CMFCRibbonContextCaption::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe não pode ser instanciada diretamente. O [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) classe essa classe usa internamente para adicionar cor a categorias de faixa de opções.  
  
 Para definir a cor para categorias de faixa de opções, chame [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor). Para definir a cor para categorias de contexto, chame [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonContextCaption](../../mfc/reference/cmfcribboncontextcaption-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonBar.h  
  
##  <a name="a-namegetcolora--cmfcribboncontextcaptiongetcolor"></a><a name="getcolor"></a>CMFCRibbonContextCaption::GetColor  
 Retorna a cor de plano de fundo da legenda.  
  
```  
AFX_RibbonCategoryColor GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado pode ser um dos seguintes valores enumerados:  
  
- `AFX_CategoryColor_None`  
  
- `AFX_CategoryColor_Red`  
  
- `AFX_CategoryColor_Orange`  
  
- `AFX_CategoryColor_Yellow`  
  
- `AFX_CategoryColor_Green`  
  
- `AFX_CategoryColor_Blue`  
  
- `AFX_CategoryColor_Indigo`  
  
- `AFX_CategoryColor_Violet`  
  
### <a name="remarks"></a>Comentários  
 A cor da legenda pode ser definida ao chamar [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor) ou [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).  
  
##  <a name="a-namegetrighttabxa--cmfcribboncontextcaptiongetrighttabx"></a><a name="getrighttabx"></a>CMFCRibbonContextCaption::GetRightTabX  
 Recupera a posição da borda direita do guia de faixa de opções da categoria.  
  
```  
int GetRightTabX() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor X à direita do retângulo delimitador do `CMFCRibbonCategory` guia de faixa de opções do objeto ou um valor de -1 se a guia é truncada.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)   
 [Classe de CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md)   
 [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)

