---
title: 'TN021: comando e roteamento de mensagem'
ms.date: 06/28/2018
f1_keywords:
- vc.routing
helpviewer_keywords:
- TN021
- command routing [MFC], technical note TN021
- Windows messages [MFC], routing
ms.assetid: b5952c8b-123e-406c-a36d-a6ac7c6df307
ms.openlocfilehash: bdd405bda5c0af9e04a50eee4ef5738f3a53259e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370403"
---
# <a name="tn021-command-and-message-routing"></a>TN021: comando e roteamento de mensagem

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve a arquitetura de roteamento e despacho de comando, bem como tópicos avançados no roteamento geral de mensagens de janela.

Consulte o Visual C++ para obter detalhes gerais sobre as arquiteturas descritas aqui, especialmente a distinção entre mensagens do Windows, notificações de controle e comandos. Esta nota pressupõe que você esteja muito familiarizado com os problemas descritos na documentação impressa e apenas aborda tópicos muito avançados.

## <a name="command-routing-and-dispatch-mfc-10-functionality-evolves-to-mfc-20-architecture"></a>A funcionalidade de roteamento e despacho de comando MFC 1.0 evolui para a arquitetura MFC 2.0

O Windows tem a mensagem WM_COMMAND que está sobrecarregada para fornecer notificações de comandos de menu, chaves do acelerador e notificações de controle de diálogo.

O MFC 1.0 baseou-se um pouco nisso ao permitir que um `CWnd` manipulador de comando (por exemplo, "OnFileNew") em uma classe derivada seja chamado em resposta a um WM_COMMAND específico. Isso é colado com uma estrutura de dados chamada mapa de mensagem, e resulta em um mecanismo de comando muito eficiente no espaço.

O MFC 1.0 também forneceu funcionalidade adicional para separar notificações de controle de mensagens de comando. Os comandos são representados por um ID de 16 bits, às vezes conhecido como ID de Comando. Os comandos normalmente começam a partir de um `CFrameWnd` (ou seja, um menu selecionado ou um acelerador traduzido) e são roteados para uma variedade de outras janelas.

O MFC 1.0 usou o roteamento de comando em um sentido limitado para a implementação do MDI (Multiple Document Interface). (Um derneta de quadro MDI comanda a janela MDI Child ativa.)

Essa funcionalidade foi generalizada e estendida no MFC 2.0 para permitir que os comandos sejam manuseados por uma gama maior de objetos (não apenas objetos de janela). Ele fornece uma arquitetura mais formal e extensível para roteamento de mensagens e reutiliza o roteamento de destino de comando não apenas para o manuseio de comandos, mas também para atualizar objetos de interface do usuário (como itens de menu e botões de barra de ferramentas) para refletir a disponibilidade atual de um comando.

## <a name="command-ids"></a>IDs de comando

Consulte Visual C++ para obter uma explicação sobre o processo de roteamento e vinculação do comando. [Nota Técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md) contém informações sobre nomeação de ID.

Usamos o prefixo genérico "ID_" para iDs de comando. Os IDs de comando são >= 0x8000. A linha de mensagem ou a barra de status mostrarão a seqüência de descrição de comando se houver um recurso STRINGTABLE com os mesmos IDs do comando ID.

Nos recursos da sua aplicação, um ID de comando pode aparecer em vários lugares:

- Em um recurso STRINGTABLE que tem o mesmo ID do prompt de linha de mensagem.

- Em possivelmente muitos recursos MENU que são anexados a itens de menu que invocam o mesmo comando.

- (ADVANCED) em um botão de diálogo para um comando GOSUB.

No código-fonte do seu aplicativo, um ID de comando pode aparecer em vários lugares:

- Em seu RECURSO. H (ou outro arquivo de cabeçalho de símbolo principal) para definir IDs de comando específicos do aplicativo.

- TALVEZ Em uma matriz de ID usada para criar uma barra de ferramentas.

- Em uma macro ON_COMMAND.

- TALVEZ em uma ON_UPDATE_COMMAND_UI macro.

Atualmente, a única implementação no MFC que requer que os IDs de comando sejam >= 0x8000 é a implementação de diálogos/comandos GOSUB.

## <a name="gosub-commands-using-command-architecture-in-dialogs"></a>Comandos GOSUB, usando arquitetura de comando em diálogos

A arquitetura de comando saqueando comandos funciona bem com janelas de quadro, itens de menu, botões de barra de ferramentas, botões de barra de diálogo, outras barras de controle e outros elementos de interface do usuário projetados para atualizar comandos de demanda e rota ou IDs de controle para um alvo principal de comando (geralmente a janela do quadro principal). Esse alvo principal de comando pode direcionar as notificações de comando ou controle para outros objetos de destino de comando conforme apropriado.

