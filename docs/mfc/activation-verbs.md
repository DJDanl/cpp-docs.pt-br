---
title: 'Ativação: verbos'
ms.date: 11/04/2016
helpviewer_keywords:
- verbs [MFC]
- OLE [MFC], activation
- edit verb [MFC]
- activation [MFC], verbs
- OLE [MFC], editing
- Primary verb [MFC]
- OLE activation {MFC]
ms.assetid: eb56ff23-1de8-43ad-abeb-dc7346ba7b70
ms.openlocfilehash: 03edba0a4336fdc147ef6dd10c7a8154aca19d3a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616639"
---
# <a name="activation-verbs"></a>Ativação: verbos

Este artigo explica os verbos primários e secundários da função que são executados na [ativação](activation-cpp.md)OLE.

Normalmente, clicar duas vezes em um item incorporado permite que o usuário o edite. No entanto, determinados itens não se comportam dessa maneira. Por exemplo, clicar duas vezes em um item criado com o aplicativo gravador de som não abre o servidor em uma janela separada; em vez disso, ele reproduz o som.

A razão para essa diferença de comportamento é que os itens do gravador de som têm um "verbo primário" diferente. O verbo principal é a ação executada quando o usuário clica duas vezes em um item OLE. Para a maioria dos tipos de itens OLE, o verbo primário é Edit, que inicia o servidor que criou o item. Para alguns tipos de itens, como itens do gravador de som, o verbo principal é Play.

Muitos tipos de itens OLE dão suporte a apenas um verbo, e editar é o mais comum. No entanto, alguns tipos de itens dão suporte a vários verbos. Por exemplo, itens do gravador de som dão suporte a editar como um verbo secundário.

Outro verbo usado com frequência é aberto. O verbo Open é idêntico ao Edit, exceto que o aplicativo do servidor é iniciado em uma janela separada. Esse verbo deve ser usado quando o aplicativo de contêiner ou o aplicativo de servidor não oferece suporte à ativação in-loco.

Qualquer verbo diferente do verbo primário deve ser invocado por meio de um comando de submenu quando o item é selecionado. Esse submenu contém todos os verbos com suporte do item e geralmente é atingido pelo comando *TypeName* **Object** no menu **Editar** . Para obter informações sobre o comando de **objeto** *TypeName* , consulte o artigo [menus e recursos: adições de contêiner](menus-and-resources-container-additions.md).

Os verbos aos quais um aplicativo de servidor dá suporte estão listados no banco de dados de registro do Windows. Se o aplicativo do servidor for gravado com o biblioteca MFC, ele registrará automaticamente todos os verbos quando o servidor for iniciado. Caso contrário, você deve registrá-los durante a fase de inicialização do aplicativo do servidor. Para obter mais informações, consulte o artigo [registro](registration.md).

## <a name="see-also"></a>Consulte também

[Ativação](activation-cpp.md)<br/>
[Contêineres](containers.md)<br/>
[Servidores](servers.md)
