---
title: 'TN021: Comando e roteamento de mensagens'
ms.date: 06/28/2018
f1_keywords:
- vc.routing
helpviewer_keywords:
- TN021
- command routing [MFC], technical note TN021
- Windows messages [MFC], routing
ms.assetid: b5952c8b-123e-406c-a36d-a6ac7c6df307
ms.openlocfilehash: ce8aa2013c8f2f351ca1028f0d6103135ba5ecd8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62306175"
---
# <a name="tn021-command-and-message-routing"></a>TN021: Comando e roteamento de mensagens

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve a arquitetura de roteamento e a expedição de comando, bem como tópicos avançados no roteamento de mensagens da janela geral.

Consulte Visual C++ para obter detalhes gerais sobre as arquiteturas descritas aqui, especialmente a distinção entre as mensagens, notificações de controle e comandos do Windows. Essa observação pressupõe que você esteja familiarizado com os problemas descritos na documentação impressa e só aborda tópicos muito avançados.

## <a name="command-routing-and-dispatch-mfc-10-functionality-evolves-to-mfc-20-architecture"></a>Roteamento de comando e expedição MFC 1.0 funcionalidade evolui ao MFC 2.0 arquitetura

Windows tem a mensagem WM_COMMAND é sobrecarregada para fornecer notificações de comandos de menu, teclas de aceleração e notificações de controle de caixa de diálogo.

MFC 1.0 interna em que um pouco, permitindo que um manipulador de comandos (por exemplo, "OnFileNew") um `CWnd` derivado da classe a ser chamada em resposta a um WM_COMMAND específico. Isso é colado junto com uma estrutura de dados chamada mapa de mensagens e resulta em um mecanismo muito eficiente de espaço de comando.

MFC 1.0 também fornecia uma funcionalidade adicional para separar as notificações de controle de mensagens de comando. Comandos são representados por uma ID de 16 bits, às vezes conhecida como uma ID de comando. Comandos normalmente começam de um `CFrameWnd` (ou seja, um menu, selecione ou um acelerador traduzido) e são roteados para uma variedade de outras janelas.

MFC 1.0 usado o roteamento de comando em um sentido limitado para a implementação de Interface de documentos múltiplos (MDI). (Uma janela de quadro MDI delegar comandos à sua janela filho MDI ativo.)

Essa funcionalidade foi generalizada e estendida no MFC 2.0 para permitir que os comandos a serem manipuladas por uma maior variedade de objetos (não apenas objetos de janela). Ele fornece mais formais e arquitetura extensível para roteamento de mensagens e reutiliza o roteamento de destino de comando para não apenas a manipulação de comandos, mas também para atualizar objetos de interface do usuário (como itens de menu e botões da barra de ferramentas) para refletir a disponibilidade atual de um comando .

## <a name="command-ids"></a>IDs de comando

Consulte Visual C++ para obter uma explicação do comando de roteamento e processo de associação. [Nota técnica 20](../mfc/tn020-id-naming-and-numbering-conventions.md) contém informações sobre nomenclatura de ID.

IDs de comando, usamos o prefixo genérico "ID _". IDs de comando são > 0x8000. A barra de status ou de linha de mensagens mostrará a cadeia de caracteres de descrição de comando se há um recurso STRINGTABLE com as mesmas IDs que a ID de comando.

Nos recursos do seu aplicativo, um comando que pode ID aparece em vários locais:

- Em um recurso STRINGTABLE que tem a mesma ID que o prompt de linha de mensagem.

- No, possivelmente, vários recursos do MENU que estão anexados a itens de menu que invocam o mesmo comando.

- (Avançado) em um botão da caixa de diálogo para um comando GOSUB.

No código-fonte do seu aplicativo, um comando que pode ID aparece em vários locais:

- Em seu recurso. H (ou outro arquivo de cabeçalho de símbolo principal) para definir as IDs de comando específicas do aplicativo.

- TALVEZ em uma matriz de ID usada para criar uma barra de ferramentas.

- Em uma macro ON_COMMAND.

- TALVEZ em uma macro ON_UPDATE_COMMAND_UI.

Atualmente, a única implementação no MFC que requer IDs de comando ser > = 0x8000 é a implementação de caixas de diálogo GOSUB/comandos.

## <a name="gosub-commands-using-command-architecture-in-dialogs"></a>Comandos GOSUB, usando o comando arquitetura nas caixas de diálogo

