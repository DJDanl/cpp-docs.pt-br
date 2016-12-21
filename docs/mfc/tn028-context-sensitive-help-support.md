---
title: "TN028: suporte &#224; ajuda contextual | Microsoft Docs"
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
  - "vc.help"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Ajuda contextual, Aplicativos MFC"
  - "identificadores de recursos, Ajuda contextual"
  - "TN028"
ms.assetid: 884f1c55-fa27-4d4c-984f-30907d477484
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN028: suporte &#224; ajuda contextual
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve as regras para atribuir IDs dos contextos da ajuda e outros problemas de MFC ajuda no.  O suporte da ajuda contextuais requer o compilador de ajuda que está disponível no Visual C\+\+.  
  
> [!NOTE]
>  Além de implementar a ajuda contextual WinHelp usando o, o oferece suporte MFC também que usam ajuda HTML.  Para obter mais informações sobre esses suporte e programação com ajuda HTML, consulte [Ajuda HTML: Ajuda contextual para seus programas](../mfc/html-help-context-sensitive-help-for-your-programs.md).  
  
## Tipos de ajuda com suporte  
 Há dois tipos de ajuda contextuais implementados nos aplicativos do Windows.  O primeiro, conhecido como “da ajuda F1” envolve iniciar WinHelp com o contexto apropriado com base no objeto atualmente ativo.  O segundo modo é “Shift\+ F1”.  Nesse modo, o cursor do mouse em alterações do cursor de ajuda, e a vai do usuário para clique em um objeto.  Nesse ponto, WinHelp é iniciado para dar a ajuda do objeto que o usuário clicou.  
  
 As classes do Microsoft implementam essas duas formas da ajuda.  Além disso, a estrutura da suporte a dois comandos simples da ajuda, índice da ajuda e ajuda do usando o.  
  
## Arquivos de ajuda  
 As classes do Microsoft assumem um único arquivo de ajuda.  Que o arquivo de ajuda deve ter o mesmo nome e caminho que o aplicativo.  Por exemplo, se o executável é C:\\MyApplication\\MyHelp.exe o arquivo de ajuda deve ser C:\\MyApplication\\MyHelp.hlp.  Você define o caminho entre a variável de membro de `m_pszHelpFilePath` de [Classe de CWinApp](../mfc/reference/cwinapp-class.md).  
  
## Intervalos de contexto da ajuda  
 A implementação padrão de MFC requer um programa e algumas regras sobre a atribuição de IDs de contexto da ajuda.  Essas regras são um intervalo de IDs atribuídas aos controles específicos.  Você pode substituir estas regras para fornecer implementações diferentes das várias funções de membro Ajuda\- relacionados.  
  
```  
0x00000000 - 0x0000FFFF : user defined  
0x00010000 - 0x0001FFFF : commands (menus/command buttons)  
   0x00010000 + ID_  
   (note: 0x18000-> 0x1FFFF is the practical range since command IDs are >=0x8000)  
0x00020000 - 0x0002FFFF : windows and dialogs  
   0x00020000 + IDR_  
   (note: 0x20000-> 0x27FFF is the practical range since IDRs are <= 0x7FFF)  
0x00030000 - 0x0003FFFF : error messages (based on error string ID)  
   0x00030000 + IDP_  
0x00040000 - 0x0004FFFF : special purpose (non-client areas)  
   0x00040000 + HitTest area  
0x00050000 - 0x0005FFFF : controls (those that are not commands)  
   0x00040000 + IDW_  
```  
  
## Comandos simples de “ajuda”  
 Há dois comandos simples de ajuda que são implementados por classes do Microsoft:  
  
-   ID\_HELP\_INDEX que é implementado por [CWinApp::OnHelpIndex](../Topic/CWinApp::OnHelpIndex.md)  
  
