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
ms.openlocfilehash: 9eb204dd240ae17421a20b7cddeff56c9a22c19b
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618074"
---
# <a name="mfc-activex-controls-using-pictures-in-an-activex-control"></a>Controles ActiveX MFC: usando imagens em um controle ActiveX

Este artigo descreve o tipo de imagem comum e como implementá-lo em seu controle ActiveX. Os tópicos incluem:

- [Visão geral das propriedades personalizadas da imagem](#_core_overview_of_custom_picture_properties)

- [Implementando uma propriedade de imagem personalizada no controle ActiveX](#_core_implementing_a_custom_picture_property_in_your_activex_control)

- [Adições ao seu projeto de controle](#_core_additions_to_your_control_project)

## <a name="overview-of-custom-picture-properties"></a><a name="_core_overview_of_custom_picture_properties"></a>Visão geral das propriedades personalizadas da imagem

Um tipo de imagem é um de um grupo de tipos comuns a alguns controles ActiveX. O tipo de imagem manipula os metaarquivos, os bitmaps ou os ícones e permite que o usuário especifique uma imagem a ser exibida em um controle ActiveX. As propriedades de imagem personalizadas são implementadas usando um objeto de imagem e funções get/set que permitem ao usuário de controle acessar a propriedade Picture. Controlar usuários acessam a propriedade de imagem personalizada usando a página de propriedades de imagem de estoque.

Além do tipo de imagem padrão, os tipos de fonte e cor também estão disponíveis. Para obter mais informações sobre como usar o tipo de fonte padrão em seu controle ActiveX, consulte o artigo [controles ActiveX do MFC: usando fontes](mfc-activex-controls-using-fonts.md).

As classes de controle ActiveX fornecem vários componentes que você pode usar para implementar a propriedade de imagem dentro do controle. Esses componentes incluem:

- A classe [CPictureHolder](reference/cpictureholder-class.md) .

   Essa classe fornece acesso fácil ao objeto de imagem e à funcionalidade do item exibido pela propriedade de imagem personalizada.

- Suporte para propriedades do tipo **LPPICTUREDISP**, implementado com funções get/set.

   Usando Modo de Exibição de Classe você pode adicionar rapidamente uma propriedade personalizada, ou propriedades, que ofereça suporte ao tipo de imagem. Para obter mais informações sobre como adicionar propriedades de controle ActiveX com Modo de Exibição de Classe, consulte o artigo [controles ActiveX do MFC: Propriedades](mfc-activex-controls-properties.md).

- Uma página de propriedades que manipula a propriedade ou as propriedades da imagem de um controle.

   Essa página de propriedades faz parte de um grupo de páginas de propriedades de estoque disponíveis para controles ActiveX. Para obter mais informações sobre páginas de propriedades de controle ActiveX, consulte o artigo [controles ActiveX do MFC: usando páginas de propriedades de estoque](mfc-activex-controls-using-stock-property-pages.md)

## <a name="implementing-a-custom-picture-property-in-your-activex-control"></a><a name="_core_implementing_a_custom_picture_property_in_your_activex_control"></a>Implementando uma propriedade de imagem personalizada no controle ActiveX

Quando você tiver concluído as etapas descritas nesta seção, o controle poderá exibir imagens escolhidas por seu usuário. O usuário pode alterar a imagem exibida usando uma página de propriedades que mostra a imagem atual e tem um botão procurar que permite ao usuário selecionar imagens diferentes.

Uma propriedade de imagem personalizada é implementada usando um processo semelhante ao usado para implementar outras propriedades, a principal diferença é que a propriedade personalizada deve oferecer suporte a um tipo de imagem. Como o item da propriedade Picture deve ser desenhado pelo controle ActiveX, várias adições e modificações devem ser feitas na propriedade antes que possam ser totalmente implementadas.

Para implementar uma propriedade de imagem personalizada, você deve fazer o seguinte:

- [Adicione código ao seu projeto de controle](#_core_additions_to_your_control_project).

   Uma ID de página de propriedade de imagem padrão, um membro de dados do tipo `CPictureHolder` e uma propriedade personalizada do tipo **LPPICTUREDISP** com uma implementação de Get/Set deve ser adicionada.

- [Modifique várias funções em sua classe de controle](#_core_modifications_to_your_control_project).

   Essas modificações serão feitas em várias funções que são responsáveis pelo desenho do seu controle ActiveX.

## <a name="additions-to-your-control-project"></a><a name="_core_additions_to_your_control_project"></a>Adições ao seu projeto de controle

Para adicionar a ID da página de propriedades à página de propriedades da imagem padrão, insira a linha a seguir após a BEGIN_PROPPAGEIDS macro no arquivo de implementação de controle (. CPP):

[!code-cpp[NVC_MFC_AxPic#1](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_1.cpp)]

Você também deve incrementar o parâmetro Count de sua BEGIN_PROPPAGEIDS macro por um. A linha a seguir ilustra isso:

[!code-cpp[NVC_MFC_AxPic#2](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_2.cpp)]

Para adicionar o `CPictureHolder` membro de dados à classe de controle, insira a linha a seguir na seção protegida da declaração de classe de controle no arquivo de cabeçalho de controle (. H):

[!code-cpp[NVC_MFC_AxPic#3](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_3.h)]

Não é necessário nomear o membro de dados *m_pic*; qualquer nome será suficiente.

Em seguida, adicione uma propriedade personalizada que ofereça suporte a um tipo de imagem:

#### <a name="to-add-a-custom-picture-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de imagem personalizada usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, escolha **Adicionar** e **Adicionar Propriedade**.

1. Na caixa **nome da propriedade** , digite o nome da propriedade. Para fins de exemplo, `ControlPicture` é usado neste procedimento.

1. Na caixa **tipo de propriedade** , selecione **IPictureDisp** <strong>\*</strong> para o tipo de propriedade.

1. Para **tipo de implementação**, clique em **obter/definir métodos**.

1. Digite nomes exclusivos para suas funções Get e Set ou aceite os nomes padrão. (Neste exemplo, os nomes padrão `GetControlPicture` e `SetControlPicture` são usados.)

1. Clique em **Concluir**.

O assistente para adicionar propriedade adiciona o código a seguir entre os comentários do mapa de expedição no cabeçalho de controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxPic#4](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_4.h)]

Além disso, o código a seguir foi inserido no mapa de expedição da implementação do controle (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxPic#5](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_5.cpp)]

O assistente para adicionar propriedade também adiciona as duas funções de stub a seguir no arquivo de implementação de controle:

[!code-cpp[NVC_MFC_AxPic#6](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_6.cpp)]

> [!NOTE]
> Seus nomes de classe e função de controle podem ser diferentes do exemplo acima.

### <a name="modifications-to-your-control-project"></a><a name="_core_modifications_to_your_control_project"></a>Modificações no seu projeto de controle

Depois de ter feito as adições necessárias ao seu projeto de controle, você precisa modificar várias funções que afetam a renderização do controle ActiveX. Essas funções, `OnResetState` , `OnDraw` , e as funções get/set de uma propriedade de imagem personalizada, estão localizadas no arquivo de implementação de controle. (Observe que, neste exemplo, a classe de controle é chamada `CSampleCtrl` , o `CPictureHolder` membro de dados é chamado *m_pic*e o nome da propriedade de imagem personalizada é `ControlPicture` .)

Na função de controle `OnResetState` , adicione a seguinte linha opcional após a chamada para `COleControl::OnResetState` :

[!code-cpp[NVC_MFC_AxPic#7](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_7.cpp)]

Isso define a imagem do controle como uma imagem em branco.

Para desenhar a imagem corretamente, faça uma chamada para [CPictureHolder:: render](reference/cpictureholder-class.md#render) na função de controle `OnDraw` . Modifique sua função para se parecer com o exemplo a seguir:

[!code-cpp[NVC_MFC_AxPic#8](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_8.cpp)]

Na função obter da propriedade de imagem personalizada do controle, adicione a seguinte linha:

[!code-cpp[NVC_MFC_AxPic#9](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_9.cpp)]

Na função definir da propriedade de imagem personalizada do controle, adicione as seguintes linhas:

[!code-cpp[NVC_MFC_AxPic#10](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_10.cpp)]

A propriedade Picture deve se tornar persistente para que as informações adicionadas em tempo de design sejam exibidas em tempo de execução. Adicione a seguinte linha à `COleControl` função da classe derivada `DoPropExchange` :

[!code-cpp[NVC_MFC_AxPic#11](codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_11.cpp)]

> [!NOTE]
> Os nomes de classe e função podem ser diferentes do exemplo acima.

Depois de concluir as modificações, recompile o projeto para incorporar a nova funcionalidade da propriedade de imagem personalizada e use o contêiner de teste para testar a nova propriedade. Consulte [testando Propriedades e eventos com o contêiner de teste](testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: usando fontes](mfc-activex-controls-using-fonts.md)<br/>
[Controles ActiveX do MFC: páginas de propriedade](mfc-activex-controls-property-pages.md)
