---
title: Classe CMiniFrameWnd
ms.date: 11/04/2016
f1_keywords:
- CMiniFrameWnd
- AFXWIN/CMiniFrameWnd
- AFXWIN/CMiniFrameWnd::CMiniFrameWnd
- AFXWIN/CMiniFrameWnd::Create
- AFXWIN/CMiniFrameWnd::CreateEx
helpviewer_keywords:
- CMiniFrameWnd [MFC], CMiniFrameWnd
- CMiniFrameWnd [MFC], Create
- CMiniFrameWnd [MFC], CreateEx
ms.assetid: b8f534ed-0532-4d8e-9657-5595cf677749
ms.openlocfilehash: e9b91161f4207f4d2215d8777beade93617ddfac
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319814"
---
# <a name="cminiframewnd-class"></a>Classe CMiniFrameWnd

Representa uma janela de armação de meia altura normalmente vista em torno de barras de ferramentas flutuantes.

## <a name="syntax"></a>Sintaxe

```
class CMiniFrameWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMiniFrameWnd::CMiniFrameWnd](#cminiframewnd)|Constrói um objeto `CMiniFrameWnd`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMiniFrameWnd::Criar](#create)|Cria `CMiniFrameWnd` um objeto após a construção.|
|[CMiniFrameWnd::CreateEx](#createex)|Cria `CMiniFrameWnd` um objeto (com opções adicionais) após a construção.|

## <a name="remarks"></a>Comentários

Essas janelas de mini-quadro se comportam como janelas de quadros normais, exceto que elas não têm botões ou menus de minimização/maximização e você só precisa clicar no menu do sistema para dispensá-los.

Para usar `CMiniFrameWnd` um objeto, primeiro defina o objeto. Em seguida, chame a função [Criar](#create) membro para exibir a janela do miniquadro.

Para obter mais informações `CMiniFrameWnd` sobre como usar objetos, consulte o artigo [Docking and Floating Toolbars](../../mfc/docking-and-floating-toolbars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMiniFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cminiframewndcminiframewnd"></a><a name="cminiframewnd"></a>CMiniFrameWnd::CMiniFrameWnd

Constrói um `CMiniFrameWnd` objeto, mas não cria a janela.

```
CMiniFrameWnd();
```

### <a name="remarks"></a>Comentários

Para criar a janela, chame [CMiniFrameWnd::Criar](#create).

## <a name="cminiframewndcreate"></a><a name="create"></a>CMiniFrameWnd::Criar

Cria a janela de miniquadro do `CMiniFrameWnd` Windows e a anexa ao objeto.

```
virtual BOOL Create(
    LPCTSTR lpClassName,
    LPCTSTR lpWindowName,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd = NULL,
    UINT nID = 0);
```

### <a name="parameters"></a>Parâmetros

*Boolean*<br/>
Aponta para uma seqüência de caracteres com término nulo que nomeia a classe Windows. O nome da classe pode ser qualquer nome registrado com a função global [AfxRegisterWndClass.](application-information-and-management.md#afxregisterwndclass) Se NULA, a classe de janela será registrada para você pela estrutura. O MFC dá à classe padrão os seguintes estilos e atributos:

- Define CS_DBLCLKS de bits de estilo, que envia mensagens de duplo clique para o procedimento da janela quando o usuário clica duas vezes no mouse.

- Define bits de estilo CS_HREDRAW e CS_VREDRAW, que direcionam o conteúdo da área do cliente a ser redesenhado quando a janela muda de tamanho.

- Define o cursor de classe para o IDC_ARROW padrão do Windows.

- Define o pincel de fundo da classe como NULL, para que a janela não apague seu plano de fundo.

- Define o ícone de classe para o ícone padrão do logotipo do Windows com bandeira sinuosa.

- Define a janela para o tamanho e posição padrão, conforme indicado pelo Windows.

*lpWindowName*<br/>
Aponta para uma seqüência de caracteres com término nulo que contém o nome da janela.

*Dwstyle*<br/>
Especifica os atributos de estilo da janela. Estes podem incluir estilos de janela padrão e um ou mais dos seguintes estilos especiais:

- MFS_MOVEFRAME Permite que a janela do miniquadro seja movida clicando em qualquer borda da janela, não apenas na legenda.

- MFS_4THICKFRAME Desativa o redimensionamento da janela do miniquadro.

- MFS_SYNCACTIVE Sincroniza a ativação da janela de miniquadro para a ativação de sua janela pai.

- MFS_THICKFRAME Permite que a janela de miniquadroseja tão pequena quanto o conteúdo da área do cliente permitir.

- MFS_BLOCKSYSMENU Desativa o acesso ao menu do sistema e ao menu de controle e os converte em parte da legenda (barra de título).

Consulte [CWnd::Criar](../../mfc/reference/cwnd-class.md#create) para uma descrição dos possíveis valores de estilo de janela. A combinação típica usada para janelas de miniquadros é WS_POPUP&#124;WS_CAPTION&#124;WS_SYSMENU.

*Rect*<br/>
Uma `RECT` estrutura especificando as dimensões desejadas da janela.

*Pparentwnd*<br/>
Aponta para a janela dos pais. Use NULL para janelas de nível superior.

*nID*<br/>
Se a janela de mini-quadro for criada como uma janela filho, este será o identificador do controle da criança; caso contrário, 0.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Create`inicializa o nome da classe da janela e o nome da janela e registra valores padrão para seu estilo e pai.