-   ID\_HELP\_USING que é implementado por [CWinApp::OnHelpUsing](../Topic/CWinApp::OnHelpUsing.md)  
  
 O primeiro comando mostra o índice da ajuda para o aplicativo.  O segundo mostra a ajuda do usuário no usando o programa de WinHelp.  
  
## Ajuda contextuais \(ajuda de F1\)  
 A tecla F1 é convertido em geral a um comando com uma ID de `ID_HELP` por um acelerador colocado na tabela de aceleração da janela principal do.  O comando de `ID_HELP` também pode ser gerado por um botão com uma ID de `ID_HELP` na janela principal ou na caixa de diálogo.  
  
 Independentemente de como o comando de `ID_HELP` é gerado, é roteado como um comando normal até alcançar um manipulador de comando.  Para obter mais informações sobre a arquitetura de comando\- roteamento MFC, consulte [Observação 21 técnica](../mfc/tn021-command-and-message-routing.md).  Se o aplicativo tem a ajuda habilitada, o comando de `ID_HELP` será tratado por [CWinApp::OnHelp](../Topic/CWinApp::OnHelp.md).  O objeto de aplicativo recebe a mensagem da ajuda e o roteará o comando adequadamente.  Isso é necessário porque o roteamento de comando padrão não é suficiente para determinar o contexto o mais específico.  
  
 tentativas de`CWinApp::OnHelp` de iniciar WinHelp na seguinte ordem:  
  
1.  Verificações de uma chamada ativa de `AfxMessageBox` com uma ID da ajuda  Se uma caixa de mensagem está atualmente ativo, WinHelp é iniciado com o contexto apropriado a essa caixa de mensagem.  
  
2.  Envia uma mensagem de WM\_COMMANDHELP a janela ativa.  Se essa janela não responde inicial WinHelp, a mesma mensagem será enviada nos ancestrais dessa janela até que a mensagem seja processada ou a janela atual for uma janela de nível superior.  
  
3.  Envia um comando de ID\_DEFAULT\_HELP a janela principal.  Isso invoca a ajuda padrão.  Este comando é mapeado geralmente a `CWinApp::OnHelpIndex`.  
  
 Para substituir os valores padrão global da base de ID \(por exemplo 0x10000 para comandos e 0x20000 para recursos como caixas de diálogo\), o aplicativo deve substituir [CWinApp::WinHelp](../Topic/CWinApp::WinHelp.md).  
  
 Para substituir essa funcionalidade e a maneira como um contexto da ajuda é determinado, você deve controlar a mensagem de WM\_COMMANDHELP.  Talvez você queira fornecer um roteamento mais específico de ajuda da estrutura fornece, porque ficar tão profundamente quanto a janela filho MDI atual.  Você também pode desejar fornecer uma ajuda mais específico para uma janela ou uma caixa de diálogo específico, talvez com base no estado interno atual desse objeto ou o controle ativa dentro da caixa de diálogo.  
  
## WM\_COMMANDHELP  
  
```  
  
afx_msg LRESULT CWnd::OnCommandHelp(WPARAM wParam, LPARAM lParam)  
```  
  
 WM\_COMMANDHELP é uma mensagem privada MFC do windows que seja recebida pela janela ativa quando a ajuda for solicitada.  Quando a janela recebe essa mensagem, pode chamar com `CWinApp::WinHelp` contexto que corresponde ao estado interno da janela.  
  
 `lParam`  
 Contém o contexto disponível atualmente da ajuda.  `lParam` será nulo se nenhum contexto da ajuda foi determinado.  Uma implementação de `OnCommandHelp` pode usar o ID do contexto em `lParam` para determinar um contexto diferente ou pode apenas passá\-lo para `CWinApp::WinHelp`.  
  
 `wParam`  
 Não é usado e será zero.  
  
 Se as chamadas de função `CWinApp::WinHelp`de `OnCommandHelp` , ele retornará `TRUE`.  Retornar `TRUE` para roteamento desse comando a outras classes e outras o windows.  
  
