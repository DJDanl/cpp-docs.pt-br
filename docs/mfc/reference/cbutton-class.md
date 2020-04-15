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
ms.openlocfilehash: 05ad60855cd03115cf88ab2b51e56e6a26822035
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352440"
---
# <a name="cbutton-class"></a>Classe CButton

Fornece a funcionalidade dos controles de botão do Windows.

## <a name="syntax"></a>Sintaxe

```
class CButton : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CButton::CButton](#cbutton)|Constrói um objeto `CButton`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CButton::Criar](#create)|Cria o controle do botão do `CButton` Windows e o anexa ao objeto.|
|[CButton::DrawItem](#drawitem)|Substituir para desenhar um `CButton` objeto desenhado pelo proprietário.|
|[CButton::GetBitmap](#getbitmap)|Recupera a alça do bitmap previamente definida com [SetBitmap](#setbitmap).|
|[CButton::GetButtonStyle](#getbuttonstyle)|Recupera informações sobre o estilo de controle do botão.|
|[CButton::GetCheck](#getcheck)|Recupera o estado de verificação de um controle de botão.|
|[CButton::GetCursor](#getcursor)|Recupera a alça da imagem do cursor previamente definida com [SetCursor](#setcursor).|
|[CButton::GetIcon](#geticon)|Recupera a alça do ícone previamente definido com [SetIcon](#seticon).|
|[Cbutton::GetIdealSize](#getidealsize)|Recupera o tamanho ideal do controle do botão.|
|[CButton::GetImageList](#getimagelist)|Recupera a lista de imagens do controle do botão.|
|[CButton::GetNote](#getnote)|Recupera o componente de nota do controle atual do link de comando.|
|[cbutton::getNoteLength](#getnotelength)|Recupera o comprimento do texto da nota para o controle atual do link de comando.|
|[CButton::GetSplitGliph](#getsplitglyph)|Recupera o glifo associado ao controle atual do botão split.|
|[cbutton::GetSplitImagelist](#getsplitimagelist)|Recupera a lista de imagens para o controle atual do botão dividido.|
|[cbutton::getSplitinfo](#getsplitinfo)|Recupera informações que definem o controle atual do botão split.|
|[CButton::GetSplitSize](#getsplitsize)|Recupera o retângulo delimitador do componente drop-down do controle atual do botão split.|
|[CButton::GetSplitStyle](#getsplitstyle)|Recupera os estilos de botão dividido que definem o controle atual do botão dividido.|
|[Cbutton::GetState](#getstate)|Recupera o estado de verificação, o estado de destaque e o estado de foco de um controle de botão.|
|[CButton::GetTextMargin](#gettextmargin)|Recupera a margem de texto do controle do botão.|
|[CButton::SetBitmap](#setbitmap)|Especifica um bitmap a ser exibido no botão.|
|[CButton::SetButtonEstilo de botão](#setbuttonstyle)|Muda o estilo de um botão.|
|[CButton::SetCheck](#setcheck)|Define o estado de verificação de um controle de botão.|
|[CButton::SetCursor](#setcursor)|Especifica uma imagem do cursor a ser exibida no botão.|
|[cbutton::setDropDownState](#setdropdownstate)|Define o estado de isto do controle atual do botão split.|
|[CButton::SetIcon](#seticon)|Especifica um ícone a ser exibido no botão.|
|[CButton::SetImageList](#setimagelist)|Define a lista de imagens do controle do botão.|
|[CButton::SetNote](#setnote)|Define a nota no controle atual do link de comando.|
|[CButton::SetSplitGlyph](#setsplitglyph)|Associa um glifo especificado com o controle atual do botão split.|
|[cbutton::SetSplitImagelist](#setsplitimagelist)|Associa uma lista de imagens com o controle atual do botão dividido.|
|[cbutton::SetSplitInfo](#setsplitinfo)|Especifica informações que definem o controle atual do botão split.|
|[cbutton::SetSplitSize](#setsplitsize)|Define o retângulo delimitador do componente drop-down do controle atual do botão split.|
|[cbutton::SetSplitStyle](#setsplitstyle)|Define o estilo do controle atual do botão dividido.|
|[cbutton::setState](#setstate)|Define o estado de destaque de um controle de botão.|
|[cbutton::SetTextMargin](#settextmargin)|Define a margem de texto do controle do botão.|

## <a name="remarks"></a>Comentários

Um controle de botão é uma pequena janela infantil retangular que pode ser clicada e desligada. Os botões podem ser usados sozinhos ou em grupos e podem ser rotulados ou aparecer sem texto. Um botão normalmente muda a aparência quando o usuário clica nele.

Os botões típicos são a caixa de seleção, o botão de rádio e o botão. Um `CButton` objeto pode se tornar qualquer um desses, de acordo com o estilo de [botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) especificado em sua inicialização pela função [Criar](#create) membro.

Além disso, a classe [CBitmapButton](../../mfc/reference/cbitmapbutton-class.md) derivada da `CButton` criação de controles de botão rotulados com imagens bitmap em vez de texto. A `CBitmapButton` pode ter bitmaps separados para os estados de cima, baixa, foco e desativado de um botão.

Você pode criar um controle de botão a partir de um modelo de diálogo ou diretamente em seu código. Em ambos os casos, `CButton` primeiro chame `CButton` o construtor para construir o objeto; em seguida, chame a `Create` função de membro para `CButton` criar o controle do botão do Windows e anexá-lo ao objeto.

A construção pode ser um processo de `CButton`uma etapa em uma classe derivada de . Escreva um construtor para a classe `Create` derivada e ligue de dentro do construtor.

Se você quiser lidar com mensagens de notificação do Windows enviadas por um controle de botão para seu pai (geralmente uma classe derivada do [CDialog),](../../mfc/reference/cdialog-class.md)adicione uma função de membro do mapa de mensagem e do manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem tem o seguinte formulário:

**ON\_**_Notification_ _(id_, _memberFxn_ **)** **(**

onde *id* especifica o ID da janela filho do controle enviando a notificação e *membroFxn* é o nome da função de membro pai que você escreveu para lidar com a notificação.

O protótipo de função dos pais é o seguinte:

`afx_msg void memberFxn();`

As entradas potenciais do mapa de mensagens são as seguintes:

|Entrada do mapa|Enviado para o pai quando...|
|---------------|----------------------------|
|ON_BN_CLICKED|O usuário clica em um botão.|
|ON_BN_DOUBLECLICKED|O usuário clica duas vezes em um botão.|

Se você `CButton` criar um objeto a `CButton` partir de um recurso de diálogo, o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CButton` criar um objeto dentro de uma janela, talvez precise destruí-lo. Se você `CButton` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário fecha o controle do botão do Windows. Se você `CButton` criar o objeto na pilha ou ele estiver incorporado no objeto de diálogo pai, ele será destruído automaticamente.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

