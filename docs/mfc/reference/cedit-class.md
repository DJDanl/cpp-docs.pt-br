---
title: Classe CEdit | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fc11631b6a9b4c675d488d69c5575a89853e64a3
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079266"
---
# <a name="cedit-class"></a>Classe CEdit

Fornece a funcionalidade de um controle de edição do Windows.

## <a name="syntax"></a>Sintaxe

```
class CEdit : public CWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CEdit::CEdit](#cedit)|Constrói um `CEdit` objeto de controle.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CEdit::CanUndo](#canundo)|Determina se uma operação de controle de edição pode ser desfeita.|
|[CEdit::CharFromPos](#charfrompos)|Recupera os índices de linha e de caractere para o caractere mais próximo para uma posição especificada.|
|[CEdit::Clear](#clear)|Exclusões (limpa) a seleção atual (se houver) na edição de controle.|
|[CEdit::Copy](#copy)|Copia a seleção atual (se houver) no controle de edição para a área de transferência no formato CF_TEXT.|
|[CEdit::Create](#create)|Cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.|
|[CEdit::Cut](#cut)|Controle de seleção atual (se houver) na edição de exclusões (cortes) e copia o texto excluído na área de transferência no CF_TEXT de formato.|
|[CEdit::EmptyUndoBuffer](#emptyundobuffer)|Redefine o controle (limpa) o sinalizador de desfazer de uma edição.|
|[CEdit::FmtLines](#fmtlines)|Define a inclusão de caracteres de quebra de linha reversível ativada ou desativada dentro de um controle de edição de várias linhas.|
|[CEdit::GetCueBanner](#getcuebanner)|Recupera o texto que é exibido como a indicação de texto ou dica, em um controle de edição quando o controle está vazio e não tem o foco.|
|[CEdit::GetFirstVisibleLine](#getfirstvisibleline)|Determina a nível mais alta linha visível em um controle de edição.|
|[CEdit::GetHandle](#gethandle)|Recupera um identificador para a memória alocada no momento para um controle de edição de várias linhas.|
|[CEdit::GetHighlight](#gethighlight)|Obtém os índices de inicial e final de caracteres em um intervalo de texto que está realçado no controle de edição atual.|
|[CEdit::GetLimitText](#getlimittext)|Obtém a quantidade máxima de texto essa `CEdit` pode conter.|
|[CEdit::GetLine](#getline)|Recupera uma linha de texto de um controle de edição.|
|[CEdit::GetLineCount](#getlinecount)|Recupera o número de linhas em um controle de edição de várias linhas.|
|[CEdit::GetMargins](#getmargins)|Obtém as margens esquerdas e direita para este `CEdit`.|
|[CEdit::GetModify](#getmodify)|Determina se o conteúdo de um controle de edição foi modificado.|
|[CEdit::GetPasswordChar](#getpasswordchar)|Recupera o caractere de senha exibido em um controle de edição, quando o usuário insere texto.|
|[CEdit::GetRect](#getrect)|Obtém o retângulo de formatação de um controle de edição.|
|[CEdit::GetSel](#getsel)|Obtém as posições de primeiro e último caractere da seleção atual em um controle de edição.|
|[CEdit::HideBalloonTip](#hideballoontip)|Impede que qualquer dica de balão associada ao controle de edição atual.|
|[CEdit::LimitText](#limittext)|Limita o comprimento do texto que o usuário pode inserir em um controle de edição.|
|[CEdit::LineFromChar](#linefromchar)|Recupera o número de linha da linha que contém o índice do caractere especificado.|
|[CEdit::LineIndex](#lineindex)|Recupera o índice de caracteres de uma linha dentro de um controle de edição de várias linhas.|
|[CEdit::LineLength](#linelength)|Recupera o comprimento de uma linha em um controle de edição.|
|[CEdit::LineScroll](#linescroll)|Rola o texto de um controle de edição de várias linhas.|
|[CEdit::Paste](#paste)|Insere os dados da área de transferência no controle de edição na posição atual do cursor. Dados são inseridos somente se a área de transferência contém dados no formato CF_TEXT.|
|[CEdit::PosFromChar](#posfromchar)|Recupera as coordenadas do canto superior esquerdo de um índice de caractere especificado.|
|[CEdit::ReplaceSel](#replacesel)|Substitui a seleção atual em um controle de edição com o texto especificado.|
|[CEdit::SetCueBanner](#setcuebanner)|Define o texto que é exibido como a indicação de texto ou dica, em um controle de edição quando o controle está vazio e não tem o foco.|
|[CEdit::SetHandle](#sethandle)|Define o identificador para a memória local que será usada por um controle de edição de várias linhas.|
|[CEdit::SetHighlight](#sethighlight)|Destaques de um intervalo de texto que é exibido no atual de controle de edição.|
|[CEdit::SetLimitText](#setlimittext)|Define a quantidade máxima de texto isso `CEdit` pode conter.|
|[CEdit::SetMargins](#setmargins)|Define as margens esquerdas e direita para esse `CEdit`.|
|[CEdit::SetModify](#setmodify)|Define ou limpa o sinalizador de modificação de um controle de edição.|
|[CEdit::SetPasswordChar](#setpasswordchar)|Define ou remove um caractere de senha exibido em um controle de edição, quando o usuário insere texto.|
|[CEdit::SetReadOnly](#setreadonly)|Define o estado somente leitura de um controle de edição.|
|[CEdit::SetRect](#setrect)|Define o retângulo de formatação de um controle de edição de várias linhas e atualiza o controle.|
|[CEdit::SetRectNP](#setrectnp)|Define o retângulo de formatação de um controle de edição de várias linhas sem redesenhar a janela de controle.|
|[CEdit::SetSel](#setsel)|Seleciona um intervalo de caracteres em um controle de edição.|
|[CEdit::SetTabStops](#settabstops)|Define as paradas de tabulação em várias linhas de controle de edição.|
|[CEdit::ShowBalloonTip](#showballoontip)|Exibe uma dica de balão associada ao controle de edição atual.|
|[CEdit::Undo](#undo)|Inverte a última operação de controle de edição.|

## <a name="remarks"></a>Comentários

Um controle de edição é uma janela filho retangular na qual o usuário pode digitar texto.

Você pode criar um controle de edição de um modelo de caixa de diálogo ou diretamente em seu código. Em ambos os casos, chame o construtor `CEdit` para construir o `CEdit` do objeto, em seguida, chame o [criar](#create) controle de edição de função de membro para criar o Windows e anexá-lo para o `CEdit` objeto.

Construção pode ser um processo de uma etapa em uma classe derivada de `CEdit`. Escrever um construtor para a classe derivada e a chamada `Create` do construtor.

`CEdit` herda a funcionalidade significativa do `CWnd`. Para definir e recuperar o texto de um `CEdit` do objeto, use o `CWnd` funções de membro [SetWindowText](cwnd-class.md#setwindowtext) e [GetWindowText](cwnd-class.md#getwindowtext), quais set ou get todo o conteúdo de uma edição de controle, mesmo se ele é um controle de várias linhas. Linhas de texto em um controle de várias linhas são separadas por sequências de caracteres '\r\n'. Além disso, se um controle de edição é multilinha, obter e configurar a parte do texto do controle, chamando o `CEdit` funções de membro [GetLine](#getline), [SetSel](#setsel), [GetSel](#getsel)e [ ReplaceSel](#replacesel).

Se você quiser manipular mensagens de notificação do Windows enviadas por um controle de edição para seu pai (normalmente uma classe derivada de `CDialog`), adicione uma função de membro de entrada e o manipulador de mensagens do mapa de mensagem para a classe pai para cada mensagem.

Cada entrada de mapa de mensagem usa o seguinte formato:

  **On _**_notificação_**(** _id_**,** _memberFxn_ **)**

em que `id` Especifica a ID de janela filho do controle de edição, enviando a notificação e `memberFxn` é o nome da função de membro pai que você tenha escrito para manipular a notificação.

O protótipo de função do pai é o seguinte:

**afx_msg** memberFxn void **();**

A seguir está uma lista de entradas de mapa de mensagem potenciais e uma descrição dos casos em que eles seriam enviados ao pai:

- ON_EN_CHANGE o usuário executou uma ação que pode ter alterado o texto em um controle de edição. Ao contrário de mensagem de notificação EN_UPDATE, esta mensagem de notificação é enviada depois que a exibição de atualizações do Windows.

- ON_EN_ERRSPACE o controle de edição não é possível alocar memória suficiente para atender a uma solicitação específica.

- ON_EN_HSCROLL o usuário clica em barras de rolagem horizontal do controle de edição. A janela pai é notificada antes da tela é atualizada.

- O controle de edição ON_EN_KILLFOCUS perde o foco de entrada.

- ON_EN_MAXTEXT de inserção atual excedeu o número especificado de caracteres para o controle de edição e foi truncado. Também é enviado quando um controle de edição não tem o estilo ES_AUTOHSCROLL e o número de caracteres a ser inserido excede a largura do controle de edição. Também é enviado quando um controle de edição não tem o estilo ES_AUTOVSCROLL e o número total de linhas resultante de uma inserção de texto excede a altura do controle de edição.

- ON_EN_SETFOCUS enviada quando um controle de edição recebe o foco de entrada.

- ON_EN_UPDATE o controle de edição é sobre o texto de exibição alterado. Enviado após o controle formatou o texto, mas antes de ele telas o texto para que o tamanho da janela pode ser alterado, se necessário.

- ON_EN_VSCROLL o usuário clica em barras de rolagem vertical do controle de edição. A janela pai é notificada antes da tela é atualizada.

Se você criar uma `CEdit` objeto dentro de uma caixa de diálogo, o `CEdit` objeto será destruído automaticamente quando o usuário fecha a caixa de diálogo.

Se você criar uma `CEdit` objeto de um recurso de caixa de diálogo usando o editor de caixa de diálogo, o `CEdit` objeto será destruído automaticamente quando o usuário fecha a caixa de diálogo.

Se você criar um `CEdit` do objeto dentro de uma janela, você também precisará destruí-lo. Se você criar o `CEdit` do objeto na pilha, ele será destruído automaticamente. Se você criar o `CEdit` objeto no heap usando a **novos** função, você deve chamar **excluir** no objeto a destruí-la quando o usuário termina o Windows o controle de edição. Se você alocar qualquer memória na `CEdit` do objeto, substituir o `CEdit` destruidor para dispose das alocações.

Para modificar alguns estilos em um controle de edição (por exemplo, ES_READONLY) você deve enviar mensagens específicas para o controle em vez de usar [ModifyStyle](cwnd-class.md#modifystyle). Ver [estilos de controle de edição](/windows/desktop/Controls/edit-control-styles) no Windows SDK.

Para obter mais informações sobre `CEdit`, consulte [controles](../../mfc/controls-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](cobject-class.md)

[CCmdTarget](ccmdtarget-class.md)

[CWnd](cwnd-class.md)

`CEdit`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="canundo"></a>  CEdit::CanUndo

Chame essa função para determinar se a última operação de edição pode ser desfeita.

```
BOOL CanUndo() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a última operação de edição pode ser desfeita por uma chamada para o `Undo` função de membro; 0 se ele não pode ser desfeito.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_CANUNDO](/windows/desktop/Controls/em-canundo) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::Undo](#undo).

##  <a name="cedit"></a>  CEdit::CEdit

Constrói um objeto `CEdit`.

```
CEdit();
```

### <a name="remarks"></a>Comentários

Use [criar](#create) para construir os Windows do controle de edição.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#1](../../mfc/reference/codesnippet/cpp/cedit-class_1.cpp)]

##  <a name="charfrompos"></a>  CEdit::CharFromPos

Chame essa função para recuperar a linha de base zero e os índices de caracteres do caractere mais próximo o ponto especificado neste `CEdit` controle

```
int CharFromPos(CPoint pt) const;
```

### <a name="parameters"></a>Parâmetros

*pt*<br/>
As coordenadas de um ponto na área de cliente deste `CEdit` objeto.

### <a name="return-value"></a>Valor de retorno

O índice do caractere da palavra de ordem inferior e o índice de linha a palavra de ordem superior.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função membro está disponível desde Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_CHARFROMPOS](/windows/desktop/Controls/em-charfrompos) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#3](../../mfc/reference/codesnippet/cpp/cedit-class_2.cpp)]

##  <a name="clear"></a>  CEdit::Clear

Chame essa função para excluir (clear) a seleção atual (se houver) no controle de edição.

```
void Clear();
```

### <a name="remarks"></a>Comentários

A exclusão executada pelo `Clear` pode ser desfeita com a chamada a [desfazer](#undo) função de membro.

Para excluir a seleção atual e colocar o conteúdo excluído na área de transferência, chame o [Recortar](#cut) função de membro.

Para obter mais informações, consulte [WM_CLEAR](/windows/desktop/dataxchg/wm-clear) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#4](../../mfc/reference/codesnippet/cpp/cedit-class_3.cpp)]

##  <a name="copy"></a>  CEdit::Copy

Chame essa função para copiar a seleção atual (se houver) no controle de edição na área de transferência no formato CF_TEXT.

```
void Copy();
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [WM_COPY](/windows/desktop/dataxchg/wm-copy) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#5](../../mfc/reference/codesnippet/cpp/cedit-class_4.cpp)]

##  <a name="create"></a>  CEdit::Create

Cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.

```
virtual BOOL Create(
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```

### <a name="parameters"></a>Parâmetros

*dwStyle*<br/>
Especifica o estilo do controle de edição. Aplicar qualquer combinação de [Editar estilos](styles-used-by-mfc.md#edit-styles) ao controle.

*Rect*<br/>
Especifica o tamanho e a posição do controle de edição. Pode ser um `CRect` objeto ou `RECT` estrutura.

*pParentWnd*<br/>
Especifica a janela pai do controle de edição (geralmente um `CDialog`). Ele não deve ser NULL.

*nID*<br/>
Especifica a ID. do controle de edição

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a inicialização for bem-sucedida; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você constrói um `CEdit` objeto em duas etapas. Primeiro, chame o `CEdit` construtor e em seguida, chame `Create`, que cria o controle de edição do Windows e anexa-o para o `CEdit` objeto.

Quando `Create` envios do Windows, executa o [WM_NCCREATE](/windows/desktop/winmsg/wm-nccreate), [WM_NCCALCSIZE](/windows/desktop/winmsg/wm-nccalcsize), [WM_CREATE](/windows/desktop/winmsg/wm-create), e [WM_GETMINMAXINFO](/windows/desktop/winmsg/wm-getminmaxinfo) mensagens para o controle de edição.

Essas mensagens são manipuladas por padrão, o [OnNcCreate](cwnd-class.md#onnccreate), [OnNcCalcSize](cwnd-class.md#onnccalcsize), [OnCreate](cwnd-class.md#oncreate), e [OnGetMinMaxInfo](cwnd-class.md#ongetminmaxinfo) funções de membro no `CWnd` classe base. Para estender o tratamento de mensagem padrão, derive uma classe de `CEdit`, adicionar um mapa de mensagem para a nova classe e substituir as funções de membro acima do manipulador de mensagens. Substituir `OnCreate`, por exemplo, para executar a inicialização necessária para a nova classe.

Aplicar o seguinte [estilos de janela](styles-used-by-mfc.md#window-styles) para um controle de edição.

- Sempre WS_CHILD

- Normalmente, WS_VISIBLE

- WS_DISABLED raramente

- WS_GROUP para agrupar controles

- WS_TABSTOP para incluir o controle de edição na ordem de tabulação

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#2](../../mfc/reference/codesnippet/cpp/cedit-class_5.cpp)]

##  <a name="cut"></a>  CEdit::Cut

Chame essa função para excluir (Recortar) a seleção atual (se houver) no controle de edição e copie o texto excluído para a área de transferência no formato CF_TEXT.

```
void Cut();
```

### <a name="remarks"></a>Comentários

A exclusão executada pelo `Cut` pode ser desfeita com a chamada a [desfazer](#undo) função de membro.

Para excluir a seleção atual sem colocar o texto excluído na área de transferência, chame o [clara](#clear) função de membro.

Para obter mais informações, consulte [WM_CUT](/windows/desktop/dataxchg/wm-cut) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#6](../../mfc/reference/codesnippet/cpp/cedit-class_6.cpp)]

##  <a name="emptyundobuffer"></a>  CEdit::EmptyUndoBuffer

Chame essa função para redefinir (limpar) o sinalizador de desfazer de um controle de edição.

```
void EmptyUndoBuffer();
```

### <a name="remarks"></a>Comentários

O controle de edição agora será possível desfazer a última operação. O sinalizador de desfazer é definido sempre que uma operação de controle de edição pode ser desfeita.

O sinalizador de desfazer é automaticamente limpo sempre que o [SetWindowText](../../mfc/reference/cwnd-class.md#setwindowtext) ou [SetHandle](#sethandle) `CWnd` são chamadas de funções de membro.

Para obter mais informações, consulte [EM_EMPTYUNDOBUFFER](/windows/desktop/Controls/em-emptyundobuffer) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#7](../../mfc/reference/codesnippet/cpp/cedit-class_7.cpp)]

##  <a name="fmtlines"></a>  CEdit::FmtLines

Chame essa função para definir a inclusão de caracteres de quebra de linha reversível ativada ou desativada dentro de um controle de edição de várias linhas.

```
BOOL FmtLines(BOOL bAddEOL);
```

### <a name="parameters"></a>Parâmetros

*bAddEOL*<br/>
Especifica se os caracteres de quebra de linha reversível estão a ser inserido. Um valor TRUE insere os caracteres; um valor FALSE remove-los.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se qualquer formatação ocorre; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma quebra de linha suave consiste em dois retornos de carro e um avanço de linha inserida no final de uma linha que é interrompida devido a quebra de texto. Uma quebra de linha rígido consiste em um retorno de carro e um avanço de linha. Linhas que terminam com uma quebra de linha rígido não são afetadas por `FmtLines`.

Windows só responderá se o `CEdit` objeto é um controle de edição de várias linhas.

`FmtLines` afeta somente o buffer retornado por [GetHandle](#gethandle) e o texto retornado por [WM_GETTEXT](/windows/desktop/winmsg/wm-gettext). Ele não tem impacto sobre a exibição do texto dentro do controle de edição.

Para obter mais informações, consulte [EM_FMTLINES](/windows/desktop/Controls/em-fmtlines) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#8](../../mfc/reference/codesnippet/cpp/cedit-class_8.cpp)]

##  <a name="getcuebanner"></a>  CEdit::GetCueBanner

Recupera o texto que é exibido como a indicação de texto ou dica, em um controle de edição quando o controle está vazio.

```
BOOL GetCueBanner(
    LPWSTR lpszText,
    int cchText) const;

CString GetCueBanner() const;
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[out] Um ponteiro para uma cadeia de caracteres que contém o texto de indicação.

*cchText*<br/>
[in] O número de caracteres que pode ser recebido. Esse número inclui o caractere nulo de terminação.

### <a name="return-value"></a>Valor de retorno

Para a primeira sobrecarga, TRUE se o método for bem-sucedido; Caso contrário, FALSE.

Para a segunda sobrecarga, uma [CString](../../atl-mfc-shared/using-cstring.md) que contém o texto de indicação se o método for bem-sucedido; caso contrário, a cadeia de caracteres vazia ("").

### <a name="remarks"></a>Comentários

Esse método envia o [EM_GETCUEBANNER](/windows/desktop/Controls/em-getcuebanner) mensagem, que é descrita no SDK do Windows. Para obter mais informações, consulte o [Edit_GetCueBannerText](/windows/desktop/api/commctrl/nf-commctrl-edit_getcuebannertext) macro.

##  <a name="getfirstvisibleline"></a>  CEdit::GetFirstVisibleLine

Chame essa função para determinar a linha superior visível em um controle de edição.

```
int GetFirstVisibleLine() const;
```

### <a name="return-value"></a>Valor de retorno

O índice baseado em zero da primeira linha visível. Para controles de edição de linha única, o valor de retorno é 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETFIRSTVISIBLELINE](/windows/desktop/Controls/em-getfirstvisibleline) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#9](../../mfc/reference/codesnippet/cpp/cedit-class_9.cpp)]

##  <a name="gethandle"></a>  CEdit::GetHandle

Chame essa função para recuperar um identificador para a memória alocada atualmente para um controle de edição de várias linhas.

```
HLOCAL GetHandle() const;
```

### <a name="return-value"></a>Valor de retorno

Um identificador de local de memória que identifica o buffer que contém o conteúdo do controle de edição. Se ocorrer um erro, como enviar a mensagem para um controle de edição de linha única, o valor de retorno é 0.

### <a name="remarks"></a>Comentários

O identificador é um identificador de memória local e pode ser usado por todos os **Local** lidar com funções de memória do Windows que usam um local de memória como um parâmetro.

`GetHandle` é processada apenas por controles de edição de várias linhas.

Chamar `GetHandle` para um controle de edição de várias linhas em uma caixa de diálogo somente se a caixa de diálogo foi criada com o sinalizador de estilo DS_LOCALEDIT definido. Se o estilo DS_LOCALEDIT não for definido, você ainda obterá um valor de retorno diferente de zero, mas você não poderá usar o valor retornado.

> [!NOTE]
> `GetHandle` não funcionará com o Windows 95/98. Se você chamar `GetHandle` no Windows 95/98, ele retornará NULL. `GetHandle` funcionará conforme documentado no Windows NT, versões 3.51 e posterior.

Para obter mais informações, consulte [EM_GETHANDLE](/windows/desktop/Controls/em-gethandle) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#10](../../mfc/reference/codesnippet/cpp/cedit-class_10.cpp)]

##  <a name="gethighlight"></a>  CEdit::GetHighlight

Obtém os índices do primeiro e último caracteres em um intervalo de texto que está realçado no controle de edição atual.

```
BOOL GetHighlight(
    int* pichStart,
    int* pichEnd) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*pichStart*|[out] Índice baseado em zero do primeiro caractere no intervalo de texto que está realçado.|
|*pichEnd*|[out] Índice baseado em zero do último caractere no intervalo de texto que está realçado.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [EM_GETHILITE](/windows/desktop/Controls/em-gethilite) mensagem, que é descrita no SDK do Windows. Ambos `SetHighlight` e `GetHighlight` está habilitado no momento para compilações de UNICODE somente.

##  <a name="getlimittext"></a>  CEdit::GetLimitText

Chame essa função de membro para obter o limite de texto para este `CEdit` objeto.

```
UINT GetLimitText() const;
```

### <a name="return-value"></a>Valor de retorno

O texto limite atual, em bytes, para este `CEdit` objeto.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em bytes, que o controle de edição pode aceitar.

> [!NOTE]
>  Essa função membro está disponível desde Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_GETLIMITTEXT](/windows/desktop/Controls/em-getlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#11](../../mfc/reference/codesnippet/cpp/cedit-class_11.cpp)]

##  <a name="getline"></a>  CEdit::GetLine

Chame essa função para recuperar uma linha de texto de um controle de edição e o coloca na *lpszbuffer é*.

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
Especifica o número de linha para recuperar de várias linhas de controle de edição. Números de linha são baseados em zero; um valor de 0 especifica a primeira linha. Esse parâmetro é ignorado por um controle de edição de linha única.

*lpszbuffer é*<br/>
Aponta para o buffer que recebe uma cópia da linha. A primeira palavra do buffer deve especificar o número máximo de caracteres que podem ser copiados para o buffer.

*nMaxLength*<br/>
Especifica o número máximo de bytes que podem ser copiados para o buffer. `GetLine` coloca esse valor na primeira palavra da *lpszbuffer é* antes de fazer a chamada para o Windows.

### <a name="return-value"></a>Valor de retorno

O número de bytes realmente copiados. O valor retornado será 0 se o número de linha especificado por *nIndex* é maior que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

Linha copiada não contém um caractere nulo de terminação.

Para obter mais informações, consulte [EM_GETLINE](/windows/desktop/Controls/em-getline) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetLineCount](#getlinecount).

##  <a name="getlinecount"></a>  CEdit::GetLineCount

Chame essa função para recuperar o número de linhas em um controle de edição de várias linhas.

```
int GetLineCount() const;
```

### <a name="return-value"></a>Valor de retorno

Controle de edição de um inteiro que contém o número de linhas em várias linhas. Caso nenhum texto tenha sido inserido no controle de edição, o valor de retorno é 1.

### <a name="remarks"></a>Comentários

`GetLineCount` só é processada por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_GETLINECOUNT](/windows/desktop/Controls/em-getlinecount) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#12](../../mfc/reference/codesnippet/cpp/cedit-class_12.cpp)]

##  <a name="getmargins"></a>  CEdit::GetMargins

Chame essa função de membro para recuperar as margens esquerdas e direita desse controle de edição.

```
DWORD GetMargins() const;
```

### <a name="return-value"></a>Valor de retorno

A largura da margem esquerda na palavra de ordem inferior e a largura da margem direita da palavra de ordem superior.

### <a name="remarks"></a>Comentários

As margens são medidas em pixels.

> [!NOTE]
>  Essa função membro está disponível desde Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_GETMARGINS](/windows/desktop/Controls/em-getmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="getmodify"></a>  CEdit::GetModify

Chame essa função para determinar se o conteúdo de um controle de edição foram modificado.

```
BOOL GetModify() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conteúdo do controle de edição foi modificado; 0 se eles permanecem inalterados.

### <a name="remarks"></a>Comentários

Windows mantém um sinalizador interno que indica se o conteúdo do controle de edição tiver sido alterado. Esse sinalizador estiver desmarcado quando o controle de edição é criado pela primeira vez e também poderá ser limpa por meio da chamada a [SetModify](#setmodify) função de membro.

Para obter mais informações, consulte [EM_GETMODIFY](/windows/desktop/Controls/em-getmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#13](../../mfc/reference/codesnippet/cpp/cedit-class_13.cpp)]

##  <a name="getpasswordchar"></a>  CEdit::GetPasswordChar

Chame essa função para recuperar o caractere de senha é exibido em um controle de edição quando o usuário insere texto.

```
TCHAR GetPasswordChar() const;
```

### <a name="return-value"></a>Valor de retorno

Especifica o caractere a ser exibido em vez do caractere digitado pelo usuário. O valor retornado é NULL, não se existir nenhum caractere de senha.

### <a name="remarks"></a>Comentários

Se você criar um controle de edição com o estilo ES_PASSWORD, a DLL que suporta o controle determina o caractere de senha padrão. O manifesto ou o [InitCommonControlsEx](/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) método determina qual DLL dá suporte a controle de edição. Se o User32 dá suporte a controle de edição, o caractere de senha padrão é o asterisco ('* ', U + 002A). Se o comctl32.dll versão 6 dá suporte a controle de edição, o caractere padrão é CÍRCULO preto ('●', U + 25CF). Para obter mais informações sobre o que dá suporte a DLL e versão controles comuns, consulte [Shell e versões de controles comuns](https://msdn.microsoft.com/library/windows/desktop/bb776779).

Esse método envia o [EM_GETPASSWORDCHAR](/windows/desktop/Controls/em-getpasswordchar) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#14](../../mfc/reference/codesnippet/cpp/cedit-class_14.cpp)]

##  <a name="getrect"></a>  CEdit::GetRect

Chame essa função para obter o retângulo de formatação de um controle de edição.

```
void GetRect(LPRECT lpRect) const;
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para o `RECT` estrutura que recebe o retângulo de formatação.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição.

O retângulo de formatação de um controle de edição de várias linhas pode ser modificado pela [SetRect](#setrect) e [SetRectNP](#setrectnp) funções de membro.

Para obter mais informações, consulte [EM_GETRECT](/windows/desktop/Controls/em-getrect) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LimitText](#limittext).

##  <a name="getsel"></a>  CEdit::GetSel

Chame essa função para obter o início e final posições de caractere da seleção atual (se houver) em um controle de edição, usando o valor de retorno ou os parâmetros.

```
DWORD GetSel() const;

void GetSel(
    int& nStartChar,
    int& nEndChar) const;
```

### <a name="parameters"></a>Parâmetros

*nStartChar*<br/>
Referência a um número inteiro que receberá a posição do primeiro caractere na seleção atual.

*nEndChar*<br/>
Referência a um número inteiro que receberá a posição do primeiro caractere após o fim da seleção atual não selecionado.

### <a name="return-value"></a>Valor de retorno

A versão que retorna um DWORD retorna um valor que contém a posição inicial da palavra de ordem inferior e a posição do primeiro caractere não selecionado após o fim da seleção da palavra de ordem superior.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_GETSEL](/windows/desktop/Controls/em-getsel) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#15](../../mfc/reference/codesnippet/cpp/cedit-class_15.cpp)]

##  <a name="hideballoontip"></a>  CEdit::HideBalloonTip

Impede que qualquer dica de balão associada ao controle de edição atual.

```
BOOL HideBalloonTip();
```

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função envia o [EM_HIDEBALLOONTIP](/windows/desktop/Controls/em-hideballoontip) mensagem, que é descrita no SDK do Windows.

##  <a name="limittext"></a>  CEdit::LimitText

Chame essa função para limitar o comprimento do texto que o usuário pode inserir em um controle de edição.

```
void LimitText(int nChars = 0);
```

### <a name="parameters"></a>Parâmetros

*nChars*<br/>
Especifica o comprimento (em bytes) do texto que o usuário pode inserir. Se esse parâmetro for 0, o comprimento do texto é definido como bytes UINT_MAX. Este é o comportamento padrão.

### <a name="remarks"></a>Comentários

Alterar o limite de texto restringe somente o texto que o usuário pode inserir. Ele não tem nenhum efeito em qualquer texto já no controle de edição, nem afeta o comprimento do texto copiado para o controle de edição, o [SetWindowText](cwnd-class.md#setwindowtext) função de membro em `CWnd`. Se um aplicativo usa o `SetWindowText` função para colocar mais texto em um controle de edição que foi especificada na chamada para `LimitText`, o usuário pode excluir qualquer texto dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substitua o texto existente pelo novo texto, a menos que excluindo a seleção atual faz com que o texto a cair abaixo do limite de texto.

> [!NOTE]
>  No Win32 (Windows NT e Windows 95/98), [SetLimitText](#setlimittext) substitui essa função.

Para obter mais informações, consulte [EM_LIMITTEXT](/windows/desktop/Controls/em-limittext) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#17](../../mfc/reference/codesnippet/cpp/cedit-class_16.cpp)]

##  <a name="linefromchar"></a>  CEdit::LineFromChar

Chame essa função para recuperar o número de linha da linha que contém o índice do caractere especificado.

```
int LineFromChar(int nIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Contém o valor de índice baseado em zero para o caractere desejado no texto do controle de edição ou -1. Se *nIndex* é -1, ele especifica a linha atual, ou seja, a linha que contém o cursor.

### <a name="return-value"></a>Valor de retorno

O número de linha de base zero da linha que contém o índice do caractere especificado por *nIndex*. Se *nIndex* é -1, o número da linha que contém o primeiro caractere da seleção é retornado. Se não houver nenhuma seleção, o número da linha atual será retornado.

### <a name="remarks"></a>Comentários

Um índice de caracteres é o número de caracteres do início do controle de edição.

Essa função de membro só é usada por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEFROMCHAR](/windows/desktop/Controls/em-linefromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#18](../../mfc/reference/codesnippet/cpp/cedit-class_17.cpp)]

##  <a name="lineindex"></a>  CEdit::LineIndex

Chame essa função para recuperar o índice de caracteres de uma linha dentro de um controle de edição de várias linhas.

```
int LineIndex(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLinha*<br/>
Contém o valor de índice para a linha desejada no texto do controle de edição ou -1. Se *nLinha* é -1, ele especifica a linha atual, ou seja, a linha que contém o cursor.

### <a name="return-value"></a>Valor de retorno

O índice do caractere da linha especificada no *nLinha* ou -1 se o número de linha especificado é maior que o número de linhas no controle de edição.

### <a name="remarks"></a>Comentários

O índice de caracteres é o número de caracteres do início do controle de edição para a linha especificada.

Essa função membro é processada somente por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_LINEINDEX](https://msdn.microsoft.com/library/windows/desktop/bb761611) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#19](../../mfc/reference/codesnippet/cpp/cedit-class_18.cpp)]

##  <a name="linelength"></a>  CEdit::LineLength

Recupera o comprimento de uma linha em um controle de edição.

```
int LineLength(int nLine = -1) const;
```

### <a name="parameters"></a>Parâmetros

*nLinha*<br/>
O índice baseado em zero de um caractere na linha cujo comprimento deve ser recuperado. O valor padrão é -1.

### <a name="return-value"></a>Valor de retorno

Para controles de edição de linha única, o valor de retorno é o comprimento, em TCHARs, do texto no controle de edição.

Para controles de edição de várias linhas, o valor de retorno é o comprimento, em TCHARs, da linha especificada pela *nLinha* parâmetro. Para texto ANSI, o comprimento é o número de bytes na linha. para texto em Unicode, o comprimento é o número de caracteres na linha. O tamanho não inclui o caractere de retorno de carro no final da linha.

Se o *nLinha* parâmetro for maior que o número de caracteres no controle, o valor retornado será zero.

Se o *nLinha* parâmetro é -1, o valor de retorno é o número de caracteres não selecionados em linhas que contêm caracteres selecionados. Por exemplo, se a seleção se estende do quarto caractere de uma linha por meio do oitavo caracteres do final da próxima linha, o valor de retorno é 10. Isto é, os três caracteres na primeira linha e sete na próxima.

Para obter mais informações sobre o tipo TCHAR, consulte a linha TCHAR na tabela [tipos de dados do Windows](/windows/desktop/WinProg/windows-data-types).

### <a name="remarks"></a>Comentários

Este método é compatível com o [EM_LINELENGTH](/windows/desktop/Controls/em-linelength) mensagem, que é descrita no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineIndex](#lineindex).

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
Especifica o número de posições de caractere para rolar horizontalmente. Esse valor será ignorado se o controle de edição tem o estilo ES_RIGHT ou ES_CENTER.

### <a name="remarks"></a>Comentários

Essa função membro é processada apenas por controles de edição de várias linhas.

O controle de edição não rola verticalmente após a última linha do texto no controle de edição. Se o atual de linha mais o número de linhas especificado pelo *nLines* excede o número total de linhas no controle de edição, o valor é ajustado para que a última linha do controle de edição é rolada para a parte superior da janela de controle de edição.

`LineScroll` pode ser usado para rolar horizontalmente após o último caractere de qualquer linha.

Para obter mais informações, consulte [EM_LINESCROLL](/windows/desktop/Controls/em-linescroll) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetFirstVisibleLine](#getfirstvisibleline).

##  <a name="paste"></a>  CEdit::Paste

Chame essa função para inserir os dados da área de transferência no `CEdit` no ponto de inserção.

```
void Paste();
```

### <a name="remarks"></a>Comentários

Dados são inseridos somente se a área de transferência contém dados no formato CF_TEXT.

Para obter mais informações, consulte [WM_PASTE](/windows/desktop/dataxchg/wm-paste) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#20](../../mfc/reference/codesnippet/cpp/cedit-class_19.cpp)]

##  <a name="posfromchar"></a>  CEdit::PosFromChar

Chame essa função para obter a posição (canto superior esquerdo) de um determinado caractere dentro deste `CEdit` objeto.

```
CPoint PosFromChar(UINT nChar) const;
```

### <a name="parameters"></a>Parâmetros

*nChar*<br/>
O índice baseado em zero do caractere especificado.

### <a name="return-value"></a>Valor de retorno

As coordenadas do canto superior esquerdo do caractere especificado por *nChar*.

### <a name="remarks"></a>Comentários

O caractere for especificado, fornecendo seu valor de índice baseado em zero. Se *nChar* é maior que o índice do último caractere nesse `CEdit` do objeto, o valor de retorno Especifica as coordenadas de posição do caractere logo após o último caractere nesse `CEdit` objeto.

> [!NOTE]
>  Essa função membro está disponível desde Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_POSFROMCHAR](/windows/desktop/Controls/em-posfromchar) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineFromChar](#linefromchar).

##  <a name="replacesel"></a>  CEdit::ReplaceSel

Chame essa função para substituir a seleção atual em um controle de edição com o texto especificado pelo *lpszNewText*.

```
void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszNewText*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o texto de substituição.

*bCanUndo*<br/>
Para especificar que essa função pode ser desfeita, defina o valor desse parâmetro como TRUE. O valor padrão é FALSE.

### <a name="remarks"></a>Comentários

Substitui apenas uma parte do texto em um controle de edição. Se você quiser substituir todo o texto, use o [CWnd::SetWindowText](cwnd-class.md#setwindowtext) função de membro.

Se não houver nenhuma seleção atual, o texto de substituição é inserido no local atual do cursor.

Para obter mais informações, consulte [EM_REPLACESEL](/windows/desktop/Controls/em-replacesel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::LineIndex](#lineindex).

##  <a name="setcuebanner"></a>  CEdit::SetCueBanner

Define o texto que é exibido como a indicação de texto, ou dica, em uma edição controlar quando o controle está vazio.

```
BOOL SetCueBanner(LPCWSTR lpszText);

BOOL SetCueBanner(
    LPCWSTR lpszText,
    BOOL fDrawWhenFocused = FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
[in] Ponteiro para uma cadeia de caracteres que contém a indicação para exibir no controle de edição.

*fDrawWhenFocused*<br/>
[in] Se for FALSE, a faixa de indicação não é desenhada quando o usuário clica no controle de edição e fornece o foco de controle.

Se for TRUE, a faixa de indicação é desenhada, mesmo quando o controle tem foco. A faixa de indicação desaparece quando o usuário começa a digitar no controle.

O valor padrão é FALSE.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método envia o [EM_SETCUEBANNER](/windows/desktop/Controls/em-setcuebanner) mensagem, que é descrita no SDK do Windows. Para obter mais informações, consulte o [Edit_SetCueBannerTextFocused](/windows/desktop/api/commctrl/nf-commctrl-edit_setcuebannertextfocused) macro.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra a [CEdit::SetCueBanner](#setcuebanner) método.

[!code-cpp[NVC_MFC_CEdit_s1#2](../../mfc/reference/codesnippet/cpp/cedit-class_20.cpp)]

##  <a name="sethandle"></a>  CEdit::SetHandle

Chame essa função para definir o identificador para a memória local que será usada por um controle de edição de várias linhas.

```
void SetHandle(HLOCAL hBuffer);
```

### <a name="parameters"></a>Parâmetros

*hBuffer*<br/>
Contém um identificador para a memória local. Esse identificador deve ter sido criado por uma chamada anterior a [LocalAlloc](/windows/desktop/api/winbase/nf-winbase-localalloc) função do Windows usando o sinalizador LMEM_MOVEABLE. A memória deve para conter uma cadeia de caracteres terminada em nulo. Se isso não for o caso, o primeiro byte da memória alocada deve ser definido como 0.

### <a name="remarks"></a>Comentários

O controle de edição, em seguida, usará esse buffer para armazenar o texto exibido em vez de alocar o próprio buffer.

Essa função membro é processada apenas por controles de edição de várias linhas.

Antes de um aplicativo define um novo identificador de memória, ele deve usar o [GetHandle](#gethandle) função de membro para obter o identificador para o buffer de memória atual e liberar essa memória usando o `LocalFree` função do Windows.

`SetHandle` Limpa o buffer de desfazer (o [CanUndo](#canundo) função de membro, em seguida, retorna 0) e o sinalizador interno de modificação (o [GetModify](#getmodify) função membro, em seguida, retorna 0). A janela de controle de edição é redesenhada.

Você pode usar essa função de membro em um controle de edição de várias linhas em uma caixa de diálogo somente se você tiver criado a caixa de diálogo com o sinalizador de estilo DS_LOCALEDIT definido.

> [!NOTE]
> `GetHandle` não funcionará com o Windows 95/98. Se você chamar `GetHandle` no Windows 95/98, ele retornará NULL. `GetHandle` funcionará conforme documentado no Windows NT, versões 3.51 e posterior.

Para obter mais informações, consulte [EM_SETHANDLE](/windows/desktop/Controls/em-sethandle), [LocalAlloc](/windows/desktop/api/winbase/nf-winbase-localalloc), e [LocalFree](/windows/desktop/api/winbase/nf-winbase-localfree) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#22](../../mfc/reference/codesnippet/cpp/cedit-class_21.cpp)]

##  <a name="sethighlight"></a>  CEdit::SetHighlight

Destaques de um intervalo de texto que é exibido no atual de controle de edição.

```
void SetHighlight(
    int ichStart,
    int ichEnd);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*ichStart*|[in] Índice baseado em zero do primeiro caractere no intervalo de texto para realçar.|
|*ichEnd*|[in] Índice baseado em zero do último caractere no intervalo de texto para realçar.|

### <a name="remarks"></a>Comentários

Esse método envia o [EM_SETHILITE](/windows/desktop/Controls/em-sethilite) mensagem, que é descrita no SDK do Windows.  Esse método envia o [EM_SETHILITE](/windows/desktop/Controls/em-sethilite) mensagem, que é descrita no SDK do Windows. Ambos `SetHighlight` e `GetHighlight` estão habilitados para UNICODE apenas compilações.

##  <a name="setlimittext"></a>  CEdit::SetLimitText

Chame essa função de membro para definir o limite de texto para este `CEdit` objeto.

```
void SetLimitText(UINT nMax);
```

### <a name="parameters"></a>Parâmetros

*Nmáx*<br/>
O novo limite de texto, em caracteres.

### <a name="remarks"></a>Comentários

O limite de texto é a quantidade máxima de texto, em caracteres, que o controle de edição pode aceitar.

Alterar o limite de texto restringe somente o texto que o usuário pode inserir. Ele não tem nenhum efeito em qualquer texto já no controle de edição, nem afeta o comprimento do texto copiado para o controle de edição, o [SetWindowText](cwnd-class.md#setwindowtext) função de membro em `CWnd`. Se um aplicativo usa o `SetWindowText` função para colocar mais texto em um controle de edição que foi especificada na chamada para `LimitText`, o usuário pode excluir qualquer texto dentro do controle de edição. No entanto, o limite de texto impedirá que o usuário substitua o texto existente pelo novo texto, a menos que excluindo a seleção atual faz com que o texto a cair abaixo do limite de texto.

Essa função substitui [LimitText](#limittext) no Win32.

Para obter mais informações, consulte [EM_SETLIMITTEXT](/windows/desktop/Controls/em-setlimittext) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="setmargins"></a>  CEdit::SetMargins

Chame esse método para definir as margens esquerdas e direita desse controle de edição.

```
void SetMargins(
    UINT nLeft,
    UINT nRight);
```

### <a name="parameters"></a>Parâmetros

*nLeft*<br/>
A largura da margem esquerda novo, em pixels.

*nRight*<br/>
A largura da margem direita novo, em pixels.

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função membro está disponível desde Windows 95 e Windows NT 4.0.

Para obter mais informações, consulte [EM_SETMARGINS](/windows/desktop/Controls/em-setmargins) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::GetEditCtrl](ceditview-class.md#geteditctrl).

##  <a name="setmodify"></a>  CEdit::SetModify

Chame essa função para definir ou limpar o sinalizador modificado para um controle de edição.

```
void SetModify(BOOL bModified = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bModified*<br/>
Um valor TRUE indica que o texto foi modificado, e um valor FALSE indica que é não modificado. Por padrão, o sinalizador modificado é definido.

### <a name="remarks"></a>Comentários

O sinalizador modificado indica se o texto dentro do controle de edição foi modificado. Ele é definido automaticamente sempre que o usuário altera o texto. Seu valor pode ser recuperado com o [GetModify](#getmodify) função de membro.

Para obter mais informações, consulte [EM_SETMODIFY](/windows/desktop/Controls/em-setmodify) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetModify](#getmodify).

##  <a name="setpasswordchar"></a>  CEdit::SetPasswordChar

Chame essa função para definir ou remover um caractere de senha exibido em um controle de edição, quando o usuário digita texto.

```
void SetPasswordChar(TCHAR ch);
```

### <a name="parameters"></a>Parâmetros

*ch*<br/>
Especifica o caractere a ser exibido no lugar do caractere digitado pelo usuário. Se *ch* for 0, os caracteres reais digitados pelo usuário são exibidos.

### <a name="remarks"></a>Comentários

Quando um caractere de senha é definido, esse caractere é exibido para cada caractere que o usuário digita.

Essa função de membro não tem nenhum efeito em várias linhas controle de edição.

Quando o `SetPasswordChar` função de membro é chamada, `CEdit` redesenhará todos os caracteres visíveis usando o caractere especificado por *ch*.

Se o controle de edição for criado com o [ES_PASSWORD](styles-used-by-mfc.md#edit-styles) estilo, o caractere de senha padrão é definido como um asterisco ( <strong>\*</strong>). Esse estilo é removido se `SetPasswordChar` é chamado com *ch* definido como 0.

Para obter mais informações, consulte [EM_SETPASSWORDCHAR](/windows/desktop/Controls/em-setpasswordchar) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#16](../../mfc/reference/codesnippet/cpp/cedit-class_22.cpp)]

##  <a name="setreadonly"></a>  CEdit::SetReadOnly

Chama esta função para definir o estado somente leitura de um controle de edição.

```
BOOL SetReadOnly(BOOL bReadOnly = TRUE);
```

### <a name="parameters"></a>Parâmetros

*bReadOnly*<br/>
Especifica se deve definir ou remover o estado somente leitura do controle de edição. Um valor TRUE define o estado como somente leitura; um valor FALSE define o estado como leitura/gravação.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a operação for bem-sucedida, ou 0 se ocorrer um erro.

### <a name="remarks"></a>Comentários

A configuração atual pode ser encontrada pelo teste de [ES_READONLY](styles-used-by-mfc.md#edit-styles) sinalizador no valor de retorno [CWnd::GetStyle](cwnd-class.md#getstyle).

Para obter mais informações, consulte [EM_SETREADONLY](/windows/desktop/Controls/em-setreadonly) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#23](../../mfc/reference/codesnippet/cpp/cedit-class_23.cpp)]

##  <a name="setrect"></a>  CEdit::SetRect

Chame essa função para definir as dimensões de um retângulo usando coordenadas especificadas.

```
void SetRect(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para o `RECT` estrutura ou `CRect` objeto que especifica as novas dimensões do retângulo de formatação.

### <a name="remarks"></a>Comentários

Esse membro é processado apenas por controles de edição de várias linhas.

Use `SetRect` para definir a formatação de controle de edição do retângulo de várias linhas. O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição. Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo que a área de cliente da janela do controle de edição. Usando o `SetRect` função de membro, um aplicativo pode fazer o retângulo de formatação maior ou menor que a janela de controle de edição.

Se o controle de edição não tem nenhuma barra de rolagem, texto será recortado, não encapsulados, se o retângulo de formatação for feito maior que a janela. Se o controle de edição contiver uma borda, o retângulo de formatação é reduzido pelo tamanho da borda. Se você ajustar o retângulo retornado pela `GetRect` função de membro, você deve remover o tamanho da borda antes de você passar o retângulo a ser `SetRect`.

Quando `SetRect` é chamado, o controle de edição do texto é reformatado e reexibido também.

Para obter mais informações, consulte [EM_SETRECT](/windows/desktop/Controls/em-setrect) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#24](../../mfc/reference/codesnippet/cpp/cedit-class_24.cpp)]

##  <a name="setrectnp"></a>  CEdit::SetRectNP

Chame essa função para definir o retângulo de formatação de um controle de edição de várias linhas.

```
void SetRectNP(LPCRECT lpRect);
```

### <a name="parameters"></a>Parâmetros

*lpRect*<br/>
Aponta para um `RECT` estrutura ou `CRect` objeto que especifica as novas dimensões do retângulo.

### <a name="remarks"></a>Comentários

O retângulo de formatação é o retângulo de limitação do texto, que é independente do tamanho da janela de controle de edição.

`SetRectNP` é idêntico de `SetRect` função de membro, exceto que a janela de controle de edição não é redesenhada.

Quando o controle de edição é criado pela primeira vez, o retângulo de formatação é o mesmo que a área de cliente da janela do controle de edição. Chamando o `SetRectNP` função de membro, um aplicativo pode fazer o retângulo de formatação maior ou menor que a janela de controle de edição.

Se o controle de edição não tem nenhuma barra de rolagem, texto será recortado, não encapsulados, se o retângulo de formatação for feito maior que a janela.

Esse membro é processado apenas por controles de edição de várias linhas.

Para obter mais informações, consulte [EM_SETRECTNP](/windows/desktop/Controls/em-setrectnp) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::SetRect](#setrect).

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
Especifica a posição inicial da palavra de ordem inferior e a posição final da palavra de ordem superior. Se a palavra de ordem inferior é 0 e a palavra de ordem superior é -1, todo o texto no controle de edição é selecionado. Se a palavra de ordem inferior é -1, qualquer seleção atual é removida.

*bNoScroll*<br/>
Indica se o cursor deve ser colocado na exibição. Se for FALSE, o cursor for colocado na exibição. Se for TRUE, o cursor não for colocado na exibição.

*nStartChar*<br/>
Especifica a posição inicial. Se *nStartChar* é 0 e *nEndChar* é -1, todos o texto no controle de edição é selecionado. Se *nStartChar* é -1, qualquer seleção atual é removida.

*nEndChar*<br/>
Especifica a posição final.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [EM_SETSEL](/windows/desktop/Controls/em-setsel) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEdit::GetSel](#getsel).

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
Especifica que as paradas de tabulação devem ser definidas em cada *cxEachStop* unidades de diálogo.

*nTabStops*<br/>
Especifica o número de paradas de tabulação contido em *rgTabStops*. Esse número deve ser maior que 1.

*rgTabStops*<br/>
Aponta para uma matriz de inteiros sem sinal, especificando a guia para em unidades de diálogo. Uma unidade de caixa de diálogo é uma distância horizontal ou vertical. Uma unidade de caixa de diálogo horizontal é igual a um quarto da unidade de base de largura da caixa de diálogo atual e 1 unidade vertical da caixa de diálogo é igual a um oitavo da unidade de base de altura da caixa de diálogo atual. As unidades base da caixa de diálogo são calculadas com base na altura e largura da fonte atual do sistema. O `GetDialogBaseUnits` função Windows retorna a caixa de diálogo atual unidades base em pixels.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se as guias foram definidas; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Quando o texto é copiado para um controle de edição de várias linhas, qualquer caractere de tabulação no texto fará com que o espaço a ser gerado até a próxima parada de tabulação.

Para definir paradas de tabulação para o tamanho padrão de 32 unidades de caixa de diálogo, chame a versão sem parâmetros dessa função de membro. Para definir paradas de tabulação para um tamanho diferente de 32, chame a versão com o *cxEachStop* parâmetro. Para definir paradas de tabulação para uma matriz de tamanhos, use a versão com dois parâmetros.

Essa função membro é processada somente por controles de edição de várias linhas.

`SetTabStops` não atualiza automaticamente a janela de edição. Se você alterar as paradas de tabulação para texto já está no controle de edição, chame [CWnd::InvalidateRect](cwnd-class.md#invalidaterect) redesenhar a janela de edição.

Para obter mais informações, consulte [EM_SETTABSTOPS](/windows/desktop/Controls/em-settabstops) e [GetDialogBaseUnits](/windows/desktop/api/winuser/nf-winuser-getdialogbaseunits) no SDK do Windows.

### <a name="example"></a>Exemplo

  Veja o exemplo de [CEditView::SetTabStops](ceditview-class.md#settabstops).

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
|*pEditBalloonTip*|[in] Ponteiro para um [EDITBALLOONTIP](/windows/desktop/api/commctrl/ns-commctrl-_tageditballoontip) estrutura que descreve a dica de balão.|
|*lpszTitle*|[in] Ponteiro para uma cadeia de caracteres Unicode que contém o título da dica de balão.|
|*lpszText*|[in] Ponteiro para uma cadeia de caracteres Unicode que contém o texto de dica de balão.|
|*ttiIcon*|[in] Uma **INT** que especifica o tipo de ícone a ser associado com a dica de balão. O valor padrão é TTI_NONE. Para obter mais informações, consulte o `ttiIcon` membro a [EDITBALLOONTIP](/windows/desktop/api/commctrl/ns-commctrl-_tageditballoontip) estrutura.|

### <a name="return-value"></a>Valor de retorno

TRUE se esse método for bem-sucedida; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Essa função envia o [EM_SHOWBALLOONTIP](/windows/desktop/Controls/em-showballoontip) mensagem, que é descrita no SDK do Windows. Para obter mais informações, consulte o [Edit_ShowBalloonTip](/windows/desktop/api/commctrl/nf-commctrl-edit_showballoontip) macro.

### <a name="example"></a>Exemplo

O exemplo de código a seguir define uma variável, `m_cedit`, que é usado para acessar o controle de edição atual. Essa variável é usada no exemplo a seguir.

[!code-cpp[NVC_MFC_CEdit_s1#1](../../mfc/reference/codesnippet/cpp/cedit-class_25.h)]

### <a name="example"></a>Exemplo

O exemplo de código a seguir exibe uma dica de balão para um controle de edição. O [CEdit::ShowBalloonTip](#showballoontip) método Especifica um texto da dica de balão e de título.

[!code-cpp[NVC_MFC_CEdit_s1#3](../../mfc/reference/codesnippet/cpp/cedit-class_26.cpp)]

##  <a name="undo"></a>  CEdit::Undo

Chame essa função para desfazer a última operação de controle de edição.

```
BOOL Undo();
```

### <a name="return-value"></a>Valor de retorno

Para um controle de edição de linha única, o valor retornado é sempre diferente de zero. Para um controle de edição de várias linhas, o valor de retorno é diferente de zero se a operação de desfazer for bem-sucedida, ou 0 se a operação de desfazer falhar.

### <a name="remarks"></a>Comentários

Uma operação de desfazer também pode ser desfeita. Por exemplo, você pode restaurar o texto excluído com a primeira chamada para `Undo`. Desde que não há nenhuma operação de edição intermediários, você pode remover o texto novamente com uma segunda chamada para `Undo`.

Para obter mais informações, consulte [EM_UNDO](/windows/desktop/Controls/em-undo) no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFC_CEdit#25](../../mfc/reference/codesnippet/cpp/cedit-class_27.cpp)]

## <a name="see-also"></a>Consulte também

[Exemplo MFC CALCDRIV](../../visual-cpp-samples.md)<br/>
[CMNCTRL2 de exemplo do MFC](../../visual-cpp-samples.md)<br/>
[Classe CWnd](../../mfc/reference/cwnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CWnd](cwnd-class.md)<br/>
[Classe CButton](cbutton-class.md)<br/>
[Classe CComboBox](ccombobox-class.md)<br/>
[Classe CListBox](clistbox-class.md)<br/>
[Classe CScrollBar](cscrollbar-class.md)<br/>
[Classe CStatic](cstatic-class.md)<br/>
[Classe CDialog](cdialog-class.md)
