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
ms.openlocfilehash: 70f090e2d9830ccfdd98640b54ff07440064d542
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57293258"
---
# <a name="cminiframewnd-class"></a>Classe CMiniFrameWnd

Representa uma janela do quadro de metade da altura normalmente Vista em torno de barras de ferramentas flutuantes.

## <a name="syntax"></a>Sintaxe

```
class CMiniFrameWnd : public CFrameWnd
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMiniFrameWnd::CMiniFrameWnd](#cminiframewnd)|Constrói um objeto `CMiniFrameWnd`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CMiniFrameWnd::Create](#create)|Cria um `CMiniFrameWnd` objeto após a construção.|
|[CMiniFrameWnd::CreateEx](#createex)|Cria um `CMiniFrameWnd` objeto (com opções adicionais) após a construção.|

## <a name="remarks"></a>Comentários

Essas janelas com minimoldura se comportam como janelas com moldura normal, exceto que eles não têm maximizar/minimizar botões ou menus e você só precisará único clique no menu de sistema para ignorá-las.

Para usar um `CMiniFrameWnd` de objeto, primeiro defina o objeto. Em seguida, chame o [criar](#create) função de membro para exibir a janela com minimoldura.

Para obter mais informações sobre como usar `CMiniFrameWnd` objetos, consulte o artigo [encaixe e barras de ferramentas flutuante](../../mfc/docking-and-floating-toolbars.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CFrameWnd](../../mfc/reference/cframewnd-class.md)

`CMiniFrameWnd`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cminiframewnd"></a>  CMiniFrameWnd::CMiniFrameWnd

Constrói um `CMiniFrameWnd` do objeto, mas não cria a janela.

```
CMiniFrameWnd();
```

### <a name="remarks"></a>Comentários

Para criar a janela, chame [CMiniFrameWnd::Create](#create).

##  <a name="create"></a>  CMiniFrameWnd::Create

Cria a janela com minimoldura Windows e anexa-o para o `CMiniFrameWnd` objeto.

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
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe Windows. O nome de classe pode ser qualquer nome registrado com global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função. Se for NULL, a classe de janela será registrada para você pela estrutura. MFC fornece a classe padrão, os estilos e atributos a seguir:

- O bit de estilo de conjuntos CS_DBLCLKS, que envia duas vezes em mensagens para o procedimento de janela quando o usuário clica duas vezes no mouse.

- Define os bits de estilo CS_HREDRAW e CS_VREDRAW, que direcionam o conteúdo da área de cliente a ser redesenhado quando a janela de tamanho é alterado.

- Define o cursor de classe para o IDC_ARROW padrão do Windows.

- Define o pincel de plano de fundo de classe como NULL, portanto, a janela não apagará seu plano de fundo.

- Define o ícone de classe para o ícone do logotipo do Windows padrão, o sinalizador de ondulação.

- Define a janela para o tamanho padrão e a posição, conforme indicado pelo Windows.

*lpWindowName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da janela.

*dwStyle*<br/>
Especifica os atributos de estilo de janela. Eles podem incluir os estilos de janela padrão e um ou mais dos seguintes estilos especiais:

- MFS_MOVEFRAME permite que a janela com minimoldura a ser movido, clicando em qualquer borda da janela, não apenas a legenda.

- MFS_4THICKFRAME desabilita o redimensionamento da janela com minimoldura.

- MFS_SYNCACTIVE sincroniza a ativação da janela com minimoldura para a ativação da sua janela pai.

- MFS_THICKFRAME permite que permitem que a janela com minimoldura que ser dimensionados tão pequena quanto o conteúdo da área de cliente.

- MFS_BLOCKSYSMENU desabilita o acesso ao menu de sistema e o menu de controle e os converte em parte da legenda (barra de título).

Ver [CWnd::Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição dos valores de estilo de janela possível. A combinação de típica usada para janelas com moldura mini é WS_POPUP&#124;WS_CAPTION&#124;WS_SYSMENU.

*rect*<br/>
Um `RECT` especificando as dimensões desejadas da janela de estrutura.

*pParentWnd*<br/>
Aponta para a janela pai. Use NULL para janelas de nível superior.

*nID*<br/>
Se a janela com minimoldura é criada como uma janela filho, esse é o identificador do controle filho; Caso contrário, 0.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

`Create` inicializa o nome da classe da janela e o nome da janela e registra os valores padrão para seu pai e o estilo.

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
Especifica o estilo estendido do `CMiniFrameWnd` que está sendo criado. Aplicar qualquer um dos [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles) à janela.

*lpClassName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que nomeia a classe do Windows (um [WNDCLASS](/windows/desktop/api/winuser/ns-winuser-tagwndclassa) estrutura). O nome de classe pode ser qualquer nome registrado com global [AfxRegisterWndClass](application-information-and-management.md#afxregisterwndclass) função ou qualquer um dos nomes predefinidos de classe de controle. Ele não deve ser NULL.

*lpWindowName*<br/>
Aponta para uma cadeia de caracteres terminada em nulo que contém o nome da janela.

*dwStyle*<br/>
Especifica os atributos de estilo de janela. Ver [estilos da janela](../../mfc/reference/styles-used-by-mfc.md#window-styles) e [CWnd::Create](../../mfc/reference/cwnd-class.md#create) para obter uma descrição dos possíveis valores.

*rect*<br/>
O tamanho e posição da janela, em coordenadas do cliente do *pParentWnd*.

*pParentWnd*<br/>
Aponta para o objeto de janela pai.

*nID*<br/>
O identificador da janela filho.

### <a name="return-value"></a>Valor de retorno

Retorna verdadeiro em caso de êxito, FALSE em caso de falha.

### <a name="remarks"></a>Comentários

O `CreateEx` os parâmetros especificam o WNDCLASS, o estilo da janela e a posição inicial (opcionalmente) e o tamanho da janela. `CreateEx` também especifica a janela pai (se houver) e ID.

Quando `CreateEx` envios do Windows, executa o [WM_GETMINMAXINFO](../../mfc/reference/cwnd-class.md#ongetminmaxinfo), [WM_NCCREATE](../../mfc/reference/cwnd-class.md#onnccreate), [WM_NCCALCSIZE](../../mfc/reference/cwnd-class.md#onnccalcsize), e [WM_CREATE](../../mfc/reference/cwnd-class.md#oncreate) mensagens na janela.

Para estender o tratamento de mensagem padrão, derive uma classe de `CMiniFrameWnd`, adicionar um mapa de mensagem para a nova classe e fornecer funções de membro para as mensagens acima. Substituir `OnCreate`, por exemplo, para executar a inicialização necessária para uma nova classe.

Substituir adicional `On` *mensagem* manipuladores para adicionar mais funcionalidade à sua classe derivada da mensagem.

Se o estilo WS_VISIBLE for fornecido, o Windows envia a janela de todas as mensagens necessárias para ativar e mostrar a janela. Se o estilo da janela especifica uma barra de título, o título da janela apontando para o *lpszWindowName* parâmetro é exibido na barra de título.

O *dwStyle* parâmetro pode ser qualquer combinação de [estilos de janela](../../mfc/reference/styles-used-by-mfc.md#window-styles).

Não há suporte para o antigo estilo paleta da caixa de ferramentas do windows. O estilo antigo, o que não tem um botão "X" Close, tinha suporte durante a execução de um aplicativo do MFC em versões anteriores do Windows, mas não é mais suportada no Visual C++ .NET. Agora há suporte para o novo estilo WS_EX_TOOLWINDOW; Para obter uma descrição desse estilo, consulte [estilos de janela estendidos](../../mfc/reference/styles-used-by-mfc.md#extended-window-styles).

## <a name="see-also"></a>Consulte também

[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CFrameWnd](../../mfc/reference/cframewnd-class.md)