## Modo de ajuda \(ajuda Shift\+F1\)  
 Este é o segundo formulário de ajuda contextual.  Geralmente, esse modo é conectado ao pressionar SHIFT\+F1 ou através do menu\/barra de ferramentas.  É implementado como um comando \(**ID\_CONTEXT\_HELP**\).  O gancho de filtro de mensagem não será usado para converter esse comando quando uma caixa de diálogo modal ou um menu é ativa, consequentemente este comando está disponível somente para o usuário quando o aplicativo está executando a bomba principal da mensagem \(`CWinApp::Run`\).  
  
 Depois de entrada nesse modo, o cursor do mouse da ajuda é exibido em todas as áreas de aplicativo, mesmo se o aplicativo exibiria normalmente seu próprio cursor para aquela área \(como a borda de dimensionamento em torno da janela\).  O usuário pode usar o mouse ou o teclado para selecionar um comando.  Em vez de executar o comando, a ajuda nesse comando é exibida.  Além disso, o usuário pode clicar em um objeto visível na tela, como um botão na barra de ferramentas, e a ajuda será exibida para esse objeto.  Este modo de ajuda é fornecido por `CWinApp::OnContextHelp`.  
  
 Durante a execução desse loop, qualquer entrada de teclado estiver inativa, com exceção de chaves que acessam o menu.  Além disso, a tradução de comando é executado ainda por meio de `PreTranslateMessage` para permitir que o usuário pressione uma tecla de aceleração e recebe a ajuda no comando.  
  
 Se houver traduções específicos ou as ações que ocorrem em `PreTranslateMessage` funções que não deveria ocorrer durante o modo de ajuda SHIFT\+F1, você deve verificar o membro de `m_bHelpMode` de `CWinApp` antes de executar essas operações.  A implementação de `CDialog` de `PreTranslateMessage` marca essa antes de chamar `IsDialogMessage`, por exemplo.  Isso desabilita de “chaves de navegação caixa de diálogo” em caixas de diálogo modeless durante o modo SHIFT\+F1.  Além disso, `CWinApp::OnIdle` ainda será chamado durante esse loop.  
  
 Se o usuário escolher um comando no menu, será tratado como a ajuda no comando \(com **WM\_COMMANDHELP**, consulte abaixo\).  Se o usuário clicar em uma área visível da janela de aplicativos, uma determinação será feita se for um clique de nonclient ou clicar no cliente.  mapeamento das alças de`OnContextHelp` de cliques de nonclient ao cliente automaticamente clique em.  Se for um clique do cliente, então envia **WM\_HELPHITTEST** a janela que foi clicada.  Se essa janela retorna um valor diferente de zero, esse valor será usado como o contexto da ajuda.  Se retornar zero, `OnContextHelp` tentar a janela pai \(e falhar isso, seu pai, e assim por diante\).  Se um contexto da ajuda não pode ser determinado, a opção é enviar um comando de **ID\_DEFAULT\_HELP** a janela principal, que geralmente em \(\) é mapeada para `CWinApp::OnHelpIndex`.  
  
## WM\_HELPHITTEST  
  
```  
  
afx_msg LRESULT CWnd::OnHelpHitTest(  
WPARAM, LPARAM lParam)  
```  
  
 **WM\_HELPHITTEST** é uma mensagem privada do windows MFC que é recebida pela janela ativa clicada durante o modo de ajuda SHIFT\+F1.  Quando a janela recebe essa mensagem, retorna a ID da ajuda DWORD para o uso de WinHelp.  
  
 LOWORD \(lParam\)  
 contém a coordenada de dispositivo do eixo x onde o mouse foi clicada em relação à área do cliente da janela.  
  
 HIWORD \(lParam\)  
 contém a coordenada do eixo y.  
  
 `wParam`  
 não é usado e será zero.  Se o valor de retorno for diferente de zero, WinHelp é chamado com esse contexto.  Se o valor de retorno for zero, a janela pai é consultada para obter ajuda.  
  
 Em muitos casos, você pode aproveitar o código de ocorrência\- teste você já pode ter.  Consulte a implementação de **CToolBar::OnHelpHitTest** para obter um exemplo de lidar com a mensagem de **WM\_HELPHITTEST** \(a intensidade de alternância de código o código de ocorrência\- teste usado nos botões e em dicas de ferramenta em `CControlBar`\).  
  
