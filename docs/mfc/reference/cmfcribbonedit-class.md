---
title: Classe CMFCRibbonEdit | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::CMFCRibbonEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::CanBeStretched
- AFXRIBBONEDIT/CMFCRibbonEdit::CopyFrom
- AFXRIBBONEDIT/CMFCRibbonEdit::CreateEdit
- AFXRIBBONEDIT/CMFCRibbonEdit::DestroyCtrl
- AFXRIBBONEDIT/CMFCRibbonEdit::DropDownList
- AFXRIBBONEDIT/CMFCRibbonEdit::EnableSpinButtons
- AFXRIBBONEDIT/CMFCRibbonEdit::GetCompactSize
- AFXRIBBONEDIT/CMFCRibbonEdit::GetEditText
- AFXRIBBONEDIT/CMFCRibbonEdit::GetIntermediateSize
- AFXRIBBONEDIT/CMFCRibbonEdit::GetTextAlign
- AFXRIBBONEDIT/CMFCRibbonEdit::GetWidth
- AFXRIBBONEDIT/CMFCRibbonEdit::HasCompactMode
- AFXRIBBONEDIT/CMFCRibbonEdit::HasFocus
- AFXRIBBONEDIT/CMFCRibbonEdit::HasLargeMode
- AFXRIBBONEDIT/CMFCRibbonEdit::HasSpinButtons
- AFXRIBBONEDIT/CMFCRibbonEdit::IsHighlighted
- AFXRIBBONEDIT/CMFCRibbonEdit::OnAfterChangeRect
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDraw
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDrawLabelAndImage
- AFXRIBBONEDIT/CMFCRibbonEdit::OnDrawOnList
- AFXRIBBONEDIT/CMFCRibbonEdit::OnEnable
- AFXRIBBONEDIT/CMFCRibbonEdit::OnHighlight
- AFXRIBBONEDIT/CMFCRibbonEdit::OnKey
- AFXRIBBONEDIT/CMFCRibbonEdit::OnLButtonDown
- AFXRIBBONEDIT/CMFCRibbonEdit::OnLButtonUp
- AFXRIBBONEDIT/CMFCRibbonEdit::OnRTLChanged
- AFXRIBBONEDIT/CMFCRibbonEdit::OnShow
- AFXRIBBONEDIT/CMFCRibbonEdit::Redraw
- AFXRIBBONEDIT/CMFCRibbonEdit::SetACCData
- AFXRIBBONEDIT/CMFCRibbonEdit::SetEditText
- AFXRIBBONEDIT/CMFCRibbonEdit::SetTextAlign
- AFXRIBBONEDIT/CMFCRibbonEdit::SetWidth
dev_langs:
- C++
helpviewer_keywords:
- CMFCRibbonEdit [MFC], CMFCRibbonEdit
- CMFCRibbonEdit [MFC], CanBeStretched
- CMFCRibbonEdit [MFC], CMFCRibbonEdit
- CMFCRibbonEdit [MFC], CopyFrom
- CMFCRibbonEdit [MFC], CreateEdit
- CMFCRibbonEdit [MFC], DestroyCtrl
- CMFCRibbonEdit [MFC], DropDownList
- CMFCRibbonEdit [MFC], EnableSpinButtons
- CMFCRibbonEdit [MFC], GetCompactSize
- CMFCRibbonEdit [MFC], GetEditText
- CMFCRibbonEdit [MFC], GetIntermediateSize
- CMFCRibbonEdit [MFC], GetTextAlign
- CMFCRibbonEdit [MFC], GetWidth
- CMFCRibbonEdit [MFC], HasCompactMode
- CMFCRibbonEdit [MFC], HasFocus
- CMFCRibbonEdit [MFC], HasLargeMode
- CMFCRibbonEdit [MFC], HasSpinButtons
- CMFCRibbonEdit [MFC], IsHighlighted
- CMFCRibbonEdit [MFC], OnAfterChangeRect
- CMFCRibbonEdit [MFC], OnDraw
- CMFCRibbonEdit [MFC], OnDrawLabelAndImage
- CMFCRibbonEdit [MFC], OnDrawOnList
- CMFCRibbonEdit [MFC], OnEnable
- CMFCRibbonEdit [MFC], OnHighlight
- CMFCRibbonEdit [MFC], OnKey
- CMFCRibbonEdit [MFC], OnLButtonDown
- CMFCRibbonEdit [MFC], OnLButtonUp
- CMFCRibbonEdit [MFC], OnRTLChanged
- CMFCRibbonEdit [MFC], OnShow
- CMFCRibbonEdit [MFC], Redraw
- CMFCRibbonEdit [MFC], SetACCData
- CMFCRibbonEdit [MFC], SetEditText
- CMFCRibbonEdit [MFC], SetTextAlign
- CMFCRibbonEdit [MFC], SetWidth
ms.assetid: 9b85f1f2-446b-454e-9af9-104fdad8a897
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c96b5b18530cd9b983e5a4c022883919261cc22c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701604"
---
# <a name="cmfcribbonedit-class"></a>Classe CMFCRibbonEdit
Implementa um controle de edição que está localizado em uma barra de faixa de opções.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCRibbonEdit : public CMFCRibbonButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonEdit::CMFCRibbonEdit](#cmfcribbonedit)|Constrói um objeto `CMFCRibbonEdit`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCRibbonEdit::CanBeStretched](#canbestretched)|Indica se a altura do `CMFCRibbonEdit` controle pode aumentar verticalmente para a altura de uma linha de faixa de opções.|  
|[CMFCRibbonEdit::CMFCRibbonEdit](#cmfcribbonedit)|Constrói um objeto `CMFCRibbonEdit`.|  
|[CMFCRibbonEdit::CopyFrom](#copyfrom)|Copia o estado do especificado `CMFCRibbonEdit` o objeto atual `CMFCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::CreateEdit](#createedit)|Cria uma nova caixa de texto para o `CMFCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::DestroyCtrl](#destroyctrl)|Destrói o `CMFCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::DropDownList](#dropdownlist)|Exibe uma caixa de listagem.|  
|[CMFCRibbonEdit::EnableSpinButtons](#enablespinbuttons)|Habilita e define o intervalo do botão de rotação da caixa de texto.|  
|[CMFCRibbonEdit::GetCompactSize](#getcompactsize)|Recupera o tamanho compacto do `CFMCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::GetEditText](#getedittext)|Recupera o texto na caixa de texto.|  
|[CMFCRibbonEdit::GetIntermediateSize](#getintermediatesize)|Recupera o tamanho intermediário do `CMFCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::GetTextAlign](#gettextalign)|Recupera o alinhamento do texto na caixa de texto.|  
|[CMFCRibbonEdit::GetWidth](#getwidth)|Recupera a largura, em pixels, da `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::HasCompactMode](#hascompactmode)|Indica se a exibição de tamanho para o `CMFCRibbonEdit` controle pode ser compacto.|  
|[CMFCRibbonEdit::HasFocus](#hasfocus)|Indica se o `CMFCRIbbonEdit` controle tem o foco.|  
|[CMFCRibbonEdit::HasLargeMode](#haslargemode)|Indica se a exibição de tamanho para o `CMFCRibbonEdit` controle pode ser grande.|  
|[CMFCRibbonEdit::HasSpinButtons](#hasspinbuttons)|Indica se a caixa de texto tem um botão de rotação.|  
|[CMFCRibbonEdit::IsHighlighted](#ishighlighted)|Indica se o `CMFCRibbonEdit` controle é realçado.|  
|[CMFCRibbonEdit::OnAfterChangeRect](#onafterchangerect)|Chamado pelo framework quando as dimensões do retângulo de exibição para o `CMFCRibbonEdit` controlar alterações.|  
|[CMFCRibbonEdit::OnDraw](#ondraw)|Chamado pelo framework para desenhar o `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::OnDrawLabelAndImage](#ondrawlabelandimage)|Chamado pelo framework para desenhar o rótulo de uma imagem para o `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::OnDrawOnList](#ondrawonlist)|Chamado pelo framework para desenhar o `CMFCRibbonEdit` controle em uma caixa de lista de comandos.|  
|[CMFCRibbonEdit::OnEnable](#onenable)|Chamado pelo framework para habilitar ou desabilitar o `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::OnHighlight](#onhighlight)|Chamado pelo framework quando o ponteiro entra ou sai dos limites do `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::OnKey](#onkey)|Chamado pelo framework quando o usuário pressiona uma dica de tecla e o `CMFCRibbonEdit` controle tem o foco.|  
|[CMFCRibbonEdit::OnLButtonDown](#onlbuttondown)|Chamado pelo framework para atualizar o `CMFCRibbonEdit` controlar quando o usuário pressiona o botão esquerdo do mouse no controle.|  
|[CMFCRibbonEdit::OnLButtonUp](#onlbuttonup)|Chamado pelo framework quando o usuário libera o botão esquerdo do mouse.|  
|[CMFCRibbonEdit::OnRTLChanged](#onrtlchanged)|Chamado pelo framework para atualizar o `CMFCRibbonEdit` controlar quando o layout muda de direção.|  
|[CMFCRibbonEdit::OnShow](#onshow)|Chamado pelo framework para mostrar ou ocultar o `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::Redraw](#redraw)|Atualiza a exibição do `CMFCRibbonEdit` controle.|  
|[CMFCRibbonEdit::SetACCData](#setaccdata)|Define os dados de acessibilidade para o `CMFCRibbonEdit` objeto.|  
|[CMFCRibbonEdit::SetEditText](#setedittext)|Define o texto na caixa de texto.|  
|[CMFCRibbonEdit::SetTextAlign](#settextalign)|Define o alinhamento do texto da caixa de texto.|  
|[CMFCRibbonEdit::SetWidth](#setwidth)|Define a largura da caixa de texto para o `CMFCRibbonEdit` controle.|  
  
## <a name="remarks"></a>Comentários  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCRibbonEdit` do objeto, Mostrar botões de rotação ao lado do controle de edição e definir o texto do controle de edição. Este trecho de código faz parte de [amostra de demonstração do MS Office 2007](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_MSOffice2007Demo#7](../../mfc/reference/codesnippet/cpp/cmfcribbonedit-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxRibbonEdit.h  
  
##  <a name="canbestretched"></a>  CMFCRibbonEdit::CanBeStretched  
 Indica se a altura do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle pode aumentar verticalmente para a altura de uma linha de faixa de opções.  
  
```  
virtual BOOL CanBeStretched();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="cmfcribbonedit"></a>  CMFCRibbonEdit::CMFCRibbonEdit  
 Constrói uma [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
CMFCRibbonEdit(
    UINT nID,  
    int nWidth,  
    LPCTSTR lpszLabel = NULL,  
    int nImage = -1);

CMFCRibbonEdit();
```  
  
### <a name="parameters"></a>Parâmetros  
*nID*<br/>
[in] Comando ID para o `CMFCRibbonEdit` controle.  
  
*nWidth*<br/>
[in] A largura, em pixels, da caixa de texto para o `CMFCRibbonEdit` controle.  
  
*lpszLabel*<br/>
[in] O rótulo para o `CMFCRibbonEdit` controle.  
  
*Nimagem*<br/>
[in] Índice da imagem pequena a ser usado para o `CMFCRibbonEdit` controle. A coleção de imagens pequenas é mantida pela categoria pai da faixa de opções.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCRibbonEdit` controle não usa uma imagem grande.  
  
##  <a name="copyfrom"></a>  CMFCRibbonEdit::CopyFrom  
 Copia o estado do especificado [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto atual [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual void CopyFrom(const CMFCRibbonBaseElement& src);
```  
  
### <a name="parameters"></a>Parâmetros  
*src*<br/>
[in] A fonte `CMFCRibbonEdit` objeto.  
  
### <a name="remarks"></a>Comentários  
 O *src* parâmetro deve ser do tipo `CMFCRibbonEdit`.  
  
##  <a name="createedit"></a>  CMFCRibbonEdit::CreateEdit  
 Cria uma nova caixa de texto para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual CMFCRibbonRichEditCtrl* CreateEdit(
    CWnd* pWndParent,  
    DWORD dwEditStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
*pWndParent*<br/>
[in] Um ponteiro para a janela pai do `CMFCRibbonEdit` objeto.  
  
*dwEditStyle*<br/>
[in] Especifica o estilo da caixa de texto. Você pode combinar os estilos de janela listados na seção de comentários com o [estilos de controle de edição](/windows/desktop/Controls/edit-control-styles) que são descritos no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para a nova caixa de texto se o método foi bem-sucedida; Caso contrário, nulo.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método em uma classe derivada para criar uma caixa de texto personalizado.  
  
 Você pode aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para uma caixa de texto:  
  
- **WS_CHILD**  
  
- **WS_VISIBLE**  
  
- **WS_DISABLED**  
  
- **WS_GROUP**  
  
- **WS_TABSTOP**  
  
##  <a name="destroyctrl"></a>  CMFCRibbonEdit::DestroyCtrl  
 Destrói a [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual void DestroyCtrl();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="dropdownlist"></a>  CMFCRibbonEdit::DropDownList  
 Exibe uma caixa de listagem.  
  
```  
virtual void DropDownList();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método não fará nada. Substitua este método para uma caixa de lista suspensa.  
  
##  <a name="enablespinbuttons"></a>  CMFCRibbonEdit::EnableSpinButtons  
 Habilita e define o intervalo do botão de rotação da caixa de texto.  
  
```  
void EnableSpinButtons(
    int nMin,  
    int nMax);
```  
  
### <a name="parameters"></a>Parâmetros  
*Nmín*<br/>
[in] O valor mínimo do botão de rotação.  
  
*Nmáx*<br/>
[in] O valor máximo do botão de rotação.  
  
### <a name="remarks"></a>Comentários  
 Botões de rotação exibem cima e seta para baixo e permitem que os usuários percorrer um conjunto fixo de valores.  
  
##  <a name="getcompactsize"></a>  CMFCRibbonEdit::GetCompactSize  
 Recupera o tamanho compacto do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual CSize GetCompactSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho compacto do `CMFCRibbonEdit` objeto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getedittext"></a>  CMFCRibbonEdit::GetEditText  
 Recupera o texto na caixa de texto.  
  
```  
CString GetEditText() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O texto na caixa de texto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getintermediatesize"></a>  CMFCRibbonEdit::GetIntermediateSize  
 Recupera o tamanho intermediário do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual CSize GetIntermediateSize(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho intermediário do `CMFCRibbonEdit` objeto.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gettextalign"></a>  CMFCRibbonEdit::GetTextAlign  
 Recupera o alinhamento do texto na caixa de texto.  
  
```  
int GetTextAlign() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor enumerado de alinhamento de texto. Consulte a seção comentários para os valores possíveis.  
  
### <a name="remarks"></a>Comentários  
 O valor retornado é um dos seguintes estilos de controle de edição:  
  
- **ES_LEFT** para alinhamento à esquerda  
  
- **ES_CENTER** para alinhamento centralizado  
  
- **ES_RIGHT** para alinhamento à direita  
  
 Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/desktop/Controls/edit-control-styles).  
  
##  <a name="getwidth"></a>  CMFCRibbonEdit::GetWidth  
 Recupera a largura, em pixels, do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
int GetWidth(BOOL bInFloatyMode = FALSE) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
*bInFloatyMode*<br/>
[in] TRUE se o `CMFCRibbonEdit` controle está no modo flutuante; caso contrário, FALSE.  
  
### <a name="return-value"></a>Valor de retorno  
 A largura, em pixels, da `CMFCRibbonEdit` controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="hascompactmode"></a>  CMFCRibbonEdit::HasCompactMode  
 Indica se a exibição de tamanho para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle pode ser compacto.  
  
```  
virtual BOOL HasCompactMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna TRUE.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retorna TRUE. Substitua este método para indicar se o tamanho de exibição pode ser compact.  
  
##  <a name="hasfocus"></a>  CMFCRibbonEdit::HasFocus  
 Indica se o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle tem o foco.  
  
```  
virtual BOOL HasFocus() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o `CMFCRibbonEdit` controle tem o foco; caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="haslargemode"></a>  CMFCRibbonEdit::HasLargeMode  
 Indica se a exibição de tamanho para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle pode ser grande.  
  
```  
virtual BOOL HasLargeMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna FALSE.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método sempre retorna FALSE. Substitua este método para indicar se o tamanho de exibição pode ser grande.  
  
##  <a name="hasspinbuttons"></a>  CMFCRibbonEdit::HasSpinButtons  
 Indica se a caixa de texto tem um botão de rotação.  
  
```  
virtual BOOL HasSpinButtons() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a caixa de texto tem um botão de rotação; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ishighlighted"></a>  CMFCRibbonEdit::IsHighlighted  
 Indica se o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle é realçado.  
  
```  
virtual BOOL IsHighlighted() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o `CMFCRibbonEdit` controle estiver realçado; caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onafterchangerect"></a>  CMFCRibbonEdit::OnAfterChangeRect  
 Chamado pelo framework quando as dimensões do retângulo de exibição para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controlar alterações.  
  
```  
virtual void OnAfterChangeRect(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondraw"></a>  CMFCRibbonEdit::OnDraw  
 Chamado pelo framework para desenhar o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void OnDraw(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawlabelandimage"></a>  CMFCRibbonEdit::OnDrawLabelAndImage  
 Chamado pelo framework para desenhar o rótulo de uma imagem para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void OnDrawLabelAndImage(CDC* pDC);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="ondrawonlist"></a>  CMFCRibbonEdit::OnDrawOnList  
 Chamado pelo framework para desenhar o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle em uma caixa de lista de comandos.  
  
```  
virtual void OnDrawOnList(
    CDC* pDC,  
    CString strText,  
    int nTextOffset,  
    CRect rect,  
    BOOL bIsSelected,  
    BOOL bHighlighted);
```  
  
### <a name="parameters"></a>Parâmetros  
*pDC*<br/>
[in] Ponteiro para um contexto de dispositivo para o `CMFCRibbonEdit` controle.  
  
*strText*<br/>
[in] O texto de exibição [ ] (../../mfc/reference/cmfcribbonedit-class.md "classe cmfcribbonedit").  
  
*nTextOffset*<br/>
[in] Distância, em pixels, do lado esquerdo da caixa de listagem para o texto de exibição.  
  
*Rect*<br/>
[in] O retângulo de exibição para o `CMFCRibbonEdit` controle.  
  
*bIsSelected*<br/>
[in] Esse parâmetro não é usado.  
  
*bHighlighted*<br/>
[in] Esse parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
 A caixa de lista de comandos exibe controles de faixa de opções para permitir que os usuários personalizem a barra de ferramentas de acesso rápido.  
  
##  <a name="onenable"></a>  CMFCRibbonEdit::OnEnable  
 Chamado pelo framework para habilitar ou desabilitar a [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void OnEnable(BOOL bEnable);
```  
  
### <a name="parameters"></a>Parâmetros  
*bAtivar*<br/>
[in] TRUE para habilitar o controle; FALSE para desabilitar o controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onhighlight"></a>  CMFCRibbonEdit::OnHighlight  
 Chamado pelo framework quando o ponteiro entra ou sai dos limites do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void OnHighlight(BOOL bHighlight);
```  
  
### <a name="parameters"></a>Parâmetros  
*bHighlight*<br/>
[in] TRUE se o ponteiro está nos limites do `CMFCRibbonEdit` controle; caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onkey"></a>  CMFCRibbonEdit::OnKey  
 Chamado pelo framework quando o usuário pressiona uma dica de tecla e o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle tem o foco.  
  
```  
virtual BOOL OnKey(BOOL bIsMenuKey);
```  
  
### <a name="parameters"></a>Parâmetros  
*bIsMenuKey*<br/>
[in] TRUE se a dica de tecla exibe um menu pop-up. Caso contrário, FALSE.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o evento foi tratado; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onlbuttondown"></a>  CMFCRibbonEdit::OnLButtonDown  
 Chamado pelo framework para atualizar o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controlar quando o usuário pressiona o botão esquerdo do mouse no controle.  
  
```  
virtual void OnLButtonDown(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
*ponto*<br/>
[in] Esse parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onlbuttonup"></a>  CMFCRibbonEdit::OnLButtonUp  
 Chamado pelo framework quando o usuário libera o botão esquerdo do mouse.  
  
```  
virtual void OnLButtonUp(CPoint point);
```  
  
### <a name="parameters"></a>Parâmetros  
*ponto*<br/>
[in] Esse parâmetro não é usado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onrtlchanged"></a>  CMFCRibbonEdit::OnRTLChanged  
 Chamado pelo framework para atualizar o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controlar quando o layout muda de direção.  
  
```  
virtual void OnRTLChanged(BOOL bIsRTL);
```  
  
### <a name="parameters"></a>Parâmetros  
*bIsRTL*<br/>
[in] TRUE se o layout é da direita para esquerda; FALSE se o layout é esquerda para a direita.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onshow"></a>  CMFCRibbonEdit::OnShow  
 Chamado pelo framework para mostrar ou ocultar a [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void OnShow(BOOL bShow);
```  
  
### <a name="parameters"></a>Parâmetros  
*bMostrar*<br/>
[in] TRUE para mostrar o controle; FALSO para ocultar o controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="redraw"></a>  CMFCRibbonEdit::Redraw  
 Atualiza a exibição do [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
virtual void Redraw();
```  
  
### <a name="remarks"></a>Comentários  
 Esse método redesenha o retângulo de exibição para o `CMFCRibbonEdit` objeto indiretamente chamando [CWnd::RedrawWindow](/windows/desktop/api/winuser/nf-winuser-redrawwindow) com os sinalizadores RDW_INVALIDATE, RDW_ERASE e RDW_UPDATENOW definido.  
  
##  <a name="setaccdata"></a>  CMFCRibbonEdit::SetACCData  
 Define os dados de acessibilidade para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) objeto.  
  
```  
virtual BOOL SetACCData(
    CWnd* pParent,  
    CAccessibilityData& data);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pParent*  
 Ponteiro para a janela pai para o `CMFCRibbonEdit` objeto.  
  
 *data*  
 Os dados de acessibilidade para o `CMFCRibbonEdit` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Sempre retorna TRUE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setedittext"></a>  CMFCRibbonEdit::SetEditText  
 Define o texto na caixa de texto.  
  
```  
void SetEditText(CString strText);
```  
  
### <a name="parameters"></a>Parâmetros  
*strText*<br/>
[in] O texto da caixa de texto.  
  
##  <a name="settextalign"></a>  CMFCRibbonEdit::SetTextAlign  
 Define o alinhamento do texto da caixa de texto.  
  
```  
void SetTextAlign(int nAlign);
```  
  
### <a name="parameters"></a>Parâmetros  
*nAlign*<br/>
[in] Um valor enumerado de alinhamento de texto. Consulte a seção comentários para os valores possíveis.  
  
### <a name="remarks"></a>Comentários  
 O parâmetro *nAlign* é uma da edição seguinte estilos de controle:  
  
- ES_LEFT para alinhamento à esquerda  
  
- ES_CENTER para alinhamento centralizado  
  
- ES_RIGHT para alinhamento à direita  
  
 Para obter mais informações sobre esses estilos, consulte [Editar estilos de controle](/windows/desktop/Controls/edit-control-styles).  
  
##  <a name="setwidth"></a>  CMFCRibbonEdit::SetWidth  
 Define a largura da caixa de texto para o [CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md) controle.  
  
```  
void SetWidth(
    int nWidth,  
    BOOL bInFloatyMode = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
*nWidth*<br/>
[in] A largura, em pixels, da caixa de texto.  
  
 *bInFloatyMode*  
 TRUE para definir a largura para o modo de flutuante; FALSE para definir a largura para o modo normal.  
  
### <a name="remarks"></a>Comentários  
 O `CMFCRibbonEdit` controle tem dois larguras dependendo do seu modo de exibição: flutuante modo e o modo comum.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)   
 [Classe CMFCRibbonBar](../../mfc/reference/cmfcribbonbar-class.md)