A arquitetura de comando do roteamento e permitindo comandos funciona bem com janelas de quadro, itens de menu, botões de barra de ferramentas, botões da barra de diálogo, outras barras de controle e outros elementos de interface do usuário criados para atualizar em demanda e rotear comandos ou IDs de controle para um principal destino do comando (normalmente, a janela de quadro principal). Esse destino do comando principal pode rotear as notificações de comando ou o controle para outros objetos de destino do comando conforme apropriado.

Uma caixa de diálogo (modal ou sem-modo) pode se beneficiar de alguns dos recursos da arquitetura do comando se você atribuir a ID do controle do controle de caixa de diálogo para a ID de comando apropriado. Suporte para as caixas de diálogo não é automático, portanto, você talvez precise escrever algum código adicional.

Observe que, para todos esses recursos funcionar corretamente, suas IDs de comando devem ser > = 0x8000. Uma vez que muitas caixas de diálogo poderia ser roteadas para o mesmo quadro, comandos compartilhados devem ser > = 0x8000, enquanto os IDCs não compartilhadas em uma caixa de diálogo específica devem ser < = 0x7FFF.

Você pode colocar um botão normal em uma caixa de diálogo modal normal com a IDC do botão definido como a ID de comando apropriado. Quando o usuário seleciona o botão, o proprietário da caixa de diálogo (normalmente, a janela de quadro principal) obtém o comando assim como qualquer outro comando. Isso é chamado um comando GOSUB, pois ela geralmente é usada para abrir outra caixa de diálogo (GOSUB da caixa de diálogo primeiro).

Você também pode chamar a função `CWnd::UpdateDialogControls` na sua caixa de diálogo e passe-o endereço da janela do quadro principal. Essa função será habilitar ou desabilitar os controles de caixa de diálogo com base em se eles têm manipuladores de comandos no quadro. Essa função é chamada automaticamente para você para barras de controle em loop de ociosidade do seu aplicativo, mas você deve chamá-lo diretamente para as caixas de diálogo normais que você deseja ter esse recurso.

## <a name="when-onupdatecommandui-is-called"></a>Quando ON_UPDATE_COMMAND_UI é chamado

Manter o estado habilitado/marcada de todo um programa itens de menu sempre pode ser um problema de computação dispendioso. Uma técnica comum é habilitar/verificação de itens de menu apenas quando o usuário seleciona o pop-up. A implementação MFC 2.0 `CFrameWnd` manipula a mensagem WM_INITMENUPOPUP e usa a arquitetura de roteamento de comando para determinar os estados dos menus por meio de manipuladores ON_UPDATE_COMMAND_UI.

`CFrameWnd` também lida com a mensagem WM_ENTERIDLE para descrever o item selecionado na barra (também conhecido como a linha de mensagem) de status de menu atual.

Estrutura do menu do aplicativo, editada por Visual C++, é usado para representar os comandos possíveis disponíveis em tempo de WM_INITMENUPOPUP. Manipuladores ON_UPDATE_COMMAND_UI podem modificar o estado ou o texto de um menu, ou para usos avançados (como a lista MRU do arquivo ou no menu pop-up verbos OLE), na verdade, modificar a estrutura de menu antes de menu é desenhado.

O mesmo tipo de processamento de ON_UPDATE_COMMAND_UI é feito para barras de ferramentas (e outras barras de controle) quando o aplicativo entra em seu loop ocioso. Consulte a *referência da biblioteca de classe* e [31 de observação técnica](../mfc/tn031-control-bars.md) para obter mais informações sobre barras de controle.

## <a name="nested-pop-up-menus"></a>Menus pop-up aninhadas

Se você estiver usando uma estrutura de menu aninhada, você observará que o manipulador ON_UPDATE_COMMAND_UI para o primeiro item de menu no menu pop-up é chamado em dois casos diferentes.

Primeiro, ele é chamado para o menu pop-up em si. Isso é necessário porque os menus pop-up não possuem IDs e usamos a ID do primeiro item de menu do menu pop-up para se referir a todo o menu pop-up. Nesse caso, o *m_pSubMenu* variável de membro do `CCmdUI` objeto será não nulo e apontará para o menu pop-up.

Em segundo lugar, ele é chamado antes que os itens de menu no menu pop-up são a ser desenhado. Nesse caso, a identificação refere-se apenas para o primeiro item de menu e o *m_pSubMenu* variável de membro do `CCmdUI` objeto será nulo.

Isso permite que você habilite o menu pop-up distinto de seus itens de menu, mas requer que você escreva algum código ciente de menu. Por exemplo, em um menu aninhado com a seguinte estrutura:

