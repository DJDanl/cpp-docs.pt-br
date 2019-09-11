---
title: Criando um aplicativo MFC com base em formulários
ms.date: 09/09/2019
f1_keywords:
- vc.appwiz.mfcforms.project
helpviewer_keywords:
- applications [MFC], forms-based
- forms-based applications [MFC]
ms.assetid: 048d2f7d-b60d-4386-ad8e-71d49af9c05e
ms.openlocfilehash: 1dbbc5c29f85ced846cb3e07a02a5d6a55c94b20
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70908053"
---
# <a name="creating-a-forms-based-mfc-application"></a>Criando um aplicativo MFC com base em formulários

Um formulário é uma caixa de diálogo com controles que permitem que um usuário acesse e possivelmente altere dados. Talvez você queira desenvolver um aplicativo no qual o usuário seleciona em uma seleção de formulários. Normalmente, um aplicativo baseado em formulários permite que o usuário acesse formulários clicando em **novo** no menu **arquivo** . Um aplicativo baseado em caixa de diálogo, que não dá aos usuários acesso a uma **nova** opção no menu **arquivo** , também é considerado um aplicativo baseado em formulários.

Uma interface de documento único (SDI), aplicativo baseado em formulários permite que apenas uma instância de um formulário específico seja executada por vez. É possível executar diferentes formulários ao mesmo tempo de um aplicativo baseado em formulários SDI selecionando um novo formulário na **nova** opção no menu **arquivo** .

Se você criar uma MDI (interface de vários documentos), aplicativo baseado em formulários, o aplicativo será capaz de dar suporte a várias instâncias do mesmo formulário.

Se você criar um aplicativo com vários suporte a documentos de nível superior, a área de trabalho será o pai implícito do documento e o quadro do documento não será restrito à área do cliente do aplicativo. Você pode abrir várias instâncias do documento, cada uma com seu próprio quadro, menu e ícone de barra de tarefas. Você pode fechar as instâncias subsequentes de documentos individualmente, mas se você selecionar a opção **sair** no menu **arquivo** da instância inicial, o aplicativo fechará todas as instâncias.

Os aplicativos SDI, MDI e vários documentos de nível superior são baseados em formulários e usam a arquitetura de documento/exibição.

Qualquer aplicativo baseado em caixa de diálogo, por definição, é baseado em formulários. Um aplicativo baseado em caixa de diálogo não usa a arquitetura de documento/exibição, portanto, você deve gerenciar os métodos de criação e acesso para seus próprios formulários adicionais.

A classe base para aplicativos baseados em formulário é [CFormView](cformview-class.md). Se seu aplicativo tiver suporte a banco de dados, você também poderá selecionar qualquer classe derivada de `CFormView`. Um formulário é qualquer janela derivada de `CFormView` ou de qualquer classe que herda de `CFormView`.

Mesmo que você use uma classe base como [cvisualização](cview-class.md), você pode posteriormente tornar seus aplicativos baseados em formulários [adicionando uma classe MFC](adding-an-mfc-class.md) derivada de `CFormView`.

Depois de terminar com o assistente, o projeto será aberto e, se você `CFormView` tiver selecionado (ou uma classe herdada de `CFormView`) como sua classe base ou se tiver criado um aplicativo baseado em caixa C++ de diálogo, o Visual abrirá o editor de caixa de diálogo. Neste ponto, você está pronto para criar seu primeiro formulário.

### <a name="to-begin-creating-a-forms-based-mfc-executable"></a>Para começar a criar um executável MFC baseado em formulários

1. Siga as instruções em [criando um aplicativo MFC](creating-an-mfc-application.md) para um aplicativo MFC baseado em formulários.

1. Na página [tipo de aplicativo](application-type-mfc-application-wizard.md) do assistente de aplicativo do MFC, marque a caixa de seleção **documento/Exibir suporte à arquitetura** .

1. Selecione **um único documento**, **vários documentos**ou **vários documentos de nível superior**.

    > [!NOTE]
    >  Se você escolher um SDI, MDI ou vários aplicativos de interface de documento de nível superior, por padrão `CView` , o será definido como a classe base para a exibição do seu aplicativo na página [classes geradas](generated-classes-mfc-application-wizard.md) do assistente. Para criar um aplicativo baseado em formulários, você deve selecionar `CFormView` como a classe base para a exibição do aplicativo. Observe que o assistente não fornece suporte de impressão para um aplicativo baseado em formulários.

1. Defina outras opções de projeto desejadas nas outras páginas do assistente.

1. Clique em **concluir** para gerar o aplicativo de esqueleto.

Para obter mais informações, consulte:

- [Classes de exibição derivadas](../derived-view-classes-available-in-mfc.md)

- [Alternativas para a arquitetura de documento/exibição](../alternatives-to-the-document-view-architecture.md)

- [Opções de design do aplicativo](../application-design-choices.md)

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](mfc-application-wizard.md)<br/>
[Exibições de formulário](../form-views-mfc.md)<br/>
[Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](creating-a-file-explorer-style-mfc-application.md)<br/>
[Criando um aplicativo MFC no estilo de navegador da Web](creating-a-web-browser-style-mfc-application.md)
