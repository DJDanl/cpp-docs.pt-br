---
title: Contêineres de controle ActiveX | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ActiveX control containers [MFC]
- OLE controls [MFC], containers
ms.assetid: 0eb1a713-e607-4c79-a0c7-67c5f1fd5fab
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 73496f892cc55ef59b2d84228ae9ae0416d3e8a6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="activex-control-containers"></a>Contêineres de controle ActiveX
Um contêiner de controle ActiveX é um contêiner que oferece suporte para controles ActiveX e incorporá-las em seu próprio windows ou caixas de diálogo. Um controle ActiveX é um elemento de software reutilizáveis que você pode usar em vários projetos de desenvolvimento. Controles permitem que o usuário do aplicativo acessar bancos de dados, monitorar os dados e fazer várias seleções em seus aplicativos. Para obter mais informações sobre os controles ActiveX, consulte o artigo [controles ActiveX MFC](../mfc/mfc-activex-controls.md).  
  
 Contêineres de controle geralmente levam dois formulários em um projeto:  
  
-   Caixas de diálogo e janelas do diálogo com como modos de exibição de formulário, em que um controle ActiveX é usado em algum lugar na caixa de diálogo.  
  
-   Windows em um aplicativo, onde um controle ActiveX é usado em uma barra de ferramentas, ou em outro local na janela do usuário.  
  
 O ActiveX contêiner de controle interage com o controle via expostos [métodos](../mfc/mfc-activex-controls-methods.md) e [propriedades](../mfc/mfc-activex-controls-properties.md). Esses métodos e propriedades que podem ser acessadas e modificadas pelo contêiner de controle, são acessadas por meio de uma classe wrapper no projeto de contêiner de controle ActiveX. O controle ActiveX incorporado também pode interagir com o contêiner de acionamento (envio) [eventos](../mfc/mfc-activex-controls-events.md) para notificar o contêiner que ocorreu uma ação. O contêiner de controle pode escolher agir sobre essas notificações ou não.  
  
 Artigos discutem vários tópicos, crie um projeto de contêiner de controle ActiveX a implementação básica problemas relacionados a contêineres de controle ActiveX criados com o Visual C++:  
  
-   [Criando um contêiner de controle ActiveX do MFC](../mfc/reference/creating-an-mfc-activex-control-container.md)  
  
-   [Contêineres para controles ActiveX](../mfc/containers-for-activex-controls.md)  
  
-   [Contêineres de controle ActiveX: habilitando contenção de controle ActiveX manualmente](../mfc/activex-control-containers-manually-enabling-activex-control-containment.md)  
  
-   [Contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle](../mfc/inserting-a-control-into-a-control-container-application.md)  
  
-   [Contêineres de controle ActiveX: conectando um controle ActiveX a uma variável membro](../mfc/activex-control-containers-connecting-an-activex-control-to-a-member-variable.md)  
  
-   [Contêineres de controle ActiveX: Controle de manipulação de eventos de um controle ActiveX](../mfc/activex-control-containers-handling-events-from-an-activex-control.md)  
  
-   [Contêineres de controle ActiveX: exibindo e modificando propriedades de controle](../mfc/activex-control-containers-viewing-and-modifying-control-properties.md)  
  
-   [Contêineres de controle ActiveX: programando controles ActiveX em um contêiner de controle ActiveX](../mfc/programming-activex-controls-in-a-activex-control-container.md)  
  
-   [Contêineres de controle ActiveX: usando controles em um contêiner que não é uma caixa de diálogo](../mfc/activex-control-containers-using-controls-in-a-non-dialog-container.md)  
  
 Para obter mais informações sobre como usar os controles ActiveX na caixa de diálogo, consulte o [Editor de caixa de diálogo](../windows/dialog-editor.md) tópicos.  
  
 Para obter uma lista de artigos que explicam os detalhes de desenvolvimento de controles ActiveX usando o Visual C++ e as classes de controle ActiveX MFC, consulte [controles ActiveX MFC](../mfc/mfc-activex-controls.md). Os artigos são agrupados por categorias funcionais.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

