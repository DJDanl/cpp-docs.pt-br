---
title: 'TN028: Suporte à ajuda contextual'
ms.date: 11/04/2016
f1_keywords:
- vc.help
helpviewer_keywords:
- context-sensitive Help [MFC], MFC applications
- TN028
- resource identifiers, context-sensitive Help
ms.assetid: 884f1c55-fa27-4d4c-984f-30907d477484
ms.openlocfilehash: e3ac2742f2c57c01c645c72c933234a96ece773a
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57288279"
---
# <a name="tn028-context-sensitive-help-support"></a>TN028: Suporte à ajuda contextual

Essa observação descreve as regras de atribuição de IDs de contextos de Ajuda e outros problemas de Ajuda no MFC. Suporte à ajuda contextual exige que o compilador de Ajuda que está disponível no Visual C++.

> [!NOTE]
>  Além de implementar usando WinHelp de ajuda contextual, MFC também oferece suporte ao uso Ajuda em HTML. Para obter mais informações sobre esse suporte e a programação com a Ajuda HTML, consulte [Ajuda em HTML: Ajuda contextual para seus programas](../mfc/html-help-context-sensitive-help-for-your-programs.md).

## <a name="types-of-help-supported"></a>Tipos de ajuda com suporte

Há dois tipos de ajuda contextual, implementado em aplicativos do Windows. A primeira, chamado de "F1 Help" envolve iniciar WinHelp com o contexto apropriado com base no objeto ativo no momento. O segundo é o modo de "Shift + F1". Nesse modo, o cursor do mouse muda para o cursor de Ajuda e o usuário passa para clicar em um objeto. Nesse ponto, WinHelp é iniciado para fornecer ajuda para o objeto que o usuário clicou.

O Microsoft Foundation Classes implementam essas formas de obter ajuda. Além disso, o framework oferece suporte a dois comandos simples ajuda, índice da Ajuda e ajudar a usar.

## <a name="help-files"></a>Arquivos de Ajuda

As Microsoft Foundation classes supor que um único arquivo de Ajuda. Esse arquivo de Ajuda deve ter o mesmo nome e caminho do aplicativo. Por exemplo, se o executável é C:\MyApplication\MyHelp.exe o arquivo de Ajuda deve ser C:\MyApplication\MyHelp.hlp. Você definir o caminho por meio de *m_pszHelpFilePath* variável de membro da [classe CWinApp](../mfc/reference/cwinapp-class.md).

## <a name="help-context-ranges"></a>Intervalos de contexto de ajuda

A implementação padrão do MFC exige um programa a seguir algumas regras sobre a atribuição de IDs de contexto de Ajuda. Essas regras são um intervalo de IDs alocada a controles específicos. Você pode substituir essas regras, fornecendo implementações diferentes das várias funções de membro relacionados à Ajuda.

```
0x00000000 - 0x0000FFFF : user defined
0x00010000 - 0x0001FFFF : commands (menus/command buttons)
0x00010000 + ID_
(note: 0x18000-> 0x1FFFF is the practical range since command IDs are>=0x8000)
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

## <a name="simple-help-commands"></a>Comandos simples "Help"

Há dois comandos simples de Ajuda que são implementados pela Microsoft Foundation Classes:

- ID_HELP_INDEX que é implementada pela [CWinApp::OnHelpIndex](../mfc/reference/cwinapp-class.md#onhelpindex)

- ID_HELP_USING que é implementada pela [CWinApp::OnHelpUsing](../mfc/reference/cwinapp-class.md#onhelpusing)

O primeiro comando mostra o índice da Ajuda para o aplicativo. O segundo mostra a Ajuda do usuário sobre como usar o programa WinHelp.

## <a name="context-sensitive-help-f1-help"></a>Ajuda contextual (Ajuda de F1)

A tecla F1 é geralmente traduzida para um comando com uma ID de ID_HELP por um acelerador colocado na tabela de aceleradores da janela principal. O comando ID_HELP também pode ser gerado por um botão com uma ID de ID_HELP na caixa de diálogo ou janela principal.

Independentemente de como o comando ID_HELP é gerado, ele será encaminhado como um comando normal até atingir um manipulador de comandos. Para obter mais informações sobre a arquitetura de roteamento de comando do MFC, consulte [21 de observação técnica](../mfc/tn021-command-and-message-routing.md). Se o aplicativo tiver ajuda habilitada, o comando ID_HELP será manipulado pelo [CWinApp::OnHelp](../mfc/reference/cwinapp-class.md#onhelp). O objeto de aplicativo recebe a mensagem de Ajuda e, em seguida, encaminha o comando adequadamente. Isso é necessário, pois o roteamento de comando padrão não é adequado para determinar o contexto mais específico.

`CWinApp::OnHelp` tenta iniciar WinHelp na seguinte ordem:

1. Verifica se há um ativo `AfxMessageBox` chamada com uma ID da Ajuda. Se uma caixa de mensagem estiver atualmente ativa, WinHelp é iniciado com o contexto apropriado para essa caixa de mensagem.

1. Envia uma mensagem WM_COMMANDHELP para a janela ativa. Se essa janela não responder iniciando WinHelp, a mesma mensagem, em seguida, é enviada para os ancestrais dessa janela até que a mensagem é processada ou a janela atual é uma janela de nível superior.

1. Envia um comando ID_DEFAULT_HELP à janela principal. Isso invoca a Ajuda padrão. Geralmente, esse comando é mapeado para `CWinApp::OnHelpIndex`.

Para substituir globalmente os valores de base do ID padrão (por exemplo, 0x10000 para comandos e 0x20000 para recursos, como caixas de diálogo), o aplicativo deve substituir [CWinApp::WinHelp](../mfc/reference/cwinapp-class.md#winhelp).

Para substituir essa funcionalidade e a maneira que um contexto de Ajuda é determinado, você deve tratar a mensagem WM_COMMANDHELP. Talvez você queira fornecer roteamento mais específico ajuda que fornece a estrutura, pois ele vai apenas como a janela filho MDI atual. Talvez você queira fornecer ajuda mais específica para uma janela ou caixa de diálogo, talvez com base no estado interno atual do objeto ou o controle ativo na caixa de diálogo.

## <a name="wmcommandhelp"></a>WM_COMMANDHELP

```

