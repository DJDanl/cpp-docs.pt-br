---
title: 'TN031: barras de controle'
ms.date: 11/04/2016
f1_keywords:
- vc.controls.bars
helpviewer_keywords:
- control bars [MFC], styles
- CStatusBar class [MFC], Tech Note 31 usage
- CControlBar class [MFC], Tech Note 31 usage
- CControlBar class [MFC], deriving from
- control bars [MFC], classes [MFC]
- CDialogBar class [MFC], Tech Note 31 usage
- CToolBar class [MFC], Tech Note 31 usage
- TN031
- styles [MFC], control bars
ms.assetid: 8cb895c0-40ea-40ef-90ee-1dd29f34cfd1
ms.openlocfilehash: 37c3a15c281018260e65508dee3799ab0011dbfe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370299"
---
# <a name="tn031-control-bars"></a>TN031: barras de controle

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve as classes da barra de controle no MFC: a [CControlBar](#_mfcnotes_ccontrolbar) `CDockBar`geral, [CStatusBar,](#_mfcnotes_cstatusbar) [CToolBar,](#_mfcnotes_ctoolbar) [CDialogBar](#_mfcnotes_cdialogbar)e .

## <a name="ccontrolbar"></a><a name="_mfcnotes_ccontrolbar"></a>Ccontrolbar

A `ControlBar` é `CWnd`uma classe derivada que:

- Está alinhado à parte superior ou inferior de uma janela de quadro.

- Pode conter itens infantis que são controles baseados em HWND (por `CDialogBar`exemplo, ) ou itens não`HWND` baseados (por exemplo, `CToolBar`). `CStatusBar`

As barras de controle suportam os estilos adicionais:

- CBRS_TOP (O padrão) fixar a barra de controle na parte superior.

- CBRS_BOTTOM fixar a barra de controle até o fundo.

- CBRS_NOALIGN Não reposicione a barra de controle quando o pai for redimensionado.

Classes derivadas `CControlBar` fornecem implementações mais interessantes:

- `CStatusBar`Uma barra de status, itens são painéis de barra de status contendo texto.

- `CToolBar`Uma barra de ferramentas, itens são botões de bitmap alinhados em uma linha.

- `CDialogBar`Um quadro semelhante a uma barra de ferramentas contendo controles padrão do windows (criado a partir de um recurso de modelo de diálogo).

- `CDockBar`Uma área de acoplamento generalizada para outros `CControlBar` objetos derivados. As funções e variáveis específicas do membro disponíveis nesta classe provavelmente mudarão em versões futuras.

Todos os objetos/janelas da barra de controle serão janelas de algum quadro dos pais. Eles geralmente são adicionados como um irmão para a área cliente do quadro (por exemplo, um Cliente MDI ou exibição). A imincia da janela infantil de uma barra de controle é importante. O layout padrão da barra de controle só funciona para barras de controle com IDs na faixa de AFX_IDW_CONTROLBAR_FIRST para AFX_IDW_CONTROLBAR_LAST. Observe que, embora existam uma gama de 256 IDs de barra de controle, os primeiros 32 desses IDs de barra de controle são especiais, uma vez que são suportados diretamente pela arquitetura de visualização de impressão.

A `CControlBar` classe fornece implementação padrão para:

- Alinhando a barra de controle à parte superior, inferior ou de ambos os lados do quadro.

- Alocar matrizes de itens de controle.

- Apoio à implementação de classes derivadas.

Os objetos da barra de controle C++ geralmente serão incorporados como membros de uma `CFrameWnd` classe derivada e serão limpos quando o pai e o `HWND` objeto forem destruídos. Se você precisar alocar um objeto de barra de controle no heap, você pode simplesmente definir `HWND` o membro *m_bAutoDestruct* como **TRUE** para fazer a barra de controle " excluir**isso**" quando o for destruído.

> [!NOTE]
> Se você criar `CControlBar`sua própria classe derivada, em vez de usar uma `CStatusBar` `CToolBar`das `CDialogBar`classes derivadas do MFC, como , ou , você precisará definir o membro de dados *m_dwStyle.* Isso pode ser feito na `Create`substituição de:

```
// CMyControlBar is derived from CControlBar
BOOL CMyControlBar::Create(CWnd* pParentWnd,
    DWORD dwStyle,
    UINT nID)
{
    m_dwStyle = dwStyle;

.
.
.
}
```

**Algoritmo de layout da barra de controle**

O algoritmo de layout da barra de controle é muito simples. A janela do quadro envia uma mensagem WM_SIZEPARENT para todas as crianças na faixa da barra de controle. Junto com esta mensagem, um ponteiro para o retângulo do cliente do pai é passado. Esta mensagem é enviada para crianças em ordem Z. As crianças da barra de controle usam essas informações para se posicionare e diminuir o tamanho da área cliente dos pais. O retângulo final deixado para a área normal do cliente (menos barras de controle) é usado para posicionar a janela principal do cliente (geralmente uma janela de cliente MDI, visualização ou divisor).

Veja `CWnd::RepositionBars` `CFrameWnd::RecalcLayout` e para mais detalhes.

Mensagens privadas do Windows MFC, incluindo WM_SIZEPARENT, estão documentadas na [Nota Técnica 24](../mfc/tn024-mfc-defined-messages-and-resources.md).

## <a name="cstatusbar"></a><a name="_mfcnotes_cstatusbar"></a>Cstatusbar

Uma barra de status é uma barra de controle que tem uma linha de painéis de saída de texto. Existem duas maneiras comuns de usar painéis de saída de texto:

- Como uma linha de mensagem

     (por exemplo, a linha de mensagem de ajuda do menu padrão). Estes são geralmente acessados por um indexado baseado em 0

- Como indicadores de status

     (por exemplo, os indicadores CAP, NUM e SCRL). Estes são geralmente acessados por string/command ID.

A fonte para a barra de status é MS Sans Serif de 10 pontos (ditada pelo Guia de Design de Aplicativos de Interface do Windows ou os mapeadores de fonte melhor correspondência de uma fonte proporcional suíça de 10 pontos). Em certas versões do Windows, como a edição japonesa, as fontes selecionadas são diferentes.

As cores usadas na barra de status também são consistentes com a recomendação do Guia de Design de Aplicativos de Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta à personalização do usuário no Painel de Controle.

|Item|Valor COR do Windows|RGB padrão|
|----------|-------------------------|-----------------|
|Fundo da barra de status|Color_btnface|RGB (192, 192, 192)|
|Texto da barra de status|COLOR_BTNTEXT|RGB (000, 000,000)|
|Bordas superior/esquerda da barra de status|COLOR_BTNHIGHLIGHT|RGB (255, 255, 255)|
|Bot/bordas direitas da barra de status|COLOR_BTNSHADOW|RGB (128, 128, 128)|

**Suporte ccmdui para CStatusBar**

A forma como os indicadores são normalmente atualizados é através do mecanismo ON_UPDATE_COMMAND_UI. No tempo ocioso, a barra de status chamará o manipulador de ON_UPDATE_COMMAND_UI com o ID de seqüência de string do painel indicador.

O manipulador de ON_UPDATE_COMMAND_UI pode ligar:

- `Enable`: Para ativar ou desativar o painel. Um painel desativado se parece exatamente com um painel habilitado, mas o texto é invisível (ou seja, desliga o indicador de texto).

- `SetText`: Alterar o texto. Tenha cuidado se você usar isso porque o painel não será redimensionado automaticamente.

Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) na Referência `CStatusBar` da Biblioteca de *Classe* para obter detalhes sobre APIs de criação e personalização. A maior parte da personalização das barras de status deve ser feita antes que a barra de status seja inicialmente visível.