`CButton`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cbuttoncbutton"></a><a name="cbutton"></a>CButton::CButton

Constrói um objeto `CButton`.

```
CButton();
```

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#1](../../mfc/reference/codesnippet/cpp/cbutton-class_1.cpp)]

## <a name="cbuttoncreate"></a><a name="create"></a>CButton::Criar

Cria o controle do botão do `CButton` Windows e o anexa ao objeto.

```
virtual BOOL Create(
    LPCTSTR lpszCaption,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*lpszCaption*<br/>
Especifica o texto do controle do botão.

*Dwstyle*<br/>
Especifica o estilo do controle do botão. Aplique qualquer combinação de estilos de [botão](../../mfc/reference/styles-used-by-mfc.md#button-styles) no botão.

*Rect*<br/>
Especifica o tamanho e a posição do controle do botão. Pode ser um `CRect` objeto `RECT` ou uma estrutura.

*Pparentwnd*<br/>
Especifica a janela pai do controle `CDialog`do botão, geralmente um . Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle do botão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CButton` um objeto em dois passos. Primeiro, ligue para o `Create`construtor e, em seguida, ligue, `CButton` que cria o controle do botão do Windows e o anexa ao objeto.

Se o estilo WS_VISIBLE for dado, o Windows envia ao botão o controle de todas as mensagens necessárias para ativar e mostrar o botão.

Aplique os [seguintes estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) a um controle de botão:

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_GROUP Para controles de grupo

- WS_TABSTOP Para incluir o botão na ordem de abas

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#2](../../mfc/reference/codesnippet/cpp/cbutton-class_2.cpp)]

## <a name="cbuttondrawitem"></a><a name="drawitem"></a>CButton::DrawItem

Chamado pela estrutura quando um aspecto visual de um botão desenhado pelo proprietário foi alterado.

```
virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
```

### <a name="parameters"></a>Parâmetros

*Lpdrawitemstruct*<br/>
Um ponteiro longo para uma estrutura [DRAWITEMSTRUCT.](/windows/win32/api/winuser/ns-winuser-drawitemstruct) A estrutura contém informações sobre o item a ser sorteado e o tipo de desenho necessário.

