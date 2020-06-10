---
title: 'Contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle'
ms.date: 11/04/2016
helpviewer_keywords:
- ActiveX control containers [MFC], inserting controls
- ActiveX controls [MFC], adding to projects
ms.assetid: bbb617ff-872f-43d8-b4d6-c49adb16b148
ms.openlocfilehash: 1d2fc82628b3bcf842a6efb1d36ab9e8389fc0ba
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618493"
---
# <a name="activex-control-containers-inserting-a-control-into-a-control-container-application"></a>Contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle

Antes de poder acessar um controle ActiveX de um aplicativo de contêiner de controle ActiveX, você deve adicionar o controle ActiveX ao aplicativo de contêiner usando a caixa de diálogo [Inserir controle ActiveX](../windows/insert-activex-control-dialog-box.md) .

Para adicionar um controle ActiveX ao projeto de contêiner do controle ActiveX, consulte [exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

Depois de adicionar o controle, você precisará adicionar uma variável de membro (do tipo de controle ActiveX) à classe da caixa de diálogo. Para obter mais informações sobre esse procedimento, consulte [adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md).

Depois de adicionar a variável de membro, uma classe, chamada de classe de wrapper, será gerada e adicionada automaticamente ao seu projeto. Essa classe é usada como uma interface entre o contêiner de controle e o controle incorporado.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](activex-control-containers.md)