A barra de status suporta apenas um painel elástico, geralmente o primeiro painel. O tamanho desse painel é realmente um tamanho mínimo. Se a barra de status for maior que o tamanho mínimo de todos os painéis, qualquer largura extra será dada ao painel elástico. O aplicativo padrão com uma barra de status tem indicadores alinhados à direita para CAP, NUM e SCRL, uma vez que o primeiro painel é elástico.

## <a name="ctoolbar"></a><a name="_mfcnotes_ctoolbar"></a>Ctoolbar

Uma barra de ferramentas é uma barra de controle com uma linha de botões bitmap que podem incluir separadores. Dois estilos de botões são suportados: botões e botões de caixa de seleção. A funcionalidade do grupo de rádio pode ser construída com botões de caixa de seleção e ON_UPDATE_COMMAND_UI.

Todos os botões de bitmap na barra de ferramentas são retirados de um bitmap. Este bitmap deve conter uma imagem ou glifo para cada botão. Normalmente, a ordem das imagens/glifos no bitmap é a mesma ordem que serão desenhadas na tela. (Isso pode ser alterado usando as APIs de personalização.)

Cada botão deve ter o mesmo tamanho. O padrão é o padrão de 24x22 pixels. Cada imagem/glifo deve ter o mesmo tamanho e deve estar lado a lado no bitmap. O tamanho padrão da imagem/glifo é de 16x15 pixels. Portanto, para uma barra de ferramentas com 10 botões (usando tamanhos padrão), você precisa de um bitmap de 160 pixels de largura e 15 pixels de altura.

