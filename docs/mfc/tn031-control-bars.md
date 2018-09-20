---
title: 'TN031: Barras de controle | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.controls.bars
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 412dd9e0a4e81ee6152197634205401cbe71df2e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390604"
---
# <a name="tn031-control-bars"></a>TN031: barras de controle

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve as classes da barra de controle no MFC: gerais [CControlBar](#_mfcnotes_ccontrolbar), [CStatusBar](#_mfcnotes_cstatusbar), [CToolBar](#_mfcnotes_ctoolbar), [CDialogBar](#_mfcnotes_cdialogbar)e `CDockBar`.

## <a name="_mfcnotes_ccontrolbar"></a> CControlBar

Um `ControlBar` é um `CWnd`-derivadas de classes que:

- É alinhado à parte superior ou inferior de uma janela de quadro.

- Pode conter itens filhos que estão a qualquer um dos controles baseados em HWND (por exemplo, `CDialogBar`) ou não-`HWND` com base em itens (por exemplo, `CToolBar`, `CStatusBar`).

Barras de controle dão suporte os estilos adicionais:

- A barra de controle na parte superior de pin CBRS_TOP (o padrão).

- Pin CBRS_BOTTOM a barra de controle na parte inferior.

- Não fazer CBRS_NOALIGN reposicionar a barra de controle quando o pai for redimensionado.

As classes derivadas de `CControlBar` fornecem implementações mais interessantes:

- `CStatusBar` Uma barra de status, os itens são painéis da barra de status que contém texto.

- `CToolBar` Uma barra de ferramentas, os itens são alinhados em uma linha de botões de bitmap.

- `CDialogBar` Um quadro de barra de ferramentas semelhantes que contém o padrão do windows controles (criados de um recurso de modelo de caixa de diálogo).

- `CDockBar` Um generalizado de área de encaixe para outros `CControlBar` objetos derivados. As funções de membro específico e variáveis disponíveis nesta classe são provavelmente mudar em versões futuras.

Barra de controle todos os objetos de/windows será janelas filho de uma janela de quadro do pai. Geralmente, eles são adicionados como um irmão à área de cliente do quadro (por exemplo, um cliente do MDI ou exibição). A ID de janela filho de uma barra de controle é importante. O layout padrão da barra de controle funciona somente para as barras de controle com as IDs no intervalo de AFX_IDW_CONTROLBAR_FIRST para AFX_IDW_CONTROLBAR_LAST. Observe que, mesmo que haja uma variedade de 256 controles de barra IDs, as primeiras 32 esses de barra de controle IDs são especiais, pois são diretamente compatíveis com a arquitetura de visualização de impressão.

O `CControlBar` aula oferece a implementação padrão para:

- Alinhando a barra de controle para a parte superior, inferior ou ambos os lados do quadro.

- Alocar matrizes de item de controle.

- A implementação de classes derivadas de suporte.

Objetos de barra de controle do C++ geralmente serão inseridos como membros de um `CFrameWnd` classe derivada e serão limpos quando o pai `HWND` e objeto são destruídos. Se você precisar alocar um objeto da barra de controle no heap, você pode simplesmente definir a *m_bAutoDestruct* membro **verdadeiro** para deixar a barra de controle "**excluir este**" quando o `HWND` é destruído.

> [!NOTE]
>  Se você criar seu próprio `CControlBar`-derivado de classe, em vez de usar um do MFC classes derivadas, como `CStatusBar`, `CToolBar`, ou `CDialogBar`, você precisará definir o *m_dwStyle* membro de dados. Isso pode ser feito na substituição do `Create`:

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

**Algoritmo de Layout da barra de controle**

O algoritmo de layout da barra de controle é muito simple. A janela do quadro envia uma mensagem WM_SIZEPARENT para todos os filhos do intervalo da barra de controle. Junto com esta mensagem, um ponteiro para o retângulo do cliente do pai é passado. Esta mensagem é enviada aos filhos na ordem Z. Os filhos de barra de controle usam essas informações para se posicionar e diminuir o tamanho da área de cliente do pai. O retângulo final que é deixado para a área de cliente normal (menos barras de controle) é usado para posicionar a janela principal do cliente (normalmente, um cliente, exibição ou divisor janela MDI).

Ver `CWnd::RepositionBars` e `CFrameWnd::RecalcLayout` para obter mais detalhes.

MFC privada Windows mensagens, incluindo WM_SIZEPARENT, estão documentadas em [24 de observação técnica](../mfc/tn024-mfc-defined-messages-and-resources.md).

## <a name="_mfcnotes_cstatusbar"></a>  CStatusBar

Uma barra de status é uma barra de controle que tem uma linha de painéis de saída de texto. Há duas maneiras comuns de usar os painéis de saída de texto:

- Como uma linha de mensagem

     (por exemplo, menu padrão ajuda a linha de mensagem). Eles geralmente são acessados por um indexada baseado em 0

- Como os indicadores de status

     (por exemplo, os limite, NUM e SCRL indicadores). Eles normalmente são acessados pelo ID de cadeia de caracteres/comando.

A fonte para a barra de status é o ponto de 10 MS Sans Serif (determinado pelo guia de Design do aplicativo de Interface do Windows ou a fonte mapeadores melhor correspondência de uma fonte de proporcional Suíça 10 pontos). Em determinadas versões do Windows, como a edição de japonês, as fontes selecionadas são diferentes.

As cores usadas na barra de status também são consistentes com a recomendação do guia de Design do aplicativo de Interface do Windows. Essas cores não são codificados e são alterados dinamicamente em resposta a personalização de usuário no painel de controle.

|Item|Valor de cor do Windows|Padrão RGB|
|----------|-------------------------|-----------------|
|Plano de fundo de barra de status|COLOR_BTNFACE|RGB (192, 192, 192)|
|Texto da barra de status|COLOR_BTNTEXT|RGB (000 000, 000)|
|Status da barra superior/esquerdo bordas|COLOR_BTNHIGHLIGHT|RGB (255, 255, 255)|
|Barra bordas direita/bot de status|COLOR_BTNSHADOW|RGB (128, 128, 128)|

**Suporte a CCmdUI CStatusBar**

A maneira indicadores geralmente são atualizados é por meio do mecanismo ON_UPDATE_COMMAND_UI. No tempo ocioso, a barra de status chamará o manipulador ON_UPDATE_COMMAND_UI com a ID de cadeia de caracteres do painel do indicador.

O manipulador ON_UPDATE_COMMAND_UI pode chamar:

- `Enable`: Para habilitar ou desabilitar o painel. Um painel desabilitado parece exatamente em um painel de habilitado, mas o texto é invisível (ou seja, desativa o indicador de texto).

- `SetText`: Para alterar o texto. Tenha cuidado se você usar isso, pois o painel não será redimensionado automaticamente.

Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) na *referência da biblioteca de classe* para obter detalhes sobre `CStatusBar` criação e personalização de APIs. A maioria dos personalização das barras de status deve ser feita antes que a barra de status inicialmente fica visível.

