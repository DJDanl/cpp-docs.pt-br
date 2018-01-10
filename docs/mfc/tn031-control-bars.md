---
title: 'TN031: Barras de controle | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.controls.bars
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9e4ea57f77c615ba439f2d07c3926cde5efa0c27
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn031-control-bars"></a>TN031: barras de controle
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve as classes da barra de controle no MFC: geral [CControlBar](#_mfcnotes_ccontrolbar), [CStatusBar](#_mfcnotes_cstatusbar), [CToolBar](#_mfcnotes_ctoolbar), [CDialogBar](#_mfcnotes_cdialogbar)e  **CDockBar**.  
  
## <a name="_mfcnotes_ccontrolbar"></a>CControlBar 
  
 Um **ControlBar** é um `CWnd`-derivado de classe que:  
  
-   Será alinhado à parte superior ou inferior de uma janela do quadro.  
  
-   Pode conter itens filho ou controles baseados em HWND (por exemplo, `CDialogBar`) ou não-`HWND` com base em itens (por exemplo, `CToolBar`, `CStatusBar`).  
  
 Barras de controle suportam os estilos adicionais:  
  
- `CBRS_TOP`(O padrão) fixar a barra de controle na parte superior.  
  
- `CBRS_BOTTOM`Fixe a barra de controle na parte inferior.  
  
- `CBRS_NOALIGN`Reposiciona a barra de controle quando o pai for redimensionado.  
  
 Classes derivadas de `CControlBar` fornecer implementações mais interessantes:  
  
- `CStatusBar`Uma barra de status, os itens são painéis da barra de status que contém texto.  
  
- `CToolBar`Uma barra de ferramentas, os itens são alinhados em uma linha de botões de bitmap.  
  
- `CDialogBar`Um quadro de como a barra de ferramentas que contém o padrão do windows controles (criados a partir de um recurso de modelo de caixa de diálogo).  
  
- **CDockBar** um generalizado de área de encaixe para outros `CControlBar` objetos derivados. As funções de membro específico e variáveis disponíveis nesta classe são provavelmente mudar em versões futuras.  
  
 Barra de controle todos os objetos/windows será janelas filho de uma janela do quadro pai. Geralmente, eles são adicionados como um irmão à área de cliente do quadro (por exemplo, um cliente MDI ou exibição). A ID de janela filho de uma barra de controle é importante. O layout padrão de barra de controle só funciona para as barras de controle com IDs no intervalo de **AFX_IDW_CONTROLBAR_FIRST** para **AFX_IDW_CONTROLBAR_LAST**. Observe que, embora não exista um intervalo de 256 controle barra IDs, as primeiras 32 dessas barras de controle IDs são especiais porque são diretamente compatíveis com a arquitetura de visualização de impressão.  
  
 O `CControlBar` classe fornece uma implementação padrão para:  
  
-   Alinhando a barra de controle para a parte superior, inferior ou ambos os lados do quadro.  
  
-   Alocar matrizes de item de controle.  
  
-   A implementação de classes derivadas de suporte.  
  
 Objetos de barra de controle de C++ geralmente serão inseridos como membros de um `CFrameWnd` classe derivada e será limpo quando o pai `HWND` e objeto são destruídos. Se você precisar alocar um objeto da barra de controle na pilha, você pode simplesmente definir o **m_bAutoDestruct** membro **TRUE** para tornar a barra de controle "**excluir este**" quando o `HWND` é destruído.  
  
> [!NOTE]
>  Se você criar seu próprio `CControlBar`-a classe derivada, em vez de usando um do MFC classes derivadas, como `CStatusBar`, `CToolBar`, ou `CDialogBar`, você precisará definir o `m_dwStyle` membro de dados. Isso pode ser feito na substituição do **criar**:  
  
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
  
 O algoritmo de layout da barra de controle é muito simple. A janela do quadro envia uma mensagem **WM_SIZEPARENT** para todos os filhos do intervalo da barra de controle. Junto com esta mensagem é passado a um ponteiro para o retângulo de cliente do pai. Esta mensagem é enviada aos filhos na ordem Z. Os filhos de barra de controle usam essas informações para se posicionar e diminuir o tamanho da área do cliente do pai. O retângulo final que está à esquerda para a área cliente normal (menos barras de controle) é usado para posicionar a janela principal do cliente (geralmente um cliente, a exibição ou divisor janela MDI).  
  
 Consulte `CWnd::RepositionBars` e `CFrameWnd::RecalcLayout` para obter mais detalhes.  
  
 Privada mensagens do Windows MFC, incluindo **WM_SIZEPARENT**, estão documentados em [24 de observação técnica](../mfc/tn024-mfc-defined-messages-and-resources.md).  
  
## <a name="_mfcnotes_cstatusbar"></a>CStatusBar  
  
 Uma barra de status é uma barra de controle que tem uma linha de texto de painéis de saída. Há duas maneiras de usar os painéis de saída de texto:  
  
-   Como uma linha de mensagem  
  
     (por exemplo, o menu padrão ajuda a linha de mensagem). Eles normalmente são acessados por um indexada baseado em 0  
  
-   Como os indicadores de status  
  
     (por exemplo, os limite, NUM e SCRL indicadores). Esses são normalmente acessados por ID de cadeia de caracteres/comando.  
  
 A fonte para a barra de status é o ponto de 10 MS Sans Serif (determinado pelo guia de Design de aplicativo de Interface do Windows ou a fonte mapeadores melhor correspondência de uma fonte de proporcional 10 pontos na Suíça). Em determinadas versões do Windows, como a edição em japonês, as fontes selecionadas são diferentes.  
  
 As cores usadas na barra de status também são consistentes com a recomendação do guia de Design de aplicativo de Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta a personalização de usuário no painel de controle.  
  
|Item|Valor de cor do Windows|Padrão RGB|  
|----------|-------------------------|-----------------|  
|Plano de fundo de barra de status|**COLOR_BTNFACE**|RGB (192, 192 192.)|  
|Texto da barra de status|**COLOR_BTNTEXT**|RGB (000, 000 000.)|  
|Status da barra superior/esquerdo bordas|**COLOR_BTNHIGHLIGHT**|RGB (255, 255, 255)|  
|Barra bordas bot/direito de status|**COLOR_BTNSHADOW**|RGB (128, 128, 128)|  
  
 **Suporte a CCmdUI CStatusBar**  
  
 É a maneira como os indicadores geralmente são atualizados por meio de `ON_UPDATE_COMMAND_UI` mecanismo. No tempo ocioso, a barra de status chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de cadeia de caracteres do painel do indicador.  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
- **Habilitar**: para ativar ou desativar o painel. Um painel desabilitado parece exatamente um painel habilitado, mas o texto está invisível (ou seja, desativa o indicador de texto).  
  
- **SetText**: para alterar o texto. Tenha cuidado ao usar isso como o painel não será redimensionado automaticamente.  
  
 Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) no *referência da biblioteca de classe* para obter detalhes sobre `CStatusBar` criação e personalização de APIs. A maioria dos personalização das barras de status deve ser feita antes que a barra de status inicialmente ficam visível.  
  
 A barra de status oferece suporte a somente um painel alongado, normalmente o primeiro painel. O tamanho do painel é realmente um tamanho mínimo. Se a barra de status é maior do que o tamanho mínimo de todos os painéis, qualquer largura extra terá ao painel alongado. O aplicativo padrão com uma barra de status tem indicadores alinhado à direita para CAP, NUM e SCRL como o primeiro painel é alongado.  
  