### <a name="remarks"></a>Comentários

Um botão desenhado pelo proprietário tem o conjunto de BS_OWNERDRAW estilo. Substituir essa função de membro para implementar `CButton` o desenho de um objeto desenhado pelo proprietário. O aplicativo deve restaurar todos os objetos GDI (Graphics Device Interface, interface de dispositivo gráfico) selecionados para o contexto de exibição fornecido no *lpDrawItemStruct* antes que a função do membro seja encerrada.

Veja também os valores de estilo [BS_.](../../mfc/reference/styles-used-by-mfc.md#button-styles)

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#3](../../mfc/reference/codesnippet/cpp/cbutton-class_3.cpp)]

## <a name="cbuttongetbitmap"></a><a name="getbitmap"></a>CButton::GetBitmap

Ligue para esta função de membro para obter a alça de um bitmap, previamente definida com [SetBitmap,](#setbitmap)que está associada a um botão.

```
HBITMAP GetBitmap() const;
```

### <a name="return-value"></a>Valor retornado

Uma alça para um bitmap. NULL se nenhum bitmap for previamente especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]

## <a name="cbuttongetbuttonstyle"></a><a name="getbuttonstyle"></a>CButton::GetButtonStyle

Recupera informações sobre o estilo de controle do botão.

```
UINT GetButtonStyle() const;
```

### <a name="return-value"></a>Valor retornado

Retorna os estilos `CButton` de botão para este objeto. Esta função retorna apenas os valores de estilo [BS_,](../../mfc/reference/styles-used-by-mfc.md#button-styles) não qualquer um dos outros estilos de janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]

## <a name="cbuttongetcheck"></a><a name="getcheck"></a>CButton::GetCheck

Recupera o estado de verificação de um botão de rádio ou caixa de seleção.

```
int GetCheck() const;
```

### <a name="return-value"></a>Valor retornado

O valor de devolução de um controle de botão criado com o estilo BS_AUTOCHECKBOX, BS_AUTORADIOBUTTON, BS_AUTO3STATE, BS_CHECKBOX, BS_RADIOBUTTON ou BS_3STATE é um dos seguintes valores:

|Valor|Significado|
|-----------|-------------|
|Bst_unchecked|O estado do botão não está controlado.|
|BST_CHECKED|O estado do botão é verificado.|
|BST_INDETERMINATE|O estado do botão é indeterminado (só se aplica se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE).|

Se o botão tiver qualquer outro estilo, o valor de retorno é BST_UNCHECKED.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]

## <a name="cbuttongetcursor"></a><a name="getcursor"></a>CButton::GetCursor

Ligue para esta função de membro para obter a alça de um cursor, previamente definido com [SetCursor,](#setcursor)que está associado a um botão.

```
HCURSOR GetCursor();
```

### <a name="return-value"></a>Valor retornado

Uma alça para uma imagem do cursor. NULL se nenhum cursor for previamente especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]

## <a name="cbuttongeticon"></a><a name="geticon"></a>CButton::GetIcon

Ligue para esta função de membro para obter o cabo de um ícone, previamente definido com [SetIcon](#seticon), que está associado a um botão.

```
HICON GetIcon() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para um ícone. NULL se nenhum ícone for previamente especificado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]

## <a name="cbuttongetidealsize"></a><a name="getidealsize"></a>Cbutton::GetIdealSize

Recupera o tamanho ideal para o controle do botão.

```
BOOL GetIdealSize(SIZE* psize);
```

### <a name="parameters"></a>Parâmetros

*Psize*<br/>
Um ponteiro para o tamanho atual do botão.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem BCM_GETIDEALSIZE, conforme descrito na seção [Botões](/windows/win32/controls/buttons) do Windows SDK.

## <a name="cbuttongetimagelist"></a><a name="getimagelist"></a>CButton::GetImageList

Chame este método para obter a lista de imagens a partir do controle do botão.

```
BOOL GetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```

### <a name="parameters"></a>Parâmetros

*pbuttonImagelist*<br/>
Um ponteiro para a `CButton` lista de imagens do objeto.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem BCM_GETIMAGELIST, conforme descrito na seção [Botões](/windows/win32/controls/buttons) do Windows SDK.

## <a name="cbuttongetnote"></a><a name="getnote"></a>CButton::GetNote

Recupera o texto de nota associado ao controle atual do link de comando.

```
CString GetNote() const;

BOOL GetNote(
    LPTSTR lpszNote,
    UINT* cchNote) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszNote*|[fora] Ponteiro para um buffer, que o chamador é responsável por alocar e negociar. Se o valor de retorno for TRUE, o buffer contém o texto de nota associado ao controle atual do link de comando; caso contrário, o buffer é inalterado.|
|*cchNote*|[dentro, fora] Um ponteiro para uma variável inteiro não assinada.<br /><br /> Quando este método é chamado, a variável contém o tamanho do buffer especificado pelo parâmetro *lpszNote.*<br /><br /> Quando este método retorna, se o valor de retorno for TRUE, a variável contém o tamanho da nota associada ao controle atual do link de comando. Se o valor de retorno for FALSO, a variável contém o tamanho do buffer necessário para conter a nota.|

### <a name="return-value"></a>Valor retornado

Na primeira sobrecarga, um objeto [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de nota associado ao controle atual do link de comando.

-ou-

Na segunda sobrecarga, TRUE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Este método envia a [mensagem BCM_GETNOTE,](/windows/win32/Controls/bcm-getnote) que é descrita no SDK do Windows.

## <a name="cbuttongetnotelength"></a><a name="getnotelength"></a>cbutton::getNoteLength

Recupera o comprimento do texto da nota para o controle atual do link de comando.

```
UINT GetNoteLength() const;
```

### <a name="return-value"></a>Valor retornado

O comprimento do texto de nota, em caracteres Unicode de 16 bits, para o controle atual do link de comando.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Este método envia a mensagem [BCM_GETNOTELENGTH,](/windows/win32/Controls/bcm-getnotelength) que é descrita no SDK do Windows.

## <a name="cbuttongetsplitglyph"></a><a name="getsplitglyph"></a>CButton::GetSplitGliph

Recupera o glifo associado ao controle atual do botão split.

```
TCHAR GetSplitGlyph() const;
```

### <a name="return-value"></a>Valor retornado

O caractere glifo associado ao controle atual do botão split.

### <a name="remarks"></a>Comentários

Um glifo é a representação física de um personagem em uma fonte específica. Por exemplo, um controle de botão dividido pode ser decorado com o glifo do caractere de marca de verificação Unicode (U+2713).

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Este método inicializa `mask` o membro de uma estrutura [de BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_GLYPH e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows. Quando a função de mensagem retorna, este `himlGlyph` método recupera o glifo do membro da estrutura.

## <a name="cbuttongetsplitimagelist"></a><a name="getsplitimagelist"></a>cbutton::GetSplitImagelist

Recupera a [lista de imagens](../../mfc/reference/cimagelist-class.md) para o controle atual do botão dividido.

```
CImageList* GetSplitImageList() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto [CImageList.](../../mfc/reference/cimagelist-class.md)

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Este método inicializa `mask` o membro de uma estrutura [de BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_IMAGE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows. Quando a função de mensagem retorna, este `himlGlyph` método recupera a lista de imagens do membro da estrutura.

## <a name="cbuttongetsplitinfo"></a><a name="getsplitinfo"></a>cbutton::getSplitinfo

Recupera parâmetros que determinam como o Windows desenha o controle atual do botão dividido.

```
BOOL GetSplitInfo(PBUTTON_SPLITINFO pInfo) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Pinfo*|[fora] Ponteiro para uma estrutura [de BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) que recebe informações sobre o controle atual do botão split. O interlocutor é responsável por alocar a estrutura.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Este método envia a mensagem [BCM_GETSPLITINFO,](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows.

## <a name="cbuttongetsplitsize"></a><a name="getsplitsize"></a>CButton::GetSplitSize

Recupera o retângulo delimitador do componente drop-down do controle atual do botão split.

```
BOOL GetSplitSize(LPSIZE pSize) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Psize*|[fora] Pointer para uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) que recebe a descrição de um retângulo.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Quando o controle de botão dividido é expandido, ele pode exibir um componente suspenso, como um controle de lista ou controle de pager. Este método recupera o retângulo delimitador que contém o componente drop-down.

Este método inicializa `mask` o membro de uma estrutura [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_SIZE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows. Quando a função de mensagem retorna, este método `size` recupera o retângulo delimitador do membro da estrutura.

## <a name="cbuttongetsplitstyle"></a><a name="getsplitstyle"></a>CButton::GetSplitStyle

Recupera os estilos de botão dividido que definem o controle atual do botão dividido.

```
UINT GetSplitStyle() const;
```

### <a name="return-value"></a>Valor retornado

Uma combinação um pouco de estilos de botão dividido. Para obter mais `uSplitStyle` informações, consulte o membro da estrutura [BUTTON_SPLITINFO.](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo)

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Os estilos de botão dividido especificam o alinhamento, a proporção e o formato gráfico com o qual o Windows desenha um ícone de botão dividido.

Este método inicializa `mask` o membro de uma estrutura [de BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_STYLE e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows. Quando a função de mensagem retorna, este `uSplitStyle` método recupera os estilos de botão dividido do membro da estrutura.

## <a name="cbuttongetstate"></a><a name="getstate"></a>Cbutton::GetState

Recupera o estado de um controle de botão.

```
UINT GetState() const;
```

### <a name="return-value"></a>Valor retornado

Um campo de bits que contém a combinação de valores que indicam o estado atual de um controle de botão. A tabela a seguir lista possíveis valores.

|Estado do botão|Valor|Descrição|
|------------------|-----------|-----------------|
|Bst_unchecked|0x0000|O estado inicial.|
|BST_CHECKED|0x0001|O controle do botão está verificado.|
|BST_INDETERMINATE|0x0002|O estado é indeterminado (só é possível quando o controle do botão tem três estados).|
|BST_PUSHED|0x0004|O controle do botão é pressionado.|
|BST_FOCUS|0x0008|O controle do botão tem o foco.|

### <a name="remarks"></a>Comentários

Um controle de botão com o estilo de botão BS_3STATE ou BS_AUTO3STATE cria uma caixa de seleção que tem um terceiro estado que é chamado de estado indeterminado. O estado indeterminado indica que a caixa de seleção não é verificada nem desmarcada.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]

## <a name="cbuttongettextmargin"></a><a name="gettextmargin"></a>CButton::GetTextMargin

Chame este método para obter `CButton` a margem de texto do objeto.

```
BOOL GetTextMargin(RECT* pmargin);
```

### <a name="parameters"></a>Parâmetros

*pmargem*<br/>
Um ponteiro para a `CButton` margem de texto do objeto.

### <a name="return-value"></a>Valor retornado

Retorna a margem de texto.

### <a name="remarks"></a>Comentários

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem BCM_GETTEXTMARGIN, conforme descrito na seção [Botões](/windows/win32/controls/buttons) do Windows SDK.

## <a name="cbuttonsetbitmap"></a><a name="setbitmap"></a>CButton::SetBitmap

Ligue para esta função de membro para associar um novo bitmap com o botão.

```
HBITMAP SetBitmap(HBITMAP hBitmap);
```

### <a name="parameters"></a>Parâmetros

*Hbitmap*<br/>
A alça de um bitmap.

### <a name="return-value"></a>Valor retornado

A alça de um bitmap anteriormente associada ao botão.

### <a name="remarks"></a>Comentários

O bitmap será colocado automaticamente na face do botão, centrado por padrão. Se o bitmap for muito grande para o botão, ele será cortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário [do CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que `SetBitmap` usa quatro bitmaps por botão, usa apenas um bitmap por botão. Quando o botão é pressionado, o bitmap parece mudar para baixo e para a direita.

Você é responsável por liberar o bitmap quando terminar com ele.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#4](../../mfc/reference/codesnippet/cpp/cbutton-class_4.cpp)]

## <a name="cbuttonsetbuttonstyle"></a><a name="setbuttonstyle"></a>CButton::SetButtonEstilo de botão

Muda o estilo de um botão.

```
void SetButtonStyle(
    UINT nStyle,
    BOOL bRedraw = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nStyle*<br/>
Especifica o estilo do [botão](../../mfc/reference/styles-used-by-mfc.md#button-styles).

*Bredraw*<br/>
Especifica se o botão deve ser redesenhado. Um valor não zero redesenha o botão. Um valor 0 não redesenhar o botão. O botão é redesenhado por padrão.

### <a name="remarks"></a>Comentários

Use `GetButtonStyle` a função membro para recuperar o estilo do botão. A palavra de baixa ordem do estilo completo do botão é o estilo específico do botão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#5](../../mfc/reference/codesnippet/cpp/cbutton-class_5.cpp)]

## <a name="cbuttonsetcheck"></a><a name="setcheck"></a>CButton::SetCheck

Define ou redefine o estado de verificação de um botão de rádio ou caixa de seleção.

```
void SetCheck(int nCheck);
```

### <a name="parameters"></a>Parâmetros

*Ncheck*<br/>
Especifica o estado de verificação. Esse parâmetro pode ser um dos seguintes:

|Valor|Significado|
|-----------|-------------|
|Bst_unchecked|Defina o estado do botão como descontrolado.|
|BST_CHECKED|Defina o estado do botão como verificado.|
|BST_INDETERMINATE|Defina o estado do botão como indeterminado. Este valor só pode ser usado se o botão tiver o estilo BS_3STATE ou BS_AUTO3STATE.|

### <a name="remarks"></a>Comentários

Esta função de membro não tem efeito em um botão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#6](../../mfc/reference/codesnippet/cpp/cbutton-class_6.cpp)]

## <a name="cbuttonsetcursor"></a><a name="setcursor"></a>CButton::SetCursor

Ligue para esta função de membro para associar um novo cursor com o botão.

```
HCURSOR SetCursor(HCURSOR hCursor);
```

### <a name="parameters"></a>Parâmetros

*Hcursor*<br/>
A alça de um cursor.

### <a name="return-value"></a>Valor retornado

A alça de um cursor anteriormente associada ao botão.

### <a name="remarks"></a>Comentários

O cursor será automaticamente colocado na face do botão, centrado por padrão. Se o cursor for muito grande para o botão, ele será cortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário [do CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que `SetCursor` usa quatro bitmaps por botão, usa apenas um cursor por botão. Quando o botão é pressionado, o cursor parece mudar para baixo e para a direita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#7](../../mfc/reference/codesnippet/cpp/cbutton-class_7.cpp)]

## <a name="cbuttonsetdropdownstate"></a><a name="setdropdownstate"></a>cbutton::setDropDownState

Define o estado de isto do controle atual do botão split.

```
BOOL SetDropDownState(BOOL fDropDown);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*fDropDown*|[em] VERDADEIRO para definir BST_DROPDOWNPUSHED estado; caso contrário, FALSE.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Um controle de botão split tem um estilo de BS_SPLITBUTTON ou BS_DEFSPLITBUTTON e consiste em um botão e uma seta para baixo à direita. Para obter mais informações, consulte [Button Styles](/windows/win32/Controls/button-styles). Normalmente, o estado de desestatado é definido quando o usuário clica na seta baixa. Use este método para definir programáticamente o estado de desestatado do controle. A seta suspensa é desenhada sombreada para indicar o estado.

Este método envia a [mensagem BCM_SETDROPDOWNSTATE,](/windows/win32/Controls/bcm-setdropdownstate) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_splitButton*, que é usada para acessar programáticamente o controle do botão dividido. Esta variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estado do controle do botão dividido para indicar que a seta suspensa é empurrada.

[!code-cpp[NVC_MFC_CButton_s1#6](../../mfc/reference/codesnippet/cpp/cbutton-class_11.cpp)]

## <a name="cbuttonsetelevationrequired"></a><a name="setelevationrequired"></a>cbutton::setElevationRequired

Define o estado do controle `elevation required`atual do botão para , o que é necessário para que o controle exiba um ícone de segurança elevado.

```
BOOL SetElevationRequired(BOOL fElevationRequired);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*fElevationRequired*|[em] VERDADEIRO para `elevation required` definir estado; caso contrário, FALSE.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se um controle de botão ou link de comando exigir uma `elevation required` permissão de segurança elevada para executar uma ação, defina o controle como estado. Posteriormente, o Windows exibe o ícone de escudo uac (User Account Control, controle da conta de usuário) no controle. Para obter mais informações, consulte "Controle da conta de usuário" no [MSDN](https://go.microsoft.com/fwlink/p/?linkid=18507).

Este método envia a [mensagem BCM_SETSHIELD,](/windows/win32/Controls/bcm-setshield) que é descrita no SDK do Windows.

## <a name="cbuttonseticon"></a><a name="seticon"></a>CButton::SetIcon

Ligue para esta função de membro para associar um novo ícone ao botão.

```
HICON SetIcon(HICON hIcon);
```

### <a name="parameters"></a>Parâmetros

*Hicon*<br/>
A alça de um ícone.

### <a name="return-value"></a>Valor retornado

A alça de um ícone anteriormente associado ao botão.

### <a name="remarks"></a>Comentários

O ícone será colocado automaticamente na face do botão, centrado por padrão. Se o ícone for muito grande para o botão, ele será cortado em ambos os lados. Você pode escolher outras opções de alinhamento, incluindo as seguintes:

- BS_TOP

- BS_LEFT

- BS_RIGHT

- BS_CENTER

- BS_BOTTOM

- BS_VCENTER

Ao contrário [do CBitmapButton](../../mfc/reference/cbitmapbutton-class.md), que `SetIcon` usa quatro bitmaps por botão, usa apenas um ícone por botão. Quando o botão é pressionado, o ícone parece mudar para baixo e para a direita.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#8](../../mfc/reference/codesnippet/cpp/cbutton-class_8.cpp)]

## <a name="cbuttonsetimagelist"></a><a name="setimagelist"></a>CButton::SetImageList

Chame este método para definir `CButton` a lista de imagens do objeto.

```
BOOL SetImageList(PBUTTON_IMAGELIST pbuttonImagelist);
```

### <a name="parameters"></a>Parâmetros

*pbuttonImagelist*<br/>
Um ponteiro para a nova lista de imagens.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem BCM_SETIMAGELIST, conforme descrito na seção [Botões](/windows/win32/controls/buttons) do Windows SDK.

## <a name="cbuttonsetnote"></a><a name="setnote"></a>CButton::SetNote

Define o texto da nota para o controle atual do link de comando.

```
BOOL SetNote(LPCTSTR lpszNote);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*lpszNote*|[em] Ponteiro para uma seqüência unicode definida como o texto de nota para o controle do link de comando.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_COMMANDLINK ou BS_DEFCOMMANDLINK.

Este método envia a mensagem [BCM_SETNOTE,](/windows/win32/Controls/bcm-setnote) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define a variável, *m_cmdLink*, que é usada para acessar programáticamente o controle do link de comando. Esta variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o texto da nota para o controle do link de comando.

[!code-cpp[NVC_MFC_CButton_s1#7](../../mfc/reference/codesnippet/cpp/cbutton-class_12.cpp)]

## <a name="cbuttonsetsplitglyph"></a><a name="setsplitglyph"></a>CButton::SetSplitGlyph

Associa um glifo especificado com o controle atual do botão split.

```
BOOL SetSplitGlyph(TCHAR chGlyph);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*chGllyph*|[em] Um caractere que especifica o glifo para usar como a seta de dissélo do botão split.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles que tenham o estilo de botão BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Um glifo é a representação física de um personagem em uma fonte específica. O parâmetro *chGlif o chglif* não é usado como o glifo, mas é usado para selecionar um glifo de um conjunto de glifos definidos pelo sistema. O glifo de seta baixa padrão é especificado por um caractere '6', e se assemelha ao caractere Unicode BLACK DOWN-POINTING TRIANGLE (U+25BC).

Este método inicializa `mask` o membro de uma estrutura `himlGlyph` de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_GLYPH e o membro com o parâmetro *chGlyph,* e então envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no Windows SDK.

## <a name="cbuttonsetsplitimagelist"></a><a name="setsplitimagelist"></a>cbutton::SetSplitImagelist

Associa uma [lista de imagens](../../mfc/reference/cimagelist-class.md) com o controle atual do botão dividido.

```
BOOL SetSplitImageList(CImageList* pSplitImageList);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pSplitImageList*|[em] Pointer para um objeto [CImageList](../../mfc/reference/cimagelist-class.md) para atribuir ao controle atual do botão dividido.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Este método inicializa `mask` o membro de uma estrutura `himlGlyph` de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_IMAGE e o membro com o parâmetro *pSplitImageList* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita no SDK do Windows.

## <a name="cbuttonsetsplitinfo"></a><a name="setsplitinfo"></a>cbutton::SetSplitInfo

Especifica parâmetros que determinam como o Windows desenha o controle atual do botão dividido.

```
BOOL SetSplitInfo(PBUTTON_SPLITINFO pInfo);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Pinfo*|[em] Ponteiro para uma estrutura [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) que define o controle atual do botão de divisão.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Este método envia a mensagem [BCM_SETSPLITINFO,](/windows/win32/Controls/bcm-setsplitinfo) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_splitButton`seguir define a variável, que é usada para acessar programáticamente o controle do botão dividido.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir altera o glifo usado para a seta de baixa do botão split. O exemplo substitui um glifo triângulo para cima apontando para cima para o glifo do triângulo de apontar para baixo padrão. O glifo exibido depende do caractere que você especifica `himlGlyph` ré `BUTTON_SPLITINFO` no membro da estrutura. O glifo do triângulo para baixo é especificado por um caractere '6' e o glifo do triângulo para cima é especificado por um caractere '5'. Para comparação, consulte o método de [conveniência, CButton::SetSplitGlyph](#setsplitglyph).

[!code-cpp[NVC_MFC_CButton_s1#4](../../mfc/reference/codesnippet/cpp/cbutton-class_13.cpp)]

## <a name="cbuttonsetsplitsize"></a><a name="setsplitsize"></a>cbutton::SetSplitSize

Define o retângulo delimitador do componente drop-down do controle atual do botão split.

```
BOOL SetSplitSize(LPSIZE pSize);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Psize*|[em] Pointer para uma estrutura [SIZE](/windows/win32/api/windef/ns-windef-size) que descreve um retângulo delimitador.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Quando o controle de botão dividido é expandido, ele pode exibir um componente suspenso, como um controle de lista ou controle de pager. Este método especifica o tamanho do retângulo delimitador que contém o componente gota.

Este método inicializa `mask` o membro de uma estrutura `size` de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_SIZE e o membro com o parâmetro *pSize,* e então envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_splitButton`seguir define a variável, que é usada para acessar programáticamente o controle do botão dividido. Esta variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir dobra o tamanho da seta para baixo do botão split.

[!code-cpp[NVC_MFC_CButton_s1#5](../../mfc/reference/codesnippet/cpp/cbutton-class_14.cpp)]

## <a name="cbuttonsetsplitstyle"></a><a name="setsplitstyle"></a>cbutton::SetSplitStyle

Define o estilo do controle atual do botão dividido.

```
BOOL SetSplitStyle(UINT uSplitStyle);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*uSplitStyle*|[em] Uma combinação um pouco de estilos de botão dividido. Para obter mais `uSplitStyle` informações, consulte o membro da estrutura [BUTTON_SPLITINFO.](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo)|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método apenas com controles cujo estilo de botão seja BS_SPLITBUTTON ou BS_DEFSPLITBUTTON.

Os estilos de botão dividido especificam o alinhamento, a proporção e o formato gráfico com o qual o Windows desenha um ícone de botão dividido. Para obter mais `uSplitStyle` informações, consulte o membro da estrutura [BUTTON_SPLITINFO.](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo)

Este método inicializa `mask` o membro de uma estrutura `uSplitStyle` de [BUTTON_SPLITINFO](/windows/win32/api/commctrl/ns-commctrl-button_splitinfo) com a bandeira BCSIF_STYLE e o membro com o parâmetro *uSplitStyle* e, em seguida, envia essa estrutura na mensagem [BCM_GETSPLITINFO](/windows/win32/Controls/bcm-getsplitinfo) descrita no SDK do Windows.

### <a name="example"></a>Exemplo

O exemplo de código a `m_splitButton`seguir define a variável, que é usada para acessar programáticamente o controle do botão dividido.

[!code-cpp[NVC_MFC_CButton_s1#1](../../mfc/reference/codesnippet/cpp/cbutton-class_10.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir define o estilo da seta para baixo do botão dividido. O estilo BCSS_ALIGNLEFT exibe a seta no lado esquerdo do botão, e o estilo BCSS_STRETCH mantém as proporções da seta baixa quando você redimensiona o botão.

[!code-cpp[NVC_MFC_CButton_s1#3](../../mfc/reference/codesnippet/cpp/cbutton-class_15.cpp)]

## <a name="cbuttonsetstate"></a><a name="setstate"></a>cbutton::setState

Define se um controle de botão está ou não destacado.

```
void SetState(BOOL bHighlight);
```

### <a name="parameters"></a>Parâmetros

*bDestaque*<br/>
Especifica se o botão deve ser destacado. Um valor não zero destaca o botão; um valor 0 remove qualquer destaque.

### <a name="remarks"></a>Comentários

O destaque afeta o exterior de um controle de botão. Não tem efeito sobre o estado de verificação de um botão de rádio ou caixa de seleção.

Um controle de botão é automaticamente destacado quando o usuário clica e segura o botão esquerdo do mouse. O destaque é removido quando o usuário libera o botão do mouse.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CButton#9](../../mfc/reference/codesnippet/cpp/cbutton-class_9.cpp)]

## <a name="cbuttonsettextmargin"></a><a name="settextmargin"></a>cbutton::SetTextMargin

Chame este método para definir `CButton` a margem de texto do objeto.

```
BOOL SetTextMargin(RECT* pmargin);
```

### <a name="parameters"></a>Parâmetros

*pmargem*<br/>
Um ponteiro para a nova margem de texto.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Esta função membro emula a funcionalidade da mensagem BCM_SETTEXTMARGIN, conforme descrito na seção [Botões](/windows/win32/controls/buttons) do Windows SDK.

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
