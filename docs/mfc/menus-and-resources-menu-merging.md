---
title: 'Menus e recursos: Mesclagem de menu'
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
ms.openlocfilehash: 1f7af7007e72cb8e01022c81a244fc70ba52a5cc
ms.sourcegitcommit: ecf274bcfe3a977c48745aaa243e5e731f1fdc5f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2019
ms.locfileid: "66504818"
---
# <a name="menus-and-resources-menu-merging"></a>Menus e recursos: Mesclagem de menu

Este artigo detalha as etapas necessárias para aplicativos de documento OLE tratar a edição visual e ativação in-loco corretamente. Ativação in-loco representa um desafio para o contêiner e o servidor de aplicativos (componentes). O usuário permanece na mesma janela do quadro (dentro do contexto do documento contêiner), mas está realmente executando outro aplicativo (o servidor). Isso exige a coordenação entre os recursos dos aplicativos de contêiner e o servidor.

Os tópicos abordados neste artigo incluem:

- [Layouts de menu](#_core_menu_layouts)

- [Barras de ferramentas e barras de Status](#_core_toolbars_and_status_bars)

##  <a name="_core_menu_layouts"></a> Layouts de menu

A primeira etapa é coordenar os layouts de menu. Aplicativos de contêiner devem criar um novo menu a ser usado somente quando os itens inseridos são ativados em vigor. No mínimo, esse menu deve consistir no seguinte, na ordem listada:

1. Menu de arquivo idêntico àquele usado quando os arquivos estiverem abertos. (Nenhum outro item de menu é colocado em geral antes do próximo item.)

1. Dois separadores consecutivos.

1. Menu Janela idêntico àquele usado quando os arquivos estiverem abertos (somente se o aplicativo de contêiner em um aplicativo MDI). Alguns aplicativos podem ter outros menus, como um menu de opções, que pertencem a esse grupo, que permanecerá no menu quando um item inserido é ativado em vigor.

    > [!NOTE]
    >  Pode haver outros menus que afetam o modo de exibição do documento contêiner, como o Zoom. Esses menus do contêiner aparecem entre os dois separadores nesse recurso de menu.

Aplicativos de servidor (componente) também devem criar um novo menu especificamente para ativação no local. Ele deve ser como o menu usado quando os arquivos estiverem abertos, mas sem os itens de menu, como o arquivo e a janela que manipulam o documento do servidor em vez dos dados. Normalmente, esse menu consiste no seguinte:

1. Edite menu idêntico àquele usado quando os arquivos estiverem abertos.

1. Separador.

1. Edição de menus, como o menu de caneta no aplicativo de exemplo de Scribble do objeto.

1. Separador.

1. Menu de Ajuda.

Por exemplo, examine o layout de alguns menus no local de exemplo para um contêiner e um servidor. Os detalhes de cada item de menu tem sido removidos para tornar o exemplo mais claro. Menu de no local do contêiner tem as seguintes entradas:

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

Os separadores consecutivos indicam onde a primeira parte do menu do servidor deve ficar. Agora examine o menu de no local do servidor:

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

Os separadores aqui indicam onde o segundo grupo de contêiner de itens de menu deve ir. A estrutura do menu resultante quando um objeto deste servidor é ativado em vigor dentro desse contêiner tem esta aparência:

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

Como você pode ver, os separadores foram substituídos com os diferentes grupos de menus de cada aplicativo.

Tabelas de aceleradores associadas ao menu no local também devem ser fornecidas pelo aplicativo de servidor. O contêiner será incorporá-los em suas próprias tabelas de acelerador.

Quando um item inserido é ativado em vigor, o framework carrega o menu no local. Em seguida, ele solicita que o aplicativo de servidor para o menu para ativação no local e o insere onde estão os separadores. Isso é como combinam os menus. Obter menus do contêiner para a operação em que o posicionamento de arquivo e a janela e obter menus do servidor para a operação no item.

##  <a name="_core_toolbars_and_status_bars"></a> Barras de ferramentas e barras de Status

Aplicativos de servidor devem criar uma nova barra de ferramentas e armazenar seu bitmap em um arquivo separado. Os aplicativos gerados pelo Assistente de aplicativo armazenam esse bitmap em um arquivo chamado ITOOLBAR. BMP. A nova barra de ferramentas substitui a barra de ferramentas do aplicativo de contêiner quando o item do seu servidor é ativado em vigor e deve conter os mesmos itens como sua barra de ferramentas normal, mas remova ícones que representam os itens nos menus do arquivo e a janela.

Essa barra de ferramentas é carregada no seu `COleIPFrameWnd`-derivado da classe, criado para você pelo Assistente de aplicativo. A barra de status é tratada pelo aplicativo recipiente. Para obter mais informações sobre a implementação de janelas com moldura no local, consulte [servidores: Implementação de um servidor](../mfc/servers-implementing-a-server.md).

## <a name="see-also"></a>Consulte também

[Menus e recursos (OLE)](../mfc/menus-and-resources-ole.md)<br/>
[Ativação](../mfc/activation-cpp.md)<br/>
[Servidores](../mfc/servers.md)<br/>
[Contêineres](../mfc/containers.md)
