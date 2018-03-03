---
title: 'TN021: Comando e roteamento de mensagens | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.routing
dev_langs:
- C++
helpviewer_keywords:
- TN021
- command routing [MFC], technical note TN021
- Windows messages [MFC], routing
ms.assetid: b5952c8b-123e-406c-a36d-a6ac7c6df307
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1854be249db91257228e6dab70fc7ff2f50664ce
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn021-command-and-message-routing"></a>TN021: comando e roteamento de mensagem
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve a arquitetura de roteamento e a expedição de comando, bem como tópicos avançados no roteamento de mensagens da janela geral.  
  
 Consulte Visual C++ para obter detalhes gerais sobre as arquiteturas descritas aqui, especialmente a distinção entre as mensagens, notificações de controle e comandos do Windows. Esta anotação supõe que você esteja familiarizado com os problemas descritos na documentação do impressa e aborda apenas tópicos muito avançados.  
  
## <a name="command-routing-and-dispatch-mfc-10-functionality-evolves-to-mfc-20-architecture"></a>Funcionalidade de roteamento de comando e expedição MFC 1.0 evolui ao MFC 2.0 arquitetura  
 O Windows tem o **WM_COMMAND** mensagem está sobrecarregada para fornecer notificações de comandos de menu, teclas de aceleração e notificações de controle de caixa de diálogo.  
  
 MFC 1.0 criados em que um pouco, permitindo que um manipulador de comando (por exemplo, "OnFileNew") um **CWnd** derivado da classe for chamado em resposta a um determinado **WM_COMMAND**. Isso é colado junto com uma estrutura de dados chamada de mapa de mensagem e resulta em um mecanismo de comando muito eficiente de espaço.  
  
 1.0 MFC também fornecida funcionalidade adicional para separar as notificações de controle de mensagens de comando. Comandos são representados por uma ID de 16 bits, às vezes conhecida como uma ID de comando. Comandos normalmente iniciam a partir de um **CFrameWnd** (ou seja, um menu, selecione ou um acelerador traduzido) e roteada para uma variedade de outras janelas.  
  
 1.0 MFC usado roteamento de comando em um sentido limitado para a implementação de Interface de documentos múltiplos (MDI). (Uma janela de quadro MDI delegar comandos para a janela filho MDI ativo.)  
  
 Essa funcionalidade foi generalizada e estendida no MFC 2.0 para permitir comandos sejam tratadas por um número maior de objetos (não apenas objetos de janela). Ele fornece mais formais e arquitetura extensível para roteamento de mensagens e reutiliza o roteamento de destino de comando para não apenas de tratamento de comandos, mas também para atualizar objetos de interface do usuário (como itens de menu e botões de barra de ferramentas) para refletir a disponibilidade atual de um comando .  
  
## <a name="command-ids"></a>IDs de comando  
 Consulte Visual C++ para obter uma explicação do comando de roteamento e o processo de associação. [20 de observação técnica](../mfc/tn020-id-naming-and-numbering-conventions.md) contém informações sobre nomenclatura de ID.  
  
 Usamos o prefixo genérico "ID _" para as IDs de comando. IDs de comando são > 0x8000. A barra de status ou de linha de mensagem mostrará a cadeia de caracteres de descrição de comando se há um recurso STRINGTABLE com as mesmas IDs que a ID de comando.  
  
 Nos recursos do seu aplicativo, um comando que ID pode exibido em vários locais:  
  
-   Em um recurso STRINGTABLE que tenha a mesma ID que o prompt de linha de mensagem.  
  
-   Em possivelmente muitos recursos do MENU anexados a itens de menu que invocam o mesmo comando.  
  
-   (Avançado) em um botão da caixa de diálogo para um comando GOSUB.  
  
 No código-fonte do seu aplicativo, um comando que ID pode exibido em vários locais:  
  
-   Em seu recurso. H (ou outro arquivo de cabeçalho de símbolo principal) para definir as IDs de comando específicas do aplicativo.  
  
-   TALVEZ em uma matriz de ID usada para criar uma barra de ferramentas.  
  
-   Em um **ON_COMMAND** macro.  
  
-   TALVEZ em um **ON_UPDATE_COMMAND_UI** macro.  
  
 Atualmente, a única implementação em MFC que requer IDs de comando ser > = 0x8000 é a implementação de caixas de diálogo GOSUB/comandos.  
  
