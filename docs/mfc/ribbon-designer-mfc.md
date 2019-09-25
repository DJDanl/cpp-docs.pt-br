---
title: Designer da faixa de opções (MFC)
ms.date: 11/19/2018
f1_keywords:
- vc.editors.ribbon.F1
helpviewer_keywords:
- Ribbon Designer (MFC)
- MFC Ribbon Designer
ms.assetid: 0806dfd6-7d11-471a-99e1-4072852231f9
ms.openlocfilehash: a39a3a69b43eb06d67fc806e2d4fa9aec323b650
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/25/2019
ms.locfileid: "70907815"
---
# <a name="ribbon-designer-mfc"></a>Designer da faixa de opções (MFC)

O designer de faixa de faixas permite criar e personalizar as faixas de faixa em aplicativos MFC. Uma faixa é um elemento da interface do usuário que organiza os comandos em grupos lógicos. Esses grupos aparecem em guias separadas em uma faixa na parte superior da janela. A faixa de faixas substitui a barra de menus e as barras de ferramentas. Uma faixa de faixas pode melhorar significativamente a usabilidade do aplicativo. Para obter mais informações, consulte [Ribbons](/windows/win32/uxguide/cmd-ribbons). A ilustração a seguir mostra uma faixa de opções.

![Controle de recursos da faixa] de de MFC (../mfc/media/ribbon_no_callouts.png "Controle de recursos da faixa") de de MFC

Em versões anteriores do Visual Studio, as faixas de faixa tinham que ser criadas escrevendo um código que usa as classes de faixa de forma do MFC, como a [classe CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md). No Visual Studio 2010 e posteriores, o designer de faixa de faixas fornece um método alternativo para a criação de faixas de opção. Primeiro, crie e personalize uma faixa de uma como um recurso. Em seguida, carregue o recurso da faixa de medida do código no aplicativo do MFC. Você pode até mesmo usar os recursos da faixa de forma e as classes da faixa de uma MFC. Por exemplo, você pode criar um recurso de faixa de forma e, em seguida, adicionar com programação mais elementos a ele em tempo de execução usando código.

## <a name="understanding-the-ribbon-designer"></a>Noções básicas sobre o designer de faixa de das

O designer de faixa de faixas cria e armazena a faixa de faixas como um recurso. Ao criar um recurso de faixa de opções, o designer de faixa de opções faz estas três coisas:

- Adiciona uma entrada no script de definição de recurso do projeto (*. rc). No exemplo a seguir, IDR_RIBBON é o nome exclusivo que identifica o recurso da faixa de opções, RT_RIBBON_XML é o tipo de recurso e Ribbon. mfcribbon-MS é o nome do arquivo de recurso.

```
    IDR_RIBBON RT_RIBBON_XML      "res\\ribbon.mfcribbon-ms"
```

- Adiciona as definições de IDs de comando a Resource. h.

```
#define IDR_RIBBON            307
```

- Cria um arquivo de recurso da faixa de bits (*. mfcribbon-MS) que contém o código XML que define os botões, controles e atributos da faixa de,. As alterações na faixa de lista no designer de faixa de faixas são armazenadas no arquivo de recursos como XML. O exemplo de código a seguir mostra parte do conteúdo de \*um arquivo. mfcribbon-MS:

```
<RIBBON_BAR>
<ELEMENT_NAME>RibbonBar</ELEMENT_NAME>
<IMAGE>
<ID>
<NAME>IDB_BUTTONS</NAME>
<VALUE>113</VALUE>
</ID>
```

