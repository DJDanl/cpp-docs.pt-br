---
title: "TN021: comando e roteamento de mensagem | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.routing"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "roteamento de comando [C++], observação técnica TN021"
  - "TN021"
  - "mensagens do Windows [C++], roteamento"
ms.assetid: b5952c8b-123e-406c-a36d-a6ac7c6df307
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN021: comando e roteamento de mensagem
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve a arquitetura de roteamento e de distribuição do comando bem como os tópicos avançados no roteamento de mensagem geral da janela.  
  
 Consulte os Visual C\+\+ para obter detalhes gerais em arquiteturas descritas aqui, especialmente a distinção entre as mensagens do windows, notificações de controle comandos, e.  Essa observação assumirá que é muito familiarizado com os problemas descritos na documentação impressa e apenas os tópicos muito avançados de endereços.  
  
## A funcionalidade de MFC 1,0 de roteamento e de distribuição do comando evolui a arquitetura de MFC 2.0  
 O windows tem a mensagem de **WM\_COMMAND** que é sobrecarregada para fornecer notificações de comandos de menu, as teclas de aceleração e notificações de diálogo\- controle.  
  
 MFC 1,0 compilado em que um pouco permitindo que um manipulador de comando \(por exemplo, “OnFileNew”\) em uma classe derivada de **CWnd** é chamado em resposta a **WM\_COMMAND**específico.  Isso é colado junto com uma estrutura de dados chamada no mapa de mensagem, e resultados em um mecanismo muito espaço eficiente de comando.  
  
 Funcionalidade adicional também fornecida MFC 1,0 para separar notificações de controle de mensagens do comando.  Os comandos são representados por uma ID de 16 bits, às vezes conhecida como uma ID de comando  Os comandos geralmente partir de **CFrameWnd** \(isto é, um menu ou selecione um acelerador convertido\) e são direcionadas para uma variedade de outras janelas.  
  
 Roteamento usado de comando MFC 1,0 em um sentido limitado para a implementação interface de documentos \(MDI\). \(Um representante da janela do quadro MDI comandos à janela ativa filho MDI.\)  
  
 Essa funcionalidade foi generalizada e estendida em MFC 2.0 para permitir que os comandos a serem manipulados por um intervalo mais amplo de objetos \(não apenas objetos da janela\).  O fornece uma arquitetura extensível e mais mais formal para rotear mensagens e reutilizam o roteamento de destino do comando não somente para tratar de comandos, mas também para atualizar interface do usuário objetos \(como itens de menu e botões da barra de ferramentas\) para refletir a disponibilidade atual de um comando.  
  
## IDs de comando  
 Visual C\+\+ consulte para obter uma explicação de roteamento de comando e o processo de associação.  [Observação 20 técnica](../mfc/tn020-id-naming-and-numbering-conventions.md) contém informações sobre a nomeação de ID.  
  
 Usamos o prefixo genérico ID\_” para IDs de comando.  As IDs de comando são \>\= 0x8000.  A linha ou a barra de status de mensagem mostrarão a cadeia de caracteres de descrição do comando se houver um recurso de STRINGTABLE com as mesmas IDs que a ID de comando  
  
 Os recursos de seu aplicativo, um comando ao da ID que aparece em vários campos:  
  
-   Em um recurso de STRINGTABLE com a mesma ID da linha mensagem\- aviso.  
  
-   Possivelmente em muitos recursos de MENU que estão anexados aos itens de menu que invoca o mesmo comando.  
  
-   \(AVANÇADO\) em um botão da caixa de diálogo para um comando de GOSUB.  
  
 No código\-fonte do aplicativo, um comando ao da ID que aparece em vários campos:  
  
-   No RESOURCE.H \(ou outro arquivo de cabeçalho principal do símbolo\) para definir IDs específicas do aplicativo do comando.  
  
-   TALVEZ em uma matriz de ID usada para criar uma barra de ferramentas.  
  
-   Em uma macro de **ON\_COMMAND** .  
  
-   TALVEZ em uma macro de **ON\_UPDATE\_COMMAND\_UI** .  
  
 Atualmente, o único implementação em MFC que requer IDs de comando é \>\= 0x8000 é a implementação de caixas de diálogo comandos\/de GOSUB.  
  