## <a name="_mfcnotes_ctoolbar"></a>CToolBar  
  
 Uma barra de ferramentas é uma barra de controle com uma linha de botões de bitmap que podem incluir separadores. Há suporte para dois estilos de botões: pushbuttons e botões da caixa de seleção. Funcionalidade de grupo de opção pode ser criada com os botões da caixa de seleção e `ON_UPDATE_COMMAND_UI`.  
  
 Todos os botões na barra de ferramentas de bitmap são obtidos de um bitmap. Este bitmap deve conter uma imagem ou glifo para cada botão. Normalmente, a ordem de imagens/glifos no bitmap é a mesma ordem que serão desenhadas na tela. (Isso pode ser alterado usando a APIs de personalização.)  
  
 Cada botão deve ser do mesmo tamanho. O padrão é 22 x 24 pixels padrão. Cada imagem/glifo deve ter o mesmo tamanho e deve ser o lado a lado no bitmap. O tamanho da imagem/glifo padrão é 15, 16 pixels. Portanto, para uma barra de ferramentas com 10 botões (usando tamanhos padrão), é necessário um bitmap que é 160 pixels de largura e 15 pixels de altura.  
  
 Cada botão tem somente uma imagem/glifo. O botão diferente estados e estilos (por exemplo, pressionado, para cima, para baixo, desabilitado, desabilitado para baixo, indeterminado) maneira algorítmica gerados a partir de que um imagem/glifo. Qualquer bitmap de cor ou DIB pode ser usado em teoria. O algoritmo para gerar o botão diferente estados funciona melhor se a imagem original for tons de cinza. Examinar os botões da barra de ferramentas padrão e o botão de barra de ferramentas clip-art fornecido no exemplo de MFC geral [clip-art](../visual-cpp-samples.md) para obter exemplos.  
  
 As cores usadas na barra de ferramentas também são consistentes com a recomendação do guia de Design de aplicativo de Interface do Windows. Essas cores não são codificadas e são alteradas dinamicamente em resposta a personalização de usuário no painel de controle.  
  