A barra de status dá suporte a apenas um único painel alongado, normalmente, o primeiro painel. O tamanho do painel é realmente um tamanho mínimo. Se a barra de status é maior do que o tamanho mínimo de todos os painéis, qualquer largura extra terá ao painel alongado. O aplicativo padrão com uma barra de status possui indicadores de alinhado à direita para CAP, NUM e SCRL como o primeiro painel é alongado.

## <a name="_mfcnotes_ctoolbar"></a>  CToolBar

Uma barra de ferramentas é uma barra de controle com uma linha de botões de bitmap que podem incluir separadores. Há suporte para dois estilos de botões: comportarem e botões de caixa de seleção. Funcionalidade de grupo de opção pode ser criada com os botões de caixa de seleção e ON_UPDATE_COMMAND_UI.

Todos os botões de bitmap na barra de ferramentas são obtidos de um bitmap. Esse bitmap deve conter uma imagem ou glifo para cada botão. Normalmente, a ordem de glifos/imagens no bitmap é a mesma ordem em que eles serão desenhados na tela. (Isso pode ser alterado usando a APIs de personalização.)

Cada botão deve ser do mesmo tamanho. O padrão é os padrão 24 x 22 pixels. Cada imagem/glifo deve ser do mesmo tamanho e deve ser o lado a lado no bitmap. O tamanho de imagem/glifos padrão é 16 x 15 pixels. Portanto, para uma barra de ferramentas com 10 botões (usando os tamanhos padrão), você precisa de um bitmap que é de 160 pixels de largura e 15 pixels de altura.

