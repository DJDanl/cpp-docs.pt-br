---
title: Criando um aplicativo MFC com base em formulários | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfcforms.project
dev_langs:
- C++
helpviewer_keywords:
- applications [MFC], forms-based
- forms-based applications [MFC]
ms.assetid: 048d2f7d-b60d-4386-ad8e-71d49af9c05e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 692370e06668152cb6f5d5ecc762a3bbe991af08
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46374651"
---
# <a name="creating-a-forms-based-mfc-application"></a>Criando um aplicativo MFC com base em formulários

Um formulário é uma caixa de diálogo com controles que permitem que um usuário acessar e, possivelmente, alterar dados. Você talvez queira desenvolver um aplicativo no qual o usuário seleciona em uma seleção de formulários. Normalmente, um aplicativo baseado em formulários permite que os formulários de acesso do usuário por clique **New** da **arquivo** menu. Um aplicativo baseado em diálogo, que não dá aos usuários acesso a um **New** opção a **arquivo** menu, também é considerado um aplicativo baseado em formulários.

Uma interface de documento único (SDI), baseada em formulários de aplicativo permite que apenas uma instância de um formulário específico para ser executado por vez. É possível executar diferentes formas ao mesmo tempo, de um aplicativo com base em formulários de SDI, selecionando um novo formulário do **New** opção a **arquivo** menu.

Se você criar uma interface de documentos múltiplos (MDI), baseada em formulários de aplicativo, o aplicativo será capaz de dar suporte a várias instâncias do mesmo formulário.

Se você criar um aplicativo com suporte a vários documentos de nível superior, a área de trabalho é o pai implícito para o documento e o quadro do documento não está restrito a área de cliente do aplicativo. Você pode abrir várias instâncias do documento, cada um com seu próprio quadro, o menu e o ícone da barra de tarefas. Você pode fechar instâncias subsequentes de documentos individualmente, mas se você selecionar o **Exit** opção a **arquivo** menu da instância inicial, o aplicativo fecha todas as instâncias.

SDI e MDI vários aplicativos de nível superior do documento são todas as formas com base e usam a arquitetura de documento/exibição.

Qualquer aplicativo baseado em caixa de diálogo, por definição, é baseada em formulários. Um aplicativo baseado em caixa de diálogo não usa a arquitetura de documento/exibição, portanto, você deve gerenciar os métodos de criação e o acesso para seus próprios formulários adicionais.

É a classe base para aplicativos baseados em formulário [CFormView](../../mfc/reference/cformview-class.md). Se seu aplicativo tiver suporte do banco de dados, você também pode selecionar qualquer classe que deriva de `CFormView`. Um formulário é qualquer janela derivada `CFormView` ou de qualquer classe que herda de `CFormView`.

Mesmo se você usar uma classe base, como [CView](../../mfc/reference/cview-class.md), mais tarde você pode fazer com que o seus aplicativos com base em formulários pelo [adicionando uma classe MFC](../../mfc/reference/adding-an-mfc-class.md) derivado de `CFormView` e verificando o **gerar DocTemplate recursos** caixa de seleção de [MFC Class Wizard](../../mfc/reference/document-template-strings-mfc-add-class-wizard.md).

Depois que você concluir o assistente, seu projeto é aberto, e se você selecionou `CFormView` (ou uma classe que herda de `CFormView`) como sua classe base ou se você criou um aplicativo baseado em caixa de diálogo, o Visual C++ abre o editor de caixa de diálogo. Neste ponto, você está pronto para criar o primeiro formulário.

### <a name="to-begin-creating-a-forms-based-mfc-executable"></a>Para começar a criar um executável MFC baseada em formulários

1. Siga as instruções em [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).

1. No Assistente de aplicativo MFC [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) página, selecione o **suporte de arquitetura de documento/exibição** caixa de seleção.

1. Selecione **único documento**, **vários documentos**, ou **vários documentos de nível superior**.

    > [!NOTE]
    >  Se você escolheu um SDI, MDI ou vários aplicativos de interface de nível superior do documento, por padrão, `CView` é definido como a classe base para o modo de exibição do seu aplicativo na [Classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) página do assistente. Para criar um aplicativo baseado em formulários, você deve selecionar `CFormView` como a classe base para o modo de exibição do aplicativo. Observe que o assistente não fornece nenhum suporte de impressão para um aplicativo baseado em formulários.

1. Defina outras opções de projeto desejado nas outras páginas do assistente.

1. Clique em **concluir** para gerar o aplicativo de esqueleto.

Para obter mais informações, consulte:

- [Classes de exibição derivadas](../../mfc/derived-view-classes-available-in-mfc.md)

- [Alternativas à arquitetura de documento/exibição](../../mfc/alternatives-to-the-document-view-architecture.md)

- [Opções de design do aplicativo](../../mfc/application-design-choices.md)

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)<br/>
[Modos de exibição de formulário](../../mfc/form-views-mfc.md)<br/>
[Criando um aplicativo MFC no estilo de Gerenciador de Arquivos](../../mfc/reference/creating-a-file-explorer-style-mfc-application.md)<br/>
[Criando um aplicativo MFC no estilo de navegador da Web](../../mfc/reference/creating-a-web-browser-style-mfc-application.md)