```Output
File>
    New>
    Sheet (ID_NEW_SHEET)
    Chart (ID_NEW_CHART)
```

Os comandos ID_NEW_SHEET e ID_NEW_CHART podem ser habilitados ou desabilitados independentemente. O **New** menu pop-up deve ser habilitada se uma das duas estiver habilitada.

O manipulador de comandos para ID_NEW_SHEET (o primeiro comando pop-up) seria algo parecido com:

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

O manipulador de comandos para ID_NEW_CHART seria um manipulador de comandos de atualização normal e o procure algo como:

```cpp
void CMyApp::OnUpdateNewChart(CCmdUI* pCmdUI)
{
    pCmdUI->Enable(m_bCanCreateChart);
}
```

## <a name="oncommand-and-onbnclicked"></a>ON_COMMAND e ON_BN_CLICKED

As macros de mapa de mensagem para **ON_COMMAND** e **ON_BN_CLICKED** são os mesmos. O comando e controle notificação roteamento mecanismo MFC usa apenas a ID de comando para decidir onde rotear para. Controlar as notificações com o código de notificação do controle de zero (**BN_CLICKED**) são interpretadas como comandos.

> [!NOTE]
> Na verdade, todas as mensagens de notificação do controle percorrer a cadeia de manipulador de comando. Por exemplo, é tecnicamente possível para que você possa escrever um manipulador de notificação do controle para **eventos EN_CHANGE** em sua classe de documento. Isso não é aconselhável, geralmente, porque as aplicações desse recurso são poucas, o recurso não é suportado pelo ClassWizard e uso do recurso pode resultar em um código frágil.

## <a name="disabling-the-automatic-disabling-of-button-controls"></a>Desabilitando a desativação automática de controles de botão

Se você colocar um controle de botão em uma barra de diálogo, ou em uma caixa de diálogo usando onde você está chamando **CWnd::UpdateDialogControls** por conta própria, você observará que os botões que não têm **ON_COMMAND** ou **ON_UPDATE_COMMAND_UI** manipuladores serão automaticamente desabilitados para você pela estrutura. Em alguns casos, você não precisará ter um manipulador, mas você desejará o botão permaneça ativado. A maneira mais fácil de fazer isso é adicionar um manipulador de comandos fictício (fácil com ClassWizard) e não faça nada nele.

## <a name="window-message-routing"></a>Roteamento de mensagens de janela

A seguir descreve alguns tópicos mais avançados sobre as classes MFC e como o roteamento de mensagens do Windows e outros tópicos afetam-los. As informações aqui só são descritas resumidamente. Consulte a *referência da biblioteca de classe* para obter detalhes sobre as APIs públicas. Consulte o código fonte para obter mais informações sobre detalhes da implementação da biblioteca MFC.

Consulte a [17 de observação técnica](../mfc/tn017-destroying-window-objects.md) para obter detalhes sobre limpeza de janela, um tópico muito importante para todos os **CWnd**-as classes derivadas.

## <a name="cwnd-issues"></a>Problemas de CWnd

A função de membro de implementação **CWnd::OnChildNotify** fornece uma arquitetura poderosa e extensível para janelas filho (também conhecido como controles) vincular ou caso contrário, ser informado sobre mensagens, comandos e controle notificações que vão para seu pai (ou "proprietário"). Se a janela filho (controle /) é um C++ **CWnd** objeto em si, a função virtual **OnChildNotify** é chamado pela primeira vez com os parâmetros da mensagem original (ou seja, um **MSG**estrutura). A janela filho pode deixar a mensagem, comê-lo ou modifique a mensagem para o pai (raro).

O padrão **CWnd** lida com as seguintes mensagens de implementação e usa o **OnChildNotify** gancho para permitir que o filho (controles) windows primeiro acesso a mensagem:

- **WM_MEASUREITEM** e **WM_DRAWITEM** (de Self desenhe)

- **WM_COMPAREITEM** e **WM_DELETEITEM** (de Self desenhe)

- **Mensagens WM_HSCROLL** e **WM_VSCROLL**

- **WM_CTLCOLOR**

- **WM_PARENTNOTIFY**

Você observará a **OnChildNotify** gancho será usado para alterar as mensagens de desenho proprietário em mensagens Self desenhar.

Além de **OnChildNotify** mensagens de rolagem de gancho, para ter ainda mais o comportamento de roteamento. Consulte abaixo para obter mais detalhes sobre as barras de rolagem e fontes de **mensagens WM_HSCROLL** e **WM_VSCROLL** mensagens.

