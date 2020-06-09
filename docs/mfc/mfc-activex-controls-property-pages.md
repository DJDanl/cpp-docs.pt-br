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
ms.openlocfilehash: 3d22085daa503a7c778111718445920f98b98a89
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615435"
---
# <a name="mfc-activex-controls-property-pages"></a>Controles ActiveX MFC: páginas de propriedade

As páginas de propriedades permitem que um usuário controle ActiveX exiba e altere as propriedades do controle ActiveX. Essas propriedades são acessadas invocando-se uma caixa de diálogo Propriedades de controle, que contém uma ou mais páginas de propriedades que fornecem uma interface gráfica personalizada para exibir e editar as propriedades de controle.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

As páginas de propriedades do controle ActiveX são exibidas de duas maneiras:

- Quando o verbo de propriedades do controle (**OLEIVERB_PROPERTIES**) é invocado, o controle abre uma caixa de diálogo de propriedade modal que contém as páginas de propriedades do controle.

- O contêiner pode exibir sua própria caixa de diálogo sem janela restrita que mostra as páginas de propriedades do controle selecionado.

A caixa de diálogo Propriedades (ilustrada na figura a seguir) consiste em uma área para exibir a página de propriedades atual, guias para alternar entre páginas de propriedades e uma coleção de botões que executam tarefas comuns, como fechar a caixa de diálogo da página de propriedades, cancelar quaisquer alterações feitas ou aplicar imediatamente quaisquer alterações ao controle ActiveX.

![Caixa de diálogo Propriedades para Circ3](../mfc/media/vc373i1.gif "Caixa de diálogo Propriedades para Circ3") <br/>
Caixa de diálogo Propriedades

Este artigo aborda os tópicos relacionados ao uso de páginas de propriedades em um controle ActiveX. Elas incluem:

- [Implementando a página de propriedades padrão para um controle ActiveX](#_core_implementing_the_default_property_page)

- [Adicionando controles a uma página de propriedades](#_core_adding_controls_to_a_property_page)

- [Personalizando a função DoDataExchange](#_core_customizing_the_dodataexchange_function)

Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os seguintes artigos:

- [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](mfc-activex-controls-adding-another-custom-property-page.md)

- [Controles ActiveX do MFC: usando páginas de propriedade de estoque](mfc-activex-controls-using-stock-property-pages.md)

Para obter informações sobre como usar folhas de propriedades em um aplicativo MFC que não seja um controle ActiveX, consulte [folhas de propriedades](property-sheets-mfc.md).

## <a name="implementing-the-default-property-page"></a><a name="_core_implementing_the_default_property_page"></a>Implementando a página de propriedades padrão

Se você usar o assistente de controle ActiveX para criar seu projeto de controle, o assistente de controle ActiveX fornecerá uma classe de página de propriedades padrão para o controle derivado da [classe COlePropertyPage](reference/colepropertypage-class.md). Inicialmente, essa página de propriedades está em branco, mas você pode adicionar qualquer controle de caixa de diálogo ou conjunto de controles a ela. Como o assistente de controle ActiveX cria apenas uma classe de página de propriedades por padrão, as classes de página de propriedades adicionais (também derivadas de `COlePropertyPage` ) devem ser criadas usando modo de exibição de classe. Para obter mais informações sobre esse procedimento, consulte [controles ActiveX do MFC: adicionando outra página de propriedades Personalizada](mfc-activex-controls-adding-another-custom-property-page.md).

A implementação de uma página de Propriedades (nesse caso, o padrão) é um processo de três etapas:

#### <a name="to-implement-a-property-page"></a>Para implementar uma página de propriedades

1. Adicione uma `COlePropertyPage` classe derivada ao projeto de controle. Se o projeto foi criado usando o assistente de controle ActiveX (como neste caso), a classe de página de propriedades padrão já existe.

1. Use o editor de caixa de diálogo para adicionar qualquer controle ao modelo de página de propriedades.

1. Personalize a `DoDataExchange` função da `COlePropertyPage` classe derivada para trocar valores entre o controle de página de propriedades e o controle ActiveX.

Para fins de exemplo, os procedimentos a seguir usam um controle simples (chamado "Sample"). O exemplo foi criado usando o assistente de controle ActiveX e contém apenas a propriedade de legenda de estoque.

## <a name="adding-controls-to-a-property-page"></a><a name="_core_adding_controls_to_a_property_page"></a>Adicionando controles a uma página de propriedades

#### <a name="to-add-controls-to-a-property-page"></a>Para adicionar controles a uma página de propriedades

1. Com seu projeto de controle aberto, abra Modo de Exibição de Recursos.

1. Clique duas vezes no ícone do diretório de **diálogo** .

1. Abra a caixa de diálogo IDD_PROPPAGE_SAMPLE.

   O assistente de controle ActiveX acrescenta o nome do projeto ao final da ID da caixa de diálogo, neste caso, de exemplo.

1. Arraste e solte o controle selecionado da caixa de ferramentas para a área de caixas de diálogo.

1. Para este exemplo, um controle de rótulo de texto "Caption:" e um controle de caixa de edição com um identificador de IDC_CAPTION são suficientes.

1. Clique em **salvar** na barra de ferramentas para salvar as alterações.

Agora que a interface do usuário foi modificada, você precisa vincular a caixa de edição com a propriedade Caption. Isso é feito na seção a seguir editando a `CSamplePropPage::DoDataExchange` função.

## <a name="customizing-the-dodataexchange-function"></a><a name="_core_customizing_the_dodataexchange_function"></a>Personalizando a função DoDataExchange

Sua página de propriedades [CWnd::D odataexchange](reference/cwnd-class.md#dodataexchange) function permite vincular valores de página de propriedades com os valores reais das propriedades no controle. Para estabelecer links, você deve mapear os campos de página de propriedades apropriados para suas respectivas propriedades de controle.

Esses mapeamentos são implementados usando a página de propriedades **DDP_** funções. As funções **DDP_** funcionam como as **DDX_** funções usadas em caixas de diálogo padrão do MFC, com uma exceção. Além da referência a uma variável de membro, **DDP_** funções assumem o nome da propriedade de controle. A seguir está uma entrada típica na `DoDataExchange` função para uma página de propriedades.

[!code-cpp[NVC_MFC_AxUI#31](codesnippet/cpp/mfc-activex-controls-property-pages_1.cpp)]

Essa função associa a variável de membro *m_caption* da página de propriedades à legenda, usando a `DDP_TEXT` função.

Depois de inserir o controle de página de propriedades, você precisa estabelecer um vínculo entre o controle de página de propriedades, IDC_CAPTION e a propriedade de controle real, legenda, usando a `DDP_Text` função, conforme descrito acima.

As [páginas de propriedades](reference/property-pages-mfc.md) estão disponíveis para outros tipos de controle de caixa de diálogo, como caixas de seleção, botões de opção e caixas de listagem. A tabela a seguir lista todo o conjunto de páginas de propriedades **DDP_** funções e suas finalidades:

### <a name="property-page-functions"></a>Funções de página de propriedades

|Nome da função|Use esta função para vincular|
|-------------------|-------------------------------|
|`DDP_CBIndex`|O índice da cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade de controle.|
|`DDP_CBString`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade de controle. A cadeia de caracteres selecionada pode começar com as mesmas letras do valor da propriedade, mas não precisa fazer a correspondência completa.|
|`DDP_CBStringExact`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade de controle. A cadeia de caracteres selecionada e o valor da cadeia de caracteres da propriedade devem corresponder exatamente.|
|`DDP_Check`|Uma caixa de seleção com uma propriedade de controle.|
|`DDP_LBIndex`|O índice da cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade de controle.|
|`DDP_LBString`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade de controle. A cadeia de caracteres selecionada pode começar com as mesmas letras do valor da propriedade, mas não precisa fazer a correspondência completa.|
|`DDP_LBStringExact`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade de controle. A cadeia de caracteres selecionada e o valor da cadeia de caracteres da propriedade devem corresponder exatamente.|
|`DDP_Radio`|Um botão de opção com uma propriedade de controle.|
|`DDP_Text`|Texto com uma propriedade de controle.|

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Classe COlePropertyPage](reference/colepropertypage-class.md)
