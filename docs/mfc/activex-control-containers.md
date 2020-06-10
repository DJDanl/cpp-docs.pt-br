---
title: Contêineres de controle ActiveX
ms.date: 09/12/2018
helpviewer_keywords:
- ActiveX control containers [MFC]
- OLE controls [MFC], containers
ms.assetid: 0eb1a713-e607-4c79-a0c7-67c5f1fd5fab
ms.openlocfilehash: 42fa18c41ebd960aa8de080df00556ad5c909d40
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620752"
---
# <a name="activex-control-containers"></a>Contêineres de controle ActiveX

Um contêiner de controle ActiveX é um contêiner que dá suporte total a controles ActiveX e pode incorporá-los em suas próprias janelas ou caixas de diálogo. Um controle ActiveX é um elemento de software reutilizável que você pode usar em muitos projetos de desenvolvimento. Os controles permitem que o usuário do aplicativo acesse bancos de dados, monitore e faça várias seleções em seus aplicativos. Para obter mais informações sobre controles ActiveX, consulte o artigo [controles ActiveX do MFC](mfc-activex-controls.md).

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações, consulte [controles ActiveX](activex-controls.md).

Os contêineres de controle normalmente usam dois formulários em um projeto:

- Caixas de diálogo e janelas de caixa de diálogo, como modos de exibição de formulário, em que um controle ActiveX é usado em algum lugar na caixa de diálogo.

- Windows em um aplicativo, em que um controle ActiveX é usado em uma barra de ferramentas ou em outro local na janela do usuário.

O contêiner de controle ActiveX interage com o controle por meio de [métodos](mfc-activex-controls-methods.md) e [Propriedades](mfc-activex-controls-properties.md)expostos. Esses métodos e propriedades, que podem ser acessados e modificados pelo contêiner de controle, são acessados por meio de uma classe wrapper no projeto de contêiner do controle ActiveX. O controle ActiveX incorporado também pode interagir com o contêiner acionando (enviando) [eventos](mfc-activex-controls-events.md) para notificar o contêiner de que uma ação ocorreu. O contêiner de controle pode optar por agir sobre essas notificações ou não.

Artigos adicionais abordam vários tópicos, desde a criação de um projeto de contêiner de controle ActiveX até problemas de implementação básicos relacionados aos contêineres de controle ActiveX criados com Visual C++:

- [Criando um contêiner de controle ActiveX do MFC](reference/creating-an-mfc-activex-control-container.md)

- [Contêineres para controles ActiveX](containers-for-activex-controls.md)

- [Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente](activex-control-containers-manually-enabling-activex-control-containment.md)

- [Contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle](inserting-a-control-into-a-control-container-application.md)

- [Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro](activex-control-containers-connecting-an-activex-control-to-a-member-variable.md)

- [Contêineres de controle ActiveX: Manipulando eventos de um controle ActiveX](activex-control-containers-handling-events-from-an-activex-control.md)

- [Contêineres de controle ActiveX: exibindo e modificando propriedades de controle](activex-control-containers-viewing-and-modifying-control-properties.md)

- [Contêineres de controle ActiveX: programando controles ActiveX em um contêiner de controle ActiveX](programming-activex-controls-in-a-activex-control-container.md)

- [Contêineres de controle ActiveX: usando controles em um contêiner que não seja da caixa de diálogo](activex-control-containers-using-controls-in-a-non-dialog-container.md)

Para obter mais informações sobre como usar controles ActiveX em uma caixa de diálogo, consulte os tópicos do editor de caixa de [diálogo](../windows/dialog-editor.md) .

Para obter uma lista de artigos que explicam os detalhes do desenvolvimento de controles ActiveX usando Visual C++ e as classes de controle ActiveX do MFC, consulte [controles ActiveX do MFC](mfc-activex-controls.md). Os artigos são agrupados por categorias funcionais.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
