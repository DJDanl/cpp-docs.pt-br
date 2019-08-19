---
title: Classe CEdit
ms.date: 09/12/2018
f1_keywords:
- CEdit
- AFXWIN/CEdit
- AFXWIN/CEdit::CEdit
- AFXWIN/CEdit::CanUndo
- AFXWIN/CEdit::CharFromPos
- AFXWIN/CEdit::Clear
- AFXWIN/CEdit::Copy
- AFXWIN/CEdit::Create
- AFXWIN/CEdit::Cut
- AFXWIN/CEdit::EmptyUndoBuffer
- AFXWIN/CEdit::FmtLines
- AFXWIN/CEdit::GetCueBanner
- AFXWIN/CEdit::GetFirstVisibleLine
- AFXWIN/CEdit::GetHandle
- AFXWIN/CEdit::GetHighlight
- AFXWIN/CEdit::GetLimitText
- AFXWIN/CEdit::GetLine
- AFXWIN/CEdit::GetLineCount
- AFXWIN/CEdit::GetMargins
- AFXWIN/CEdit::GetModify
- AFXWIN/CEdit::GetPasswordChar
- AFXWIN/CEdit::GetRect
- AFXWIN/CEdit::GetSel
- AFXWIN/CEdit::HideBalloonTip
- AFXWIN/CEdit::LimitText
- AFXWIN/CEdit::LineFromChar
- AFXWIN/CEdit::LineIndex
- AFXWIN/CEdit::LineLength
- AFXWIN/CEdit::LineScroll
- AFXWIN/CEdit::Paste
- AFXWIN/CEdit::PosFromChar
- AFXWIN/CEdit::ReplaceSel
- AFXWIN/CEdit::SetCueBanner
- AFXWIN/CEdit::SetHandle
- AFXWIN/CEdit::SetHighlight
- AFXWIN/CEdit::SetLimitText
- AFXWIN/CEdit::SetMargins
- AFXWIN/CEdit::SetModify
- AFXWIN/CEdit::SetPasswordChar
- AFXWIN/CEdit::SetReadOnly
- AFXWIN/CEdit::SetRect
- AFXWIN/CEdit::SetRectNP
- AFXWIN/CEdit::SetSel
- AFXWIN/CEdit::SetTabStops
- AFXWIN/CEdit::ShowBalloonTip
- AFXWIN/CEdit::Undo
helpviewer_keywords:
- CEdit [MFC], CEdit
- CEdit [MFC], CanUndo
- CEdit [MFC], CharFromPos
- CEdit [MFC], Clear
- CEdit [MFC], Copy
- CEdit [MFC], Create
- CEdit [MFC], Cut
- CEdit [MFC], EmptyUndoBuffer
- CEdit [MFC], FmtLines
- CEdit [MFC], GetCueBanner
- CEdit [MFC], GetFirstVisibleLine
- CEdit [MFC], GetHandle
- CEdit [MFC], GetHighlight
- CEdit [MFC], GetLimitText
- CEdit [MFC], GetLine
- CEdit [MFC], GetLineCount
- CEdit [MFC], GetMargins
- CEdit [MFC], GetModify
- CEdit [MFC], GetPasswordChar
- CEdit [MFC], GetRect
- CEdit [MFC], GetSel
- CEdit [MFC], HideBalloonTip
- CEdit [MFC], LimitText
- CEdit [MFC], LineFromChar
- CEdit [MFC], LineIndex
- CEdit [MFC], LineLength
- CEdit [MFC], LineScroll
- CEdit [MFC], Paste
- CEdit [MFC], PosFromChar
- CEdit [MFC], ReplaceSel
- CEdit [MFC], SetCueBanner
- CEdit [MFC], SetHandle
- CEdit [MFC], SetHighlight
- CEdit [MFC], SetLimitText
- CEdit [MFC], SetMargins
- CEdit [MFC], SetModify
- CEdit [MFC], SetPasswordChar
- CEdit [MFC], SetReadOnly
- CEdit [MFC], SetRect
- CEdit [MFC], SetRectNP
- CEdit [MFC], SetSel
- CEdit [MFC], SetTabStops
- CEdit [MFC], ShowBalloonTip
- CEdit [MFC], Undo
ms.assetid: b1533c30-7f10-4663-88d3-8b7f2c9f7024
ms.openlocfilehash: 5ad8784f3bff999eec046aa91f52b1cd164764e5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506799"
---
# <a name="cedit-class"></a>Classe CEdit

Fornece a funcionalidade de um controle de edição do Windows.

## <a name="syntax"></a>Sintaxe

