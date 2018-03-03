---
title: Classe CMFCCustomColorsPropertyPage | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCCustomColorsPropertyPage
- AFXCUSTOMCOLORSPROPERTYPAGE/CMFCCustomColorsPropertyPage
- AFXCUSTOMCOLORSPROPERTYPAGE/CMFCCustomColorsPropertyPage::Setup
dev_langs:
- C++
helpviewer_keywords:
- CMFCCustomColorsPropertyPage [MFC], Setup
ms.assetid: 46a45ba2-1fda-440d-8018-d4dcd44f5816
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7dac4260c69e4d2bbf9c74965e73f6961dd6ad6b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfccustomcolorspropertypage-class"></a>Classe CMFCCustomColorsPropertyPage
Representa uma página de propriedades que pode selecionar cores personalizadas em uma caixa de diálogo de cor.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCCustomColorsPropertyPage : public CPropertyPage  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage`|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|||  
|-|-|  
|Nome|Descrição|  
|`CMFCCustomColorsPropertyPage::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|`CMFCCustomColorsPropertyPage::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCCustomColorsPropertyPage::Setup](#setup)|Define os componentes de cor da página de propriedades.|  
  
### <a name="remarks"></a>Comentários  
 O `CMFCColorDialog` classe usa essa classe para exibir a página de propriedade de cor personalizada. Para obter mais informações sobre `CMFCColorDialog`, consulte [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCCustomColorsPropertyPage` de objeto e definir os componentes de cor da página de propriedades.  
  
 [!code-cpp[NVC_MFC_RibbonApp#35](../../mfc/reference/codesnippet/cpp/cmfccustomcolorspropertypage-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CPropertyPage](../../mfc/reference/cpropertypage-class.md)  
  
 [CMFCCustomColorsPropertyPage](../../mfc/reference/cmfccustomcolorspropertypage-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcustomcolorspropertypage.h  
  
##  <a name="setup"></a>CMFCCustomColorsPropertyPage::Setup  
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
|[in] `R`|O componente vermelho, o valor de RGB.|  
|[in] `G`|O componente verde, o valor de RGB.|  
|[in] `B`|O componente azul, o valor de RGB.|  
  
### <a name="remarks"></a>Comentários  
 Este método atualizará o RGB atual e as HLS (matiz, luminosidade e saturação) cor valores associados da página de propriedades. O [CMFCColorDialog::SetPageTwo](../../mfc/reference/cmfccolordialog-class.md#setpagetwo) método chama este método quando o framework inicializa a caixa de diálogo de cor ou o usuário pressiona o botão esquerdo do mouse. Para obter mais informações sobre `CMFCColorDialog`, consulte [CMFCColorDialog classe](../../mfc/reference/cmfccolordialog-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)   
 [Classe CMFCStandardColorsPropertyPage](../../mfc/reference/cmfcstandardcolorspropertypage-class.md)
