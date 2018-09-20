---
title: 'Controles ActiveX MFC: Usando fontes | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- OnFontChanged
- HeadingFont
- InternalFont
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b14adec8d601778e255ae7e4242fc552fc820e64
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46396695"
---
# <a name="mfc-activex-controls-using-fonts"></a>Controles ActiveX MFC: usando fontes

Se o seu controle ActiveX exibe o texto, você pode permitir que o usuário do controle alterar a aparência do texto, alterando uma propriedade de fonte. Propriedades de fonte são implementadas como objetos de fonte e pode ser um dos dois tipos: personalizado ou padrão. Propriedades de fonte de estoque são propriedades de fonte preimplemented que você pode adicionar usando o Assistente para adicionar propriedade. Propriedades personalizadas da fonte não são preimplemented e o desenvolvedor do controle determina o comportamento e o uso da propriedade.

Este artigo aborda os seguintes tópicos:

- [Usando a propriedade de fonte de estoque](#_core_using_the_stock_font_property)

- [Usando propriedades de fonte personalizada em seu controle](#_core_implementing_a_custom_font_property)

##  <a name="_core_using_the_stock_font_property"></a> Usando a propriedade de fonte de estoque

Propriedades de fonte de estoque são preimplemented pela classe [COleControl](../mfc/reference/colecontrol-class.md). Além disso, uma página de propriedades de fonte padrão também está disponível, permitindo que o usuário alterar diversos atributos do objeto da fonte, como seu nome, tamanho e estilo.

Acessar o objeto de fonte por meio de [GetFont](../mfc/reference/colecontrol-class.md#getfont), [SetFont](../mfc/reference/colecontrol-class.md#setfont), e [InternalGetFont](../mfc/reference/colecontrol-class.md#internalgetfont) funções de `COleControl`. O usuário do controle irá acessar o objeto de fonte por meio de `GetFont` e `SetFont` funções da mesma maneira como qualquer outra propriedade Get/Set. Quando for necessário de dentro de um controle o acesso ao objeto de fonte, use o `InternalGetFont` função.

Conforme discutido em [controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md), adicionando propriedades de estoque é fácil com o [Adicionar Assistente de propriedade](../ide/names-add-property-wizard.md). Escolha a propriedade de fonte e o Assistente para adicionar propriedade automaticamente insere a entrada de fonte de estoque no mapa de expedição do controle.

#### <a name="to-add-the-stock-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de fonte de estoque usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

     Isso abre o Assistente para adicionar propriedade.

1. No **nome da propriedade** , clique em **fonte**.

1. Clique em **Finalizar**.

O Assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, localizado no arquivo de implementação de classe de controle:

[!code-cpp[NVC_MFC_AxFont#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_1.cpp)]

Além disso, o Assistente para adicionar propriedade adiciona a seguinte linha ao controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxFont#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_2.idl)]

A propriedade Caption estoque é um exemplo de uma propriedade de texto que pode ser desenhado usando as informações de propriedade da fonte das ações. Adicionando a propriedade Caption de estoque para o controle usa etapas semelhantes àquelas usadas para a propriedade de fonte de estoque.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade Caption ações usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

     Isso abre o Assistente para adicionar propriedade.

1. No **nome da propriedade** , clique em **legenda**.

1. Clique em **Finalizar**.

O Assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, localizado no arquivo de implementação de classe de controle:

[!code-cpp[NVC_MFC_AxFont#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_3.cpp)]

##  <a name="_core_modifying_the_ondraw_function"></a> Modificando a função OnDraw

A implementação padrão de `OnDraw` usa a fonte de sistema do Windows para todo o texto exibido no controle. Isso significa que você deve modificar o `OnDraw` código selecionando o objeto de fonte no contexto de dispositivo. Para fazer isso, chame [COleControl::SelectStockFont](../mfc/reference/colecontrol-class.md#selectstockfont) e passar o contexto de dispositivo do controle, conforme mostrado no exemplo a seguir:

[!code-cpp[NVC_MFC_AxFont#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_4.cpp)]

Após o `OnDraw` função foi modificada para usar o objeto de fonte, qualquer texto dentro do controle é exibido com as características da propriedade da fonte de estoque do controle.

##  <a name="_core_using_custom_font_properties_in_your_control"></a> Usando propriedades de fonte personalizada em seu controle

Além da propriedade de fonte de estoque, o controle ActiveX pode ter propriedades personalizadas da fonte. Para adicionar uma propriedade de fonte personalizado, você deve:

- Use o Assistente para adicionar propriedade para implementar a propriedade de fonte personalizada.

- [Processando notificações de fonte](#_core_processing_font_notifications).

- [Implementando uma nova interface de notificação de fonte](#_core_implementing_a_new_font_notification_interface).

###  <a name="_core_implementing_a_custom_font_property"></a> Implementando uma propriedade de fonte personalizada

Para implementar uma propriedade de fonte personalizada, você pode usar o Assistente para adicionar propriedade para adicionar a propriedade e, em seguida, fazer algumas modificações no código. As seções a seguir descrevem como adicionar personalizado `HeadingFont` propriedade ao controle de exemplo.

##### <a name="to-add-the-custom-font-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de fonte personalizada usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

     Isso abre o Assistente para adicionar propriedade.

1. No **nome da propriedade** , digite um nome para a propriedade. Para este exemplo, use **HeadingFont**.

1. Para **tipo de implementação**, clique em **métodos Get/Set**.

1. No **tipo de propriedade** caixa, selecione **IDispatch** <strong>\*</strong> para o tipo da propriedade.

1. Clique em **Finalizar**.

O Assistente para adicionar propriedade cria o código para adicionar o `HeadingFont` propriedade personalizada para o `CSampleCtrl` classe e o exemplo. Arquivo IDL. Porque `HeadingFont` é um tipo de propriedade Get/Set, o Assistente para adicionar propriedade modifica o `CSampleCtrl` mapa de expedição da classe para incluir um DISP_PROPERTY_EX_ID[DISP_PROPERTY_EX](../mfc/reference/dispatch-maps.md#disp_property_ex) entrada de macro:

[!code-cpp[NVC_MFC_AxFont#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_5.cpp)]

A macro DISP_PROPERTY_EX associa a `HeadingFont` nome da propriedade correspondente `CSampleCtrl` classe métodos Get e Set, `GetHeadingFont` e `SetHeadingFont`. O tipo do valor da propriedade também é especificado; Nesse caso, VT_FONT.

O Assistente para adicionar propriedade também adiciona uma declaração no arquivo de controle de cabeçalho (. H) para o `GetHeadingFont` e `SetHeadingFont` funções e adiciona seus modelos de função no arquivo de implementação de controle (. CPP):

[!code-cpp[NVC_MFC_AxFont#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_6.cpp)]

Por fim, o Assistente para adicionar propriedade modifica o controle. Arquivo IDL, adicionando uma entrada para o `HeadingFont` propriedade:

[!code-cpp[NVC_MFC_AxFont#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_7.idl)]

### <a name="modifications-to-the-control-code"></a>Modificações no código de controle

Agora que você adicionou o `HeadingFont` propriedade ao controle, você deve fazer algumas alterações para os arquivos de cabeçalho e de implementação de controle para dar suporte total a nova propriedade.

No arquivo de controle de cabeçalho (. H), adicione a seguinte declaração de uma variável de membro protegida:

[!code-cpp[NVC_MFC_AxFont#8](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_8.h)]

No arquivo de implementação de controle (. CPP), faça o seguinte:

- Inicializar *m_fontHeading* no construtor de controle.

     [!code-cpp[NVC_MFC_AxFont#9](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_9.cpp)]

- Declare uma estrutura FONTDESC estática que contém os atributos padrão da fonte.

     [!code-cpp[NVC_MFC_AxFont#10](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_10.cpp)]

- No controle `DoPropExchange` membro de função, adicione uma chamada para o `PX_Font` função. Isso fornece a inicialização e a persistência para a propriedade de fonte personalizada.

     [!code-cpp[NVC_MFC_AxFont#11](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_11.cpp)]

- Concluir a implementação do controle `GetHeadingFont` função de membro.

     [!code-cpp[NVC_MFC_AxFont#12](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_12.cpp)]

- Concluir a implementação do controle `SetHeadingFont` função de membro.

     [!code-cpp[NVC_MFC_AxFont#13](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_13.cpp)]

- Modificar o controle `OnDraw` a função de membro para definir uma variável para manter a fonte selecionada anteriormente.

     [!code-cpp[NVC_MFC_AxFont#14](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_14.cpp)]

- Modificar o controle `OnDraw` a função de membro para selecionar a fonte personalizada no contexto de dispositivo, adicionando a seguinte linha sempre que a fonte deve ser usada.

     [!code-cpp[NVC_MFC_AxFont#15](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_15.cpp)]

- Modificar o controle `OnDraw` a função de membro para selecionar a fonte anterior volta para o contexto de dispositivo, adicionando a seguinte linha depois que a fonte foi usada.

     [!code-cpp[NVC_MFC_AxFont#16](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_16.cpp)]

Depois que a propriedade de fonte personalizada tiver sido implementada, a página de propriedades de fonte padrão deve ser implementada, permitindo que os usuários de controle alterar a fonte do atual do controle. Para adicionar a ID de página de propriedade para a página de propriedades de fonte padrão, insira a seguinte linha após a macro BEGIN_PROPPAGEIDS:

[!code-cpp[NVC_MFC_AxFont#17](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_17.cpp)]

Você também deve incrementar o parâmetro de contagem de sua macro BEGIN_PROPPAGEIDS por um. A linha a seguir ilustra isso:

[!code-cpp[NVC_MFC_AxFont#18](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_18.cpp)]

Depois que essas alterações foram feitas, recompile todo o projeto para incorporar a funcionalidade adicional.

###  <a name="_core_processing_font_notifications"></a> Processando notificações de fonte

Na maioria dos casos o controle precisa saber quando as características do objeto font foram modificadas. Cada objeto de fonte é capaz de fornecer notificações quando ele é alterado ao chamar uma função de membro do `IFontNotification` interface, implementada pelo `COleControl`.

Se o controle usa a propriedade de fonte de estoque, suas notificações são manipuladas pelo `OnFontChanged` função de membro de `COleControl`. Quando você adiciona as propriedades de fonte personalizado, é necessário que eles usam a mesma implementação. No exemplo na seção anterior, isso foi feito ao passar &*m_xFontNotification* ao inicializar o *m_fontHeading* variável de membro.

![Implementando várias interfaces de objeto de fonte](../mfc/media/vc373q1.gif "vc373q1") implementar várias Interfaces de objeto de fonte

As linhas sólidas na figura acima mostram que os dois objetos de fonte estão usando a mesma implementação de `IFontNotification`. Isso pode causar problemas se você quiser distinguir qual fonte é alterada.

Uma maneira de distinguir entre as notificações de objeto de fonte do controle é criar uma implementação separada do `IFontNotification` interface para cada objeto de fonte no controle. Essa técnica permite otimizar o código de desenho, atualizando apenas a cadeia de caracteres ou cadeias de caracteres, que usam a fonte modificada recentemente. As seções a seguir demonstram as etapas necessárias para implementar as interfaces de notificação separada para uma segunda propriedade Font. A segunda propriedade font é considerada o `HeadingFont` propriedade que foi adicionada na seção anterior.

###  <a name="_core_implementing_a_new_font_notification_interface"></a> Implementando uma nova Interface de notificação de fonte

Para distinguir entre as notificações de duas ou mais fontes, uma nova interface de notificação deve ser implementada para cada fonte usada no controle. As seções a seguir descrevem como implementar uma nova interface de notificação de fonte, modificando os arquivos de cabeçalho e de implementação de controle.

### <a name="additions-to-the-header-file"></a>Adições para o arquivo de cabeçalho

No arquivo de controle de cabeçalho (. H), adicione as seguintes linhas à declaração de classe:

[!code-cpp[NVC_MFC_AxFont#19](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_19.h)]

Isso cria uma implementação de `IPropertyNotifySink` interface chamada `HeadingFontNotify`. Essa nova interface contém um método chamado `OnChanged`.

### <a name="additions-to-the-implementation-file"></a>Adições ao arquivo de implementação

O código que inicializa a fonte do cabeçalho (no construtor de controle), altere &*m_xFontNotification* para &*m_xHeadingFontNotify*. Em seguida, adicione o seguinte código:

[!code-cpp[NVC_MFC_AxFont#20](../mfc/codesnippet/cpp/mfc-activex-controls-using-fonts_20.cpp)]

O `AddRef` e `Release` métodos no `IPropertyNotifySink` interface manter o controle da contagem de referência para o objeto de controle ActiveX. Quando o controle obtém acesso ao ponteiro de interface, o controle chama `AddRef` para incrementar a contagem de referência. Quando o controle é concluído com o ponteiro, ele chama `Release`, da mesma forma que `GlobalFree` pode ser chamado para liberar um bloco de memória global. Quando a contagem de referência para essa interface chega a zero, a implementação da interface pode ser liberada. Neste exemplo, o `QueryInterface` função retorna um ponteiro para um `IPropertyNotifySink` interface em um determinado objeto. Essa função permite que um controle ActiveX para consultar um objeto para determinar quais interfaces ele suporta.

Depois que essas alterações foram feitas ao seu projeto, recompile o projeto e use o contêiner de teste para testar a interface. Ver [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: usando imagens em um controle ActiveX](../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md)<br/>
[Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)

