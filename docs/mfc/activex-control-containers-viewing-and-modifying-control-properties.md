---
title: 'Contêineres de controle ActiveX: exibindo e modificando propriedades de controle'
ms.date: 11/04/2016
helpviewer_keywords:
- properties [MFC], viewing and modifying
- ActiveX control containers [MFC], viewing and modifying properties
- resource editors, viewing and modifying ActiveX controls
- ActiveX controls [MFC], properties
- controls [MFC], properties
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
ms.openlocfilehash: b0ca43f59cf70dea1348f22a08cfb4e89b45c3dd
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617364"
---
# <a name="activex-control-containers-viewing-and-modifying-control-properties"></a>Contêineres de controle ActiveX: exibindo e modificando propriedades de controle

Quando você insere um controle ActiveX em um projeto, é útil exibir e alterar as propriedades com suporte no controle ActiveX. Este artigo discute como usar o Visual C++ editor de recursos para fazer isso.

Se seu aplicativo de contêiner de controle ActiveX usar controles inseridos, você poderá exibir e modificar as propriedades do controle enquanto estiver no editor de recursos. Você também pode usar o editor de recursos para definir valores de propriedade durante o tempo de design. O editor de recursos salva automaticamente esses valores no arquivo de recursos do projeto. Qualquer instância do controle terá suas propriedades inicializadas para esses valores.

Este procedimento pressupõe que você inseriu um controle em seu projeto. Para obter informações, consulte [contêineres de controle ActiveX: inserindo um controle em um aplicativo de contêiner de controle](inserting-a-control-into-a-control-container-application.md).

A primeira etapa na exibição das propriedades do controle é adicionar uma instância do controle ao modelo de caixa de diálogo do projeto.

### <a name="to-view-the-properties-of-a-control"></a>Para exibir as propriedades de um controle

1. Em Modo de Exibição de Recursos, abra a pasta **caixa de diálogo** .

1. Abra o modelo de caixa de diálogo principal.

1. Insira um controle ActiveX usando a caixa de diálogo **Inserir controle ActiveX** . Para obter mais informações, consulte [exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

1. Selecione o controle ActiveX na caixa de diálogo.

1. Na janela **Propriedades** , clique no botão **Propriedades** .

Use a caixa de diálogo **Propriedades** para modificar e testar novas propriedades imediatamente.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](activex-control-containers.md)