afx_msg LRESULT CWnd::OnCommandHelp(WPARAM wParam, LPARAM lParam)
```

WM_COMMANDHELP é uma mensagem privada do MFC do Windows que é recebida pela janela do Active Directory quando a Ajuda é solicitada. Quando a janela recebe essa mensagem, ele pode chamar `CWinApp::WinHelp` com contexto que corresponde ao estado interno da janela.

*lParam*<br/>
Contém o contexto da Ajuda está disponível. *lParam* for zero, se nenhum contexto de Ajuda tiver sido determinado. Uma implementação de `OnCommandHelp` pode usar a ID do contexto no *lParam* para determinar um contexto diferente ou pode apenas passá-lo para `CWinApp::WinHelp`.

*wParam*<br/>
Não é usado e será zero.

Se o `OnCommandHelp` chamadas de função `CWinApp::WinHelp`, ele deverá retornar **verdadeiro**. Retornando **verdadeira** interrompe o roteamento desse comando para outras classes e outras janelas.

## <a name="help-mode-shiftf1-help"></a>Modo de Ajuda (Shift + F1 Ajuda)

Isso é a segunda forma de ajuda contextual. Em geral, esse modo é inserido, pressionando SHIFT + F1 ou por meio do menu/barra de ferramentas. Ele é implementado como um comando (ID_CONTEXT_HELP). O driver de filtro de mensagem não é usado para converter esse comando durante uma caixa de diálogo modal ou menu estiver ativo, portanto, esse comando só está disponível para o usuário quando o aplicativo está em execução para a bomba de mensagem principal (`CWinApp::Run`).

Depois de inserir esse modo, o cursor do mouse ajuda é exibido sobre todas as áreas do aplicativo, mesmo se o aplicativo normalmente seria exibida para seu próprio cursor para a área (como borda de dimensionamento ao redor da janela). O usuário é capaz de usar o mouse ou teclado para selecionar um comando. Em vez de executar o comando, a Ajuda no comando que é exibida. Além disso, o usuário pode clicar em um objeto visível na tela, como um botão na barra de ferramentas e a Ajuda será exibida para esse objeto. Este modo de Ajuda é fornecido pelo `CWinApp::OnContextHelp`.

Durante a execução desse loop, todas as entrada do teclado está inativo, exceto para as chaves que acessar o menu. Além disso, a conversão de comando ainda é realizada por meio de `PreTranslateMessage` para permitir que o usuário pressione uma tecla de aceleração e obter ajuda sobre esse comando.

Se não houver específico traduções ou ações tomando colocar nas `PreTranslateMessage` função que não deve ocorrer durante o modo SHIFT + F1 Ajuda, você deve verificar a *m_bHelpMode* membro do `CWinApp` antes de executar esses operações. O `CDialog` implementací `PreTranslateMessage` verifica isso antes de chamar `IsDialogMessage`, por exemplo. Isso desabilita as chaves de "navegação de caixa de diálogo" em caixas de diálogo sem janela restrita durante o modo de SHIFT+F1. Além disso, `CWinApp::OnIdle` ainda é chamado durante esse loop.

Se o usuário escolhe um comando de menu, ele é tratado como obter ajuda sobre esse comando (por meio de WM_COMMANDHELP, veja abaixo). Se o usuário clica em uma área visível da janela de aplicativos, uma determinação é feita sobre se ele está um clique de não cliente ou um clique do cliente. `OnContextHelp` mapeamento de identificadores de não cliente clica aos cliques do cliente automaticamente. Se for um clique do cliente, ele, em seguida, envia um WM_HELPHITTEST para a janela que foi clicada. Se essa janela retorna um valor diferente de zero, esse valor é usado como o contexto para obter ajuda. Se ele retornar zero, `OnContextHelp` tenta a janela pai (e caso de falha, seu pai e assim por diante). Se um contexto de Ajuda não pode ser determinado, o padrão é enviar um comando ID_DEFAULT_HELP à janela principal, que, em seguida, (geralmente) é mapeada para `CWinApp::OnHelpIndex`.

## <a name="wmhelphittest"></a>WM_HELPHITTEST

```