Cada botão tem uma imagem/glifo. Os diferentes estados e estilos de botões (por exemplo, pressionados, para cima, para baixo, desativados, desativados, indeterminados) são gerados algoritmicamente a partir dessa imagem/glifo. Qualquer bitmap de cor ou DIB pode ser usado em teoria. O algoritmo para gerar os diferentes estados de botão funciona melhor se a imagem original for de tons de cinza. Veja os botões padrão da barra de ferramentas e o clipart do botão da barra de ferramentas fornecido no MFC General sample [CLIPART,](../overview/visual-cpp-samples.md) por exemplo.

As cores usadas na barra de ferramentas também são consistentes com a recomendação do Guia de Design de Aplicativos de Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta à personalização do usuário no Painel de Controle.

|Item|Valor COR do Windows|RGB padrão|
|----------|-------------------------|-----------------|
|Fundo da Barra de Ferramentas|Color_btnface|RGB(192.192.192)|
|Botões da barra de ferramentas bordas superior/esquerda|COLOR_BTNHIGHLIGHT|RGB (255.255.255)|
|Botões da Barra de Ferramentas bot/bordas direitas|COLOR_BTNSHADOW|RGB (128.128.128)|

Além disso, os botões de bitmap da barra de ferramentas são recoloridos como se fossem controles padrão de botões do Windows. Essa recoloração ocorre quando o bitmap é carregado a partir do recurso e em resposta a uma alteração nas cores do sistema em resposta à personalização do usuário no Painel de Controle. As seguintes cores em um bitmap da barra de ferramentas serão recoloridas automaticamente, de modo que devem ser usadas com cautela. Se você não deseja ter uma parte do bitmap recolorida, use uma cor que se aproxime de um dos valores RGB mapeados. O mapeamento é feito com base em valores exatos de RGB.

|Valor RGB|Valor COR mapeado dinamicamente|
|---------------|------------------------------------|
|RGB (000, 000,000)|COLOR_BTNTEXT|
|RGB (128, 128, 128)|COLOR_BTNSHADOW|
|RGB (192, 192, 192)|Color_btnface|
|RGB (255, 255, 255)|COLOR_BTNHIGHLIGHT|

Consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md) the Class `CToolBar` Library *Reference* para obter detalhes sobre as APIs de criação e personalização. A maior parte da personalização das barras de ferramentas deve ser feita antes que a barra de ferramentas seja inicialmente visível.

As APIs de personalização podem ser usadas para ajustar os IDs do botão, estilos, largura do espaçador e qual imagem/glifo é usado para qual botão. Por padrão, você não precisa usar essas APIs.

## <a name="ccmdui-support-for-ctoolbar"></a>Suporte ccmdui para ctoolbar

A forma como os botões da barra de ferramentas são sempre atualizados é através do mecanismo ON_UPDATE_COMMAND_UI. Em tempo ocioso, a barra de ferramentas chamará o manipulador ON_UPDATE_COMMAND_UI com o ID de comando desse botão. ON_UPDATE_COMMAND_UI não é chamado para separadores, mas é chamado para botões de botão e caixa de seleção.

