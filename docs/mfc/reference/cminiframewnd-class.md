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
ms.openlocfilehash: 45b4698cc70487a6c3fe1470fe27f7b5c4f95402
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504597"
---
# <a name="cminiframewnd-class"></a>Classe CMiniFrameWnd

Representa uma janela de quadro de meia altura normalmente vista em relação a barras de ferramentas flutuantes.

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
|[CMiniFrameWnd::Create](#create)|Cria um `CMiniFrameWnd` objeto após a construção.|
|[CMiniFrameWnd::CreateEx](#createex)|Cria um `CMiniFrameWnd` objeto (com opções adicionais) após a construção.|

## <a name="remarks"></a>Comentários

Essas janelas de mini quadros se comportam como janelas de quadros normais, exceto que não têm botões ou menus de minimizar/maximizar e você só precisa clicar com um único clique no menu do sistema para descartá-las.

Para usar um `CMiniFrameWnd` objeto, primeiro defina o objeto. Em seguida, chame a função [criar](#create) membro para exibir a janela do mini-quadro.

Para obter mais informações sobre como usar `CMiniFrameWnd` objetos, consulte o artigo [encaixe e barras de ferramentas flutuantes](../../mfc/docking-and-floating-toolbars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMiniFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

##  <a name="cminiframewnd"></a>  CMiniFrameWnd::CMiniFrameWnd

Constrói um `CMiniFrameWnd` objeto, mas não cria a janela.

```
CMiniFrameWnd();
```

### <a name="remarks"></a>Comentários

Para criar a janela, chame [CMiniFrameWnd:: Create](#create).

##  <a name="create"></a>  CMiniFrameWnd::Create

Cria a janela do mini-quadro do Windows e a anexa ao `CMiniFrameWnd` objeto.

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

*lpClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows. O nome da classe pode ser qualquer nome registrado com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) . Se for NULL, a classe Window será registrada para você pela estrutura. O MFC dá à classe padrão os seguintes estilos e atributos:

- Define o CS_DBLCLKS de bits de estilo, que envia mensagens de clique duplo para o procedimento de janela quando o usuário clica duas vezes no mouse.

- Define os bits de estilo CS_HREDRAW e CS_VREDRAW, que direcionam o conteúdo da área do cliente a ser redesenhado quando a janela muda de tamanho.

- Define o cursor de classe para o IDC_ARROW padrão do Windows.

- Define o pincel de plano de fundo da classe como nulo, portanto, a janela não apagará seu plano de fundo.

- Define o ícone de classe para o ícone de logotipo padrão acenando do Windows.

- Define a janela como o tamanho e a posição padrão, conforme indicado pelo Windows.

*lpWindowName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo que contém o nome da janela.

*dwStyle*<br/>
Especifica os atributos de estilo de janela. Eles podem incluir estilos de janela padrão e um ou mais dos seguintes estilos especiais:

- MFS_MOVEFRAME permite que a janela de mini-quadro seja movida clicando em qualquer borda da janela, não apenas na legenda.

- MFS_4THICKFRAME desabilita o redimensionamento da janela de mini-quadro.

- MFS_SYNCACTIVE sincroniza a ativação da janela de mini-quadro para a ativação de sua janela pai.

- MFS_THICKFRAME permite que a janela de mini-quadro seja dimensionada como pequena como o conteúdo da área de cliente permitir.

- MFS_BLOCKSYSMENU desabilita o acesso ao menu do sistema e ao menu de controle e os converte em parte da legenda (barra de título).

Consulte [CWnd:: Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição de possíveis valores de estilo de janela. A combinação típica usada para janelas de mini quadros é WS_POPUP&#124;WS_CAPTION&#124;WS_SYSMENU.

*rect*<br/>
Uma `RECT` estrutura que especifica as dimensões desejadas da janela.

*pParentWnd*<br/>
Aponta para a janela pai. Use NULL para janelas de nível superior.

*nID*<br/>
Se a janela do mini-quadro for criada como uma janela filho, esse será o identificador do controle filho; caso contrário, 0.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Create`Inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para seu estilo e pai.

##  <a name="createex"></a>  CMiniFrameWnd::CreateEx

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

*dwExStyle*<br/>
Especifica o estilo estendido do `CMiniFrameWnd` que está sendo criado. Aplique qualquer um dos [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) à janela.

*lpClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (uma estrutura [WNDCLASS](/windows/win32/api/winuser/ns-winuser-wndclassw) ). O nome da classe pode ser qualquer nome registrado com a função global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) ou qualquer um dos nomes de classe de controle predefinidos. Ele não deve ser nulo.

*lpWindowName*<br/>
Aponta para uma cadeia de caracteres de caractere terminada em nulo que contém o nome da janela.

*dwStyle*<br/>
Especifica os atributos de estilo de janela. Consulte [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CWnd:: Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição dos valores possíveis.

*rect*<br/>
O tamanho e a posição da janela, nas coordenadas do cliente de *pParentWnd*.

*pParentWnd*<br/>
Aponta para o objeto de janela pai.

*nID*<br/>
O identificador da janela filho.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, falso em caso de falha.

### <a name="remarks"></a>Comentários

Os `CreateEx` parâmetros especificam o WNDCLASS, o estilo da janela e (opcionalmente) a posição inicial e o tamanho da janela. `CreateEx`também especifica o pai da janela (se houver) e a ID.

Quando `CreateEx` o é executado, o Windows envia as mensagens [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo), [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize)e [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) para a janela.

Para estender a manipulação de mensagens padrão, derive uma `CMiniFrameWnd`classe de, adicione um mapa de mensagem à nova classe e forneça funções de membro para as mensagens acima. Substitua `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Substitua os `On`manipuladores de mensagens de *mensagem* adicionais para adicionar mais funcionalidades à classe derivada.

Se o estilo WS_VISIBLE for fornecido, o Windows enviará a janela todas as mensagens necessárias para ativar e mostrar a janela. Se o estilo da janela especificar uma barra de título, o título da janela apontado pelo parâmetro *lpszWindowName* será exibido na barra de título.

O parâmetro *dwStyle* pode ser qualquer combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

Não há mais suporte para as janelas de caixa de ferramentas de estilo antigo. O estilo antigo, que não tinha um botão de fechamento "X", tinha suporte ao executar um aplicativo MFC em versões anteriores do Windows, mas não há mais suporte no Visual C++.net. Somente o novo estilo WS_EX_TOOLWINDOW agora tem suporte; para obter uma descrição desse estilo, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

## <a name="see-also"></a>Consulte também

[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