## Suporte do assistente de aplicativo MFC e MAKEHM  
 O assistente de aplicativo MFC cria os arquivos necessários para criar um arquivo de ajuda \(arquivos de .cnt e de .hpj\).  Também inclui um número de arquivos de prebuilt .rtf aceitos pelo compilador de ajuda do Microsoft.  Muitos dos tópicos estão cheios, mas algumas podem precisar ser alterado para seu aplicativo específico.  
  
 A criação automática de “de um arquivo de mapeamento a ajuda” é suportada por um utilitário chamado MAKEHM.  O utilitário de MAKEHM pode traduzir o arquivo de RESOURCE.H de um aplicativo para um arquivo de mapeamento da ajuda.  Por exemplo:  
  
```  
#define IDD_MY_DIALOG   2000  
#define ID_MY_COMMAND   150  
```  
  
 será convertido em:  
  
```  
HIDD_MY_DIALOG    0x207d0  
HID_MY_COMMAND    0x10096  
```  
  
 Esse formato é compatível com facilidade de compilador da ajuda, que mapeia os IDs de contexto \(os números à direita\) com nomes do tópico nos símbolos \(esquerdo\).  
  
 O código\-fonte de MAKEHM está disponível em utilitários [MAKEHM](../top/visual-cpp-samples.md)de exemplo de programação de MFC.  
  
## Adicionando suporte da ajuda depois de executar o assistente de aplicativo MFC  
 A melhor maneira de adicionar a ajuda para o seu aplicativo é verificar a opção “da ajuda contextuais” na página de recursos avançados do assistente de aplicativo MFC antes de criar seu aplicativo.  Essa maneira o assistente de aplicativo MFC adiciona automaticamente entradas necessárias ao `CWinApp`\- classe derivada da mensagem à ajuda de suporte.  
  
## Ajuda na caixa de mensagem  
 A ajuda na caixa de mensagem \(alertas às vezes chamado\) tem suporte através da função de `AfxMessageBox` , um wrapper para a API de `MessageBox` .  
  
 Há duas versões de `AfxMessageBox`, um para uso com uma ID de cadeia de caracteres e outros para uso com um ponteiro`LPCSTR`: string \(\)  
  
```  
int AFXAPI AfxMessageBox(LPCSTR lpszText, UINT nType, UINT nIDHelp);  
int AFXAPI AfxMessageBox(UINT nIDPrompt, UINT nType, UINT nIDHelp);  
```  
  
 Em ambos os casos, há uma ID opcional da ajuda  
  
 As primeiras caixas, a opção para o nIDHelp é 0, que indica nenhuma ajuda da caixa de mensagem.  Se o usuário pressione F1 quando como a caixa de mensagem estiver ativa, o usuário não receberá ajuda \(mesmo se a ajuda da suporte de aplicativo\).  Se isso não é desejável, uma ID da ajuda deve ser fornecido para o nIDHelp.  
  
 Na segunda caixas, o valor padrão para o nIDHelp é \-1, indicando que o ID da ajuda é o mesmo que o nIDPrompt.  A ajuda só funcionará se o aplicativo Ajuda\- estiver habilitado, naturalmente\).  Você deve fornecer 0 para o nIDHelp se você deseja que a caixa de mensagem não tem suporte da ajuda.  Se você quiser ajuda a mensagem a ser habilitada, mas desejar uma ID diferente da ajuda do nIDPrompt, basta fornecer um valor positivo para o nIDHelp diferente de aquele de nIDPrompt.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)