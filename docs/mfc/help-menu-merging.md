---
title: Mescla do menu Ajuda
ms.date: 11/04/2016
helpviewer_keywords:
- menus [MFC], merging
- merging Help menus [MFC]
- Help [MFC], for active document containers
ms.assetid: 9d615999-79ba-471a-9288-718f0c903d49
ms.openlocfilehash: 1bd70af6f24ee6f9873b89b2060f4b2d90149c90
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620125"
---
# <a name="help-menu-merging"></a>Mescla do menu Ajuda

Quando um objeto está ativo em um contêiner, o menu mesclando o protocolo de documentos OLE dá ao objeto controle total sobre o menu **ajuda** . Como resultado, os tópicos da ajuda do contêiner não estarão disponíveis, a menos que o usuário desative o objeto. A arquitetura de contenção de documentos ativos expande as regras para mesclagem de menu in-loco para permitir o contêiner e um documento ativo ativo para compartilhar o menu. As novas regras são simplesmente convenções adicionais sobre qual componente pertence a parte do menu e como o menu compartilhado é construído.

A nova Convenção é simples. Em documentos ativos, o menu **ajuda** tem dois itens de menu de nível superior organizados da seguinte maneira:

`Help`

`Container Help >`

`Object Help    >`

Por exemplo, quando uma seção do Word está ativa no fichário do Office, o menu **ajuda** seria exibido da seguinte maneira:

`Help`

`Binder Help >`

`Word Help   >`

Ambos os itens de menu são menus em cascata sob os quais quaisquer itens de menu adicionais específicos ao contêiner e o objeto são fornecidos ao usuário. Os itens que aparecem aqui irão variar com o contêiner e os objetos envolvidos.

Para construir esse menu de **ajuda** mesclado, a arquitetura de contenção do documento ativo modifica o procedimento normal de documentos OLE. De acordo com os documentos OLE, a barra de menus mesclada pode ter seis grupos de menus, ou seja, **arquivo**, **Editar**, **contêiner**, **objeto**, **janela**, **ajuda**, nessa ordem. Em cada grupo, pode haver zero ou mais menus. O **arquivo**de grupos, o **contêiner**e a **janela** pertencem ao contêiner e aos grupos **Edit**, **Object** e **Help** pertencem ao objeto. Quando o objeto quer fazer a mesclagem de menus, ele cria uma barra de menus em branco e a passa para o contêiner. O contêiner insere seus menus, chamando `IOleInPlaceFrame::InsertMenus` . O objeto também passa uma estrutura que é uma matriz de seis valores longos (**OLEMENUGROUPWIDTHS**). Depois de inserir os menus, o contêiner marca quantos menus ele adicionou em cada um de seus grupos e, em seguida, retorna. Em seguida, o objeto insere seus menus, prestando atenção à contagem de menus em cada grupo de contêineres. Por fim, o objeto passa a barra de menus mesclada e a matriz (que contém a contagem de menus em cada grupo) para OLE, que retorna um identificador opaco de "descritor de menu". Posteriormente, o objeto passa esse identificador e a barra de menus mesclada para o contêiner, via `IOleInPlaceFrame::SetMenu` . Neste momento, o contêiner exibe a barra de menus mesclada e também passa o identificador para OLE, para que o OLE possa fazer uma expedição adequada de mensagens de menu.

No procedimento de documento ativo modificado, o objeto deve primeiro inicializar os elementos **OLEMENUGROUPWIDTHS** como zero antes de passá-lo para o contêiner. Em seguida, o contêiner executa uma inserção de menu normal com uma exceção: o contêiner insere um menu de **ajuda** como o último item e armazena um valor de 1 na última entrada (sexto) da matriz **OLEMENUGROUPWIDTHS** (ou seja, largura [5], que pertence ao grupo de ajuda do objeto). Este menu **ajuda** terá apenas um item que é um submenu, o menu "**ajuda do contêiner** >" em cascata, conforme descrito anteriormente.

Em seguida, o objeto executa seu código de inserção de menu normal, exceto que antes de inserir o menu **ajuda** , ele verifica a sexta entrada da matriz **OLEMENUGROUPWIDTHS** . Se o valor for 1 e o nome do último menu for **ajuda** (ou a cadeia de caracteres localizada apropriada), o objeto inserirá o menu **ajuda** como submenu do menu **ajuda** do contêiner.

Em seguida, o objeto define o sexto elemento de **OLEMENUGROUPWIDTHS** como zero e incrementa o quinto elemento por um. Isso permite que o OLE saiba que o menu **ajuda** pertence ao contêiner e as mensagens de menu correspondentes a esse menu (e seus submenus) devem ser roteadas para o contêiner. Em seguida, é responsabilidade do contêiner encaminhar **WM_INITMENUPOPUP**, **WM_SELECT**, **WM_COMMAND**e outras mensagens relacionadas ao menu que pertencem à parte do objeto do menu **ajuda** . Isso é feito usando **WM_INITMENU** para limpar um sinalizador que informa ao contêiner se o usuário navegou no menu **ajuda** do objeto. O contêiner, em seguida, observa **WM_MENUSELECT** para entrada ou saída de qualquer item no menu **ajuda** que o contêiner não adicionou a si mesmo. Na entrada, isso significa que o usuário navegou em um menu de objeto, portanto, o contêiner define o sinalizador "no menu ajuda do objeto" e usa o estado desse sinalizador para encaminhar as mensagens **WM_MENUSELECT**, **WM_INITMENUPOPUP**e **WM_COMMAND** , como um mínimo, para a janela de objeto. (Ao sair, o contêiner limpa o sinalizador e processa as mesmas mensagens em si.) O contêiner deve usar a janela retornada da função do objeto `IOleInPlaceActiveObejct::GetWindow` como o destino para essas mensagens.

Se o objeto detectar um zero no sexto elemento de **OLEMENUGROUPWIDTHS**, ele continuará de acordo com as regras normais de documentos OLE. Este procedimento aborda os contêineres que participam da mesclagem do menu **ajuda** , bem como aqueles que não o fazem.

Quando o objeto chama `IOleInPlaceFrame::SetMenu` , antes de exibir a barra de menus mesclada, o contêiner verifica se o menu **ajuda** tem um submenu adicional, além do que o contêiner inseriu. Nesse caso, o contêiner deixa o menu **ajuda** na barra de menus mesclada. Se o menu **ajuda** não tiver um submenu adicional, o contêiner removerá o menu **ajuda** da barra de menus mesclada. Este procedimento aborda objetos que participam da mesclagem do menu **ajuda** , bem como aqueles que não o fazem.

Por fim, quando for o momento de desmontar o menu, o objeto removerá o menu de **ajuda** inserido, além de remover os outros menus inseridos. Quando o contêiner remover seus menus, ele removerá seu menu **ajuda** , além dos outros menus inseridos.

## <a name="see-also"></a>Consulte também

[Contêineres de documento ativos](active-document-containers.md)
