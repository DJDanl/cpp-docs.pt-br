---
title: Inserindo um formulário em um projeto
ms.date: 11/04/2016
helpviewer_keywords:
- inserting forms [MFC]
- Insert New dialog box [MFC]
- forms, adding to projects
ms.assetid: f3bd2998-3ce2-496d-ac5c-57ca70eec7cb
ms.openlocfilehash: 8e3162ac3917781920130bcbed23864eb90afa59
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618424"
---
# <a name="inserting-a-form-into-a-project"></a>Inserindo um formulário em um projeto

Os formulários fornecem um contêiner conveniente para controles. Você pode inserir facilmente um formulário baseado em MFC em seu aplicativo, contanto que o aplicativo dê suporte às bibliotecas MFC.

### <a name="to-insert-a-form-into-your-project"></a>Para inserir um formulário em seu projeto

1. Em Modo de Exibição de Classe, selecione o projeto ao qual você deseja adicionar o formulário e clique com o botão direito do mouse.

1. No menu de atalho, clique em **Adicionar** e em **Adicionar Classe**.

   Se o comando **novo formulário** não estiver disponível, seu projeto poderá ser baseado no Active Template Library (ATL). Para adicionar um formulário a um projeto do ATL, você deve [especificar determinadas configurações](../atl/reference/application-settings-atl-project-wizard.md) ao criar o projeto pela primeira vez.

1. Na pasta **MFC** , clique em **classe MFC**.

1. Usando o assistente de classe MFC, faça com que a nova classe derive de [CFormView](reference/cformview-class.md).

Visual C++ adiciona o formulário ao seu aplicativo, abrindo-o dentro do editor de caixa de diálogo para que você possa começar a adicionar controles e trabalhar em seu design geral.

Talvez você queira executar as seguintes etapas adicionais (não aplicável para aplicativos baseados em caixa de diálogo):

1. Substitua a `OnUpdate` função de membro.

1. Implemente uma função de membro para mover dados de sua exibição para o documento.

1. Crie uma `OnPrint` função de membro.

## <a name="see-also"></a>Consulte também

[Exibições de formulário](form-views-mfc.md)
