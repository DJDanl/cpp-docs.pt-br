---
title: Classe CMFCFontInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCFontInfo
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::GetFullName
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nCharSet
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nPitchAndFamily
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nType
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_strName
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_strScript
dev_langs:
- C++
helpviewer_keywords:
- CMFCFontInfo [MFC], GetFullName
- CMFCFontInfo [MFC], m_nCharSet
- CMFCFontInfo [MFC], m_nPitchAndFamily
- CMFCFontInfo [MFC], m_nType
- CMFCFontInfo [MFC], m_strName
- CMFCFontInfo [MFC], m_strScript
ms.assetid: f88329b2-d74e-4921-9441-a3bb6536a049
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3984ebc1568c831420e11bd7b3c9004dabcc316b
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43222088"
---
# <a name="cmfcfontinfo-class"></a>Classe CMFCFontInfo
O `CMFCFontInfo` classe descreve o nome e outros atributos de uma fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCFontInfo : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCFontInfo`|Constrói um objeto `CMFCFontInfo`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontInfo::GetFullName](#getfullname)|Recupera os nomes concatenados de uma fonte e seu caractere de conjunto (script).|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontInfo::m_nCharSet](#m_ncharset)|Um valor que especifica o conjunto de caracteres (script) associado com a fonte.|  
|[CMFCFontInfo::m_nPitchAndFamily](#m_npitchandfamily)|Um valor que especifica a densidade e a família da fonte.|  
|[CMFCFontInfo::m_nType](#m_ntype)|Um valor que especifica o tipo da fonte.|  
|[CMFCFontInfo::m_strName](#m_strname)|O nome da fonte. Por exemplo, **Arial**.|  
|[CMFCFontInfo::m_strScript](#m_strscript)|O nome de um conjunto de caracteres (script) associado com a fonte.|  
  
## <a name="remarks"></a>Comentários  
 Você pode anexar um `CMFCFontInfo` objeto a um item do [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) classe. Chame o [CMFCToolBarFontComboBox::GetFontDesc](../../mfc/reference/cmfctoolbarfontcombobox-class.md#getfontdesc) método para recuperar um ponteiro para um `CMFCFontInfo` objeto.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários membros do `CMFCFontInfo` classe. O exemplo demonstra como obter um `CMFCFontInfo` do objeto de um `CMFCRibbonFontComboBox`e como acessar suas variáveis locais. Este exemplo é parte do [amostra de demonstração de 2007 MSOffice](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo#6](../../mfc/reference/codesnippet/cpp/cmfcfontinfo-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
##  <a name="cmfcfontinfo"></a>  CMFCFontInfo::CMFCFontInfo  
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
 [in] *lpszName*  
 O nome da fonte. Para obter mais informações, consulte o `lfFaceName` membro a [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) estrutura.  
  
 [in] *lpszScript*  
 O nome do script (conjunto de caracteres) da fonte.  
  
 [in] *nCharSet*  
 Um valor que especifica o conjunto de caracteres (script) da fonte. Para obter mais informações, consulte o `lfCharSet` membro a [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) estrutura.  
  
 [in] *nPitchAndFamily*  
 Um valor que especifica a densidade e a família da fonte. Para obter mais informações, consulte o `lfPitchAndFamily` membro a [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) estrutura.  
  
 [in] *nType*  
 Um valor que especifica o tipo de fonte. Esse parâmetro pode ser uma combinação bit a bit (OR) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.  
  
 [in] *src*  
 Um existente `CMFCFontInfo` objeto cujos membros são usados para construir este `CMFCFontInfo` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
 Esta documentação usa os termos *conjunto de caracteres* e *script* alternadamente. Um *script*, que é também conhecido como um sistema de escrita, é uma coleção de regras para escrever esses caracteres em um ou mais idiomas e caracteres. A coleção de caracteres inclui o alfabeto e pontuação usados no script. Por exemplo, o script latino é usado para inglês conforme ele é falado nos Estados Unidos, e seu alfabeto inclui os caracteres de À Z. O `lfCharSet` membro a [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) estrutura Especifica um conjunto de caracteres. Por exemplo, o valor ANSI_CHARSET Especifica o conjunto de caracteres ANSI, que inclui o alfabeto de script latino.  
  
##  <a name="getfullname"></a>  CMFCFontInfo::GetFullName  
 Recupera os nomes concatenados de uma fonte e seu caractere de conjunto (script).  
  
```  
CString GetFullName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma cadeia de caracteres que contém o nome da fonte e o script.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para obter o nome completo da fonte. Por exemplo, se for o nome da fonte **Arial** e é o script da fonte **cirílico**, esse método retorna "Arial (cirílico)".  
  
##  <a name="m_ncharset"></a>  CMFCFontInfo::m_nCharSet  
 Um valor que especifica o conjunto de caracteres (script) associado com a fonte.  
  
```  
const BYTE m_nCharSet;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o *nCharSet* parâmetro do [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="m_npitchandfamily"></a>  CMFCFontInfo::m_nPitchAndFamily  
 Um valor que especifica a densidade (tamanho de ponto) e a família (por exemplo, serif, sans-serif e com espaçamento uniforme) da fonte.  
  
```  
const BYTE m_nPitchAndFamily;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o *nPitchAndFamily* parâmetro do [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="m_ntype"></a>  CMFCFontInfo::m_nType  
 Um valor que especifica o tipo da fonte.  
  
```  
const int m_nType;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o *nType* parâmetro do [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="m_strname"></a>  CMFCFontInfo::m_strName  
 O nome da fonte: por exemplo, **Arial**.  
  
```  
const CString m_strName;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o *lpszName* parâmetro do [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
##  <a name="m_strscript"></a>  CMFCFontInfo::m_strScript  
 O nome de um conjunto de caracteres (script) associado com a fonte.  
  
```  
const CString m_strScript;  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte o *lpszScript* parâmetro do [CMFCFontInfo::CMFCFontInfo](#cmfcfontinfo) construtor.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)   
 [Classe CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)