## <a name="gosub-commands-using-command-architecture-in-dialogs"></a>Comandos GOSUB, usando o comando arquitetura nas caixas de diálogo  
 A arquitetura do comando de roteamento e habilitar comandos funciona bem com janelas com moldura, itens de menu, botões da barra de ferramentas, botões da barra de caixa de diálogo, outras barras de controle e outros elementos de interface do usuário projetados para atualizar em comandos de rota e de demanda ou controlar IDs para um principal destino do comando (geralmente a janela do quadro principal). Esse destino principal pode encaminhar as notificações de comando ou o controle a outros objetos de destino do comando conforme apropriado.  
  
 Uma caixa de diálogo (modal ou sem janela restrita) pode se beneficiar de alguns dos recursos da arquitetura do comando se você atribuir a ID do controle do controle de caixa de diálogo para a ID de comando apropriado. Suporte para as caixas de diálogo não é automático, então talvez seja necessário escrever código adicional.  
  
 Observe que, para todos esses recursos funcionar corretamente, suas IDs de comando devem ser > = 0x8000. Como muitas caixas de diálogo foi roteadas para a mesma estrutura, comandos compartilhados devem ser > = 0x8000, enquanto os IDCs não compartilhados em uma caixa de diálogo específica devem ser < = 0x7FFF.  
  
 Você pode colocar um botão normal em uma caixa de diálogo modal normal com IDC do botão definido como a ID de comando apropriado. Quando o usuário seleciona o botão, o proprietário da caixa de diálogo (geralmente a janela do quadro principal) obtém o comando exatamente como qualquer outro comando. Isso é chamado um comando GOSUB porque geralmente é usado para abrir outra caixa de diálogo (GOSUB da caixa de diálogo primeiro).  
  
 Você também pode chamar a função **CWnd::UpdateDialogControls** na sua caixa de diálogo e passá-lo o endereço da janela do quadro principal. Essa função será habilitar ou desabilitar os controles de caixa de diálogo com base em se eles têm manipuladores de comandos no quadro. Essa função é chamada automaticamente para você das barras de controle de loop ocioso do seu aplicativo, mas você deve chamá-lo diretamente para as caixas de diálogo normais que você deseja que tenham esse recurso.  
  
## <a name="when-onupdatecommandui-is-called"></a>Quando ON_UPDATE_COMMAND_UI é chamado  
 Manter o estado da habilitado/check de todas de um programa itens de menu sempre pode ser um problema de computação dispendioso. Uma técnica comum é habilitar/verificação de itens de menu apenas quando o usuário seleciona o pop-up. A implementação do MFC 2.0 de **CFrameWnd** identificadores de **WM_INITMENUPOPUP** mensagem e usa a arquitetura de roteamento de comando para determinar os estados de menus por meio de **ON_UPDATE_COMMAND_ Interface do usuário** manipuladores.  
  
 **CFrameWnd** também controla o **WM_ENTERIDLE** mensagem para descrever o menu atual ao item selecionado no status de barra (também conhecido como a linha de mensagem).  
  
 Estrutura de menu do aplicativo, editada pelo Visual C++, é usada para representar os potencial de comandos disponíveis na **WM_INITMENUPOPUP** tempo. **ON_UPDATE_COMMAND_UI** manipuladores podem modificar o estado ou o texto de um menu ou para usos avançados (como a lista MRU de arquivo ou o menu de verbos OLE), na verdade, modifique a estrutura do menu antes de menu é desenhado.  
  
 O mesmo tipo de **ON_UPDATE_COMMAND_UI** processamento é feito para barras de ferramentas (e outras barras de controle) quando o aplicativo entra em seu loop ocioso. Consulte o *referência da biblioteca de classe* e [31 de observação técnica](../mfc/tn031-control-bars.md) para obter mais informações sobre barras de controle.  
  
## <a name="nested-pop-up-menus"></a>Menus pop-up aninhadas  
 Se você estiver usando uma estrutura aninhada de menu, você observará que o **ON_UPDATE_COMMAND_UI** manipulador para o primeiro item de menu no menu pop-up é chamado em dois casos diferentes.  
  
 Primeiro, ele é chamado para o próprio menu pop-up. Isso é necessário porque os menus pop-up não têm IDs e usamos a ID do primeiro item de menu do menu pop-up para se referir ao menu pop-up inteiro. Nesse caso, o **m_pSubMenu** variável de membro do **CCmdUI** objeto será não nulo e apontará para o menu pop-up.  
  
 Em segundo lugar, ele é chamado antes que os itens de menu no menu pop-up devem ser desenhada. Nesse caso, a ID refere-se apenas para o primeiro item de menu e a **m_pSubMenu** variável de membro do **CCmdUI** objeto será nulo.  
  
 Isso permite que você habilite o menu pop-up distinto de seus itens de menu, mas requer que você escreva algum código de percepção de menu. Por exemplo, em um menu aninhado com a seguinte estrutura:  
  
```  
File>  
    New> 
    Sheet (ID_NEW_SHEET)  
    Chart (ID_NEW_CHART)  
```  
  
 Os comandos ID_NEW_SHEET e ID_NEW_CHART podem ser ativados ou desativados independentemente. O **novo** menu pop-up deve ser habilitada se um dos dois está ativado.  
  
 O manipulador de comandos para ID_NEW_SHEET (o primeiro comando o pop-up) seria algo como:  
  
