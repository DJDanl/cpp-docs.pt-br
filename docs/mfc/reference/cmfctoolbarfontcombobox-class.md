---
title: Classe CMFCToolBarFontComboBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::GetFontDesc
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::SetFont
dev_langs:
- C++
helpviewer_keywords:
- CMFCToolBarFontComboBox [MFC], CMFCToolBarFontComboBox
- CMFCToolBarFontComboBox [MFC], GetFontDesc
- CMFCToolBarFontComboBox [MFC], SetFont
ms.assetid: 25f8e08c-aadd-4cb5-9581-a99d49d444b1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ea8f05c20c3a3276f51b4267b6763831dc23eacf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33373521"
---
# <a name="cmfctoolbarfontcombobox-class"></a>Classe CMFCToolBarFontComboBox
Um botão de barra de ferramentas que contém um controle de caixa de combinação que permite que o usuário selecione uma fonte de uma lista de fontes do sistema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCToolBarFontComboBox : public CMFCToolBarComboBoxButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarFontComboBox::CMFCToolBarFontComboBox](#cmfctoolbarfontcombobox)|Constrói um objeto `CMFCToolBarFontComboBox`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCToolBarFontComboBox::GetFontDesc](#getfontdesc)|Retorna um ponteiro para o `CMFCFontInfo` objeto para um índice especificado na caixa de combinação.|  
|[CMFCToolBarFontComboBox::SetFont](#setfont)|Seleciona uma fonte na caixa de combinação de fonte de acordo com o nome da fonte ou o prefixo e conjunto de caracteres da fonte.|  
  
### <a name="data-members"></a>Membros de Dados  
 [CMFCToolBarFontComboBox::m_nFontHeight](#m_nfontheight)  
 A altura dos caracteres na caixa de combinação de fonte.  
  
## <a name="remarks"></a>Comentários  
 Para adicionar um botão de caixa de combinação de fonte para uma barra de ferramentas, siga estas etapas:  
  
1.  Reserve uma ID de recurso fictício do botão no recurso pai da barra de ferramentas.  
  
2.  Construir um `CMFCToolBarFontComboBox` objeto.  
  
3.  No manipulador de mensagens que processa o `AFX_WM_RESETTOOLBAR` mensagem, substitua o botão original pelo novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).  
  
4.  Sincronizar a fonte selecionada na caixa de combinação com a fonte do documento usando o [CMFCToolBarFontComboBox::SetFont](#setfont) método.  
  
 Para sincronizar a fonte do documento com a fonte selecionada na caixa de combinação, use o [CMFCToolBarFontComboBox::GetFontDesc](#getfontdesc) método para recuperar os atributos da fonte selecionada e use esses atributos para criar um [ Classe CFont](../../mfc/reference/cfont-class.md) objeto.  
  
 O botão de caixa de combinação de fonte chama a função Win32 [EnumFontFamiliesEx](http://msdn.microsoft.com/library/windows/desktop/dd162620) para determinar as fontes de tela e impressora disponíveis para o sistema.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)  
  
 [CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)  
  
 [CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxtoolbarfontcombobox.h  
  
##  <a name="cmfctoolbarfontcombobox"></a>  CMFCToolBarFontComboBox::CMFCToolBarFontComboBox  
 Constrói um [CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) objeto.  
  
```  
public:  
CMFCToolBarFontComboBox(
    UINT uiID,  
    int iImage,  
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,  
    BYTE nCharSet = DEFAULT_CHARSET,  
    DWORD dwStyle = CBS_DROPDOWN,  
    int iWidth = 0,  
    BYTE nPitchAndFamily = DEFAULT_PITCH);

 
protected:  
CMFCToolBarFontComboBox(
    CObList* pLstFontsExternal,  
    int nFontType,  
    BYTE nCharSet,  
    BYTE nPitchAndFamily);  
  
CMFCToolBarFontComboBox();
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiID`  
 A ID de comando da caixa de combinação.  
  
 [in] `iImage`  
 O índice de base zero de uma imagem da barra de ferramentas. A imagem está localizada no [CMFCToolBarImages classe](../../mfc/reference/cmfctoolbarimages-class.md) o objeto [CMFCToolBar classe](../../mfc/reference/cmfctoolbar-class.md) classe mantém.  
  
 [in] `nFontType`  
 Os tipos de fontes que contém a caixa de combinação. Esse parâmetro pode ser uma combinação (booliano OR) dos valores a seguir:  
  
 DEVICE_FONTTYPE  
  
 RASTER_FONTTYPE  
  
 TRUETYPE_FONTTYPE  
  
 [in] `nCharSet`  
 Se definido como DEFAULT_CHARSET, a caixa de combinação contém todos os exclusivamente nomeada fontes em todos os conjuntos de caracteres. (Se houver duas fontes com o mesmo nome, a caixa de combinação contém um deles.) Se definido como um valor de conjunto de caracteres válida, a caixa de combinação contém apenas as fontes no conjunto de caracteres especificado. Consulte [LOGFONT](http://msdn.microsoft.com/library/windows/desktop/dd145037) define uma lista de caracteres possíveis.  
  
 [in] `dwStyle`  
 O estilo da caixa de combinação. (consulte [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles))  
  
 [in] `iWidth`  
 A largura em pixels do controle de edição.  
  
 [in] `nPitchAndFamily`  
 Se definido como DEFAULT_PITCH, a caixa de combinação contém fontes, independentemente da distância. Se definido como FIXED_PITCH ou VARIABLE_PITCH, a caixa de combinação contém apenas as fontes com o tipo tom. Atualmente não há suporte para a filtragem com base na família de fontes.  
  
 [out] `pLstFontsExternal`  
 Ponteiro para um [CObList classe](../../mfc/reference/coblist-class.md) objeto que armazena as fontes disponíveis.  
  
### <a name="remarks"></a>Comentários  
 Normalmente, `CMFCToolBarFontComboBox` objetos armazenam a lista de fontes disponíveis em um único compartilhado `CObList` objeto. Se você usar a segunda sobrecarga do construtor e fornecer um ponteiro válido para `pLstFontsExternal`, que `CMFCToolBarFontComboBox` objeto preencherá em vez disso, o `CObList` que `pLstFontsExternal` aponta para com fontes disponíveis.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCToolBarFontComboBox` objeto. Este trecho de código é parte do [exemplo Word Pad](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_WordPad#7](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontcombobox-class_1.cpp)]  
  
##  <a name="getfontdesc"></a>  CMFCToolBarFontComboBox::GetFontDesc  
 Retorna um ponteiro para o `CMFCFontInfo` objeto para um índice especificado na caixa de combinação.  
  
```  
const CMFCFontInfo* GetFontDesc(int iIndex=-1) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `iIndex`  
 Especifica o índice de base zero de um item de caixa de combinação.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `CMFCFontInfo` objeto. Se `iIndex` não especifica um índice de item válido, o valor de retorno é `NULL`.  
  
##  <a name="m_nfontheight"></a>  CMFCToolBarFontComboBox::m_nFontHeight  
 Especifica a altura, em pixels, dos caracteres na caixa de combinação de fonte se a caixa de combinação tem proprietário desenhar estilo.  
  
```  
static int m_nFontHeight  
```  
  
### <a name="remarks"></a>Comentários  
 Se o `m_nFontHeight` variável for 0, a altura é calculada automaticamente de acordo com a fonte padrão da caixa de combinação. A altura inclui tanto o ascendente de caracteres acima da linha de base e descendente de caracteres abaixo da linha de base.  
  
##  <a name="setfont"></a>  CMFCToolBarFontComboBox::SetFont  
 Seleciona que a fonte na caixa de combinação de fonte acordo com o nome da fonte e o caractere definida que é especificadas nos parâmetros.  
  
```  
BOOL SetFont(
    LPCTSTR lpszName,  
    BYTE nCharSet=DEFAULT_CHARSET,  
    BOOL bExact=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszName`  
 Especifica o nome da fonte ou o prefixo.  
  
 [in] `nCharSet`  
 Especifica o conjunto de caracteres.  
  
 [in] `bExact`  
 Especifica se `lpszName` contém o nome da fonte ou o prefixo de fonte.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a fonte foi marcada com êxito; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `bExact` é `TRUE`, esse método seleciona uma fonte que corresponda exatamente ao nome que você especificou como `lpszName`. Se `bExact` é `FALSE`, esse método seleciona uma fonte que começa com o texto especificado como `lpszName` e que usa o conjunto de caracteres que você especificou como `nCharSet`. Se `nCharSet` está definido para DEFAULT_CHARSET, o conjunto de caracteres será ignorado e somente `lpszName` será usado para selecionar uma fonte.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)   
 [Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)   
 [Classe CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)   
 [Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)   
 [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)   
 [Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)