|Item|Valor de cor do Windows|Padrão RGB|  
|----------|-------------------------|-----------------|  
|Plano de fundo da barra de ferramentas|**COLOR_BTNFACE**|RGB(192,192,192)|  
|Botões de barra de ferramentas bordas superior/esquerdo|**COLOR_BTNHIGHLIGHT**|RGB(255,255,255)|  
|Botões de barra de ferramentas bordas bot ou para a direita|**COLOR_BTNSHADOW**|RGB(128,128,128)|  
  
 Além disso, os botões de barra de ferramentas de bitmap são recoloridos como se fossem controles de botão padrão do Windows. Este recolorindo ocorre quando o bitmap é carregado do recurso e, em resposta a uma alteração de cores do sistema em resposta a personalização de usuário no painel de controle. As seguintes cores em um bitmap de barra de ferramentas serão recoloridas automaticamente para que eles devem ser usados com cuidado. Se não desejar que uma parte de seu bitmap recolorido, em seguida, use uma cor que aproxime mais um dos valores RGB mapeados. O mapeamento é feito com base nos valores RGB exatos.  
  
|Valor RGB|Valor de cor mapeado dinamicamente|  
|---------------|------------------------------------|  
|RGB (000, 000 000.)|COLOR_BTNTEXT|  
|RGB (128, 128, 128)|COLOR_BTNSHADOW|  
|RGB (192, 192 192.)|COLOR_BTNFACE|  
|RGB (255, 255, 255)|COLOR_BTNHIGHLIGHT|  
  
 Consulte a classe [CToolBar](../mfc/reference/ctoolbar-class.md) o *referência da biblioteca de classe* para obter detalhes sobre o `CToolBar` criação e personalização de APIs. A maioria dos personalização das barras de ferramentas deve ser feita antes que a barra de ferramentas inicialmente ficam visível.  
  
 A personalização APIs podem ser usados para ajustar o botão IDs, estilos, largura de espaçador e qual imagem/glifo é usado para o botão. Por padrão, não é necessário usar essas APIs.  
  
## <a name="ccmdui-support-for-ctoolbar"></a>Suporte a CCmdUI CToolBar  
 É a maneira como os botões da barra de ferramentas sempre são atualizadas por meio de `ON_UPDATE_COMMAND_UI` mecanismo. No tempo ocioso, a barra de ferramentas chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de comando do botão. `ON_UPDATE_COMMAND_UI`não é chamado para separadores, mas ele é chamado para pushbuttons e botões de caixa de seleção.  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
- **Habilitar**: para habilitar ou desabilitar o botão. Isso funciona para pushbuttons e botões de caixa de seleção.  
  