Cada botão tem uma e apenas uma imagem/glifo. O botão diferente estados e estilos (por exemplo, pressionado, para cima, para baixo, desabilitado, desabilitado para baixo, indeterminado) algoritmicamente gerados a partir de que uma imagem/glifos. Qualquer bitmap colorido ou DIB pode ser usado na teoria. O algoritmo para gerar o botão diferente estados funciona melhor se a imagem original é tons de cinza. Examinar os botões de barra de ferramentas padrão e o botão de barra de ferramentas clip-art fornecido no exemplo de MFC geral [clip-art](../visual-cpp-samples.md) para obter exemplos.

As cores usadas na barra de ferramentas também são consistentes com a recomendação do guia de Design do aplicativo de Interface do Windows. Essas cores não são codificados e são alterados dinamicamente em resposta a personalização de usuário no painel de controle.

|Item|Valor de cor do Windows|Padrão RGB|
|----------|-------------------------|-----------------|
|Plano de fundo da barra de ferramentas|COLOR_BTNFACE|RGB(192,192,192)|
|Botões de barra de ferramentas bordas superior/esquerdo|COLOR_BTNHIGHLIGHT|RGB(255,255,255)|
|Botões de barra de ferramentas bordas do bot/direito|COLOR_BTNSHADOW|RGB(128,128,128)|

Além disso, os botões de bitmap de barra de ferramentas são recoloridos como se fossem controles de botão do Windows padrão. Essa nova coloração ocorre quando o bitmap é carregado do recurso e, em resposta a uma alteração nas cores do sistema em resposta a personalização de usuário no painel de controle. As seguintes cores em um bitmap da barra de ferramentas serão Recolorir automaticamente para que eles devem ser usados com cuidado. Se você não quiser ter uma parte de seu bitmap recolorido, em seguida, use uma cor que se aproxima um dos valores de RGB mapeados. O mapeamento é feito com base em valores RGB exatos.

|Valor RGB|Valor de cor mapeado dinamicamente|
|---------------|------------------------------------|
|RGB (000 000, 000)|COLOR_BTNTEXT|
|RGB (128, 128, 128)|COLOR_BTNSHADOW|
|RGB (192, 192, 192)|COLOR_BTNFACE|
|RGB (255, 255, 255)|COLOR_BTNHIGHLIGHT|

Consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md) o *referência da biblioteca de classe* para obter detalhes sobre o `CToolBar` criação e personalização de APIs. A maioria dos personalização das barras de ferramentas deve ser feita antes que a barra de ferramentas inicialmente fica visível.

A personalização de APIs que podem ser usadas para ajustar o botão de IDs, estilos, largura de espaçador e qual imagem/glifo é usado para o botão. Por padrão, não é necessário usar essas APIs.

## <a name="ccmdui-support-for-ctoolbar"></a>Suporte a CCmdUI CToolBar

É a maneira como os botões da barra de ferramentas de serão sempre atualizadas por meio do mecanismo ON_UPDATE_COMMAND_UI. No tempo ocioso, a barra de ferramentas chamará o manipulador ON_UPDATE_COMMAND_UI com a ID de comando do botão. ON_UPDATE_COMMAND_UI não é chamado para separadores, mas ele é chamado para comportarem e botões de caixa de seleção.

O manipulador ON_UPDATE_COMMAND_UI pode chamar:

