---
title: 'Menus e recursos: mescla de menu'
ms.date: 11/04/2016
helpviewer_keywords:
- status bars [MFC], OLE document applications
- visual editing [MFC], application menus and resources
- coordinating menu layouts [MFC]
- OLE containers [MFC], menus and resources
- toolbars [MFC], OLE document applications
- merging toolbar and status bar [MFC]
- menus [MFC], OLE document applications
ms.assetid: 80b6bb17-d830-4122-83f0-651fc112d4d1
ms.openlocfilehash: 03d27443f90634b5d787eee25acc951d24178f42
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626216"
---
# <a name="menus-and-resources-menu-merging"></a>Menus e recursos: mescla de menu

Este artigo detalha as etapas necessárias para que os aplicativos de documento OLE manipulem a edição visual e a ativação in-loco corretamente. A ativação in-loco representa um desafio para os aplicativos de contêiner e servidor (componente). O usuário permanece na mesma janela do quadro (dentro do contexto do documento de contêiner), mas, na verdade, está executando outro aplicativo (o servidor). Isso requer a coordenação entre os recursos do contêiner e dos aplicativos de servidor.

Os tópicos abordados neste artigo incluem:

- [Layouts de menu](#_core_menu_layouts)

- [Barras de ferramentas e barras de status](#_core_toolbars_and_status_bars)

## <a name="menu-layouts"></a><a name="_core_menu_layouts"></a>Layouts de menu

A primeira etapa é coordenar layouts de menu. Os aplicativos de contêiner devem criar um novo menu para ser usado somente quando itens inseridos são ativados no lugar. No mínimo, esse menu deve consistir no seguinte, na ordem listada:

1. Menu de arquivo idêntico ao usado quando os arquivos estão abertos. (Geralmente, nenhum outro item de menu é colocado antes do próximo item.)

1. Dois separadores consecutivos.

1. Menu de janela idêntico àquele usado quando os arquivos estão abertos (somente se o aplicativo de contêiner em um aplicativo MDI). Alguns aplicativos podem ter outros menus, como um menu de opções, que pertencem a esse grupo, que permanece no menu quando um item incorporado é ativado no local.

    > [!NOTE]
    >  Pode haver outros menus que afetam a exibição do documento de contêiner, como zoom. Esses menus de contêiner aparecem entre os dois separadores neste recurso de menu.

Os aplicativos de servidor (componente) também devem criar um novo menu especificamente para ativação in-loco. Deve ser como o menu usado quando os arquivos estão abertos, mas sem itens de menu, como arquivo e janela, que manipulam o documento do servidor em vez dos dados. Normalmente, esse menu consiste no seguinte:

1. Edite o menu idêntico ao usado quando os arquivos estão abertos.

1. Caractere.

1. Menus de edição de objetos, como o menu de caneta no aplicativo de exemplo rabiscar.

1. Caractere.

1. Menu ajuda.

Para obter um exemplo, examine o layout de alguns menus in-loco de exemplo para um contêiner e um servidor. Os detalhes de cada item de menu foram removidos para tornar o exemplo mais claro. O menu no local do contêiner tem as seguintes entradas:

```
IDR_CONTAINERTYPE_CNTR_IP MENU PRELOAD DISCARDABLE
BEGIN
    POPUP "&File C1"
    MENUITEM SEPARATOR
    POPUP "&Zoom C2"
    MENUITEM SEPARATOR
    POPUP "&Options C3"
    POPUP "&Window C3"
END
```

Os separadores consecutivos indicam onde a primeira parte do menu do servidor deve ir. Agora, examine o menu no local do servidor:

```
IDR_SERVERTYPE_SRVR_IP MENU PRELOAD DISCARDABLE
BEGIN
    POPUP "&Edit S1"
    MENUITEM SEPARATOR
    POPUP "&Format S2"
    MENUITEM SEPARATOR
    POPUP "&Help S3"
END
```

Os separadores aqui indicam onde o segundo grupo de itens de menu de contêiner deve ir. A estrutura de menu resultante quando um objeto desse servidor é ativado no local dentro desse contêiner é semelhante a este:

```
BEGIN
    POPUP "&File C1"
    POPUP "&Edit S1"
    POPUP "&Zoom C2"
    POPUP "&Format S2"
    POPUP "&Options C3
    POPUP "&Window C3"
    POPUP "&Help S3"
END
```

Como você pode ver, os separadores foram substituídos pelos diferentes grupos do menu de cada aplicativo.

As tabelas de acelerador associadas ao menu in-loco também devem ser fornecidas pelo aplicativo de servidor. O contêiner irá incorporá-los em suas próprias tabelas de acelerador.

Quando um item incorporado é ativado no lugar, a estrutura carrega o menu in-loco. Em seguida, ele solicita ao aplicativo de servidor seu menu para ativação in-loco e o insere onde os separadores são. É assim que os menus se combinam. Você Obtém os menus do contêiner para operar no posicionamento do arquivo e da janela e obtém os menus do servidor para operação no item.

## <a name="toolbars-and-status-bars"></a><a name="_core_toolbars_and_status_bars"></a>Barras de ferramentas e barras de status

Os aplicativos de servidor devem criar uma nova barra de ferramentas e armazenar seu bitmap em um arquivo separado. Os aplicativos gerados pelo assistente de aplicativo armazenam esse bitmap em um arquivo chamado ITOOLBAR. BMP. A nova barra de ferramentas substitui a barra de ferramentas do aplicativo de contêiner quando o item do servidor é ativado no local e deve conter os mesmos itens da sua barra de ferramentas normal, mas remover ícones que representam itens nos menus arquivo e janela.

Essa barra de ferramentas é carregada em sua `COleIPFrameWnd` classe derivada, criada para você pelo assistente de aplicativo. A barra de status é manipulada pelo aplicativo de contêiner. Para obter mais informações sobre a implementação de janelas de quadros in-loco, consulte [servidores: Implementando um servidor](servers-implementing-a-server.md).

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](menus-and-resources-ole.md)<br/>
[Ativação](activation-cpp.md)<br/>
[Servidores](servers.md)<br/>
[Contêineres](containers.md)
