---
title: Classe CButton
ms.date: 11/04/2016
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
ms.openlocfilehash: 669bdb18e378c4dc39bdc6d51ca1ebe7f93fa839
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79418828"
---
# <a name="cbutton-class"></a>Classe CButton

Fornece a funcionalidade dos controles de botão do Windows.

## <a name="syntax"></a>Sintaxe

```
class CButton : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CButton::CButton](#cbutton)|Constrói um objeto `CButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CButton:: criar](#create)|Cria o controle de botão do Windows e o anexa ao objeto `CButton`.|
|[CButton::D rawItem](#drawitem)|Substitua para desenhar um objeto de `CButton` desenhado pelo proprietário.|
|[CButton:: getbitmap](#getbitmap)|Recupera o identificador do bitmap definido anteriormente com [SetBitmap](#setbitmap).|
|[CButton:: GetButtonStyle](#getbuttonstyle)|Recupera informações sobre o estilo de controle de botão.|
|[CButton:: getcheck](#getcheck)|Recupera o estado de verificação de um controle de botão.|
|[CButton:: getCursor](#getcursor)|Recupera o identificador da imagem de cursor definida anteriormente com [SetCursor](#setcursor).|
|[CButton:: GetIcon](#geticon)|Recupera o identificador do ícone definido anteriormente com [SetIcon](#seticon).|
|[CButton::GetIdealSize](#getidealsize)|Recupera o tamanho ideal do controle de botão.|
|[CButton:: GetImageList](#getimagelist)|Recupera a lista de imagens do controle de botão.|
|[CButton:: getnote](#getnote)|Recupera o componente de observação do controle de link de comando atual.|
|[CButton::GetNoteLength](#getnotelength)|Recupera o comprimento do texto da nota para o controle de link de comando atual.|
|[CButton::GetSplitGlyph](#getsplitglyph)|Recupera o glifo associado ao controle do botão de divisão atual.|
|[CButton::GetSplitImageList](#getsplitimagelist)|Recupera a lista de imagens do controle do botão de divisão atual.|
|[CButton::GetSplitInfo](#getsplitinfo)|Recupera informações que definem o controle do botão de divisão atual.|
|[CButton::GetSplitSize](#getsplitsize)|Recupera o retângulo delimitador do componente suspenso do controle do botão de divisão atual.|
|[CButton:: getsplitstyle](#getsplitstyle)|Recupera os estilos do botão de divisão que definem o controle do botão de divisão atual.|
|[CButton:: GetState](#getstate)|Recupera o estado de verificação, o estado de realce e o estado de foco de um controle de botão.|
|[CButton::GetTextMargin](#gettextmargin)|Recupera a margem de texto do controle de botão.|
|[CButton:: SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no botão.|
|[CButton:: SetButtonStyle](#setbuttonstyle)|Altera o estilo de um botão.|
|[CButton:: SetCheck](#setcheck)|Define o estado de verificação de um controle de botão.|
|[CButton:: SetCursor](#setcursor)|Especifica uma imagem de cursor a ser exibida no botão.|
|[CButton:: setdropdownstate](#setdropdownstate)|Define o estado suspenso do controle do botão de divisão atual.|
|[CButton:: SetIcon](#seticon)|Especifica um ícone a ser exibido no botão.|
|[CButton:: SetImageList](#setimagelist)|Define a lista de imagens do controle de botão.|
|[CButton:: setobservação](#setnote)|Define a observação no controle de link de comando atual.|
|[CButton::SetSplitGlyph](#setsplitglyph)|Associa um glifo especificado ao controle do botão de divisão atual.|
|[CButton::SetSplitImageList](#setsplitimagelist)|Associa uma lista de imagens ao controle do botão de divisão atual.|
|[CButton::SetSplitInfo](#setsplitinfo)|Especifica informações que definem o controle do botão de divisão atual.|
|[CButton::SetSplitSize](#setsplitsize)|Define o retângulo delimitador do componente suspenso do controle do botão de divisão atual.|
|[CButton:: setdivisãostyle](#setsplitstyle)|Define o estilo do controle do botão de divisão atual.|
|[CButton:: SetState](#setstate)|Define o estado de realce de um controle de botão.|
|[CButton::SetTextMargin](#settextmargin)|Define a margem de texto do controle de botão.|

## <a name="remarks"></a>Comentários

Um controle de botão é uma janela filho pequena e retangular que pode ser clicada e desativada. Os botões podem ser usados sozinhos ou em grupos e podem ser rotulados ou exibidos sem texto. Normalmente, um botão altera a aparência quando o usuário clica nele.

Os botões típicos são a caixa de seleção, o botão de opção e a pressão. Um objeto `CButton` pode se tornar qualquer um deles, de acordo com o [estilo de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) especificado em sua inicialização pela função [criar](#create) membro.

Além disso, a classe [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md) derivada de `CButton` dá suporte à criação de controles de botão rotulados com imagens de bitmap em vez de texto. Um `CBitmapButton` pode ter bitmaps separados para os Estados de um botão para cima, para baixo, com foco e desabilitado.

Você pode criar um controle de botão a partir de um modelo de caixa de diálogo ou diretamente no seu código. Em ambos os casos, primeiro chame o Construtor `CButton` para construir o objeto `CButton`; em seguida, chame a função de membro `Create` para criar o controle de botão do Windows e anexá-lo ao objeto `CButton`.

A construção pode ser um processo de uma etapa em uma classe derivada de `CButton`. Escreva um construtor para a classe derivada e chame `Create` de dentro do construtor.

Se você quiser manipular mensagens de notificação do Windows enviadas por um controle de botão para seu pai (geralmente uma classe derivada de [CDialog](../../mfc/reference/cdialog-class.md)), adicione uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

**Na notificação de\_** **(** _ID_, _memberFxn_ **)**

onde *ID* especifica a ID da janela filho do controle que envia a notificação e *memberFxn* é o nome da função de membro pai que você escreveu para manipular a notificação.

O protótipo de função do pai é o seguinte:

`afx_msg void memberFxn();`

As entradas de mapa de mensagens em potencial são as seguintes:

|Entrada de mapa|Enviado ao pai quando...|
|---------------|----------------------------|
|ON_BN_CLICKED|O usuário clica em um botão.|
|ON_BN_DOUBLECLICKED|O usuário clica duas vezes em um botão.|

Se você criar um objeto de `CButton` de um recurso de caixa de diálogo, o objeto de `CButton` será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um objeto de `CButton` dentro de uma janela, talvez seja necessário destruí-lo. Se você criar o objeto `CButton` no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando o usuário fechar o controle de botão do Windows. Se você criar o objeto de `CButton` na pilha ou ele estiver inserido no objeto de caixa de diálogo pai, ele será destruído automaticamente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cbutton"></a>CButton::CButton

Constrói um objeto `CButton`.

```
CButton();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#1](../../mfc/reference/codesnippet/cpp/cbutton-class_1.cpp)]

##  <a name="create"></a>CButton:: criar

Cria o controle de botão do Windows e o anexa ao objeto `CButton`.

```
virtual BOOL Create(
    LPCTSTR lpszCaption,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>parâmetros

*lpszCaption*<br/>
Especifica o texto do controle de botão.

*dwStyle*<br/>
Especifica o estilo do controle de botão. Aplique qualquer combinação de [estilos de botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) ao botão.

*Rect*<br/>
Especifica o tamanho e a posição do controle de botão. Pode ser um objeto `CRect` ou uma estrutura de `RECT`.

*pParentWnd*<br/>
Especifica a janela pai do controle de botão, geralmente um `CDialog`. Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de botão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um objeto `CButton` em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de botão do Windows e o anexa ao objeto `CButton`.

Se o estilo de WS_VISIBLE for fornecido, o Windows enviará o controle de botão todas as mensagens necessárias para ativar e mostrar o botão.

Aplique os seguintes [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de botão:

- WS_CHILD sempre

- Geralmente WS_VISIBLE

- WS_DISABLED raramente

- WS_GROUP a controles de grupo

- WS_TABSTOP incluir o botão na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#2](../../mfc/reference/codesnippet/cpp/cbutton-class_2.cpp)]

##  <a name="drawitem"></a>CButton::D rawItem

Chamado pelo Framework quando um aspecto visual de um botão desenhado pelo proprietário foi alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>parâmetros

*lpDrawItemStruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT](/windows/win32/api/winuser/ns-winuser-drawitemstruct) . A estrutura contém informações sobre o item a ser desenhado e o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Um botão desenhado pelo proprietário tem o estilo de BS_OWNERDRAW definido. Substitua essa função de membro para implementar o desenho de um objeto de `CButton` desenhado pelo proprietário. O aplicativo deve restaurar todos os objetos da interface de dispositivo de gráficos (GDI) selecionados para o contexto de exibição fornecido em *lpDrawItemStruct* antes que a função de membro seja encerrada.

Consulte também os valores de estilo de [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#3](../../mfc/reference/codesnippet/cpp/cbutton-class_3.cpp)]

##  <a name="getbitmap"></a>CButton:: getbitmap

Chame essa função de membro para obter o identificador de um bitmap, definido anteriormente com [SetBitmap](#setbitmap), que está associado a um botão.

```
HBITMAP GetBitmap() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para um bitmap. NULL se nenhum bitmap for especificado anteriormente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]

##  <a name="getbuttonstyle"></a>CButton:: GetButtonStyle

Recupera informações sobre o estilo de controle de botão.

```
UINT GetButtonStyle() const;
```

### <a name="return-value"></a>Valor retornado

Retorna os estilos de botão para este `CButton` objeto. Essa função retorna apenas os valores de estilo [BS_](../../mfc/reference/styles-used-by-mfc.md#button-styles) , não qualquer um dos outros estilos de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]

##  <a name="getcheck"></a>CButton:: getcheck

Recupera o estado de verificação de um botão de opção ou caixa de seleção.

```
int GetCheck() const;
```

### <a name="return-value"></a>Valor retornado

O valor de retorno de um controle de botão criado com o BS_AUTOCHECKBOX, BS_AUTORADIOBUTTON, BS_AUTO3STATE, BS_CHECKBOX, BS_RADIOBUTTON ou BS_3STATE estilo é um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|BST_UNCHECKED|O estado do botão está desmarcado.|
|BST_CHECKED|O estado do botão está marcado.|
|BST_INDETERMINATE|O estado do botão é indeterminado (aplica-se somente se o botão tiver o BS_3STATE ou o estilo de BS_AUTO3STATE).|

Se o botão tiver qualquer outro estilo, o valor de retorno será BST_UNCHECKED.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]

##  <a name="getcursor"></a>CButton:: getCursor

Chame essa função de membro para obter o identificador de um cursor, anteriormente definido com [SetCursor](#setcursor), que está associado a um botão.

```
HCURSOR GetCursor();
```

### <a name="return-value"></a>Valor retornado

Um identificador para uma imagem de cursor. NULL se nenhum cursor for especificado anteriormente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]

##  <a name="geticon"></a>CButton:: GetIcon

Chame essa função de membro para obter o identificador de um ícone, definido anteriormente com [SetIcon](#seticon), que está associado a um botão.

```
HICON GetIcon() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para um ícone. NULL se nenhum ícone for especificado anteriormente.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]

##  <a name="getidealsize"></a>CButton::GetIdealSize

Recupera o tamanho ideal para o controle de botão.

```
BOOL GetIdealSize(SIZE* psize);
```

### <a name="parameters"></a>parâmetros

*psize*<br/>
Um ponteiro para o tamanho atual do botão.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da BCM_GETIDEALSIZE mensagem, conforme descrito na seção [botões](/windows/win32/controls/buttons) da SDK do Windows.

##  <a name="getimagelist"></a>CButton:: GetImageList

Chame esse método para obter a lista de imagens do controle de botão.

```
BOOL GetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```

### <a name="parameters"></a>parâmetros

*pbuttonImagelist*<br/>
Um ponteiro para a lista de imagens do objeto `CButton`.

### <a name="return-value"></a>Valor retornado

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da BCM_GETIMAGELIST mensagem, conforme descrito na seção [botões](/windows/win32/controls/buttons) da SDK do Windows.

##  <a name="getnote"></a>CButton:: getnote

Recupera o texto da nota associado ao controle de link de comando atual.

```
CString GetNote() const;

BOOL GetNote(
    LPTSTR lpszNote,
    UINT* cchNote) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpszNote*|fora Ponteiro para um buffer, que o chamador é responsável por alocar e desalocar. Se o valor de retorno for TRUE, o buffer conterá o texto de observação associado ao controle de link de comando atual; caso contrário, o buffer não será alterado.|
|*cchNote*|[entrada, saída] Um ponteiro para uma variável de inteiro sem sinal.<br /><br /> Quando esse método é chamado, a variável contém o tamanho do buffer especificado pelo parâmetro *lpszNote* .<br /><br /> Quando esse método retornar, se o valor de retorno for TRUE, a variável conterá o tamanho da nota associada ao controle de link de comando atual. Se o valor de retorno for FALSE, a variável conterá o tamanho do buffer necessário para conter a observação.|

### <a name="return-value"></a>Valor retornado

Na primeira sobrecarga, um objeto [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de observação associado ao controle de link de comando atual.

-ou-

Na segunda sobrecarga, TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Esse método envia a mensagem de [BCM_GETNOTE](/windows/win32/Controls/bcm-getnote) , que é descrita na SDK do Windows.

##  <a name="getnotelength"></a>CButton::GetNoteLength

Recupera o comprimento do texto da nota para o controle de link de comando atual.

```
UINT GetNoteLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do texto da nota, em caracteres Unicode de 16 bits, para o controle de link do comando atual.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Esse método envia a mensagem de [BCM_GETNOTELENGTH](/windows/win32/Controls/bcm-getnotelength) , que é descrita na SDK do Windows.

##  <a name="getsplitglyph"></a>CButton::GetSplitGlyph

Recupera o glifo associado ao controle do botão de divisão atual.

```
TCHAR GetSplitGlyph() const;
```

### <a name="return-value"></a>Valor retornado

O caractere de glifo associado ao controle do botão de divisão atual.

### <a name="remarks"></a>Comentários

Um glifo é a representação física de um caractere em uma fonte específica. Por exemplo, um controle de botão de divisão pode ser decorado com o glifo do caractere de marca de seleção Unicode (U + 2713).

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_GLYPH e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita na SDK do Windows. Quando a função Message retorna, esse método recupera o glifo do membro `himlGlyph` da estrutura.

##  <a name="getsplitimagelist"></a>CButton::GetSplitImageList

Recupera a [lista de imagens](../../mfc/reference/cimagelist-class.md) do controle do botão de divisão atual.

```
CImageList* GetSplitImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) .

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_IMAGE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita na SDK do Windows. Quando a função Message retorna, esse método recupera a lista de imagens do membro `himlGlyph` da estrutura.

##  <a name="getsplitinfo"></a>CButton::GetSplitInfo

Recupera parâmetros que determinam como o Windows desenha o controle do botão de divisão atual.

```
BOOL GetSplitInfo(PBUTTON_SPLITINFO pInfo) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pInfo*|fora Ponteiro para uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) que recebe informações sobre o controle de botão de divisão atual. O chamador é responsável por alocar a estrutura.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Esse método envia a mensagem de [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) , que é descrita na SDK do Windows.

##  <a name="getsplitsize"></a>CButton::GetSplitSize

Recupera o retângulo delimitador do componente suspenso do controle do botão de divisão atual.

```
BOOL GetSplitSize(LPSIZE pSize) const;
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pSize*|fora Ponteiro para uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) que recebe a descrição de um retângulo.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Quando o controle do botão de divisão é expandido, ele pode exibir um componente suspenso, como um controle de lista ou um controle de pager. Esse método recupera o retângulo delimitador que contém o componente suspenso.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_SIZE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita na SDK do Windows. Quando a função Message retorna, esse método recupera o retângulo delimitador do membro `size` da estrutura.

##  <a name="getsplitstyle"></a>CButton:: getsplitstyle

Recupera os estilos do botão de divisão que definem o controle do botão de divisão atual.

```
UINT GetSplitStyle() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação de bits bit A de estilos de botão de divisão. Para obter mais informações, consulte o membro `uSplitStyle` da estrutura [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) .

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Os estilos do botão de divisão especificam o alinhamento, a taxa de proporção e o formato gráfico com o qual o Windows desenha um ícone de botão de divisão.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_STYLE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita na SDK do Windows. Quando a função Message retorna, esse método recupera os estilos do botão Split do membro `uSplitStyle` da estrutura.

##  <a name="getstate"></a>CButton:: GetState

Recupera o estado de um controle de botão.

```
UINT GetState() const;
```

### <a name="return-value"></a>Valor retornado

Um campo de bits que contém a combinação de valores que indicam o estado atual de um controle de botão. A tabela a seguir lista os valores possíveis.

|Estado do botão|Valor|DESCRIÇÃO|
|------------------|-----------|-----------------|
|BST_UNCHECKED|0x0000|O estado inicial.|
|BST_CHECKED|0x0001|O controle de botão está marcado.|
|BST_INDETERMINATE|0x0002|O estado é indeterminado (só possível quando o controle de botão tem três Estados).|
|BST_PUSHED|0x0004|O controle de botão é pressionado.|
|BST_FOCUS|0x0008|O controle de botão tem o foco.|

### <a name="remarks"></a>Comentários

Um controle de botão com o estilo de botão BS_3STATE ou BS_AUTO3STATE cria uma caixa de seleção que tem um terceiro estado chamado de estado indeterminado. O estado indeterminado indica que a caixa de seleção não está marcada nem desmarcada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]

##  <a name="gettextmargin"></a>CButton::GetTextMargin

Chame esse método para obter a margem de texto do objeto `CButton`.

```
BOOL GetTextMargin(RECT* pmargin);
```

### <a name="parameters"></a>parâmetros

*pmargin*<br/>
Um ponteiro para a margem de texto do objeto `CButton`.

### <a name="return-value"></a>Valor retornado

Retorna a margem do texto.

### <a name="remarks"></a>Comentários

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da BCM_GETTEXTMARGIN mensagem, conforme descrito na seção [botões](/windows/win32/controls/buttons) da SDK do Windows.

##  <a name="setbitmap"></a>CButton:: SetBitmap

Chame essa função de membro para associar um novo bitmap ao botão.

```
HBITMAP SetBitmap(HBITMAP hBitmap);
```

### <a name="parameters"></a>parâmetros

*hBitmap*<br/>
O identificador de um bitmap.

### <a name="return-value"></a>Valor retornado

O identificador de um bitmap associado anteriormente ao botão.

### <a name="remarks"></a>Comentários

O bitmap será colocado automaticamente na face do botão, centralizado por padrão. Se o bitmap for muito grande para o botão, ele será recortado em qualquer lado. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetBitmap` usa apenas um bitmap por botão. Quando o botão é pressionado, o bitmap parece deslocar para baixo e para a direita.

Você é responsável por liberar o bitmap quando terminar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]

##  <a name="setbuttonstyle"></a>CButton:: SetButtonStyle

Altera o estilo de um botão.

```
void SetButtonStyle(
    UINT nStyle,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>parâmetros

*nStyle*<br/>
Especifica o [estilo do botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

*bRedraw*<br/>
Especifica se o botão deve ser redesenhado. Um valor diferente de zero redesenha o botão. Um valor 0 não redesenha o botão. O botão é redesenhado por padrão.

### <a name="remarks"></a>Comentários

Use a função membro `GetButtonStyle` para recuperar o estilo do botão. A palavra de ordem inferior do estilo de botão completo é o estilo específico do botão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]

##  <a name="setcheck"></a>CButton:: SetCheck

Define ou redefine o estado de verificação de um botão de opção ou caixa de seleção.

```
void SetCheck(int nCheck);
```

### <a name="parameters"></a>parâmetros

*nVerifique*<br/>
Especifica o estado de verificação. Esse parâmetro pode ser um dos seguintes:

|Valor|Significado|
|-----------|-------------|
|BST_UNCHECKED|Defina o estado do botão como desmarcado.|
|BST_CHECKED|Defina o estado do botão como marcado.|
|BST_INDETERMINATE|Defina o estado do botão como indeterminado. Esse valor só poderá ser usado se o botão tiver o BS_3STATE ou o estilo de BS_AUTO3STATE.|

### <a name="remarks"></a>Comentários

Essa função de membro não tem nenhum efeito em uma supressão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]

##  <a name="setcursor"></a>CButton:: SetCursor

Chame essa função de membro para associar um novo cursor ao botão.

```
HCURSOR SetCursor(HCURSOR hCursor);
```

### <a name="parameters"></a>parâmetros

*hCursor*<br/>
O identificador de um cursor.

### <a name="return-value"></a>Valor retornado

O identificador de um cursor associado anteriormente ao botão.

### <a name="remarks"></a>Comentários

O cursor será colocado automaticamente na face do botão, centralizado por padrão. Se o cursor for muito grande para o botão, ele será recortado em qualquer lado. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetCursor` usa apenas um cursor de acordo com o botão. Quando o botão é pressionado, o cursor é exibido para deslocar para baixo e para a direita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]

##  <a name="setdropdownstate"></a>CButton:: setdropdownstate

Define o estado suspenso do controle do botão de divisão atual.

```
BOOL SetDropDownState(BOOL fDropDown);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*fDropDown*|no TRUE para definir BST_DROPDOWNPUSHED estado; caso contrário, FALSE.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um controle de botão de divisão tem um estilo de BS_SPLITBUTTON ou BS_DEFSPLITBUTTON e consiste em um botão e uma seta suspensa à direita. Para obter mais informações, consulte [estilos de botão](/windows/win32/Controls/button-styles). Normalmente, o estado suspenso é definido quando o usuário clica na seta suspensa. Use este método para definir o estado suspenso do controle de forma programática. A seta suspensa é desenhada como sombreada para indicar o estado.

Esse método envia a mensagem de [BCM_SETDROPDOWNSTATE](/windows/win32/Controls/bcm-setdropdownstate) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_splitButton*, que é usada para acessar programaticamente o controle do botão de divisão. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estado do controle do botão de divisão para indicar que a seta suspensa é enviada por push.

[!code-cpp[NVC_MFC_CButton_s1#6](../../mfc/reference/codesnippet/cpp/cbutton-class_11.cpp)]

##  <a name="setelevationrequired"></a>CButton::SetElevationRequired

Define o estado do controle do botão atual como `elevation required`, que é necessário para que o controle exiba um ícone de segurança elevada.

```
BOOL SetElevationRequired(BOOL fElevationRequired);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*fElevationRequired*|no TRUE para definir `elevation required` estado; caso contrário, FALSE.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se um botão ou controle de link de comando exigir permissão de segurança elevada para executar uma ação, defina o controle como `elevation required` estado. Subsequentemente, o Windows exibe o ícone de escudo do UAC (controle de conta de usuário) no controle. Para obter mais informações, consulte "controle de conta de usuário" no [msdn](https://go.microsoft.com/fwlink/p/?linkid=18507).

Esse método envia a mensagem de [BCM_SETSHIELD](/windows/win32/Controls/bcm-setshield) , que é descrita na SDK do Windows.

##  <a name="seticon"></a>CButton:: SetIcon

Chame essa função de membro para associar um novo ícone ao botão.

```
HICON SetIcon(HICON hIcon);
```

### <a name="parameters"></a>parâmetros

*hIcon*<br/>
O identificador de um ícone.

### <a name="return-value"></a>Valor retornado

O identificador de um ícone associado anteriormente ao botão.

### <a name="remarks"></a>Comentários

O ícone será colocado automaticamente na face do botão, centralizado por padrão. Se o ícone for muito grande para o botão, ele será recortado em qualquer lado. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário de [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que usa quatro bitmaps por botão, `SetIcon` usa apenas um ícone por botão. Quando o botão é pressionado, o ícone é exibido para deslocar para baixo e para a direita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]

##  <a name="setimagelist"></a>CButton:: SetImageList

Chame esse método para definir a lista de imagens do objeto `CButton`.

```
BOOL SetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```

### <a name="parameters"></a>parâmetros

*pbuttonImagelist*<br/>
Um ponteiro para a nova lista de imagens.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da BCM_SETIMAGELIST mensagem, conforme descrito na seção [botões](/windows/win32/controls/buttons) da SDK do Windows.

##  <a name="setnote"></a>CButton:: setobservação

Define o texto da nota para o controle de link de comando atual.

```
BOOL SetNote(LPCTSTR lpszNote);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*lpszNote*|no Ponteiro para uma cadeia de caracteres Unicode que é definida como o texto de nota para o controle de link de comando.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Esse método envia a mensagem de [BCM_SETNOTE](/windows/win32/Controls/bcm-setnote) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_cmdLink*, que é usada para acessar programaticamente o controle de link de comando. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o texto da nota para o controle de link de comando.

[!code-cpp[NVC_MFC_CButton_s1#7](../../mfc/reference/codesnippet/cpp/cbutton-class_12.cpp)]

##  <a name="setsplitglyph"></a>CButton::SetSplitGlyph

Associa um glifo especificado ao controle do botão de divisão atual.

```
BOOL SetSplitGlyph(TCHAR chGlyph);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*chGlyph*|no Um caractere que especifica o glifo a ser usado como a seta suspensa do botão de divisão.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles que tenham o estilo de botão BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Um glifo é a representação física de um caractere em uma fonte específica. O parâmetro *chGlyph* não é usado como glifo, mas, em vez disso, é usado para selecionar um glifo de um conjunto de glifos definidos pelo sistema. O glifo de seta suspensa padrão é especificado por um caractere ' 6 ' e se assemelha ao triângulo Unicode preto apontando para baixo (U + 25BC).

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_GLYPH e o membro `himlGlyph` com o parâmetro *chGlyph* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita na SDK do Windows.

##  <a name="setsplitimagelist"></a>CButton::SetSplitImageList

Associa uma [lista de imagens](../../mfc/reference/cimagelist-class.md) ao controle do botão de divisão atual.

```
BOOL SetSplitImageList(CImageList* pSplitImageList);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pSplitImageList*|no Ponteiro para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) para atribuir ao controle do botão de divisão atual.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_IMAGE e o membro `himlGlyph` com o parâmetro *pSplitImageList* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita na SDK do Windows.

##  <a name="setsplitinfo"></a>CButton::SetSplitInfo

Especifica os parâmetros que determinam como o Windows desenha o controle do botão de divisão atual.

```
BOOL SetSplitInfo(PBUTTON_SPLITINFO pInfo);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pInfo*|no Ponteiro para uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) que define o controle do botão de divisão atual.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Esse método envia a mensagem de [BCM_SETSPLITINFO](/windows/win32/Controls/bcm-setsplitinfo) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_splitButton`, que é usada para acessar programaticamente o controle do botão de divisão.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir altera o glifo usado para a seta suspensa do botão de divisão. O exemplo substitui um glifo de triângulo apontando para cima para o glifo de triângulo padrão apontando para baixo. O glifo exibido depende do caractere que você especifica no membro `himlGlyph` da estrutura `BUTTON_SPLITINFO`. O glifo de triângulo apontando para baixo é especificado por um caractere ' 6 ' e o glifo de triângulo apontando para cima é especificado por um caractere ' 5 '. Para comparação, consulte o método de conveniência, [CButton:: SetSplitGlyph](#setsplitglyph).

[!code-cpp[NVC_MFC_CButton_s1#4](../../mfc/reference/codesnippet/cpp/cbutton-class_13.cpp)]

##  <a name="setsplitsize"></a>CButton::SetSplitSize

Define o retângulo delimitador do componente suspenso do controle do botão de divisão atual.

```
BOOL SetSplitSize(LPSIZE pSize);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*pSize*|no Ponteiro para uma estrutura de [tamanho](/windows/win32/api/windef/ns-windef-size) que descreve um retângulo delimitador.|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Quando o controle do botão de divisão é expandido, ele pode exibir um componente suspenso, como um controle de lista ou um controle de pager. Esse método especifica o tamanho do retângulo delimitador que contém o componente suspenso.

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_SIZE e o membro `size` com o parâmetro *psize* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_splitButton`, que é usada para acessar programaticamente o controle do botão de divisão. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir duplica o tamanho da seta suspensa do botão de divisão.

[!code-cpp[NVC_MFC_CButton_s1#5](../../mfc/reference/codesnippet/cpp/cbutton-class_14.cpp)]

##  <a name="setsplitstyle"></a>CButton:: setdivisãostyle

Define o estilo do controle do botão de divisão atual.

```
BOOL SetSplitStyle(UINT uSplitStyle);
```

### <a name="parameters"></a>parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*uSplitStyle*|no Uma combinação de bits bit A de estilos de botão de divisão. Para obter mais informações, consulte o membro `uSplitStyle` da estrutura [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) .|

### <a name="return-value"></a>Valor retornado

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método somente com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Os estilos do botão de divisão especificam o alinhamento, a taxa de proporção e o formato gráfico com o qual o Windows desenha um ícone de botão de divisão. Para obter mais informações, consulte o membro `uSplitStyle` da estrutura [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) .

Esse método inicializa o membro `mask` de uma estrutura de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com o sinalizador BCSIF_STYLE e o membro `uSplitStyle` com o parâmetro *uSplitStyle* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, `m_splitButton`, que é usada para acessar programaticamente o controle do botão de divisão.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estilo da seta suspensa do botão de divisão. O estilo de BCSS_ALIGNLEFT exibe a seta no lado esquerdo do botão e o estilo de BCSS_STRETCH retém as proporções da seta suspensa quando você redimensiona o botão.

[!code-cpp[NVC_MFC_CButton_s1#3](../../mfc/reference/codesnippet/cpp/cbutton-class_15.cpp)]

##  <a name="setstate"></a>CButton:: SetState

Define se um controle de botão é realçado ou não.

```
void SetState(BOOL bHighlight);
```

### <a name="parameters"></a>parâmetros

*bHighlight*<br/>
Especifica se o botão deve ser realçado. Um valor diferente de zero realça o botão; um valor 0 remove qualquer realce.

### <a name="remarks"></a>Comentários

Realce afeta o exterior de um controle de botão. Ele não tem nenhum efeito no estado de verificação de um botão de opção ou caixa de seleção.

Um controle de botão é realçado automaticamente quando o usuário clica e mantém o botão esquerdo do mouse. O realce é removido quando o usuário libera o botão do mouse.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]

##  <a name="settextmargin"></a>CButton::SetTextMargin

Chame esse método para definir a margem de texto do objeto `CButton`.

```
BOOL SetTextMargin(RECT* pmargin);
```

### <a name="parameters"></a>parâmetros

*pmargin*<br/>
Um ponteiro para a nova margem de texto.

### <a name="return-value"></a>Valor retornado

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Essa função de membro emula a funcionalidade da BCM_SETTEXTMARGIN mensagem, conforme descrito na seção [botões](/windows/win32/controls/buttons) da SDK do Windows.

## <a name="see-also"></a>Confira também

[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Classe CComboBox](../../mfc/reference/ccombobox-class.md)<br/>
[Classe CEdit](../../mfc/reference/cedit-class.md)<br/>
[Classe CListBox](../../mfc/reference/clistbox-class.md)<br/>
[Classe CScrollBar](../../mfc/reference/cscrollbar-class.md)<br/>
[Classe CStatic](../../mfc/reference/cstatic-class.md)<br/>
[Classe CBitmapButton](../../mfc/reference/cbitmapbutton-class.md)<br/>
[Classe CDialog](../../mfc/reference/cdialog-class.md)
