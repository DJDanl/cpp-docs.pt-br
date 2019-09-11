---
title: 'Contêineres de controle ActiveX: Exibindo e modificando Propriedades de controle'
ms.date: 11/04/2016
helpviewer_keywords:
- properties [MFC], viewing and modifying
- ActiveX control containers [MFC], viewing and modifying properties
- resource editors, viewing and modifying ActiveX controls
- ActiveX controls [MFC], properties
- controls [MFC], properties
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
ms.openlocfilehash: 1d42820efd06c2ae52f5d1b22b0bdfb6335c4a89
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907802"
---
# <a name="activex-control-containers-viewing-and-modifying-control-properties"></a>Contêineres de controle ActiveX: Exibindo e modificando Propriedades de controle

Quando você insere um controle ActiveX em um projeto, é útil exibir e alterar as propriedades com suporte no controle ActiveX. Este artigo discute como usar o editor de recursos C++ visuais para fazer isso.

Se seu aplicativo de contêiner de controle ActiveX usar controles inseridos, você poderá exibir e modificar as propriedades do controle enquanto estiver no editor de recursos. Você também pode usar o editor de recursos para definir valores de propriedade durante o tempo de design. O editor de recursos salva automaticamente esses valores no arquivo de recursos do projeto. Qualquer instância do controle terá suas propriedades inicializadas para esses valores.

Este procedimento pressupõe que você inseriu um controle em seu projeto. Para obter informações, [consulte contêineres de controle ActiveX: Inserindo um controle em um aplicativo](../mfc/inserting-a-control-into-a-control-container-application.md)de contêiner de controle.

A primeira etapa na exibição das propriedades do controle é adicionar uma instância do controle ao modelo de caixa de diálogo do projeto.

### <a name="to-view-the-properties-of-a-control"></a>Para exibir as propriedades de um controle

1. Em Modo de Exibição de Recursos, abra a pasta **caixa de diálogo** .

1. Abra o modelo de caixa de diálogo principal.

1. Insira um controle ActiveX usando a caixa de diálogo **Inserir controle ActiveX** . Para obter mais informações, consulte [exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).

1. Selecione o controle ActiveX na caixa de diálogo.

1. Na janela **Propriedades** , clique no botão **Propriedades** .

Use a caixa de diálogo **Propriedades** para modificar e testar novas propriedades imediatamente.

## <a name="see-also"></a>Consulte também

[Contêineres de controle ActiveX](../mfc/activex-control-containers.md)
