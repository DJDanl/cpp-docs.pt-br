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
ms.openlocfilehash: 149af83bd53b7a97fd264bd6b18701fc9f64ea1f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364764"
---
# <a name="menus-and-resources-menu-merging"></a>Menus e recursos: mescla de menu

Este artigo detalha as etapas necessárias para que os aplicativos de documentos OLE lidem adequadamente com a edição visual e a ativação no local. A ativação no local representa um desafio para aplicativos de contêiner e servidor (componente). O usuário permanece na mesma janela de quadro (dentro do contexto do documento do contêiner), mas na verdade está executando outro aplicativo (o servidor). Isso requer coordenação entre os recursos dos aplicativos de contêiner e servidor.

Os tópicos abordados neste artigo incluem:

- [Menu Layouts](#_core_menu_layouts)

- [Barras de ferramentas e barras de status](#_core_toolbars_and_status_bars)

## <a name="menu-layouts"></a><a name="_core_menu_layouts"></a>Menu Layouts

O primeiro passo é coordenar os layouts do menu. Os aplicativos de contêiner devem criar um novo menu para ser usado somente quando os itens incorporados estiverem ativados no lugar. No mínimo, este menu deve consistir no seguinte, na ordem listada:

1. Menu de arquivo idêntico ao usado quando os arquivos estão abertos. (Normalmente, nenhum outro item do menu é colocado antes do próximo item.)

1. Dois separadores consecutivos.

1. Menu de janela idêntico ao usado quando os arquivos estão abertos (somente se o aplicativo do contêiner em um aplicativo MDI). Alguns aplicativos podem ter outros menus, como um menu Options, que pertence a esse grupo, que permanece no menu quando um item incorporado é ativado no lugar.

    > [!NOTE]
    >  Pode haver outros menus que afetam a visualização do documento do contêiner, como o Zoom. Esses menus de contêiner aparecem entre os dois separadores neste recurso de menu.

Os aplicativos server (componente) também devem criar um novo menu especificamente para ativação no local. Deve ser como o menu usado quando os arquivos estão abertos, mas sem itens de menu, como Arquivo e Janela que manipulam o documento do servidor em vez dos dados. Normalmente, este menu consiste no seguinte:

1. Editar menu idêntico ao usado quando os arquivos estão abertos.

1. Separador.

1. Menus de edição de objetos, como o menu Caneta no aplicativo de exemplo Scribble.

1. Separador.

1. Menu de ajuda.

Por exemplo, veja o layout de alguns menus de amostra no lugar para um contêiner e um servidor. Os detalhes de cada item do menu foram removidos para tornar o exemplo mais claro. O menu no local do contêiner tem as seguintes entradas:

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

Os separadores consecutivos indicam para onde a primeira parte do menu do servidor deve ir. Agora, veja o menu no local do servidor:

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

Os separadores aqui indicam para onde o segundo grupo de itens do menu do contêiner deve ir. A estrutura de menu resultante quando um objeto deste servidor é ativado no lugar dentro deste recipiente é assim:

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

As tabelas do acelerador associadas ao menu no local também devem ser fornecidas pelo aplicativo do servidor. O contêiner irá incorporá-los em suas próprias tabelas de acelerador.

Quando um item incorporado é ativado no lugar, a estrutura carrega o menu no lugar. Em seguida, ele pede ao aplicativo do servidor o seu menu para ativação no local e insere-o onde os separadores estão. É assim que os menus se combinam. Você recebe menus do contêiner para operar no arquivo e na colocação da janela, e você recebe menus do servidor para operar no item.

## <a name="toolbars-and-status-bars"></a><a name="_core_toolbars_and_status_bars"></a>Barras de ferramentas e barras de status

Os aplicativos do servidor devem criar uma nova barra de ferramentas e armazenar seu bitmap em um arquivo separado. Os aplicativos gerados pelo assistente de aplicativo armazenam esse bitmap em um arquivo chamado ITOOLBAR. Bmp. A nova barra de ferramentas substitui a barra de ferramentas do aplicativo de contêiner quando o item do servidor está ativado no lugar e deve conter os mesmos itens da barra de ferramentas normal, mas remover ícones representando itens nos menus Arquivo e Janela.

Esta barra de ferramentas `COleIPFrameWnd`é carregada em sua classe derivada, criada para você pelo assistente do aplicativo. A barra de status é manuseada pela aplicação do contêiner. Para obter mais informações sobre a implementação de janelas de quadrono local, consulte [Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md).

## <a name="see-also"></a>Confira também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Ativação](../mfc/activation-cpp.md)<br/>
[Servidores](../mfc/servers.md)<br/>
[Contêineres](../mfc/containers.md)
