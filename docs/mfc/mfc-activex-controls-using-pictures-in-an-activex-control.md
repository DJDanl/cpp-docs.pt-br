---
title: 'Controles ActiveX MFC: usando imagens em um controle ActiveX'
ms.date: 11/04/2016
f1_keywords:
- LPPICTUREDISP
helpviewer_keywords:
- OnDraw method, MFC ActiveX controls
- MFC ActiveX controls [MFC], pictures
- OnDraw method [MFC]
- OnResetState method [MFC]
- CLSID_CPicturePropPage [MFC]
ms.assetid: 2e49735c-21b9-4442-bb3d-c82ef258eec9
ms.openlocfilehash: 1f78823f39417ff6928a1b915d83507bc1ac9526
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358291"
---
# <a name="mfc-activex-controls-using-pictures-in-an-activex-control"></a>Controles ActiveX MFC: usando imagens em um controle ActiveX

Este artigo descreve o tipo de imagem comum e como implementá-lo no seu controle ActiveX. Os tópicos incluem:

- [Visão geral das propriedades de imagem personalizadas](#_core_overview_of_custom_picture_properties)

- [Implementando uma propriedade de imagem personalizada no seu controle ActiveX](#_core_implementing_a_custom_picture_property_in_your_activex_control)

- [Adições ao seu projeto de controle](#_core_additions_to_your_control_project)

## <a name="overview-of-custom-picture-properties"></a><a name="_core_overview_of_custom_picture_properties"></a>Visão geral das propriedades de imagem personalizadas

Um tipo de imagem é um de um grupo de tipos comuns a alguns controles ActiveX. O tipo Imagem lida com metaarquivos, bitmaps ou ícones e permite que o usuário especifique uma imagem a ser exibida em um controle ActiveX. As propriedades de Imagem personalizada são implementadas usando um objeto de imagem e funções Get/Set que permitem ao usuário de controle acesso à propriedade Imagem. Os usuários de controle acessam a propriedade Imagem personalizada usando a página de propriedade stock Picture.

Além do tipo de imagem padrão, os tipos Fonte e Cor também estão disponíveis. Para obter mais informações sobre o uso do tipo de fonte padrão no controle do ActiveX, consulte o artigo [MFC ActiveX Controls: Using Fonts](../mfc/mfc-activex-controls-using-fonts.md).

As classes de controle ActiveX fornecem vários componentes que você pode usar para implementar a propriedade Picture dentro do controle. Esses componentes incluem:

- A classe [CPictureHolder.](../mfc/reference/cpictureholder-class.md)

   Esta classe fornece fácil acesso ao objeto de imagem e funcionalidade para o item exibido pela propriedade Imagem personalizada.

- Suporte para propriedades do tipo **LPPICTUREDISP,** implementado com funções Get/Set.

   Usando a exibição de classe, você pode adicionar rapidamente uma propriedade personalizada ou propriedades que suporta mera forma. Para obter mais informações sobre a adição de propriedades de controle ActiveX com o Class View, consulte o artigo [MFC ActiveX Controls: Properties](../mfc/mfc-activex-controls-properties.md).

- Uma página de propriedade que manipula a propriedade ou propriedades picture de um controle.

   Esta página de propriedade faz parte de um grupo de páginas de propriedade de ações disponíveis para controles ActiveX. Para obter mais informações sobre páginas de propriedade de controle do ActiveX, consulte o artigo [MFC ActiveX Controls: Usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)

## <a name="implementing-a-custom-picture-property-in-your-activex-control"></a><a name="_core_implementing_a_custom_picture_property_in_your_activex_control"></a>Implementando uma propriedade de imagem personalizada no seu controle ActiveX

Quando você tiver concluído as etapas descritas nesta seção, o controle pode exibir imagens escolhidas pelo usuário. O usuário pode alterar a imagem exibida usando uma página de propriedade que mostra a imagem atual e tem um botão Procurar que permite ao usuário selecionar diferentes imagens.

Uma propriedade de imagem personalizada é implementada usando um processo semelhante ao usado para implementar outras propriedades, a principal diferença é que a propriedade personalizada deve suportar um tipo de Imagem. Como o item da propriedade Picture deve ser desenhado pelo controle ActiveX, uma série de adições e modificações devem ser feitas na propriedade antes que ela possa ser totalmente implementada.

Para implementar uma propriedade de imagem personalizada, você deve fazer o seguinte:

- [Adicione código ao seu projeto de controle](#_core_additions_to_your_control_project).

   Um ID de página de propriedade `CPictureHolder`de imagem padrão, um membro de dados do tipo e uma propriedade personalizada do tipo **LPPICTUREDISP** com uma implementação Get/Set devem ser adicionados.

- [Modifique várias funções em sua classe de controle](#_core_modifications_to_your_control_project).

   Essas modificações serão feitas em várias funções que são responsáveis pelo desenho do seu controle ActiveX.

## <a name="additions-to-your-control-project"></a><a name="_core_additions_to_your_control_project"></a>Adições ao seu projeto de controle

Para adicionar o ID da página de propriedade para a página de propriedade imagem padrão, insira a seguinte linha após a BEGIN_PROPPAGEIDS macro no arquivo de implementação de controle (. CPP):

[!code-cpp[NVC_MFC_AxPic#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_1.cpp)]

Você também deve incrementar o parâmetro de contagem de sua BEGIN_PROPPAGEIDS macro por um. A seguinte linha ilustra o seguinte:

[!code-cpp[NVC_MFC_AxPic#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_2.cpp)]

Para adicionar `CPictureHolder` o membro de dados à classe de controle, insira a seguinte linha sob a seção protegida da declaração da classe de controle no arquivo de cabeçalho de controle (. H):

[!code-cpp[NVC_MFC_AxPic#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_3.h)]

Não é necessário nomear seu membro de dados *m_pic;* qualquer nome será suficiente.

Em seguida, adicione uma propriedade personalizada que suporte um tipo de imagem:

#### <a name="to-add-a-custom-picture-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de imagem personalizada usando o Assistente de Adicionar Propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, escolha **Adicionar** e, em seguida, **Adicionar propriedade**.

1. Na caixa Nome da **propriedade,** digite o nome da propriedade. Por exemplo, `ControlPicture` é usado neste procedimento.

1. Na caixa **Tipo de propriedade,** selecione **IPictureDisp** <strong>\*</strong> para o tipo de propriedade.

1. Para **o tipo de implementação,** clique em **Métodos de entrada/conjunto**.

1. Digite nomes exclusivos para suas Funções Get and Set ou aceite os nomes padrão. (Neste exemplo, os `GetControlPicture` nomes `SetControlPicture` padrão e são usados.)

1. Clique em **Concluir**.

O Assistente de adicionar propriedade adiciona o seguinte código entre os comentários do mapa de despacho no cabeçalho de controle (. Arquivo H:

[!code-cpp[NVC_MFC_AxPic#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_4.h)]

Além disso, o seguinte código foi inserido no mapa de despacho da implementação do controle (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxPic#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_5.cpp)]

O Assistente de propriedade de adicionar também adiciona as seguintes duas funções de stub no arquivo de implementação de controle:

[!code-cpp[NVC_MFC_AxPic#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_6.cpp)]

> [!NOTE]
> Seus nomes de classe de controle e função podem diferir do exemplo acima.

### <a name="modifications-to-your-control-project"></a><a name="_core_modifications_to_your_control_project"></a>Modificações no seu projeto de controle

Depois de fazer as adições necessárias ao seu projeto de controle, você precisa modificar várias funções que afetam a renderização do seu controle ActiveX. Essas `OnResetState`funções, `OnDraw`e as funções Get/Set de uma propriedade de Imagem personalizada, estão localizadas no arquivo de implementação de controle. (Observe que neste exemplo a `CSampleCtrl`classe `CPictureHolder` de controle é chamada, o membro `ControlPicture`de dados é chamado de *m_pic*e o nome da propriedade de imagem personalizada é .)

Na função `OnResetState` de controle, adicione a seguinte `COleControl::OnResetState`linha opcional após a chamada para:

[!code-cpp[NVC_MFC_AxPic#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_7.cpp)]

Isso define a imagem do controle para uma imagem em branco.

Para desenhar a imagem corretamente, faça uma chamada para `OnDraw` [CPictureHolder::Render](../mfc/reference/cpictureholder-class.md#render) na função de controle. Modifique sua função para se assemelhar ao seguinte exemplo:

[!code-cpp[NVC_MFC_AxPic#8](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_8.cpp)]

Na função Obter da propriedade de imagem personalizada do controle, adicione a seguinte linha:

[!code-cpp[NVC_MFC_AxPic#9](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_9.cpp)]

Na função Definir da propriedade imagem personalizada do controle, adicione as seguintes linhas:

[!code-cpp[NVC_MFC_AxPic#10](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_10.cpp)]

A propriedade de imagem deve ser persistente para que as informações adicionadas na hora do projeto apareçam no tempo de execução. Adicione a seguinte `COleControl`linha à função `DoPropExchange` da classe derivada:

[!code-cpp[NVC_MFC_AxPic#11](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_11.cpp)]

> [!NOTE]
> Seus nomes de classe e função podem diferir do exemplo acima.

Depois de concluir as modificações, reconstrua seu projeto para incorporar a nova funcionalidade da propriedade Picture personalizada e use O Recipiente de Teste para testar a nova propriedade. Consulte [Propriedades de teste e eventos com o recipiente de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o recipiente de teste.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: usando fontes](../mfc/mfc-activex-controls-using-fonts.md)<br/>
[Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)