- `SetCheck`: Para definir o estado de seleção de um botão. Chamar isso para um botão de barra de ferramentas, ela se transformará em um botão de caixa de seleção. `SetCheck`usa um parâmetro que pode ser 0 (não verificado), 1 (marcado) ou 2 (desativada)  
  
- `SetRadio`: Abreviação para `SetCheck`.  
  
 Caixa de seleção botões é "AUTO" caixa de seleção; ou seja, quando o usuário pressiona-las imediatamente será alterado estado. Check é o estado pressionado ou para baixo. Não há nenhuma maneira de interface de usuário internas para alterar um botão no estado "indeterminado"; que deve ser feito por meio de código.  
  
 A personalização APIs permitirá que você alterar o estado de um botão de barra de ferramentas determinado, preferencialmente, você deve alterar esses estados de `ON_UPDATE_COMMAND_UI` manipulador para o comando que representa o botão de barra de ferramentas. Lembre-se de que o processamento ocioso alterará o estado dos botões de barra de ferramentas com o `ON_UPDATE_COMMAND_UI` manipulador, para que as alterações para esses estados feitas por meio de SetButtonStyle podem ser perdidas após o próximo ocioso.  
  
 Botões da barra de ferramentas enviará **WM_COMMAND** mensagens como botões normal ou itens de menu e normalmente são tratadas por um `ON_COMMAND` manipulador na mesma classe que fornece o `ON_UPDATE_COMMAND_UI` manipulador.  
  
 Há quatro ferramentas botão estilos (valores TBBS_) usados para estados de exibição:  
  
-   TBBS_CHECKED: caixa de seleção é marcada no momento (baixo).  
  
-   TBBS_INDETERMINATE: caixa de seleção está desativada no momento.  
  
-   TBBS_DISABLED: Botão está desabilitado no momento.  
  
-   TBBS_PRESSED: Botão é pressionado no momento.  
  
 Os estilos de botão de guia de Design de aplicativo de Interface do Windows oficiais seis são representados por valores TBBS:  
  
-   Até = 0  
  
-   Mouse para baixo = TBBS_PRESSED (&#124; qualquer outro estilo)  
  
-   Desabilitado = TBBS_DISABLED  
  
-   Para baixo = TBBS_CHECKED  
  
-   Para baixo desabilitado = TBBS_CHECKED &#124; TBBS_DISABLED  
  
-   Indeterminado = TBBS_INDETERMINATE  
  
##  <a name="_mfcnotes_cdialogbar"></a>CDialogBar  
 Uma barra da caixa de diálogo é uma barra de controle que contém controles padrão do Windows. Ele atua como uma caixa de diálogo que contém os controles e dá suporte a tabulação entre eles. Ele também atua como uma caixa de diálogo em que ele usa um modelo de caixa de diálogo para representar a barra.  
  
 Um `CDialogBar` é usado para a barra de ferramentas de visualização de impressão, que contém os controles de botão de pressão padrão.  
  
 Usando um `CDialogBar` é como usar um `CFormView`. Você deve definir um modelo de caixa de diálogo para a barra da caixa de diálogo e remover todos os estilos exceto **WS_CHILD**. Observe que a caixa de diálogo não deve ser visível.  
  
 As notificações de controle para um `CDialogBar` será enviado para o pai da barra de controle (assim como botões da barra de ferramentas).  
  
## <a name="ccmdui-support-for-cdialogbar"></a>Suporte a CCmdUI CDialogBar  
 Botões da barra de caixa de diálogo devem ser atualizada por meio de `ON_UPDATE_COMMAND_UI` mecanismo do manipulador. No tempo ocioso, a barra da caixa de diálogo chamará o `ON_UPDATE_COMMAND_UI` manipulador com a ID de comando de todos os botões que têm uma ID > 0x8000 (isto é, no intervalo de IDs de comando).  
  
 O `ON_UPDATE_COMMAND_UI` manipulador pode chamar:  
  
-   Habilitar: para habilitar ou desabilitar o botão.  
  
-   SetText: para alterar o texto do botão.  
  
 Personalização pode ser feita por meio de APIs do Gerenciador de janela padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