Uma caixa de diálogo (modal ou modeless) pode beneficiar de alguns dos recursos da arquitetura de comando se você atribuir o ID de controle de controle do controle de diálogo ao ID de comando apropriado. O suporte para diálogos não é automático, então você pode ter que escrever algum código adicional.

Observe que para todos esses recursos funcionarem corretamente, seus IDs de comando devem ser >= 0x8000. Uma vez que muitos diálogos podem ser encaminhados para o mesmo quadro, os comandos compartilhados devem ser >= 0x8000, enquanto os IDCs não compartilhados em uma caixa de diálogo específica devem ser <= 0x7FFF.

Você pode colocar um botão normal em uma caixa de diálogo modal normal com o IDC do botão definido para o ID de comando apropriado. Quando o usuário seleciona o botão, o proprietário da caixa de diálogo (geralmente a janela do quadro principal) recebe o comando como qualquer outro comando. Isso é chamado de comando GOSUB, uma vez que geralmente é usado para trazer à tona outro diálogo (um GOSUB do primeiro diálogo).

Você também pode `CWnd::UpdateDialogControls` chamar a função em sua caixa de diálogo e passá-la o endereço da janela principal do quadro. Esta função habilitará ou desativará os controles de diálogo com base em se eles têm manipuladores de comando no quadro. Esta função é chamada automaticamente para você para barras de controle no loop ocioso do aplicativo, mas você deve chamá-la diretamente para diálogos normais que você deseja ter esse recurso.

## <a name="when-on_update_command_ui-is-called"></a>Quando ON_UPDATE_COMMAND_UI é chamado

Manter o estado ativado/verificado de todos os itens de menu de um programa o tempo todo pode ser um problema computacionalmente caro. Uma técnica comum é ativar/verificar itens do menu somente quando o usuário selecionar o POPUP. A implementação do `CFrameWnd` MFC 2.0 lida com a mensagem WM_INITMENUPOPUP e usa a arquitetura de roteamento de comando para determinar os estados dos menus através de manipuladores ON_UPDATE_COMMAND_UI.

`CFrameWnd`também lida com a mensagem WM_ENTERIDLE para descrever o item de menu atual selecionado na barra de status (também conhecida como linha de mensagem).

A estrutura de menu de um aplicativo, editada pelo Visual C++, é usada para representar os potenciais comandos disponíveis em WM_INITMENUPOPUP momento. ON_UPDATE_COMMAND_UI os manipuladores podem modificar o estado ou o texto de um menu, ou para usos avançados (como a lista File MRU ou o menu pop-up OLE Verbs), na verdade modificar a estrutura do menu antes que o menu seja desenhado.

O mesmo tipo de ON_UPDATE_COMMAND_UI processamento é feito para barras de ferramentas (e outras barras de controle) quando o aplicativo entra em seu loop ocioso. Consulte a Referência da *Biblioteca de Classe* e a [Nota Técnica 31](../mfc/tn031-control-bars.md) para obter mais informações sobre as barras de controle.

## <a name="nested-pop-up-menus"></a>Menus pop-up aninhados

Se você estiver usando uma estrutura de menu aninhada, você notará que o manipulador de ON_UPDATE_COMMAND_UI para o primeiro item do menu no menu pop-up é chamado em dois casos diferentes.

Primeiro, é chamado para o próprio menu pop-up. Isso é necessário porque os menus pop-up não possuem IDs e usamos o ID do primeiro item do menu pop-up para consultar todo o menu pop-up. Neste caso, a variável membro `CCmdUI` *m_pSubMenu* do objeto não será NULA e apontará para o menu pop-up.

Em segundo lugar, é chamado pouco antes dos itens do menu pop-up serem sorteados. Neste caso, o ID refere-se apenas ao primeiro item `CCmdUI` do menu e a variável membro *m_pSubMenu* do objeto será NULL.

Isso permite que você habilite o menu pop-up diferente de seus itens de menu, mas requer que você escreva algum código de reconhecimento de menu. Por exemplo, em um menu aninhado com a seguinte estrutura:

```Output
File>
    New>
    Sheet (ID_NEW_SHEET)
    Chart (ID_NEW_CHART)
```

Os comandos ID_NEW_SHEET e ID_NEW_CHART podem ser habilitados ou desativados de forma independente. O **novo** menu pop-up deve ser ativado se qualquer um dos dois estiver habilitado.

O manipulador de comando para ID_NEW_SHEET (o primeiro comando no pop-up) seria algo como:

