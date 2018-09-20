---
title: 'Contêineres de controle ActiveX: Exibindo e modificando propriedades de controle | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- properties [MFC], viewing and modifying
- ActiveX control containers [MFC], viewing and modifying properties
- resource editors, viewing and modifying ActiveX controls
- ActiveX controls [MFC], properties
- controls [MFC], properties
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9614ecfcd23418f8b0abc08622e8c272bb5548a7
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46388817"
---
# <a name="activex-control-containers-viewing-and-modifying-control-properties"></a>Contêineres de controle ActiveX: exibindo e modificando propriedades de controle

Quando você insere um controle ActiveX em um projeto, é útil exibir e alterar as propriedades compatíveis com o controle ActiveX. Este artigo discute como usar o editor de recursos do Visual C++ para fazer isso.

Se seu aplicativo de contêiner do controle ActiveX usa controles incorporados, você pode exibir e modificar as propriedades do controle enquanto estiver no editor de recursos. Você também pode usar o editor de recursos para definir valores de propriedade durante o tempo de design. O editor de recursos, em seguida, salva automaticamente esses valores no arquivo de recurso do projeto. Qualquer instância do controle, em seguida, terá suas propriedades inicializadas para esses valores.

Este procedimento pressupõe que você inseriu um controle em seu projeto. Para obter informações, consulte [contêineres de controle ActiveX: inserindo um controle em um controle de aplicativo de contêiner](../mfc/inserting-a-control-into-a-control-container-application.md).

Exibindo as propriedades do controle a primeira etapa é adicionar uma instância do controle ao modelo de caixa de diálogo do projeto.

### <a name="to-view-the-properties-of-a-control"></a>Para exibir as propriedades de um controle

1. No modo de exibição de recursos, abra o **caixa de diálogo** pasta.

1. Abra o modelo de caixa de diálogo principal.

1. Inserir um controle ActiveX usando o **Inserir controle ActiveX** caixa de diálogo. Para obter mais informações, consulte [exibindo e adicionando os controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

1. Selecione o controle ActiveX na caixa de diálogo.

1. Na janela Propriedades, clique o **propriedades** botão.

Use o **propriedades** caixa de diálogo para modificar e testar as novas propriedades imediatamente.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