## <a name="cframewnd-issues"></a>Problemas de CFrameWnd

O **CFrameWnd** classe fornece a maioria do roteamento de comando e a interface do usuário atualizando a implementação. Isso é usado principalmente para a janela de quadro principal do aplicativo (**CWinApp::m_pMainWnd**), mas se aplica a todas as janelas de quadro.

A janela de quadro principal é a janela com a barra de menus e é o pai da barra de status ou linha de mensagem. Consulte a discussão acima sobre o roteamento de comando e **WM_INITMENUPOPUP.**

O **CFrameWnd** classe fornece gerenciamento de modo de exibição ativo. As seguintes mensagens são roteadas por meio do modo de exibição ativo:

- Todas as mensagens de comando (modo de exibição ativo obtém primeiro acesso a eles).

- **Mensagens WM_HSCROLL** e **WM_VSCROLL** (veja abaixo) de barras de rolagem de mensagens de irmão.

- **WM_ACTIVATE** (e **WM_MDIACTIVATE** para MDI) obtenha transformado em chamadas para a função virtual **CView::OnActivateView**.

## <a name="cmdiframewndcmdichildwnd-issues"></a>Problemas de CMDIFrameWnd/CMDIChildWnd

Ambas as classes de janela de quadro MDI derivam **CFrameWnd** e, portanto, ambos estão habilitadas para o mesmo tipo de roteamento de comando e atualização de interface do usuário fornecida no **CFrameWnd**. Em um aplicativo MDI típico, somente a janela de quadro principal (ou seja, o **CMDIFrameWnd** objeto) contém a barra de menus e barra de status e, portanto, é a principal fonte da implementação de roteamento do comando.

O esquema de roteamento geral é que a janela filho MDI ativo obtém primeiro acesso a comandos. O padrão **PreTranslateMessage** funções de lidar com tabelas de aceleradores para ambas as janelas filho MDI (primeiro) e o quadro da MDI (segundo), bem como os aceleradores de comando do sistema MDI padrão normalmente são manipulados pelo  **TranslateMDISysAccel** (último).

## <a name="scroll-bar-issues"></a>Problemas de barra de rolagem

Ao lidar com mensagens de rolagem (**mensagens WM_HSCROLL**/**OnHScroll** e/ou **WM_VSCROLL**/**OnVScroll**), você deveria tentar escrever o código do manipulador para que ele não depende de onde veio a mensagem da barra de rolagem. Esse não é só é um problema Windows geral, uma vez que as mensagens de rolagem podem vir de rolagem true controles de barra ou de **WS_HSCROLL**/**WS_VSCROLL** barras que não são controles da barra de rolagem de rolagem.

Estende o MFC para permitir que o controles da barra de rolagem ser filhos ou irmãos da janela que está sendo rolada (na verdade, a relação pai/filho entre a barra de rolagem e a janela que está sendo rolada pode ser qualquer coisa). Isso é especialmente importante para barras de rolagem compartilhado com janelas separadoras. Consulte a [29 de observação técnica](../mfc/tn029-splitter-windows.md) para obter detalhes sobre a implementação de **CSplitterWnd** incluindo obter mais informações sobre compartilhado problemas de barra de rolagem.

Em uma anotação rápida, há dois **CWnd** onde os estilos de barra de rolagem especificados no momento da criação de classes derivadas são interceptadas e não são passadas para o Windows. Quando passados para uma rotina de criação **WS_HSCROLL** e **WS_VSCROLL** podem ser definidas independentemente, mas após a criação não pode ser alterada. Claro, você deve testar não diretamente ou definir os bits de estilo WS_SCROLL da janela que criaram.

Para **CMDIFrameWnd** os estilos de barra de rolagem para o qual você passar **Create** ou **LoadFrame** são usados para criar o MDICLIENT. Se você quiser ter uma área rolável do MDICLIENT (como o Windows gerente de programa) não se esqueça de definir ambos da barra de rolagem estilos (**WS_HSCROLL** &#124; **WS_VSCROLL**) para o estilo usado para criar o **CMDIFrameWnd**.

Para **CSplitterWnd** os estilos de barra de rolagem se aplicam às barras de rolagem de compartilhado especial para as regiões do divisor. Para janelas separadoras estáticas, você normalmente não definirá o estilo de barra de rolagem. Para janelas separadoras dinâmicas, você geralmente terá a barra de estilo definido para a direção em que você dividirá, ou seja, de rolagem **WS_HSCROLL** se você pode dividir linhas, **WS_VSCROLL** se você pode dividir colunas.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
