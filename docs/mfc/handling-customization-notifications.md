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
ms.openlocfilehash: dc34f3eaa4b085b9d8acbaf47b21cf1825627100
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62240673"
---
# <a name="handling-customization-notifications"></a>Manipulando notificações de personalização

Um controle comum de barra de ferramentas do Windows tem recursos de personalização internas, incluindo uma caixa de diálogo de personalização definida pelo sistema que permitem ao usuário inserir, excluir ou reorganizar os botões da barra de ferramentas. O aplicativo determina se os recursos de personalização disponíveis e controla a extensão para o qual o usuário pode personalizar a barra de ferramentas.

Você pode disponibilizar esses recursos de personalização para o usuário, fornecendo a barra de ferramentas do **CCS_ADJUSTABLE** estilo. Os recursos de personalização permitem ao usuário arrastar um botão para uma nova posição ou remover um botão, arrastando-o da barra de ferramentas. Além disso, o usuário pode clicar duas vezes para exibir a barra de ferramentas do **Personalizar barra de ferramentas** caixa de diálogo que permite que o usuário adicionar, excluir e reorganizar os botões da barra de ferramentas. O aplicativo pode exibir a caixa de diálogo usando o [personalizar](../mfc/reference/ctoolbarctrl-class.md#customize) função de membro.

O controle de barra de ferramentas envia mensagens de notificação para a janela pai em cada etapa no processo de personalização. Se o usuário mantiver a tecla SHIFT pressionada e começa a arrastar um botão, a barra de ferramentas manipula automaticamente a operação de arrastar. A barra de ferramentas envia o **TBN_QUERYDELETE** mensagem de notificação para a janela pai para determinar se o botão pode ser excluído. A operação de arrastar termina se a janela pai retorna **falsos**. Caso contrário, a barra de ferramentas de captura a entrada de mouse e aguarda o usuário liberar o botão do mouse.

Quando o usuário libera o botão do mouse, o controle de barra de ferramentas determina o local do cursor do mouse. Se o cursor estiver fora da barra de ferramentas, o botão é excluído. Se o cursor estiver em outro botão de barra de ferramentas, a barra de ferramentas envia o **TBN_QUERYINSERT** mensagem de notificação para a janela pai para determinar se um botão pode ser inserido à esquerda do botão determinado. O botão será inserido se a janela pai retorna **verdadeira**; caso contrário, ele não é. A barra de ferramentas envia o **TBN_TOOLBARCHANGE** mensagem de notificação para sinalizar o final da operação de arrastar.

Se o usuário começa uma operação de arrastar sem manter pressionada a tecla SHIFT pressionada, o controle de barra de ferramentas envia o **TBN_BEGINDRAG** mensagem de notificação para a janela do proprietário. Um aplicativo que implementa seu próprio código arrastando o botão pode usar essa mensagem como um sinal para iniciar uma operação de arrastar. A barra de ferramentas envia o **TBN_ENDDRAG** mensagem de notificação para sinalizar o final da operação de arrastar.

Um controle de barra de ferramentas envia mensagens de notificação quando o usuário personaliza uma barra de ferramentas usando o **Personalizar barra de ferramentas** caixa de diálogo. A barra de ferramentas envia o **TBN_BEGINADJUST** mensagem de notificação depois que o usuário clica duas vezes a barra de ferramentas, mas antes da caixa de diálogo caixa é criada. Em seguida, a barra de ferramentas começa enviando uma série de **TBN_QUERYINSERT** mensagens de notificação para determinar se a barra de ferramentas permite que os botões a serem inseridos. Quando a janela pai retorna **verdadeira**, a barra de ferramentas interromperá o envio **TBN_QUERYINSERT** mensagens de notificação. Se a janela pai não retornar **verdadeira** para qualquer botão, a barra de ferramentas destrói a caixa de diálogo.

Em seguida, o controle de barra de ferramentas determina se os botões poderão ser excluídos da barra de ferramentas, enviando uma **TBN_QUERYDELETE** mensagem de notificação para cada botão na barra de ferramentas. Retorna a janela pai **verdadeira** para indicar que um botão pode ser excluído; caso contrário, retornará **falso**. A barra de ferramentas adiciona todos os botões de barra de ferramentas para a caixa de diálogo, mas grays aqueles que não pode ser excluído.

Sempre que o controle de barra de ferramentas precisa obter informações sobre um botão na caixa de diálogo Personalizar barra de ferramentas, ele envia o **TBN_GETBUTTONINFO** mensagem de notificação, que especifica o índice do botão para que ele precisa de informações e o endereço de uma **TBNOTIFY** estrutura. A janela pai deve preencher a estrutura com as informações relevantes.

O **Personalizar barra de ferramentas** caixa de diálogo inclui um botão de Ajuda e um botão de redefinição. Quando o usuário escolhe o botão Ajuda, o controle de barra de ferramentas envia o **TBN_CUSTHELP** mensagem de notificação. A janela pai deve responder exibindo informações de Ajuda. A caixa de diálogo envia o **TBN_RESET** mensagem de notificação quando o usuário seleciona o botão de reinicialização. Esta mensagem indica que a barra de ferramentas está prestes a reinicializar a caixa de diálogo.

Essas mensagens são todos os **WM_NOTIFY** mensagens e eles podem ser manipulados em sua janela do proprietário, adicionando entradas de mapa de mensagem do formulário a seguir ao mapa de mensagem da janela do proprietário:

```cpp
ON_NOTIFY( wNotifyCode, idControl, memberFxn )
```

- **wNotifyCode**

   Mensagem de notificação de código de identificador, tal como **TBN_BEGINADJUST**.

- **idControl**

   O identificador do controle que está enviando a notificação.

- **memberFxn**

   A função de membro a ser chamado quando a notificação é recebida.

Sua função de membro deve ser declarada com o seguinte protótipo:

```cpp
afx_msg void memberFxn( NMHDR * pNotifyStruct, LRESULT * result );
```

Se o manipulador de mensagens de notificação retorna um valor, ele deve colocá-los a **LRESULT** apontado por *resultado*.

Para cada mensagem `pNotifyStruct` aponta para a um **NMHDR** estrutura ou uma **TBNOTIFY** estrutura. Essas estruturas são descritas abaixo:

O **NMHDR** estrutura contém os seguintes membros:

```cpp
typedef struct tagNMHDR {
    HWND hwndFrom;  // handle of control sending message
    UINT idFrom;// identifier of control sending message
    UINT code;  // notification code; see below
} NMHDR;
```

- **hwndFrom**

   Identificador de janela do controle que está enviando a notificação. Para converter este identificador para um `CWnd` ponteiro, use [CWnd::FromHandle](../mfc/reference/cwnd-class.md#fromhandle).

- **idFrom**

   Identificador do controle que está enviando a notificação.

- **code**

   Código de notificação. Esse membro pode ser um valor específico para um tipo de controle, tal como **TBN_BEGINADJUST** ou **TTN_NEEDTEXT**, ou pode ser um dos valores de notificação comuns listados abaixo:

   - **NM_CLICK** o usuário clicou no botão esquerdo do mouse dentro do controle.

   - **NM_DBLCLK** o usuário clicou duas vezes no botão esquerdo do mouse dentro do controle.

   - **NM_KILLFOCUS** o controle perdeu o foco de entrada.

   - **NM_OUTOFMEMORY** o controle não foi possível concluir uma operação porque não há memória suficiente disponível.

   - **NM_RCLICK** o usuário clicou o botão direito do mouse dentro do controle.

   - **NM_RDBLCLK** o usuário clicou duas vezes com o botão direito do mouse dentro do controle.

   - **NM_RETURN** o controle tem o foco de entrada, e o usuário pressiona a tecla ENTER.

   - **NM_SETFOCUS** controle recebeu o foco de entrada.

O **TBNOTIFY** estrutura contém os seguintes membros:

```cpp
typedef struct {
    NMHDR hdr; // information common to all WM_NOTIFY messages
    int iItem; // index of button associated with notification
    TBBUTTON tbButton; // info about button associated withnotification
    int cchText;   // count of characters in button text
    LPSTR lpszText;// address of button text
} TBNOTIFY, FAR* LPTBNOTIFY;
```

- **hdr**

   Informações comuns a todos os **WM_NOTIFY** mensagens.

- **iItem**

   Índice do botão associado à notificação.

- **tbButton**

   **TBBUTTON** estrutura que contém informações sobre o botão de barra de ferramentas associadas com a notificação.

- **cchText**

   Contagem de caracteres no texto do botão.

- **lpszText**

   Ponteiro para o texto do botão.

As notificações que envia a barra de ferramentas são da seguinte maneira:

- **TBN_BEGINADJUST**

   Enviado quando o usuário começa a personalização de um controle de barra de ferramentas. O ponteiro aponta para um **NMHDR** estrutura que contém informações sobre a notificação. O manipulador não precisa retornar qualquer valor específico.

- **TBN_BEGINDRAG**

   Enviado quando o usuário começa a arrastar um botão em um controle de barra de ferramentas. O ponteiro aponta para um **TBNOTIFY** estrutura. O **iItem** membro contém o índice baseado em zero do botão que está sendo arrastado. O manipulador não precisa retornar qualquer valor específico.

- **TBN_CUSTHELP**

   Enviado quando o usuário escolhe o botão Ajuda na caixa de diálogo Personalizar barra de ferramentas. Nenhum valor de retorno. O ponteiro aponta para um **NMHDR** estrutura que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar qualquer valor específico.

- **TBN_ENDADJUST**

   Enviado quando o usuário para a personalização de um controle de barra de ferramentas. O ponteiro aponta para um **NMHDR** estrutura que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar qualquer valor específico.

- **TBN_ENDDRAG**

   Enviado quando o usuário para de arrastar um botão em um controle de barra de ferramentas. O ponteiro aponta para um **TBNOTIFY** estrutura. O **iItem** membro contém o índice baseado em zero do botão que está sendo arrastado. O manipulador não precisa retornar qualquer valor específico.

- **TBN_GETBUTTONINFO**

   Enviado quando o usuário estiver personalizando um controle de barra de ferramentas. A barra de ferramentas usa esta mensagem de notificação para recuperar as informações necessárias para a caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para um **TBNOTIFY** estrutura. O **iItem** membro Especifica o índice baseado em zero de um botão. O **pszText** e **cchText** membros especificam o endereço e o comprimento, em caracteres, do texto do botão atual. Um aplicativo deve preencher a estrutura com informações sobre o botão. Retornar **verdadeira** se informações sobre o botão foi copiado para a estrutura, ou **falso** caso contrário.

- **TBN_QUERYDELETE**

   Enviado enquanto o usuário estiver personalizando uma barra de ferramentas para determinar se um botão pode ser excluído de um controle de barra de ferramentas. O ponteiro aponta para um **TBNOTIFY** estrutura. O **iItem** membro contém o índice baseado em zero do botão a ser excluído. Retornar **verdadeira** para permitir que o botão a ser excluído ou **falso** para impedir que o botão que está sendo excluído.

- **TBN_QUERYINSERT**

   Enviado enquanto o usuário estiver personalizando um controle de barra de ferramentas para determinar se um botão pode ser inserido à esquerda do botão determinado. O ponteiro aponta para um **TBNOTIFY** estrutura. O **iItem** membro contém o índice baseado em zero do botão a ser inserido. Retornar **verdadeira** para permitir que um botão a ser inserido na frente de determinado botão ou **falso** para impedir que o botão que está sendo inserido.

- **TBN_RESET**

   Enviado quando o usuário redefine o conteúdo da caixa de diálogo Personalizar barra de ferramentas. O ponteiro aponta para um **NMHDR** estrutura que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar qualquer valor específico.

- **TBN_TOOLBARCHANGE**

   Enviado depois que o usuário tiver personalizado a um controle de barra de ferramentas. O ponteiro aponta para um **NMHDR** estrutura que contém informações sobre a mensagem de notificação. O manipulador não precisa retornar qualquer valor específico.

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
