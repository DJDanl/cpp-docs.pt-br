---
title: Designer da faixa de opções (MFC)
ms.date: 11/19/2018
f1_keywords:
- vc.editors.ribbon.F1
helpviewer_keywords:
- Ribbon Designer (MFC)
- MFC Ribbon Designer
ms.assetid: 0806dfd6-7d11-471a-99e1-4072852231f9
ms.openlocfilehash: 8b66ff0f19392eb1685f8632a3fc4d9e90094304
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372796"
---
# <a name="ribbon-designer-mfc"></a>Designer da faixa de opções (MFC)

O Ribbon Designer permite criar e personalizar fitas em aplicativos MFC. Uma fita é um elemento de interface de usuário (UI) que organiza comandos em grupos lógicos. Esses grupos aparecem em guias separadas em uma tira na parte superior da janela. A fita substitui a barra de menu e as barras de ferramentas. Uma fita pode melhorar significativamente a usabilidade da aplicação. Para obter mais informações, consulte [Ribbons](/windows/win32/uxguide/cmd-ribbons). A ilustração a seguir mostra uma fita.

![Controle de recursos da fita MFC](../mfc/media/ribbon_no_callouts.png "Controle de recursos da fita MFC")

Nas versões anteriores do Visual Studio, as fitas tinham que ser criadas escrevendo código que usa as classes de fita MFC, como [CMFCRibbonBar Class](../mfc/reference/cmfcribbonbar-class.md). No Visual Studio 2010 e posterior, o designer de fitas fornece um método alternativo para construir fitas. Primeiro, crie e personalize uma fita como recurso. Em seguida, carregue o recurso de fita do código no aplicativo MFC. Você pode até usar recursos de fita e classes de fita MFC juntos. Por exemplo, você pode criar um recurso de fita e, em seguida, adicionar programáticamente mais elementos a ele em tempo de execução usando código.

## <a name="understanding-the-ribbon-designer"></a>Entendendo o Designer de Fita

O designer de fita cria e armazena a fita como um recurso. Quando você cria um recurso de fita, o designer de fita faz essas três coisas:

- Adiciona uma entrada no script de definição de recurso do projeto (*.rc). No exemplo a seguir, IDR_RIBBON é o nome único que identifica o recurso de fita, RT_RIBBON_XML é o tipo de recurso, e ribbon.mfcribbon-ms é o nome do arquivo de recurso.

```cpp
    IDR_RIBBON RT_RIBBON_XML      "res\\ribbon.mfcribbon-ms"
```

- Adiciona as definições de IDs de comando ao resource.h.

```
#define IDR_RIBBON            307
```

- Cria um arquivo de recurso de fita (*.mfcribbon-ms) que contém o código XML que define os botões, controles e atributos da fita. As alterações na fita no designer de fita são armazenadas no arquivo de recursos como XML. O exemplo de código a seguir \*mostra parte do conteúdo de um arquivo .mfcribbon-ms:

```
<RIBBON_BAR>
<ELEMENT_NAME>RibbonBar</ELEMENT_NAME>
<IMAGE>
<ID>
<NAME>IDB_BUTTONS</NAME>
<VALUE>113</VALUE>
</ID>
```

Para usar o recurso de fita no aplicativo MFC, carregue o recurso ligando para [CMFCRibbonBar::LoadFromResource](../mfc/reference/cmfcribbonbar-class.md#loadfromresource).

## <a name="creating-a-ribbon-by-using-the-ribbon-designer"></a>Criando uma fita usando o designer de fita

Estas são as duas maneiras de adicionar um recurso de fita ao seu projeto De MFC:

- Crie um aplicativo MFC e configure o Assistente de Projeto MFC para criar a fita. Para obter mais informações, consulte [Passo a Passo: Criando um aplicativo de fita usando mfc](../mfc/walkthrough-creating-a-ribbon-application-by-using-mfc.md).

- Em um projeto de MFC existente, crie um recurso de fita e carregue-o. Para obter mais informações, consulte [Passo a Passo: Atualizando o aplicativo de rabisco scribble Do MFC (Parte 1)](../mfc/walkthrough-updating-the-mfc-scribble-application-part-1.md).

Se o seu projeto já tiver uma fita codificada manualmente, o MFC tem funções que você pode usar para converter a fita existente em um recurso de fita. Para obter mais informações, [consulte Como converter uma fita MFC existente em um recurso de fita](../mfc/how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource.md).

> [!NOTE]
> As fitas não podem ser criadas em aplicativos baseados em diálogo. Para obter mais informações, consulte [Tipo de aplicativo, Assistente de aplicativo do MFC](../mfc/reference/application-type-mfc-application-wizard.md).

## <a name="customizing-ribbons"></a>Personalização de fitas

Para abrir uma fita no designer de fita, clique duas vezes no recurso de fita na exibição de recursos. No designer, você pode adicionar, remover e personalizar elementos na fita, no botão aplicativo ou na barra de ferramentas de acesso rápido. Você também pode vincular eventos, por exemplo, eventos de clique por botão e eventos de menu, a um método em sua aplicação.

A ilustração a seguir mostra os vários componentes do designer da fita.

![Designer da Faixa de Opções MFC](../mfc/media/ribbon_designer.png "Designer da Faixa de Opções MFC")

- **Caixa de ferramentas:** Contém controles que podem ser arrastados para a superfície do designer.

- **Superfície do designer:** Contém a representação visual do recurso da fita.

- ** [Assistente de classe](reference/mfc-class-wizard.md):** Lista os atributos do item selecionado na superfície do designer.

- **Janela de exibição de recursos:** Exibe os recursos que incluem recursos de fita, em seu projeto.

- **Barra de ferramentas do editor de fita:** Contém comandos que permitem visualizar a fita e alterar seu tema visual.

Os seguintes tópicos descrevem como usar os recursos no designer de fita:

- [Como personalizar o botão do aplicativo](../mfc/how-to-customize-the-application-button.md)

- [Como personalizar a barra de ferramentas de acesso rápido](../mfc/how-to-customize-the-quick-access-toolbar.md)

- [Como adicionar controles de faixa de opções e manipuladores de evento](../mfc/how-to-add-ribbon-controls-and-event-handlers.md)

- [Como carregar um recurso da faixa de opções de um aplicativo MFC](../mfc/how-to-load-a-ribbon-resource-from-an-mfc-application.md)

## <a name="definitions-of-ribbon-elements"></a>Definições de Elementos de Fita

![Fita MFC](../mfc/media/ribbon.png "Fita MFC")

- **Botão de aplicação:** O botão que aparece no canto superior esquerdo de uma fita. O botão Aplicativo substitui o menu Arquivo e é visível mesmo quando a fita é minimizada. Quando o botão é clicado, um menu que tem uma lista de comandos é exibido.

- **Barra de ferramentas de acesso rápido:** Uma pequena barra de ferramentas personalizável que exibe comandos frequentemente usados.

- **Categoria**: O agrupamento lógico que representa o conteúdo de uma guia de fita.

- **Botão Padrão da categoria:** O botão que aparece na fita quando a fita é minimizada. Quando o botão é clicado, a categoria reaparece como um menu.

- **Painel:** Uma área da barra de fita que exibe um grupo de controles relacionados. Cada categoria de fita contém um ou mais painéis de fita.

- **Elementos da fita:** Controles nos painéis, por exemplo, botões e caixas de combinação. Para ver os vários controles que podem ser hospedados em uma fita, consulte [RibbonGadgets Sample: Ribbon Gadgets Application](../overview/visual-cpp-samples.md).

## <a name="see-also"></a>Confira também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)