```cpp
void CMyApp::OnUpdateNewSheet(CCmdUI* pCmdUI)
{
    if (pCmdUI->m_pSubMenu != NULL)
    {
        // enable entire pop-up for "New" sheet and chart
        BOOL bEnable = m_bCanCreateSheet || m_bCanCreateChart;
        // CCmdUI::Enable is a no-op for this case, so we
        // must do what it would have done.
        pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex,
            MF_BYPOSITION |
            (bEnable  MF_ENABLED : (MF_DISABLED | MF_GRAYED)));

        return;
    }
    // otherwise just the New Sheet command
    pCmdUI->Enable(m_bCanCreateSheet);
}
```

O manipulador de comando sinID_NEW_CHART seria um manipulador de comando de atualização normal e se pareceria com:

```cpp
void CMyApp::OnUpdateNewChart(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(m_bCanCreateChart);
}
```

## <a name="on_command-and-on_bn_clicked"></a>ON_COMMAND e ON_BN_CLICKED

As macros do mapa de mensagem para **ON_COMMAND** e **ON_BN_CLICKED** são as mesmas. O mecanismo de roteamento de comando e notificação de controle do MFC só usa o ID de comando para decidir para onde ir. As notificações de controle com código de notificação de controle de**zero (BN_CLICKED)** são interpretadas como comandos.

> [!NOTE]
> Na verdade, todas as mensagens de notificação de controle passam pela cadeia do manipulador de comando. Por exemplo, é tecnicamente possível para você escrever um manipulador de notificação de controle para **EN_CHANGE** em sua classe de documentos. Isso geralmente não é aconselhável porque as aplicações práticas deste recurso são poucas, o recurso não é suportado pelo ClassWizard, e o uso do recurso pode resultar em código frágil.

## <a name="disabling-the-automatic-disabling-of-button-controls"></a>Desabilitando a desativação automática dos controles de botão

Se você colocar um controle de botão em uma barra de diálogo ou em uma caixa de diálogo usando onde você está chamando **CWnd::UpdateDialogControls** por conta própria, você notará que botões que não têm **ON_COMMAND** ou **manipuladores de ON_UPDATE_COMMAND_UI** serão automaticamente desativados para você pela estrutura. Em alguns casos, você não precisará ter um manipulador, mas você vai querer que o botão permaneça ativado. A maneira mais fácil de conseguir isso é adicionar um manipulador de comando manequim (fácil de fazer com classwizard) e não fazer nada nele.

## <a name="window-message-routing"></a>Roteamento de mensagens de janela

O seguinte descreve alguns tópicos mais avançados sobre as classes de MFC e como o roteamento de mensagens do Windows e outros tópicos os impactam. As informações aqui são descritas apenas brevemente. Consulte a Referência da *Biblioteca de Classe* para obter detalhes sobre APIs públicas. Consulte o código-fonte da biblioteca MFC para obter mais informações sobre detalhes da implementação.

Consulte a [Nota Técnica 17](../mfc/tn017-destroying-window-objects.md) para obter detalhes sobre a limpeza do windows, um tópico muito importante para todas as classes derivadas da **CWnd.**

## <a name="cwnd-issues"></a>Problemas com CWnd

A função de membro de implementação **CWnd::OnChildNotify** fornece uma arquitetura poderosa e extensível para janelas de crianças (também conhecidas como controles) para ligar ou de outra forma ser informado de mensagens, comandos e notificações de controle que vão para seus pais (ou "proprietário"). Se a janela filho (/controle) for um objeto C++ **CWnd** em si, a função virtual **OnChildNotify** é chamada primeiro com os parâmetros da mensagem original (ou seja, uma estrutura **MSG).** A janela da criança pode deixar a mensagem em paz, comê-la ou modificar a mensagem para o pai (raro).

A implementação **cwnd** padrão lida com as seguintes mensagens e usa o gancho **OnChildNotify** para permitir que janelas de crianças (controles) acessem primeiro a mensagem:

- **WM_MEASUREITEM** e **WM_DRAWITEM** (para auto-sorteio)

- **WM_COMPAREITEM** e **WM_DELETEITEM** (para auto-sorteio)

- **WM_HSCROLL** e **WM_VSCROLL**

- **Wm_ctlcolor**

- **Wm_parentnotify**

Você notará que o gancho **OnChildNotify** é usado para alterar mensagens de desenho do proprietário em mensagens de auto-desenho.

Além do gancho **OnChildNotify,** as mensagens de rolagem têm um comportamento de roteamento adicional. Veja abaixo mais detalhes sobre barras de rolagem e fontes de **WM_HSCROLL** e **mensagens WM_VSCROLL.**

