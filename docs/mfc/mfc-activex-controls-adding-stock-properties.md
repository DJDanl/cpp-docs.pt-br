---
title: 'Controles ActiveX MFC: adicionando propriedades de estoque'
ms.date: 11/04/2016
helpviewer_keywords:
- BackColor property [MFC]
- properties [MFC], adding stock
- ForeColor property [MFC]
- MFC ActiveX controls [MFC], properties
- foreground colors, ActiveX controls
- foreground colors [MFC]
ms.assetid: 8b98c8c5-5b69-4366-87bf-0e61e6668ecb
ms.openlocfilehash: 27fed55ac8a5fc8b95f81c1bfd2c6edb3da6227d
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91502238"
---
# <a name="mfc-activex-controls-adding-stock-properties"></a>Controles ActiveX MFC: adicionando propriedades de estoque

As propriedades de ações diferem das propriedades personalizadas, pois elas já estão implementadas pela classe `COleControl` . `COleControl` contém funções de membro predefinidas que dão suporte a propriedades comuns para o controle. Algumas propriedades comuns incluem a legenda do controle e as cores de primeiro e segundo plano. Para obter informações sobre outras propriedades de ações, consulte [Propriedades de ações com suporte pelo Assistente para adicionar Propriedade](#_core_stock_properties_supported_by_classwizard) , mais adiante neste artigo. As entradas do mapa de expedição para propriedades de ações são sempre prefixadas por DISP_STOCKPROP.

Este artigo descreve como adicionar uma propriedade Stock (neste caso, Caption) a um controle ActiveX usando o assistente para adicionar propriedade e explica as modificações de código resultantes. Os tópicos incluem:

- [Usando o assistente para adicionar propriedade para adicionar uma propriedade de estoque](#_core_using_classwizard_to_add_a_stock_property)

- [Adicionar alterações do assistente de propriedade para propriedades de ações](#_core_classwizard_changes_for_stock_properties)

- [Propriedades de ações com suporte pelo Assistente para adicionar propriedade](#_core_stock_properties_supported_by_classwizard)

- [Propriedades de ações e notificação](#_core_stock_properties_and_notification)

- [Propriedades de cor](#_core_color_properties)

    > [!NOTE]
    >  Visual Basic controles personalizados normalmente têm propriedades como Top, esquerda, Width, Height, Align, tag, Name, TabIndex, TabStop e Parent. No entanto, os contêineres de controle ActiveX são responsáveis por implementar essas propriedades de controle e, portanto, os controles ActiveX não devem dar suporte a essas propriedades.

## <a name="using-the-add-property-wizard-to-add-a-stock-property"></a><a name="_core_using_classwizard_to_add_a_stock_property"></a> Usando o assistente para adicionar propriedade para adicionar uma propriedade de estoque

A adição de propriedades de ações requer menos código do que adicionar propriedades personalizadas, pois o suporte para a propriedade é manipulado automaticamente pelo `COleControl` . O procedimento a seguir demonstra como adicionar a propriedade de legenda de estoque a uma estrutura de controle ActiveX e também pode ser usada para adicionar outras propriedades de ações. Substitua o nome da propriedade de ações selecionada por legenda.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de legenda de estoque usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o [Assistente para adicionar Propriedade](../ide/adding-a-property-visual-cpp.md#names-add-property-wizard).

1. Na caixa **nome da propriedade** , clique em **legenda**.

1. Clique em **Concluir**.

## <a name="add-property-wizard-changes-for-stock-properties"></a><a name="_core_classwizard_changes_for_stock_properties"></a> Adicionar alterações do assistente de propriedade para propriedades de ações

Como `COleControl` o oferece suporte a propriedades de ações, o assistente para adicionar propriedade não altera a declaração de classe de nenhuma forma; ele adiciona a propriedade ao mapa de expedição. O assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, que está localizado na implementação (. CPP) arquivo:

[!code-cpp[NVC_MFC_AxUI#22](codesnippet/cpp/mfc-activex-controls-adding-stock-properties_1.cpp)]

A linha a seguir é adicionada à descrição da interface do seu controle (. IDL) arquivo:

[!code-cpp[NVC_MFC_AxUI#23](codesnippet/cpp/mfc-activex-controls-adding-stock-properties_2.idl)]

Essa linha atribui a propriedade Caption a uma ID específica. Observe que a propriedade é ligável e solicitará permissão do banco de dados antes de modificar o valor.

Isso torna a propriedade Caption disponível para os usuários do seu controle. Para usar o valor de uma propriedade Stock, acesse uma variável de membro ou uma função membro da `COleControl` classe base. Para obter mais informações sobre essas variáveis de membro e funções de membro, consulte a próxima seção, propriedades de ações com suporte pelo Assistente para adicionar propriedade.

## <a name="stock-properties-supported-by-the-add-property-wizard"></a><a name="_core_stock_properties_supported_by_classwizard"></a> Propriedades de ações com suporte pelo Assistente para adicionar propriedade

A `COleControl` classe fornece nove Propriedades de ações. Você pode adicionar as propriedades desejadas usando o assistente para adicionar propriedade.

|Propriedade|Entrada do mapa de expedição|Como acessar o valor|
|--------------|------------------------|-------------------------|
|`Appearance`|DISP_STOCKPROP_APPEARANCE ()|Valor acessível como `m_sAppearance` .|
|`BackColor`|DISP_STOCKPROP_BACKCOLOR ()|Valor acessível chamando `GetBackColor` .|
|`BorderStyle`|DISP_STOCKPROP_BORDERSTYLE ()|Valor acessível como `m_sBorderStyle` .|
|`Caption`|DISP_STOCKPROP_CAPTION ()|Valor acessível chamando `InternalGetText` .|
|`Enabled`|DISP_STOCKPROP_ENABLED ()|Valor acessível como `m_bEnabled` .|
|`Font`|DISP_STOCKPROP_FONT ()|Consulte o artigo [controles ActiveX do MFC: usando fontes](mfc-activex-controls-using-fonts.md) para uso.|
|`ForeColor`|DISP_STOCKPROP_FORECOLOR ()|Valor acessível chamando `GetForeColor` .|
|`hWnd`|DISP_STOCKPROP_HWND ()|Valor acessível como `m_hWnd` .|
|`Text`|DISP_STOCKPROP_TEXT ()|Valor acessível chamando `InternalGetText` . Essa propriedade é igual a `Caption` , exceto pelo nome da propriedade.|
|`ReadyState`|DISP_STOCKPROP_READYSTATE ()|Valor acessível como `m_lReadyState` ou `GetReadyState`|

## <a name="stock-properties-and-notification"></a><a name="_core_stock_properties_and_notification"></a> Propriedades de ações e notificação

A maioria das propriedades de estoque tem funções de notificação que podem ser substituídas. Por exemplo, sempre que a `BackColor` propriedade for alterada, a `OnBackColorChanged` função (uma função de membro da classe de controle) será chamada. As chamadas de implementação padrão (em `COleControl` ) `InvalidateControl` . Substitua essa função se desejar executar ações adicionais em resposta a essa situação.

## <a name="color-properties"></a><a name="_core_color_properties"></a> Propriedades de cor

Você pode usar as `ForeColor` Propriedades e ações `BackColor` , ou suas próprias propriedades de cor personalizadas, ao pintar o controle. Para usar uma propriedade de cor, chame a função de membro [COleControl:: TranslateColor](reference/colecontrol-class.md#translatecolor) . Os parâmetros dessa função são o valor da Propriedade Color e um identificador de paleta opcional. O valor de retorno é um valor **COLORREF** que pode ser passado para funções GDI, como `SetTextColor` e `CreateSolidBrush` .

Os valores de cor para a ação `ForeColor` e as `BackColor` Propriedades são acessados chamando a `GetForeColor` `GetBackColor` função ou, respectivamente.

O exemplo a seguir demonstra o uso dessas duas propriedades de cor ao pintar um controle. Ele Inicializa uma variável **COLORREF** temporária e um `CBrush` objeto com chamadas para `TranslateColor` : uma usando a `ForeColor` propriedade e a outra usando a `BackColor` propriedade. Um `CBrush` objeto temporário é usado para pintar o retângulo do controle e a cor do texto é definida usando a `ForeColor` propriedade.

[!code-cpp[NVC_MFC_AxUI#24](codesnippet/cpp/mfc-activex-controls-adding-stock-properties_3.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: Propriedades](mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
