---
title: 'Controles ActiveX MFC: páginas de propriedade'
ms.date: 11/19/2018
helpviewer_keywords:
- DDP_ functions [MFC]
- MFC ActiveX controls [MFC], properties
- property pages [MFC], MFC ActiveX controls
- DoDataExchange method [MFC]
- OLEIVERB_PROPERTIES
- CPropertyPageDialog class [MFC]
- MFC ActiveX controls [MFC], property pages
ms.assetid: 1506f87a-9fd6-4505-8380-0dbc9636230e
ms.openlocfilehash: c31d13e03483f8632f17a526da75ebe8e21bccbf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364574"
---
# <a name="mfc-activex-controls-property-pages"></a>Controles ActiveX MFC: páginas de propriedade

As páginas de propriedade permitem que um usuário de controle ActiveX visualize e altere as propriedades de controle do ActiveX. Essas propriedades são acessadas invocando uma caixa de diálogo propriedades de controle, que contém uma ou mais páginas de propriedade que fornecem uma interface gráfica personalizada para visualização e edição das propriedades de controle.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

As páginas de propriedade de controle ActiveX são exibidas de duas maneiras:

- Quando o verbo Propriedades do controle **(OLEIVERB_PROPERTIES)** é invocado, o controle abre uma caixa de diálogo de propriedade modal que contém as páginas de propriedade do controle.

- O contêiner pode exibir sua própria caixa de diálogo modeless que mostra as páginas de propriedade do controle selecionado.

A caixa de diálogo propriedades (ilustrada na figura a seguir) consiste em uma área para exibir a página de propriedade atual, guias para alternar entre páginas de propriedade e uma coleção de botões que executam tarefas comuns, como fechar a caixa de diálogo da página de propriedade, cancelar quaisquer alterações feitas ou aplicar imediatamente quaisquer alterações no controle ActiveX.

![Caixa de diálogo de propriedades para Circ3](../mfc/media/vc373i1.gif "Caixa de diálogo de propriedades para Circ3") <br/>
Caixa de diálogo de propriedades

Este artigo abrange tópicos relacionados ao uso de páginas de propriedade em um controle ActiveX. Eles incluem:

