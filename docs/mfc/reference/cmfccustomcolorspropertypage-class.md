---
title: Classe CMFCCustomColorsPropertyPage | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCCustomColorsPropertyPage
dev_langs:
- C++
helpviewer_keywords:
- CMFCCustomColorsPropertyPage class
ms.assetid: 46a45ba2-1fda-440d-8018-d4dcd44f5816
caps.latest.revision: 23
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
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: fa534f22438b7be37e7893e545c3e060df69384f
ms.lasthandoff: 02/25/2017

---
# <a name="cmfccustomcolorspropertypage-class"></a>Classe CMFCCustomColorsPropertyPage
Representa uma página de propriedades que pode selecionar cores personalizadas em uma caixa de diálogo de cor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCCustomColorsPropertyPage : public CPropertyPage  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CreateObject`|Usado pelo framework para criar uma instância desse tipo de classe dinâmica.|  
|`CMFCCustomColorsPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCCustomColorsPropertyPage::Setup](#setup)|Define os componentes de cor da página de propriedades.|  
  
### <a name="remarks"></a>Comentários  
 O `CMFCColorDialog` classe usa essa classe para exibir a página de propriedade de cor personalizada. Para obter mais informações sobre `CMFCColorDialog`, consulte [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCCustomColorsPropertyPage` de objeto e definir os componentes de cor da página de propriedades.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#35;](../../mfc/reference/codesnippet/cpp/cmfccustomcolorspropertypage-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCCustomColorsPropertyPage](../../mfc/reference/cmfccustomcolorspropertypage-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcustomcolorspropertypage.h  
  
##  <a name="a-namesetupa--cmfccustomcolorspropertypagesetup"></a><a name="setup"></a>CMFCCustomColorsPropertyPage::Setup  
 Define os componentes de cor da página de propriedades.  
  
```  
void Setup(
    BYTE R,  
    BYTE G,  
    BYTE B);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|||  
|-|-|  
|Parâmetro|Descrição|  
|[in] `R`|O componente vermelho do valor RGB.|  
|[in] `G`|O componente verde do valor RGB.|  
|[in] `B`|O componente azul do valor RGB.|  
  
### <a name="remarks"></a>Comentários  
 Esse método atualiza o RGB atual e os associados HLS (matiz, claridade e saturação) valores de cor da página de propriedades. O [CMFCColorDialog::SetPageTwo](../../mfc/reference/cmfccolordialog-class.md#setpagetwo) método chama esse método quando o framework inicializa a caixa de diálogo de cor ou o usuário pressiona o botão esquerdo do mouse. Para obter mais informações sobre `CMFCColorDialog`, consulte [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)   
 [Classe CMFCStandardColorsPropertyPage](../../mfc/reference/cmfcstandardcolorspropertypage-class.md)

