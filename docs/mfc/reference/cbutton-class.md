---
title: Classe CButton | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CButton
- AFXWIN/CButton
- AFXWIN/CButton::CButton
- AFXWIN/CButton::Create
- AFXWIN/CButton::DrawItem
- AFXWIN/CButton::GetBitmap
- AFXWIN/CButton::GetButtonStyle
- AFXWIN/CButton::GetCheck
- AFXWIN/CButton::GetCursor
- AFXWIN/CButton::GetIcon
- AFXWIN/CButton::GetIdealSize
- AFXWIN/CButton::GetImageList
- AFXWIN/CButton::GetNote
- AFXWIN/CButton::GetNoteLength
- AFXWIN/CButton::GetSplitGlyph
- AFXWIN/CButton::GetSplitImageList
- AFXWIN/CButton::GetSplitInfo
- AFXWIN/CButton::GetSplitSize
- AFXWIN/CButton::GetSplitStyle
- AFXWIN/CButton::GetState
- AFXWIN/CButton::GetTextMargin
- AFXWIN/CButton::SetBitmap
- AFXWIN/CButton::SetButtonStyle
- AFXWIN/CButton::SetCheck
- AFXWIN/CButton::SetCursor
- AFXWIN/CButton::SetDropDownState
- AFXWIN/CButton::SetIcon
- AFXWIN/CButton::SetImageList
- AFXWIN/CButton::SetNote
- AFXWIN/CButton::SetSplitGlyph
- AFXWIN/CButton::SetSplitImageList
- AFXWIN/CButton::SetSplitInfo
- AFXWIN/CButton::SetSplitSize
- AFXWIN/CButton::SetSplitStyle
- AFXWIN/CButton::SetState
- AFXWIN/CButton::SetTextMargin
dev_langs:
- C++
helpviewer_keywords:
- CButton [MFC], CButton
- CButton [MFC], Create
- CButton [MFC], DrawItem
- CButton [MFC], GetBitmap
- CButton [MFC], GetButtonStyle
- CButton [MFC], GetCheck
- CButton [MFC], GetCursor
- CButton [MFC], GetIcon
- CButton [MFC], GetIdealSize
- CButton [MFC], GetImageList
- CButton [MFC], GetNote
- CButton [MFC], GetNoteLength
- CButton [MFC], GetSplitGlyph
- CButton [MFC], GetSplitImageList
- CButton [MFC], GetSplitInfo
- CButton [MFC], GetSplitSize
- CButton [MFC], GetSplitStyle
- CButton [MFC], GetState
- CButton [MFC], GetTextMargin
- CButton [MFC], SetBitmap
- CButton [MFC], SetButtonStyle
- CButton [MFC], SetCheck
- CButton [MFC], SetCursor
- CButton [MFC], SetDropDownState
- CButton [MFC], SetIcon
- CButton [MFC], SetImageList
- CButton [MFC], SetNote
- CButton [MFC], SetSplitGlyph
- CButton [MFC], SetSplitImageList
- CButton [MFC], SetSplitInfo
- CButton [MFC], SetSplitSize
- CButton [MFC], SetSplitStyle
- CButton [MFC], SetState
- CButton [MFC], SetTextMargin
ms.assetid: cdc76d5b-31da-43c5-bc43-fde4cb39de5b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a55623c28ca7114f43f208e5c660b9df38d1242b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45701827"
---
# <a name="cbutton-class"></a>Classe CButton
Fornece a funcionalidade de controles de botão do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CButton : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CButton::CButton](#cbutton)|Constrói um objeto `CButton`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CButton::Create](#create)|Cria o controle de botão do Windows e anexa-o para o `CButton` objeto.|  
|[CButton::DrawItem](#drawitem)|Substituição para desenhar um desenho proprietário `CButton` objeto.|  
|[CButton::GetBitmap](#getbitmap)|Recupera o identificador do bitmap definido anteriormente com [SetBitmap](#setbitmap).|  
|[CButton::GetButtonStyle](#getbuttonstyle)|Recupera informações sobre o estilo de controle de botão.|  
|[CButton::GetCheck](#getcheck)|Recupera o estado de seleção de um controle de botão.|  
|[CButton::GetCursor](#getcursor)|Recupera o identificador da imagem do cursor definido anteriormente com [SetCursor](#setcursor).|  
|[CButton::GetIcon](#geticon)|Recupera o identificador do ícone definido anteriormente com [SetIcon](#seticon).|  
|[CButton::GetIdealSize](#getidealsize)|Recupera o tamanho ideal de controle de botão.|  
|[CButton::GetImageList](#getimagelist)|Recupera a lista de imagens de controle de botão.|  
|[CButton::GetNote](#getnote)|Recupera o componente de observação do controle de link de comando atual.|  
|[CButton::GetNoteLength](#getnotelength)|Recupera o comprimento do texto de Observação para o controle de link de comando atual.|  
|[CButton::GetSplitGlyph](#getsplitglyph)|Recupera o glifo associado ao controle de botão de divisão atual.|  
|[CButton::GetSplitImageList](#getsplitimagelist)|Recupera a lista de imagens para o controle de botão de divisão atual.|  
|[CButton::GetSplitInfo](#getsplitinfo)|Recupera as informações que define o controle de botão de divisão atual.|  
|[CButton::GetSplitSize](#getsplitsize)|Recupera o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.|  
|[CButton::GetSplitStyle](#getsplitstyle)|Recupera os estilos de botão de divisão que definem o controle de botão de divisão atual.|  
|[CButton::GetState](#getstate)|Recupera o estado de seleção, o estado de realce e o estado de foco de um controle de botão.|  
|[CButton::GetTextMargin](#gettextmargin)|Recupera a margem de texto do controle button.|  
|[CButton::SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no botão.|  
|[CButton::SetButtonStyle](#setbuttonstyle)|Altera o estilo de um botão.|  
|[CButton::SetCheck](#setcheck)|Define o estado de seleção de um controle de botão.|  
|[CButton::SetCursor](#setcursor)|Especifica uma imagem de cursor a ser exibido no botão.|  
|[CButton::SetDropDownState](#setdropdownstate)|Define o estado da lista suspensa do controle de botão de divisão atual.|  
|[CButton::SetIcon](#seticon)|Especifica um ícone a ser exibido no botão.|  
|[CButton::SetImageList](#setimagelist)|Define a lista de imagens de controle de botão.|  
|[CButton::SetNote](#setnote)|Define a nota no controle de link de comando atual.|  
|[CButton::SetSplitGlyph](#setsplitglyph)|Associa um glifo especificado com o controle de botão de divisão atual.|  
|[CButton::SetSplitImageList](#setsplitimagelist)|Associa uma lista de imagens com o controle de botão de divisão atual.|  
|[CButton::SetSplitInfo](#setsplitinfo)|Especifica as informações que define o controle de botão de divisão atual.|  
|[CButton::SetSplitSize](#setsplitsize)|Define o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.|  
|[CButton::SetSplitStyle](#setsplitstyle)|Define o estilo do controle de botão de divisão atual.|  
|[CButton::SetState](#setstate)|Define o estado de realce de um controle de botão.|  
|[CButton::SetTextMargin](#settextmargin)|Define a margem de texto do controle button.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de botão é uma janela filho pequenas, retangular que pode ser clicada e desativar. Botões podem ser usado sozinho ou em grupos e também podem ser rotulada ou aparecem sem texto. Um botão normalmente muda de aparência quando o usuário clica nele.  
  
 Botões comuns são a caixa de seleção, botão de opção e botão de ação. Um `CButton` objeto pode se tornar qualquer um desses, acordo com o [estilo do botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) especificado na sua inicialização pelo [criar](#create) função de membro.  
  
 Além disso, o [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md) classe derivada de `CButton` dá suporte à criação de controles de botão rotulados com imagens de bitmap em vez de texto. Um `CBitmapButton` pode ter bitmaps separados para um botão do, para baixo, com foco e desabilitados de estados.  
  
 Você pode criar um controle de botão de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, chame o construtor `CButton` para construir o `CButton` objeto; em seguida, chame o `Create` controle de botão de função de membro para criar o Windows e anexá-lo para o `CButton` objeto.  
  
 Construção pode ser um processo de uma etapa em uma classe derivada de `CButton`. Escrever um construtor para a classe derivada e a chamada `Create` do construtor.  
  
 Se você quiser manipular mensagens de notificação do Windows enviadas por um controle de botão para seu pai (normalmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicione uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem usa o seguinte formato:  
  
 **On _** notificação **(**`id`, `memberFxn` **)**  
  
 em que `id` Especifica a ID de janela filho do controle que está enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx_msg** `void` `memberFxn` **();**  
  
 Entradas de mapa de mensagem potenciais são da seguinte maneira:  
  
|Entrada de mapa|Enviado para o pai quando...|  
|---------------|----------------------------|  
|ON_BN_CLICKED|O usuário clica em um botão.|  
|ON_BN_DOUBLECLICKED|O usuário clica duas vezes em um botão.|  
  
 Se você criar uma `CButton` objeto de um recurso de caixa de diálogo, o `CButton` objeto será destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CButton` do objeto dentro de uma janela, talvez você precise destruí-lo. Se você criar o `CButton` objeto no heap usando a **novos** função, você deve chamar **excluir** controle de botão no objeto a destruí-la quando o usuário fecha o Windows. Se você criar o `CButton` objeto na pilha, ou ele é incorporado no objeto de caixa de diálogo pai, ele será destruído automaticamente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CButton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cbutton"></a>  CButton::CButton  
 Constrói um objeto `CButton`.  
  
```  
CButton();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#1](../../mfc/reference/codesnippet/cpp/cbutton-class_1.cpp)]  
  
##  <a name="create"></a>  CButton::Create  
 Cria o controle de botão do Windows e anexa-o para o `CButton` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszCaption,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszCaption*  
 Especifica o texto do controle de botão.  
  
 *dwStyle*  
 Especifica o estilo do controle de botão. Aplicar qualquer combinação de [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) ao botão.  
  
 *Rect*  
 Especifica o tamanho e a posição do controle button. Ela pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 *pParentWnd*  
 Especifica a janela do pai do controle button, geralmente um `CDialog`. Ele não deve ser NULL.  
  
 *nID*  
 Especifica a ID. do controle button  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CButton` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de botão do Windows e anexa-o para o `CButton` objeto.  
  
 Se o estilo WS_VISIBLE for fornecido, o Windows envia o controle de botão todas as mensagens necessárias para ativar e mostrar o botão.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) para um controle de botão:  
  
- Sempre WS_CHILD  
  
- Normalmente, WS_VISIBLE  
  
- WS_DISABLED raramente  
  
- WS_GROUP para agrupar controles  
  
- WS_TABSTOP para incluir o botão na ordem de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#2](../../mfc/reference/codesnippet/cpp/cbutton-class_2.cpp)]  
  
##  <a name="drawitem"></a>  CButton::DrawItem  
 Chamado pelo framework quando um aspecto visual de um botão desenhado pelo proprietário é alterado.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDrawItemStruct*  
 Um ponteiro longo para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura. A estrutura contém informações sobre o item a ser desenhado e o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 Um botão desenhado pelo proprietário tem o estilo BS_OWNERDRAW definido. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CButton` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do membro da função será encerrado.  
  
 Consulte também o [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) valores de estilo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#3](../../mfc/reference/codesnippet/cpp/cbutton-class_3.cpp)]  
  
##  <a name="getbitmap"></a>  CButton::GetBitmap  
 Chame essa função de membro para obter o identificador de um bitmap, definido anteriormente com [SetBitmap](#setbitmap), que é associado com um botão.  
  
```  
HBITMAP GetBitmap() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um bitmap. NULL se nenhum bitmap é especificado anteriormente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]  
  
##  <a name="getbuttonstyle"></a>  CButton::GetButtonStyle  
 Recupera informações sobre o estilo de controle de botão.  
  
```  
UINT GetButtonStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna os estilos de botão para este `CButton` objeto. Essa função retorna apenas o [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) valores do estilo, não qualquer um dos outros estilos de janela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]  
  
##  <a name="getcheck"></a>  CButton::GetCheck  
 Recupera o estado de seleção de um botão de opção ou a caixa de seleção.  
  
```  
int GetCheck() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor retornado de um controle de botão criado com BS_AUTOCHECKBOX, BS_AUTORADIOBUTTON, BS_AUTO3STATE, BS_CHECKBOX, BS_RADIOBUTTON ou estilo BS_3STATE é um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|BST_UNCHECKED|Estado do botão está desmarcado.|  
|BST_CHECKED|Estado do botão é verificado.|  
|BST_INDETERMINATE|Estado do botão é indeterminado (aplicável somente se o botão tem o estilo BS_3STATE ou BS_AUTO3STATE).|  
  
 Se o botão tiver qualquer outro estilo, o valor de retorno é BST_UNCHECKED.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]  
  
##  <a name="getcursor"></a>  CButton::GetCursor  
 Chame essa função de membro para obter o identificador de um cursor, definido anteriormente com [SetCursor](#setcursor), que é associado com um botão.  
  
```  
HCURSOR GetCursor();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para uma imagem do cursor. NULL se nenhum cursor é especificado anteriormente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]  
  
##  <a name="geticon"></a>  CButton::GetIcon  
 Chame essa função de membro para obter o identificador de um ícone definido anteriormente com [SetIcon](#seticon), que é associado com um botão.  
  
```  
HICON GetIcon() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone. NULL se nenhum ícone for especificado anteriormente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]  
  
##  <a name="getidealsize"></a>  CButton::GetIdealSize  
 Recupera o tamanho ideal para o controle de botão.  
  
```  
BOOL GetIdealSize(SIZE* psize);
```  
  
### <a name="parameters"></a>Parâmetros  
 *psize*  
 Um ponteiro para o tamanho atual do botão.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da mensagem BCM_GETIDEALSIZE, conforme descrito na [botões](https://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="getimagelist"></a>  CButton::GetImageList  
 Chame esse método para obter a lista de imagens de controle de botão.  
  
```  
BOOL GetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbuttonImagelist*  
 Um ponteiro para a lista de imagens do `CButton` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da mensagem BCM_GETIMAGELIST, conforme descrito na [botões](https://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="getnote"></a>  CButton::GetNote  
 Recupera o texto de anotação associado ao controle de link de comando atual.  
  
```  
CString GetNote() const;  
  
BOOL GetNote(
    LPTSTR lpszNote,   
    UINT* cchNote) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*lpszNote*|[out] Ponteiro para um buffer, que o chamador é responsável por alocar e desalocar. Se o valor de retorno for TRUE, o buffer contém o texto de anotação que está associado com o controle de link de comando atual; Caso contrário, o buffer é inalterado.|  
|*cchNote*|[no, out] Um ponteiro para uma variável de inteiro sem sinal.<br /><br /> Quando este método é chamado, a variável contém o tamanho do buffer especificado pelo *lpszNote* parâmetro.<br /><br /> Quando este método retorna, se o valor de retorno for TRUE, a variável contém o tamanho da anotação associado ao controle de link de comando atual. Se o valor de retorno for FALSE, a variável contém o tamanho do buffer necessário para conter a anotação.|  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) objeto que contém o texto de anotação associado ao controle de link de comando atual.  
  
 -ou-  
  
 Na segunda sobrecarga, TRUE se este método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_COMMANDLINK ou BS_DEFCOMMANDLINK.  
  
 Esse método envia o [BCM_GETNOTE](/windows/desktop/Controls/bcm-getnote) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getnotelength"></a>  CButton::GetNoteLength  
 Recupera o comprimento do texto de Observação para o controle de link de comando atual.  
  
```  
UINT GetNoteLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do texto de observação, em caracteres Unicode de 16 bits, para o controle de link de comando atual.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_COMMANDLINK ou BS_DEFCOMMANDLINK.  
  
 Esse método envia o [BCM_GETNOTELENGTH](/windows/desktop/Controls/bcm-getnotelength) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getsplitglyph"></a>  CButton::GetSplitGlyph  
 Recupera o glifo associado ao controle de botão de divisão atual.  
  
```  
TCHAR GetSplitGlyph() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caractere de glifo associado ao controle de botão de divisão atual.  
  
### <a name="remarks"></a>Comentários  
 Um glifo é a representação física de um caractere em uma fonte específica. Por exemplo, um controle de botão de divisão pode ser decorado com o glifo do caractere de marca de seleção de Unicode (U + 2713).  
  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_GLYPH e, em seguida, envia a estrutura no [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no Windows SDK. Quando a função de mensagens retorna, esse método recupera o glifo do `himlGlyph` membro da estrutura.  
  
##  <a name="getsplitimagelist"></a>  CButton::GetSplitImageList  
 Recupera o [lista de imagens](../../mfc/reference/cimagelist-class.md) para o controle de botão de divisão atual.  
  
```  
CImageList* GetSplitImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_IMAGE e, em seguida, envia a estrutura no [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no Windows SDK. Quando a função de mensagens retorna, esse método recupera a lista de imagens do `himlGlyph` membro da estrutura.  
  
##  <a name="getsplitinfo"></a>  CButton::GetSplitInfo  
 Recupera os parâmetros que determinam como o Windows desenha o controle de botão de divisão atual.  
  
```  
BOOL GetSplitInfo(PBUTTON_SPLITINFO pInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*pInfo*|[out] Ponteiro para um [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura que recebe informações sobre o controle de botão de divisão atual. O chamador é responsável por alocar a estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Esse método envia o [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getsplitsize"></a>  CButton::GetSplitSize  
 Recupera o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.  
  
```  
BOOL GetSplitSize(LPSIZE pSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*pSize*|[out] Ponteiro para um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que recebe a descrição de um retângulo.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Quando o controle de botão de divisão for expandido, ele pode exibir um componente de lista suspensa, como um controle de lista ou um controle de paginação. Esse método recupera o retângulo delimitador que contém o componente de lista suspensa.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_SIZE e, em seguida, envia a estrutura no [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no Windows SDK. Quando a função de mensagens retorna, esse método recupera o retângulo delimitador do `size` membro da estrutura.  
  
##  <a name="getsplitstyle"></a>  CButton::GetSplitStyle  
 Recupera os estilos de botão de divisão que definem o controle de botão de divisão atual.  
  
```  
UINT GetSplitStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação bit a bit dos estilos de botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro a [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Os estilos de botão de divisão especificam o alinhamento, a taxa de proporção e o formato de gráfico com o qual o Windows desenha um ícone do botão de divisão.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_STYLE e, em seguida, envia a estrutura no [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no Windows SDK. Quando a função de mensagens retorna, esse método recupera os estilos de botão de divisão do `uSplitStyle` membro da estrutura.  
  
##  <a name="getstate"></a>  CButton::GetState  
 Recupera o estado de um controle de botão.  
  
```  
UINT GetState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um campo de bits que contém a combinação de valores que indicam o estado atual de um controle de botão. A tabela a seguir lista os valores possíveis.  
  
|Estado do botão|Valor|Descrição|  
|------------------|-----------|-----------------|  
|BST_UNCHECKED|0x0000|O estado inicial.|  
|BST_CHECKED|0x0001|O controle de botão é verificado.|  
|BST_INDETERMINATE|0x0002|O estado indeterminado (só é possível quando o controle de botão tem três estados).|  
|BST_PUSHED|0x0004|O controle de botão é pressionado.|  
|BST_FOCUS|0x0008|O controle de botão tem o foco.|  
  
### <a name="remarks"></a>Comentários  
 Um controle de botão com o estilo de botão BS_3STATE ou BS_AUTO3STATE cria uma caixa de seleção que tem um terceiro estado chamado estado indeterminado. O estado indeterminado indica que a caixa de seleção não está marcada ou desmarcada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]  
  
##  <a name="gettextmargin"></a>  CButton::GetTextMargin  
 Chame esse método para obter a margem de texto do `CButton` objeto.  
  
```  
BOOL GetTextMargin(RECT* pmargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pmargin*  
 Um ponteiro para a margem de texto do `CButton` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a margem de texto.  
  
### <a name="remarks"></a>Comentários  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da mensagem BCM_GETTEXTMARGIN, conforme descrito na [botões](https://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="setbitmap"></a>  CButton::SetBitmap  
 Chame essa função de membro para associar um novo bitmap com o botão.  
  
```  
HBITMAP SetBitmap(HBITMAP hBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hBitmap*  
 O identificador de um bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um bitmap associado anteriormente com o botão.  
  
### <a name="remarks"></a>Comentários  
 O bitmap será colocado automaticamente na face do botão, centralizado, por padrão. Se o bitmap for muito grande para o botão, ele será recortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- BS_TOP  
  
- BS_LEFT  
  
- BS_RIGHT  
  
- BS_CENTER  
  
- BS_BOTTOM  
  
- BS_VCENTER  
  
 Diferentemente [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetBitmap` usa apenas um bitmap por botão. Quando o botão é pressionado, o bitmap é exibido Deslocar para baixo e para a direita.  
  
 Você é responsável por liberar o bitmap quando você terminar com ele.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]  
  
##  <a name="setbuttonstyle"></a>  CButton::SetButtonStyle  
 Altera o estilo de um botão.  
  
```  
void SetButtonStyle(
    UINT nStyle,  
    BOOL bRedraw = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nStyle*  
 Especifica o [estilo do botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).  
  
 *bRedraw*  
 Especifica se o botão deve ser redesenhado. Um valor diferente de zero redesenha o botão. Um valor 0 não atualiza o botão. O botão é redesenhado por padrão.  
  
### <a name="remarks"></a>Comentários  
 Use o `GetButtonStyle` a função de membro para recuperar o estilo de botão. A palavra de ordem inferior do estilo de botão Concluir é o estilo de botão específico.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]  
  
##  <a name="setcheck"></a>  CButton::SetCheck  
 Define ou redefine o estado de seleção de um botão de opção ou a caixa de seleção.  
  
```  
void SetCheck(int nCheck);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nVerifique*  
 Especifica o estado de seleção. Esse parâmetro pode ser um dos seguintes:  
  
|Valor|Significado|  
|-----------|-------------|  
|BST_UNCHECKED|Defina o estado do botão como desmarcada.|  
|BST_CHECKED|Defina o estado do botão verificada.|  
|BST_INDETERMINATE|Defina o estado do botão como indeterminado. Esse valor pode ser usado somente se o botão tem o estilo BS_3STATE ou BS_AUTO3STATE.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não tem nenhum efeito em um botão de ação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]  
  
##  <a name="setcursor"></a>  CButton::SetCursor  
 Chame essa função de membro para associar um novo cursor com o botão.  
  
```  
HCURSOR SetCursor(HCURSOR hCursor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hCursor*  
 O identificador de um cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um cursor anteriormente associado ao botão.  
  
### <a name="remarks"></a>Comentários  
 O cursor será colocado automaticamente na face do botão, centralizado, por padrão. Se o cursor for muito grande para o botão, ele será recortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- BS_TOP  
  
- BS_LEFT  
  
- BS_RIGHT  
  
- BS_CENTER  
  
- BS_BOTTOM  
  
- BS_VCENTER  
  
 Diferentemente [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetCursor` usa apenas um cursor por botão. Quando o botão é pressionado, o cursor é exibido Deslocar para baixo e para a direita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]  
  
##  <a name="setdropdownstate"></a>  CButton::SetDropDownState  
 Define o estado da lista suspensa do controle de botão de divisão atual.  
  
```  
BOOL SetDropDownState(BOOL fDropDown);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*fDropDown*|[in] TRUE para definir o estado BST_DROPDOWNPUSHED; Caso contrário, FALSE.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Um controle de botão de divisão tem um estilo BS_SPLITBUTTON ou BS_DEFSPLITBUTTON e consiste em um botão e uma seta suspensa à direita. Para obter mais informações, consulte [estilos de botão](/windows/desktop/Controls/button-styles). Normalmente, o estado de lista suspensa é definido quando o usuário clica na seta suspensa. Use esse método para definir programaticamente o estado de lista suspensa do controle. A seta suspensa é desenhada sombreada para indicar o estado.  
  
 Esse método envia o [BCM_SETDROPDOWNSTATE](/windows/desktop/Controls/bcm-setdropdownstate) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável *m_splitButton*, que é usado para acessar programaticamente o controle de botão de divisão. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o estado de controle de botão de divisão para indicar que a seta suspensa é enviada por push.  
  
 [!code-cpp[NVC_MFC_CButton_s1#6](../../mfc/reference/codesnippet/cpp/cbutton-class_11.cpp)]  
  
##  <a name="setelevationrequired"></a>  CButton::SetElevationRequired  
 Define o estado do controle de botão para `elevation required`, que é necessário para o controle exibir um ícone de segurança elevadas.  
  
```  
BOOL SetElevationRequired(BOOL fElevationRequired);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*fElevationRequired*|[in] True para definir `elevation required` estado; caso contrário, FALSE.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Se um controle de link do botão ou comando requer a permissão de segurança com privilégios elevados para executar uma ação, defina o controle como `elevation required` estado. Subsequentemente, o Windows exibe o ícone de escudo de controle de conta de usuário (UAC) no controle. Para obter mais informações, consulte "Controle de conta de usuário" em [MSDN](http://go.microsoft.com/fwlink/p/?linkid=18507).  
  
 Esse método envia o [BCM_SETSHIELD](/windows/desktop/Controls/bcm-setshield) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="seticon"></a>  CButton::SetIcon  
 Chame essa função de membro para associar um ícone de novo com o botão.  
  
```  
HICON SetIcon(HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hIcon*  
 O identificador de um ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um ícone associado ao botão anteriormente.  
  
### <a name="remarks"></a>Comentários  
 O ícone será colocado automaticamente na face do botão, centralizado, por padrão. Se o ícone for muito grande para o botão, ele será recortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- BS_TOP  
  
- BS_LEFT  
  
- BS_RIGHT  
  
- BS_CENTER  
  
- BS_BOTTOM  
  
- BS_VCENTER  
  
 Diferentemente [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetIcon` usa apenas um ícone por botão. Quando o botão é pressionado, o ícone é exibido Deslocar para baixo e para a direita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]  
  
##  <a name="setimagelist"></a>  CButton::SetImageList  
 Chame esse método para definir a lista de imagens do `CButton` objeto.  
  
```  
BOOL SetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbuttonImagelist*  
 Um ponteiro para a nova lista de imagens.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da mensagem BCM_SETIMAGELIST, conforme descrito na [botões](https://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="setnote"></a>  CButton::SetNote  
 Define o texto de anotação para o controle de link de comando atual.  
  
```  
BOOL SetNote(LPCTSTR lpszNote);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*lpszNote*|[in] Ponteiro para uma cadeia de caracteres Unicode que é definido como o texto de anotação para o controle de link de comando.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_COMMANDLINK ou BS_DEFCOMMANDLINK.  
  
 Esse método envia o [BCM_SETNOTE](/windows/desktop/Controls/bcm-setnote) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável *m_cmdLink*, que é usado para acessar programaticamente o controle de link de comando. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o texto de anotação para o controle de link de comando.  
  
 [!code-cpp[NVC_MFC_CButton_s1#7](../../mfc/reference/codesnippet/cpp/cbutton-class_12.cpp)]  
  
##  <a name="setsplitglyph"></a>  CButton::SetSplitGlyph  
 Associa um glifo especificado com o controle de botão de divisão atual.  
  
```  
BOOL SetSplitGlyph(TCHAR chGlyph);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*chGlyph*|[in] Um caractere que especifica o glifo para usar como a seta de lista suspensa do botão de divisão.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles que têm o estilo BS_SPLITBUTTON ou BS_DEFSPLITBUTTON do botão.  
  
 Um glifo é a representação física de um caractere em uma fonte específica. O *chGlyph* parâmetro não é usado como o glifo, mas em vez disso, é usado para selecionar um glifo de um conjunto de glifos definida pelo sistema. O glifo de seta padrão é especificado por um caractere '6' e se parece com o caractere Unicode (U + 25BC) de triângulo preto para baixo APONTANDO.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_GLYPH e o `himlGlyph` membro com o *chGlyph* parâmetro e, em seguida, envia que estrutura na [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no SDK do Windows.  
  
##  <a name="setsplitimagelist"></a>  CButton::SetSplitImageList  
 Associa um [lista de imagens](../../mfc/reference/cimagelist-class.md) com o controle de botão de divisão atual.  
  
```  
BOOL SetSplitImageList(CImageList* pSplitImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*pSplitImageList*|[in] Ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto a ser atribuído ao controle de botão de divisão atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_IMAGE e o `himlGlyph` membro com o *pSplitImageList* parâmetro e, em seguida, envia Essa estrutura na [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no SDK do Windows.  
  
##  <a name="setsplitinfo"></a>  CButton::SetSplitInfo  
 Especifica os parâmetros que determinam como o Windows desenha o controle de botão de divisão atual.  
  
```  
BOOL SetSplitInfo(PBUTTON_SPLITINFO pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*pInfo*|[in] Ponteiro para um [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura que define o controle de botão de divisão atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Esse método envia o [BCM_SETSPLITINFO](/windows/desktop/Controls/bcm-setsplitinfo) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir altera o glifo de que é usado para a seta de lista suspensa do botão de divisão. O exemplo substitui um glifo de triângulo que aponta para cima para o glifo de triângulo para baixo do padrão. O glifo exibido depende do caractere que você especificar na `himlGlyph` membro o `BUTTON_SPLITINFO` estrutura. O glifo de triângulo para baixo é especificado por um caractere ' 6 'e o glifo de triângulo que aponta para cima é especificado por um caractere ' 5'. Para comparação, consulte o método de conveniência [CButton::SetSplitGlyph](#setsplitglyph).  
  
 [!code-cpp[NVC_MFC_CButton_s1#4](../../mfc/reference/codesnippet/cpp/cbutton-class_13.cpp)]  
  
##  <a name="setsplitsize"></a>  CButton::SetSplitSize  
 Define o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.  
  
```  
BOOL SetSplitSize(LPSIZE pSize);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*pSize*|[in] Ponteiro para um [tamanho](https://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que descreve um retângulo delimitador.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Quando o controle de botão de divisão for expandido, ele pode exibir um componente de lista suspensa, como um controle de lista ou um controle de paginação. Esse método Especifica o tamanho do retângulo delimitador que contém o componente de lista suspensa.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_SIZE e o `size` membro com o *pSize* parâmetro e, em seguida, envia a estrutura no [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir dobra o tamanho da seta de lista suspensa de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#5](../../mfc/reference/codesnippet/cpp/cbutton-class_14.cpp)]  
  
##  <a name="setsplitstyle"></a>  CButton::SetSplitStyle  
 Define o estilo do controle de botão de divisão atual.  
  
```  
BOOL SetSplitStyle(UINT uSplitStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|*uSplitStyle*|[in] Uma combinação bit a bit dos estilos de botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro a [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Use esse método apenas com controles cujo estilo de botão é BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.  
  
 Os estilos de botão de divisão especificam o alinhamento, a taxa de proporção e o formato de gráfico com o qual o Windows desenha um ícone do botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro a [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura.  
  
 Esse método inicializa o `mask` membro de uma [BUTTON_SPLITINFO](/windows/desktop/api/commctrl/ns-commctrl-tagbutton_splitinfo) estrutura com o sinalizador BCSIF_STYLE e o `uSplitStyle` membro com o *uSplitStyle* parâmetro e, em seguida, envia que estrutura na [muito](/windows/desktop/Controls/bcm-getsplitinfo) mensagem que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o estilo da seta de lista suspensa de botão de divisão. O estilo BCSS_ALIGNLEFT exibe na seta à esquerda do botão, e o estilo BCSS_STRETCH mantém proporções da seta do menu suspenso quando você redimensiona o botão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#3](../../mfc/reference/codesnippet/cpp/cbutton-class_15.cpp)]  
  
##  <a name="setstate"></a>  CButton::SetState  
 Define se um controle de botão está realçado ou não.  
  
```  
void SetState(BOOL bHighlight);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bHighlight*  
 Especifica se o botão deve ser realçada. Um valor diferente de zero realça o botão; um valor 0 remove qualquer realce.  
  
### <a name="remarks"></a>Comentários  
 Realce afeta a parte externa de um controle de botão. Ele não tem nenhum efeito sobre o estado de seleção de um botão de opção ou a caixa de seleção.  
  
 Um controle de botão será realçado automaticamente quando o usuário clica e mantém o botão esquerdo do mouse. O realce é removido quando o usuário libera o botão do mouse.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]  
  
##  <a name="settextmargin"></a>  CButton::SetTextMargin  
 Chame esse método para definir a margem de texto do `CButton` objeto.  
  
```  
BOOL SetTextMargin(RECT* pmargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pmargin*  
 Um ponteiro para a nova margem de texto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro em caso de êxito, FALSE em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro emula a funcionalidade da mensagem BCM_SETTEXTMARGIN, conforme descrito na [botões](https://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe CStatic](../../mfc/reference/cstatic-class.md)   
 [Classe CBitmapButton](../../mfc/reference/cbitmapbutton-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)
