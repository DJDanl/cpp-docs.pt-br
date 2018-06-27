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
ms.openlocfilehash: 5e232c363da4c9bbaf7e049551f9e2915671098c
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36957436"
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
|[CButton::Create](#create)|Cria o controle de botão do Windows e a anexa ao `CButton` objeto.|  
|[CButton::DrawItem](#drawitem)|Substituição para desenhar um desenho proprietário `CButton` objeto.|  
|[CButton::GetBitmap](#getbitmap)|Recupera o identificador do bitmap definido anteriormente com [SetBitmap](#setbitmap).|  
|[CButton::GetButtonStyle](#getbuttonstyle)|Recupera informações sobre o estilo de controle de botão.|  
|[CButton::GetCheck](#getcheck)|Recupera o estado de seleção de um controle de botão.|  
|[CButton::GetCursor](#getcursor)|Recupera o identificador da imagem do cursor definido anteriormente com [SetCursor](#setcursor).|  
|[CButton::GetIcon](#geticon)|Recupera o identificador do ícone definido anteriormente com [SetIcon](#seticon).|  
|[CButton::GetIdealSize](#getidealsize)|Recupera o tamanho ideal do controle de botão.|  
|[CButton::GetImageList](#getimagelist)|Recupera a lista de imagens de controle de botão.|  
|[CButton::GetNote](#getnote)|Recupera o componente de observação do controle de link de comando atual.|  
|[CButton::GetNoteLength](#getnotelength)|Recupera o comprimento do texto de anotação para o controle de link do comando atual.|  
|[CButton::GetSplitGlyph](#getsplitglyph)|Recupera o glifo associado ao controle de botão de divisão atual.|  
|[CButton::GetSplitImageList](#getsplitimagelist)|Recupera a lista de imagens para o controle de botão de divisão atual.|  
|[CButton::GetSplitInfo](#getsplitinfo)|Recupera as informações que definem o controle de botão de divisão atual.|  
|[CButton::GetSplitSize](#getsplitsize)|Recupera o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.|  
|[CButton::GetSplitStyle](#getsplitstyle)|Recupera os estilos de botão de divisão que definem o controle de botão de divisão atual.|  
|[CButton::GetState](#getstate)|Recupera o estado de seleção, o estado de realce e o estado de foco de um controle de botão.|  
|[CButton::GetTextMargin](#gettextmargin)|Recupera a margem de texto do controle de botão.|  
|[CButton::SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no botão.|  
|[CButton::SetButtonStyle](#setbuttonstyle)|Altera o estilo de um botão.|  
|[CButton::SetCheck](#setcheck)|Define o estado de seleção de um controle de botão.|  
|[CButton::SetCursor](#setcursor)|Especifica uma imagem de cursor a ser exibido no botão.|  
|[CButton::SetDropDownState](#setdropdownstate)|Define o estado suspenso do controle de botão de divisão atual.|  
|[CButton::SetIcon](#seticon)|Especifica um ícone a ser exibido no botão.|  
|[CButton::SetImageList](#setimagelist)|Define a lista de imagens de controle de botão.|  
|[CButton::SetNote](#setnote)|Define a observação sobre o controle de link de comando atual.|  
|[CButton::SetSplitGlyph](#setsplitglyph)|Associa um glifo especificado com o controle de botão de divisão atual.|  
|[CButton::SetSplitImageList](#setsplitimagelist)|Associa uma lista de imagens com o controle de botão de divisão atual.|  
|[CButton::SetSplitInfo](#setsplitinfo)|Especifica as informações que definem o controle de botão de divisão atual.|  
|[CButton::SetSplitSize](#setsplitsize)|Define o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.|  
|[CButton::SetSplitStyle](#setsplitstyle)|Define o estilo do controle de botão de divisão atual.|  
|[CButton::SetState](#setstate)|Define o estado de realce de um controle de botão.|  
|[CButton::SetTextMargin](#settextmargin)|Define a margem de texto do controle de botão.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de botão é uma janela filho pequeno, retangular que pode ser clicada e desativar. Botões podem ser usados sozinha ou em grupos e ou podem ser rotulados ou aparecem sem texto. Um botão normalmente altera a aparência quando o usuário clica neles.  
  
 Botões típicos são a caixa de seleção, um botão de opção e um botão de ação. Um `CButton` objeto pode tornar-se qualquer uma dessas opções, de acordo com o [estilo do botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) especificado na sua inicialização pelo [criar](#create) função de membro.  
  
 Além disso, o [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md) classe derivada de `CButton` oferece suporte à criação de controles de botão rotulado com imagens de bitmap em vez de texto. Um `CBitmapButton` pode ter bitmaps separados para um botão do, para baixo, com foco e desabilitados estados.  
  
 Você pode criar um controle de botão de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, chame o construtor `CButton` para construir o `CButton` objeto; em seguida, chame o `Create` controle de botão de função de membro para criar o Windows e anexá-lo para o `CButton` objeto.  
  
 Construção pode ser um processo de uma etapa em uma classe derivada de `CButton`. Escrever um construtor para a classe derivada e chamada `Create` de dentro do construtor.  
  
 Se você desejar tratar mensagens de notificação do Windows enviadas por um controle de botão para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicionar uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.  
  
 Cada entrada de mapa de mensagem assume o seguinte formato:  
  
 **On _** notificação **(**`id`, `memberFxn` **)**  
  
 onde `id` Especifica a ID de janela filho do controle que está enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.  
  
 O protótipo de função do pai é o seguinte:  
  
 **afx_msg** `void` `memberFxn` **();**  
  
 Entradas de mapa de mensagem possíveis são as seguintes:  
  
|Entrada de mapa|Enviado para o pai quando...|  
|---------------|----------------------------|  
|**ON_BN_CLICKED**|O usuário clica em um botão.|  
|**ON_BN_DOUBLECLICKED**|O usuário clica duas vezes em um botão.|  
  
 Se você criar um `CButton` objeto a partir de um recurso de caixa de diálogo, o `CButton` objeto é destruído automaticamente quando o usuário fecha a caixa de diálogo.  
  
 Se você criar um `CButton` objeto dentro de uma janela, talvez você precise destruída. Se você criar o `CButton` objeto na pilha usando o **novo** função, você deve chamar **excluir** sobre o objeto a ser destruída quando o usuário fecha o Windows controle de botão. Se você criar o `CButton` objeto na pilha, ou ele está incorporado no objeto de caixa de diálogo pai, ele será destruído automaticamente.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CButton`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cbutton"></a>  CButton::CButton  
 Constrói um objeto `CButton`.  
  
```  
CButton();
```  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#1](../../mfc/reference/codesnippet/cpp/cbutton-class_1.cpp)]  
  
##  <a name="create"></a>  CButton::Create  
 Cria o controle de botão do Windows e a anexa ao `CButton` objeto.  
  
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
 Especifica o estilo do controle de botão. Aplique qualquer combinação de [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) ao botão.  
  
 *Rect*  
 Especifica o tamanho e a posição do controle de botão. Ele pode ser um `CRect` objeto ou um `RECT` estrutura.  
  
 *pParentWnd*  
 Especifica a janela do pai do controle button, geralmente um `CDialog`. Ele não deve ser **nulo**.  
  
 *nID*  
 Especifica a identificação. do controle de botão  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você pode criar um `CButton` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chamar `Create`, que cria o controle de botão do Windows e a anexa ao `CButton` objeto.  
  
 Se o **WS_VISIBLE** estilo for fornecido, o Windows envia o controle de botão de todas as mensagens necessárias para ativar e mostrar o botão.  
  
 Aplicar o seguinte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de botão:  
  
- **Estilo** sempre  
  
- **WS_VISIBLE** normalmente  
  
- **WS_DISABLED** raramente  
  
- **WS_GROUP** a controles de grupo  
  
- **WS_TABSTOP** para incluir o botão na ordem de tabulação  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#2](../../mfc/reference/codesnippet/cpp/cbutton-class_2.cpp)]  
  
##  <a name="drawitem"></a>  CButton::DrawItem  
 Chamado pelo framework quando um aspecto visual de um botão de desenho proprietário é alterado.  
  
```  
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpDrawItemStruct*  
 Um ponteiro de tempo para um [DRAWITEMSTRUCT](../../mfc/reference/drawitemstruct-structure.md) estrutura. A estrutura contém informações sobre o item a ser desenhada e o tipo de desenho necessárias.  
  
### <a name="remarks"></a>Comentários  
 Um botão de desenho proprietário tem o **BS_OWNERDRAW** conjunto de estilos. Substituir essa função de membro para implementar o desenho de um desenho proprietário `CButton` objeto. O aplicativo deve restaurar todos os objetos de interface (GDI) do dispositivo gráficos selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes do membro da função será encerrado.  
  
 Consulte também o [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) valores de estilo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#3](../../mfc/reference/codesnippet/cpp/cbutton-class_3.cpp)]  
  
##  <a name="getbitmap"></a>  CButton::GetBitmap  
 Chamar essa função de membro para obter o identificador de um bitmap, definido anteriormente com [SetBitmap](#setbitmap), que é associado a um botão.  
  
```  
HBITMAP GetBitmap() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um bitmap. **NULO** se nenhum bitmap é especificado anteriormente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]  
  
##  <a name="getbuttonstyle"></a>  CButton::GetButtonStyle  
 Recupera informações sobre o estilo de controle de botão.  
  
```  
UINT GetButtonStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna os estilos de botão para este `CButton` objeto. Essa função retorna apenas o [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) valores de estilo, não os outros estilos de janela.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]  
  
##  <a name="getcheck"></a>  CButton::GetCheck  
 Recupera o estado de seleção de um botão de opção ou a caixa de seleção.  
  
```  
int GetCheck() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor de retorno de um controle de botão criado com o **BS_AUTOCHECKBOX**, **BS_AUTORADIOBUTTON**, **BS_AUTO3STATE**, **BS_CHECKBOX**, **BS_RADIOBUTTON**, ou **BS_3STATE** estilo é um dos seguintes valores:  
  
|Valor|Significado|  
|-----------|-------------|  
|**BST_UNCHECKED**|Estado do botão é desmarcado.|  
|**BST_CHECKED**|Estado do botão é verificado.|  
|**BST_INDETERMINATE**|Estado do botão é indeterminado (aplica-se apenas se o botão tiver o **BS_3STATE** ou **BS_AUTO3STATE** estilo).|  
  
 Se o botão tiver qualquer outro estilo, o valor de retorno é **BST_UNCHECKED**.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]  
  
##  <a name="getcursor"></a>  CButton::GetCursor  
 Chamar essa função de membro para obter o identificador de um cursor, definido anteriormente com [SetCursor](#setcursor), que é associado a um botão.  
  
```  
HCURSOR GetCursor();  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para uma imagem do cursor. **NULO** se nenhum cursor é especificado anteriormente.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]  
  
##  <a name="geticon"></a>  CButton::GetIcon  
 Chamar essa função de membro para obter o identificador de um ícone definido anteriormente com [SetIcon](#seticon), que é associado a um botão.  
  
```  
HICON GetIcon() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um ícone. **NULO** se nenhum ícone for especificado anteriormente.  
  
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
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do **BCM_GETIDEALSIZE** mensagem, conforme descrito no [botões](http://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="getimagelist"></a>  CButton::GetImageList  
 Chame este método para obter a lista de imagens de controle de botão.  
  
```  
BOOL GetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbuttonImagelist*  
 Um ponteiro para a lista de imagens do `CButton` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do **BCM_GETIMAGELIST** mensagem, conforme descrito no [botões](http://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="getnote"></a>  CButton::GetNote  
 Recupera o texto associado ao controle de link do comando atual.  
  
```  
CString GetNote() const;  
  
BOOL GetNote(
    LPTSTR lpszNote,   
    UINT* cchNote) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] *lpszNote*|Ponteiro para um buffer, que o chamador é responsável por alocando e desalocando. Se o valor de retorno é `true`, o buffer contém o texto de anotação que é associado com o controle de link do comando atual; caso contrário, o buffer é alterado.|  
|[out no] *cchNote*|Um ponteiro para uma variável de inteiro não assinado.<br /><br /> Quando este método é chamado, a variável contém o tamanho do buffer especificado pelo *lpszNote* parâmetro.<br /><br /> Quando esse método retorna, se o valor de retorno é `true` a variável contém o tamanho da anotação associada ao controle de link do comando atual. Se o valor de retorno é `false`, a variável contém o tamanho do buffer necessário para conter a anotação.|  
  
### <a name="return-value"></a>Valor de retorno  
 Na primeira sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) objeto que contém o texto associado ao controle de link do comando atual.  
  
 -ou-  
  
 Na segunda sobrecarga, `true` se esse método for bem-sucedida; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_COMMANDLINK` ou `BS_DEFCOMMANDLINK`.  
  
 Esse método envia o [BCM_GETNOTE](http://msdn.microsoft.com/library/windows/desktop/bb775965) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getnotelength"></a>  CButton::GetNoteLength  
 Recupera o comprimento do texto de anotação para o controle de link do comando atual.  
  
```  
UINT GetNoteLength() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O comprimento do texto de observação, em caracteres de Unicode de 16 bits para o controle de link do comando atual.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_COMMANDLINK` ou `BS_DEFCOMMANDLINK`.  
  
 Esse método envia o [BCM_GETNOTELENGTH](http://msdn.microsoft.com/library/windows/desktop/bb775967) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getsplitglyph"></a>  CButton::GetSplitGlyph  
 Recupera o glifo associado ao controle de botão de divisão atual.  
  
```  
TCHAR GetSplitGlyph() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O caractere de glifo associado ao controle de botão de divisão atual.  
  
### <a name="remarks"></a>Comentários  
 Um glifo é a representação física de um caractere em uma determinada fonte. Por exemplo, um controle de botão de divisão pode ser decorado com o símbolo do caractere Unicode de marca de seleção (U + 2713).  
  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_GLYPH` sinalizador e, em seguida, envia a estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem descrita no SDK do Windows. Quando a função de mensagens retorna, esse método recupera o glifo do `himlGlyph` membro da estrutura.  
  
##  <a name="getsplitimagelist"></a>  CButton::GetSplitImageList  
 Recupera o [lista de imagens](../../mfc/reference/cimagelist-class.md) para o controle de botão de divisão atual.  
  
```  
CImageList* GetSplitImageList() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_IMAGE` sinalizador e, em seguida, envia a estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem descrita no SDK do Windows. Quando a função de mensagens retorna, esse método recupera a lista de imagens do `himlGlyph` membro da estrutura.  
  
##  <a name="getsplitinfo"></a>  CButton::GetSplitInfo  
 Recupera os parâmetros que determinam como o Windows desenha o controle de botão de divisão atual.  
  
```  
BOOL GetSplitInfo(PBUTTON_SPLITINFO pInfo) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] *pInfo*|Ponteiro para um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura que recebe informações sobre o controle de botão de divisão atual. O chamador é responsável para alocar a estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Esse método envia o [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="getsplitsize"></a>  CButton::GetSplitSize  
 Recupera o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.  
  
```  
BOOL GetSplitSize(LPSIZE pSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[out] *pSize*|Ponteiro para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que recebe a descrição de um retângulo.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Quando o controle de botão de divisão é expandido, ele pode exibir um componente de lista suspensa como um controle de lista ou controle de pager. Esse método recupera o retângulo delimitador que contém o componente de lista suspensa.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_SIZE` sinalizador e, em seguida, envia a estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem descrita no SDK do Windows. Quando a função de mensagens retorna, esse método recupera o retângulo delimitador do `size` membro da estrutura.  
  
##  <a name="getsplitstyle"></a>  CButton::GetSplitStyle  
 Recupera os estilos de botão de divisão que definem o controle de botão de divisão atual.  
  
```  
UINT GetSplitStyle() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação bit a bit de estilos de botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro o [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Os estilos de botão de divisão especificam o alinhamento, a taxa de proporção e o formato gráfico com o qual o Windows desenha um ícone do botão de divisão.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_STYLE` sinalizador e, em seguida, envia a estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem descrita no SDK do Windows. Quando a função de mensagens retorna, esse método recupera os estilos de botão de divisão do `uSplitStyle` membro da estrutura.  
  
##  <a name="getstate"></a>  CButton::GetState  
 Recupera o estado de um controle de botão.  
  
```  
UINT GetState() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um campo de bits que contém a combinação de valores que indicam o estado atual de um controle de botão. A tabela a seguir lista os valores possíveis.  
  
|Estado do botão|Valor|Descrição|  
|------------------|-----------|-----------------|  
|`BST_UNCHECKED`|0x0000|O estado inicial.|  
|`BST_CHECKED`|0x0001|O controle de botão é verificado.|  
|`BST_INDETERMINATE`|0x0002|O estado indeterminado (só é possível quando o controle de botão tem três estados).|  
|`BST_PUSHED`|0x0004|O controle de botão é pressionado.|  
|`BST_FOCUS`|0x0008|O controle de botão tem o foco.|  
  
### <a name="remarks"></a>Comentários  
 Um controle de botão com o `BS_3STATE` ou `BS_AUTO3STATE` estilo do botão cria uma caixa de seleção que tem um estado de terceiro chamado o estado indeterminado. O estado indeterminado indica que a caixa de seleção é marcada, nem desmarcada.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]  
  
##  <a name="gettextmargin"></a>  CButton::GetTextMargin  
 Chame esse método para a margem de texto do `CButton` objeto.  
  
```  
BOOL GetTextMargin(RECT* pmargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pmargin*  
 Um ponteiro para a margem de texto do `CButton` objeto.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a margem de texto.  
  
### <a name="remarks"></a>Comentários  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do **BCM_GETTEXTMARGIN** mensagem, conforme descrito no [botões](http://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="setbitmap"></a>  CButton::SetBitmap  
 Chame essa função de membro para associar um novo bitmap com o botão.  
  
```  
HBITMAP SetBitmap(HBITMAP hBitmap);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hBitmap*  
 O identificador de um bitmap.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um bitmap anteriormente associado ao botão.  
  
### <a name="remarks"></a>Comentários  
 O bitmap será colocado automaticamente na face do botão, centralizado, por padrão. Se o bitmap for muito grande para o botão, ele será anexado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- **BS_TOP**  
  
- **BS_LEFT**  
  
- **BS_RIGHT**  
  
- **BS_CENTER**  
  
- **BS_BOTTOM**  
  
- **BS_VCENTER**  
  
 Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetBitmap` usa apenas um bitmap por botão. Quando o botão for pressionado, o bitmap é exibido Deslocar para baixo e para a direita.  
  
 Você é responsável pela liberação de bitmap quando tiver terminado com ele.  
  
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
 Use o `GetButtonStyle` função de membro para recuperar o estilo do botão. A palavra de ordem inferior do estilo do botão Concluir é o estilo do botão específicos.  
  
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
|**BST_UNCHECKED**|Defina o estado do botão como desmarcada.|  
|**BST_CHECKED**|Defina o estado do botão verificadas.|  
|**BST_INDETERMINATE**|Defina o estado do botão como indeterminado. Esse valor pode ser usado somente se o botão tem o **BS_3STATE** ou **BS_AUTO3STATE** estilo.|  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro não tem efeito em um botão de ação.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]  
  
##  <a name="setcursor"></a>  CButton::SetCursor  
 Chame essa função de membro para associar um cursor novo botão.  
  
```  
HCURSOR SetCursor(HCURSOR hCursor);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hCursor*  
 O identificador de um cursor.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um cursor anteriormente associado ao botão.  
  
### <a name="remarks"></a>Comentários  
 O cursor será colocado automaticamente na face do botão, centralizado, por padrão. Se o cursor for muito grande para o botão, ele será anexado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- **BS_TOP**  
  
- **BS_LEFT**  
  
- **BS_RIGHT**  
  
- **BS_CENTER**  
  
- **BS_BOTTOM**  
  
- **BS_VCENTER**  
  
 Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetCursor` usa apenas um cursor por botão. Quando o botão for pressionado, o cursor aparece para deslocar para baixo e para a direita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]  
  
##  <a name="setdropdownstate"></a>  CButton::SetDropDownState  
 Define o estado suspenso do controle de botão de divisão atual.  
  
```  
BOOL SetDropDownState(BOOL fDropDown);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *fDropDown*|`true` Para definir `BST_DROPDOWNPUSHED` estado; caso contrário, `false`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Um controle de botão de divisão tem um estilo de `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON` e consiste em um botão e uma seta suspensa à direita. Para obter mais informações, consulte [estilos de botão](http://msdn.microsoft.com/library/windows/desktop/bb775951). Normalmente, o estado suspenso é definido quando o usuário clica na seta suspensa. Use esse método para definir o estado suspenso do controle. A seta suspensa é desenhada sombreada para indicar o estado.  
  
 Esse método envia o [BCM_SETDROPDOWNSTATE](http://msdn.microsoft.com/library/windows/desktop/bb775973) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável, *m_splitButton*, que é usado para acessar programaticamente o controle de botão de divisão. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o estado do controle de botão de divisão para indicar que a seta suspensa é enviada.  
  
 [!code-cpp[NVC_MFC_CButton_s1#6](../../mfc/reference/codesnippet/cpp/cbutton-class_11.cpp)]  
  
##  <a name="setelevationrequired"></a>  CButton::SetElevationRequired  
 Define o estado do controle de botão atual para `elevation required`, que é necessário para o controle exibe um ícone de segurança com privilégios elevados.  
  
```  
BOOL SetElevationRequired(BOOL fElevationRequired);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `fElevationRequired`|`true` Para definir `elevation required` estado; caso contrário, `false`.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Se um controle de link do botão ou o comando requer a permissão de segurança com privilégios elevados para executar uma ação, configurar o controle `elevation required` estado. Subsequentemente, o Windows exibe o ícone de escudo de controle de conta de usuário (UAC) no controle. Para obter mais informações, consulte "Controle de conta de usuário" em [MSDN](http://go.microsoft.com/fwlink/p/?linkid=18507).  
  
 Esse método envia o [BCM_SETSHIELD](http://msdn.microsoft.com/library/windows/desktop/bb775979) mensagem, que é descrita no SDK do Windows.  
  
##  <a name="seticon"></a>  CButton::SetIcon  
 Chame essa função de membro para associar um novo ícone com o botão.  
  
```  
HICON SetIcon(HICON hIcon);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hIcon*  
 O identificador de um ícone.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador de um ícone anteriormente associado ao botão.  
  
### <a name="remarks"></a>Comentários  
 O ícone será colocado automaticamente na face do botão, centralizado, por padrão. Se o ícone é muito grande para o botão, ele será anexado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo o seguinte:  
  
- **BS_TOP**  
  
- **BS_LEFT**  
  
- **BS_RIGHT**  
  
- **BS_CENTER**  
  
- **BS_BOTTOM**  
  
- **BS_VCENTER**  
  
 Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetIcon` usa apenas um ícone por botão. Quando o botão for pressionado, o ícone é exibido Deslocar para baixo e para a direita.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]  
  
##  <a name="setimagelist"></a>  CButton::SetImageList  
 Chame este método para definir a lista de imagens do `CButton` objeto.  
  
```  
BOOL SetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbuttonImagelist*  
 Um ponteiro para a nova lista de imagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** em caso de sucesso, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do **BCM_SETIMAGELIST** mensagem, conforme descrito no [botões](http://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
##  <a name="setnote"></a>  CButton::SetNote  
 Define o texto de anotação para o controle de link do comando atual.  
  
```  
BOOL SetNote(LPCTSTR lpszNote);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *lpszNote*|Ponteiro para uma cadeia de caracteres Unicode que é definido como o texto de anotação para o controle de link de comando.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_COMMANDLINK` ou `BS_DEFCOMMANDLINK`.  
  
 Esse método envia o [BCM_SETNOTE](http://msdn.microsoft.com/library/windows/desktop/bb775977) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável, *m_cmdLink*, que é usado para acessar programaticamente o controle de link de comando. Essa variável é usada no exemplo a seguir.  
  
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
|[in] *chGlyph*|Um caractere que especifica o símbolo a ser usado como seta do menu suspenso de botão de divisão.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles que têm o estilo do botão `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Um glifo é a representação física de um caractere em uma determinada fonte. O *chGlyph* parâmetro não é usado como o símbolo, mas em vez disso, é usado para selecionar um glifo de um conjunto de glifos definidas pelo sistema. O símbolo de seta suspensa padrão é especificado por um caractere '6' e se parece com o caractere Unicode preto para baixo triângulo (U + 25BC).  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_GLYPH` sinalizador e o `himlGlyph` membro com o `chGlyph` parâmetro e, em seguida, envia o deestrutura[ Mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem que é descrita no SDK do Windows.  
  
##  <a name="setsplitimagelist"></a>  CButton::SetSplitImageList  
 Associa um [lista de imagens](../../mfc/reference/cimagelist-class.md) com o controle de botão de divisão atual.  
  
```  
BOOL SetSplitImageList(CImageList* pSplitImageList);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *pSplitImageList*|Ponteiro para um [CImageList](../../mfc/reference/cimagelist-class.md) objeto para atribuir o controle de botão de divisão atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_IMAGE` sinalizador e o `himlGlyph` membro com o *pSplitImageList* parâmetro e, em seguida, envia a estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem que é descrita no SDK do Windows.  
  
##  <a name="setsplitinfo"></a>  CButton::SetSplitInfo  
 Especifica os parâmetros que determinam como o Windows desenha o controle de botão de divisão atual.  
  
```  
BOOL SetSplitInfo(PBUTTON_SPLITINFO pInfo);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *pInfo*|Ponteiro para um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura que define o controle de botão de divisão atual.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Esse método envia o [BCM_SETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775981) mensagem, que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir altera o glifo que é usado a seta de lista suspensa do botão de divisão. O exemplo substitui um glifo de triângulo apontando para cima do glifo de triângulo para baixo do padrão. O glifo exibido depende do caractere que você especificar na `himlGlyph` membro o `BUTTON_SPLITINFO` estrutura. O símbolo de triângulo para baixo é especificado por um caractere ' 6 'e o símbolo de triângulo apontando para cima é especificado por um caractere ' 5'. Para comparação, consulte o método de conveniência, [CButton::SetSplitGlyph](#setsplitglyph).  
  
 [!code-cpp[NVC_MFC_CButton_s1#4](../../mfc/reference/codesnippet/cpp/cbutton-class_13.cpp)]  
  
##  <a name="setsplitsize"></a>  CButton::SetSplitSize  
 Define o retângulo delimitador do componente lista suspensa do controle de botão de divisão atual.  
  
```  
BOOL SetSplitSize(LPSIZE pSize);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *pSize*|Ponteiro para um [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura que descreve um retângulo delimitador.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Quando o controle de botão de divisão é expandido, ele pode exibir um componente de lista suspensa como um controle de lista ou controle de pager. Esse método Especifica o tamanho do retângulo delimitador que contém o componente de lista suspensa.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_SIZE` sinalizador e o `size` membro com o *pSize* parâmetro e, em seguida, envia que estrutura no [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão. Essa variável é usada no exemplo a seguir.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir dobra o tamanho da seta do menu suspenso de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#5](../../mfc/reference/codesnippet/cpp/cbutton-class_14.cpp)]  
  
##  <a name="setsplitstyle"></a>  CButton::SetSplitStyle  
 Define o estilo do controle de botão de divisão atual.  
  
```  
BOOL SetSplitStyle(UINT uSplitStyle);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *uSplitStyle*|Uma combinação bit a bit de estilos de botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro o [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` Se esse método for bem-sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente com controles cujo estilo do botão é `BS_SPLITBUTTON` ou `BS_DEFSPLITBUTTON`.  
  
 Os estilos de botão de divisão especificam o alinhamento, a taxa de proporção e o formato gráfico com o qual o Windows desenha um ícone do botão de divisão. Para obter mais informações, consulte o `uSplitStyle` membro o [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura.  
  
 Esse método inicializa o `mask` membro de um [BUTTON_SPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775955) estrutura com a `BCSIF_STYLE` sinalizador e o `uSplitStyle` membro com o *uSplitStyle* parâmetro e, em seguida, envia na estrutura de [mensagens BCM_GETSPLITINFO](http://msdn.microsoft.com/library/windows/desktop/bb775969) mensagem que é descrita no SDK do Windows.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define a variável `m_splitButton`, que é usado para acessar programaticamente o controle de botão de divisão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define o estilo de seta do menu suspenso de botão de divisão. O `BCSS_ALIGNLEFT` estilo exibe a seta à esquerda do botão e o `BCSS_STRETCH` estilo retém proporções da seta suspensa ao redimensionar o botão.  
  
 [!code-cpp[NVC_MFC_CButton_s1#3](../../mfc/reference/codesnippet/cpp/cbutton-class_15.cpp)]  
  
##  <a name="setstate"></a>  CButton::SetState  
 Define se um controle de botão é realçado ou não.  
  
```  
void SetState(BOOL bHighlight);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bHighlight*  
 Especifica se o botão deve ser realçado. Um valor diferente de zero destaques do botão. um valor 0 remove qualquer realce.  
  
### <a name="remarks"></a>Comentários  
 Realce afeta exterior de um controle de botão. Ele não tem nenhum efeito sobre o estado de seleção de um botão de opção ou a caixa de seleção.  
  
 Um controle de botão é realçado automaticamente quando o usuário clica e mantém o botão esquerdo do mouse. O realce será removido quando o usuário libera o botão do mouse.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]  
  
##  <a name="settextmargin"></a>  CButton::SetTextMargin  
 Chame este método para definir a margem de texto do `CButton` objeto.  
  
```  
BOOL SetTextMargin(RECT* pmargin);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pmargin*  
 Um ponteiro para a margem de texto novo.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna verdadeiro no caso de sucesso, falso em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro emula a funcionalidade do **BCM_SETTEXTMARGIN** mensagem, conforme descrito no [botões](http://msdn.microsoft.com/library/windows/desktop/bb775943) seção do SDK do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CComboBox](../../mfc/reference/ccombobox-class.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)   
 [Classe CListBox](../../mfc/reference/clistbox-class.md)   
 [Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)   
 [Classe CStatic](../../mfc/reference/cstatic-class.md)   
 [Classe CBitmapButton](../../mfc/reference/cbitmapbutton-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)
