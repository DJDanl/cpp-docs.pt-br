---
title: Classe CMFCFontInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCFontInfo
dev_langs:
- C++
helpviewer_keywords:
- CMFCFontInfo class
- CMFCFontInfo::CMFCFontInfo constructor
ms.assetid: f88329b2-d74e-4921-9441-a3bb6536a049
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
ms.openlocfilehash: ac1409bcfce389cbc334edd2b864f7505d7443c7
ms.lasthandoff: 02/25/2017

---
# <a name="cmfcfontinfo-class"></a>Classe CMFCFontInfo
O `CMFCFontInfo` classe descreve o nome e outros atributos de uma fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCFontInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCFontInfo`|Constrói um objeto `CMFCFontInfo`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontInfo::GetFullName](#getfullname)|Recupera os nomes concatenados de uma fonte e seu caractere definido (script).|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontInfo::m_nCharSet](#m_ncharset)|Um valor que especifica o conjunto de caracteres (script) associado à fonte.|  
|[CMFCFontInfo::m_nPitchAndFamily](#m_npitchandfamily)|Um valor que especifica a densidade e a família da fonte.|  
|[CMFCFontInfo::m_nType](#m_ntype)|Um valor que especifica o tipo da fonte.|  
|[CMFCFontInfo::m_strName](#m_strname)|O nome da fonte. Por exemplo, **Arial**.|  
|[CMFCFontInfo::m_strScript](#m_strscript)|O nome de um conjunto de caracteres (script) associado à fonte.|  
  
## <a name="remarks"></a>Comentários  
 Você pode anexar um `CMFCFontInfo` objeto a um item do [CMFCToolBarFontComboBox classe](../../mfc/reference/cmfctoolbarfontcombobox-class.md) classe. Chamar o [CMFCToolBarFontComboBox::GetFontDesc](../../mfc/reference/cmfctoolbarfontcombobox-class.md#getfontdesc) método para recuperar um ponteiro para um `CMFCFontInfo` objeto.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários membros da `CMFCFontInfo` classe. O exemplo demonstra como obter um `CMFCFontInfo` de objeto um `CMFCRibbonFontComboBox`e como acessar suas variáveis locais. Este exemplo é parte do [exemplo MSOffice 2007 demonstração](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo n º&6;](../../mfc/reference/codesnippet/cpp/cmfcfontinfo-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
##  <a name="a-namecmfcfontinfoa--cmfcfontinfocmfcfontinfo"></a><a name="cmfcfontinfo"></a>CMFCFontInfo::CMFCFontInfo  
 Constrói um objeto `CMFCFontInfo`.  
  
```  
CMFCFontInfo(
    LPCTSTR lpszName,  
    LPCTSTR lpszScript,  
    BYTE nCharSet,  
    BYTE nPitchAndFamily,  
    int nType);  
  
CMFCFontInfo(const CMFCFontInfo& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 O nome da fonte. Para obter mais informações, consulte o `lfFaceName` membro do [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura.  
  
 [in] `lpszScript`  
 O nome do script (conjunto de caracteres) da fonte.  
  
 [in] `nCharSet`  
 Um valor que especifica o conjunto de caracteres (script) da fonte. Para obter mais informações, consulte o `lfCharSet` membro do [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura.  
  
 [in] `nPitchAndFamily`  
 Um valor que especifica a densidade e a família da fonte. Para obter mais informações, consulte o `lfPitchAndFamily` membro do [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura.  
  
 [in] `nType`  
 Um valor que especifica o tipo de fonte. Esse parâmetro pode ser uma combinação bit a bit (OR) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.  
  
 [in] `src`  
 Existente `CMFCFontInfo` objeto cujos membros são usados para construir essa `CMFCFontInfo` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Esta documentação usa os termos *do conjunto de caracteres* e *script* alternadamente. A *script*, que é também conhecido como um sistema de escrita, é uma coleção de regras para escrever esses caracteres em um ou mais idiomas e caracteres. O conjunto de caracteres inclui o alfabeto e pontuação usados no script. Por exemplo, o script latino é usado para inglês como ele é falado nos Estados Unidos, e o alfabeto inclui os caracteres de À Z. O `lfCharSet` membro do [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) estrutura Especifica um conjunto de caracteres. Por exemplo, o valor `ANSI_CHARSET` Especifica a [!INCLUDE[vcpransi](../../atl-mfc-shared/reference/includes/vcpransi_md.md)] conjunto de caracteres, que inclui o alfabeto de script latino.  
  
##  <a name="a-namegetfullnamea--cmfcfontinfogetfullname"></a><a name="getfullname"></a>CMFCFontInfo::GetFullName  
 Recupera os nomes concatenados de uma fonte e seu caractere definido (script).  
  
```  
CString GetFullName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o nome da fonte e o script.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para obter o nome completo da fonte. Por exemplo, se o nome da fonte é `Arial` e o script da fonte é `Cyrillic`, esse método retorna "Arial (cirílico)".  
  
##  <a name="a-namemncharseta--cmfcfontinfomncharset"></a><a name="m_ncharset"></a>CMFCFontInfo::m_nCharSet  
 Um valor que especifica o conjunto de caracteres (script) associado à fonte.  
  
```  
const BYTE m_nCharSet;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `nCharSet` parâmetro o [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="a-namemnpitchandfamilya--cmfcfontinfomnpitchandfamily"></a><a name="m_npitchandfamily"></a>CMFCFontInfo::m_nPitchAndFamily  
 Um valor que especifica a densidade (tamanho de ponto) e a família (por exemplo, serif, sans-serif e monospace) da fonte.  
  
```  
const BYTE m_nPitchAndFamily;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `nPitchAndFamily` parâmetro o [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="a-namemntypea--cmfcfontinfomntype"></a><a name="m_ntype"></a>CMFCFontInfo::m_nType  
 Um valor que especifica o tipo da fonte.  
  
```  
const int m_nType;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `nType` parâmetro o [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="a-namemstrnamea--cmfcfontinfomstrname"></a><a name="m_strname"></a>CMFCFontInfo::m_strName  
 O nome da fonte: por exemplo, **Arial**.  
  
```  
const CString m_strName;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `lpszName` parâmetro o [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="a-namemstrscripta--cmfcfontinfomstrscript"></a><a name="m_strscript"></a>CMFCFontInfo::m_strScript  
 O nome de um conjunto de caracteres (script) associado à fonte.  
  
```  
const CString m_strScript;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o `lpszScript` parâmetro o [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)   
 [Classe CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)