Para usar o recurso da faixa de faixas em seu aplicativo MFC, carregue o recurso chamando [CMFCRibbonBar:: LoadFromResource](../mfc/reference/cmfcribbonbar-class.md#loadfromresource).

## <a name="creating-a-ribbon-by-using-the-ribbon-designer"></a>Criando uma faixa de faixas usando o designer de faixa de faixas

Essas são as duas maneiras de adicionar um recurso de faixa de opções ao seu projeto do MFC:

- Crie um aplicativo MFC e configure o assistente de projeto MFC para criar a faixa de uma. Para obter mais informações, confira [Passo a passo: Criando um aplicativo de faixa de faixas](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md)usando o MFC.

- Em um projeto existente do MFC, crie um recurso da faixa de recursos e carregue-o. Para obter mais informações, confira [Passo a passo: Atualizando o aplicativo de rabisco do MFC (](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md)parte 1).

Se o seu projeto já tiver uma faixa de recursos codificada manualmente, o MFC tem funções que você pode usar para converter a faixa de faixas existente em um recurso da faixa de faixas. Para obter mais informações, confira [Como: Converter uma faixa de faixas do MFC existente em](../mfc/how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource.md)um recurso da faixa de faixas.

> [!NOTE]
>  As faixas de faixa não podem ser criadas em aplicativos baseados em caixas de diálogo. Para obter mais informações, consulte [tipo de aplicativo, assistente de aplicativo do MFC](../mfc/reference/application-type-mfc-application-wizard.md).

## <a name="customizing-ribbons"></a>Personalizando faixas de as

Para abrir uma faixa de bits no designer de faixa de faixas, clique duas vezes no recurso da faixa de das Modo de Exibição de Recursos. No designer, você pode adicionar, remover e personalizar elementos na faixa de guia, no botão aplicativo ou na barra de ferramentas de acesso rápido. Você também pode vincular eventos, por exemplo, eventos de clique de botão e eventos de menu, a um método em seu aplicativo.

A ilustração a seguir mostra os vários componentes no designer de faixa de opções.

![Designer de faixa de da MFC](../mfc/media/ribbon_designer.png "Designer de faixa de da MFC")

- **Guia** Contém controles que podem ser arrastados para a superfície do designer.

- **Superfície do designer:** Contém a representação visual do recurso da faixa de faixas.

- **[Assistente de classe](reference/mfc-class-wizard.md):** Lista os atributos do item que está selecionado na superfície do designer.

- **Modo de Exibição de Recursos janela:** Exibe os recursos que incluem os recursos da faixa de medida em seu projeto.

- **Barra de ferramentas do editor de faixa:** Contém comandos que permitem visualizar a faixa de visualização e alterar seu tema visual.

Os tópicos a seguir descrevem como usar os recursos no designer de faixa de opções:

- [Como: personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)

- [Como: personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)

- [Como: adicionar controles de faixa de opções e manipuladores de evento](../mfc/how-to-add-ribbon-controls-and-event-handlers.md)

- [Como: carregar um recurso da faixa de opções de um aplicativo MFC](../mfc/how-to-load-a-ribbon-resource-from-an-mfc-application.md)

## <a name="definitions-of-ribbon-elements"></a>Definições de elementos da faixa de faixas

![Faixa de faixas do MFC](../mfc/media/ribbon.png "Faixa de faixas do MFC")

- **Botão do aplicativo:** O botão que aparece no canto superior esquerdo de uma faixa de bits. O botão aplicativo substitui o menu arquivo e fica visível mesmo quando a faixa de faixas é minimizada. Quando o botão é clicado, um menu que tem uma lista de comandos é exibido.

- **Barra de ferramentas de acesso rápido:** Uma barra de ferramentas pequena e personalizável que exibe comandos usados com frequência.

- **Categoria**: O agrupamento lógico que representa o conteúdo de uma guia da faixa de uma.

- **Botão padrão da categoria:** O botão que aparece na faixa de faixas quando a faixa de faixas é minimizada. Quando o botão é clicado, a categoria reaparece como um menu.

- Uma área da barra da faixa de faixas que exibe um grupo de controles relacionados. Cada categoria da faixa de faixas contém um ou mais painéis da faixa de faixas.

- **Elementos da faixa de faixas:** Controles nos painéis, por exemplo, botões e caixas de combinação. Para ver os vários controles que podem ser hospedados em uma faixa de [faixas, consulte RibbonGadgets Sample: Aplicativo](../overview/visual-cpp-samples.md)de gadgets de faixa de faixas.

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)