```  
void CMyApp::OnUpdateNewSheet(CCmdUI* pCmdUI)  
{  
    if (pCmdUI->m_pSubMenu != NULL)  
 { *// enable entire pop-up for "New" sheet and chart  
    BOOL bEnable = m_bCanCreateSheet || m_bCanCreateChart;  
 *// CCmdUI::Enable is a no-op for this case,
    so we *//   must do what it would have done.  
    pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex, 
    MF_BYPOSITION |   
 (bEnable  MF_ENABLED : (MF_DISABLED | MF_GRAYED)));

    return; 
 } *// otherwise just the New Sheet command  
    pCmdUI->Enable(m_bCanCreateSheet);

} 
```  
  
 O manipulador de comandos para ID_NEW_CHART seria um manipulador de comandos de atualização normal e procure algo como:  
  
```  
void CMyApp::OnUpdateNewChart(CCmdUI* pCmdUI)  
{  
    pCmdUI->Enable(m_bCanCreateChart);

} 
```  
  
## <a name="oncommand-and-onbnclicked"></a>ON_COMMAND e ON_BN_CLICKED  
 As macros de mapa de mensagem para **ON_COMMAND** e **ON_BN_CLICKED** são os mesmos. O comando e controle de notificação roteamento mecanismo MFC usa apenas a ID de comando para decidir onde rotear para. Controlar notificações com código de notificação de controle de zero (**BN_CLICKED**) são interpretados como comandos.  
  
> [!NOTE]
>  Na verdade, todas as mensagens de notificação do controle percorrer a cadeia de manipulador de comando. Por exemplo, é tecnicamente possível para escrever um manipulador de notificação de controle para **EN_CHANGE** em sua classe de documento. Isso não é aconselhável geralmente porque as aplicações desse recurso são poucas, o recurso não é suportado pelo ClassWizard e uso do recurso pode resultar em um código frágil.  
  
## <a name="disabling-the-automatic-disabling-of-button-controls"></a>Desabilitando a desativação automática de controles de botão  
 Se você colocar um controle de botão na barra de uma caixa de diálogo ou em uma caixa de diálogo usando onde você está chamando **CWnd::UpdateDialogControls** por conta própria, você observará que botões que não têm **ON_COMMAND** ou **ON_UPDATE_COMMAND_UI** manipuladores serão automaticamente desabilitados para você pela estrutura. Em alguns casos, você não precisa ter um manipulador, mas você pode permanecer habilitado, o botão. A maneira mais fácil de fazer isso é adicionar um manipulador de comando fictício (fácil com ClassWizard) e não em branco.  
  
## <a name="window-message-routing"></a>Roteamento de mensagens de janela  
 O exemplo a seguir descreve alguns tópicos mais avançados nas classes MFC e afetam-los como roteamento de mensagens do Windows e outros tópicos. As informações aqui só são descritas brevemente. Consulte o *referência da biblioteca de classe* para obter detalhes sobre APIs públicas. Consulte o código-fonte biblioteca MFC para obter mais informações sobre detalhes de implementação.  
  
 Consulte [17 de observação técnica](../mfc/tn017-destroying-window-objects.md) para obter detalhes sobre a limpeza de janela, um tópico muito importante para todos os **CWnd**-classes derivadas.  
  
## <a name="cwnd-issues"></a>Problemas de CWnd  
 A função de membro de implementação **CWnd::OnChildNotify** fornece uma arquitetura avançada e extensível para janelas filho (também conhecido como controles) conectar-se ou caso contrário, se mantenha informado sobre o controle de mensagens e comandos notificações enviadas a seu pai (ou "proprietário"). Se a janela filho (/ controle) é um C++ **CWnd** objeto em si, a função virtual **OnChildNotify** é chamada primeiro com os parâmetros da mensagem original (ou seja, um **MSG**estrutura). A janela filho pode deixar a mensagem sem, comê-lo ou modificá-la para o pai (raro).  
  
 O padrão **CWnd** implementação lida com as seguintes mensagens e usa o **OnChildNotify** gancho para permitir que o filho (controles) do windows para o primeiro acesso a mensagem:  
  
- **WM_MEASUREITEM** e **WM_DRAWITEM** (para auto desenhar)  
  
- **WM_COMPAREITEM** e **WM_DELETEITEM** (para auto desenhar)  
  
- **WM_HSCROLL** e **WM_VSCROLL**  
  
- **WM_CTLCOLOR**  
  
- **WM_PARENTNOTIFY**  
  
 Você observará a **OnChildNotify** gancho será usado para alterar as mensagens de desenho proprietário em mensagens desenhar automaticamente.  
  
 Além de **OnChildNotify** mensagens de rolagem de gancho, para ter ainda mais o comportamento de roteamento. Consulte abaixo para obter mais detalhes sobre as barras de rolagem e fontes de **WM_HSCROLL** e **WM_VSCROLL** mensagens.  
  
