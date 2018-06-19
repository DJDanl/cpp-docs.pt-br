---
title: Classe CMFCRibbonContextCaption | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonContextCaption
- AFXRIBBONBAR/CMFCRibbonContextCaption
- AFXRIBBONBAR/CMFCRibbonContextCaption::GetColor
- AFXRIBBONBAR/CMFCRibbonContextCaption::GetRightTabX
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonContextCaption [MFC], GetColor
- CMFCRibbonContextCaption [MFC], GetRightTabX
ms.assetid: cce2c0a2-8370-4266-997e-f8d0eeb3d616
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2fa63de2a633b2c8a9fff975de6eaaae7cbb470c
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33370315"
---
# <a name="cmfcribboncontextcaption-class"></a>Classe CMFCRibbonContextCaption
Implementa uma legenda colorida que aparece na parte superior de uma categoria de faixa de opções ou um contexto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonContextCaption : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonContextCaption::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCRibbonContextCaption::GetColor](#getcolor)|Retorna a cor da legenda.|  
|[CMFCRibbonContextCaption::GetRightTabX](#getrighttabx)||  
|`CMFCRibbonContextCaption::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe não pode ser instanciada diretamente. O [classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md) classe essa classe usa internamente para adicionar a cor para categorias de faixa de opções.  
  
 Para definir a cor para categorias de faixa de opções, chame [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor). Para definir a cor para categorias de contexto, chame [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonContextCaption](../../mfc/reference/cmfcribboncontextcaption-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonBar.h  
  
##  <a name="getcolor"></a>  CMFCRibbonContextCaption::GetColor  
 Retorna a cor de plano de fundo da legenda.  
  
```  
AFX_RibbonCategoryColor GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado pode ser um dos valores enumerados a seguir:  
  
- `AFX_CategoryColor_None`  
  
- `AFX_CategoryColor_Red`  
  
- `AFX_CategoryColor_Orange`  
  
- `AFX_CategoryColor_Yellow`  
  
- `AFX_CategoryColor_Green`  
  
- `AFX_CategoryColor_Blue`  
  
- `AFX_CategoryColor_Indigo`  
  
- `AFX_CategoryColor_Violet`  
  
### <a name="remarks"></a>Comentários  
 A cor da legenda pode ser definida chamando [CMFCRibbonCategory::SetTabColor](../../mfc/reference/cmfcribboncategory-class.md#settabcolor) ou [CMFCRibbonBar::AddContextCategory](../../mfc/reference/cmfcribbonbar-class.md#addcontextcategory).  
  
##  <a name="getrighttabx"></a>  CMFCRibbonContextCaption::GetRightTabX  
 Recupera a posição da borda direita do guia de faixa de opções da categoria.  
  
```  
int GetRightTabX() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o valor de X à direita do retângulo delimitador do `CMFCRibbonCategory` guia de faixa de opções do objeto ou um valor de -1 se a guia é truncada.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)   
 [Classe CMFCRibbonCategory](../../mfc/reference/cmfcribboncategory-class.md)   
 [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)
