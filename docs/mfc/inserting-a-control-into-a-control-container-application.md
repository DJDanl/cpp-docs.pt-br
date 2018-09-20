---
title: 'Contêineres de controle ActiveX: Inserindo um controle em um aplicativo de contêiner de controle | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ActiveX control containers [MFC], inserting controls
- ActiveX controls [MFC], adding to projects
ms.assetid: bbb617ff-872f-43d8-b4d6-c49adb16b148
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f025c9fa564bcd37c585db6ea5c5cd0f5be83e0d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46432133"
---
# <a name="activex-control-containers-inserting-a-control-into-a-control-container-application"></a>Contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle

Antes de poder acessar um controle ActiveX de um aplicativo de contêiner do controle ActiveX, você deve adicionar o controle ActiveX para o aplicativo de contêiner usando o [Inserir controle ActiveX](../windows/insert-activex-control-dialog-box.md) caixa de diálogo.

Para adicionar um controle ActiveX para o projeto de contêiner do controle ActiveX, consulte [exibindo e adicionando os controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

Depois de adicionar o controle, você precisará adicionar uma variável de membro (do tipo de controle ActiveX) para a classe de caixa de diálogo. Para obter mais informações sobre esse procedimento, consulte [adicionando uma variável de membro](../ide/adding-a-member-variable-visual-cpp.md).

Depois de adicionar a variável de membro uma classe, conhecida como uma classe wrapper, é gerada automaticamente e adicionada ao seu projeto. Essa classe é usada como uma interface entre o contêiner de controle e o controle inserido.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

