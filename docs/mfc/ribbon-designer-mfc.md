---
title: Designer da faixa de opções (MFC)
ms.date: 11/19/2018
f1_keywords:
- vc.editors.ribbon.F1
helpviewer_keywords:
- Ribbon Designer (MFC)
- MFC Ribbon Designer
ms.assetid: 0806dfd6-7d11-471a-99e1-4072852231f9
ms.openlocfilehash: 5740b2f93f451a74407483c98ce5bf547b79bf35
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58769479"
---
# <a name="ribbon-designer-mfc"></a>Designer da faixa de opções (MFC)

O Designer de faixa de opções permite que você crie e personalize faixas de opções em aplicativos MFC. Uma faixa de opções é um elemento de interface do usuário do usuário que organiza comandos em grupos lógicos. Esses grupos aparecem em guias separadas em uma faixa na parte superior da janela. A faixa de opções substitui a barra de menus e barras de ferramentas. Uma faixa de opções pode melhorar significativamente a usabilidade do aplicativo. Para obter mais informações, consulte [faixas de opções](/windows/desktop/uxguide/cmd-ribbons). A ilustração a seguir mostra uma faixa de opções.

![Controle de recurso de faixa de opções do MFC](../mfc/media/ribbon_no_callouts.png "controle de recurso de faixa de opções do MFC")

Em versões anteriores do Visual Studio, as faixas tinham que ser criadas escrevendo código que usa as classes de faixa de opções do MFC, como [classe CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md). No Visual Studio 2010 e posterior, o designer de faixa de opções fornece um método alternativo para a criação de faixas de opções. Primeiro, crie e personalize uma fita como um recurso. Em seguida, carregue o recurso de faixa de opções do código no aplicativo MFC. Você pode até usar recursos de faixa de opções e classes de faixa de opções do MFC juntos. Por exemplo, você pode criar um recurso de faixa de opções e, em seguida, adicionar programaticamente mais elementos a ele em tempo de execução por meio de código.

## <a name="understanding-the-ribbon-designer"></a>Noções básicas sobre o Designer de faixa de opções

O designer de faixa de opções cria e armazena a faixa de opções como um recurso. Quando você cria um recurso de faixa de opções, o designer de faixa de opções faz o seguinte:

- Adiciona uma entrada no script de definição de recurso de projeto (*. rc). No exemplo a seguir, IDR_RIBBON é o nome exclusivo que identifica o recurso de faixa de opções, RT_RIBBON_XML é o tipo de recurso e mfcribbon-ms é o nome do arquivo de recurso.

```
    IDR_RIBBON RT_RIBBON_XML      "res\\ribbon.mfcribbon-ms"
```

- Adiciona as definições de IDs de comando a Resource. h.

```
#define IDR_RIBBON            307
```

- Cria um arquivo de recurso de faixa de opções (*. mfcribbon-ms) que contém o código XML que define os botões, controles e atributos da faixa de opções. As alterações à faixa de opções no designer de faixa de opções são armazenadas no arquivo de recurso como XML. O exemplo de código a seguir mostra parte do conteúdo de um \*. mfcribbon-ms arquivo:

```
<RIBBON_BAR>
<ELEMENT_NAME>RibbonBar</ELEMENT_NAME>
<IMAGE>
<ID>
<NAME>IDB_BUTTONS</NAME>
<VALUE>113</VALUE>
</ID>
```