## Comandos de GOSUB, usando a arquitetura de comando nas caixas de diálogo  
 A arquitetura do comando de roteamento e os comandos habilitar funciona bem com as janelas de peça, os itens de menu, os botões da barra de ferramentas, os botões da barra da caixa de diálogo, as outras barras de controle e outros elementos da interface do usuário criados para atualizar comandos sob demanda e da rota ou IDs de controle em um destino principal de comando \(normalmente a janela do quadro principal\).  Que o destino principal do comando pode rotear as notificações do comando ou de controle para outros objetos de destino do comando conforme apropriado.  
  
 Uma caixa de diálogo modal ou modeless \(\) pode se beneficiar de qualquer um dos recursos da arquitetura de comando se você atribuir a ID do controle da caixa de diálogo para a ID de comando apropriado  O suporte para caixas de diálogo não é automática, assim você pode precisar escrever um código adicional.  
  
 Observe que para que todos esses recursos funcionem corretamente, o comando que as IDs devem ser \>\= 0x8000.  Desde que várias caixas de diálogo eles obteriam direcionadas ao mesmo lado, os comandos compartilhados devem ser \>\= 0x8000, quando o IDCs nonshared em uma caixa de diálogo específica deve ser \<\= 0x7FFF.  
  
 Você pode colocar um botão normal em uma caixa de diálogo modal normal com o IDC de cluster do botão à ID de comando apropriado  Quando o usuário seleciona o botão, o proprietário da caixa de diálogo \(normalmente a janela do quadro principal\) obtém o comando como qualquer outro comando.  Isso é chamado de um comando de GOSUB desde que normalmente é usado para ativar outra caixa de diálogo \(um GOSUB da primeira caixa de diálogo\).  
  
 Você também pode chamar a função **CWnd::UpdateDialogControls** na caixa de diálogo e passá\-la o endereço da janela principal do quadro.  Essa função habilitará ou desabilitará os controles da caixa de diálogo com base no se tiverem manipuladores do comando no quadro.  Essa função é chamada automaticamente para você para barras de controle no loop ocioso de seu aplicativo, mas você deve chame diretamente para caixas de diálogo normais que você deseja que tenham esse recurso.  
  
## Quando é chamado ON\_UPDATE\_COMMAND\_UI  
 Mantendo estado habilitado\/verificado de todos os itens de menu de um programa qualquer tempo podem ser um problema computacionalmente caro.  Uma técnica comum é itens de menu habilitar\/verificação apenas quando o usuário seleciona o POP\-UP.  A implementação de MFC 2.0 de **CFrameWnd** trata a mensagem de **WM\_INITMENUPOPUP** e usa a arquitetura de roteamento de comando para determinar os estados de menus pelos manipuladores de **ON\_UPDATE\_COMMAND\_UI** .  
  
 **CFrameWnd** também controla a mensagem de **WM\_ENTERIDLE** para descrever o item de menu atual selecionado na barra de status \(também conhecida como a linha de mensagens\).  
  
 A estrutura do menu de um aplicativo, editada pelo Visual C\+\+, é usada para representar os comandos em potencial disponíveis no momento de **WM\_INITMENUPOPUP** .  Os manipuladores de**ON\_UPDATE\_COMMAND\_UI** podem alterar o estado ou o texto de um menu, ou por avançadas \(como a lista de Arquivo MRU ou o menu pop\-up OLE os verbos\), altere a verdade a estrutura do menu antes que o menu seja desenhado.  
  
 Mesmo processamento de **ON\_UPDATE\_COMMAND\_UI** é feito média para barras de ferramentas \(e outras barras de controle\) quando o aplicativo digita o loop ocioso.  Consulte *a biblioteca de classes referência* e [Observação 31 técnica](../mfc/tn031-control-bars.md) para obter mais informações sobre as barras de controle.  
  
## Menu pop\-up aninhados  
 Se você estiver usando uma estrutura aninhada no menu, você observará que o manipulador de **ON\_UPDATE\_COMMAND\_UI** para o primeiro item de menu no menu pop\-up é chamado em dois casos diferentes.  
  
 Primeiro, é chamado para o próprio menu pop\-up.  Isso é necessário porque o menu pop\-up não têm IDs e usamos a ID do primeiro item de menu do menu suspenso para consultar o menu pop\-up inteiro.  Nesse caso, a variável de membro de **m\_pSubMenu** do objeto de **CCmdUI** será não nulo e apontará para o menu pop\-up.  
  
 Segundo, é chamado imediatamente antes que os itens de menu no menu pop\-up devem ser desenhados.  Nesse caso, o ID faz referência a apenas o primeiro item de menu e a variável de membro de **m\_pSubMenu** do objeto de **CCmdUI** será NULL.  
  
 Isso permite que você habilite o menu pop\-up distinto de seus itens de menu, mas requer que você grava a qualquer código que o menu.  Por exemplo, em um menu aninhado com a seguinte estrutura:  
  
```  
File>  
    New>  
        Sheet (ID_NEW_SHEET)  
        Chart (ID_NEW_CHART)  
```  
  
 Os comandos de ID\_NEW\_SHEET de ID\_NEW\_CHART independentes e podem ser habilitados ou desabilitados.  O menu pop\-up de **Novo** deve ser habilitado se qualquer um dos dois está habilitado.  
  
 O manipulador de comando para ID\_NEW\_SHEET \(primeiro comando no pop\-up\) seria algo como:  
  
