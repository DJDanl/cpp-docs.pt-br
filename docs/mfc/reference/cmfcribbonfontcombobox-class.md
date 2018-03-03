---
title: Classe CMFCRibbonFontComboBox | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::BuildFonts
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetCharSet
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetFontDesc
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetFontType
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetPitchAndFamily
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::RebuildFonts
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::SetFont
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonFontComboBox [MFC], CMFCRibbonFontComboBox
- CMFCRibbonFontComboBox [MFC], BuildFonts
- CMFCRibbonFontComboBox [MFC], GetCharSet
- CMFCRibbonFontComboBox [MFC], GetFontDesc
- CMFCRibbonFontComboBox [MFC], GetFontType
- CMFCRibbonFontComboBox [MFC], GetPitchAndFamily
- CMFCRibbonFontComboBox [MFC], RebuildFonts
- CMFCRibbonFontComboBox [MFC], SetFont
ms.assetid: 33b4db50-df4f-45fa-8f05-2e6e73c31435
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fab339300de907169ab7f4471d9892feadffad81
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcribbonfontcombobox-class"></a>Classe CMFCRibbonFontComboBox
Implementa uma caixa de combinação que contém uma lista de fontes. Você pode colocar a caixa de combinação em um painel de faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonFontComboBox : public CMFCRibbonComboBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCRibbonFontComboBox::~CMFCRibbonFontComboBox`|Destruidor.|  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonFontComboBox::CMFCRibbonFontComboBox](#cmfcribbonfontcombobox)|Constrói e inicializa um objeto `CMFCRibbonFontComboBox`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonFontComboBox::BuildFonts](#buildfonts)|Preenche a caixa de combinação de fonte de faixa de opções com as fontes do tipo de fonte especificada, o conjunto de caracteres e densidade e família.|  
|`CMFCRibbonFontComboBox::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|  
|[CMFCRibbonFontComboBox::GetCharSet](#getcharset)|Retorna o conjunto de caracteres especificado.|  
|[CMFCRibbonFontComboBox::GetFontDesc](#getfontdesc)||  
|[CMFCRibbonFontComboBox::GetFontType](#getfonttype)|Retorna os tipos de fonte para exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE ou uma combinação bit a bit disso.|  
|[CMFCRibbonFontComboBox::GetPitchAndFamily](#getpitchandfamily)|Retorna o tom e a família de fontes que são exibidos na caixa de combinação.|  
|`CMFCRibbonFontComboBox::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto associado esse tipo de classe.|  
|[CMFCRibbonFontComboBox::RebuildFonts](#rebuildfonts)|Preenche a caixa de combinação de fonte de faixa de opções com as fontes do tipo de fonte especificado anteriormente, o conjunto de caracteres e densidade e família.|  
|[CMFCRibbonFontComboBox::SetFont](#setfont)|Seleciona a fonte especificada na caixa de combinação.|  
  
## <a name="remarks"></a>Comentários  
 Depois de criar um `CMFCRibbonFontComboBox` de objeto, adicione-a um painel de faixa de opções chamando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)  
  
 [CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)  
  
 [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)  
  
 [CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)  
  
 [CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonComboBox.h  
  
##  <a name="buildfonts"></a>CMFCRibbonFontComboBox::BuildFonts  
 Preenche a caixa de combinação na faixa de opções com as fontes.  
  
```  
void BuildFonts(
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,  
    BYTE nCharSet = DEFAULT_CHARSET,  
    BYTE nPitchAndFamily = DEFAULT_PITCH);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nFontType`  
 Especifica o tipo de fonte de fontes para adicionar.  
  
 [in] `nCharSet`  
 Especifica o conjunto de caracteres das fontes para adicionar.  
  
 [in] `nPitchAndFamily`  
 Especifica a densidade e a família de fontes para adicionar.  
  
##  <a name="cmfcribbonfontcombobox"></a>CMFCRibbonFontComboBox::CMFCRibbonFontComboBox  
 Cria e inicializa um [CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md) objeto.  
  
```  
CMFCRibbonFontComboBox(
    UINT nID,  
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,  
    BYTE nCharSet = DEFAULT_CHARSET,  
    BYTE nPitchAndFamily = DEFAULT_PITCH,  
    int nWidth = -1);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nID`  
 A ID de comando do comando que é executado quando o usuário seleciona um item da caixa de combinação.  
  
 [in] `nFontType`  
 Especifica os tipos de fonte que exibir na caixa de combinação. As opções válidas são **DEVICE_FONTTYPE**, **RASTER_FONTTYPE**, e **TRUETYPE_FONTTYPE**, ou uma combinação bit a bit disso.  
  
 [in] `nCharSet`  
 Filtra as fontes na caixa de combinação para aqueles que pertencem ao conjunto de caracteres especificado.  
  
 [in] `nPitchAndFamily`  
 Especifica a densidade e a família de fontes que são exibidos na caixa de combinação.  
  
 [in] `nWidth`  
 Especifica a largura, em pixels, da caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre possíveis `nFontType` valores de parâmetro, consulte [EnumFontFamProc](http://msdn.microsoft.com/library/windows/desktop/dd162621) na documentação do SDK do Windows.  
  
 Para obter mais informações sobre conjuntos de caracteres válida que podem ser atribuídos a `nCharSet`e os valores válidos que podem ser atribuídos a `nPitchAndFamily`, consulte [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) na documentação do SDK do Windows.  
  
##  <a name="getfontdesc"></a>CMFCRibbonFontComboBox::GetFontDesc  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
const CMFCFontInfo* GetFontDesc(int iIndex = -1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="rebuildfonts"></a>CMFCRibbonFontComboBox::RebuildFonts  
 Preenche a caixa de combinação na faixa de opções com as fontes de um tipo de fonte especificado anteriormente, o conjunto de caracteres e o tom e a família.  
  
```  
void RebuildFonts();
```  
  
### <a name="remarks"></a>Comentários  
 Você pode especificar o tipo de fonte, o conjunto de caracteres, e a densidade e a família de fontes para incluir na caixa de combinação de fonte da faixa de opções caixa o [construtor](#cmfcribbonfontcombobox) para esta classe, ou chamando [CMFCRibbonFontComboBox::BuildFonts](#buildfonts).  
  
##  <a name="setfont"></a>CMFCRibbonFontComboBox::SetFont  
 Seleciona a fonte especificada na caixa de combinação.  
  
```  
BOOL SetFont(
    LPCTSTR lpszName,  
    BYTE nCharSet = DEFAULT_CHARSET,  
    BOOL bExact = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszName`  
 Especifica o nome da fonte para selecionar.  
  
 `nCharSet`  
 Especifica o conjunto de caracteres para a fonte selecionada.  
  
 `bExact`  
 `TRUE`para especificar que o conjunto de caracteres deve corresponder ao selecionar uma fonte. `FALSE` para especificar que o conjunto de caracteres pode ser ignorado ao selecionar uma fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte especificada foi encontrada e selecionada. Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcharset"></a>CMFCRibbonFontComboBox::GetCharSet  
 Retorna o conjunto de caracteres especificado.  
  
```  
BYTE GetCharSet() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Conjunto de caracteres (consulte LOGFONT na documentação do SDK do Windows).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getfonttype"></a>CMFCRibbonFontComboBox::GetFontType  
 Retorna os tipos de fonte para exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE ou uma combinação bit a bit disso.  
  
```  
int GetFontType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tipos de fonte (consulte EnumFontFamProc na documentação do SDK do Windows).  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getpitchandfamily"></a>CMFCRibbonFontComboBox::GetPitchAndFamily  
 Retorna o tom e a família de fontes que são exibidos na caixa de combinação.  
  
```  
BYTE GetPitchAndFamily() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Tom e a família de produtos (consulte LOGFONT na documentação do SDK do Windows).  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)