O manipulador de ON_UPDATE_COMMAND_UI pode ligar:

- `Enable`: Para ativar ou desativar o botão. Isso funciona igualmente para botões e botões de caixa de seleção.

- `SetCheck`: Para definir o estado de verificação de um botão. Chamar isso para um botão de barra de ferramentas irá transformá-lo em um botão de caixa de seleção. `SetCheck`leva um parâmetro que pode ser 0 (não verificado), 1 (verificado) ou 2 (indeterminado)

- `SetRadio`: Taquigrafia para `SetCheck`.

Os botões da caixa de seleção são botões de caixa de seleção "AUTO"; ou seja, quando o usuário pressiona-los, eles mudarão imediatamente de estado. Verificado é o estado de baixa ou depressão. Não há uma maneira incorporada de interface de usuário para alterar um botão no estado "indeterminado"; que deve ser feito através de código.

As APIs de personalização permitirão que você altere o estado de um determinado botão de barra de ferramentas, de preferência você deve alterar esses estados no manipulador de ON_UPDATE_COMMAND_UI para o comando que o botão da barra de ferramentas representa. Lembre-se, o processamento ocioso mudará o estado dos botões da barra de ferramentas com o manipulador de ON_UPDATE_COMMAND_UI, de modo que quaisquer alterações nesses estados feitas através do SetButtonStyle podem se perder após o próximo ocioso.

Os botões da barra de ferramentas enviarão mensagens WM_COMMAND como botões normais ou itens de menu e normalmente são manuseados por um manipulador de ON_COMMAND na mesma classe que fornece o manipulador ON_UPDATE_COMMAND_UI.

Existem quatro estilos de botão de barra de ferramentas (valores TBBS_) usados para estados de exibição:

- TBBS_CHECKED: A caixa de seleção está verificada no momento (para baixo).

- TBBS_INDETERMINATE: A caixa de seleção está atualmente indeterminada.

- TBBS_DISABLED: O botão está atualmente desativado.

- TBBS_PRESSED: O botão está pressionado no momento.

Os seis estilos oficiais do guia de design de aplicativos do Windows Interface são representados pelos seguintes valores do TBBS:

- Para cima = 0

- Mouse Down = TBBS_PRESSED (&#124; qualquer outro estilo)

- Deficiente = TBBS_DISABLED

- Para baixo = TBBS_CHECKED

- Down Disabled = TBBS_CHECKED &#124; TBBS_DISABLED

- Indeterminado = TBBS_INDETERMINATE

## <a name="cdialogbar"></a><a name="_mfcnotes_cdialogbar"></a>Cdialogbar

Uma barra de diálogo é uma barra de controle que contém controles padrão do Windows. Ele age como um diálogo na forma em que contém os controles e suporta a tabulação entre eles. Ele também age como um diálogo na forma em que usa um modelo de diálogo para representar a barra.

A `CDialogBar` é usado para a barra de ferramentas de visualização de impressão, que contém controles padrão de botão.

Usar `CDialogBar` um é `CFormView`como usar um . Você deve definir um modelo de diálogo para a barra de diálogo e remover todos os estilos, exceto WS_CHILD. Observe que a caixa de diálogo não deve ser visível.

As notificações `CDialogBar` de controle para um serão enviadas ao pai da barra de controle (assim como botões de barra de ferramentas).

## <a name="ccmdui-support-for-cdialogbar"></a>Suporte ccmdui para cdialogbar

Os botões da barra de diálogo devem ser atualizados através do mecanismo de ON_UPDATE_COMMAND_UI manipulador. No momento ocioso, a barra de diálogo chamará o manipulador de ON_UPDATE_COMMAND_UI com o ID de comando de todos os botões que possuem um ID >= 0x8000 (ou seja, na gama de IDs de comando).

O manipulador de ON_UPDATE_COMMAND_UI pode ligar:

- Habilite: para ativar ou desativar o botão.

- SetText: para alterar o texto do botão.

A personalização pode ser feita através de APIs padrão do gerenciador de janelas.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