- [Implementando a página de propriedade padrão para um controle ActiveX](#_core_implementing_the_default_property_page)

- [Adicionando controles a uma página de propriedade](#_core_adding_controls_to_a_property_page)

- [Personalização da função DoDataExchange](#_core_customizing_the_dodataexchange_function)

Para obter mais informações sobre o uso de páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)

- [Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)

Para obter informações sobre o uso de folhas de propriedade em um aplicativo MFC que não seja um controle ActiveX, consulte [Folhas de propriedade](../mfc/property-sheets-mfc.md).

## <a name="implementing-the-default-property-page"></a><a name="_core_implementing_the_default_property_page"></a>Implementando a página de propriedade padrão

Se você usar o ActiveX Control Wizard para criar seu projeto de controle, o ActiveX Control Wizard fornecerá uma classe de página de propriedade padrão para o controle derivado da [COlePropertyPage Class](../mfc/reference/colepropertypage-class.md). Inicialmente, esta página de propriedade está em branco, mas você pode adicionar qualquer controle de caixa de diálogo ou conjunto de controles a ela. Como o ActiveX Control Wizard cria apenas uma classe de página de `COlePropertyPage`propriedade por padrão, classes adicionais de página de propriedade (também derivadas) devem ser criadas usando a exibição de classe. Para obter mais informações sobre este procedimento, consulte [Controles MFC ActiveX: Adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md).

A implementação de uma página de propriedade (neste caso, o padrão) é um processo de três etapas:

#### <a name="to-implement-a-property-page"></a>Para implementar uma página de propriedade

1. Adicione `COlePropertyPage`uma classe derivada ao projeto de controle. Se o projeto foi criado usando o Assistente de Controle ActiveX (como neste caso), a classe de página de propriedade padrão já existe.

1. Use o editor de diálogo para adicionar quaisquer controles ao modelo da página de propriedade.

1. Personalize `DoDataExchange` a função `COlePropertyPage`da classe derivada para trocar valores entre o controle da página de propriedade e o controle ActiveX.

Por exemplo, os procedimentos a seguir usam um controle simples (chamado "Amostra"). A amostra foi criada usando o ActiveX Control Wizard e contém apenas a propriedade stock Caption.

## <a name="adding-controls-to-a-property-page"></a><a name="_core_adding_controls_to_a_property_page"></a>Adicionando controles a uma página de propriedade

#### <a name="to-add-controls-to-a-property-page"></a>Para adicionar controles a uma página de propriedade

1. Com seu projeto de controle aberto, abra a Visualização de Recursos.

1. Clique duas vezes no ícone do diretório **Diálogo.**

1. Abra a caixa de diálogo IDD_PROPPAGE_SAMPLE.

   O Assistente de Controle ActiveX anexa o nome do projeto até o final do ID de diálogo, neste caso, Sample.

1. Arraste e solte o controle selecionado da caixa de ferramentas na área da caixa de diálogo.

1. Para este exemplo, um controle de etiqueta de texto "Caption :" e um controle de caixa de edição com um identificador IDC_CAPTION são suficientes.

1. Clique em **Salvar** na barra de ferramentas para salvar suas alterações.

Agora que a interface do usuário foi modificada, você precisa vincular a caixa de edição com a propriedade Caption. Isso é feito na seção `CSamplePropPage::DoDataExchange` a seguir, editando a função.

## <a name="customizing-the-dodataexchange-function"></a><a name="_core_customizing_the_dodataexchange_function"></a>Personalização da função DoDataExchange

Sua página de propriedade [CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) permite vincular valores de página de propriedade com os valores reais das propriedades no controle. Para estabelecer links, você deve mapear os campos de página de propriedade apropriados para suas respectivas propriedades de controle.

Esses mapeamentos são implementados usando as funções DDP_ página **de** propriedade. As **funções DDP_** funcionam como as **funções DDX_** usadas em diálogos MFC padrão, com uma exceção. Além da referência a uma variável membro, **DDP_** funções levam o nome da propriedade de controle. A seguir está uma `DoDataExchange` entrada típica na função para uma página de propriedade.

[!code-cpp[NVC_MFC_AxUI#31](../mfc/codesnippet/cpp/mfc-activex-controls-property-pages_1.cpp)]

Esta função associa a variável membro da página de `DDP_TEXT` *m_caption* da propriedade com a Legenda, usando a função.

Depois de ter o controle da página de propriedade inserido, você precisa estabelecer um link entre o `DDP_Text` controle da página de propriedade, IDC_CAPTION, e a propriedade de controle real, Caption, usando a função conforme descrito acima.

[As páginas de propriedade](../mfc/reference/property-pages-mfc.md) estão disponíveis para outros tipos de controle de diálogo, como caixas de seleção, botões de rádio e caixas de lista. A tabela abaixo lista todo o conjunto de funções **de página de propriedade DDP_** e seus propósitos:

### <a name="property-page-functions"></a>Funções da página de propriedades

|Nome da função|Use esta função para vincular|
|-------------------|-------------------------------|
|`DDP_CBIndex`|O índice de string selecionado em uma caixa de combinação com uma propriedade de controle.|
|`DDP_CBString`|A seqüência selecionada em uma caixa combo com uma propriedade de controle. A seqüência selecionada pode começar com as mesmas letras que o valor da propriedade, mas não precisa corresponder totalmente.|
|`DDP_CBStringExact`|A seqüência selecionada em uma caixa combo com uma propriedade de controle. A seqüência selecionada e o valor da seqüência da propriedade devem corresponder exatamente.|
|`DDP_Check`|Uma caixa de seleção com propriedade de controle.|
|`DDP_LBIndex`|O índice de string selecionado em uma caixa de lista com uma propriedade de controle.|
|`DDP_LBString`|A seqüência selecionada em uma caixa de lista com uma propriedade de controle. A seqüência selecionada pode começar com as mesmas letras que o valor da propriedade, mas não precisa corresponder totalmente.|
|`DDP_LBStringExact`|A seqüência selecionada em uma caixa de lista com uma propriedade de controle. A seqüência selecionada e o valor da seqüência da propriedade devem corresponder exatamente.|
|`DDP_Radio`|Um botão de rádio com propriedade de controle.|
|`DDP_Text`|Texto com uma propriedade de controle.|

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Classe COlePropertyPage](../mfc/reference/colepropertypage-class.md)
