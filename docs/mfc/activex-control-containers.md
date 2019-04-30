---
title: Contêineres de controle ActiveX
ms.date: 09/12/2018
helpviewer_keywords:
- ActiveX control containers [MFC]
- OLE controls [MFC], containers
ms.assetid: 0eb1a713-e607-4c79-a0c7-67c5f1fd5fab
ms.openlocfilehash: e8340acafc81447052fcb8d90df8997e81dc4117
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394852"
---
# <a name="activex-control-containers"></a>Contêineres de controle ActiveX

Um contêiner de controle ActiveX é um contêiner que dá suporte a controles ActiveX e pode incorporá-las em seu próprio windows ou caixas de diálogo. Um controle ActiveX é um elemento de software reutilizáveis que você pode usar em vários projetos de desenvolvimento. Controles permitem que o usuário do seu aplicativo acessar bancos de dados, monitorar os dados e fazer várias seleções em seus aplicativos. Para obter mais informações sobre os controles ActiveX, consulte o artigo [controles ActiveX do MFC](../mfc/mfc-activex-controls.md).

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Contêineres de controle normalmente assumir duas formas em um projeto:

- Caixas de diálogo e semelhante a caixa de diálogo do windows, como modos de exibição de formulário, onde um controle ActiveX é usado em algum lugar na caixa de diálogo.

- Windows em um aplicativo, onde um controle ActiveX é usado em uma barra de ferramentas ou em outro local na janela do usuário.

O contêiner de controle interage com o controle por meio de ActiveX expostos [métodos](../mfc/mfc-activex-controls-methods.md) e [propriedades](../mfc/mfc-activex-controls-properties.md). Esses métodos e propriedades que podem ser acessadas e modificadas pelo contêiner de controle, são acessadas por meio de uma classe de wrapper no projeto do contêiner de controle ActiveX. O controle ActiveX incorporado também pode interagir com o contêiner disparando (envio) [eventos](../mfc/mfc-activex-controls-events.md) para notificar o contêiner que uma ação tenha ocorrido. O contêiner de controle pode optar por agir dessas notificações ou não.

Artigos adicionais sobre vários tópicos, desde a criação de um projeto de contêiner do controle ActiveX para problemas de implementação básica relacionados aos contêineres de controle ActiveX criados com o Visual C++:

- [Criando um contêiner de controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control-container.md)

- [Contêineres para controles ActiveX](../mfc/containers-for-activex-controls.md)

- [Contêineres de controle ActiveX: habilitar contenção de controle ActiveX manualmente](../mfc/activex-control-containers-manually-enabling-activex-control-containment.md)

- [Contêineres de controle ActiveX: inserir um controle em um aplicativo de contêiner de controle](../mfc/inserting-a-control-into-a-control-container-application.md)

- [Contêineres de controle ActiveX: conectar um controle ActiveX a uma variável membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md)

- [Contêineres de controle ActiveX: Manipulação de eventos de um controle ActiveX](../mfc/activex-control-containers-handling-events-from-an-activex-control.md)

- [Contêineres de controle ActiveX: exibir e modificar propriedades de controle](../mfc/activex-control-containers-viewing-and-modifying-control-properties.md)

- [Contêineres de controle ActiveX: programar controles ActiveX em um contêiner de controle ActiveX](../mfc/programming-activex-controls-in-a-activex-control-container.md)

- [Contêineres de controle ActiveX: usar controles em um contêiner que não seja da caixa de diálogo](../mfc/activex-control-containers-using-controls-in-a-non-dialog-container.md)

Para obter mais informações sobre como usar controles ActiveX em uma caixa de diálogo, consulte a [Editor de caixa de diálogo](../windows/dialog-editor.md) tópicos.

Para obter uma lista de artigos que explicam os detalhes do desenvolvimento de controles ActiveX usando o Visual C++ e as classes de controle ActiveX do MFC, consulte [controles ActiveX MFC](../mfc/mfc-activex-controls.md). Os artigos são agrupados por categorias funcionais.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
