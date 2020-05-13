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
ms.openlocfilehash: 67f40d0dc50a853a39cb9b60a938d8eafe8293c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370481"
---
# <a name="handling-customization-notifications"></a>Manipulando notificações de personalização

Um controle comum da barra de ferramentas do Windows possui recursos de personalização incorporados, incluindo uma caixa de diálogo de personalização definida pelo sistema, que permite ao usuário inserir, excluir ou reorganizar botões de barra de ferramentas. O aplicativo determina se os recursos de personalização estão disponíveis e controla até que ponto o usuário pode personalizar a barra de ferramentas.

Você pode disponibilizar esses recursos de personalização para o usuário dando à barra de ferramentas o estilo **CCS_ADJUSTABLE.** Os recursos de personalização permitem que o usuário arraste um botão para uma nova posição ou para remover um botão arrastando-o para fora da barra de ferramentas. Além disso, o usuário pode clicar duas vezes na barra de ferramentas para exibir a caixa de diálogo **Personalizar barra de ferramentas,** que permite ao usuário adicionar, excluir e reorganizar botões da barra de ferramentas. O aplicativo pode exibir a caixa de diálogo usando a função [Personalizar](../mfc/reference/ctoolbarctrl-class.md#customize) membro.

O controle da barra de ferramentas envia mensagens de notificação para a janela pai em cada etapa do processo de personalização. Se o usuário segurar a tecla SHIFT e começar a arrastar um botão, a barra de ferramentas manuseia automaticamente a operação de arrasto. A barra de ferramentas envia a mensagem de notificação **TBN_QUERYDELETE** para a janela pai para determinar se o botão pode ser excluído. A operação de arrastar termina se a janela pai retornar **FALSA**. Caso contrário, a barra de ferramentas captura a entrada do mouse e espera que o usuário solte o botão do mouse.

Quando o usuário libera o botão do mouse, o controle da barra de ferramentas determina a localização do cursor do mouse. Se o cursor estiver fora da barra de ferramentas, o botão será excluído. Se o cursor estiver em outro botão da barra de ferramentas, a barra de ferramentas envia a **mensagem de** notificação TBN_QUERYINSERT para a janela pai para determinar se um botão pode ser inserido à esquerda do botão dado. O botão é inserido se a janela pai retornar **TRUE**; caso contrário, não é. A barra de ferramentas envia a mensagem de notificação **TBN_TOOLBARCHANGE** para sinalizar o fim da operação de arrasto.

Se o usuário iniciar uma operação de arrastar sem segurar a tecla SHIFT, o controle da barra de ferramentas envia a mensagem de notificação **TBN_BEGINDRAG** para a janela do proprietário. Um aplicativo que implementa seu próprio código de arrasto de botões pode usar esta mensagem como um sinal para iniciar uma operação de arrasto. A barra de ferramentas envia a mensagem de notificação **TBN_ENDDRAG** para sinalizar o fim da operação de arrasto.

Um controle da barra de ferramentas envia mensagens de notificação quando o usuário personaliza uma barra de ferramentas usando a caixa de diálogo **Personalizar barra de** ferramentas. A barra de ferramentas envia a mensagem de notificação **TBN_BEGINADJUST** após o usuário clicar duas vezes na barra de ferramentas, mas antes que a caixa de diálogo seja criada. Em seguida, a barra de ferramentas começa a enviar uma série de **mensagens** de notificação TBN_QUERYINSERT para determinar se a barra de ferramentas permite que os botões sejam inseridos. Quando a janela pai retorna **TRUE,** a barra de ferramentas pára de enviar **mensagens de** notificação TBN_QUERYINSERT. Se a janela pai não retornar **TRUE** para qualquer botão, a barra de ferramentas destruirá a caixa de diálogo.

Em seguida, o controle da barra de ferramentas determina se algum botão pode ser excluído da barra de ferramentas enviando uma **mensagem de** notificação TBN_QUERYDELETE para cada botão na barra de ferramentas. A janela pai retorna **TRUE** para indicar que um botão pode ser excluído; caso contrário, ele retorna **FALSO**. A barra de ferramentas adiciona todos os botões da barra de ferramentas à caixa de diálogo, mas cinzas aqueles que podem não ser excluídos.

Sempre que o controle da barra de ferramentas precisa de informações sobre um botão na caixa de diálogo Personalizar barra de ferramentas, ele envia a mensagem de notificação **TBN_GETBUTTONINFO,** especificando o índice do botão para o qual precisa de informações e o endereço de uma estrutura **TBNOTIFY.** A janela dos pais deve preencher a estrutura com as informações relevantes.

A caixa de diálogo **Personalizar barra de** ferramentas inclui um botão Ajuda e um botão Redefinir. Quando o usuário escolhe o botão Ajuda, o controle da barra de ferramentas envia a **mensagem de** notificação TBN_CUSTHELP. A janela pai deve responder exibindo informações de ajuda. A caixa de diálogo envia a mensagem de notificação **TBN_RESET** quando o usuário seleciona o botão Redefinir. Esta mensagem sinaliza que a barra de ferramentas está prestes a reinicializar a caixa de diálogo.

Essas mensagens são **todas WM_NOTIFY** mensagens, e podem ser manuseadas na janela do proprietário adicionando entradas de mapa de mensagem do formulário a seguir no mapa de mensagens da janela do proprietário:

```cpp
ON_NOTIFY( wNotifyCode, idControl, memberFxn )
```

- **wNotifyCode**

   Código identificador de mensagem de notificação, como **TBN_BEGINADJUST**.

- **idControl**

   O identificador do controle que envia a notificação.

- **Memberfxn**

   A função de membro a ser chamada quando esta notificação for recebida.

Sua função de membro seria declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn( NMHDR * pNotifyStruct, LRESULT * result );
```

Se o manipulador de mensagens de notificação retornar um valor, ele deve colocá-lo no **LRESULT** apontado por *resultado*.

Para cada `pNotifyStruct` mensagem, aponta para uma estrutura **NMHDR** ou uma estrutura **TBNOTIFY.** Estas estruturas estão descritas abaixo:

A estrutura **NMHDR** contém os seguintes membros:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;  // handle of control sending message
    UINT idFrom;// identifier of control sending message
    UINT code;  // notification code; see below
} NMHDR;
```

- **hwndFrom**

   Alça da janela do controle que está enviando a notificação. Para converter esta `CWnd` alça em um ponteiro, use [CWnd::FromHandle](../mfc/reference/cwnd-class.md#fromhandle).

- **Idfrom**

   Identificador do controle que envia a notificação.

- **Código**

   Código de notificação. Este membro pode ser um valor específico para um tipo de controle, como **TBN_BEGINADJUST** ou **TTN_NEEDTEXT,** ou pode ser um dos valores comuns de notificação listados abaixo:

  - **NM_CLICK.** O usuário clicou no botão esquerdo do mouse dentro do controle.

  - **NM_DBLCLK NM_DBLCLK** O usuário clicou duas vezes no botão esquerdo do mouse dentro do controle.

  - **NM_KILLFOCUS NM_KILLFOCUS** O controle perdeu o foco de entrada.

  - **NM_OUTOFMEMORY.** O controle não pôde completar uma operação porque não há memória suficiente disponível.

  - **NM_RCLICK** O usuário clicou no botão direito do mouse dentro do controle.

  - **NM_RDBLCLK NM_RDBLCLK** O usuário clicou duas vezes no botão direito do mouse dentro do controle.

  - **NM_RETURN.** O controle tem o foco de entrada, e o usuário pressionou a tecla ENTER.

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

- **Hdr**

   Informações comuns a todas as **mensagens WM_NOTIFY.**

- **Iitem**

   Índice do botão associado à notificação.

- **Tbbutton**

   **Estrutura TBBUTTON** que contém informações sobre o botão de barra de ferramentas associada à notificação.

- **cchText**

   Contagem de caracteres no texto do botão.

- **lpszText**

   Ponteiro para texto de botão.

As notificações que a barra de ferramentas envia são as seguintes:

- **Tbn_beginadjust**

   Enviado quando o usuário começa a personalizar um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a notificação. O manipulador não precisa devolver nenhum valor específico.

- **TBN_BEGINDRAG**

   Enviado quando o usuário começa a arrastar um botão em um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY.** O membro **iItem** contém o índice baseado em zero do botão que está sendo arrastado. O manipulador não precisa devolver nenhum valor específico.

- **TBN_CUSTHELP**

   Enviado quando o usuário escolhe o botão Ajudar na caixa de diálogo Personalizar barra de ferramentas. Sem valor de retorno. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa devolver nenhum valor específico.

- **TBN_ENDADJUST**

   Enviado quando o usuário pára de personalizar um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa devolver nenhum valor específico.

- **TBN_ENDDRAG**

   Enviado quando o usuário pára de arrastar um botão no controle da barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY.** O membro **iItem** contém o índice baseado em zero do botão que está sendo arrastado. O manipulador não precisa devolver nenhum valor específico.

- **TBN_GETBUTTONINFO**

   Enviado quando o usuário está personalizando um controle de barra de ferramentas. A barra de ferramentas usa esta mensagem de notificação para recuperar as informações necessárias pela caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY.** O membro **iItem** especifica o índice baseado em zero de um botão. Os membros **pszText** e **cchText** especificam o endereço e o comprimento, em caracteres, do texto do botão atual. Um aplicativo deve preencher a estrutura com informações sobre o botão. Retorne **TRUE** se as informações do botão foram copiadas para a estrutura ou FALSA soruteira de outra forma. **FALSE**

- **TBN_QUERYDELETE**

   Enviado enquanto o usuário está personalizando uma barra de ferramentas para determinar se um botão pode ser excluído de um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **TBNOTIFY.** O membro **iItem** contém o índice baseado em zero do botão a ser excluído. Retorne **TRUE** para permitir que o botão seja excluído ou **FALSO** para evitar que o botão seja excluído.

- **Tbn_queryinsert**

   Enviado enquanto o usuário está personalizando um controle da barra de ferramentas para determinar se um botão pode ser inserido à esquerda do botão dado. O ponteiro aponta para uma estrutura **TBNOTIFY.** O membro **iItem** contém o índice baseado em zero do botão a ser inserido. Retorne **TRUE** para permitir que um botão seja inserido na frente do botão dado ou **FALSE** para evitar que o botão seja inserido.

- **TBN_RESET**

   Enviado quando o usuário redefine o conteúdo da caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa devolver nenhum valor específico.

- **TBN_TOOLBARCHANGE**

   Enviado depois que o usuário personalizou um controle de barra de ferramentas. O ponteiro aponta para uma estrutura **NMHDR** que contém informações sobre a mensagem de notificação. O manipulador não precisa devolver nenhum valor específico.

## <a name="see-also"></a>Confira também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