- `Enable`: Para habilitar ou desabilitar o botão. Isso funciona igualmente para comportarem e botões de caixa de seleção.

- `SetCheck`: Para definir o estado de seleção de um botão. Chamar isso de um botão de barra de ferramentas, ela se transformará em um botão da caixa de seleção. `SetCheck` usa um parâmetro que pode ser 0 (não marcado), 1 (marcado) ou 2 (indeterminado)

- `SetRadio`: Uma abreviação para `SetCheck`.

Botões de caixa de seleção são botões de caixa de seleção "AUTO"; ou seja, quando o usuário pressiona-los eles imediatamente estado serão alterado. Verificado é o estado pressionado ou para baixo. Não há nenhuma maneira de interface de usuário internas para alterar um botão no estado "indeterminado"; Isso deve ser feito por meio de código.

A personalização de APIs permitirá que você altere o estado de um botão de barra de ferramentas, preferencialmente, você deve alterar esses estados em que o manipulador ON_UPDATE_COMMAND_UI para o comando que representa o botão de barra de ferramentas. Lembre-se de que o processamento ocioso alterará o estado dos botões da barra de ferramentas com o manipulador ON_UPDATE_COMMAND_UI, portanto, todas as alterações para esses estados feitas por meio de SetButtonStyle podem ser perdidas após o próximo ocioso.

Botões da barra de ferramentas enviará mensagens WM_COMMAND como botões normais ou itens de menu e normalmente são manipuladas por um manipulador ON_COMMAND na mesma classe que fornece o manipulador ON_UPDATE_COMMAND_UI.

Há quatro barra de ferramentas botão estilos (valores TBBS_) usados para os estados de exibição:

- TBBS_CHECKED: caixa de seleção no momento é verificado (para baixo).

- TBBS_INDETERMINATE: caixa de seleção é indeterminado no momento.

- TBBS_DISABLED: Botão está desabilitado no momento.

- TBBS_PRESSED: Botão é pressionado no momento.

Os seis estilos de botão oficiais do guia de Design de aplicativo de Interface do Windows são representados pelos valores TBBS a seguir:

- Até = 0

- Mouse para baixo = TBBS_PRESSED (&#124; qualquer outro estilo)

- Desabilitado = TBBS_DISABLED

- Para baixo = TBBS_CHECKED

- Para baixo desabilitado = TBBS_CHECKED &#124; TBBS_DISABLED

- Indeterminado = TBBS_INDETERMINATE

##  <a name="_mfcnotes_cdialogbar"></a> CDialogBar

Uma barra de diálogo é uma barra de controle que contém os controles padrão do Windows. Ele atua como uma caixa de diálogo que contém os controles e dá suporte ao uso da tecla TAB entre eles. Ele também atua como uma caixa de diálogo que utiliza um modelo de caixa de diálogo para representar a barra.

Um `CDialogBar` é usado para a barra de ferramentas de visualização de impressão, que contém os controles padrão.

Usando um `CDialogBar` é como usar um `CFormView`. Você deve definir um modelo de caixa de diálogo para a barra da caixa de diálogo e remover todos os estilos, exceto WS_CHILD. Observe que a caixa de diálogo não deve estar visível.

As notificações de controle para um `CDialogBar` será enviado para o pai da barra de controle (como botões da barra de ferramentas).

## <a name="ccmdui-support-for-cdialogbar"></a>Suporte a CCmdUI CDialogBar

Botões da barra de diálogo devem ser atualizados por meio do mecanismo de manipulador ON_UPDATE_COMMAND_UI. No tempo ocioso, a barra da caixa de diálogo chamará o manipulador ON_UPDATE_COMMAND_UI com a ID de comando de todos os botões que têm uma ID > 0x8000 (ou seja, no intervalo de IDs de comando).

O manipulador ON_UPDATE_COMMAND_UI pode chamar:

- Habilitar: para habilitar ou desabilitar o botão.

- SetText: para alterar o texto do botão.

Personalização pode ser feita por meio de APIs do Gerenciador de janela padrão.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

