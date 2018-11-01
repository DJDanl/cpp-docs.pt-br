---
title: Inserindo um formulário em um projeto
ms.date: 11/04/2016
helpviewer_keywords:
- inserting forms [MFC]
- Insert New dialog box [MFC]
- forms, adding to projects
ms.assetid: f3bd2998-3ce2-496d-ac5c-57ca70eec7cb
ms.openlocfilehash: 5f5758e84e89f23f06fb9d5f2fa97220d0279725
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50666616"
---
# <a name="inserting-a-form-into-a-project"></a>Inserindo um formulário em um projeto

Formulários fornecem um contêiner conveniente para controles. Você pode inserir facilmente um formulário com base em MFC em seu aplicativo desde que o aplicativo dá suporte as bibliotecas MFC.

### <a name="to-insert-a-form-into-your-project"></a>Para inserir um formulário em seu projeto

1. Na exibição de classe, selecione o projeto ao qual você deseja adicionar o formulário e clique no botão direito do mouse.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Adicionar classe**.

   Se o **novo formulário** comando não estiver disponível, seu projeto pode se basear na biblioteca ATL (Active Template). Para adicionar um formulário a um projeto da ATL, você deve [especificar determinadas configurações](../atl/reference/application-settings-atl-project-wizard.md) ao primeiro criar o projeto.

1. Dos **MFC** pasta, clique em **classe MFC**.

1. Usando o Assistente de classe do MFC, faça a nova classe derivam [CFormView](../mfc/reference/cformview-class.md).

Visual C++ adiciona o formulário ao seu aplicativo, abri-lo dentro do editor de caixa de diálogo para que você possa começar adicionando controles e trabalhando em seu design geral.

Você talvez queira executar as seguintes etapas adicionais (não aplicáveis para aplicativos baseados na caixa de diálogo):

1. Substituir o `OnUpdate` função de membro.

1. Implemente uma função de membro para mover dados de seu modo de exibição para o seu documento.

1. Criar um `OnPrint` função de membro.

## <a name="see-also"></a>Consulte também

[Modos de exibição de formulário](../mfc/form-views-mfc.md)

