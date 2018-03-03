---
title: Classe CMFCPropertyGridFileProperty | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty
- AFXPROPERTYGRIDCTRL/CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty
dev_langs:
- C++
helpviewer_keywords:
- CMFCPropertyGridFileProperty [MFC], CMFCPropertyGridFileProperty
ms.assetid: 2bb8b8b4-47fc-4798-bd5e-dc8ea0b4cd9d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4111c7da24300d83128d56b85266ee808b304ace
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcpropertygridfileproperty-class"></a>Classe CMFCPropertyGridFileProperty
O `CMFCPropertyGridFileProperty` classe oferece suporte a um item de controle de lista de propriedade que abre uma caixa de diálogo de seleção de arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCPropertyGridFileProperty : public CMFCPropertyGridProperty  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty](#cmfcpropertygridfileproperty)|Constrói um objeto `CMFCPropertyGridFileProperty`.|  
|`CMFCPropertyGridFileProperty::~CMFCPropertyGridFileProperty`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCPropertyGridFileProperty::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|`CMFCPropertyGridFileProperty::OnClickButton`|(Substitui [CMFCPropertyGridProperty::OnClickButton](../../mfc/reference/cmfcpropertygridproperty-class.md#onclickbutton).)|  
  
### <a name="remarks"></a>Comentários  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)  
  
 [CMFCPropertyGridFileProperty](../../mfc/reference/cmfcpropertygridfileproperty-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxpropertygridctrl.h  
  
##  <a name="cmfcpropertygridfileproperty"></a>CMFCPropertyGridFileProperty::CMFCPropertyGridFileProperty  
 Constrói um objeto `CMFCPropertyGridFileProperty`.  
  
```  
CMFCPropertyGridFileProperty(
    const CString& strName,  
    BOOL bOpenFileDialog,  
    const CString& strFileName,  
    LPCTSTR lpszDefExt=NULL,  
    DWORD dwFlags=OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,  
    LPCTSTR lpszFilter=NULL,  
    LPCTSTR lpszDescr=NULL,  
    DWORD_PTR dwData=0);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strName`  
 O nome da propriedade.  
  
 [in] `bOpenFileDialog`  
 `TRUE`Para abrir um **abrir arquivo** caixa de diálogo. `FALSE` para abrir um **salvar arquivo** caixa de diálogo.  
  
 [in] `strFileName`  
 O nome do arquivo inicial.  
  
 [in] `lpszDefExt`  
 Uma cadeia de caracteres de uma ou mais extensões de nome de arquivo. O valor padrão é `NULL`.  
  
 [in] `dwFlags`  
 Sinalizadores de caixa de diálogo. O valor padrão é uma combinação bit a bit (ou) de `OFN_HIDEREADONLY` e `OFN_OVERWRITEPROMPT`.  
  
 [in] `lpszFilter`  
 Uma cadeia de caracteres de um ou mais filtros de arquivo. O valor padrão é `NULL`.  
  
 [in] `lpszDescr`  
 A descrição do item de propriedade. O valor padrão é `NULL`.  
  
 [in] `dwData`  
 Dados específicos do aplicativo que está associados ao item de propriedade. Por exemplo, um inteiro de 32 bits ou um ponteiro para outros dados. O valor padrão é 0.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Para obter uma lista completa de sinalizadores disponíveis, consulte [estrutura OPENFILENAME](https://msdn.microsoft.com/library/ms646839.aspx).  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto usando o construtor do `CMFCPropertyGridFileProperty` classe. Este exemplo é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#22](../../mfc/codesnippet/cpp/cmfcpropertygridfileproperty-class_1.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCPropertyGridCtrl](../../mfc/reference/cmfcpropertygridctrl-class.md)   
 [Classe CMFCPropertyGridProperty](../../mfc/reference/cmfcpropertygridproperty-class.md)
