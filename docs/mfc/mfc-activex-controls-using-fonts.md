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
ms.openlocfilehash: 02c52d2544afdc9d13fc3ec67ad9eed757a3f277
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499698"
---
# <a name="mfc-activex-controls-using-fonts"></a>Controles ActiveX MFC: usando fontes

Se o controle ActiveX exibir texto, você poderá permitir que o usuário do controle altere a aparência do texto alterando uma propriedade de fonte. As propriedades de fonte são implementadas como objetos Font e podem ser de dois tipos: Stock ou Custom. As propriedades de fonte de estoque são propriedades de fonte preimplementadas que você pode adicionar usando o assistente para adicionar propriedade. As propriedades de fonte personalizadas não são preimplementadas e o desenvolvedor de controle determina o comportamento e o uso da propriedade.

Este artigo aborda os seguintes tópicos:

- [Usando a propriedade Font de ações](#_core_using_the_stock_font_property)

- [Usando propriedades de fonte personalizadas em seu controle](#_core_implementing_a_custom_font_property)

## <a name="using-the-stock-font-property"></a><a name="_core_using_the_stock_font_property"></a> Usando a propriedade Font de ações

As propriedades da fonte de ações são preimplementadas pela classe [COleControl](reference/colecontrol-class.md). Além disso, uma página de propriedades de fonte padrão também está disponível, permitindo que o usuário altere vários atributos do objeto Font, como seu nome, tamanho e estilo.

Acesse o objeto Font por meio das funções [GetFont](reference/colecontrol-class.md#getfont), [SetFont](reference/colecontrol-class.md#setfont)e [InternalGetFont](reference/colecontrol-class.md#internalgetfont) do `COleControl` . O usuário de controle acessará o objeto Font por meio das `GetFont` funções e da `SetFont` mesma maneira que qualquer outra propriedade get/set. Quando o acesso ao objeto de fonte é necessário em um controle, use a `InternalGetFont` função.

Conforme discutido em [controles ActiveX do MFC: Propriedades](mfc-activex-controls-properties.md), a adição de propriedades de ações é fácil com o [Assistente para adicionar Propriedade](../ide/adding-a-property-visual-cpp.md#names-add-property-wizard). Você escolhe a propriedade Font e o assistente para adicionar propriedade insere automaticamente a entrada de fonte Stock no mapa de expedição do controle.

#### <a name="to-add-the-stock-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade Font de ações usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o assistente para adicionar propriedade.

1. Na caixa **nome da propriedade** , clique em **fonte**.

1. Clique em **Concluir**.

O assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, localizado no arquivo de implementação da classe de controle:

[!code-cpp[NVC_MFC_AxFont#1](codesnippet/cpp/mfc-activex-controls-using-fonts_1.cpp)]

Além disso, o assistente para adicionar propriedade adiciona a linha a seguir ao controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxFont#2](codesnippet/cpp/mfc-activex-controls-using-fonts_2.idl)]

A propriedade de legenda de estoque é um exemplo de uma propriedade de texto que pode ser desenhada usando as informações de propriedade da fonte de estoque. A adição da propriedade Caption de stock ao controle usa etapas semelhantes àquelas usadas para a propriedade Font de stock.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de legenda de estoque usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o assistente para adicionar propriedade.

1. Na caixa **nome da propriedade** , clique em **legenda**.

1. Clique em **Concluir**.

O assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, localizado no arquivo de implementação da classe de controle:

[!code-cpp[NVC_MFC_AxFont#3](codesnippet/cpp/mfc-activex-controls-using-fonts_3.cpp)]

## <a name="modifying-the-ondraw-function"></a><a name="_core_modifying_the_ondraw_function"></a> Modificando a função OnDraw

A implementação padrão do `OnDraw` usa a fonte do sistema Windows para todo o texto exibido no controle. Isso significa que você deve modificar o `OnDraw` código selecionando o objeto de fonte no contexto do dispositivo. Para fazer isso, chame [COleControl:: SelectStockFont](reference/colecontrol-class.md#selectstockfont) e passe o contexto do dispositivo do controle, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFC_AxFont#4](codesnippet/cpp/mfc-activex-controls-using-fonts_4.cpp)]

Depois que a `OnDraw` função tiver sido modificada para usar o objeto Font, qualquer texto dentro do controle será exibido com características da propriedade Font de Stock do controle.

## <a name="using-custom-font-properties-in-your-control"></a><a name="_core_using_custom_font_properties_in_your_control"></a> Usando propriedades de fonte personalizadas em seu controle

Além da propriedade fonte de estoque, o controle ActiveX pode ter propriedades de fonte personalizadas. Para adicionar uma propriedade de fonte personalizada, você deve:

- Use o assistente para adicionar propriedade para implementar a propriedade de fonte personalizada.

- [Processando notificações de fonte](#_core_processing_font_notifications).

- [Implementando uma nova interface de notificação de fonte](#_core_implementing_a_new_font_notification_interface).

### <a name="implementing-a-custom-font-property"></a><a name="_core_implementing_a_custom_font_property"></a> Implementando uma propriedade de fonte personalizada

Para implementar uma propriedade de fonte personalizada, use o assistente para adicionar propriedade para adicionar a propriedade e, em seguida, fazer algumas modificações no código. As seções a seguir descrevem como adicionar a `HeadingFont` propriedade personalizada ao controle de exemplo.

##### <a name="to-add-the-custom-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de fonte personalizada usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o assistente para adicionar propriedade.

1. Na caixa **nome da propriedade** , digite um nome para a propriedade. Para este exemplo, use **HeadingFont**.

1. Para **tipo de implementação**, clique em **obter/definir métodos**.

1. Na caixa **tipo de propriedade** , selecione **IDispatch** <strong>\*</strong> para o tipo da propriedade.

1. Clique em **Concluir**.

O assistente para adicionar propriedade cria o código para adicionar a `HeadingFont` propriedade personalizada à `CSampleCtrl` classe e ao exemplo. Arquivo IDL. Como `HeadingFont` é um tipo de propriedade get/set, o assistente para adicionar propriedade modifica o `CSampleCtrl` mapa de expedição da classe para incluir uma entrada de macro DISP_PROPERTY_EX_ID[DISP_PROPERTY_EX](reference/dispatch-maps.md#disp_property_ex) :

[!code-cpp[NVC_MFC_AxFont#5](codesnippet/cpp/mfc-activex-controls-using-fonts_5.cpp)]

A macro DISP_PROPERTY_EX associa o `HeadingFont` nome da propriedade com seus `CSampleCtrl` métodos get e set de classe correspondente `GetHeadingFont` e `SetHeadingFont` . O tipo do valor da propriedade também é especificado; Nesse caso, VT_FONT.

O assistente para adicionar propriedade também adiciona uma declaração no arquivo de cabeçalho de controle (. H) para as `GetHeadingFont` `SetHeadingFont` funções e e adiciona seus modelos de função no arquivo de implementação de controle (. CPP):

[!code-cpp[NVC_MFC_AxFont#6](codesnippet/cpp/mfc-activex-controls-using-fonts_6.cpp)]

Por fim, o assistente para adicionar propriedade modifica o controle. Arquivo IDL adicionando uma entrada para a `HeadingFont` Propriedade:

[!code-cpp[NVC_MFC_AxFont#7](codesnippet/cpp/mfc-activex-controls-using-fonts_7.idl)]

### <a name="modifications-to-the-control-code"></a>Modificações no código de controle

Agora que você adicionou a `HeadingFont` propriedade ao controle, deve fazer algumas alterações no cabeçalho de controle e nos arquivos de implementação para oferecer suporte total à nova propriedade.

No arquivo de cabeçalho de controle (. H), adicione a seguinte declaração de uma variável de membro protegida:

[!code-cpp[NVC_MFC_AxFont#8](codesnippet/cpp/mfc-activex-controls-using-fonts_8.h)]

No arquivo de implementação de controle (. CPP), faça o seguinte:

- Inicializar *m_fontHeading* no construtor de controle.

   [!code-cpp[NVC_MFC_AxFont#9](codesnippet/cpp/mfc-activex-controls-using-fonts_9.cpp)]

- Declare uma estrutura FONTDESC estática que contém os atributos padrão da fonte.

   [!code-cpp[NVC_MFC_AxFont#10](codesnippet/cpp/mfc-activex-controls-using-fonts_10.cpp)]

- Na função de `DoPropExchange` membro Control, adicione uma chamada para a `PX_Font` função. Isso fornece a inicialização e a persistência para sua propriedade de fonte personalizada.

   [!code-cpp[NVC_MFC_AxFont#11](codesnippet/cpp/mfc-activex-controls-using-fonts_11.cpp)]

- Conclua a implementação da função de membro de controle `GetHeadingFont` .

   [!code-cpp[NVC_MFC_AxFont#12](codesnippet/cpp/mfc-activex-controls-using-fonts_12.cpp)]

- Conclua a implementação da função de membro de controle `SetHeadingFont` .

   [!code-cpp[NVC_MFC_AxFont#13](codesnippet/cpp/mfc-activex-controls-using-fonts_13.cpp)]

- Modifique a função de membro de controle `OnDraw` para definir uma variável para manter a fonte selecionada anteriormente.

   [!code-cpp[NVC_MFC_AxFont#14](codesnippet/cpp/mfc-activex-controls-using-fonts_14.cpp)]

- Modifique a função de membro de controle `OnDraw` para selecionar a fonte personalizada no contexto do dispositivo adicionando a linha a seguir sempre que a fonte for usada.

   [!code-cpp[NVC_MFC_AxFont#15](codesnippet/cpp/mfc-activex-controls-using-fonts_15.cpp)]

- Modifique a função de membro de controle `OnDraw` para selecionar a fonte anterior novamente no contexto do dispositivo adicionando a linha a seguir depois que a fonte tiver sido usada.

   [!code-cpp[NVC_MFC_AxFont#16](codesnippet/cpp/mfc-activex-controls-using-fonts_16.cpp)]

Depois que a propriedade de fonte personalizada tiver sido implementada, a página de propriedades de fonte padrão deverá ser implementada, permitindo que os usuários de controle alterem a fonte atual do controle. Para adicionar a ID da página de propriedades à página de propriedades de fonte padrão, insira a seguinte linha após a macro BEGIN_PROPPAGEIDS:

[!code-cpp[NVC_MFC_AxFont#17](codesnippet/cpp/mfc-activex-controls-using-fonts_17.cpp)]

Você também deve incrementar o parâmetro Count de sua BEGIN_PROPPAGEIDS macro por um. A linha a seguir ilustra isso:

[!code-cpp[NVC_MFC_AxFont#18](codesnippet/cpp/mfc-activex-controls-using-fonts_18.cpp)]

Depois que essas alterações tiverem sido feitas, recompile o projeto inteiro para incorporar a funcionalidade adicional.

### <a name="processing-font-notifications"></a><a name="_core_processing_font_notifications"></a> Processando notificações de fonte

Na maioria dos casos, o controle precisa saber quando as características do objeto de fonte foram modificadas. Cada objeto Font é capaz de fornecer notificações quando ele é alterado chamando uma função membro da `IFontNotification` interface implementada pelo `COleControl` .

Se o controle usar a propriedade Font de stock, suas notificações serão tratadas pela `OnFontChanged` função membro do `COleControl` . Ao adicionar propriedades de fonte personalizadas, você pode fazer com que elas usem a mesma implementação. No exemplo na seção anterior, isso foi feito passando &*m_xFontNotification* ao inicializar a variável de membro *m_fontHeading* .

![Implementando várias interfaces de objeto de fonte](../mfc/media/vc373q1.gif "Implementando várias interfaces de objeto de fonte") <br/>
Implementando várias interfaces de objeto de fonte

As linhas sólidas na figura acima mostram que ambos os objetos Font estão usando a mesma implementação de `IFontNotification` . Isso pode causar problemas se você quisesse distinguir qual fonte mudou.

Uma maneira de distinguir entre as notificações de objeto de fonte do controle é criar uma implementação separada da `IFontNotification` interface para cada objeto de fonte no controle. Essa técnica permite que você Otimize seu código de desenho atualizando apenas a cadeia de caracteres, ou cadeias, que usam a fonte modificada recentemente. As seções a seguir demonstram as etapas necessárias para implementar interfaces de notificação separadas para uma segunda propriedade de fonte. A segunda Propriedade Font é considerada a `HeadingFont` propriedade que foi adicionada na seção anterior.

### <a name="implementing-a-new-font-notification-interface"></a><a name="_core_implementing_a_new_font_notification_interface"></a> Implementando uma nova interface de notificação de fonte

Para distinguir entre as notificações de duas ou mais fontes, uma nova interface de notificação deve ser implementada para cada fonte usada no controle. As seções a seguir descrevem como implementar uma nova interface de notificação de fonte modificando o cabeçalho de controle e os arquivos de implementação.

### <a name="additions-to-the-header-file"></a>Adições ao arquivo de cabeçalho

No arquivo de cabeçalho de controle (. H), adicione as seguintes linhas à declaração de classe:

[!code-cpp[NVC_MFC_AxFont#19](codesnippet/cpp/mfc-activex-controls-using-fonts_19.h)]

Isso cria uma implementação da `IPropertyNotifySink` interface chamada `HeadingFontNotify` . Essa nova interface contém um método chamado `OnChanged` .

### <a name="additions-to-the-implementation-file"></a>Adições ao arquivo de implementação

No código que inicializa a fonte do cabeçalho (no construtor de controle), altere &*m_xFontNotification* para &*m_xHeadingFontNotify*. Em seguida, adicione o seguinte código:

[!code-cpp[NVC_MFC_AxFont#20](codesnippet/cpp/mfc-activex-controls-using-fonts_20.cpp)]

Os `AddRef` `Release` métodos e na `IPropertyNotifySink` interface controlam a contagem de referência para o objeto de controle ActiveX. Quando o controle obtém acesso ao ponteiro de interface, o controle chama `AddRef` para incrementar a contagem de referência. Quando o controle é concluído com o ponteiro, ele chama `Release` , praticamente da mesma forma que `GlobalFree` pode ser chamado para liberar um bloco de memória global. Quando a contagem de referência para essa interface chega a zero, a implementação da interface pode ser liberada. Neste exemplo, a `QueryInterface` função retorna um ponteiro para uma `IPropertyNotifySink` interface em um objeto específico. Essa função permite que um controle ActiveX consulte um objeto para determinar a quais interfaces ele dá suporte.

Depois que essas alterações tiverem sido feitas em seu projeto, recompile o projeto e use o contêiner de teste para testar a interface. Consulte [testando Propriedades e eventos com o contêiner de teste](testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: usando imagens em um controle ActiveX](mfc-activex-controls-using-pictures-in-an-activex-control.md)<br/>
[Controles ActiveX do MFC: usando páginas de propriedades de estoque](mfc-activex-controls-using-stock-property-pages.md)
