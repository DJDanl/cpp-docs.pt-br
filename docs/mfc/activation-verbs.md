---
title: 'Ativação: Verbos'
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
ms.openlocfilehash: baf8e0ac3527407b2e5ba77dfdf3921419217fd7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62392902"
---
# <a name="activation-verbs"></a>Ativação: Verbos

Este artigo explica a função primária e secundária verbos play em OLE [ativação](../mfc/activation-cpp.md).

Geralmente, clicar duas vezes em um item inserido permite que o usuário editá-lo. No entanto, certos itens não se comportam dessa forma. Por exemplo, clicar duas vezes em um item criado com o aplicativo de gravador de som não abre o servidor em uma janela separada. em vez disso, ela reproduz o som.

A razão para essa diferença de comportamento é que os itens do gravador de som tem um diferente "verbo primário". O verbo primário é a ação executada quando o usuário clica duas vezes em um item OLE. Para a maioria dos tipos de itens OLE, o verbo primário está edição, que inicia o servidor que criou o item. Para alguns tipos de itens, como itens de gravador de som, o verbo primário é Play.

Muitos tipos de itens OLE oferecer suporte a apenas um verbo e edição é a mais comum. No entanto, alguns tipos de itens de suportam a vários verbos. Por exemplo, o gravador de som, dar suporte a itens editar como um verbo secundário.

Outro verbo usado com frequência é aberto. O verbo Open é idêntico à edição, exceto o aplicativo de servidor é iniciado em uma janela separada. Esse verbo deve ser usado quando o aplicativo de contêiner ou o aplicativo de servidor não dá suporte a ativação in-loco.

Qualquer verbos que não seja o verbo primário devem ser invocados por meio de um comando de submenu quando o item é selecionado. Esse submenu contendo todos os verbos compatíveis com o item e geralmente for atingido, o *typename* **objeto** comando o **editar** menu. Para obter informações sobre o *typename* **objeto** de comando, consulte o artigo [Menus e recursos: Adições de contêiner](../mfc/menus-and-resources-container-additions.md).

Os verbos que dá suporte a um aplicativo de servidor são listados no banco de dados de registro do Windows. Se seu aplicativo de servidor foi escrito com a biblioteca Microsoft Foundation Class, ele registrará automaticamente todos os verbos quando o servidor é iniciado. Caso contrário, você deve registrá-los durante a fase de inicialização do aplicativo de servidor. Para obter mais informações, consulte o artigo [registro](../mfc/registration.md).

## <a name="see-also"></a>Consulte também

[Ativação](../mfc/activation-cpp.md)<br/>
[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)
