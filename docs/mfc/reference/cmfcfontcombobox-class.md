---
title: Classe CMFCFontComboBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox::CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox::GetSelFont
- AFXFONTCOMBOBOX/CMFCFontComboBox::SelectFont
- AFXFONTCOMBOBOX/CMFCFontComboBox::Setup
- AFXFONTCOMBOBOX/CMFCFontComboBox::m_bDrawUsingFont
dev_langs:
- C++
helpviewer_keywords:
- CMFCFontComboBox [MFC], CMFCFontComboBox
- CMFCFontComboBox [MFC], GetSelFont
- CMFCFontComboBox [MFC], SelectFont
- CMFCFontComboBox [MFC], Setup
- CMFCFontComboBox [MFC], m_bDrawUsingFont
ms.assetid: 9a53fb0c-7b45-486d-8187-2a4c723d9fbb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0c0f72fd7a359654ffdb32ae0030a82216384207
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43197607"
---
# <a name="cmfcfontcombobox-class"></a>Classe CMFCFontComboBox
O `CMFCFontComboBox` classe cria um controle de caixa de combinação que contém uma lista de fontes.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCFontComboBox : public CComboBox  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontComboBox::CMFCFontComboBox](#cmfcfontcombobox)|Constrói um objeto `CMFCFontComboBox`.|  
|`CMFCFontComboBox::~CMFCFontComboBox`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCFontComboBox::CompareItem`|Chamado pelo framework para determinar a posição relativa de um novo item na caixa de lista classificada de controle de caixa de combinação de fonte atual. (Substitui [CComboBox::CompareItem](../../mfc/reference/ccombobox-class.md#compareitem).)|  
|`CMFCFontComboBox::DrawItem`|Chamado pelo framework para desenhar um item especificado no controle de caixa de combinação de fonte atual. (Substitui [CComboBox::DrawItem](../../mfc/reference/ccombobox-class.md#drawitem).)|  
|[CMFCFontComboBox::GetSelFont](#getselfont)|Recupera informações sobre a fonte atualmente selecionada.|  
|`CMFCFontComboBox::MeasureItem`|Chamado pelo framework para informar ao Windows das dimensões da caixa de listagem no controle de caixa de combinação de fonte atual. (Substitui [CComboBox::MeasureItem](../../mfc/reference/ccombobox-class.md#measureitem).)|  
|`CMFCFontComboBox::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](https://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](https://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|  
|[CMFCFontComboBox::SelectFont](#selectfont)|Seleciona a fonte que corresponde aos critérios especificados na caixa de combinação de fonte.|  
|[CMFCFontComboBox::Setup](#setup)|Inicializa a lista de itens na caixa de combinação de fonte.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCFontComboBox::m_bDrawUsingFont](#m_bdrawusingfont)|Indica o framework qual fonte a ser usado para desenhar os rótulos de itens na caixa de combinação de fonte atual.|  
  
## <a name="remarks"></a>Comentários  
 Para usar um `CMFCFontComboBox` do objeto em uma caixa de diálogo, adicione um `CMFCFontComboBox` variável à classe de caixa de diálogo. Em seguida, nos `OnInitDialog` método da classe de caixa de diálogo, chamada a [CMFCFontComboBox::Setup](#setup) método para inicializar a lista de itens no controle de caixa de combinação.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CComboBox](../../mfc/reference/ccombobox-class.md)  
  
 [CMFCFontComboBox](../../mfc/reference/cmfcfontcombobox-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxfontcombobox.h  
  
##  <a name="cmfcfontcombobox"></a>  CMFCFontComboBox::CMFCFontComboBox  
 Constrói um objeto `CMFCFontComboBox`.  
  
```  
CMFCFontComboBox();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getselfont"></a>  CMFCFontComboBox::GetSelFont  
 Recupera informações sobre a fonte atualmente selecionada.  
  
```  
CMFCFontInfo* GetSelFont() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para [classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md) objeto que descreve uma fonte. Ele pode ser NULL se nenhuma fonte é selecionada na caixa de combinação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_bdrawusingfont"></a>  CMFCFontComboBox::m_bDrawUsingFont  
 Indica o framework qual fonte a ser usado para desenhar os rótulos de itens na caixa de combinação de fonte atual.  
  
```  
static BOOL m_bDrawUsingFont;  
```  
  
### <a name="remarks"></a>Comentários  
 Defina esse membro como TRUE para direcionar a estrutura para usar a mesma fonte para desenhar cada rótulo de item. Defina esse membro como FALSE para direcionar o framework para desenhar cada rótulo de item com a fonte cujo nome é o mesmo que o rótulo. O valor padrão desse membro é FALSE.  
  
##  <a name="selectfont"></a>  CMFCFontComboBox::SelectFont  
 Seleciona a fonte que corresponde aos critérios especificados na caixa de combinação de fonte.  
  
```  
BOOL SelectFont(CMFCFontInfo* pDesc);

 
BOOL SelectFont(
    LPCTSTR lpszName,  
    BYTE nCharSet=DEFAULT_CHARSET);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *apresentado a pDesc*  
 Aponta para um objeto de descrição da fonte.  
  
 [in] *lpszName*  
 Especifica um nome de fonte.  
  
 [in] *nCharSet*  
 Especifica um conjunto de caracteres. O valor padrão é DEFAULT_CHARSET. Para obter mais informações, consulte o `lfCharSet` membro a [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) estrutura.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o objeto de descrição da fonte especificada ou o nome e o conjunto de caracteres; corresponde a um item na caixa de combinação de fonte Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para selecionar e role até o item na caixa de combinação de fonte que corresponde à fonte especificada.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `SelectFont` método no `CMFCFontComboBox` classe. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#35](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_2.cpp)]  
  
##  <a name="setup"></a>  CMFCFontComboBox::Setup  
 Inicializa a lista de itens na caixa de combinação de fonte.  
  
```  
BOOL Setup(
    int nFontType=DEVICE_FONTTYPE|RASTER_FONTTYPE|TRUETYPE_FONTTYPE,  
    BYTE nCharSet=DEFAULT_CHARSET,  
    BYTE nPitchAndFamily=DEFAULT_PITCH);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nFontType*  
 Especifica o tipo de fonte. O valor padrão é a combinação bit a bit (OR) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.  
  
 [in] *nCharSet*  
 Especifica o conjunto de caracteres da fonte. O valor padrão é DEFAULT_CHARSET.  
  
 [in] *nPitchAndFamily*  
 Especifica a densidade de fonte e a família. O valor padrão é DEFAULT_PITCH.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a caixa de combinação de fonte foi inicializada com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Esse método inicializa a caixa de combinação de fonte enumerando as fontes atualmente instaladas que correspondem aos parâmetros especificados e inserindo os nomes de fonte na caixa de combinação de fonte.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar o `Setup` método no `CMFCFontComboBox` classe. Este exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#36](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)   
 [Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)