## <a name="cframewnd-issues"></a>Problemas cframewnd

A classe **CFrameWnd** fornece a maior parte da implementação de roteamento de comando e atualização da interface do usuário. Isso é usado principalmente para a janela principal do quadro do aplicativo **(CWinApp:m_pMainWnd),** mas se aplica a todas as janelas do quadro.

A janela principal do quadro é a janela com a barra de menu e é o pai da barra de status ou linha de mensagem. Por favor, consulte a discussão acima sobre roteamento de comando e **WM_INITMENUPOPUP.**

A classe **CFrameWnd** fornece o gerenciamento da exibição ativa. As seguintes mensagens são roteadas através da exibição ativa:

- Todas as mensagens de comando (a exibição ativa obtém primeiro acesso a elas).

- **WM_HSCROLL** e **WM_VSCROLL** mensagens de barras de rolagem de irmãos (veja abaixo).

- **WM_ACTIVATE** (e **WM_MDIACTIVATE** para MDI) são transformadas em chamadas para a função virtual **CView::OnActivateView**.

## <a name="cmdiframewndcmdichildwnd-issues"></a>Problemas cmdiframewnd/CMDIChildWnd

Ambas as classes de janela de quadro MDI derivam de **CFrameWnd** e, portanto, ambas estão habilitadas para o mesmo tipo de roteamento de comando e atualização da interface do usuário fornecida no **CFrameWnd**. Em um aplicativo MDI típico, apenas a janela principal do quadro (ou seja, o objeto **CMDIFrameWnd)** mantém a barra de menu e a barra de status e, portanto, é a principal fonte da implementação de roteamento de comando.

O esquema geral de roteamento é que a janela de criança SmDI ativa obtém primeiro acesso a comandos. As funções padrão **do PreTranslateMessage** lidam com tabelas do acelerador tanto para janelas de criançaS MDI (primeiro) quanto para o quadro MDI (segundo) bem como para os aceleradores padrão de comando de sistema MDI normalmente manuseados pelo **TranslateMDISysAccel** (último).

## <a name="scroll-bar-issues"></a>Problemas da barra de rolagem

Ao manusear a mensagem de rolagem **(WM_HSCROLL**/**OnHScroll** e/ou **WM_VSCROLL**/**OnVScroll),** você deve tentar escrever o código do manipulador para que ele não conte com a de onde veio a mensagem da barra de rolagem. Este não é apenas um problema geral do Windows, uma vez que as mensagens de rolagem podem vir de controles de barra de rolagem verdadeiros ou de **WS_HSCROLL**/**WS_VSCROLL** barras de rolagem que não são controles de barra de rolagem.

O MFC estende isso para permitir que os controles da barra de rolagem sejam filhos ou irmãos da janela que está sendo rolada (na verdade, a relação pai/filho entre a barra de rolagem e a janela que está sendo rolada pode ser qualquer coisa). Isso é especialmente importante para barras de rolagem compartilhadas com janelas de divisor. Consulte a [Nota Técnica 29](../mfc/tn029-splitter-windows.md) para obter detalhes sobre a implementação do **CSplitterWnd,** incluindo mais informações sobre problemas de barra de rolagem compartilhada.

Em uma nota lateral, há duas classes derivadas **da CWnd** onde os estilos de barra de rolagem especificados na hora de criar são presos e não passados para o Windows. Quando passada para uma rotina de criação, **WS_HSCROLL** e **WS_VSCROLL** podem ser definidas de forma independente, mas após a criação não podem ser alteradas. Claro, você não deve testar ou definir diretamente os WS_SCROLL pedaços de estilo da janela que eles criaram.

Para **CMDIFrameWnd,** os estilos de barra de rolagem que você passa para **Criar** ou **LoadFrame** são usados para criar o MDICLIENT. Se você deseja ter uma área MDICLIENT rolável (como o Gerenciador de programas do Windows) certifique-se de definir ambos os estilos de barra de rolagem **(WS_HSCROLL** &#124; **WS_VSCROLL)** para o estilo usado para criar o **CMDIFrameWnd**.

Para **CSplitterWnd,** os estilos da barra de rolagem aplicam-se às barras de rolagem compartilhadas especiais para as regiões do divisor. Para janelas de divisor estática, você normalmente não definirá nenhum dos estilos de barra de rolagem. Para janelas de divisor dinâmico, você geralmente terá o estilo da barra de rolagem definido para a direção que você dividirá, **ou seja, WS_HSCROLL** se você puder dividir linhas, **WS_VSCROLL** se você puder dividir colunas.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