afx_msg LRESULT CWnd::OnHelpHitTest(
WPARAM, LPARAM lParam)
```

WM_HELPHITTEST é uma mensagem de windows privada de MFC recebida pela janela ativa clicada durante o modo SHIFT + F1 Ajuda. Quando a janela recebe essa mensagem, ele retorna um **DWORD** identificação de ajuda para uso por WinHelp.

LOWORD (lParam) contém a coordenada de dispositivo do eixo x em que o mouse foi clicado em relação à área de cliente da janela.

HIWORD(lParam) contém a coordenada do eixo y.

*wParam*<br/>
Não é usado e será zero. Se o valor de retorno é diferente de zero, WinHelp for chamado com esse contexto. Se o valor de retorno for zero, a janela pai é consultada para obter ajuda.

Em muitos casos, você pode aproveitar o código de teste de clique que talvez você já tenha. Veja a implementação de `CToolBar::OnHelpHitTest` para obter um exemplo de lidar com a mensagem WM_HELPHITTEST (o código utiliza o código de teste de clique usado em botões e dicas de ferramenta no `CControlBar`).

## <a name="mfc-application-wizard-support-and-makehm"></a>MAKEHM e suporte ao Assistente de aplicativo do MFC

O Assistente de aplicativo do MFC cria os arquivos necessários para criar um arquivo de Ajuda (arquivos. CNT e hpj). Ele também inclui um número de arquivos. rtf predefinidos que são aceitos pelo compilador de Ajuda da Microsoft. Muitos dos tópicos forem concluídos, mas alguns talvez precise ser modificado para seu aplicativo específico.

Há suporte para a criação automática de um arquivo "help mapeamento" um utilitário chamado MAKEHM. O utilitário MAKEHM pode traduzir os recursos do aplicativo. Arquivo de H para um arquivo de mapeamento de Ajuda. Por exemplo:

```
#define IDD_MY_DIALOG   2000
#define ID_MY_COMMAND   150
```

será convertida em:

```
HIDD_MY_DIALOG    0x207d0
HID_MY_COMMAND    0x10096
```

Esse formato é compatível com o recurso de Ajuda do compilador, que mapeia as IDs de contexto (os números à direita) com nomes de tópico (os símbolos no lado esquerdo).

O código-fonte MAKEHM está disponível no exemplo utilitários de programação MFC [MAKEHM](../visual-cpp-samples.md).

## <a name="adding-help-support-after-running-the-mfc-application-wizard"></a>Adicionando suporte à Ajuda após executar o Assistente de aplicativo do MFC

É a melhor maneira de adicionar Ajuda ao seu aplicativo verificar se a opção "Ajuda contextual" na página recursos avançados do Assistente de aplicativo MFC antes de criar seu aplicativo. Dessa forma, o Assistente de aplicativo MFC adiciona automaticamente as entradas de mapa de mensagem necessário para sua `CWinApp`-derivado da classe para dar suporte à Ajuda.

## <a name="help-on-message-boxes"></a>Ajuda nas caixas de mensagem

Ajuda nas caixas de mensagem (às vezes chamado de alertas) tem suporte por meio de `AfxMessageBox` função, um wrapper para o `MessageBox` API do Windows.

Há duas versões do `AfxMessageBox`, um para uso com uma ID de cadeia de caracteres e outro para uso com um ponteiro para cadeia de caracteres (`LPCSTR`):

```
int AFXAPI AfxMessageBox(LPCSTR lpszText,
    UINT nType,
    UINT nIDHelp);

int AFXAPI AfxMessageBox(UINT nIDPrompt,
    UINT nType,
    UINT nIDHelp);
```

Em ambos os casos, há um opcional ID da Ajuda.

No primeiro caso, o padrão para nIDHelp é 0, que não indica nenhuma ajuda para essa caixa de mensagem. Se o usuário pressiona F1 enquanto, como mensagem de caixa estiver ativa, o usuário não receberá ajuda (mesmo se o aplicativo dá suporte à Ajuda). Se isso não for desejável, uma ID de Ajuda deve ser fornecido para nIDHelp.

No segundo caso, o valor padrão para nIDHelp é -1, que indica que a identificação de Ajuda é o mesmo que nIDPrompt. Ajuda funcionará apenas se o aplicativo for habilitado ajuda, é claro). Você deve fornecer 0 nIDHelp se desejar que a caixa de mensagem não tem nenhum suporte de Ajuda. Você deve a mensagem a ser ajuda habilitada, mas desejar uma ID de ajuda diferentes que nIDPrompt, simplesmente fornecer um valor positivo para nIDHelp diferente do nIDPrompt.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