## <a name="cminiframewndcreateex"></a><a name="createex"></a>CMiniFrameWnd::CreateEx

Cria um objeto `CMiniFrameWnd`.

```
virtual BOOL CreateEx(
    DWORD dwExStyle,
    LPCTSTR lpClassName,
    LPCTSTR lpWindowName,
    DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd = NULL,
    UINT nID = 0);
```

### <a name="parameters"></a>Parâmetros

*Dwexstyle*<br/>
Especifica o estilo estendido `CMiniFrameWnd` do ser criado. Aplique qualquer um dos [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) à janela.

*Boolean*<br/>
Aponta para uma seqüência de caracteres com término nulo que nomeia a classe Windows (uma estrutura [WNDCLASS).](/windows/win32/api/winuser/ns-winuser-wndclassw) O nome da classe pode ser qualquer nome registrado com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) ou qualquer um dos nomes de classe de controle predefinidos. Não deve ser NULO.

*lpWindowName*<br/>
Aponta para uma seqüência de caracteres com término nulo que contém o nome da janela.

*Dwstyle*<br/>
Especifica os atributos de estilo da janela. Consulte [Estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CWnd::Criar](../../mfc/reference/cwnd-class.md#create) para uma descrição dos valores possíveis.

*Rect*<br/>
O tamanho e a posição da janela, nas coordenadas do cliente de *pParentWnd*.

*Pparentwnd*<br/>
Aponta para o objeto da janela pai.

*nID*<br/>
O identificador da janela da criança.

### <a name="return-value"></a>Valor retornado

Retorna TRUE no sucesso, FALSO no fracasso.

### <a name="remarks"></a>Comentários

Os `CreateEx` parâmetros especificam o WNDCLASS, o estilo da janela e (opcionalmente) a posição e o tamanho da janela. `CreateEx`também especifica o pai da janela (se houver) e iD.

Quando `CreateEx` é executado, o Windows envia as mensagens [WM_GETMINMAXINFO,](../../mfc/reference/cwnd-class.md#ongetminmaxinfo) [WM_NCCREATE,](../../mfc/reference/cwnd-class.md#onnccreate) [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) para a janela.

Para estender o tratamento padrão da `CMiniFrameWnd`mensagem, obtenha uma classe de , adicione um mapa de mensagem à nova classe e forneça funções de membro para as mensagens acima. Substituição, `OnCreate`por exemplo, para realizar a inicialização necessária para uma nova classe.

Anular outros `On`manipuladores de *mensagens* para adicionar mais funcionalidade à sua classe derivada.

Se o estilo WS_VISIBLE for dado, o Windows envia à janela todas as mensagens necessárias para ativar e mostrar a janela. Se o estilo da janela especificar uma barra de título, o título da janela apontado pelo parâmetro *lpszWindowName* será exibido na barra de título.

O parâmetro *dwStyle* pode ser qualquer combinação de estilos de [janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

As janelas da caixa de ferramentas paleta de estilo antigo não são mais suportadas. O estilo antigo, que não tinha um botão "X" Close, foi suportado ao executar um aplicativo MFC em versões anteriores do Windows, mas não é mais suportado no Visual C++.NET. Apenas o novo estilo WS_EX_TOOLWINDOW agora é suportado; para obter uma descrição deste estilo, consulte [Estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

## <a name="see-also"></a>Confira também

[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