```
class CEdit : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CEdit::CEdit](#cedit)|Constrói um objeto `CEdit` de controle.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEdit::CanUndo](#canundo)|Determina se uma operação de controle de edição pode ser desfeita.|
|[CEdit::CharFromPos](#charfrompos)|Recupera os índices de linha e de caractere para o caractere mais próximo de uma posição especificada.|
|[CEdit::Clear](#clear)|Exclui (limpa) a seleção atual (se houver) no controle de edição.|
|[CEdit::Copy](#copy)|Copia a seleção atual (se houver) no controle de edição para a área de transferência no formato CF_TEXT.|
|[CEdit::Create](#create)|Cria o controle de edição do Windows e o anexa ao `CEdit` objeto.|
|[CEdit::Cut](#cut)|Exclui (recorta) a seleção atual (se houver) no controle de edição e copia o texto excluído para a área de transferência no formato CF_TEXT.|
|[CEdit::EmptyUndoBuffer](#emptyundobuffer)|Redefine (limpa) o sinalizador de desfazer de um controle de edição.|
|[CEdit::FmtLines](#fmtlines)|Define a inclusão de caracteres de quebra de linha flexível ativados ou desativados dentro de um controle de edição de várias linhas.|
|[CEdit::GetCueBanner](#getcuebanner)|Recupera o texto que é exibido como a indicação de texto, ou Tip, em um controle de edição quando o controle está vazio e não tem foco.|
|[CEdit::GetFirstVisibleLine](#getfirstvisibleline)|Determina a linha visível superior em um controle de edição.|
|[CEdit::GetHandle](#gethandle)|Recupera um identificador para a memória que está alocada no momento para um controle de edição de várias linhas.|
|[CEdit::GetHighlight](#gethighlight)|Obtém os índices dos caracteres inicial e final em um intervalo de texto que é realçado no controle de edição atual.|
|[CEdit::GetLimitText](#getlimittext)|Obtém a quantidade máxima de texto `CEdit` que pode conter.|
|[CEdit::GetLine](#getline)|Recupera uma linha de texto de um controle de edição.|
|[CEdit::GetLineCount](#getlinecount)|Recupera o número de linhas em um controle de edição de várias linhas.|
|[CEdit::GetMargins](#getmargins)|Obtém as margens esquerda e direita para isso `CEdit`.|
|[CEdit::GetModify](#getmodify)|Determina se o conteúdo de um controle de edição foi modificado.|
|[CEdit::GetPasswordChar](#getpasswordchar)|Recupera o caractere de senha exibido em um controle de edição quando o usuário digita o texto.|
|[CEdit::GetRect](#getrect)|Obtém o retângulo de formatação de um controle de edição.|
|[CEdit::GetSel](#getsel)|Obtém as primeiras e última posições de caractere da seleção atual em um controle de edição.|
|[CEdit::HideBalloonTip](#hideballoontip)|Oculta qualquer dica de balão associada ao controle de edição atual.|
|[CEdit::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir em um controle de edição.|
|[CEdit::LineFromChar](#linefromchar)|Recupera o número de linha da linha que contém o índice de caracteres especificado.|
|[CEdit::LineIndex](#lineindex)|Recupera o índice de caracteres de uma linha dentro de um controle de edição de várias linhas.|
|[CEdit::LineLength](#linelength)|Recupera o comprimento de uma linha em um controle de edição.|
|[CEdit::LineScroll](#linescroll)|Rola o texto de um controle de edição de várias linhas.|
|[CEdit::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Os dados só serão inseridos se a área de transferência contiver dados no formato CF_TEXT.|
|[CEdit::PosFromChar](#posfromchar)|Recupera as coordenadas do canto superior esquerdo de um índice de caracteres especificado.|
|[CEdit::ReplaceSel](#replacesel)|Substitui a seleção atual em um controle de edição pelo texto especificado.|
|[CEdit::SetCueBanner](#setcuebanner)|Define o texto que é exibido como a indicação de texto, ou Tip, em um controle de edição quando o controle está vazio e não tem foco.|
|[CEdit::SetHandle](#sethandle)|Define o identificador para a memória local que será usada por um controle de edição de várias linhas.|
|[CEdit::SetHighlight](#sethighlight)|Realça um intervalo de texto que é exibido no controle de edição atual.|
|[CEdit::SetLimitText](#setlimittext)|Define a quantidade máxima de texto `CEdit` que pode conter.|
|[CEdit::SetMargins](#setmargins)|Define as margens esquerda e direita para isso `CEdit`.|
|[CEdit::SetModify](#setmodify)|Define ou limpa o sinalizador de modificação para um controle de edição.|
|[CEdit::SetPasswordChar](#setpasswordchar)|Define ou remove um caractere de senha exibido em um controle de edição quando o usuário digita o texto.|
|[CEdit::SetReadOnly](#setreadonly)|Define o estado somente leitura de um controle de edição.|
|[CEdit::SetRect](#setrect)|Define o retângulo de formatação de um controle de edição de várias linhas e atualiza o controle.|
|[CEdit::SetRectNP](#setrectnp)|Define o retângulo de formatação de um controle de edição de várias linhas sem redesenhar a janela de controle.|
|[CEdit::SetSel](#setsel)|Seleciona um intervalo de caracteres em um controle de edição.|
|[CEdit::SetTabStops](#settabstops)|Define as paradas de tabulação em um controle de edição de várias linhas.|
|[CEdit::ShowBalloonTip](#showballoontip)|Exibe uma dica de balão associada ao controle de edição atual.|
|[CEdit::Undo](#undo)|Reverte a última operação de edição de controle.|

## <a name="remarks"></a>Comentários

Um controle de edição é uma janela filho retangular na qual o usuário pode inserir texto.

Você pode criar um controle de edição a partir de um modelo de caixa de diálogo ou diretamente no seu código. Em ambos os casos, primeiro chame o `CEdit` Construtor para construir `CEdit` o objeto e, em seguida, chame a função [criar](#create) membro para criar o controle de `CEdit` edição do Windows e anexá-lo ao objeto.

A construção pode ser um processo de uma etapa em uma classe derivada `CEdit`de. Escreva um construtor para a classe derivada e chame `Create` de dentro do construtor.

`CEdit`herda uma funcionalidade significativa `CWnd`do. Para definir e recuperar texto de um `CEdit` objeto, use as `CWnd` funções de membro [SetWindowText](cwnd-class.md#setwindowtext) e [GetWindowText](cwnd-class.md#getwindowtext), que definem ou obtêm todo o conteúdo de um controle de edição, mesmo que ele seja um controle de várias linhas. As linhas de texto em um controle de várias linhas são separadas por sequências de caracteres ' \r\n '. Além disso, se um controle de edição for Multiline, obter e definir parte do texto do controle chamando as funções de membro `CEdit`[getline](#getline), [SetSel](#setsel), [GetSel](#getsel)e [ReplaceSel](#replacesel).

Se você quiser manipular mensagens de notificação do Windows enviadas por um controle de edição para seu pai (geralmente uma classe `CDialog`derivada de), adicione uma entrada de mapa de mensagem e uma função de membro de manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

  **ON_** _NOTIFICATION_ **(** _id_ **,** _memberFxn_ **)**

em `id` que especifica a ID da janela filho do controle de edição que envia a `memberFxn` notificação e é o nome da função de membro pai que você escreveu para manipular a notificação.

O protótipo de função do pai é o seguinte:

**afx_msg** void memberFxn **();**

A seguir está uma lista de possíveis entradas de mapa de mensagem e uma descrição dos casos em que eles seriam enviados para o pai:

- ON_EN_CHANGE o usuário executou uma ação que pode ter alterado o texto em um controle de edição. Ao contrário da mensagem de notificação EN_UPDATE, essa mensagem de notificação é enviada depois que o Windows atualiza a exibição.

- ON_EN_ERRSPACE o controle de edição não pode alocar memória suficiente para atender a uma solicitação específica.

- ON_EN_HSCROLL o usuário clica na barra de rolagem horizontal do controle de edição. A janela pai é notificada antes da atualização da tela.

- ON_EN_KILLFOCUS o controle de edição perde o foco de entrada.

- ON_EN_MAXTEXT a inserção atual excedeu o número especificado de caracteres para o controle de edição e foi truncado. Também é enviado quando um controle de edição não tem o estilo ES_AUTOHSCROLL e o número de caracteres a serem inseridos excede a largura do controle de edição. Também é enviado quando um controle de edição não tem o estilo ES_AUTOVSCROLL e o número total de linhas resultante de uma inserção de texto excede a altura do controle de edição.

- ON_EN_SETFOCUS enviado quando um controle de edição recebe o foco de entrada.

- ON_EN_UPDATE o controle de edição está prestes a exibir o texto alterado. Enviado depois que o controle tiver formatado o texto, mas antes de fazer uma triagem do texto para que o tamanho da janela possa ser alterado, se necessário.

- ON_EN_VSCROLL o usuário clica na barra de rolagem vertical do controle de edição. A janela pai é notificada antes da atualização da tela.

Se você criar um `CEdit` objeto dentro de uma caixa de diálogo `CEdit` , o objeto será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um `CEdit` objeto de um recurso de caixa de diálogo usando o editor `CEdit` de caixa de diálogo, o objeto será destruído automaticamente quando o usuário fechar a caixa de diálogo.

Se você criar um `CEdit` objeto em uma janela, talvez também precise destruí-lo. Se você criar o `CEdit` objeto na pilha, ele será destruído automaticamente. Se você criar o `CEdit` objeto no heap usando a **nova** função, deverá chamar **delete** no objeto para destruí-lo quando o usuário encerrar o controle de edição do Windows. Se você alocar qualquer memória no `CEdit` objeto, substitua o `CEdit` destruidor para descartar as alocações.

Para modificar determinados estilos em um controle de edição (como ES_READONLY), você deve enviar mensagens específicas para o controle em vez de usar [ModifyStyle](cwnd-class.md#modifystyle). Consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles) na SDK do Windows.

Para obter mais informações `CEdit`sobre o, consulte [controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](cobject-class.md)

[CCmdTarget](ccmdtarget-class.md)

[CWnd](cwnd-class.md)

`CEdit`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="canundo"></a>  CEdit::CanUndo

Chame essa função para determinar se a última operação de edição pode ser desfeita.

```
BOOL CanUndo() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a última operação de edição puder ser desfeita por uma `Undo` chamada para a função membro; 0 se não puder ser desfeito.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_CANUNDO](/windows/win32/Controls/em-canundo) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: Undo](#undo).

##  <a name="cedit"></a>  CEdit::CEdit

Constrói um objeto `CEdit`.

```
CEdit();
```

### <a name="remarks"></a>Comentários

Use [Create](#create) para construir o controle de edição do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#1](../../mfc/reference/codesnippet/cpp/cedit-class_1.cpp)]

##  <a name="charfrompos"></a>  CEdit::CharFromPos

Chame essa função para recuperar a linha de base zero e os índices de caracteres do caractere mais próximo ao ponto especificado neste `CEdit` controle

```
int CharFromPos(CPoint pt) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
As coordenadas de um ponto na área do cliente deste `CEdit` objeto.

### <a name="return-value"></a>Valor de retorno

O índice de caracteres na palavra de ordem inferior e o índice de linha na palavra de ordem superior.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função de membro está disponível a partir do Windows 95 e do Windows NT 4,0.

Para obter mais informações, consulte [EM_CHARFROMPOS](/windows/win32/Controls/em-charfrompos) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#3](../../mfc/reference/codesnippet/cpp/cedit-class_2.cpp)]

##  <a name="clear"></a>  CEdit::Clear

Chame essa função para excluir (limpar) a seleção atual (se houver) no controle de edição.

```
void Clear();
```

### <a name="remarks"></a>Comentários

A exclusão realizada pelo `Clear` pode ser desfeita chamando a função de membro [Undo](#undo) .

Para excluir a seleção atual e inserir o conteúdo excluído na área de transferência, chame a função de membro [Cut](#cut) .

Para obter mais informações, consulte [WM_CLEAR](/windows/win32/dataxchg/wm-clear) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#4](../../mfc/reference/codesnippet/cpp/cedit-class_3.cpp)]

##  <a name="copy"></a>  CEdit::Copy

Chame essa função para copiar a seleção atual (se houver) no controle de edição para a área de transferência no formato CF_TEXT.

```
void Copy();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [WM_COPY](/windows/win32/dataxchg/wm-copy) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#5](../../mfc/reference/codesnippet/cpp/cedit-class_4.cpp)]

##  <a name="create"></a>  CEdit::Create

Cria o controle de edição do Windows e o anexa ao `CEdit` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de edição. Aplicar qualquer combinação de [estilos de edição](styles-used-by-mfc.md#edit-styles) ao controle.

*rect*<br/>
Especifica o tamanho e a posição do controle de edição. Pode ser um `CRect` objeto ou `RECT` uma estrutura.

*pParentWnd*<br/>
Especifica a janela pai do controle de edição (geralmente `CDialog`um). Ele não deve ser nulo.

*nID*<br/>
Especifica a ID do controle de edição.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização for bem-sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CEdit` objeto em duas etapas. Primeiro, chame o `CEdit` Construtor e, em `Create`seguida, chame, que cria o controle de edição do Windows e `CEdit` o anexa ao objeto.

Quando `Create` o é executado, o Windows envia as mensagens [WM_NCCREATE](/windows/win32/winmsg/wm-nccreate), [WM_NCCALCSIZE](/windows/win32/winmsg/wm-nccalcsize), [WM_CREATE](/windows/win32/winmsg/wm-create)e [WM_GETMINMAXINFO](/windows/win32/winmsg/wm-getminmaxinfo) para o controle de edição.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate](cwnd-class.md#onnccreate), [OnNcCalcSize](cwnd-class.md#onnccalcsize), [OnCreate](cwnd-class.md#oncreate)e [OnGetMinMaxInfo](cwnd-class.md#ongetminmaxinfo) na `CWnd` classe base. Para estender a manipulação de mensagens padrão, derive uma `CEdit`classe de, adicione um mapa de mensagem à nova classe e substitua as funções de membro do manipulador de mensagens acima. Substitua `OnCreate`, por exemplo, para executar a inicialização necessária para a nova classe.

Aplique os seguintes [estilos de janela](styles-used-by-mfc.md#window-styles) a um controle de edição.

- WS_CHILD sempre

- WS_VISIBLE geralmente

- WS_DISABLED raramente

- WS_GROUP para controles de grupo

- WS_TABSTOP para incluir o controle de edição na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#2](../../mfc/reference/codesnippet/cpp/cedit-class_5.cpp)]

##  <a name="cut"></a>  CEdit::Cut

Chame essa função para excluir (recortar) a seleção atual (se houver) no controle de edição e copie o texto excluído para a área de transferência no formato CF_TEXT.

```
void Cut();
```

### <a name="remarks"></a>Comentários

A exclusão realizada pelo `Cut` pode ser desfeita chamando a função de membro [Undo](#undo) .

Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame a função de membro [Clear](#clear) .

Para obter mais informações, consulte [WM_CUT](/windows/win32/dataxchg/wm-cut) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#6](../../mfc/reference/codesnippet/cpp/cedit-class_6.cpp)]

##  <a name="emptyundobuffer"></a>  CEdit::EmptyUndoBuffer

Chame essa função para redefinir (limpar) o sinalizador de desfazer de um controle de edição.

```
void EmptyUndoBuffer();
```

### <a name="remarks"></a>Comentários

O controle de edição agora não será capaz de desfazer a última operação. O sinalizador de desfazer é definido sempre que uma operação dentro do controle de edição pode ser desfeita.

O sinalizador de desfazer é limpo automaticamente sempre que as funções de membro [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) ou [SetHandle](#sethandle) `CWnd` são chamadas.

Para obter mais informações, consulte [EM_EMPTYUNDOBUFFER](/windows/win32/Controls/em-emptyundobuffer) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#7](../../mfc/reference/codesnippet/cpp/cedit-class_7.cpp)]

##  <a name="fmtlines"></a>  CEdit::FmtLines

Chame essa função para definir a inclusão de caracteres de quebra de linha flexível ativados ou desativados dentro de um controle de edição de várias linhas.

```
BOOL FmtLines(BOOL bAddEOL);
```

### <a name="parameters"></a>Parâmetros

*bAddEOL*<br/>
Especifica se os caracteres de quebra de linha flexível devem ser inseridos. Um valor TRUE insere os caracteres; um valor FALSE remove-os.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se ocorrer alguma formatação; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma quebra de linha suave consiste em dois retornos de carro e um feed de linha inserido no final de uma linha que é quebrada devido à quebra automática da palavra. Uma quebra de linha rígida consiste em um retorno de carro e um feed de linha. As linhas que terminam com uma quebra de linha rígida não `FmtLines`são afetadas pelo.

O Windows só responderá se `CEdit` o objeto for um controle de edição de várias linhas.

`FmtLines`afeta apenas o buffer retornado por [GetHandle](#gethandle) e o texto retornado por [WM_GETTEXT](/windows/win32/winmsg/wm-gettext). Ele não tem impacto na exibição do texto dentro do controle de edição.

Para obter mais informações, consulte [EM_FMTLINES](/windows/win32/Controls/em-fmtlines) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#8](../../mfc/reference/codesnippet/cpp/cedit-class_8.cpp)]

##  <a name="getcuebanner"></a>  CEdit::GetCueBanner

Recupera o texto que é exibido como a indicação de texto, ou Tip, em um controle de edição quando o controle está vazio.

```
BOOL GetCueBanner(
    LPWSTR lpszText,
    int cchText) const;

CString GetCueBanner() const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
fora Um ponteiro para uma cadeia de caracteres que contém o texto de indicação.

*cchText*<br/>
no O número de caracteres que podem ser recebidos. Esse número inclui o caractere nulo de terminação.

### <a name="return-value"></a>Valor de retorno

Para a primeira sobrecarga, TRUE se o método for bem-sucedido; caso contrário, FALSE.

Para a segunda sobrecarga, um [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de indicação se o método for bem-sucedido; caso contrário, a cadeia de caracteres vazia ("").

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [EM_GETCUEBANNER](/windows/win32/Controls/em-getcuebanner) , que é descrita na SDK do Windows. Para obter mais informações, consulte a macro [Edit_GetCueBannerText](/windows/win32/api/commctrl/nf-commctrl-edit_getcuebannertext) .

##  <a name="getfirstvisibleline"></a>  CEdit::GetFirstVisibleLine

Chame essa função para determinar a linha visível mais alta em um controle de edição.

```
int GetFirstVisibleLine() const;
```

### <a name="return-value"></a>Valor de retorno

O índice de base zero da linha visível superior. Para controles de edição de linha única, o valor de retorno é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETFIRSTVISIBLELINE](/windows/win32/Controls/em-getfirstvisibleline) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#9](../../mfc/reference/codesnippet/cpp/cedit-class_9.cpp)]

##  <a name="gethandle"></a>  CEdit::GetHandle

Chame essa função para recuperar um identificador para a memória alocada atualmente para um controle de edição de várias linhas.

```
HLOCAL GetHandle() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador de memória local que identifica o buffer que contém o conteúdo do controle de edição. Se ocorrer um erro, como enviar a mensagem para um controle de edição de linha única, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

O identificador é um identificador de memória local e pode ser usado por qualquer uma das funções de memória **local** do Windows que usam um identificador de memória local como um parâmetro.

`GetHandle`é processado somente por controles de edição de várias linhas.

Chame `GetHandle` um controle de edição de várias linhas em uma caixa de diálogo somente se a caixa de diálogo tiver sido criada com o sinalizador de estilo DS_LOCALEDIT definido. Se o estilo DS_LOCALEDIT não for definido, você ainda receberá um valor de retorno diferente de zero, mas não poderá usar o valor retornado.

> [!NOTE]
> `GetHandle`não funcionará com o Windows 95/98. Se você chamar `GetHandle` no Windows 95/98, retornará NULL. `GetHandle`funcionará conforme documentado no Windows NT, versões 3,51 e posteriores.

Para obter mais informações, consulte [EM_GETHANDLE](/windows/win32/Controls/em-gethandle) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#10](../../mfc/reference/codesnippet/cpp/cedit-class_10.cpp)]

##  <a name="gethighlight"></a>  CEdit::GetHighlight

Obtém os índices do primeiro e do último caracteres em um intervalo de texto que é realçado no controle de edição atual.

```
BOOL GetHighlight(
    int* pichStart,
    int* pichEnd) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pichStart*|fora Índice de base zero do primeiro caractere no intervalo de texto que é realçado.|
|*pichEnd*|fora Índice de base zero do último caractere no intervalo de texto que é realçado.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [EM_GETHILITE](/windows/win32/Controls/em-gethilite) , que é descrita na SDK do Windows. Ambos `SetHighlight` e`GetHighlight` estão atualmente habilitados para compilações Unicode somente.

##  <a name="getlimittext"></a>  CEdit::GetLimitText

Chame essa função de membro para obter o limite de texto `CEdit` para este objeto.

```
UINT GetLimitText() const;
```

### <a name="return-value"></a>Valor de retorno

O limite de texto atual, em TCHARs, para `CEdit` este objeto.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em TCHARs, que o controle de edição pode aceitar.

> [!NOTE]
>  Essa função de membro está disponível a partir do Windows 95 e do Windows NT 4,0.

Para obter mais informações, consulte [EM_GETLIMITTEXT](/windows/win32/Controls/em-getlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#11](../../mfc/reference/codesnippet/cpp/cedit-class_11.cpp)]

##  <a name="getline"></a>  CEdit::GetLine

Chame essa função para recuperar uma linha de texto de um controle de edição e a coloca em *lpszBuffer*.

```
int GetLine(
    int nIndex,
    LPTSTR lpszBuffer) const;

int GetLine(
    int nIndex,
    LPTSTR lpszBuffer,
    int nMaxLength) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Especifica o número de linha a ser recuperado de um controle de edição de várias linhas. Os números de linha são baseados em zero; um valor de 0 especifica a primeira linha. Esse parâmetro é ignorado por um controle de edição de linha única.

*lpszBuffer*<br/>
Aponta para o buffer que recebe uma cópia da linha. A primeira palavra do buffer deve especificar o número máximo de TCHARs que podem ser copiadas para o buffer.

*nMaxLength*<br/>
Especifica o número máximo de caracteres TCHAR que podem ser copiados para o buffer. `GetLine`coloca esse valor na primeira palavra de *lpszBuffer* antes de fazer a chamada para o Windows.

### <a name="return-value"></a>Valor de retorno

O número de caracteres realmente copiados. O valor de retorno será 0 se o número de linha especificado por *nIndex* for maior que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

A linha copiada não contém um caractere de terminação nula.

Para obter mais informações, consulte [EM_GETLINE](/windows/win32/Controls/em-getline) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: GetLineCount](#getlinecount).

##  <a name="getlinecount"></a>  CEdit::GetLineCount

Chame essa função para recuperar o número de linhas em um controle de edição de várias linhas.

```
int GetLineCount() const;
```

### <a name="return-value"></a>Valor de retorno

Um inteiro que contém o número de linhas no controle de edição de várias linhas. Se nenhum texto tiver sido inserido no controle de edição, o valor de retorno será 1.

### <a name="remarks"></a>Comentários

`GetLineCount`é processado somente por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_GETLINECOUNT](/windows/win32/Controls/em-getlinecount) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#12](../../mfc/reference/codesnippet/cpp/cedit-class_12.cpp)]

##  <a name="getmargins"></a>  CEdit::GetMargins

Chame essa função de membro para recuperar as margens esquerda e direita deste controle de edição.

```
DWORD GetMargins() const;
```

### <a name="return-value"></a>Valor de retorno

A largura da margem esquerda na palavra de ordem inferior e a largura da margem direita na palavra de ordem superior.

### <a name="remarks"></a>Comentários

As margens são medidas em pixels.

> [!NOTE]
>  Essa função de membro está disponível a partir do Windows 95 e do Windows NT 4,0.

Para obter mais informações, consulte [EM_GETMARGINS](/windows/win32/Controls/em-getmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEditView:: GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="getmodify"></a>  CEdit::GetModify

Chame essa função para determinar se o conteúdo de um controle de edição foi modificado.

```
BOOL GetModify() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conteúdo do controle de edição tiver sido modificado; 0 se eles permaneceram inalterados.

### <a name="remarks"></a>Comentários

O Windows mantém um sinalizador interno que indica se o conteúdo do controle de edição foi alterado. Esse sinalizador é limpo quando o controle de edição é criado pela primeira vez e também pode ser limpo chamando a função de membro [SetModify](#setmodify).

Para obter mais informações, consulte [EM_GETMODIFY](/windows/win32/Controls/em-getmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#13](../../mfc/reference/codesnippet/cpp/cedit-class_13.cpp)]

##  <a name="getpasswordchar"></a>  CEdit::GetPasswordChar

Chame essa função para recuperar o caractere de senha exibido em um controle de edição quando o usuário inserir texto.

```
TCHAR GetPasswordChar() const;
```

### <a name="return-value"></a>Valor de retorno

Especifica o caractere a ser exibido em vez do caractere que o usuário digitou. O valor de retorno será nulo se não existir nenhum caractere de senha.

### <a name="remarks"></a>Comentários

Se você criar o controle de edição com o estilo ES_PASSWORD, a DLL que dá suporte ao controle determinará o caractere de senha padrão. O manifesto ou o método [InitCommonControlsEx](/windows/win32/api/commctrl/nf-commctrl-initcommoncontrolsex) determina qual DLL dá suporte ao controle de edição. Se user32. dll der suporte ao controle de edição, o caractere de senha padrão será asterisco (' * ', U + 002A). Se o Comctl32. dll versão 6 der suporte ao controle de edição, o caractere padrão será círculo preto (' ● ', U + 25CF). Para obter mais informações sobre qual DLL e versão dá suporte aos controles comuns, consulte [shell e versões de controles comuns](/previous-versions/windows/desktop/legacy/bb776779\(v=vs.85\)).

Esse método envia a mensagem [EM_GETPASSWORDCHAR](/windows/win32/Controls/em-getpasswordchar) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#14](../../mfc/reference/codesnippet/cpp/cedit-class_14.cpp)]

##  <a name="getrect"></a>  CEdit::GetRect

Chame essa função para obter o retângulo de formatação de um controle de edição.

```
void GetRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para a `RECT` estrutura que recebe o retângulo de formatação.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição.

O retângulo de formatação de um controle de edição de várias linhas pode ser modificado pelas funções de membro [SetRect](#setrect) e [SetRectNP](#setrectnp) .

Para obter mais informações, consulte [EM_GETRECT](/windows/win32/Controls/em-getrect) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: LimitText](#limittext).

##  <a name="getsel"></a>  CEdit::GetSel

Chame essa função para obter as posições de caractere inicial e final da seleção atual (se houver) em um controle de edição, usando o valor de retorno ou os parâmetros.

```
DWORD GetSel() const;

void GetSel(
    int& nStartChar,
    int& nEndChar) const;
```

### <a name="parameters"></a>Parâmetros

*nStartChar*<br/>
Referência a um inteiro que receberá a posição do primeiro caractere na seleção atual.

*nEndChar*<br/>
Referência a um inteiro que receberá a posição do primeiro caractere não selecionado após o final da seleção atual.

### <a name="return-value"></a>Valor de retorno

A versão que retorna um DWORD retorna um valor que contém a posição inicial na palavra de ordem inferior e a posição do primeiro caractere não selecionado após o final da seleção na palavra de ordem superior.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETSEL](/windows/win32/Controls/em-getsel) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#15](../../mfc/reference/codesnippet/cpp/cedit-class_15.cpp)]

##  <a name="hideballoontip"></a>  CEdit::HideBalloonTip

Oculta qualquer dica de balão associada ao controle de edição atual.

```
BOOL HideBalloonTip();
```

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função envia a mensagem [EM_HIDEBALLOONTIP](/windows/win32/Controls/em-hideballoontip) , que é descrita na SDK do Windows.

##  <a name="limittext"></a>  CEdit::LimitText

Chame essa função para limitar o comprimento do texto que o usuário pode inserir em um controle de edição.

```
void LimitText(int nChars = 0);
```

### <a name="parameters"></a>Parâmetros

*nChars*<br/>
Especifica o comprimento (em TCHARs) do texto que o usuário pode inserir. Se esse parâmetro for 0, o tamanho do texto será definido como UINT_MAX bytes. Este é o comportamento padrão.

### <a name="remarks"></a>Comentários

Alterar o limite de texto restringe apenas o texto que o usuário pode inserir. Ele não tem nenhum efeito em nenhum texto que já esteja no controle de edição, nem afeta o tamanho do texto copiado para o controle de edição pela função membro [SetWindowText](cwnd-class.md#setwindowtext) no `CWnd`. Se um aplicativo usar a `SetWindowText` função para posicionar mais texto em um controle de edição do que é especificado na `LimitText`chamada para, o usuário poderá excluir qualquer um dos textos dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substitua o texto existente por um novo texto, a menos que a exclusão da seleção atual faça com que o texto fique abaixo do limite de texto.

> [!NOTE]
>  No Win32 (Windows NT e Windows 95/98), [SetLimitText](#setlimittext) substitui essa função.

Para obter mais informações, consulte [EM_LIMITTEXT](/windows/win32/Controls/em-limittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#17](../../mfc/reference/codesnippet/cpp/cedit-class_16.cpp)]

##  <a name="linefromchar"></a>  CEdit::LineFromChar

Chame essa função para recuperar o número de linha da linha que contém o índice de caracteres especificado.

```
int LineFromChar(int nIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o valor de índice baseado em zero para o caractere desejado no texto do controle de edição ou contém-1. Se *nIndex* for-1, ele especificará a linha atual, ou seja, a linha que contém o cursor.

### <a name="return-value"></a>Valor de retorno

O número de linha com base em zero da linha que contém o índice de caracteres especificado por *nIndex*. Se *nIndex* for-1, o número da linha que contém o primeiro caractere da seleção será retornado. Se não houver seleção, o número da linha atual será retornado.

### <a name="remarks"></a>Comentários

Um índice de caracteres é o número de caracteres do início do controle de edição.

Essa função de membro é usada apenas por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEFROMCHAR](/windows/win32/Controls/em-linefromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#18](../../mfc/reference/codesnippet/cpp/cedit-class_17.cpp)]

##  <a name="lineindex"></a>  CEdit::LineIndex

Chame essa função para recuperar o índice de caracteres de uma linha em um controle de edição de várias linhas.

```
int LineIndex(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLine*<br/>
Contém o valor de índice para a linha desejada no texto do controle de edição ou contém-1. Se *nLinha* for-1, ele especificará a linha atual, ou seja, a linha que contém o cursor.

### <a name="return-value"></a>Valor de retorno

O índice de caracteres da linha especificada em *nLinha* ou-1 se o número de linha especificado for maior que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

O índice de caracteres é o número de caracteres desde o início do controle de edição até a linha especificada.

Essa função de membro só é processada por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEINDEX](/windows/win32/controls/em-lineindex) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#19](../../mfc/reference/codesnippet/cpp/cedit-class_18.cpp)]

##  <a name="linelength"></a>  CEdit::LineLength

Recupera o comprimento de uma linha em um controle de edição.

```
int LineLength(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLine*<br/>
O índice de base zero de um caractere na linha cujo comprimento deve ser recuperado. O valor padrão é -1.

### <a name="return-value"></a>Valor de retorno

Para controles de edição de linha única, o valor de retorno é o comprimento, em TCHARs, do texto no controle de edição.

Para controles de edição de várias linhas, o valor de retorno é o comprimento, em TCHARs, da linha especificada pelo parâmetro *nLinha* . Para texto ANSI, o comprimento é o número de bytes na linha; para texto Unicode, o comprimento é o número de caracteres na linha. O comprimento não inclui o caractere de retorno de carro no final da linha.

Se o parâmetro *nLinha* for maior que o número de caracteres no controle, o valor de retorno será zero.

Se o parâmetro *nLinha* for-1, o valor de retorno será o número de caracteres não selecionados nas linhas que contêm os caracteres selecionados. Por exemplo, se a seleção se estender do quarto caractere de uma linha pelo oitavo caractere do final da linha seguinte, o valor de retorno será 10. Ou seja, três caracteres na primeira linha e sete no próximo.

Para obter mais informações sobre o tipo TCHAR, consulte a linha TCHAR na tabela em [tipos de dados do Windows](/windows/win32/WinProg/windows-data-types).

### <a name="remarks"></a>Comentários

Esse método é suportado pela mensagem [EM_LINELENGTH](/windows/win32/Controls/em-linelength) , que é descrita na SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: LineIndex](#lineindex).

##  <a name="linescroll"></a>  CEdit::LineScroll

Chame essa função para rolar o texto de um controle de edição de várias linhas.

```
void LineScroll(
    int nLines,
    int nChars = 0);
```

### <a name="parameters"></a>Parâmetros

*nLines*<br/>
Especifica o número de linhas a rolar verticalmente.

*nChars*<br/>
Especifica o número de posições de caractere a rolar horizontalmente. Esse valor será ignorado se o controle de edição tiver o estilo ES_RIGHT ou ES_CENTER.

### <a name="remarks"></a>Comentários

Essa função de membro é processada apenas por controles de edição de várias linhas.

O controle de edição não rola verticalmente após a última linha de texto no controle de edição. Se a linha atual mais o número de linhas especificado por *nLines* exceder o número total de linhas no controle de edição, o valor será ajustado de forma que a última linha do controle de edição seja rolada para a parte superior da janela de controle de edição.

`LineScroll`pode ser usado para rolar horizontalmente além do último caractere de qualquer linha.

Para obter mais informações, consulte [EM_LINESCROLL](/windows/win32/Controls/em-linescroll) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: GetFirstVisibleLine](#getfirstvisibleline).

##  <a name="paste"></a>  CEdit::Paste

Chame essa função para inserir os dados da área de transferência no `CEdit` ponto de inserção.

```
void Paste();
```

### <a name="remarks"></a>Comentários

Os dados só serão inseridos se a área de transferência contiver dados no formato CF_TEXT.

Para obter mais informações, consulte [WM_PASTE](/windows/win32/dataxchg/wm-paste) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#20](../../mfc/reference/codesnippet/cpp/cedit-class_19.cpp)]

##  <a name="posfromchar"></a>  CEdit::PosFromChar

Chame essa função para obter a posição (canto superior esquerdo) de um determinado caractere dentro deste `CEdit` objeto.

```
CPoint PosFromChar(UINT nChar) const;
```

### <a name="parameters"></a>Parâmetros

*nChar*<br/>
O índice de base zero do caractere especificado.

### <a name="return-value"></a>Valor de retorno

As coordenadas do canto superior esquerdo do caractere especificado por *nchar*.

### <a name="remarks"></a>Comentários

O caractere é especificado fornecendo seu valor de índice baseado em zero. Se *nchar* for maior do que o índice do último caractere neste `CEdit` objeto, o valor de retorno especificará as coordenadas da posição do caractere que ultrapassou o `CEdit` último caractere neste objeto.

> [!NOTE]
>  Essa função de membro está disponível a partir do Windows 95 e do Windows NT 4,0.

Para obter mais informações, consulte [EM_POSFROMCHAR](/windows/win32/Controls/em-posfromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: LineFromChar](#linefromchar).

##  <a name="replacesel"></a>  CEdit::ReplaceSel

Chame essa função para substituir a seleção atual em um controle de edição pelo texto especificado por *lpszNewText*.

```
void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszNewText*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o texto de substituição.

*bCanUndo*<br/>
Para especificar que essa função pode ser desfeita, defina o valor desse parâmetro como TRUE. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

Substitui apenas uma parte do texto em um controle de edição. Se você quiser substituir todo o texto, use a função de membro [CWnd:: SetWindowText](cwnd-class.md#setwindowtext) .

Se não houver seleção atual, o texto de substituição será inserido no local do cursor atual.

Para obter mais informações, consulte [EM_REPLACESEL](/windows/win32/Controls/em-replacesel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: LineIndex](#lineindex).

##  <a name="setcuebanner"></a>  CEdit::SetCueBanner

Define o texto que é exibido como a indicação de texto, ou Tip, em um controle de edição quando o controle está vazio.

```
BOOL SetCueBanner(LPCWSTR lpszText);

BOOL SetCueBanner(
    LPCWSTR lpszText,
    BOOL fDrawWhenFocused = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
no Ponteiro para uma cadeia de caracteres que contém a indicação a ser exibida no controle de edição.

*fDrawWhenFocused*<br/>
no Se for FALSE, a faixa de indicação não será desenhada quando o usuário clicar no controle de edição e dará ao controle o foco.

Se for TRUE, a faixa de indicação será desenhada mesmo quando o controle tiver foco. A faixa de indicação desaparece quando o usuário começa a digitar no controle.

O valor padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [EM_SETCUEBANNER](/windows/win32/Controls/em-setcuebanner) , que é descrita na SDK do Windows. Para obter mais informações, consulte a macro [Edit_SetCueBannerTextFocused](/windows/win32/api/commctrl/nf-commctrl-edit_setcuebannertextfocused) .

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o método [CEdit:: SetCueBanner](#setcuebanner) .

[!code-cpp[NVC_MFC_CEdit_s1#2](../../mfc/reference/codesnippet/cpp/cedit-class_20.cpp)]

##  <a name="sethandle"></a>  CEdit::SetHandle

Chame essa função para definir o identificador para a memória local que será usada por um controle de edição de várias linhas.

```
void SetHandle(HLOCAL hBuffer);
```

### <a name="parameters"></a>Parâmetros

*hBuffer*<br/>
Contém um identificador para a memória local. Esse identificador deve ter sido criado por uma chamada anterior à função [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc) do Windows usando o sinalizador LMEM_MOVEABLE. Pressupõe-se que a memória contenha uma cadeia de caracteres terminada em nulo. Se esse não for o caso, o primeiro byte da memória alocada deverá ser definido como 0.

### <a name="remarks"></a>Comentários

O controle de edição usará esse buffer para armazenar o texto atualmente exibido em vez de alocar seu próprio buffer.

Essa função de membro é processada apenas por controles de edição de várias linhas.

Antes que um aplicativo defina um novo identificador de memória, ele deve usar a função de membro [GetHandle](#gethandle) para obter o identificador para o buffer de memória atual e liberar essa memória usando a função do Windows `LocalFree`.

`SetHandle`limpa o buffer de desfazer (a função de membro [cancelar](#canundo) e, em seguida,retorna 0) e o sinalizador de modificação interna (a função de membro [GetModify](#getmodify), em seguida, retorna 0). A janela de controle de edição é redesenhada.

Você poderá usar essa função de membro em um controle de edição de várias linhas em uma caixa de diálogo somente se tiver criado a caixa de diálogo com o sinalizador de estilo DS_LOCALEDIT definido.

> [!NOTE]
> `GetHandle`não funcionará com o Windows 95/98. Se você chamar `GetHandle` no Windows 95/98, retornará NULL. `GetHandle`funcionará conforme documentado no Windows NT, versões 3,51 e posteriores.

Para obter mais informações, consulte [EM_SETHANDLE](/windows/win32/Controls/em-sethandle), [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc)e [LocalFree](/windows/win32/api/winbase/nf-winbase-localfree) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#22](../../mfc/reference/codesnippet/cpp/cedit-class_21.cpp)]

##  <a name="sethighlight"></a>  CEdit::SetHighlight

Realça um intervalo de texto que é exibido no controle de edição atual.

```
void SetHighlight(
    int ichStart,
    int ichEnd);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ichStart*|no Índice de base zero do primeiro caractere no intervalo de texto a ser realçado.|
|*ichEnd*|no Índice de base zero do último caractere no intervalo de texto a ser realçado.|

### <a name="remarks"></a>Comentários

Esse método envia a mensagem [EM_SETHILITE](/windows/win32/Controls/em-sethilite) , que é descrita na SDK do Windows.  Esse método envia a mensagem [EM_SETHILITE](/windows/win32/Controls/em-sethilite) , que é descrita na SDK do Windows. Ambos `SetHighlight` e`GetHighlight` são habilitados apenas para compilações Unicode.

##  <a name="setlimittext"></a>  CEdit::SetLimitText

Chame essa função de membro para definir o limite de texto `CEdit` para esse objeto.

```
void SetLimitText(UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*nMax*<br/>
O novo limite de texto, em caracteres.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em caracteres, que o controle de edição pode aceitar.

Alterar o limite de texto restringe apenas o texto que o usuário pode inserir. Ele não tem nenhum efeito em nenhum texto que já esteja no controle de edição, nem afeta o tamanho do texto copiado para o controle de edição pela função membro [SetWindowText](cwnd-class.md#setwindowtext) no `CWnd`. Se um aplicativo usar a `SetWindowText` função para posicionar mais texto em um controle de edição do que é especificado na `LimitText`chamada para, o usuário poderá excluir qualquer um dos textos dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substitua o texto existente por um novo texto, a menos que a exclusão da seleção atual faça com que o texto fique abaixo do limite de texto.

Essa função substitui [LimitText](#limittext) no Win32.

Para obter mais informações, consulte [EM_SETLIMITTEXT](/windows/win32/Controls/em-setlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEditView:: GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="setmargins"></a>  CEdit::SetMargins

Chame esse método para definir as margens esquerda e direita deste controle de edição.

```
void SetMargins(
    UINT nLeft,
    UINT nRight);
```

### <a name="parameters"></a>Parâmetros

*nLeft*<br/>
A largura da nova margem esquerda, em pixels.

*nRight*<br/>
A largura da nova margem direita, em pixels.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função de membro está disponível a partir do Windows 95 e do Windows NT 4,0.

Para obter mais informações, consulte [EM_SETMARGINS](/windows/win32/Controls/em-setmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEditView:: GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="setmodify"></a>  CEdit::SetModify

Chame essa função para definir ou limpar o sinalizador modificado para um controle de edição.

```
void SetModify(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModified*<br/>
Um valor TRUE indica que o texto foi modificado e um valor FALSE indica que ele não é modificado. Por padrão, o sinalizador modificado é definido.

### <a name="remarks"></a>Comentários

O sinalizador modificado indica se o texto dentro do controle de edição foi modificado ou não. Ele é definido automaticamente sempre que o usuário altera o texto. Seu valor pode ser recuperado com a função de membro [GetModify](#getmodify).

Para obter mais informações, consulte [EM_SETMODIFY](/windows/win32/Controls/em-setmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo para [CEdit:: GetModify](#getmodify).

##  <a name="setpasswordchar"></a>  CEdit::SetPasswordChar

Chame essa função para definir ou remover um caractere de senha exibido em um controle de edição quando o usuário digitar o texto.

```
void SetPasswordChar(TCHAR ch);
```

### <a name="parameters"></a>Parâmetros

*ch*<br/>
Especifica o caractere a ser exibido no lugar do caractere digitado pelo usuário. Se *ch* for 0, os caracteres reais digitados pelo usuário serão exibidos.

### <a name="remarks"></a>Comentários

Quando um caractere de senha é definido, esse caractere é exibido para cada caractere que o usuário digita.

Essa função de membro não tem nenhum efeito em um controle de edição de várias linhas.

Quando a `SetPasswordChar` função de membro for chamada `CEdit` , o redesenhará todos os caracteres visíveis usando o caractere especificado por *ch*.

Se o controle de edição for criado com o estilo [ES_PASSWORD](styles-used-by-mfc.md#edit-styles) , o caractere de senha padrão será definido como um <strong>\*</strong>asterisco (). Esse estilo será removido se `SetPasswordChar` for chamado com *ch* definido como 0.

Para obter mais informações, consulte [EM_SETPASSWORDCHAR](/windows/win32/Controls/em-setpasswordchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#16](../../mfc/reference/codesnippet/cpp/cedit-class_22.cpp)]

##  <a name="setreadonly"></a>  CEdit::SetReadOnly

Chama essa função para definir o estado somente leitura de um controle de edição.

```
BOOL SetReadOnly(BOOL bReadOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bReadOnly*<br/>
Especifica se deve ser definido ou removido o estado somente leitura do controle de edição. Um valor TRUE define o estado como somente leitura; um valor FALSE define o estado como leitura/gravação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida ou 0 se ocorrer um erro.

### <a name="remarks"></a>Comentários

A configuração atual pode ser encontrada testando o sinalizador [ES_READONLY](styles-used-by-mfc.md#edit-styles) no valor de retorno de [CWnd:: GetStyle](cwnd-class.md#getstyle).

Para obter mais informações, consulte [EM_SETREADONLY](/windows/win32/Controls/em-setreadonly) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#23](../../mfc/reference/codesnippet/cpp/cedit-class_23.cpp)]

##  <a name="setrect"></a>  CEdit::SetRect

Chame essa função para definir as dimensões de um retângulo usando as coordenadas especificadas.

```
void SetRect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para a `RECT` estrutura ou `CRect` o objeto que especifica as novas dimensões do retângulo de formatação.

### <a name="remarks"></a>Comentários

Esse membro é processado somente por controles de edição de várias linhas.

Use `SetRect` para definir o retângulo de formatação de um controle de edição de várias linhas. O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição. Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo da área do cliente da janela de controle de edição. Usando a `SetRect` função membro, um aplicativo pode tornar o retângulo de formatação maior ou menor do que a janela de controle de edição.

Se o controle de edição não tiver nenhuma barra de rolagem, o texto será recortado, não encapsulado, se o retângulo de formatação for feito maior do que a janela. Se o controle de edição contiver uma borda, o retângulo de formatação será reduzido pelo tamanho da borda. Se você ajustar o retângulo retornado pela função `GetRect` de membro, deverá remover o tamanho da borda antes de passar o retângulo para. `SetRect`

Quando `SetRect` é chamado, o texto do controle de edição também é reformatado e exibido novamente.

Para obter mais informações, consulte [EM_SETRECT](/windows/win32/Controls/em-setrect) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#24](../../mfc/reference/codesnippet/cpp/cedit-class_24.cpp)]

##  <a name="setrectnp"></a>  CEdit::SetRectNP

Chame essa função para definir o retângulo de formatação de um controle de edição de várias linhas.

```
void SetRectNP(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para uma `RECT` estrutura ou `CRect` objeto que especifica as novas dimensões do retângulo.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição.

`SetRectNP`é idêntico à função `SetRect` de membro, exceto que a janela de controle de edição não é redesenhada.

Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo da área do cliente da janela de controle de edição. Ao chamar a `SetRectNP` função de membro, um aplicativo pode tornar o retângulo de formatação maior ou menor do que a janela de controle de edição.

Se o controle de edição não tiver nenhuma barra de rolagem, o texto será recortado, não encapsulado, se o retângulo de formatação for feito maior do que a janela.

Esse membro é processado somente por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_SETRECTNP](/windows/win32/Controls/em-setrectnp) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: SetRect](#setrect).

##  <a name="setsel"></a>  CEdit::SetSel

Chame essa função para selecionar um intervalo de caracteres em um controle de edição.

```
void SetSel(
    DWORD dwSelection,
    BOOL bNoScroll = FALSE);

void SetSel(
    int nStartChar,
    int nEndChar,
    BOOL bNoScroll = FALSE);
```

### <a name="parameters"></a>Parâmetros

*dwSelection*<br/>
Especifica a posição inicial na palavra de ordem inferior e a posição final na palavra de ordem superior. Se a palavra de ordem inferior for 0 e a palavra de ordem superior for-1, todo o texto no controle de edição será selecionado. Se a palavra de ordem inferior for-1, qualquer seleção atual será removida.

*bNoScroll*<br/>
Indica se o cursor deve ser rolado para a exibição. Se for FALSE, o cursor será rolado para a exibição. Se for TRUE, o cursor não será rolado para a exibição.

*nStartChar*<br/>
Especifica a posição inicial. Se *nStartChar* for 0 e *nEndChar* for-1, todo o texto no controle de edição será selecionado. Se *nStartChar* for-1, qualquer seleção atual será removida.

*nEndChar*<br/>
Especifica a posição final.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_SETSEL](/windows/win32/Controls/em-setsel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEdit:: GetSel](#getsel).

##  <a name="settabstops"></a>  CEdit::SetTabStops

Chame essa função para definir as paradas de tabulação em um controle de edição de várias linhas.

```
void SetTabStops();
BOOL SetTabStops(const int& cxEachStop);

BOOL SetTabStops(
    int nTabStops,
    LPINT rgTabStops);
```

### <a name="parameters"></a>Parâmetros

*cxEachStop*<br/>
Especifica que as paradas de tabulação devem ser definidas em todas as unidades de diálogo *cxEachStop* .

*nTabStops*<br/>
Especifica o número de paradas de tabulação contidas em *rgTabStops*. Este número deve ser maior que 1.

*rgTabStops*<br/>
Aponta para uma matriz de inteiros sem sinal especificando as paradas de tabulação em unidades de diálogo. Uma unidade de caixa de diálogo é uma distância horizontal ou vertical. Uma unidade de caixa de diálogo horizontal é igual a um quarto da unidade de largura base da caixa de diálogo atual e uma unidade de caixa de diálogo vertical é igual a um oitavo da unidade de altura base da caixa de diálogo atual. As unidades base da caixa de diálogo são computadas com base na altura e na largura da fonte atual do sistema. A `GetDialogBaseUnits` função do Windows retorna as unidades base da caixa de diálogo atual em pixels.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as guias foram definidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando o texto é copiado para um controle de edição de várias linhas, qualquer caractere de tabulação no texto fará com que o espaço seja gerado até a próxima parada de tabulação.

Para definir paradas de tabulação o tamanho padrão das unidades de diálogo 32, chame a versão sem parâmetros dessa função de membro. Para definir as paradas de tabulação com um tamanho diferente de 32, chame a versão com o parâmetro *cxEachStop* . Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com dois parâmetros.

Essa função de membro só é processada por controles de edição de várias linhas.

`SetTabStops`Não redesenha automaticamente a janela de edição. Se você alterar as paradas de tabulação para texto que já está no controle de edição, chame [CWnd:: InvalidateRect](cwnd-class.md#invalidaterect) para redesenhar a janela de edição.

Para obter mais informações, consulte [EM_SETTABSTOPS](/windows/win32/Controls/em-settabstops) e [GetDialogBaseUnits](/windows/win32/api/winuser/nf-winuser-getdialogbaseunits) no SDK do Windows.

### <a name="example"></a>Exemplo

  Consulte o exemplo de [CEditView::](ceditview-class.md#settabstops)SetTabStops.

##  <a name="showballoontip"></a>  CEdit::ShowBalloonTip

Exibe uma dica de balão associada ao controle de edição atual.

```
BOOL ShowBalloonTip(PEDITBALLOONTIP pEditBalloonTip);

BOOL ShowBalloonTip(
    LPCWSTR lpszTitle,
    LPCWSTR lpszText,
    INT ttiIcon = TTI_NONE);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pEditBalloonTip*|no Ponteiro para uma estrutura [EDITBALLOONTIP](/windows/win32/api/commctrl/ns-commctrl-editballoontip) que descreve a dica de balão.|
|*lpszTitle*|no Ponteiro para uma cadeia de caracteres Unicode que contém o título da dica de balão.|
|*lpszText*|no Ponteiro para uma cadeia de caracteres Unicode que contém o texto da dica de balão.|
|*ttiIcon*|no Um **int** que especifica o tipo de ícone a ser associado à dica de balão. O valor padrão é TTI_NONE. Para obter mais informações, consulte `ttiIcon` o membro da estrutura [EDITBALLOONTIP](/windows/win32/api/commctrl/ns-commctrl-editballoontip) .|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função envia a mensagem [EM_SHOWBALLOONTIP](/windows/win32/Controls/em-showballoontip) , que é descrita na SDK do Windows. Para obter mais informações, consulte a macro [Edit_ShowBalloonTip](/windows/win32/api/commctrl/nf-commctrl-edit_showballoontip) .

### <a name="example"></a>Exemplo

O exemplo de código a seguir define uma `m_cedit`variável,, que é usada para acessar o controle de edição atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CEdit_s1#1](../../mfc/reference/codesnippet/cpp/cedit-class_25.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir exibe uma dica de balão para um controle de edição. O método [CEdit:: ShowBalloonTip](#showballoontip) especifica um título e um texto de dica de balão.

[!code-cpp[NVC_MFC_CEdit_s1#3](../../mfc/reference/codesnippet/cpp/cedit-class_26.cpp)]

##  <a name="undo"></a>  CEdit::Undo

Chame essa função para desfazer a última operação de edição de controle.

```
BOOL Undo();
```

### <a name="return-value"></a>Valor de retorno

Para um controle de edição de linha única, o valor de retorno é sempre diferente de zero. Para um controle de edição de várias linhas, o valor de retorno será diferente de zero se a operação de desfazer for bem-sucedida ou 0 se a operação de desfazer falhar.

### <a name="remarks"></a>Comentários

Uma operação de desfazer também pode ser desfeita. Por exemplo, você pode restaurar texto excluído com a primeira chamada para `Undo`. Desde que não haja nenhuma operação de edição intermediária, você pode remover o texto novamente com uma segunda chamada para `Undo`.

Para obter mais informações, consulte [EM_UNDO](/windows/win32/Controls/em-undo) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#25](../../mfc/reference/codesnippet/cpp/cedit-class_27.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo de CALCDRIV do MFC](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de CMNCTRL2 do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](cwnd-class.md)<br/>
[Classe CButton](cbutton-class.md)<br/>
[Classe CComboBox](ccombobox-class.md)<br/>
[Classe CListBox](clistbox-class.md)<br/>
[Classe CScrollBar](cscrollbar-class.md)<br/>
[Classe CStatic](cstatic-class.md)<br/>
[Classe CDialog](cdialog-class.md)