```  
void CMyApp::OnUpdateNewSheet(CCmdUI* pCmdUI)  
{  
    if (pCmdUI->m_pSubMenu != NULL)  
    {  
        // enable entire pop-up for "New" sheet and chart  
        BOOL bEnable = m_bCanCreateSheet || m_bCanCreateChart;  
  
        // CCmdUI::Enable is a no-op for this case, so we  
        //   must do what it would have done.  
        pCmdUI->m_pMenu->EnableMenuItem(pCmdUI->m_nIndex,  
            MF_BYPOSITION |   
                (bEnable ? MF_ENABLED : (MF_DISABLED | MF_GRAYED)));  
        return;  
    }  
    // otherwise just the New Sheet command  
    pCmdUI->Enable(m_bCanCreateSheet);  
}  
```  
  
 O manipulador de comando para ID\_NEW\_CHART seria um manipulador e um aspecto regulares de comando de atualização algo como:  
  
```  
void CMyApp::OnUpdateNewChart(CCmdUI* pCmdUI)  
{  
    pCmdUI->Enable(m_bCanCreateChart);  
}  
```  
  
## ON\_COMMAND e ON\_BN\_CLICKED  
 Macros da mensagem para **ON\_COMMAND** e **ON\_BN\_CLICKED** são os mesmos.  O mecanismo de roteamento de notificação de comando e de controle de MFC usa apenas a ID de comando para decidir onde rotear a.  Controle notificações com o código de notificação de controle de zero \(**BN\_CLICKED**\) são interpretados como comandos.  
  
> [!NOTE]
>  De fato, todas as notificações de controle passam pela cadeia de manipulador de comando.  Por exemplo, é tecnicamente possível que você escrever um manipulador de notificação de controle para **EN\_CHANGE** em sua classe do documento.  Isso geralmente não é aconselhável como os aplicativos práticos esse recurso são poucas, o recurso não tem suporte por ClassWizard, e o uso de recursos pode resultar em código frágil.  
  
## Desabilitando desabilitar automático de controles do botão  
 Se você colocar um controle de botão na barra da caixa de diálogo, ou em uma caixa de diálogo usando onde você está chamando **CWnd::UpdateDialogControls** sozinho, você observará que os botões que não têm manipuladores de **ON\_COMMAND** ou de **ON\_UPDATE\_COMMAND\_UI** serão desabilitados automaticamente para você pela estrutura.  Em alguns casos, você não precisará ter um manipulador, mas você desejará o botão para permanecer habilitado.  A maneira mais fácil de fazer isso é adicionar um manipulador fictícia de comando \(fácil fazer com ClassWizard\) e não fazer nada nela.  
  
## Roteamento de mensagem da janela  
 A tabela a seguir descreve um pouco mais de tópicos avançados nas classes de MFC e como o roteamento de mensagens do windows e outros tópicos afetam as.  As informações são somente é descrita brevemente.  Consulte *a referência da biblioteca de classes* para obter detalhes sobre as APIs públicos.  Consulte os o código\-fonte de biblioteca MFC para obter mais informações sobre os detalhes de implementação.  
  
 Consulte os [Observação 17 técnica](../mfc/tn017-destroying-window-objects.md) para obter detalhes na limpeza da janela, um tópico muito importante para todo o **CWnd**\- classes derivadas.  
  
## Problemas de CWnd  
 A função de membro **CWnd::OnChildNotify** de implementação fornece uma arquitetura extensível e avançado para as janelas filho \(também conhecidas como controles\) ao gancho ou é informada de outra forma de mensagens, os comandos, e notificações de controle que levam a seu pai \(ou “owner”\).  Se a janela filho \(\/control\) é o próprio objeto c criando **CWnd** , a função **OnChildNotify** virtual será chamada primeiro com os parâmetros da mensagem original \(ou seja, uma estrutura de **MSG** \).  A janela filho pode sair da mensagem sozinha, comê\-la, ou alterar a mensagem para o pai \(raro\).  
  
 A implementação de **CWnd** da opção controla as seguintes mensagens e usa o gancho de **OnChildNotify** para permitir janelas filho \(\) controla ao primeiro acesso na mensagem:  
  
-   **WM\_MEASUREITEM** e **WM\_DRAWITEM** \(para o autoajuste descompasso\)  
  
-   **WM\_COMPAREITEM** e **WM\_DELETEITEM** \(para o autoajuste descompasso\)  
  
-   **WM\_HSCROLL** e **WM\_VSCROLL**  
  
-   **WM\_CTLCOLOR**  
  
-   **WM\_PARENTNOTIFY**  
  
 Você observará que o gancho de **OnChildNotify** é usado alterando mensagens de proprietário\- desenhe séries em mensagens da descompasso.  
  
 Além do gancho de **OnChildNotify** , as mensagens de rolagem têm um comportamento adicional de roteamento.  Consulte abaixo para obter mais detalhes sobre barras de rolagem e em fontes de mensagens de **WM\_HSCROLL** e de **WM\_VSCROLL** .  
  
