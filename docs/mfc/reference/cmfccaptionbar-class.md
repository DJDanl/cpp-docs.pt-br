---
title: Classe CMFCCaptionBar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCCaptionBar
- AFXCAPTIONBAR/CMFCCaptionBar
- AFXCAPTIONBAR/CMFCCaptionBar::Create
- AFXCAPTIONBAR/CMFCCaptionBar::DoesAllowDynInsertBefore
- AFXCAPTIONBAR/CMFCCaptionBar::EnableButton
- AFXCAPTIONBAR/CMFCCaptionBar::GetAlignment
- AFXCAPTIONBAR/CMFCCaptionBar::GetBorderSize
- AFXCAPTIONBAR/CMFCCaptionBar::GetButtonRect
- AFXCAPTIONBAR/CMFCCaptionBar::GetMargin
- AFXCAPTIONBAR/CMFCCaptionBar::IsMessageBarMode
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveBitmap
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveButton
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveIcon
- AFXCAPTIONBAR/CMFCCaptionBar::RemoveText
- AFXCAPTIONBAR/CMFCCaptionBar::SetBitmap
- AFXCAPTIONBAR/CMFCCaptionBar::SetBorderSize
- AFXCAPTIONBAR/CMFCCaptionBar::SetButton
- AFXCAPTIONBAR/CMFCCaptionBar::SetButtonPressed
- AFXCAPTIONBAR/CMFCCaptionBar::SetButtonToolTip
- AFXCAPTIONBAR/CMFCCaptionBar::SetFlatBorder
- AFXCAPTIONBAR/CMFCCaptionBar::SetIcon
- AFXCAPTIONBAR/CMFCCaptionBar::SetImageToolTip
- AFXCAPTIONBAR/CMFCCaptionBar::SetMargin
- AFXCAPTIONBAR/CMFCCaptionBar::SetText
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawBackground
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawBorder
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawButton
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawImage
- AFXCAPTIONBAR/CMFCCaptionBar::OnDrawText
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarBackground
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarBorder
- AFXCAPTIONBAR/CMFCCaptionBar::m_clrBarText
dev_langs: C++
helpviewer_keywords:
- CMFCCaptionBar [MFC], Create
- CMFCCaptionBar [MFC], DoesAllowDynInsertBefore
- CMFCCaptionBar [MFC], EnableButton
- CMFCCaptionBar [MFC], GetAlignment
- CMFCCaptionBar [MFC], GetBorderSize
- CMFCCaptionBar [MFC], GetButtonRect
- CMFCCaptionBar [MFC], GetMargin
- CMFCCaptionBar [MFC], IsMessageBarMode
- CMFCCaptionBar [MFC], RemoveBitmap
- CMFCCaptionBar [MFC], RemoveButton
- CMFCCaptionBar [MFC], RemoveIcon
- CMFCCaptionBar [MFC], RemoveText
- CMFCCaptionBar [MFC], SetBitmap
- CMFCCaptionBar [MFC], SetBorderSize
- CMFCCaptionBar [MFC], SetButton
- CMFCCaptionBar [MFC], SetButtonPressed
- CMFCCaptionBar [MFC], SetButtonToolTip
- CMFCCaptionBar [MFC], SetFlatBorder
- CMFCCaptionBar [MFC], SetIcon
- CMFCCaptionBar [MFC], SetImageToolTip
- CMFCCaptionBar [MFC], SetMargin
- CMFCCaptionBar [MFC], SetText
- CMFCCaptionBar [MFC], OnDrawBackground
- CMFCCaptionBar [MFC], OnDrawBorder
- CMFCCaptionBar [MFC], OnDrawButton
- CMFCCaptionBar [MFC], OnDrawImage
- CMFCCaptionBar [MFC], OnDrawText
- CMFCCaptionBar [MFC], m_clrBarBackground
- CMFCCaptionBar [MFC], m_clrBarBorder
- CMFCCaptionBar [MFC], m_clrBarText
ms.assetid: acb54d5f-14ff-4c96-aeb3-7717cf566d9a
caps.latest.revision: "28"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9c23129c1ac857e812b0da837b19322741087934
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfccaptionbar-class"></a>Classe CMFCCaptionBar
Um `CMFCCaptionBar` objeto é uma barra de controle que pode exibir três elementos: um bitmap, um rótulo de texto e um botão. Ele só pode exibir um elemento de cada tipo de cada vez. Você pode alinhar cada elemento para as bordas esquerdas ou direita do controle ou no centro. Você também pode aplicar um estilo 3D ou simples para as bordas superior e inferior da barra de legenda.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCCaptionBar : public CPane  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCCaptionBar::Create](#create)|Cria o controle de barra de legenda e anexa-o para o `CMFCCaptionBar` objeto.|  
|[CMFCCaptionBar::DoesAllowDynInsertBefore](#doesallowdyninsertbefore)|Indica se outro painel pode ser inserido dinamicamente entre a barra de legenda e seu quadro pai. (Substitui [CBasePane::DoesAllowDynInsertBefore](../../mfc/reference/cbasepane-class.md#doesallowdyninsertbefore).)|  
|[CMFCCaptionBar::EnableButton](#enablebutton)|Habilita ou desabilita o botão na barra de legenda.|  
|[CMFCCaptionBar::GetAlignment](#getalignment)|Retorna o alinhamento do elemento especificado.|  
|[CMFCCaptionBar::GetBorderSize](#getbordersize)|Retorna o tamanho da borda da barra de legenda.|  
|[CMFCCaptionBar::GetButtonRect](#getbuttonrect)|Recupera o retângulo delimitador do botão na barra de legenda.|  
|[CMFCCaptionBar::GetMargin](#getmargin)|Retorna a distância entre a borda dos elementos da barra de legenda e a borda do controle da barra de legenda.|  
|[CMFCCaptionBar::IsMessageBarMode](#ismessagebarmode)|Especifica se a barra de legenda está no modo de barra de mensagem.|  
|[CMFCCaptionBar::RemoveBitmap](#removebitmap)|Remove a imagem de bitmap na barra de legenda.|  
|[CMFCCaptionBar::RemoveButton](#removebutton)|Remove o botão da barra de legenda.|  
|[CMFCCaptionBar::RemoveIcon](#removeicon)|Remove o ícone da barra de legenda.|  
|[CMFCCaptionBar::RemoveText](#removetext)|Remove o rótulo de texto na barra de legenda.|  
|[CMFCCaptionBar::SetBitmap](#setbitmap)|Define a imagem de bitmap para a barra de legenda.|  
|[CMFCCaptionBar::SetBorderSize](#setbordersize)|Define o tamanho da borda da barra de legenda.|  
|[CMFCCaptionBar::SetButton](#setbutton)|Define o botão na barra de legenda.|  
|[CMFCCaptionBar::SetButtonPressed](#setbuttonpressed)|Especifica se o botão permanece pressionado.|  
|[CMFCCaptionBar::SetButtonToolTip](#setbuttontooltip)|Define a dica de ferramenta do botão.|  
|[CMFCCaptionBar::SetFlatBorder](#setflatborder)|Define o estilo de borda da barra de legenda.|  
|[CMFCCaptionBar::SetIcon](#seticon)|Define o ícone de uma barra de legenda.|  
|[CMFCCaptionBar::SetImageToolTip](#setimagetooltip)|Define a dica de ferramenta da imagem para a barra de legenda.|  
|[CMFCCaptionBar::SetMargin](#setmargin)|Define a distância entre a borda do elemento de barra de legenda e a borda do controle da barra de legenda.|  
|[CMFCCaptionBar::SetText](#settext)|Define o rótulo de texto para a barra de legenda.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCCaptionBar::OnDrawBackground](#ondrawbackground)|Chamado pelo framework para preencher o plano de fundo da barra de legenda.|  
|[CMFCCaptionBar::OnDrawBorder](#ondrawborder)|Chamado pelo framework para desenhar a borda da barra de legenda.|  
|[CMFCCaptionBar::OnDrawButton](#ondrawbutton)|Chamado pelo framework para desenhar o botão da barra de legenda.|  
|[CMFCCaptionBar::OnDrawImage](#ondrawimage)|Chamado pelo framework para desenhar a imagem da barra de legenda.|  
|[CMFCCaptionBar::OnDrawText](#ondrawtext)|Chamado pelo framework para desenhar o texto da barra de legenda.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCCaptionBar::m_clrBarBackground](#m_clrbarbackground)|A cor de plano de fundo da barra de legenda.|  
|[CMFCCaptionBar::m_clrBarBorder](#m_clrbarborder)|A cor da borda da barra de legenda.|  
|[CMFCCaptionBar::m_clrBarText](#m_clrbartext)|A cor do texto da barra de legenda.|  
  
## <a name="remarks"></a>Comentários  
 Para criar uma barra de legenda, siga estas etapas:  
  
1.  Construir o `CMFCCaptionBar` objeto. Normalmente, você adicionaria a barra de legenda para uma classe de janela do quadro.  
  
2.  Chamar o [CMFCCaptionBar::Create](#create) método para criar o controle de barra de legenda e anexá-lo para o `CMFCCaptionBar` objeto.  
  
3.  Chamar [CMFCCaptionBar::SetButton](#setbutton), [CMFCCaptionBar::SetText](#settext), [CMFCCaptionBar::SetIcon](#seticon), e [CMFCCaptionBar::SetBitmap](#setbitmap)para definir os elementos da barra de legenda.  
  
 Quando você define o elemento button, você deve atribuir uma ID de comando para o botão. Quando o usuário clica no botão, as rotas de barra de legenda a `WM_COMMAND` mensagens com essa ID para a janela do quadro pai.  
  
 Na barra de legenda também pode trabalhar no modo de barra de mensagem, que emula a barra de mensagem que aparece em aplicativos do Microsoft Office 2007. No modo de barra de mensagem, a barra de legenda exibe um bitmap, uma mensagem e um botão (que normalmente abre uma caixa de diálogo). Você pode atribuir uma dica de ferramenta para o bitmap.  
  
 Para habilitar o modo de barra de mensagem, chame [CMFCCaptionBar::Create](#create) e defina o quarto parâmetro (bIsMessageBarMode) para `TRUE`.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários métodos no `CMFCCaptionBar` classe. O exemplo mostra como criar o controle de barra de legenda, defina uma borda 3D da barra de legenda, defina a distância, em pixels, entre a borda da legenda barra elementos e a borda do controle da barra de legenda, definir o botão da barra de legenda , definir a dica de ferramenta do botão, o rótulo de texto para a barra de legenda, definir a imagem de bitmap para a barra de legenda e a dica de ferramenta para a imagem na barra de legenda. Este trecho de código é parte do [exemplo de demonstração do MS Office 2007](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo#1](../../mfc/reference/codesnippet/cpp/cmfccaptionbar-class_1.h)]  
[!code-cpp[NVC_MFC_MSOffice2007Demo#2](../../mfc/reference/codesnippet/cpp/cmfccaptionbar-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CBasePane](../../mfc/reference/cbasepane-class.md)  
  
 [CPane](../../mfc/reference/cpane-class.md)  
  
 [CMFCCaptionBar](../../mfc/reference/cmfccaptionbar-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcaptionbar.h  
  
##  <a name="create"></a>CMFCCaptionBar::Create  
 Cria o controle de barra de legenda e anexa-o para o `CMFCCaptionBar` objeto.  
  
```  
BOOL Create(
    DWORD dwStyle,  
    CWnd* pParentWnd,  
    UINT uID,  
    int nHeight=-1,  
    BOOL bIsMessageBarMode=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 A lógica ou combinação de estilos de barra de legenda.  
  
 `pParentWnd`  
 A janela pai do controle de barra de legenda.  
  
 `uID`  
 A ID do controle de barra de legenda.  
  
 `nHeight`  
 A altura, em pixels, do controle de barra de legenda. Se for -1, a altura é calculada de acordo com a altura do ícone, o texto e o botão que exibe o controle de barra de legenda.  
  
 `bIsMessageBarMode`  
 `TRUE`Se a barra de legenda estiver no modo de barra de mensagem; `FALSE` caso contrário.  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se o controle de barra de legenda é criado com êxito; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CMFCCaptionBar` objeto em duas etapas. Primeiro você chamar o construtor e, em seguida, você chama o `Create` método, que cria o controle do Windows e a anexa ao `CMFCCaptionBar` objeto.  
  
##  <a name="doesallowdyninsertbefore"></a>CMFCCaptionBar::DoesAllowDynInsertBefore  
 Indica se outro painel pode ser inserido dinamicamente entre a barra de legenda e seu quadro pai.  
  
```  
virtual BOOL DoesAllowDynInsertBefore() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna `FALSE` a menos que substituída.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="enablebutton"></a>CMFCCaptionBar::EnableButton  
 Habilita ou desabilita o botão na barra de legenda.  
  
```  
void EnableButton(BOOL bEnable=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bEnable`  
 `TRUE`Para habilitar o botão `FALSE` para desabilitar o botão.  
  
##  <a name="getalignment"></a>CMFCCaptionBar::GetAlignment  
 Retorna o alinhamento do elemento especificado.  
  
```  
BarElementAlignment GetAlignment(BarElement elem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `elem`  
 Um elemento de barra de legenda para o qual recuperar o alinhamento.  
  
### <a name="return-value"></a>Valor de retorno  
 O alinhamento de um elemento, como um botão, um bitmap, texto ou um ícone.  
  
### <a name="remarks"></a>Comentários  
 O alinhamento do elemento pode ser um dos seguintes valores:  
  
-   ALIGN_INVALID  
  
-   ALIGN_LEFT  
  
-   ALIGN_RIGHT  
  
-   ALIGN_CENTER  
  
##  <a name="getbordersize"></a>CMFCCaptionBar::GetBorderSize  
 Retorna o tamanho da borda da barra de legenda.  
  
```  
int GetBorderSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho, em pixels, da borda.  
  
##  <a name="getbuttonrect"></a>CMFCCaptionBar::GetButtonRect  
 Recupera o retângulo delimitador do botão na barra de legenda.  
  
```  
CRect GetButtonRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CRect` objeto que contém as coordenadas do retângulo delimitador do botão na barra de legenda.  
  
##  <a name="getmargin"></a>CMFCCaptionBar::GetMargin  
 Retorna a distância entre a borda dos elementos da barra de legenda e a borda do controle da barra de legenda.  
  
```  
int GetMargin() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A distância em pixels entre a borda dos elementos da barra de legenda e a borda do controle da barra de legenda.  
  
##  <a name="ismessagebarmode"></a>CMFCCaptionBar::IsMessageBarMode  
 Especifica se a barra de legenda está no modo de barra de mensagem.  
  
```  
BOOL IsMessageBarMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a barra de legenda estiver no modo de barra de mensagem; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 No modo de barra de mensagem, a barra de legenda exibe uma imagem com uma dica de ferramenta, o texto da mensagem e um botão.  
  
##  <a name="m_clrbarbackground"></a>CMFCCaptionBar::m_clrBarBackground  
 A cor de plano de fundo da barra de legenda.  
  
```  
COLORREF m_clrBarBackground  
```  
  
##  <a name="m_clrbarborder"></a>CMFCCaptionBar::m_clrBarBorder  
 A cor da borda da barra de legenda.  
  
```  
COLORREF m_clrBarBorder  
```  
  
##  <a name="m_clrbartext"></a>CMFCCaptionBar::m_clrBarText  
 A cor do texto da barra de legenda.  
  
```  
COLORREF m_clrBarText  
```  
  
##  <a name="ondrawbackground"></a>CMFCCaptionBar::OnDrawBackground  
 Chamado pelo framework para preencher o plano de fundo da barra de legenda.  
  
```  
virtual void OnDrawBackground(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para o contexto de dispositivo da barra de legenda.  
  
 [in] `rect`  
 O retângulo delimitador para preencher.  
  
### <a name="remarks"></a>Comentários  
 O `OnDrawBackground` método é chamado quando o plano de fundo da barra de legenda está prestes a ser preenchido. A implementação padrão preenche o plano de fundo usando o [CMFCCaptionBar::m_clrBarBackground](#m_clrbarbackground) cores.  
  
 Substitua este método em um `CMFCCaptionBar` derivado da classe para personalizar a aparência da barra de legenda.  
  
##  <a name="ondrawborder"></a>CMFCCaptionBar::OnDrawBorder  
 Chamado pelo framework para desenhar a borda da barra de legenda.  
  
```  
virtual void OnDrawBorder(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um contexto de dispositivo que é usado para exibir as bordas.  
  
 [in] `rect`  
 O retângulo delimitador.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, as bordas têm o estilo simples.  
  
 Substitua este método em um `CMFCCaptionBar` derivado da classe para personalizar a aparência das bordas da barra de legenda.  
  
##  <a name="ondrawbutton"></a>CMFCCaptionBar::OnDrawButton  
 Chamado pelo framework para desenhar o botão da barra de legenda.  
  
```  
virtual void OnDrawButton(
    CDC* pDC,  
    CRect rect,  
    const CString& strButton,  
    BOOL bEnabled);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo que é usado para exibir o botão.  
  
 [in] `rect`  
 O retângulo delimitador do botão.  
  
 [in] `strButton`  
 Rótulo de texto do botão.  
  
 [in] `bEnabled`  
 `TRUE`Se o botão estiver habilitado; `FALSE` caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em um `CMFCCaptionBar` derivado da classe para personalizar a aparência do botão da barra de legenda.  
  
##  <a name="ondrawimage"></a>CMFCCaptionBar::OnDrawImage  
 Chamado pelo framework para desenhar a imagem da barra de legenda.  
  
```  
virtual void OnDrawImage(
    CDC* pDC,  
    CRect rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo que é usado para exibir a imagem.  
  
 [in] `rect`  
 Especifica o retângulo delimitador da imagem.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em um `CMFCCaptionBar` derivado da classe para personalizar a aparência da imagem.  
  
##  <a name="ondrawtext"></a>CMFCCaptionBar::OnDrawText  
 Chamado pelo framework para desenhar o texto da barra de legenda.  
  
```  
virtual void OnDrawText(
    CDC* pDC,  
    CRect rect,  
    const CString& strText);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Um ponteiro para um contexto de dispositivo que é usado para exibir o botão.  
  
 [in] `rect`  
 O retângulo delimitador do texto.  
  
 [in] `strText`  
 A cadeia de caracteres de texto para exibir.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão exibe o texto usando `CDC::DrawText` e [CMFCCaptionBar::m_clrBarText](#m_clrbartext) cores.  
  
 Substitua este método em um `CMFCCaptionBar` derivado da classe para personalizar a aparência do texto da barra de legenda.  
  
##  <a name="removebitmap"></a>CMFCCaptionBar::RemoveBitmap  
 Remove a imagem de bitmap na barra de legenda.  
  
```  
void RemoveBitmap();
```  
  
##  <a name="removebutton"></a>CMFCCaptionBar::RemoveButton  
 Remove o botão da barra de legenda.  
  
```  
void RemoveButton();
```  
  
### <a name="remarks"></a>Comentários  
 O layout dos elementos da barra de legenda são ajustados automaticamente.  
  
##  <a name="removeicon"></a>CMFCCaptionBar::RemoveIcon  
 Remove o ícone da barra de legenda.  
  
```  
void RemoveIcon();
```  
  
##  <a name="removetext"></a>CMFCCaptionBar::RemoveText  
 Remove o rótulo de texto na barra de legenda.  
  
```  
void RemoveText();
```  
  
##  <a name="setbitmap"></a>CMFCCaptionBar::SetBitmap  
 Define a imagem de bitmap para a barra de legenda.  
  
```  
void SetBitmap(
    HBITMAP hBitmap,  
    COLORREF clrTransparent,  
    BOOL bStretch=FALSE,  
    BarElementAlignment bmpAlignment=ALIGN_RIGHT);

 
void SetBitmap(
    UINT uiBmpResID,  
    COLORREF clrTransparent,  
    BOOL bStretch=FALSE,  
    BarElementAlignment bmpAlignment=ALIGN_RIGHT);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hBitmap`  
 O identificador para o bitmap a ser definido.  
  
 [in] `clrTransparent`  
 Um valor RGB que especifica a cor transparente do bitmap.  
  
 [in] `bStretch`  
 Se `TRUE`, o bitmap é ampliado se ele não se ajustar à imagem delimitadora retângulo. Caso contrário, o bitmap não é estendido.  
  
 [in] `bmpAlignment`  
 O alinhamento do bitmap.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para definir um bitmap em uma barra de legenda.  
  
 O bitmap de anterior é destruído automaticamente. Se a barra de legenda exibe um ícone que você chamou o [CMFCCaptionBar::SetIcon](#seticon) método, o bitmap não será exibido a menos que você remova o ícone chamando [CMFCCaptionBar::RemoveIcon](#removeicon).  
  
 O bitmap é alinhado conforme especificado pelo `bmpAlignment` parâmetro.  Esse parâmetro pode ser um dos seguintes `BarElementAlignment` valores:  
  
-   ALIGN_INVALID  
  
-   ALIGN_LEFT  
  
-   ALIGN_RIGHT  
  
-   ALIGN_CENTER  
  
##  <a name="setbordersize"></a>CMFCCaptionBar::SetBorderSize  
 Define o tamanho da borda da barra de legenda.  
  
```  
void SetBorderSize(int nSize);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nSize`  
 O novo tamanho, em pixels, da borda da barra de legenda.  
  
##  <a name="setbutton"></a>CMFCCaptionBar::SetButton  
 Define o botão na barra de legenda.  
  
```  
void SetButton(
    LPCTSTR lpszLabel,  
    UINT uiCmdUI,  
    BarElementAlignment btnAlignmnet=ALIGN_LEFT,  
    BOOL bHasDropDownArrow=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszLabel`  
 O rótulo do botão comando.  
  
 `uiCmdUI`  
 ID de comando. do botão  
  
 `btnAlignmnet`  
 Alinhamento do botão.  
  
 `bHasDropDownArrow`  
 `TRUE`Se o botão exibe uma seta do menu suspenso, `FALSE` caso contrário.  
  
##  <a name="setbuttonpressed"></a>CMFCCaptionBar::SetButtonPressed  
 Especifica se o botão permanece pressionado.  
  
```  
void SetButtonPressed(BOOL bPresed=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bPresed`  
 `TRUE`Se o botão mantém seu estado pressionado, `FALSE` caso contrário.  
  
##  <a name="setbuttontooltip"></a>CMFCCaptionBar::SetButtonToolTip  
 Define a dica de ferramenta do botão.  
  
```  
void SetButtonToolTip(
    LPCTSTR lpszToolTip,  
    LPCTSTR lpszDescription=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszToolTip`  
 A legenda de dica de ferramenta.  
  
 [in] `lpszDescription`  
 A descrição de dica de ferramenta.  
  
##  <a name="setflatborder"></a>CMFCCaptionBar::SetFlatBorder  
 Define o estilo de borda da barra de legenda.  
  
```  
void SetFlatBorder(BOOL bFlat=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bFlat`  
 `TRUE`Se a borda de uma barra de legenda é simples. `FALSE`Se a borda 3D.  
  
##  <a name="seticon"></a>CMFCCaptionBar::SetIcon  
 Define o ícone de uma barra de legenda.  
  
```  
void SetIcon(
    HICON hIcon,  
    BarElementAlignment iconAlignment=ALIGN_RIGHT);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hIcon`  
 O identificador para o ícone a ser definido.  
  
 [in] `iconAlignment`  
 O alinhamento do ícone.  
  
### <a name="remarks"></a>Comentários  
 Barras de legenda podem exibir ícones ou bitmaps. Consulte [CMFCCaptionBar::SetBitmap](#setbitmap) para descobrir como exibir um bitmap. Se você definir um ícone e bitmap, o ícone é exibido sempre. Chamar [CMFCCaptionBar::RemoveIcon](#removeicon) para remover um ícone na barra de legenda.  
  
 O ícone é alinhado com o `iconAlignment` parâmetro. Ele pode ser um dos seguintes `BarElementAlignment` valores:  
  
-   ALIGN_INVALID  
  
-   ALIGN_LEFT  
  
-   ALIGN_RIGHT  
  
-   ALIGN_CENTER  
  
##  <a name="setimagetooltip"></a>CMFCCaptionBar::SetImageToolTip  
 Define a dica de ferramenta para a imagem da barra de legenda.  
  
```  
void SetImageToolTip(
    LPCTSTR lpszToolTip,  
    LPCTSTR lpszDescription=NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `lpszToolTip`  
 O texto da dica de ferramenta.  
  
 [in] `lpszDescription`  
 A descrição de dica de ferramenta.  
  
##  <a name="setmargin"></a>CMFCCaptionBar::SetMargin  
 Define a distância entre a borda do elemento de barra de legenda e a borda do controle da barra de legenda.  
  
```  
void SetMargin(int nMargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nMargin`  
 A distância em pixels entre a borda dos elementos da barra de legenda e a borda do controle da barra de legenda.  
  
##  <a name="settext"></a>CMFCCaptionBar::SetText  
 Define o rótulo de texto para a barra de legenda.  
  
```  
void SetText(
    const CString& strText,  
    BarElementAlignment textAlignment=ALIGN_RIGHT);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `strText`  
 A cadeia de caracteres de texto para definir.  
  
 [in] `textAlignment`  
 O alinhamento do texto.  
  
### <a name="remarks"></a>Comentários  
 O rótulo de texto é alinhado conforme especificado pelo `textAlignment` parâmetro. Ele pode ser um dos seguintes `BarElementAlignment` valores:  
  
-   ALIGN_INVALID  
  
-   ALIGN_LEFT  
  
-   ALIGN_RIGHT  
  
-   ALIGN_CENTER  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)