## <a name="cframewnd-issues"></a>Problemas de CFrameWnd  
 O **CFrameWnd** classe fornece a maioria do roteamento de comando e a interface do usuário atualizando a implementação. Isso é usado principalmente para a janela do quadro principal do aplicativo (**CWinApp::m_pMainWnd**), mas se aplica a todas as janelas de quadro.  
  
 A janela do quadro principal é a janela com a barra de menus e é o pai da barra de status ou linha de mensagem. Consulte a discussão acima no roteamento de comando e **WM_INITMENUPOPUP.**  
  
 O **CFrameWnd** classe fornece gerenciamento de modo de exibição ativo. As seguintes mensagens são roteadas por meio do modo de exibição ativo:  
  
-   Todas as mensagens de comando (modo de exibição ativo obtém primeiro acesso a eles).  
  
- **WM_HSCROLL** e **WM_VSCROLL** mensagens de irmão rolagem (veja abaixo).  
  
- **WM_ACTIVATE** (e **WM_MDIACTIVATE** para MDI) obter transformado em chamadas para a função virtual **CView::OnActivateView**.  
  
## <a name="cmdiframewndcmdichildwnd-issues"></a>Problemas de CMDIFrameWnd/CMDIChildWnd  
 Ambas as classes de janela de quadro MDI derivam **CFrameWnd** e, portanto, estão habilitados para o mesmo tipo de roteamento de comando e atualização de interface do usuário fornecido no **CFrameWnd**. Em um aplicativo MDI típico, somente a janela do quadro principal (ou seja, o **CMDIFrameWnd** objeto) contém a barra de menu e barra de status e, portanto, é a principal fonte da implementação de roteamento do comando.  
  
 O esquema de roteamento geral é que a janela filho MDI ativo obtém primeiro acesso aos comandos. O padrão **PreTranslateMessage** funções lidar com tabelas de teclas aceleradoras para ambas as janelas de filho MDI (primeiro) e o quadro MDI (segundo), bem como os aceleradores de comando do sistema MDI padrão normalmente são manipulados pelo  **TranslateMDISysAccel** (última).  
  
## <a name="scroll-bar-issues"></a>Problemas de barra de rolagem  
 Ao lidar com a mensagem de rolagem (**WM_HSCROLL**/**OnHScroll** e/ou **WM_VSCROLL**/**OnVScroll**), você deve tentar escrever o código de manipulador para que ele não depende de onde veio a mensagem da barra de rolagem. Isso não é apenas um geral problema Windows, desde que as mensagens de rolagem podem vir de rolagem true controles de barra ou de **WS_HSCROLL**/**WS_VSCROLL** rolagem que não são controles de barra de rolagem.  
  
 Estende o MFC que para permitir que os controles de barra de rolagem ser filhos ou irmãos da janela que está sendo rolado (na verdade, a relação pai/filho entre a barra de rolagem e a janela que está sendo colocada pode ser qualquer coisa). Isso é especialmente importante para as barras de rolagem compartilhado com janelas separadoras. Consulte [29 de observação técnica](../mfc/tn029-splitter-windows.md) para obter detalhes sobre a implementação de **CSplitterWnd** incluindo obter mais informações sobre compartilhado problemas de barra de rolagem.  
  
 Em uma anotação, há dois **CWnd** onde os estilos de barra de rolagem especificados no momento da criação de classes derivadas são interceptadas e não foi passadas para o Windows. Quando passados para uma rotina de criação, **WS_HSCROLL** e **WS_VSCROLL** podem ser definidas independentemente, mas após a criação não pode ser alterada. Obviamente, não diretamente deve testar ou definir os bits de estilo WS_SCROLL da janela que criaram.  
  
 Para **CMDIFrameWnd** os estilos de barra de rolagem para o qual você passar **criar** ou **LoadFrame** são usados para criar o MDICLIENT. Se você quiser que uma área MDICLIENT rolável (como o Windows gerente de programas) não se esqueça de definir ambos da barra de rolagem estilos (**WS_HSCROLL** &#124; **WS_VSCROLL**) para o estilo usado para criar o **CMDIFrameWnd**.  
  
 Para **CSplitterWnd** os estilos de barra de rolagem se aplicam às barras de rolagem compartilhado especial para as regiões do divisor. Para janelas separadoras estáticas, você normalmente não definirá o estilo de barra de rolagem. Para janelas separadoras dinâmicas, você geralmente terá a rolagem barra estilo definido para a direção em que você dividirá, ou seja, **WS_HSCROLL** se você pode dividir linhas, **WS_VSCROLL** se você pode dividir as colunas.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

