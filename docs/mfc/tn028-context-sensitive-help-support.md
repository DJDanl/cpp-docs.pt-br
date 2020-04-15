---
title: 'TN028: suporte à ajuda contextual'
ms.date: 11/04/2016
f1_keywords:
- vc.help
helpviewer_keywords:
- context-sensitive Help [MFC], MFC applications
- TN028
- resource identifiers, context-sensitive Help
ms.assetid: 884f1c55-fa27-4d4c-984f-30907d477484
ms.openlocfilehash: 502edc837d7886dd60ab5107fb194c1490a76928
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370323"
---
# <a name="tn028-context-sensitive-help-support"></a>TN028: suporte à ajuda contextual

Esta nota descreve as regras para atribuir IDs de contextos de ajuda e outros problemas de ajuda no MFC. O suporte de ajuda sensível ao contexto requer o compilador de ajuda disponível no Visual C++.

> [!NOTE]
> Além de implementar ajuda sensível ao contexto usando o WinHelp, o MFC também suporta o uso da Ajuda HTML. Para obter mais informações sobre este suporte e programação com ajuda HTML, consulte [AJUDA HTML: Ajuda sensível ao contexto para seus programas](../mfc/html-help-context-sensitive-help-for-your-programs.md).

## <a name="types-of-help-supported"></a>Tipos de ajuda suportadas

Existem dois tipos de ajuda sensível ao contexto implementados em aplicativos windows. O primeiro, conhecido como "F1 Help", envolve o lançamento do WinHelp com o contexto apropriado com base no objeto ativo atualmente. O segundo é o modo "Shift+ F1". Neste modo, o cursor do mouse muda para o cursor de ajuda, e o usuário passa a clicar em um objeto. Nesse ponto, o WinHelp é lançado para dar ajuda ao objeto em que o usuário clicou.

As Classes da Microsoft Foundation implementam essas duas formas de ajuda. Além disso, o framework suporta dois comandos de ajuda simples, Índice de ajuda e uso de ajuda.

## <a name="help-files"></a>Arquivos de Ajuda

As classes da Microsoft Foundation assumem um único arquivo de Ajuda. Esse arquivo de Ajuda deve ter o mesmo nome e caminho do aplicativo. Por exemplo, se o executável for C:\MyApplication\MyHelp.exe, o arquivo de ajuda deve ser C:\MyApplication\MyHelp.hlp. Você define o caminho através da variável membro *m_pszHelpFilePath* da [Classe CWinApp](../mfc/reference/cwinapp-class.md).

## <a name="help-context-ranges"></a>Alcances de contexto de ajuda

A implementação padrão do MFC requer que um programa siga algumas regras sobre a atribuição de IDs de contexto de ajuda. Essas regras são uma série de IDs alocados para controles específicos. Você pode substituir essas regras fornecendo diferentes implementações das várias funções de membros relacionadas à Ajuda.

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

## <a name="simple-help-commands"></a>Comandos simples de "Ajuda"

Existem dois comandos de ajuda simples que são implementados pelo Microsoft Foundation Classes:

- ID_HELP_INDEX que é implementado pelo [CWinApp::OnHelpIndex](../mfc/reference/cwinapp-class.md#onhelpindex)

- ID_HELP_USING que é implementado pelo [CWinApp::OnHelpUsing](../mfc/reference/cwinapp-class.md#onhelpusing)

O primeiro comando mostra o índice de ajuda para o aplicativo. A segunda mostra a ajuda do usuário ao usar o programa WinHelp.

## <a name="context-sensitive-help-f1-help"></a>Ajuda sensível ao contexto (Ajuda à F1)

A tecla F1 é geralmente traduzida para um comando com um ID de ID_HELP por um acelerador colocado na mesa do acelerador da janela principal. O comando ID_HELP também pode ser gerado por um botão com um ID de ID_HELP na janela principal ou caixa de diálogo.

Independentemente de como o comando ID_HELP é gerado, ele é roteado como um comando normal até chegar a um manipulador de comando. Para obter mais informações sobre a arquitetura de roteamento de comandos MFC, consulte a [Nota Técnica 21](../mfc/tn021-command-and-message-routing.md). Se o aplicativo tiver ajuda ativada, o comando ID_HELP será tratado pelo [CWinApp::OnHelp](../mfc/reference/cwinapp-class.md#onhelp). O objeto do aplicativo recebe a mensagem de ajuda e, em seguida, encaminha o comando apropriadamente. Isso é necessário, uma vez que o roteamento de comando padrão não é adequado para determinar o contexto mais específico.

`CWinApp::OnHelp`tentativas de iniciar o WinHelp na seguinte ordem:

1. Verifica se `AfxMessageBox` há uma chamada ativa com uma identificação de ajuda. Se uma caixa de mensagens estiver ativa no momento, o WinHelp será lançado com o contexto apropriado para essa caixa de mensagens.

1. Envia uma mensagem WM_COMMANDHELP para a janela ativa. Se essa janela não responder lançando o WinHelp, a mesma mensagem será enviada aos ancestrais dessa janela até que a mensagem seja processada ou a janela atual seja uma janela de nível superior.

1. Envia um comando ID_DEFAULT_HELP para a janela principal. Isso invoca a ajuda padrão. Este comando é geralmente `CWinApp::OnHelpIndex`mapeado para .

Para substituir globalmente os valores básicos de ID padrão (por exemplo, 0x10000 para comandos e 0x20000 para recursos como diálogos), o aplicativo deve substituir [cWinApp::WinHelp](../mfc/reference/cwinapp-class.md#winhelp).

Para substituir essa funcionalidade e a forma como um contexto de Ajuda é determinado, você deve lidar com a mensagem WM_COMMANDHELP. Você pode querer fornecer um roteamento de ajuda mais específico do que a estrutura fornece, pois ele só vai tão fundo quanto a janela de criança SmDI atual. Você também pode querer fornecer ajuda mais específica para uma determinada janela ou diálogo, talvez com base no estado interno atual desse objeto ou no controle ativo dentro da caixa de diálogo.

## <a name="wm_commandhelp"></a>WM_COMMANDHELP

```

afx_msg LRESULT CWnd::OnCommandHelp(WPARAM wParam, LPARAM lParam)
```

WM_COMMANDHELP é uma mensagem privada do Windows MFC que é recebida pela janela ativa quando a Ajuda é solicitada. Quando a janela recebe esta `CWinApp::WinHelp` mensagem, ela pode ligar com contexto que corresponda ao estado interno da janela.

*lParam*<br/>
Contém o contexto de Ajuda disponível no momento. *iParam* é zero se nenhum contexto de ajuda foi determinado. Uma implementação pode usar o ID de `OnCommandHelp` contexto no *iParam* `CWinApp::WinHelp`para determinar um contexto diferente ou pode simplesmente passá-lo para .

*wParam*<br/>
Não é usado e será zero.

Se `OnCommandHelp` a `CWinApp::WinHelp`função chamar, ela deve retornar **TRUE**. O retorno **de TRUE** interrompe o roteamento deste comando para outras classes e para outras janelas.

## <a name="help-mode-shiftf1-help"></a>Modo de ajuda (Ajuda Shift+F1)

Esta é a segunda forma de ajuda sensível ao contexto. Geralmente, este modo é inserido pressionando SHIFT+F1 ou através do menu/barra de ferramentas. É implementado como um comando (ID_CONTEXT_HELP). O gancho de filtro de mensagem não é usado para traduzir este comando enquanto uma caixa de diálogo modal ou`CWinApp::Run`menu está ativo, portanto, este comando só está disponível para o usuário quando o aplicativo estiver executando a bomba de mensagem principal ().

Depois de entrar nesse modo, o cursor do mouse Help é exibido em todas as áreas do aplicativo, mesmo que o aplicativo normalmente exiba seu próprio cursor para essa área (como a borda de dimensionamento ao redor da janela). O usuário pode usar o mouse ou teclado para selecionar um comando. Em vez de executar o comando, a ajuda nesse comando é exibida. Além disso, o usuário pode clicar em um objeto visível na tela, como um botão na barra de ferramentas, e a Ajuda será exibida para esse objeto. Este modo de Ajuda `CWinApp::OnContextHelp`é fornecido por .

Durante a execução deste loop, toda a entrada do teclado está inativa, exceto as teclas que acessam o menu. Além disso, a tradução `PreTranslateMessage` de comando ainda é realizada via para permitir que o usuário pressione uma tecla do acelerador e receba ajuda nesse comando.

Se houver traduções ou ações específicas `PreTranslateMessage` ocorrendo na função que não deve ocorrer durante o modo `CWinApp` SHIFT+F1 Help, você deve verificar o *m_bHelpMode* membro antes de realizar essas operações. A `CDialog` implementação de `PreTranslateMessage` `IsDialogMessage`verificações isso antes de chamar , por exemplo. Isso desativa as teclas de "navegação de diálogo" nas diálogos de modelagem durante o modo SHIFT+F1. Além disso, `CWinApp::OnIdle` ainda é chamado durante este loop.

Se o usuário escolher um comando no menu, ele será tratado como ajuda nesse comando (através de WM_COMMANDHELP, veja abaixo). Se o usuário clicar em uma área visível da janela de aplicativos, uma determinação será feita sobre se é um clique não cliente ou um clique do cliente. `OnContextHelp`lida com o mapeamento de cliques não clientes para cliques do cliente automaticamente. Se for um clique do cliente, ele envia uma WM_HELPHITTEST para a janela que foi clicada. Se essa janela retornar um valor não zero, esse valor será usado como contexto de ajuda. Se ele retornar `OnContextHelp` zero, tente a janela pai (e falhando nisso, seu pai, e assim por diante). Se um contexto de Ajuda não puder ser determinado, o padrão é enviar um comando `CWinApp::OnHelpIndex`ID_DEFAULT_HELP para a janela principal, que é então (geralmente) mapeada para .

## <a name="wm_helphittest"></a>Wm_helphittest

```

afx_msg LRESULT CWnd::OnHelpHitTest(
WPARAM, LPARAM lParam)
```

WM_HELPHITTEST é uma mensagem de Windows privada MFC que é recebida pela janela ativa clicada durante o modo SHIFT+F1 Help. Quando a Janela recebe essa mensagem, ela retorna um **DWORD** Help ID para uso do WinHelp.

LOWORD(lParam) contém a coordenada do dispositivo de eixo X onde o mouse foi clicado em relação à área cliente da janela.

HIWORD(lParam) contém a coordenada do eixo Y.

*wParam*<br/>
não é usado e será zero. Se o valor de retorno não for zero, o WinHelp será chamado com esse contexto. Se o valor de retorno for zero, a janela pai será consultada por ajuda.

Em muitos casos, você pode aproveitar o código de teste de hit que você já pode ter. Veja a `CToolBar::OnHelpHitTest` implementação de um exemplo de manipulação da mensagem WM_HELPHITTEST (o código aproveita `CControlBar`o código de teste de hit usado em botões e dicas de ferramentas em ).

## <a name="mfc-application-wizard-support-and-makehm"></a>Suporte ao assistente de aplicativos do MFC e MAKEHM

O MFC Application Wizard cria os arquivos necessários para criar um arquivo de Ajuda (arquivos .cnt e .hpj). Ele também inclui uma série de arquivos .rtf pré-construídos que são aceitos pelo Microsoft Help Compiler. Muitos dos tópicos estão completos, mas alguns podem precisar ser modificados para sua aplicação específica.

A criação automática de um arquivo de "mapeamento de ajuda" é suportada por um utilitário chamado MAKEHM. O utilitário MAKEHM pode traduzir o RECURSO de um aplicativo. Arquivo H para um arquivo de mapeamento de ajuda. Por exemplo:

```
#define IDD_MY_DIALOG   2000
#define ID_MY_COMMAND   150
```

serão traduzidos em:

```
HIDD_MY_DIALOG    0x207d0
HID_MY_COMMAND    0x10096
```

Este formato é compatível com a facilidade do compilador Ajuda, que mapeia IDs de contexto (os números do lado direito) com nomes de tópicos (os símbolos do lado esquerdo).

O código-fonte do MAKEHM está disponível na amostra [MAKEHM](../overview/visual-cpp-samples.md).

## <a name="adding-help-support-after-running-the-mfc-application-wizard"></a>Adicionando suporte de ajuda depois de executar o assistente de aplicativo do MFC

A melhor maneira de adicionar ajuda ao seu aplicativo é verificar a opção "Ajuda sensível ao contexto" na página Recursos Avançados do Assistente de Aplicativos Do MFC antes de criar seu aplicativo. Dessa forma, o MFC Application Wizard adiciona automaticamente `CWinApp`as entradas de mapa de mensagem necessárias à sua classe derivada para suportar ajuda.

## <a name="help-on-message-boxes"></a>Ajuda em caixas de mensagens

Help on Message Boxes (às vezes chamados `AfxMessageBox` de alertas) é `MessageBox` suportado através da função, um invólucro para a API do Windows.

Existem duas `AfxMessageBox`versões de , uma para uso com um ID de seqüência de string e outra para uso com um ponteiro para string (`LPCSTR`):

```
int AFXAPI AfxMessageBox(LPCSTR lpszText,
    UINT nType,
    UINT nIDHelp);

int AFXAPI AfxMessageBox(UINT nIDPrompt,
    UINT nType,
    UINT nIDHelp);
```

Em ambos os casos, há um ID de ajuda opcional.

No primeiro caso, o padrão para nIDHelp é 0, o que indica nenhuma ajuda para esta caixa de mensagem. Se o usuário pressionar f1 enquanto tal caixa de mensagem estiver ativa, o usuário não receberá ajuda (mesmo que o aplicativo suporte ajuda). Se isso não for desejável, um ID de ajuda deve ser fornecido para nIDHelp.

No segundo caso, o valor padrão para nIDHelp é -1, o que indica que o ID de ajuda é o mesmo que nIDPrompt. A ajuda só funcionará se o aplicativo estiver habilitado para ajuda, é claro). Você deve fornecer 0 para nIDHelp se desejar que a caixa de mensagens não tenha suporte de ajuda. Se você quiser que a mensagem seja ativada, mas deseje um ID de ajuda diferente do nIDPrompt, basta fornecer um valor positivo para nIDHelp diferente do nIDPrompt.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