## Problemas de CFrameWnd  
 A classe de **CFrameWnd** fornece a maioria de roteamento e a interface do usuário de comando que atualiza a implementação.  Isso é usado principalmente para a janela principal do quadro do aplicativo \(\)**CWinApp::m\_pMainWnd**mas se aplica a todas as janelas do quadro.  
  
 A janela do quadro principal é a janela com a barra de menus e é o pai da linha da barra de status ou de mensagem.  Consulte a discussão do roteamento e no **WM\_INITMENUPOPUP.**de comando  
  
 A classe de **CFrameWnd** fornece o gerenciamento da exibição ativa.  As seguintes mensagens são roteadas através da exibição ativa:  
  
-   Todos comando mensagens \(a exibição ativa obtém o primeiro acesso a eles\).  
  
-   Mensagens de**WM\_HSCROLL** e de **WM\_VSCROLL** das barras de rolagem irmão \(consulte abaixo\).  
  
-   **WM\_ACTIVATE** \(e **WM\_MDIACTIVATE** para MDI\) são transformados em chamadas para a função **CView::OnActivateView**virtual.  
  
## Problemas de CMDIFrameWnd\/CMDIChildWnd  
 Ambas as classes da janela do quadro MDI derivam\-se de **CFrameWnd** e são\-se como consequência ambas habilitadas para o mesmo entre o roteamento de comando e atualizar da interface do usuário fornecidos em **CFrameWnd**.  Em um aplicativo típico MDI, somente a janela do quadro principal \(isto é, o objeto de **CMDIFrameWnd** \) mantém a barra de menus e a barra de status e em virtude disso é a principal origem da implementação de roteamento do comando.  
  
 O esquema geral de roteamento é que a janela ativa filho MDI obtém o primeiro acesso aos comandos.  As funções de **PreTranslateMessage** da opção controla tabelas de aceleração para janelas filho MDI primeiro \(\) e o quadro MDI \(segundo\) bem como os padrões aceleradores de comando do sistema MDI tratado normalmente pela última **TranslateMDISysAccel** \(\).  
  
## Problemas da barra de rolagem  
 Ao tratar a SCROLL\- mensagem \(**WM\_HSCROLL**\/**OnHScroll** e\/ou **WM\_VSCROLL**\/**OnVScroll**\), você deverá tentar gravar o código do manipulador e não depende em onde a mensagem da barra de rolagem foi originada.  Esse é um problema não só geral do windows, desde que as mensagens de rolagem podem vir de controles true na barra de rolagem ou das barras de rolagem de **WS\_HSCROLL**\/**WS\_VSCROLL** que não são controles da barra de rolagem.  
  
 O que MFC estende para permitir controles da barra de rolagem ser filhos ou irmãos da janela que está sendo enrolada \(de fatos, a relação entre a barra de rolagem e a janela pai\/filho que está sendo enrolada podem ser qualquer coisa\).  Isso é especialmente importante para barras de rolagem compartilhadas com o windows do separador.  Consulte os [Observação 29 técnica](../mfc/tn029-splitter-windows.md) para obter detalhes na implementação de **CSplitterWnd** que inclui mais informações sobre problemas compartilhados da barra de rolagem.  
  
 Em uma nota lateral, há duas classes derivadas de **CWnd** em onde os estilos da barra de rolagem especificados criam hora são interceptadas e não passados ao windows.  Quando é passada a uma rotina de criação, **WS\_HSCROLLWS\_VSCROLL** independentes e podem ser definidos, mas depois que a criação não pode ser alterada.  Naturalmente, você não deve testar diretamente ou defina o WS\_? SCROLL bit de estilo da janela que criaram.  
  
 Para **CMDIFrameWnd** os estilos que a barra de rolagem você passa na **Criar** ou **LoadFrame** é usado para criar o MDICLIENT.  Se você quiser ter uma área rolável de MDICLIENT \(como o gerente de programa do windows\) defina os estilos da barra de rolagem \(**WS\_HSCROLL** &#124; **WS\_VSCROLL**\) para o estilo usado para criar **CMDIFrameWnd**.  
  
 Para **CSplitterWnd** os estilos da barra de rolagem se aplicam às barras de rolagem compartilhadas especiais para as regiões do separador.  Para o windows estáticos do divisor, você normalmente não definirá um ou outro estilo da barra de rolagem.  Para o windows dinâmicos do divisor, você geralmente terá o estilo da barra de rolagem definido para a direção na qual você dividirá, ou seja, **WS\_HSCROLL** se você pode dividir linhas, **WS\_VSCROLL** se você pode dividir colunas.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)