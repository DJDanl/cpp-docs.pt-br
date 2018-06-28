---
title: Classe CMFCCaptionButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::CMFCCaptionButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetHit
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetIconID
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetRect
- AFXCAPTIONBUTTON/CMFCCaptionButton::GetSize
- AFXCAPTIONBUTTON/CMFCCaptionButton::IsMiniFrameButton
- AFXCAPTIONBUTTON/CMFCCaptionButton::Move
- AFXCAPTIONBUTTON/CMFCCaptionButton::OnDraw
- AFXCAPTIONBUTTON/CMFCCaptionButton::SetMiniFrameButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCCaptionButton [MFC], CMFCCaptionButton
- CMFCCaptionButton [MFC], GetHit
- CMFCCaptionButton [MFC], GetIconID
- CMFCCaptionButton [MFC], GetRect
- CMFCCaptionButton [MFC], GetSize
- CMFCCaptionButton [MFC], IsMiniFrameButton
- CMFCCaptionButton [MFC], Move
- CMFCCaptionButton [MFC], OnDraw
- CMFCCaptionButton [MFC], SetMiniFrameButton
ms.assetid: c5774b38-c0dd-414a-9ede-3b2f78f233ec
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: df36f8a6af5d8ad7e2a96780e02f236e3225333d
ms.sourcegitcommit: f1b051abb1de3fe96350be0563aaf4e960da13c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/27/2018
ms.locfileid: "37040623"
---
# <a name="cmfccaptionbutton-class"></a>Classe CMFCCaptionButton
O `CMFCCaptionButton` classe implementa um botão que é exibido na barra de legenda para um painel ou uma janela do quadro simplificado. Normalmente, o framework cria automaticamente botões de legenda.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCCaptionButton : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="constructors"></a>Construtores  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCCaptionButton::CMFCCaptionButton](#cmfccaptionbutton)|Constrói um objeto CMFCCaptionButton.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCCaptionButton::GetHit](#gethit)|Retorna o comando representado pelo botão.|  
|[CMFCCaptionButton::GetIconID](#geticonid)|Retorna a ID de imagem associada ao botão.|  
|[CMFCCaptionButton::GetRect](#getrect)|Retorna o retângulo ocupado pelo botão.|  
|[CMFCCaptionButton::GetSize](#getsize)|Retorna a largura e altura do botão.|  
|[CMFCCaptionButton::IsMiniFrameButton](#isminiframebutton)|Indica se a altura da barra de título está definida como tamanho mini.|  
|[CMFCCaptionButton::Move](#move)|Define o local de desenho do botão e Mostrar estado da janela.|  
|[CMFCCaptionButton::OnDraw](#ondraw)|Desenha o botão de legenda.|  
|[CMFCCaptionButton::SetMiniFrameButton](#setminiframebutton)|Define o tamanho mini da barra de título.|  
  
## <a name="remarks"></a>Comentários  
 Você pode derivar uma classe de [CPaneFrameWnd classe](../../mfc/reference/cpaneframewnd-class.md) e usar o método protegido, `AddButton`, para adicionar botões de legenda para uma janela do quadro mini.  
  
 CPaneFrameWnd.h define as IDs de comando para dois tipos de botões de legenda:  
  
- `AFX_CAPTION_BTN_PIN`, que exibe um botão de pin quando o painel de encaixe dá suporte ao modo de ocultar automaticamente.  
  
- `AFX_CAPTION_BTN_CLOSE`, que exibe um **fechar** botão quando o painel pode ser fechado ou ocultado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCCaptionButton` do objeto e defina o tamanho mini da barra de título.  
  
 [!code-cpp[NVC_MFC_RibbonApp#43](../../mfc/reference/codesnippet/cpp/cmfccaptionbutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCCaptionButton](../../mfc/reference/cmfccaptionbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcaptionbutton.h  
  
##  <a name="cmfccaptionbutton"></a>  CMFCCaptionButton::CMFCCaptionButton  
 Constrói um objeto `CMFCCaptionButton`.  
  
```  
CMFCCaptionButton();

 
CMFCCaptionButton(
    UINT nHit,  
    BOOL bLeftAlign = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *nHit*  
 O comando associado ao botão.  
  
 [in] *bLeftAlign*  
 Especifica se o botão é alinhado à esquerda.  
  
 A tabela a seguir lista os possíveis valores para o *nHit* parâmetro.  
  
|Valor|Comando|  
|-----------|-------------|  
|`AFX_HTCLOSE`|Botão Fechar.|  
|`HTMINBUTTON`|Botão de minimização.|  
|`HTMAXBUTTON`|Botão Maximize.|  
|`AFX_HTLEFTBUTTON`|Botão de seta para a esquerda.|  
|`AFX_HTRIGHTBUTTON`|Botão de seta para a direita.|  
|`AFX_HTMENU`|Botão de menu de seta.|  
|`HTNOWHERE`|O valor padrão. não representa nenhum comando.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, os botões de legenda não estão associados com um comando.  
  
 Botões de legenda são alinhados a direita ou esquerda.  
  
##  <a name="gethit"></a>  CMFCCaptionButton::GetHit  
 Retorna o comando representado pelo botão.  
  
```  
UINT GetHit() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comando representado pelo botão.  
  
 A tabela a seguir lista os possíveis valores de retorno.  
  
|Valor|Comando|  
|-----------|-------------|  
|`AFX_HTCLOSE`|Botão Fechar.|  
|`HTMINBUTTON`|Botão de minimização.|  
|`HTMAXBUTTON`|Botão Maximize.|  
|`AFX_HTLEFTBUTTON`|Botão de seta para a esquerda.|  
|`AFX_HTRIGHTBUTTON`|Botão de seta para a direita.|  
|`AFX_HTMENU`|Botão de menu de seta.|  
|`HTNOWHERE`|O valor padrão. não representa nenhum comando.|  
  
##  <a name="geticonid"></a>  CMFCCaptionButton::GetIconID  
 Retorna a ID de imagem associada ao botão.  
  
```  
virtual CMenuImages::IMAGES_IDS GetIconID(
    BOOL bHorz,  
    BOOL bMaximized = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bHorz*  
 `TRUE` imagem de seta para a esquerda ou direita IDs; `FALSE` para cima ou seta para IDs de imagem.  
  
 [in] *bMaximized*  
 `TRUE` para uma ID de imagem maximizar; `FALSE` para um minimizar imagem ID.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID da imagem.  
  
### <a name="remarks"></a>Comentários  
 Os parâmetros de especificar identificações de imagem para minimizar ou maximizar botões de legenda.  
  
##  <a name="getrect"></a>  CMFCCaptionButton::GetRect  
 Retorna o retângulo ocupado pelo botão.  
  
```  
virtual CRect GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo que representa o local do botão.  
  
### <a name="remarks"></a>Comentários  
 Se você não conseguir ver o botão, o tamanho retornado será 0.  
  
##  <a name="getsize"></a>  CMFCCaptionButton::GetSize  
 Retorna a largura e altura do botão.  
  
```  
static CSize GetSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões externas do botão.  
  
### <a name="remarks"></a>Comentários  
 O tamanho retornado inclui a borda e margem de botão.  
  
##  <a name="isminiframebutton"></a>  CMFCCaptionButton::IsMiniFrameButton  
 Indica se a altura da barra de título está definida como tamanho mini.  
  
```  
BOOL IsMiniFrameButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE` Se a legenda for definida como size mini; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="move"></a>  CMFCCaptionButton::Move  
 Define o local de desenho do botão e Mostrar estado da janela.  
  
```  
void Move(
    const CPoint& ptTo,  
    BOOL bHide = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ptTo*  
 O novo local.  
  
 [in] *bHide*  
 Se o botão Mostrar.  
  
##  <a name="ondraw"></a>  CMFCCaptionButton::OnDraw  
 Desenha o botão de legenda.  
  
```  
virtual void OnDraw(
    CDC* pDC,  
    BOOL bActive,  
    BOOL bHorz = TRUE,  
    BOOL bMaximized = TRUE,  
    BOOL bDisabled = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Ponteiro para um contexto de dispositivo para o botão.  
  
 [in] *bScripts Ativos*  
 Se desenhar uma imagem do botão ativo.  
  
 [in] *bHorz*  
 Reservado para uso em uma classe derivada.  
  
 [in] *bMaximized*  
 Se desenhar uma imagem do botão maximizada.  
  
 [in] *bDesabilitado*  
 Se desenhar uma imagem do botão habilitado.  
  
### <a name="remarks"></a>Comentários  
 O *bMaximized* parâmetro é usado quando o botão é um maximizar ou minimizar botão.  
  
##  <a name="setminiframebutton"></a>  CMFCCaptionButton::SetMiniFrameButton  
 Define o tamanho mini da barra de título.  
  
```  
void SetMiniFramebutton(BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *bSet*  
 `TRUE` para a altura da barra de título mini; `FALSE` para a altura da barra de título padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)