Para usar o recurso de faixa de opções em seu aplicativo do MFC, carregue o recurso chamando [CMFCRibbonBar::LoadFromResource](../mfc/reference/cmfcribbonbar-class.md#loadfromresource).

## <a name="creating-a-ribbon-by-using-the-ribbon-designer"></a>Criando uma faixa de opções usando o Designer de faixa de opções

Estas são as duas maneiras de adicionar um recurso de faixa de opções ao seu projeto do MFC:

- Criar um aplicativo do MFC e configurar o Assistente de projeto do MFC para criar a faixa de opções. Para obter mais informações, confira [Passo a passo: Criando um aplicativo de faixa de opções usando MFC](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).

- Em um projeto MFC existente, crie um recurso de faixa de opções e carregá-lo. Para obter mais informações, confira [Passo a passo: Atualizando o aplicativo de rabisco MFC (parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md).

Se seu projeto já possui uma faixa de opções manualmente codificada, o MFC tem funções que você pode usar para converter a faixa de opções existente a um recurso de faixa de opções. Para obter mais informações, confira [Como: Converter uma faixa de opções MFC existente em um recurso de faixa de opções](../mfc/how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource.md).

> [!NOTE]
>  Faixas de opções não podem ser criadas em aplicativos baseados na caixa de diálogo. Para obter mais informações, consulte [tipo de aplicativo, Assistente de aplicativo MFC](../mfc/reference/application-type-mfc-application-wizard.md).

## <a name="customizing-ribbons"></a>Personalizando faixas de opções

Para abrir uma faixa de opções no designer de faixa de opções, clique duas vezes o recurso de faixa de opções no modo de exibição de recursos. No designer, você pode adicionar, remover e personalizar elementos na faixa de opções, o botão do aplicativo ou a barra de ferramentas de acesso rápido. Você também pode vincular eventos, por exemplo, eventos de clique de botão e eventos de menu a um método em seu aplicativo.

A ilustração a seguir mostra os vários componentes no designer de faixa de opções.

![Designer de faixa de opções do MFC](../mfc/media/ribbon_designer.png "Designer de faixa de opções do MFC")

- **Caixa de ferramentas:** Contém os controles que podem ser arrastados para a superfície do designer.

- **Superfície do Designer:** Contém a representação visual do recurso da faixa de opções.

- **Janela de propriedades:** Lista os atributos do item que está selecionado na superfície do designer.

- **Janela de exibição de recurso:** Exibe os recursos que incluem recursos de faixa de opções, no seu projeto.

- **Barra de ferramentas do Editor de faixa de opções:** Contém comandos que permitem visualizar a faixa de opções e alterar seu tema visual.

Os tópicos a seguir descrevem como usar os recursos no designer de faixa de opções:

- [Como: Personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)

- [Como: Personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)

- [Como: Adicionar controles de faixa de opções e manipuladores de eventos](../mfc/how-to-add-ribbon-controls-and-event-handlers.md)

- [Como: Carregar um recurso de faixa de opções de um aplicativo do MFC](../mfc/how-to-load-a-ribbon-resource-from-an-mfc-application.md)

## <a name="definitions-of-ribbon-elements"></a>Definições de elementos de faixa de opções

![Faixa de opções do MFC](../mfc/media/ribbon.png "faixa de opções do MFC")

- **Botão do aplicativo:** O botão que aparece no canto superior esquerdo de uma faixa de opções. O botão aplicativo substitui o menu Arquivo e fica visível mesmo quando a fita estiver minimizada. Quando o botão é clicado, é exibido um menu que tem uma lista de comandos.

- **Barra de ferramentas de acesso rápida:** Comandos usados com uma barra de ferramentas pequeno e personalizável que exibe com frequência.

- **Categoria**: O agrupamento lógico que representa o conteúdo de uma guia de faixa de opções.

- **Botão padrão de categoria:** O botão que aparece na faixa de opções quando a faixa de opções é minimizada. Quando o botão é clicado, a categoria reaparece como um menu.

- **Painel:** Uma área da barra de faixa de opções que exibe um grupo de controles relacionados. Cada categoria de faixa de opções contém um ou mais painéis de faixa de opções.

- **Elementos de faixa de opções:** Controles nos painéis, por exemplo, botões e caixas de combinação. Para ver os diversos controles que podem ser hospedados em uma faixa de opções, consulte [exemplo de gadget de fita: Aplicativo de gadget de faixa de opções](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)
