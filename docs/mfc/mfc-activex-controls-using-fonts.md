---
title: 'Controles ActiveX MFC: usando fontes'
ms.date: 11/19/2018
f1_keywords:
- OnFontChanged
- HeadingFont
- InternalFont
helpviewer_keywords:
- notifications [MFC], MFC ActiveX controls fonts
- OnDraw method, MFC ActiveX controls
- InternalFont method [MFC]
- SetFont method [MFC]
- OnFontChanged method [MFC]
- IPropertyNotifySink class [MFC]
- MFC ActiveX controls [MFC], fonts
- Stock Font property [MFC]
- HeadingFont property [MFC]
- GetFont method [MFC]
- SelectStockFont method [MFC]
- fonts [MFC], ActiveX controls
ms.assetid: 7c51d602-3f5a-481d-84d1-a5d8a3a71761
ms.openlocfilehash: c336ec6c29b5478655ca8f19f71378a2b446ac64
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358267"
---
# <a name="mfc-activex-controls-using-fonts"></a>Controles ActiveX MFC: usando fontes

Se o controle ActiveX exibir texto, você poderá permitir que o usuário de controle altere a aparência do texto alterando uma propriedade de fonte. As propriedades da fonte são implementadas como objetos de fonte e podem ser um dos dois tipos: estoque ou personalizado. As propriedades da fonte de estoque são propriedades de fonte pré-implementadas que você pode adicionar usando o Assistente de adicionar propriedade. As propriedades da Fonte Personalizada não são pré-implementadas e o desenvolvedor de controle determina o comportamento e o uso da propriedade.

Este artigo aborda os seguintes tópicos:

- [Usando a propriedade Stock Font](#_core_using_the_stock_font_property)

- [Usando propriedades de fonte personalizadas no seu controle](#_core_implementing_a_custom_font_property)

## <a name="using-the-stock-font-property"></a><a name="_core_using_the_stock_font_property"></a>Usando a propriedade Stock Font

As propriedades da fonte de estoque são pré-implementadas pela classe [COleControl](../mfc/reference/colecontrol-class.md). Além disso, uma página de propriedade font padrão também está disponível, permitindo que o usuário altere vários atributos do objeto da fonte, como seu nome, tamanho e estilo.

Acesse o objeto de fonte através das funções [GetFont,](../mfc/reference/colecontrol-class.md#getfont) [SetFont](../mfc/reference/colecontrol-class.md#setfont)e [InternalGetFont](../mfc/reference/colecontrol-class.md#internalgetfont) de `COleControl`. O usuário de controle acessará `GetFont` `SetFont` o objeto de fonte através da e funciona da mesma forma que qualquer outra propriedade Get/Set. Quando o acesso ao objeto de fonte for `InternalGetFont` necessário dentro de um controle, use a função.

Como discutido nos [controles MFC ActiveX: Propriedades](../mfc/mfc-activex-controls-properties.md), adicionar propriedades de estoque é fácil com o [Assistente de Propriedade adicionar](../ide/names-add-property-wizard.md). Você escolhe a propriedade Font e o Assistente adicionar propriedades insere automaticamente a entrada da fonte de estoque no mapa de despacho do controle.

#### <a name="to-add-the-stock-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade font de estoque usando o Assistente adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o Assistente adicionar propriedade.

1. Na **caixa Nome** da propriedade, clique **em 'Fonte**'

1. Clique em **Concluir**.

O Assistente de Propriedade adicionar a seguir a seguir ao mapa de despacho do controle, localizado no arquivo de implementação da classe de controle:

[!code-cpp[NVC_MFC_AxFont#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_1.cpp)]

Além disso, o Assistente adicionar propriedade adiciona a seguinte linha ao controle . Arquivo IDL:

[!code-cpp[NVC_MFC_AxFont#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_2.idl)]

A propriedade stock Caption é um exemplo de uma propriedade de texto que pode ser sorteada usando as informações da propriedade Font stock. Adicionar a propriedade stock Caption ao controle usa etapas semelhantes às usadas para a propriedade Font stock.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade stock Caption usando o Assistente adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o Assistente adicionar propriedade.

1. Na caixa Nome da **propriedade,** clique **em Legenda**.

1. Clique em **Concluir**.

O Assistente de Propriedade adicionar a seguir a seguir ao mapa de despacho do controle, localizado no arquivo de implementação da classe de controle:

[!code-cpp[NVC_MFC_AxFont#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_3.cpp)]

## <a name="modifying-the-ondraw-function"></a><a name="_core_modifying_the_ondraw_function"></a>Modificando a função OnDraw

A implementação `OnDraw` padrão de usa a fonte do sistema Windows para todos os textos exibidos no controle. Isso significa que você `OnDraw` deve modificar o código selecionando o objeto de fonte no contexto do dispositivo. Para fazer isso, ligue para [COleControl::SelectStockFont](../mfc/reference/colecontrol-class.md#selectstockfont) e passe o contexto do dispositivo do controle, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFC_AxFont#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_4.cpp)]

Depois `OnDraw` que a função for modificada para usar o objeto fonte, qualquer texto dentro do controle é exibido com características da propriedade Font stock do controle.

## <a name="using-custom-font-properties-in-your-control"></a><a name="_core_using_custom_font_properties_in_your_control"></a>Usando propriedades de fonte personalizadas no seu controle

Além da propriedade Font stock, o controle ActiveX pode ter propriedades de Fonte personalizadas. Para adicionar uma propriedade de fonte personalizada, você deve:

- Use o Assistente adicionar propriedade para implementar a propriedade Font personalizada.

- [Processamento de notificações de fonte](#_core_processing_font_notifications).

- [Implementando uma nova interface de notificação de fonte](#_core_implementing_a_new_font_notification_interface).

### <a name="implementing-a-custom-font-property"></a><a name="_core_implementing_a_custom_font_property"></a>Implementando uma propriedade de fonte personalizada

Para implementar uma propriedade font personalizada, você usa o Assistente adicionar propriedade para adicionar a propriedade e, em seguida, fazer algumas modificações no código. As seções a seguir descrevem `HeadingFont` como adicionar a propriedade personalizada ao controle Amostra.

##### <a name="to-add-the-custom-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade font personalizada usando o Assistente de adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o Assistente adicionar propriedade.

1. Na caixa Nome da **propriedade,** digite um nome para a propriedade. Para este exemplo, use **HeadingFont**.

1. Para **o tipo de implementação,** clique em **Métodos de entrada/conjunto**.

1. Na caixa **Tipo de propriedade,** selecione **IDispatch** <strong>\*</strong> para o tipo da propriedade.

1. Clique em **Concluir**.

O Assistente de adicionar propriedade `HeadingFont` cria o `CSampleCtrl` código para adicionar a propriedade personalizada à classe e ao SAMPLE. Arquivo IDL. Como `HeadingFont` é um tipo de propriedade Get/Set, `CSampleCtrl` o Assistente adicionar propriedades modifica o mapa de despacho da classe para incluir uma DISP_PROPERTY_EX_ID[DISP_PROPERTY_EX](../mfc/reference/dispatch-maps.md#disp_property_ex) entrada de macro:

[!code-cpp[NVC_MFC_AxFont#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_5.cpp)]

A DISP_PROPERTY_EX macro `HeadingFont` associa o `CSampleCtrl` nome da propriedade aos `GetHeadingFont` `SetHeadingFont`métodos de get e set correspondentes e . O tipo do valor da propriedade também é especificado; neste caso, VT_FONT.

O Assistente de Adição de Propriedades também adiciona uma declaração no arquivo de cabeçalho de controle (. H) para `GetHeadingFont` `SetHeadingFont` as funções e funções e adiciona seus modelos de função no arquivo de implementação de controle (. CPP):

[!code-cpp[NVC_MFC_AxFont#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_6.cpp)]

Finalmente, o Assistente adicionar propriedade modifica o controle . Arquivo IDL adicionando uma `HeadingFont` entrada para a propriedade:

[!code-cpp[NVC_MFC_AxFont#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_7.idl)]

### <a name="modifications-to-the-control-code"></a>Modificações no Código de Controle

Agora que você `HeadingFont` adicionou a propriedade ao controle, você deve fazer algumas alterações nos arquivos de cabeçalho de controle e implementação para suportar totalmente a nova propriedade.

No arquivo de cabeçalho de controle (. H), adicionar a seguinte declaração de uma variável de membro protegido:

[!code-cpp[NVC_MFC_AxFont#8](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_8.h)]

No arquivo de implementação de controle (. CPP), faça o seguinte:

- Inicializar *m_fontHeading* no construtor de controle.

   [!code-cpp[NVC_MFC_AxFont#9](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_9.cpp)]

- Declare uma estrutura FONTDESC estática contendo atributos padrão da fonte.

   [!code-cpp[NVC_MFC_AxFont#10](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_10.cpp)]

- Na função `DoPropExchange` de membro de controle, adicione uma chamada à `PX_Font` função. Isso fornece inicialização e persistência para sua propriedade Font personalizada.

   [!code-cpp[NVC_MFC_AxFont#11](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_11.cpp)]

- Termine de implementar `GetHeadingFont` a função do membro de controle.

   [!code-cpp[NVC_MFC_AxFont#12](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_12.cpp)]

- Termine de implementar `SetHeadingFont` a função do membro de controle.

   [!code-cpp[NVC_MFC_AxFont#13](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_13.cpp)]

- Modifique `OnDraw` a função do membro de controle para definir uma variável para conter a fonte previamente selecionada.

   [!code-cpp[NVC_MFC_AxFont#14](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_14.cpp)]

- Modifique `OnDraw` a função do membro de controle para selecionar a fonte personalizada no contexto do dispositivo adicionando a seguinte linha onde quer que a fonte seja usada.

   [!code-cpp[NVC_MFC_AxFont#15](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_15.cpp)]

- Modifique `OnDraw` a função do membro de controle para selecionar a fonte anterior de volta ao contexto do dispositivo adicionando a seguinte linha após a fonte ter sido usada.

   [!code-cpp[NVC_MFC_AxFont#16](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_16.cpp)]

Depois que a propriedade Font personalizada for implementada, a página de propriedade Font padrão deve ser implementada, permitindo que os usuários de controle alterem a fonte atual do controle. Para adicionar o ID da página de propriedade da propriedade para a página de propriedade padrão Da Fonte, insira a seguinte linha após a BEGIN_PROPPAGEIDS macro:

[!code-cpp[NVC_MFC_AxFont#17](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_17.cpp)]

Você também deve incrementar o parâmetro de contagem de sua BEGIN_PROPPAGEIDS macro por um. A seguinte linha ilustra o seguinte:

[!code-cpp[NVC_MFC_AxFont#18](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_18.cpp)]

Depois que essas alterações tiverem sido feitas, reconstrua todo o projeto para incorporar a funcionalidade adicional.

### <a name="processing-font-notifications"></a><a name="_core_processing_font_notifications"></a>Processamento de notificações de fontes

Na maioria dos casos, o controle precisa saber quando as características do objeto fonte foram modificadas. Cada objeto de fonte é capaz de fornecer notificações `IFontNotification` quando ele `COleControl`muda chamando uma função membro da interface, implementada por .

Se o controle usar a propriedade Font stock, `OnFontChanged` suas `COleControl`notificações serão tratadas pela função membro de . Quando você adiciona propriedades de fonte personalizadas, você pode fazê-las usar a mesma implementação. No exemplo da seção anterior, isso foi realizado passando &*m_xFontNotification* ao inicializar a variável membro *m_fontHeading.*

![Implementação de várias interfaces de objeto de fonte](../mfc/media/vc373q1.gif "Implementação de várias interfaces de objeto de fonte") <br/>
Implementando várias interfaces de objeto de fonte

As linhas sólidas na figura acima mostram que ambos `IFontNotification`os objetos de fonte estão usando a mesma implementação de . Isso poderia causar problemas se você quisesse distinguir qual fonte mudou.

Uma maneira de distinguir entre as notificações do objeto de `IFontNotification` fonte do controle é criar uma implementação separada da interface para cada objeto de fonte no controle. Esta técnica permite que você otimize seu código de desenho atualizando apenas as strings, ou strings, que usam a fonte recentemente modificada. As seções a seguir demonstram as etapas necessárias para implementar interfaces de notificação separadas para uma segunda propriedade Font. A segunda propriedade de fonte `HeadingFont` é assumida como sendo a propriedade que foi adicionada na seção anterior.

### <a name="implementing-a-new-font-notification-interface"></a><a name="_core_implementing_a_new_font_notification_interface"></a>Implementando uma nova interface de notificação de fonte

Para distinguir entre as notificações de duas ou mais fontes, uma nova interface de notificação deve ser implementada para cada fonte usada no controle. As seções a seguir descrevem como implementar uma nova interface de notificação de fonte modificando o cabeçalho de controle e os arquivos de implementação.

### <a name="additions-to-the-header-file"></a>Adições ao arquivo de cabeçalho

No arquivo de cabeçalho de controle (. H), adicione as seguintes linhas à declaração de classe:

[!code-cpp[NVC_MFC_AxFont#19](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_19.h)]

Isso cria uma `IPropertyNotifySink` implementação `HeadingFontNotify`da interface chamada . Esta nova interface contém `OnChanged`um método chamado .

### <a name="additions-to-the-implementation-file"></a>Adições ao Arquivo de Implementação

No código que inicializa a fonte de título (no construtor de controle), mude &*m_xFontNotification* para &*m_xHeadingFontNotify*. Em seguida, adicione o seguinte código:

[!code-cpp[NVC_MFC_AxFont#20](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_20.cpp)]

Os `AddRef` `Release` métodos na `IPropertyNotifySink` interface acompanham a contagem de referência susceptino do objeto de controle ActiveX. Quando o controle obtém acesso ao `AddRef` ponteiro da interface, o controle chama para incrementar a contagem de referência. Quando o controle é terminado com `Release`o ponteiro, ele `GlobalFree` chama , da mesma forma que pode ser chamado para liberar um bloco de memória global. Quando a contagem de referência para esta interface vai para zero, a implementação da interface pode ser liberada. Neste exemplo, `QueryInterface` a função retorna `IPropertyNotifySink` um ponteiro para uma interface em um determinado objeto. Essa função permite que um controle ActiveX consulte um objeto para determinar quais interfaces ele suporta.

Depois que essas alterações forem feitas no seu projeto, reconstrua o projeto e use o Test Container para testar a interface. Consulte [Propriedades de teste e eventos com o recipiente de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o recipiente de teste.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: usando imagens em um controle ActiveX](../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md)<br/>
[Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)
