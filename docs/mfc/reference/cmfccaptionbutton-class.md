---
title: Classe CMFCCaptionButton | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCCaptionButton
dev_langs:
- C++
helpviewer_keywords:
- CMFCCaptionButton class
ms.assetid: c5774b38-c0dd-414a-9ede-3b2f78f233ec
caps.latest.revision: 28
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
ms.openlocfilehash: 9d6342f87622c34b671ad5ea443eb78ffd8c3838
ms.lasthandoff: 02/25/2017

---
# <a name="cmfccaptionbutton-class"></a>Classe CMFCCaptionButton
O `CMFCCaptionButton` classe implementa um botão que é exibido na barra de legenda para um painel de encaixe ou em uma janela de quadro simplificado. Normalmente, o framework cria automaticamente botões de legenda.  
  
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
|[CMFCCaptionButton::IsMiniFrameButton](#isminiframebutton)|Indica se a altura da barra de título é definida como mini tamanho.|  
|[CMFCCaptionButton::Move](#move)|Define o local de desenho do botão e o estado da janela Mostrar.|  
|[CMFCCaptionButton::OnDraw](#ondraw)|Desenha o botão de legenda.|  
|[CMFCCaptionButton::SetMiniFrameButton](#setminiframebutton)|Define o tamanho mini da barra de título.|  
  
## <a name="remarks"></a>Comentários  
 Você pode derivar uma classe de [CPaneFrameWnd classe](../../mfc/reference/cpaneframewnd-class.md) e usar o método protegido, `AddButton`, para adicionar botões de legenda para uma janela de quadro mini.  
  
 CPaneFrameWnd.h define as IDs de comando para dois tipos de botões de legenda:  
  
- `AFX_CAPTION_BTN_PIN`, que exibe um botão Fixar ao painel de encaixe oferece suporte ao modo de ocultar automaticamente.  
  
- `AFX_CAPTION_BTN_CLOSE`, que exibe uma **fechar** botão quando o painel pode ser fechado ou ocultado.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um `CMFCCaptionButton` do objeto e defina o tamanho mini da barra de título.  
  
 [!code-cpp[NVC_MFC_RibbonApp&#43;](../../mfc/reference/codesnippet/cpp/cmfccaptionbutton-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CMFCCaptionButton](../../mfc/reference/cmfccaptionbutton-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcaptionbutton.h  
  
##  <a name="a-namecmfccaptionbuttona--cmfccaptionbuttoncmfccaptionbutton"></a><a name="cmfccaptionbutton"></a>CMFCCaptionButton::CMFCCaptionButton  
 Constrói um objeto `CMFCCaptionButton`.  
  
```  
CMFCCaptionButton();

 
CMFCCaptionButton(
    UINT nHit,  
    BOOL bLeftAlign = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nHit`  
 O comando associado ao botão.  
  
 [in] `bLeftAlign`  
 Especifica se o botão é alinhado à esquerda.  
  
 A tabela a seguir lista os possíveis valores para o `nHit` parâmetro.  
  
|Valor|Comando|  
|-----------|-------------|  
|`AFX_HTCLOSE`|Botão Fechar.|  
|`HTMINBUTTON`|Botão minimize.|  
|`HTMAXBUTTON`|Botão Maximize.|  
|`AFX_HTLEFTBUTTON`|Botão de seta para a esquerda.|  
|`AFX_HTRIGHTBUTTON`|Botão de seta para a direita.|  
|`AFX_HTMENU`|Botão de menu de seta.|  
|`HTNOWHERE`|O valor padrão; não representa nenhum comando.|  
  
### <a name="remarks"></a>Comentários  
 Por padrão, botões de legenda não são associados um comando.  
  
 Botões de legenda são alinhados tanto à direita ou esquerda.  
  
##  <a name="a-namegethita--cmfccaptionbuttongethit"></a><a name="gethit"></a>CMFCCaptionButton::GetHit  
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
|`HTMINBUTTON`|Botão minimize.|  
|`HTMAXBUTTON`|Botão Maximize.|  
|`AFX_HTLEFTBUTTON`|Botão de seta para a esquerda.|  
|`AFX_HTRIGHTBUTTON`|Botão de seta para a direita.|  
|`AFX_HTMENU`|Botão de menu de seta.|  
|`HTNOWHERE`|O valor padrão; não representa nenhum comando.|  
  
##  <a name="a-namegeticonida--cmfccaptionbuttongeticonid"></a><a name="geticonid"></a>CMFCCaptionButton::GetIconID  
 Retorna a ID de imagem associada ao botão.  
  
```  
virtual CMenuImages::IMAGES_IDS GetIconID(
    BOOL bHorz,  
    BOOL bMaximized = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bHorz`  
 `TRUE`imagem de seta para a esquerda ou direita IDs; `FALSE` para cima ou seta para IDs de imagem.  
  
 [in] `bMaximized`  
 `TRUE`Para obter um ID de imagem maximizar; `FALSE` para um minimizar imagem ID.  
  
### <a name="return-value"></a>Valor de retorno  
 A ID da imagem.  
  
### <a name="remarks"></a>Comentários  
 Os parâmetros de especificar identificações de imagem para minimizar ou maximizar botões de legenda.  
  
##  <a name="a-namegetrecta--cmfccaptionbuttongetrect"></a><a name="getrect"></a>CMFCCaptionButton::GetRect  
 Retorna o retângulo ocupado pelo botão.  
  
```  
virtual CRect GetRect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O retângulo que representa o local do botão.  
  
### <a name="remarks"></a>Comentários  
 Se você não conseguir ver o botão, o tamanho retornado é 0.  
  
##  <a name="a-namegetsizea--cmfccaptionbuttongetsize"></a><a name="getsize"></a>CMFCCaptionButton::GetSize  
 Retorna a largura e altura do botão.  
  
```  
static CSize GetSize();
```  
  
### <a name="return-value"></a>Valor de retorno  
 As dimensões exteriores do botão.  
  
### <a name="remarks"></a>Comentários  
 O tamanho retornado inclui a borda e margem do botão.  
  
##  <a name="a-nameisminiframebuttona--cmfccaptionbuttonisminiframebutton"></a><a name="isminiframebutton"></a>CMFCCaptionButton::IsMiniFrameButton  
 Indica se a altura da barra de título é definida como mini tamanho.  
  
```  
BOOL IsMiniFrameButton() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 `TRUE`Se a legenda for definida como mini tamanho; Caso contrário, `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="a-namemovea--cmfccaptionbuttonmove"></a><a name="move"></a>CMFCCaptionButton::Move  
 Define o local de desenho do botão e o estado da janela Mostrar.  
  
```  
void Move(
    const CPoint& ptTo,  
    BOOL bHide = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ptTo`  
 O novo local.  
  
 [in] `bHide`  
 Se o botão Mostrar.  
  
##  <a name="a-nameondrawa--cmfccaptionbuttonondraw"></a><a name="ondraw"></a>CMFCCaptionButton::OnDraw  
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
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo para o botão.  
  
 [in] `bActive`  
 Se desenhar uma imagem de botão ativo.  
  
 [in] `bHorz`  
 Reservado para uso em uma classe derivada.  
  
 [in] `bMaximized`  
 Se desenhar uma imagem de botão maximizada.  
  
 [in] `bDisabled`  
 Se desenhar uma imagem de botão habilitado.  
  
### <a name="remarks"></a>Comentários  
 O `bMaximized` parâmetro é usado quando o botão é um maximizar ou minimizar o botão.  
  
##  <a name="a-namesetminiframebuttona--cmfccaptionbuttonsetminiframebutton"></a><a name="setminiframebutton"></a>CMFCCaptionButton::SetMiniFrameButton  
 Define o tamanho mini da barra de título.  
  
```  
void SetMiniFramebutton(BOOL bSet = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `bSet`  
 `TRUE`para a altura da barra de título mini; `FALSE` para a altura da barra de título padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CPaneFrameWnd](../../mfc/reference/cpaneframewnd-class.md)   
 [Classe CDockablePane](../../mfc/reference/cdockablepane-class.md)

