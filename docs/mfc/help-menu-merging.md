---
title: Mescla do Menu Ajuda | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- menus [MFC], merging
- merging Help menus [MFC]
- Help [MFC], for active document containers
ms.assetid: 9d615999-79ba-471a-9288-718f0c903d49
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 379e67d00969518400826e1f82d8801391512ef4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435617"
---
# <a name="help-menu-merging"></a>Mescla do menu Ajuda

Quando um objeto está ativo em um contêiner, o protocolo de documentos OLE de mesclagem de menu fornece o controle total do objeto do **ajudar** menu. Como resultado, os tópicos de Ajuda do contêiner não estão disponíveis, a menos que o usuário desativa o objeto. Expande a arquitetura de confinamento do documento ativo nas regras de mesclagem para permitir que o contêiner e um documento ativo que está ativo para compartilhar o menu de menu de no local. As novas regras são convenções simplesmente adicionais sobre qual componente possui qual parte do menu e como o menu compartilhado é construído.

A nova convenção é simple. Em documentos do Active Directory, o **ajudar** menu tem dois itens de menu de nível superior, organizadas da seguinte maneira:

`Help`

`Container Help >`

`Object Help    >`

Por exemplo, quando uma seção do Word está ativa no Office Binder, em seguida, a **ajudar** menu seria exibida da seguinte maneira:

`Help`

`Binder Help >`

`Word Help   >`

Os dois itens de menu são menus em cascata, sob a qual os itens de menu adicionais específicos para o contêiner e o objeto são fornecidos para o usuário. Quais itens aparecem aqui será variam de acordo com o contêiner e os objetos envolvidos.

Para construir este mesclados **ajudar** menu, a arquitetura de confinamento do documento ativo modifica o procedimento de documentos OLE normal. De acordo com a OLE documentos, a barra de menu mesclado pode ter seis grupos de menus, ou seja, **arquivo**, **editar**, **contêiner**, **objeto**,  **Janela**, **ajudar**, nessa ordem. Em cada grupo, pode haver zero ou mais menus. Os grupos **arquivo**, **contêiner**, e **janela** pertencem a grupos e o contêiner **editar**, **Object, o** e **ajudar** pertencem ao objeto. Quando o objeto quer fazer a mesclagem de menu, ele cria uma barra de menus em branco e passa-o para o contêiner. O contêiner, em seguida, insere seus menus, chamando `IOleInPlaceFrame::InsertMenus`. O objeto também passa uma estrutura que é uma matriz de seis valores longos (**OLEMENUGROUPWIDTHS**). Depois de inserir os menus, o contêiner de marca como muitos menus ele adicionado em cada um de seus grupos e, em seguida, retorna. Em seguida, o objeto insere seus menus, prestando atenção à contagem de menus em cada grupo de contêineres. Por fim, o objeto passa a barra de menu mesclado e a matriz (que contém a contagem dos menus em cada grupo) para OLE, que retorna um opaco "descritor de menu" manipular. Mais tarde o objeto passa esse identificador e a barra de menu mesclado ao contêiner, por meio de `IOleInPlaceFrame::SetMenu`. Neste momento, o contêiner exibe a barra de menu mesclado e também passa o identificador para OLE, para que o OLE pode fazer a expedir mensagens de menu.

No procedimento a modificação de documento ativo, o objeto deve ser inicializado pela primeira vez o **OLEMENUGROUPWIDTHS** elementos como zero antes de passá-la para o contêiner. Em seguida, o contêiner executa uma inserção de menu normal com uma exceção: as inserções de contêiner uma **ajudar** menu como o último item e armazena um valor de 1 na última entrada (o sexto) da **OLEMENUGROUPWIDTHS** matriz (ou seja, largura [5], que pertence ao grupo de Ajuda do objeto). Isso **ajudar** menu terá apenas um item que é um submenu, o "**contêiner ajuda** >" menu em cascata conforme descrito anteriormente.

O objeto, em seguida, executa seu código de inserção de menu normal, exceto que, antes de inserir sua **ajudar** menu, ele verifica a entrada de sexta da **OLEMENUGROUPWIDTHS** matriz. Se o valor é 1 e o nome do último menu é **ajudar** (ou cadeia de caracteres localizada apropriado), e em seguida, insere o objeto seu **ajuda** menu como o submenu do contêiner **ajuda** menu.

O objeto, em seguida, define o sexto elemento da **OLEMENUGROUPWIDTHS** como zero e incrementa o quinto elemento em um. Isso permite que OLE Saiba que o **ajudar** menu pertence ao contêiner e as mensagens de menu correspondentes para esse menu (e seus submenus) devem ser roteadas para o contêiner. Em seguida, é responsabilidade do contêiner para encaminhar **WM_INITMENUPOPUP**, **WM_SELECT**, **WM_COMMAND**e outras mensagens relacionadas de menu que pertencem do objeto parte do **ajudar** menu. Isso é feito por meio **WM_INITMENU** para limpar um sinalizador que informa o contêiner se o usuário navegar para o objeto **ajudar** menu. O contêiner, em seguida, observa **WM_MENUSELECT** para entrada em ou sair de qualquer item na **ajudar** menu que o contêiner não se adicionou. Na entrada, isso significa que o usuário navegar em um menu de objeto, portanto, o contêiner define o sinalizador "no menu de Ajuda do objeto" e usa o estado do sinalizador para encaminhar qualquer **WM_MENUSELECT**, **WM_INITMENUPOPUP**e  **WM_COMMAND** mensagens, como mínimo, para a janela de objeto. (Na saída, o contêiner limpa o sinalizador e, em seguida, processa essas mensagens mesmas em si). O contêiner deve usar a janela retornada a partir do objeto `IOleInPlaceActiveObejct::GetWindow` funcionar como o destino para essas mensagens.

Se o objeto detecta um zero no sexto elemento da **OLEMENUGROUPWIDTHS**, ele procede de acordo com as regras normais de documentos OLE. Esse procedimento aborda os contêineres que participam **ajudar** mesclagem, bem como os que não de menu.

Quando o objeto chama `IOleInPlaceFrame::SetMenu`, antes de exibir mesclada barra de menus, as verificações de contêiner se o **ajudar** menu tem um submenu adicional, além do que o contêiner foi inserido. Se, o contêiner deixa seus **ajudar** menu na barra de menu mesclado. Se o **ajudar** menu não tem um submenu adicional, o contêiner removerá seu **ajudar** menu na barra de menu mesclado. Esse procedimento aborda os objetos que participam **ajudar** mesclagem, bem como os que não de menu.

Por fim, quando é hora de desmontar o menu, o objeto remove inserida **ajudar** menu, além de remover o outro inserido menus. Quando o contêiner remove seus menus, ela removerá seus **ajudar** menu além de outros menus que ele tenha inserido.

## <a name="see-also"></a>Consulte também

[Contêineres de documento ativos](../mfc/active-document-containers.md)

