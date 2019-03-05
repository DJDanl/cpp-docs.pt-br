---
title: 'Contêineres de controle ActiveX: Exibindo e modificando propriedades de controle'
ms.date: 11/04/2016
helpviewer_keywords:
- properties [MFC], viewing and modifying
- ActiveX control containers [MFC], viewing and modifying properties
- resource editors, viewing and modifying ActiveX controls
- ActiveX controls [MFC], properties
- controls [MFC], properties
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
ms.openlocfilehash: 0a03acfd880bcf63017eec9796315b98e5d5f4d9
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326355"
---
# <a name="activex-control-containers-viewing-and-modifying-control-properties"></a>Contêineres de controle ActiveX: Exibindo e modificando propriedades de controle

Quando você insere um controle ActiveX em um projeto, é útil exibir e alterar as propriedades compatíveis com o controle ActiveX. Este artigo discute como usar o editor de recursos do Visual C++ para fazer isso.

Se seu aplicativo de contêiner do controle ActiveX usa controles incorporados, você pode exibir e modificar as propriedades do controle enquanto estiver no editor de recursos. Você também pode usar o editor de recursos para definir valores de propriedade durante o tempo de design. O editor de recursos, em seguida, salva automaticamente esses valores no arquivo de recurso do projeto. Qualquer instância do controle, em seguida, terá suas propriedades inicializadas para esses valores.

Este procedimento pressupõe que você inseriu um controle em seu projeto. Para obter informações, consulte [contêineres de controle ActiveX: Inserindo um controle em um aplicativo de contêiner do controle](../mfc/inserting-a-control-into-a-control-container-application.md).

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
