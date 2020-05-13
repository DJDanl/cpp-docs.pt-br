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
ms.openlocfilehash: 94769a6fb3c5fceefda96b54cebb35b0533a8afa
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753226"
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
|[CEdit::CEdit](#cedit)|Constrói um `CEdit` objeto de controle.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEdit::CanUndo](#canundo)|Determina se uma operação de controle de edição pode ser desfeita.|
|[CEdit::CharFromPos](#charfrompos)|Recupera os índices de linha e caracteres para o caractere mais próximo de uma posição especificada.|
|[CEdit::Claro](#clear)|Exclui (limpa) a seleção atual (se houver) no controle de edição.|
|[CEdit::Copiar](#copy)|Copia a seleção atual (se houver) no controle de edição para a Área de Transferência em formato CF_TEXT.|
|[CEdit::Criar](#create)|Cria o controle de edição do `CEdit` Windows e o anexa ao objeto.|
|[CEdit::Corte](#cut)|Exclui (corta) a seleção atual (se houver) no controle de edição e copia o texto excluído para a Área de Transferência em formato CF_TEXT.|
|[CEdit::EmptyUndoBuffer](#emptyundobuffer)|Reinicia (limpa) o sinalizador de desfazer de um controle de edição.|
|[CEdit::FmtLines](#fmtlines)|Define a inclusão de caracteres de quebra de linha suave sacaneados dentro ou fora de um controle de edição de várias linhas.|
|[Cedit::GetCueBanner](#getcuebanner)|Recupera o texto que é exibido como a deixa de texto, ou ponta, em um controle de edição quando o controle está vazio e não tem foco.|
|[Cedit::getFirstVisibleline](#getfirstvisibleline)|Determina a linha mais visível em um controle de edição.|
|[CEdit::GetHandle](#gethandle)|Recupera uma alça para a memória que está atualmente alocada para um controle de edição de várias linhas.|
|[Cedit::GetHighlight](#gethighlight)|Obtém os índices dos caracteres inicial e final em uma faixa de texto que é destacada no controle de edição atual.|
|[CEdit::GetLimitText](#getlimittext)|Obtém a quantidade `CEdit` máxima de texto que isso pode conter.|
|[Cedit::Getline](#getline)|Recupera uma linha de texto de um controle de edição.|
|[Cedit::GetLineCount](#getlinecount)|Recupera o número de linhas em um controle de edição de várias linhas.|
|[Cedit::GetMargins](#getmargins)|Obtém as margens `CEdit`esquerda e direita para isso.|
|[Cedit::getModify](#getmodify)|Determina se o conteúdo de um controle de edição foi modificado.|
|[Cedit::GetPasswordChar](#getpasswordchar)|Recupera o caractere de senha exibido em um controle de edição quando o usuário insere texto.|
|[CEdit::GetRect](#getrect)|Obtém o retângulo de formatação de um controle de edição.|
|[Cedit::GetSel](#getsel)|Obtém as primeiras e últimas posições de caractere da seleção atual em um controle de edição.|
|[CEdit::HideBalloonTip](#hideballoontip)|Oculta qualquer ponta de balão associada ao controle de edição atual.|
|[CEdit::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir em um controle de edição.|
|[Cedit::LineFromchar](#linefromchar)|Recupera o número de linha da linha que contém o índice de caracteres especificado.|
|[CEdit::Índice de linha](#lineindex)|Recupera o índice de caracteres de uma linha dentro de um controle de edição de várias linhas.|
|[CEdit:::Comprimento de linha](#linelength)|Recupera o comprimento de uma linha em um controle de edição.|
|[CEdit::LinhaDe linha](#linescroll)|Rola o texto de um controle de edição de várias linhas.|
|[CEdit::Paste](#paste)|Insere os dados da Área de Transferência no controle de edição na posição atual do cursor. Os dados só são inseridos se a Área de Transferência contiver dados em CF_TEXT formato.|
|[CEdit::PosFromChar](#posfromchar)|Recupera as coordenadas do canto superior esquerdo de um índice de caractereespecificado.|
|[CEdit::ReplaceSel](#replacesel)|Substitui a seleção atual em um controle de edição pelo texto especificado.|
|[CEdit::SetCueBanner](#setcuebanner)|Define o texto que é exibido como a deixa de texto, ou ponta, em um controle de edição quando o controle está vazio e não tem foco.|
|[CEdit::SetHandle](#sethandle)|Define a alça na memória local que será usada por um controle de edição de várias linhas.|
|[CEdit::SetHighlight](#sethighlight)|Destaca uma gama de texto que é exibido no controle de edição atual.|
|[CEdit::SetLimiteText](#setlimittext)|Define a quantidade máxima `CEdit` de texto que isso pode conter.|
|[CEdit::SetMargins](#setmargins)|Define as margens esquerda `CEdit`e direita para isso.|
|[CEdit::SetModify](#setmodify)|Define ou limpa o sinalizador de modificação para um controle de edição.|
|[CEdit::SetPasswordChar](#setpasswordchar)|Define ou remove um caractere de senha exibido em um controle de edição quando o usuário insere texto.|
|[CEdit::SetReadOnly](#setreadonly)|Define o estado somente leitura de um controle de edição.|
|[CEdit::SetRect](#setrect)|Define o retângulo de formatação de um controle de edição de várias linhas e atualiza o controle.|
|[CEdit::SetRectNP](#setrectnp)|Define o retângulo de formatação de um controle de edição de várias linhas sem redesenhar a janela de controle.|
|[CEdit::SetSel](#setsel)|Seleciona uma gama de caracteres em um controle de edição.|
|[cedit::set's'sStops](#settabstops)|Define as paradas de guia em um controle de edição de várias linhas.|
|[CEdit::ShowBalloonTip](#showballoontip)|Exibe uma ponta de balão associada ao controle de edição atual.|
|[CEdit::Undo](#undo)|Inverte a última operação de controle de edição.|

## <a name="remarks"></a>Comentários

Um controle de edição é uma janela de criança retangular na qual o usuário pode inserir texto.

Você pode criar um controle de edição a partir de um modelo de diálogo ou diretamente em seu código. Em ambos os casos, `CEdit` primeiro ligue `CEdit` para o construtor para construir o objeto, em seguida, chame a função [Criar](#create) membro para criar o controle de edição do Windows e anexá-lo ao `CEdit` objeto.

A construção pode ser um processo de `CEdit`uma etapa em uma classe derivada de . Escreva um construtor para a classe `Create` derivada e ligue de dentro do construtor.

`CEdit`herda funcionalidade significativa `CWnd`de . Para definir e recuperar `CEdit` texto de `CWnd` um objeto, use as funções de membro [SetWindowText](cwnd-class.md#setwindowtext) e [GetWindowText](cwnd-class.md#getwindowtext), que definem ou obtêm todo o conteúdo de um controle de edição, mesmo que seja um controle multilinha. As linhas de texto em um controle multilinha são separadas por seqüências de caracteres '\r\n'. Além disso, se um controle de edição for multilinha, obtenha `CEdit` e defina parte do texto do controle chamando as funções de membro [GetLine](#getline), [SetSel,](#setsel) [GetSel](#getsel)e [ReplaceSel](#replacesel).

Se você quiser lidar com mensagens de notificação do Windows enviadas por `CDialog`um controle de edição para seu pai (geralmente uma classe derivada), adicione uma função de membro do mapa de mensagem e do manipulador de mensagens à classe pai para cada mensagem.

Cada entrada de mapa de mensagem tem o seguinte formulário:

  **ON_**_NOTIFICAÇÃO_ _(id_**,** _memberFxn)_ **)** **(**

onde `id` especifica o ID da janela filho do `memberFxn` controle de edição que envia a notificação, e é o nome da função de membro pai que você escreveu para lidar com a notificação.

O protótipo de função dos pais é o seguinte:

**afx_msg** membro do vazioFxn **( );**

A seguir está uma lista de possíveis entradas de mapa de mensagens e uma descrição dos casos em que seriam enviadas ao pai:

- ON_EN_CHANGE O usuário tomou uma ação que pode ter alterado o texto em um controle de edição. Ao contrário da mensagem de notificação EN_UPDATE, esta mensagem de notificação é enviada após o Windows atualizar o display.

- ON_EN_ERRSPACE O controle de edição não pode alocar memória suficiente para atender a uma solicitação específica.

- ON_EN_HSCROLL O usuário clica na barra de rolagem horizontal de um controle de edição. A janela pai é notificada antes que a tela seja atualizada.

- ON_EN_KILLFOCUS O controle de edição perde o foco de entrada.

- ON_EN_MAXTEXT A inserção atual excedeu o número especificado de caracteres para o controle de edição e foi truncada. Também enviado quando um controle de edição não tem o estilo ES_AUTOHSCROLL e o número de caracteres a serem inseridos excederia a largura do controle de edição. Também enviado quando um controle de edição não tem o estilo ES_AUTOVSCROLL e o número total de linhas resultantes de uma inserção de texto excederia a altura do controle de edição.

- ON_EN_SETFOCUS Enviado quando um controle de edição recebe o foco de entrada.

- ON_EN_UPDATE O controle de edição está prestes a exibir texto alterado. Enviado após o controle formatar o texto, mas antes de tela o texto para que o tamanho da janela possa ser alterado, se necessário.

- ON_EN_VSCROLL O usuário clica na barra de rolagem vertical de um controle de edição. A janela pai é notificada antes que a tela seja atualizada.

Se você `CEdit` criar um objeto dentro `CEdit` de uma caixa de diálogo, o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CEdit` criar um objeto a partir de `CEdit` um recurso de diálogo usando o editor de diálogo, o objeto será automaticamente destruído quando o usuário fechar a caixa de diálogo.

Se você `CEdit` criar um objeto dentro de uma janela, você também pode precisar destruí-lo. Se você `CEdit` criar o objeto na pilha, ele será destruído automaticamente. Se você `CEdit` criar o objeto no heap usando a **nova** função, você deve chamar **excluir** no objeto para destruí-lo quando o usuário terminar o controle de edição do Windows. Se você alocar `CEdit` qualquer memória no `CEdit` objeto, anule o destruidor para descartar as alocações.

Para modificar certos estilos em um controle de edição (como ES_READONLY) você deve enviar mensagens específicas para o controle em vez de usar [ModifyStyle](cwnd-class.md#modifystyle). Consulte [Editar estilos de controle](/windows/win32/Controls/edit-control-styles) no SDK do Windows.

Para obter `CEdit`mais informações sobre , consulte [Controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](cobject-class.md)

[Ccmdtarget](ccmdtarget-class.md)

[CWnd](cwnd-class.md)

`CEdit`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="ceditcanundo"></a><a name="canundo"></a>CEdit::CanUndo

Ligue para esta função para determinar se a última operação de edição pode ser desfeita.

```
BOOL CanUndo() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a última operação de edição `Undo` puder ser desfeita por uma chamada para a função de membro; 0 se não puder ser desfeito.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_CANUNDO](/windows/win32/Controls/em-canundo) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::Desfazer](#undo).

## <a name="ceditcedit"></a><a name="cedit"></a>CEdit::CEdit

Constrói um objeto `CEdit`.

```
CEdit();
```

### <a name="remarks"></a>Comentários

Use [Criar](#create) para construir o controle de edição do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#1](../../mfc/reference/codesnippet/cpp/cedit-class_1.cpp)]

## <a name="ceditcharfrompos"></a><a name="charfrompos"></a>CEdit::CharFromPos

Chame esta função para recuperar os índices de linha e caractere baseados `CEdit` em zero do caractere mais próximo do ponto especificado neste controle

```
int CharFromPos(CPoint pt) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
As coordenadas de um ponto na `CEdit` área do cliente deste objeto.

### <a name="return-value"></a>Valor retornado

O índice de caracteres no WORD de baixa ordem e o índice de linha no WORD de alta ordem.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Esta função de membro está disponível a partir do Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_CHARFROMPOS](/windows/win32/Controls/em-charfrompos) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#3](../../mfc/reference/codesnippet/cpp/cedit-class_2.cpp)]

## <a name="ceditclear"></a><a name="clear"></a>CEdit::Claro

Chame esta função para excluir (limpar) a seleção atual (se houver) no controle de edição.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

A exclusão `Clear` realizada por pode ser desfeita chamando a função de membro [Desfazer.](#undo)

Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, ligue para a função ['Cortar](#cut) membro'.

Para obter mais informações, consulte [WM_CLEAR](/windows/win32/dataxchg/wm-clear) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#4](../../mfc/reference/codesnippet/cpp/cedit-class_3.cpp)]

## <a name="ceditcopy"></a><a name="copy"></a>CEdit::Copiar

Chame esta função para coyaaa a seleção atual (se houver) no controle de edição para a Área de Transferência em formato CF_TEXT.

```cpp
void Copy();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [WM_COPY](/windows/win32/dataxchg/wm-copy) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#5](../../mfc/reference/codesnippet/cpp/cedit-class_4.cpp)]

## <a name="ceditcreate"></a><a name="create"></a>CEdit::Criar

Cria o controle de edição do `CEdit` Windows e o anexa ao objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*Dwstyle*<br/>
Especifica o estilo do controle de edição. Aplique qualquer combinação de estilos de [edição](styles-used-by-mfc.md#edit-styles) ao controle.

*Rect*<br/>
Especifica o tamanho e a posição do controle de edição. Pode ser `CRect` um `RECT` objeto ou estrutura.

*Pparentwnd*<br/>
Especifica a janela pai do controle `CDialog`de edição (geralmente a ). Não deve ser NULO.

*nID*<br/>
Especifica o ID do controle de edição.

### <a name="return-value"></a>Valor retornado

Não zero se a inicialização for bem sucedida; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói `CEdit` um objeto em dois passos. Primeiro, ligue `CEdit` para o `Create`construtor e, em seguida, ligue, `CEdit` que cria o controle de edição do Windows e o anexa ao objeto.

Quando `Create` é executado, o Windows envia as mensagens [WM_NCCREATE,](/windows/win32/winmsg/wm-nccreate) [WM_NCCALCSIZE](/windows/win32/winmsg/wm-nccalcsize) [WM_CREATE](/windows/win32/winmsg/wm-create)e [WM_GETMINMAXINFO](/windows/win32/winmsg/wm-getminmaxinfo) para o controle de edição.

Essas mensagens são tratadas por padrão pelas funções de membro [OnNcCreate,](cwnd-class.md#onnccreate) [OnNcCalcSize,](cwnd-class.md#onnccalcsize) `CWnd` [OnCreate](cwnd-class.md#oncreate)e [OnGetMinMaxInfo](cwnd-class.md#ongetminmaxinfo) na classe base. Para estender o tratamento padrão da `CEdit`mensagem, obtenha uma classe de , adicione um mapa de mensagem à nova classe e anule as funções de membro do manipulador de mensagens acima. Substituição, `OnCreate`por exemplo, para realizar a inicialização necessária para a nova classe.

Aplique os [seguintes estilos de janela](styles-used-by-mfc.md#window-styles) a um controle de edição.

- WS_CHILD Sempre

- WS_VISIBLE Normalmente

- WS_DISABLED raramente

- WS_GROUP Para controles de grupo

- WS_TABSTOP Para incluir o controle de edição na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#2](../../mfc/reference/codesnippet/cpp/cedit-class_5.cpp)]

## <a name="ceditcut"></a><a name="cut"></a>CEdit::Corte

Chame esta função para excluir (cortar) a seleção atual (se houver) no controle de edição e copie o texto excluído para a Área de Transferência em CF_TEXT formato.

```cpp
void Cut();
```

### <a name="remarks"></a>Comentários

A exclusão `Cut` realizada por pode ser desfeita chamando a função de membro [Desfazer.](#undo)

Para excluir a seleção atual sem colocar o texto excluído na Área de Transferência, ligue para a função ['Limpar](#clear) membro'.

Para obter mais informações, consulte [WM_CUT](/windows/win32/dataxchg/wm-cut) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#6](../../mfc/reference/codesnippet/cpp/cedit-class_6.cpp)]

## <a name="ceditemptyundobuffer"></a><a name="emptyundobuffer"></a>CEdit::EmptyUndoBuffer

Chame esta função para redefinir (limpar) o sinalizador de desfazer de um controle de edição.

```cpp
void EmptyUndoBuffer();
```

### <a name="remarks"></a>Comentários

O controle de edição agora não será capaz de desfazer a última operação. O sinalizador desfazer é definido sempre que uma operação dentro do controle de edição pode ser desfeita.

O sinalizador desfazer é automaticamente apagado sempre que as funções de membro [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) ou [SetHandle](#sethandle) `CWnd` são chamadas.

Para obter mais informações, consulte [EM_EMPTYUNDOBUFFER](/windows/win32/Controls/em-emptyundobuffer) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#7](../../mfc/reference/codesnippet/cpp/cedit-class_7.cpp)]

## <a name="ceditfmtlines"></a><a name="fmtlines"></a>CEdit::FmtLines

Chame esta função para definir a inclusão de caracteres de quebra de linha suaves dentro ou fora de um controle de edição de várias linhas.

```
BOOL FmtLines(BOOL bAddEOL);
```

### <a name="parameters"></a>Parâmetros

*bAddEOL*<br/>
Especifica se os caracteres de quebra de linha suave devem ser inseridos. Um valor de TRUE insere os caracteres; um valor de FALSE remove-os.

### <a name="return-value"></a>Valor retornado

Não zero se ocorrer qualquer formatação; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma quebra de linha macia consiste em dois retornos de carruagem e uma alimentação de linha inserida no final de uma linha que está quebrada por causa do embrulho da palavra. Uma quebra de linha dura consiste em um retorno de carruagem e uma alimentação de linha. As linhas que terminam com uma `FmtLines`quebra de linha dura não são afetadas por .

O Windows só `CEdit` responderá se o objeto for um controle de edição de várias linhas.

`FmtLines`só afeta o buffer retornado pelo [GetHandle](#gethandle) e o texto devolvido por [WM_GETTEXT](/windows/win32/winmsg/wm-gettext). Não tem impacto na exibição do texto dentro do controle de edição.

Para obter mais informações, consulte [EM_FMTLINES](/windows/win32/Controls/em-fmtlines) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#8](../../mfc/reference/codesnippet/cpp/cedit-class_8.cpp)]

## <a name="ceditgetcuebanner"></a><a name="getcuebanner"></a>Cedit::GetCueBanner

Recupera o texto exibido como a deixa de texto, ou ponta, em um controle de edição quando o controle está vazio.

```
BOOL GetCueBanner(
    LPWSTR lpszText,
    int cchText) const;

CString GetCueBanner() const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[fora] Um ponteiro para uma seqüência que contém o texto da deixa.

*cchText*<br/>
[em] O número de caracteres que podem ser recebidos. Este número inclui o caractere NULL terminando.

### <a name="return-value"></a>Valor retornado

Para a primeira sobrecarga, TRUE se o método for bem sucedido; caso contrário, FALSO.

Para a segunda sobrecarga, um [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de sinalização se o método for bem sucedido; caso contrário, a corda vazia ("").

### <a name="remarks"></a>Comentários

Este método envia a mensagem [EM_GETCUEBANNER,](/windows/win32/Controls/em-getcuebanner) que é descrita no SDK do Windows. Para obter mais informações, consulte a [macro Edit_GetCueBannerText.](/windows/win32/api/commctrl/nf-commctrl-edit_getcuebannertext)

## <a name="ceditgetfirstvisibleline"></a><a name="getfirstvisibleline"></a>Cedit::getFirstVisibleline

Chame esta função para determinar a linha mais visível em um controle de edição.

```
int GetFirstVisibleLine() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero da linha mais visível. Para controles de edição de linha única, o valor de retorno é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETFIRSTVISIBLELINE](/windows/win32/Controls/em-getfirstvisibleline) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#9](../../mfc/reference/codesnippet/cpp/cedit-class_9.cpp)]

## <a name="ceditgethandle"></a><a name="gethandle"></a>CEdit::GetHandle

Chame esta função para recuperar uma alça na memória atualmente alocada para um controle de edição de várias linhas.

```
HLOCAL GetHandle() const;
```

### <a name="return-value"></a>Valor retornado

Um cabo de memória local que identifica o buffer que segura o conteúdo do controle de edição. Se ocorrer um erro, como enviar a mensagem para um controle de edição de linha única, o valor de retorno será 0.

### <a name="remarks"></a>Comentários

O cabo é um cabo de memória local e pode ser usado por qualquer uma das funções de memória **local** do Windows que tomam uma alça de memória local como parâmetro.

`GetHandle`é processado apenas por controles de edição de várias linhas.

Peça `GetHandle` um controle de edição de várias linhas em uma caixa de diálogo somente se a caixa de diálogo foi criada com o conjunto DS_LOCALEDIT de de sinalização de estilo. Se o estilo DS_LOCALEDIT não estiver definido, você ainda receberá um valor de retorno não zero, mas não poderá usar o valor retornado.

> [!NOTE]
> `GetHandle`não funcionará com o Windows 95/98. Se você `GetHandle` ligar para o Windows 95/98, ele retornará NULL. `GetHandle`funcionará conforme documentado no Windows NT, versões 3.51 e posteriores.

Para obter mais informações, consulte [EM_GETHANDLE](/windows/win32/Controls/em-gethandle) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#10](../../mfc/reference/codesnippet/cpp/cedit-class_10.cpp)]

## <a name="ceditgethighlight"></a><a name="gethighlight"></a>Cedit::GetHighlight

Obtém os índices do primeiro e último caracteres em uma faixa de texto que é destacada no controle de edição atual.

```
BOOL GetHighlight(
    int* pichStart,
    int* pichEnd) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pichStart*|[fora] Índice baseado em zero do primeiro caractere na faixa de texto que é destacada.|
|*pichEnd*|[fora] Índice baseado em zero do último caractere na faixa de texto que é destacada.|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método envia a mensagem [EM_GETHILITE,](/windows/win32/Controls/em-gethilite) que é descrita no SDK do Windows. Ambos `SetHighlight` `GetHighlight` e estão atualmente habilitados apenas para compilações UNICODE.

## <a name="ceditgetlimittext"></a><a name="getlimittext"></a>CEdit::GetLimitText

Chame esta função de membro para `CEdit` obter o limite de texto para este objeto.

```
UINT GetLimitText() const;
```

### <a name="return-value"></a>Valor retornado

O limite de texto atual, em `CEdit` TCHARs, para este objeto.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em TCHARs, que o controle de edição pode aceitar.

> [!NOTE]
> Esta função de membro está disponível a partir do Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_GETLIMITTEXT](/windows/win32/Controls/em-getlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#11](../../mfc/reference/codesnippet/cpp/cedit-class_11.cpp)]

## <a name="ceditgetline"></a><a name="getline"></a>Cedit::Getline

Chame esta função para recuperar uma linha de texto de um controle de edição e colocá-la em *lpszBuffer*.

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
Especifica o número da linha para recuperar de um controle de edição de várias linhas. Os números de linha são baseados em zero; um valor de 0 especifica a primeira linha. Este parâmetro é ignorado por um controle de edição de linha única.

*Lpszbuffer*<br/>
Aponta para o buffer que recebe uma cópia da linha. A primeira palavra do buffer deve especificar o número máximo de TCHARs que podem ser copiados para o buffer.

*Nmaxlength*<br/>
Especifica o número máximo de caracteres TCHAR que podem ser copiados para o buffer. `GetLine`coloca esse valor na primeira palavra de *lpszBuffer* antes de fazer a chamada para o Windows.

### <a name="return-value"></a>Valor retornado

O número de caracteres realmente copiados. O valor de retorno é 0 se o número de linha especificado pelo *nIndex* for maior do que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

A linha copiada não contém um caractere de rescisão nula.

Para obter mais informações, consulte [EM_GETLINE](/windows/win32/Controls/em-getline) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetLineCount](#getlinecount).

## <a name="ceditgetlinecount"></a><a name="getlinecount"></a>Cedit::GetLineCount

Chame esta função para recuperar o número de linhas em um controle de edição de várias linhas.

```
int GetLineCount() const;
```

### <a name="return-value"></a>Valor retornado

Um inteiro contendo o número de linhas no controle de edição de várias linhas. Se nenhum texto tiver sido inserido no controle de edição, o valor de retorno será 1.

### <a name="remarks"></a>Comentários

`GetLineCount`é processado apenas por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_GETLINECOUNT](/windows/win32/Controls/em-getlinecount) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#12](../../mfc/reference/codesnippet/cpp/cedit-class_12.cpp)]

## <a name="ceditgetmargins"></a><a name="getmargins"></a>Cedit::GetMargins

Ligue para esta função de membro para recuperar as margens esquerda e direita deste controle de edição.

```
DWORD GetMargins() const;
```

### <a name="return-value"></a>Valor retornado

A largura da margem esquerda no WORD de baixa ordem e a largura da margem direita no WORD de alta ordem.

### <a name="remarks"></a>Comentários

As margens são medidas em pixels.

> [!NOTE]
> Esta função de membro está disponível a partir do Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_GETMARGINS](/windows/win32/Controls/em-getmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

## <a name="ceditgetmodify"></a><a name="getmodify"></a>Cedit::getModify

Chame esta função para determinar se o conteúdo de um controle de edição foi modificado.

```
BOOL GetModify() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conteúdo de controle de edição tiver sido modificado; 0 se eles permaneceram inalterados.

### <a name="remarks"></a>Comentários

O Windows mantém uma bandeira interna indicando se o conteúdo do controle de edição foi alterado. Este sinalizador é liberado quando o controle de edição é criado pela primeira vez e também pode ser apagado chamando a função [setModify](#setmodify) membro.

Para obter mais informações, consulte [EM_GETMODIFY](/windows/win32/Controls/em-getmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#13](../../mfc/reference/codesnippet/cpp/cedit-class_13.cpp)]

## <a name="ceditgetpasswordchar"></a><a name="getpasswordchar"></a>Cedit::GetPasswordChar

Chame esta função para recuperar o caractere de senha exibido em um controle de edição quando o usuário insere texto.

```
TCHAR GetPasswordChar() const;
```

### <a name="return-value"></a>Valor retornado

Especifica o caractere a ser exibido em vez do caractere digitado pelo usuário. O valor de devolução é NULL se não existir nenhum caractere de senha.

### <a name="remarks"></a>Comentários

Se você criar o controle de edição com o estilo ES_PASSWORD, o DLL que suporta o controle determinará o caractere de senha padrão. O manifesto ou o método [InitCommonControlsEx](/windows/win32/api/commctrl/nf-commctrl-initcommoncontrolsex) determina qual DLL suporta o controle de edição. Se o user32.dll suportar o controle de edição, o caractere de senha padrão será ASTERISK ('*', U+002A). Se comctl32.dll versão 6 suporta o controle de edição, o caractere padrão é BLACK CIRCLE ('●', U+25CF). Para obter mais informações sobre quais DLL e versão suportam os controles comuns, consulte [As versões Shell e Common Controls](/previous-versions/windows/desktop/legacy/bb776779\(v=vs.85\)).

Este método envia a [mensagem EM_GETPASSWORDCHAR,](/windows/win32/Controls/em-getpasswordchar) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#14](../../mfc/reference/codesnippet/cpp/cedit-class_14.cpp)]

## <a name="ceditgetrect"></a><a name="getrect"></a>CEdit::GetRect

Chame esta função para obter o retângulo de formatação de um controle de edição.

```cpp
void GetRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` a estrutura que recebe o retângulo de formatação.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo limitante do texto, que é independente do tamanho da janela de controle de edição.

O retângulo de formatação de um controle de edição de várias linhas pode ser modificado pelas funções de membro [SetRect](#setrect) e [SetRectNP.](#setrectnp)

Para obter mais informações, consulte [EM_GETRECT](/windows/win32/Controls/em-getrect) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LimitText](#limittext).

## <a name="ceditgetsel"></a><a name="getsel"></a>Cedit::GetSel

Chame esta função para obter as posições de caracteres de inicialização e final da seleção atual (se houver) em um controle de edição, usando o valor de retorno ou os parâmetros.

```
DWORD GetSel() const;

void GetSel(
    int& nStartChar,
    int& nEndChar) const;
```

### <a name="parameters"></a>Parâmetros

*Nstartchar*<br/>
Referência a um inteiro que receberá a posição do primeiro caractere na seleção atual.

*nEndChar*<br/>
Referência a um inteiro que receberá a posição do primeiro caractere não selecionado após o final da seleção atual.

### <a name="return-value"></a>Valor retornado

A versão que retorna um DWORD retorna um valor que contém a posição inicial na palavra de baixa ordem e a posição do primeiro caractere não selecionado após o fim da seleção na palavra de alta ordem.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETSEL](/windows/win32/Controls/em-getsel) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#15](../../mfc/reference/codesnippet/cpp/cedit-class_15.cpp)]

## <a name="cedithideballoontip"></a><a name="hideballoontip"></a>CEdit::HideBalloonTip

Oculta qualquer ponta de balão associada ao controle de edição atual.

```
BOOL HideBalloonTip();
```

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esta função envia a mensagem [EM_HIDEBALLOONTIP,](/windows/win32/Controls/em-hideballoontip) que é descrita no SDK do Windows.

## <a name="ceditlimittext"></a><a name="limittext"></a>CEdit::LimitText

Chame esta função para limitar o comprimento do texto que o usuário pode inserir em um controle de edição.

```cpp
void LimitText(int nChars = 0);
```

### <a name="parameters"></a>Parâmetros

*Nchars*<br/>
Especifica o comprimento (em TCHARs) do texto que o usuário pode inserir. Se este parâmetro for 0, o comprimento do texto será definido como UINT_MAX bytes. Esse é o comportamento padrão.

### <a name="remarks"></a>Comentários

Alterar o limite de texto restringe apenas o texto que o usuário pode inserir. Não tem efeito sobre nenhum texto já no controle de edição, nem afeta o comprimento do texto copiado para o controle de edição pela função [setWindowText](cwnd-class.md#setwindowtext) em `CWnd`. Se um aplicativo `SetWindowText` usar a função para colocar mais texto em `LimitText`um controle de edição do que é especificado na chamada para, o usuário pode excluir qualquer um dos textos dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substituisse o texto existente por um novo texto, a menos que a exclusão da seleção atual faça com que o texto fique abaixo do limite do texto.

> [!NOTE]
> No Win32 (Windows NT e Windows 95/98), [SetLimitText](#setlimittext) substitui essa função.

Para obter mais informações, consulte [EM_LIMITTEXT](/windows/win32/Controls/em-limittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#17](../../mfc/reference/codesnippet/cpp/cedit-class_16.cpp)]

## <a name="ceditlinefromchar"></a><a name="linefromchar"></a>Cedit::LineFromchar

Chame esta função para recuperar o número de linha da linha que contém o índice de caractere especificado.

```
int LineFromChar(int nIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o valor de índice baseado em zero para o caractere desejado no texto do controle de edição, ou contém -1. Se *nIndex* for -1, ele especifica a linha atual, ou seja, a linha que contém o caret.

### <a name="return-value"></a>Valor retornado

O número de linha baseado em zero da linha que contém o índice de caracteres especificado pelo *nIndex*. Se *nIndex* for -1, o número da linha que contém o primeiro caractere da seleção será devolvido. Se não houver seleção, o número da linha atual é devolvido.

### <a name="remarks"></a>Comentários

Um índice de caracteres é o número de caracteres desde o início do controle de edição.

Esta função de membro é usada apenas por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEFROMCHAR](/windows/win32/Controls/em-linefromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#18](../../mfc/reference/codesnippet/cpp/cedit-class_17.cpp)]

## <a name="ceditlineindex"></a><a name="lineindex"></a>CEdit::Índice de linha

Chame esta função para recuperar o índice de caracteres de uma linha dentro de um controle de edição de várias linhas.

```
int LineIndex(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLine*<br/>
Contém o valor do índice da linha desejada no texto do controle de edição, ou contém -1. Se *nLine* for -1, ele especifica a linha atual, ou seja, a linha que contém o caret.

### <a name="return-value"></a>Valor retornado

O índice de caracteres da linha especificada em *nLine* ou -1 se o número de linha especificado for maior do que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

O índice de caracteres é o número de caracteres desde o início do controle de edição até a linha especificada.

Esta função de membro só é processada por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEINDEX](/windows/win32/controls/em-lineindex) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#19](../../mfc/reference/codesnippet/cpp/cedit-class_18.cpp)]

## <a name="ceditlinelength"></a><a name="linelength"></a>CEdit:::Comprimento de linha

Recupera o comprimento de uma linha em um controle de edição.

```
int LineLength(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLine*<br/>
O índice baseado em zero de um caractere na linha cujo comprimento deve ser recuperado. O valor padrão é -1.

### <a name="return-value"></a>Valor retornado

Para controles de edição de linha única, o valor de retorno é o comprimento, em TCHARs, do texto no controle de edição.

Para controles de edição multilinha, o valor de retorno é o comprimento, em TCHARs, da linha especificada pelo parâmetro *nLine.* Para o texto ANSI, o comprimento é o número de bytes na linha; para texto Unicode, o comprimento é o número de caracteres na linha. O comprimento não inclui o caractere de retorno de transporte no final da linha.

Se o parâmetro *nLine* for mais do que o número de caracteres no controle, o valor de retorno será zero.

Se o parâmetro *nLine* for -1, o valor de retorno será o número de caracteres não selecionados nas linhas que contêm caracteres selecionados. Por exemplo, se a seleção se estender do quarto caractere de uma linha até o oitavo caractere a partir do final da próxima linha, o valor de retorno é de 10. Ou seja, três personagens na primeira linha e sete na próxima.

Para obter mais informações sobre o tipo TCHAR, consulte a linha TCHAR na tabela em [Tipos de dados do Windows](/windows/win32/WinProg/windows-data-types).

### <a name="remarks"></a>Comentários

Este método é suportado pela mensagem [EM_LINELENGTH,](/windows/win32/Controls/em-linelength) que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineIndex](#lineindex).

## <a name="ceditlinescroll"></a><a name="linescroll"></a>CEdit::LinhaDe linha

Chame esta função para rolar o texto de um controle de edição de várias linhas.

```cpp
void LineScroll(
    int nLines,
    int nChars = 0);
```

### <a name="parameters"></a>Parâmetros

*nLinhas*<br/>
Especifica o número de linhas para rolar verticalmente.

*Nchars*<br/>
Especifica o número de posições de caracteres para rolar horizontalmente. Esse valor é ignorado se o controle de edição tiver o estilo ES_RIGHT ou ES_CENTER.

### <a name="remarks"></a>Comentários

Esta função de membro é processada apenas por controles de edição de várias linhas.

O controle de edição não passa verticalmente pela última linha de texto no controle de edição. Se a linha atual mais o número de linhas especificadas por *nLines* exceder o número total de linhas no controle de edição, o valor será ajustado para que a última linha do controle de edição seja rolada para o topo da janela de controle de edição.

`LineScroll`pode ser usado para rolar horizontalmente além do último caractere de qualquer linha.

Para obter mais informações, consulte [EM_LINESCROLL](/windows/win32/Controls/em-linescroll) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetFirstVisibleLine](#getfirstvisibleline).

## <a name="ceditpaste"></a><a name="paste"></a>CEdit::Paste

Chame esta função para inserir os dados `CEdit` da Área de Transferência no ponto de inserção.

```cpp
void Paste();
```

### <a name="remarks"></a>Comentários

Os dados só são inseridos se a Área de Transferência contiver dados em CF_TEXT formato.

Para obter mais informações, consulte [WM_PASTE](/windows/win32/dataxchg/wm-paste) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#20](../../mfc/reference/codesnippet/cpp/cedit-class_19.cpp)]

## <a name="ceditposfromchar"></a><a name="posfromchar"></a>CEdit::PosFromChar

Chame esta função para obter a posição (canto superior `CEdit` esquerdo) de um determinado caractere dentro deste objeto.

```
CPoint PosFromChar(UINT nChar) const;
```

### <a name="parameters"></a>Parâmetros

*Nchar*<br/>
O índice baseado em zero do caractere especificado.

### <a name="return-value"></a>Valor retornado

As coordenadas do canto superior esquerdo do caractere especificado por *nChar*.

### <a name="remarks"></a>Comentários

O caractere é especificado dando seu valor de índice baseado em zero. Se *nChar* for maior que o índice `CEdit` do último caractere neste objeto, o valor de retorno especificará as coordenadas da posição do caractere logo após o último caractere neste `CEdit` objeto.

> [!NOTE]
> Esta função de membro está disponível a partir do Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_POSFROMCHAR](/windows/win32/Controls/em-posfromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineFromChar](#linefromchar).

## <a name="ceditreplacesel"></a><a name="replacesel"></a>CEdit::ReplaceSel

Chame esta função para substituir a seleção atual em um controle de edição com o texto especificado pelo *lpszNewText*.

```cpp
void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
```

### <a name="parameters"></a>Parâmetros

*Lpsznewtext*<br/>
Aponta para uma seqüência de terminação nula contendo o texto de substituição.

*bCanUndo*<br/>
Para especificar que esta função pode ser desfeita, defina o valor deste parâmetro como TRUE . O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

Substitui apenas uma parte do texto em um controle de edição. Se você quiser substituir todo o texto, use a função de membro [CWnd::SetWindowText.](cwnd-class.md#setwindowtext)

Se não houver seleção atual, o texto de substituição será inserido no local atual do cursor.

Para obter mais informações, consulte [EM_REPLACESEL](/windows/win32/Controls/em-replacesel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineIndex](#lineindex).

## <a name="ceditsetcuebanner"></a><a name="setcuebanner"></a>CEdit::SetCueBanner

Define o texto exibido como a deixa de texto, ou ponta, em um controle de edição quando o controle estiver vazio.

```
BOOL SetCueBanner(LPCWSTR lpszText);

BOOL SetCueBanner(
    LPCWSTR lpszText,
    BOOL fDrawWhenFocused = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[em] Ponteiro para uma seqüência que contém a deixa a ser exibida no controle de edição.

*fDrawWhenFocado*<br/>
[em] Se FALSE, o banner de sinalização não é desenhado quando o usuário clica no controle de edição e dá o foco ao controle.

Se TRUE, o banner de sinalização é desenhado mesmo quando o controle tem foco. O banner de sinalização desaparece quando o usuário começa a digitar o controle.

O valor padrão é FALSE.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método envia a [mensagem EM_SETCUEBANNER,](/windows/win32/Controls/em-setcuebanner) que é descrita no SDK do Windows. Para obter mais informações, consulte a [macro Edit_SetCueBannerTextFocused.](/windows/win32/api/commctrl/nf-commctrl-edit_setcuebannertextfocused)

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra o método [CEdit::SetCueBanner.](#setcuebanner)

[!code-cpp[NVC_MFC_CEdit_s1#2](../../mfc/reference/codesnippet/cpp/cedit-class_20.cpp)]

## <a name="ceditsethandle"></a><a name="sethandle"></a>CEdit::SetHandle

Chame esta função para definir a alça na memória local que será usada por um controle de edição de várias linhas.

```cpp
void SetHandle(HLOCAL hBuffer);
```

### <a name="parameters"></a>Parâmetros

*hBuffer*<br/>
Contém uma alça para a memória local. Esta alça deve ter sido criada por uma chamada anterior para a função [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc) Windows usando o sinalizador de LMEM_MOVEABLE. Supõe-se que a memória contenha uma seqüência de seqüência sumida. Se este não for o caso, o primeiro byte da memória alocada deve ser definido como 0.

### <a name="remarks"></a>Comentários

O controle de edição usará este buffer para armazenar o texto exibido no momento, em vez de alocar seu próprio buffer.

Esta função de membro é processada apenas por controles de edição de várias linhas.

Antes que um aplicativo defina uma nova alça de memória, ele deve usar a função `LocalFree` [gethandle](#gethandle) membro para obter a alça para o buffer de memória atual e liberar essa memória usando a função Windows.

`SetHandle`limpa o buffer de sumido (a função membro [CanUndo](#canundo) retorna 0) e o sinalizador de modificação interna (a função [GetModify](#getmodify) membro retorna 0). A janela de controle de edição é redesenhada.

Você pode usar esta função de membro em um controle de edição de várias linhas em uma caixa de diálogo somente se você tiver criado a caixa de diálogo com o conjunto de DS_LOCALEDIT de sinalizador de estilo.

> [!NOTE]
> `GetHandle`não funcionará com o Windows 95/98. Se você `GetHandle` ligar para o Windows 95/98, ele retornará NULL. `GetHandle`funcionará conforme documentado no Windows NT, versões 3.51 e posteriores.

Para obter mais informações, consulte [EM_SETHANDLE](/windows/win32/Controls/em-sethandle), [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc)e [LocalFree](/windows/win32/api/winbase/nf-winbase-localfree) no Windows SDK.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#22](../../mfc/reference/codesnippet/cpp/cedit-class_21.cpp)]

## <a name="ceditsethighlight"></a><a name="sethighlight"></a>CEdit::SetHighlight

Destaca uma gama de texto que é exibido no controle de edição atual.

```cpp
void SetHighlight(
    int ichStart,
    int ichEnd);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ichStart*|[em] Índice baseado em zero do primeiro caractere na faixa de texto a ser destacado.|
|*ichEnd*|[em] Índice baseado em zero do último caractere na faixa de texto a ser destacada.|

### <a name="remarks"></a>Comentários

Este método envia a mensagem [EM_SETHILITE,](/windows/win32/Controls/em-sethilite) que é descrita no SDK do Windows.  Este método envia a mensagem [EM_SETHILITE,](/windows/win32/Controls/em-sethilite) que é descrita no SDK do Windows. Ambos `SetHighlight` `GetHighlight` e estão habilitados apenas para compilações UNICODE.

## <a name="ceditsetlimittext"></a><a name="setlimittext"></a>CEdit::SetLimiteText

Chame esta função de membro para `CEdit` definir o limite de texto para este objeto.

```cpp
void SetLimitText(UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmax*<br/>
O novo limite de texto, em caracteres.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em caracteres, que o controle de edição pode aceitar.

Alterar o limite de texto restringe apenas o texto que o usuário pode inserir. Não tem efeito sobre nenhum texto já no controle de edição, nem afeta o comprimento do texto copiado para o controle de edição pela função [setWindowText](cwnd-class.md#setwindowtext) em `CWnd`. Se um aplicativo `SetWindowText` usar a função para colocar mais texto em `LimitText`um controle de edição do que é especificado na chamada para, o usuário pode excluir qualquer um dos textos dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substituisse o texto existente por um novo texto, a menos que a exclusão da seleção atual faça com que o texto fique abaixo do limite do texto.

Esta função substitui [LimitText](#limittext) no Win32.

Para obter mais informações, consulte [EM_SETLIMITTEXT](/windows/win32/Controls/em-setlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

## <a name="ceditsetmargins"></a><a name="setmargins"></a>CEdit::SetMargins

Chame este método para definir as margens esquerda e direita deste controle de edição.

```cpp
void SetMargins(
    UINT nLeft,
    UINT nRight);
```

### <a name="parameters"></a>Parâmetros

*nEsquerda*<br/>
A largura da nova margem esquerda, em pixels.

*nDireito*<br/>
A largura da nova margem direita, em pixels.

### <a name="remarks"></a>Comentários

> [!NOTE]
> Esta função de membro está disponível a partir do Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_SETMARGINS](/windows/win32/Controls/em-setmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

## <a name="ceditsetmodify"></a><a name="setmodify"></a>CEdit::SetModify

Chame esta função para definir ou limpar o sinalizador modificado para um controle de edição.

```cpp
void SetModify(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModificado*<br/>
Um valor de TRUE indica que o texto foi modificado, e um valor de FALSE indica que ele não é modificado. Por padrão, o sinalizador modificado é definido.

### <a name="remarks"></a>Comentários

O sinalizador modificado indica se o texto dentro do controle de edição foi modificado ou não. Ele é configurado automaticamente sempre que o usuário altera o texto. Seu valor pode ser recuperado com a função [GetModify](#getmodify) member.

Para obter mais informações, consulte [EM_SETMODIFY](/windows/win32/Controls/em-setmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetModify](#getmodify).

## <a name="ceditsetpasswordchar"></a><a name="setpasswordchar"></a>CEdit::SetPasswordChar

Chame esta função para definir ou remover um caractere de senha exibido em um controle de edição quando o usuário digita texto.

```cpp
void SetPasswordChar(TCHAR ch);
```

### <a name="parameters"></a>Parâmetros

*Ch*<br/>
Especifica o caractere a ser exibido no lugar do caractere digitado pelo usuário. Se *ch* for 0, os caracteres reais digitados pelo usuário serão exibidos.

### <a name="remarks"></a>Comentários

Quando um caractere de senha é definido, esse caractere é exibido para cada caractere que o usuário digita.

Esta função de membro não tem efeito em um controle de edição de várias linhas.

Quando `SetPasswordChar` a função de `CEdit` membro é chamada, redesenhará todos os caracteres visíveis usando o caractere especificado por *ch*.

Se o controle de edição for criado com o estilo [ES_PASSWORD,](styles-used-by-mfc.md#edit-styles) o <strong>\*</strong>caractere de senha padrão será definido como um asterisco (). Este estilo é `SetPasswordChar` removido se for chamado com *ch* definido como 0.

Para obter mais informações, consulte [EM_SETPASSWORDCHAR](/windows/win32/Controls/em-setpasswordchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#16](../../mfc/reference/codesnippet/cpp/cedit-class_22.cpp)]

## <a name="ceditsetreadonly"></a><a name="setreadonly"></a>CEdit::SetReadOnly

Chama esta função para definir o estado somente leitura de um controle de edição.

```
BOOL SetReadOnly(BOOL bReadOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bReadOnly*<br/>
Especifica se deve definir ou remover o estado somente leitura do controle de edição. Um valor de TRUE define o estado para somente leitura; um valor de FALSO define o estado para ler/gravar.

### <a name="return-value"></a>Valor retornado

Não zero se a operação for bem sucedida, ou 0 se ocorrer um erro.

### <a name="remarks"></a>Comentários

A configuração atual pode ser encontrada testando o sinalizador [ES_READONLY](styles-used-by-mfc.md#edit-styles) no valor de retorno de [CWnd::GetStyle](cwnd-class.md#getstyle).

Para obter mais informações, consulte [EM_SETREADONLY](/windows/win32/Controls/em-setreadonly) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#23](../../mfc/reference/codesnippet/cpp/cedit-class_23.cpp)]

## <a name="ceditsetrect"></a><a name="setrect"></a>CEdit::SetRect

Chame esta função para definir as dimensões de um retângulo usando as coordenadas especificadas.

```cpp
void SetRect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` a `CRect` estrutura ou objeto que especifica as novas dimensões do retângulo de formatação.

### <a name="remarks"></a>Comentários

Este membro é processado apenas por controles de edição de várias linhas.

Use `SetRect` para definir o retângulo de formatação de um controle de edição de várias linhas. O retângulo de formatação é o retângulo limitante do texto, que é independente do tamanho da janela de controle de edição. Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo que a área cliente da janela editar-controle. Usando a `SetRect` função membro, um aplicativo pode tornar o retângulo de formatação maior ou menor do que a janela de controle de edição.

Se o controle de edição não tiver barra de rolagem, o texto será cortado, não embrulhado, se o retângulo de formatação for maior que a janela. Se o controle de edição contiver uma borda, o retângulo de formatação será reduzido pelo tamanho da borda. Se você ajustar o retângulo `GetRect` retornado pela função do membro, você deve remover `SetRect`o tamanho da borda antes de passar o retângulo para .

Quando `SetRect` é chamado, o texto do controle de edição também é reformatado e reexibido.

Para obter mais informações, consulte [EM_SETRECT](/windows/win32/Controls/em-setrect) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#24](../../mfc/reference/codesnippet/cpp/cedit-class_24.cpp)]

## <a name="ceditsetrectnp"></a><a name="setrectnp"></a>CEdit::SetRectNP

Chame esta função para definir o retângulo de formatação de um controle de edição de várias linhas.

```cpp
void SetRectNP(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*Lprect*<br/>
Aponta para `RECT` uma `CRect` estrutura ou objeto que especifica as novas dimensões do retângulo.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo limitante do texto, que é independente do tamanho da janela de controle de edição.

`SetRectNP`é idêntica `SetRect` à função de membro, exceto que a janela de controle de edição não é redesenhada.

Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo que a área cliente da janela editar-controle. Ao chamar `SetRectNP` a função de membro, um aplicativo pode tornar o retângulo de formatação maior ou menor do que a janela de controle de edição.

Se o controle de edição não tiver barra de rolagem, o texto será cortado, não embrulhado, se o retângulo de formatação for maior que a janela.

Este membro é processado apenas por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_SETRECTNP](/windows/win32/Controls/em-setrectnp) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::SetRect](#setrect).

## <a name="ceditsetsel"></a><a name="setsel"></a>CEdit::SetSel

Chame esta função para selecionar uma gama de caracteres em um controle de edição.

```cpp
void SetSel(
    DWORD dwSelection,
    BOOL bNoScroll = FALSE);

void SetSel(
    int nStartChar,
    int nEndChar,
    BOOL bNoScroll = FALSE);
```

### <a name="parameters"></a>Parâmetros

*dwSeleção*<br/>
Especifica a posição inicial na palavra de baixa ordem e a posição final na palavra de alta ordem. Se a palavra de baixa ordem for 0 e a palavra de ordem alta for -1, todo o texto no controle de edição será selecionado. Se a palavra de baixa ordem for -1, qualquer seleção atual será removida.

*bNoScroll*<br/>
Indica se o careta deve ser colocado à vista. Se FALSO, a careta é rolada para a exibição. Se TRUE, o careta não é rolado para a exibição.

*Nstartchar*<br/>
Especifica a posição inicial. Se *nStartChar* for 0 e *nEndChar* for -1, todo o texto no controle de edição será selecionado. Se *nStartChar* for -1, qualquer seleção atual será removida.

*nEndChar*<br/>
Especifica a posição final.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_SETSEL](/windows/win32/Controls/em-setsel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetSel](#getsel).

## <a name="ceditsettabstops"></a><a name="settabstops"></a>cedit::set's'sStops

Chame esta função para definir as paradas de guia em um controle de edição de várias linhas.

```cpp
void SetTabStops();
BOOL SetTabStops(const int& cxEachStop);

BOOL SetTabStops(
    int nTabStops,
    LPINT rgTabStops);
```

### <a name="parameters"></a>Parâmetros

*cxEachStop*<br/>
Especifica que as paradas de guia devem ser definidas em todas as unidades de diálogo *cxEachStop.*

*Ntabstops*<br/>
Especifica o número de guias contidas em *rgTabStops*. Este número deve ser maior que 1.

*Rgtabstops*<br/>
Aponta para uma matriz de inteiros não assinados especificando as guias paradas em unidades de diálogo. Uma unidade de diálogo é uma distância horizontal ou vertical. Uma unidade de diálogo horizontal é igual a um quarto da unidade de largura da base de diálogo atual, e 1 unidade de diálogo vertical é igual a um oitavo da unidade de altura da base de diálogo atual. As unidades base de diálogo são calculadas com base na altura e largura da fonte atual do sistema. A `GetDialogBaseUnits` função Windows retorna as unidades base de diálogo atuais em pixels.

### <a name="return-value"></a>Valor retornado

Não zero se as guias foram definidas; caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando o texto é copiado para um controle de edição de várias linhas, qualquer caractere de guia no texto fará com que o espaço seja gerado até a próxima parada de guia.

Para definir as paradas de guia para o tamanho padrão de 32 unidades de diálogo, chame a versão sem parâmetros desta função de membro. Para definir as paradas de guia para um tamanho diferente de 32, chame a versão com o parâmetro *cxEachStop.* Para definir as paradas de guia para uma matriz de tamanhos, use a versão com dois parâmetros.

Esta função de membro só é processada por controles de edição de várias linhas.

`SetTabStops`não redesenhar automaticamente a janela de edição. Se você alterar as guias para texto já no controle de edição, chame [CWnd::InvalidRect](cwnd-class.md#invalidaterect) para redesenhar a janela de edição.

Para obter mais informações, consulte [EM_SETTABSTOPS](/windows/win32/Controls/em-settabstops) e [GetDialogBaseUnits](/windows/win32/api/winuser/nf-winuser-getdialogbaseunits) no Windows SDK.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::SetTabStops](ceditview-class.md#settabstops).

## <a name="ceditshowballoontip"></a><a name="showballoontip"></a>CEdit::ShowBalloonTip

Exibe uma ponta de balão associada ao controle de edição atual.

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
|*ponta de balão pEditBalloon*|[em] Pointer para uma estrutura [EDITBALLOONTIP](/windows/win32/api/commctrl/ns-commctrl-editballoontip) que descreve a ponta do balão.|
|*lpszTitle*|[em] Pointer para uma seqüência Unicode que contém o título da ponta do balão.|
|*lpszText*|[em] Pointer para uma seqüência Unicode que contém o texto da ponta do balão.|
|*ttiIcon*|[em] Um **INT** que especifica o tipo de ícone para associar com a ponta do balão. O valor padrão é TTI_NONE. Para obter mais `ttiIcon` informações, consulte o membro da estrutura [EDITBALLOONTIP.](/windows/win32/api/commctrl/ns-commctrl-editballoontip)|

### <a name="return-value"></a>Valor retornado

VERDADE se este método for bem sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esta função envia a mensagem [EM_SHOWBALLOONTIP,](/windows/win32/Controls/em-showballoontip) que é descrita no SDK do Windows. Para obter mais informações, consulte a [macro Edit_ShowBalloonTip.](/windows/win32/api/commctrl/nf-commctrl-edit_showballoontip)

### <a name="example"></a>Exemplo

O exemplo de código a `m_cedit`seguir define uma variável, que é usada para acessar o controle de edição atual. Esta variável é usada no próximo exemplo.

[!code-cpp[NVC_MFC_CEdit_s1#1](../../mfc/reference/codesnippet/cpp/cedit-class_25.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir exibe uma ponta de balão para um controle de edição. O método [CEdit::ShowBalloonTip](#showballoontip) especifica um texto de dica de título e balão.

[!code-cpp[NVC_MFC_CEdit_s1#3](../../mfc/reference/codesnippet/cpp/cedit-class_26.cpp)]

## <a name="ceditundo"></a><a name="undo"></a>CEdit::Undo

Chame esta função para desfazer a última operação de controle de edição.

```
BOOL Undo();
```

### <a name="return-value"></a>Valor retornado

Para um controle de edição de linha única, o valor de retorno é sempre não zero. Para um controle de edição de várias linhas, o valor de retorno não é zero se a operação dedesfazer for bem sucedida ou 0 se a operação desfazer falhar.

### <a name="remarks"></a>Comentários

Uma operação de desfazer também pode ser desfeita. Por exemplo, você pode restaurar texto excluído `Undo`com a primeira chamada para . Enquanto não houver operação de edição intervindo, você pode remover `Undo`o texto novamente com uma segunda chamada para .

Para obter mais informações, consulte [EM_UNDO](/windows/win32/Controls/em-undo) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#25](../../mfc/reference/codesnippet/cpp/cedit-class_27.cpp)]

## <a name="see-also"></a>Confira também

[Amostra de MFC CALCDRIV](../../overview/visual-cpp-samples.md)<br/>
[Amostra de MFC CMNCTRL2](../../overview/visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](cwnd-class.md)<br/>
[Classe CButton](cbutton-class.md)<br/>
[Classe CComboBox](ccombobox-class.md)<br/>
[Classe CListBox](clistbox-class.md)<br/>
[Classe CScrollBar](cscrollbar-class.md)<br/>
[Classe CStatic](cstatic-class.md)<br/>
[Classe CDialog](cdialog-class.md)
