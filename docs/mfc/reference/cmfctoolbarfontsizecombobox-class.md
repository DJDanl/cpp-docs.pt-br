---
title: Classe CMFCToolBarFontSizeComboBox | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::GetTwipSize
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::RebuildFontSizes
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontSizeComboBox::SetTwipSize
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarFontSizeComboBox class
ms.assetid: 72e0c44c-6a0e-4194-a71f-ab64e3afb9b5
caps.latest.revision: 26
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
ms.openlocfilehash: 9dddb563617a708bdc8b2193fa5ee8bd10321828
ms.lasthandoff: 02/25/2017

---
# <a name="cmfctoolbarfontsizecombobox-class"></a>Classe CMFCToolBarFontSizeComboBox
Um botão de barra de ferramentas que contém um controle de caixa de combinação que permite que o usuário selecione um tamanho de fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarFontSizeComboBox : public CMFCToolBarComboBoxButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox](#cmfctoolbarfontsizecombobox)|Constrói um objeto `CMFCToolBarFontSizeComboBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize)|Retorna o tamanho da fonte selecionada em twips.|  
|[CMFCToolBarFontSizeComboBox::RebuildFontSizes](#rebuildfontsizes)|Preenche a lista da caixa de combinação com todos os tamanhos de fonte com suporte para uma fonte especificada.|  
|[CMFCToolBarFontSizeComboBox::SetTwipSize](#settwipsize)|Define o tamanho da fonte em twips.|  
  
## <a name="remarks"></a>Comentários  
 Você pode usar um `CMFCToolBarFontSizeComboBox` objeto junto com um [CMFCToolBarFontComboBox classe](../../mfc/reference/cmfctoolbarfontcombobox-class.md) objeto para permitir que um usuário selecione uma fonte e tamanho da fonte.  
  
 Você pode adicionar um botão de caixa de combinação de tamanho de fonte para uma barra de ferramentas, exatamente como adicionar um botão de caixa de combinação de fonte. Para obter mais informações, consulte [CMFCToolBarFontComboBox classe](../../mfc/reference/cmfctoolbarfontcombobox-class.md).  
  
 Quando o usuário seleciona uma nova fonte em uma `CMFCToolBarFontComboBox` do objeto, você pode preencher a caixa de combinação de tamanho de fonte com os tamanhos com suporte para essa fonte usando o [CMFCToolBarFontSizeComboBox::RebuildFontSizes](#rebuildfontsizes) método.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCToolBarFontSizeComboBox` classe para configurar um `CMFCToolBarFontSizeComboBox` objeto. O exemplo ilustra como recuperar o tamanho da fonte, em twips, a caixa de texto, preencha a caixa de combinação de tamanho de fonte com todos os tamanhos válidos de determinada fonte e especifique o tamanho da fonte em twips. Este trecho de código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad n º&8;](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontsizecombobox-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)  
  
 [CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
##  <a name="cmfctoolbarfontsizecombobox"></a>CMFCToolBarFontSizeComboBox::CMFCToolBarFontSizeComboBox  
 Constrói um objeto `CMFCToolBarFontSizeComboBox`.  
  
```  
CMFCToolBarFontSizeComboBox();
```  
  
##  <a name="gettwipsize"></a>CMFCToolBarFontSizeComboBox::GetTwipSize  
 Recupera o tamanho da fonte, em twips, a caixa de texto de uma caixa de combinação de tamanho de fonte.  
  
```  
int GetTwipSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o valor de retorno for positivo, é o tamanho da fonte em twips. É -1 se a caixa de texto da caixa de combinação está vazia. É -2 se ocorrer um erro.  
  
##  <a name="rebuildfontsizes"></a>CMFCToolBarFontSizeComboBox::RebuildFontSizes  
 Preenche uma caixa de combinação de tamanho de fonte com todos os tamanhos válidos de determinada fonte.  
  
```  
void RebuildFontSizes(const CString& strFontName);
```  
  
### <a name="parameters"></a>Parâmetros  
 `[in] strFontName`  
 Especifica um nome de fonte.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função quando você deseja sincronizar entre a seleção em uma caixa de combinação de fonte e uma caixa de combinação de tamanho de fonte, como um [CMFCToolBarFontComboBox classe](../../mfc/reference/cmfctoolbarfontcombobox-class.md).  
  
##  <a name="settwipsize"></a>CMFCToolBarFontSizeComboBox::SetTwipSize  
 Arredonda especificada o tamanho (em twips) para o tamanho mais próximo em pontos e, em seguida, define o tamanho selecionado na caixa de combinação para esse valor.  
  
```  
void SetTwipSize(int nSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nSize`  
 Especifica o tamanho da fonte (em twips) para definir.  
  
### <a name="remarks"></a>Comentários  
 Você pode recuperar o tamanho de fonte válido anterior posteriormente chamando o [CMFCToolBarFontSizeComboBox::GetTwipSize](#gettwipsize) método.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)   
 [Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)   
 [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)   
 [Passo a passo: Colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)




