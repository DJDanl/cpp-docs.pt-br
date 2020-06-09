---
title: Manipulando notificações de personalização
ms.date: 11/04/2016
f1_keywords:
- TBN_CUSTHELP
- TBN_QUERYINSERT
- TBNOTIFY
- NMHDR
- TBN_TOOLBARCHANGE
- TBN_ENDDRAG
- NM_SETFOCUS
- TBN_RESET
- NM_RETURN
- NM_ENDWAIT
- NM_STARTWAIT
- TBN_BEGINDRAG
- NM_OUTOFMEMORY
- TBN_QUERYDELETE
- NM_DBLCLK
- TBN_ENDADJUST
- NM_KILLFOCUS
- NM_RCLICK
- TBN_BEGINADJUST
- NM_CLICK
helpviewer_keywords:
- TBN_ENDADJUST notification [MFC]
- TBNOTIFY notification [MFC]
- TBN_BEGINDRAG notification [MFC]
- TBN_TOOLBARCHANGE notification [MFC]
- NM_CLICK notification [MFC]
- NM_RETURN notification [MFC]
- NM_RCLICK notification [MFC]
- TBN_ENDDRAG notification [MFC]
- TBN_BEGINADJUST notification [MFC]
- NM_ENDWAIT notification [MFC]
- NM_KILLFOCUS notification [MFC]
- NM_SETFOCUS notification [MFC]
- NM_OUTOFMEMORY notification [MFC]
- TBN_QUERYINSERT notification [MFC]
- NMHDR [MFC]
- NM_STARTWAIT notification [MFC]
- CToolBarCtrl class [MFC], handling notifications
- TBN_CUSTHELP notification [MFC]
- TBN_RESET notification [MFC]
- NM_DBLCLK notification [MFC]
- TBN_QUERYDELETE notification [MFC]
- NM_RDBLCLK notification [MFC]
- TBN_GETBUTTONINFO notification [MFC]
ms.assetid: 219ea08e-7515-4b98-85cb-47120f08c0a2
ms.openlocfilehash: d88e1efe12fd5b31a9f78b8fe439ba1aefa72d1e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625721"
---
# <a name="handling-customization-notifications"></a>Manipulando notificações de personalização

Um controle comum de barra de ferramentas do Windows tem recursos de personalização internos, incluindo uma caixa de diálogo de personalização definida pelo sistema, que permite ao usuário inserir, excluir ou reorganizar botões da barra de ferramentas. O aplicativo determina se os recursos de personalização estão disponíveis e controla a extensão na qual o usuário pode personalizar a barra de ferramentas.

Você pode disponibilizar esses recursos de personalização para o usuário, dando à barra de ferramentas o estilo de **CCS_ADJUSTABLE** . Os recursos de personalização permitem que o usuário arraste um botão para uma nova posição ou remova um botão arrastando-o para fora da barra de ferramentas. Além disso, o usuário pode clicar duas vezes na barra de ferramentas para exibir a caixa de diálogo **Personalizar barra de ferramentas** , que permite ao usuário adicionar, excluir e reorganizar botões da barra de ferramentas. O aplicativo pode exibir a caixa de diálogo usando a função [Personalizar](reference/ctoolbarctrl-class.md#customize) membro.

O controle Toolbar envia mensagens de notificação para a janela pai em cada etapa do processo de personalização. Se o usuário mantiver a tecla SHIFT pressionada e começar a arrastar um botão, a barra de ferramentas manipulará automaticamente a operação de arrastar. A barra de ferramentas envia a mensagem de notificação **TBN_QUERYDELETE** para a janela pai para determinar se o botão pode ser excluído. A operação de arrastar terminará se a janela pai retornar **false**. Caso contrário, a barra de ferramentas captura a entrada do mouse e aguarda o usuário liberar o botão do mouse.

Quando o usuário libera o botão do mouse, o controle ToolBar determina o local do cursor do mouse. Se o cursor estiver fora da barra de ferramentas, o botão será excluído. Se o cursor estiver em outro botão da barra de ferramentas, a barra de ferramentas enviará a mensagem de notificação **TBN_QUERYINSERT** para a janela pai para determinar se um botão pode ser inserido à esquerda do botão fornecido. O botão será inserido se a janela pai retornar **true**; caso contrário, não é. A barra de ferramentas envia a mensagem de notificação **TBN_TOOLBARCHANGE** para sinalizar o fim da operação de arrastar.

Se o usuário iniciar uma operação de arrastar sem manter a tecla SHIFT pressionada, o controle Toolbar enviará a mensagem de notificação **TBN_BEGINDRAG** para a janela do proprietário. Um aplicativo que implementa seu próprio código de arrastar botão pode usar essa mensagem como um sinal para iniciar uma operação de arrastar. A barra de ferramentas envia a mensagem de notificação **TBN_ENDDRAG** para sinalizar o fim da operação de arrastar.

Um controle de barra de ferramentas envia mensagens de notificação quando o usuário personaliza uma barra de ferramentas usando a caixa de diálogo **Personalizar barra de ferramentas** . A barra de ferramentas envia a mensagem de notificação **TBN_BEGINADJUST** depois que o usuário clica duas vezes na barra de ferramentas, mas antes de a caixa de diálogo ser criada. Em seguida, a barra de ferramentas começa a enviar uma série de **TBN_QUERYINSERT** mensagens de notificação para determinar se a barra de ferramentas permite que os botões sejam inseridos. Quando a janela pai retorna **true**, a barra de ferramentas para de enviar **TBN_QUERYINSERT** mensagens de notificação. Se a janela pai não retornar **true** para qualquer botão, a barra de ferramentas destruirá a caixa de diálogo.

Em seguida, o controle ToolBar determina se os botões podem ser excluídos da barra de ferramentas enviando uma mensagem de notificação **TBN_QUERYDELETE** para cada botão na barra de ferramentas. A janela pai retorna **true** para indicar que um botão pode ser excluído; caso contrário, retornará **false**. A barra de ferramentas adiciona todos os botões da barra de ferramentas à caixa de diálogo, mas cinza os que não podem ser excluídos.

Sempre que o controle Toolbar precisar de informações sobre um botão na caixa de diálogo Personalizar barra de ferramentas, ele enviará a mensagem de notificação **TBN_GETBUTTONINFO** , especificando o índice do botão para o qual ele precisa de informações e o endereço de uma estrutura **TBNOTIFY** . A janela pai deve preencher a estrutura com as informações relevantes.

A caixa de diálogo **Personalizar barra de ferramentas** inclui um botão ajuda e um botão redefinir. Quando o usuário escolhe o botão ajuda, o controle barra de ferramentas envia a mensagem de notificação **TBN_CUSTHELP** . A janela pai deve responder exibindo informações de ajuda. A caixa de diálogo envia a mensagem de notificação **TBN_RESET** quando o usuário seleciona o botão redefinir. Essa mensagem sinaliza que a barra de ferramentas está prestes a reinicializar a caixa de diálogo.

Essas mensagens são todas **WM_NOTIFY** mensagens e podem ser manipuladas em sua janela do proprietário adicionando entradas de mapa de mensagens do seguinte formulário ao mapa de mensagens da sua janela do proprietário:

```cpp
ON_NOTIFY( wNotifyCode, idControl, memberFxn )
```

- **wNotifyCode**

   Código de identificador de mensagem de notificação, como **TBN_BEGINADJUST**.

- **idControl**

   O identificador do controle que envia a notificação.

- **memberFxn**

   A função de membro a ser chamada quando essa notificação é recebida.

Sua função de membro seria declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn( NMHDR * pNotifyStruct, LRESULT * result );
```

Se o manipulador de mensagens de notificação retornar um valor, ele deverá colocá-lo no **LRESULT** apontado por *resultado*.

Para cada mensagem, `pNotifyStruct` aponta para uma estrutura **NMHDR** ou uma estrutura **TBNOTIFY** . Essas estruturas são descritas abaixo:

A estrutura **NMHDR** contém os seguintes membros:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;  // handle of control sending message
    UINT idFrom;// identifier of control sending message
    UINT code;  // notification code; see below
} NMHDR;
```

- **hwndFrom**

   Identificador de janela do controle que está enviando a notificação. Para converter esse identificador em um `CWnd` ponteiro, use [CWnd:: FromHandle](reference/cwnd-class.md#fromhandle).

- **idFrom**

   Identificador do controle que envia a notificação.

- **code**

   Código de notificação. Esse membro pode ser um valor específico de um tipo de controle, como **TBN_BEGINADJUST** ou **TTN_NEEDTEXT**, ou pode ser um dos valores de notificação comuns listados abaixo:

  - **NM_CLICK** O usuário clicou com o botão esquerdo do mouse dentro do controle.

  - **NM_DBLCLK** O usuário clicou duas vezes com o botão esquerdo do mouse dentro do controle.

  - **NM_KILLFOCUS** O controle perdeu o foco de entrada.

  - **NM_OUTOFMEMORY** O controle não pôde concluir uma operação porque não há memória suficiente disponível.

  - **NM_RCLICK** O usuário clicou com o botão direito do mouse dentro do controle.

  - **NM_RDBLCLK** O usuário clicou duas vezes com o botão direito do mouse dentro do controle.

  - **NM_RETURN** O controle tem o foco de entrada e o usuário pressionou a tecla ENTER.

  - **NM_SETFOCUS** O controle recebeu o foco de entrada.

A estrutura **TBNOTIFY** contém os seguintes membros:

```cpp
typedef struct {
    NMHDR hdr; // information common to all WM_NOTIFY messages
    int iItem; // index of button associated with notification
    TBBUTTON tbButton; // info about button associated withnotification
    int cchText;   // count of characters in button text
    LPSTR lpszText;// address of button text
} TBNOTIFY, FAR* LPTBNOTIFY;
```

- **HDR**

   Informações comuns a todas as mensagens de **WM_NOTIFY** .

- **iItem**

   Índice do botão associado à notificação.

- **tbButton**

   Estrutura **TBBUTTON** que contém informações sobre o botão da barra de ferramentas associado à notificação.

- **cchText**

   Contagem de caracteres no texto do botão.

- **lpszText**

   Ponteiro para texto do botão.

As notificações que a barra de ferramentas envia são as seguintes:

- **TBN_BEGINADJUST**

   Enviado quando o usuário começa a personalizar um controle da barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a notificação. O manipulador não precisa retornar nenhum valor específico.

- **TBN_BEGINDRAG**

   Enviado quando o usuário começa a arrastar um botão em um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY** . O membro **iItem** contém o índice de base zero do botão que está sendo arrastado. O manipulador não precisa retornar nenhum valor específico.

- **TBN_CUSTHELP**

   Enviado quando o usuário escolhe o botão ajuda na caixa de diálogo Personalizar barra de ferramentas. Sem valor de retorno. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar nenhum valor específico.

- **TBN_ENDADJUST**

   Enviado quando o usuário para de personalizar um controle ToolBar. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar nenhum valor específico.

- **TBN_ENDDRAG**

   Enviado quando o usuário para de arrastar um botão em um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY** . O membro **iItem** contém o índice de base zero do botão que está sendo arrastado. O manipulador não precisa retornar nenhum valor específico.

- **TBN_GETBUTTONINFO**

   Enviado quando o usuário está Personalizando um controle de barra de ferramentas. A barra de ferramentas usa essa mensagem de notificação para recuperar as informações necessárias para a caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY** . O membro **iItem** especifica o índice de base zero de um botão. Os membros **pszText** e **cchText** especificam o endereço e o comprimento, em caracteres, do texto do botão atual. Um aplicativo deve preencher a estrutura com informações sobre o botão. Retorna **true** se as informações do botão foram copiadas para a estrutura; caso contrário, **false** .

- **TBN_QUERYDELETE**

   Enviado enquanto o usuário está Personalizando uma barra de ferramentas para determinar se um botão pode ser excluído de um controle ToolBar. O ponteiro aponta para uma estrutura **TBNOTIFY** . O membro **iItem** contém o índice de base zero do botão a ser excluído. Retorne **true** para permitir que o botão seja excluído ou **false** para impedir que o botão seja excluído.

- **TBN_QUERYINSERT**

   Enviado enquanto o usuário está Personalizando um controle de barra de ferramentas para determinar se um botão pode ser inserido à esquerda do botão fornecido. O ponteiro aponta para uma estrutura **TBNOTIFY** . O membro **iItem** contém o índice de base zero do botão a ser inserido. Retorne **true** para permitir que um botão seja inserido na frente do botão fornecido ou **false** para impedir que o botão seja inserido.

- **TBN_RESET**

   Enviado quando o usuário redefine o conteúdo da caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar nenhum valor específico.

- **TBN_TOOLBARCHANGE**

   Enviado depois que o usuário tiver personalizado um controle da barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar nenhum valor específico.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](using-ctoolbarctrl.md)<br/>
[Controles](controls-mfc.md)
