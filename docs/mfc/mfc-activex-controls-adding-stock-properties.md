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
ms.openlocfilehash: 16bdfddf0c028bc6a312767844b38c58c942d56e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364660"
---
# <a name="mfc-activex-controls-adding-stock-properties"></a>Controles ActiveX MFC: adicionando propriedades de estoque

As propriedades de estoque diferem das propriedades personalizadas, pois já são implementadas pela classe. `COleControl` `COleControl`contém funções de membro predefinidas que suportam propriedades comuns para o controle. Algumas propriedades comuns incluem a legenda do controle e as cores de primeiro plano e de fundo. Para obter informações sobre outras propriedades de estoque, consulte [Propriedades de estoque suportadas pelo Assistente adicionar propriedades](#_core_stock_properties_supported_by_classwizard) mais tarde neste artigo. As entradas do mapa de despacho para propriedades de estoque são sempre prefixadas por DISP_STOCKPROP.

Este artigo descreve como adicionar uma propriedade de estoque (neste caso, Caption) a um controle ActiveX usando o Add Property Wizard e explica as modificações de código resultantes. Os tópicos incluem:

- [Usando o Assistente adicionar propriedade para adicionar uma propriedade de estoque](#_core_using_classwizard_to_add_a_stock_property)

- [Adicionar alterações do Assistente de Propriedade para propriedades de estoque](#_core_classwizard_changes_for_stock_properties)

- [Propriedades de estoque suportadas pelo Assistente de Adicionar Propriedades](#_core_stock_properties_supported_by_classwizard)

- [Propriedades de estoque e notificação](#_core_stock_properties_and_notification)

- [Propriedades de cores](#_core_color_properties)

    > [!NOTE]
    >  Os controles personalizados do Visual Basic normalmente têm propriedades como Top, Left, Width, Height, Align, Tag, Name, TabIndex, TabStop e Parent. Os contêineres de controle ActiveX, no entanto, são responsáveis pela implementação dessas propriedades de controle e, portanto, os controles ActiveX não devem suportar essas propriedades.

## <a name="using-the-add-property-wizard-to-add-a-stock-property"></a><a name="_core_using_classwizard_to_add_a_stock_property"></a>Usando o assistente de adicionar propriedade para adicionar uma propriedade de estoque

Adicionar propriedades de estoque requer menos código do que adicionar propriedades `COleControl`personalizadas porque o suporte para a propriedade é manipulado automaticamente por . O procedimento a seguir demonstra a adição da propriedade stock Caption a uma estrutura de controle ActiveX e também pode ser usado para adicionar outras propriedades de estoque. Substitua o nome da propriedade de estoque selecionado por Legenda.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade stock Caption usando o Assistente adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o [Assistente adicionar propriedade](../ide/names-add-property-wizard.md).

1. Na caixa Nome da **propriedade,** clique **em Legenda**.

1. Clique em **Concluir**.

## <a name="add-property-wizard-changes-for-stock-properties"></a><a name="_core_classwizard_changes_for_stock_properties"></a>Adicionar alterações do assistente de propriedade para propriedades de estoque

Como `COleControl` suporta propriedades de estoque, o Assistente adicionar propriedades não altera a declaração de classe de forma alguma; ele adiciona a propriedade ao mapa de despacho. O Assistente de Propriedade adicionar adiciona a seguinte linha ao mapa de despacho do controle, que está localizado na implementação (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#22](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_1.cpp)]

A linha a seguir é adicionada à descrição da interface do seu controle (. Arquivo IDL):

[!code-cpp[NVC_MFC_AxUI#23](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_2.idl)]

Esta linha atribui à propriedade Caption um ID específico. Observe que a propriedade é vinculável e solicitará permissão do banco de dados antes de modificar o valor.

Isso torna a propriedade Caption disponível para os usuários do seu controle. Para usar o valor de uma propriedade de estoque, `COleControl` acesse uma variável membro ou função membro da classe base. Para obter mais informações sobre essas variáveis de membro e funções de membro, consulte a próxima seção, Propriedades de estoque suportadas pelo Assistente de adicionar propriedade.

## <a name="stock-properties-supported-by-the-add-property-wizard"></a><a name="_core_stock_properties_supported_by_classwizard"></a>Propriedades de estoque suportadas pelo Assistente de Adicionar Propriedades

A `COleControl` classe fornece nove propriedades de estoque. Você pode adicionar as propriedades desejadas usando o Assistente adicionar propriedade.

|Propriedade|Entrada do mapa de despacho|Como acessar o valor|
|--------------|------------------------|-------------------------|
|`Appearance`|DISP_STOCKPROP_APPEARANCE.|Valor acessível como `m_sAppearance`.|
|`BackColor`|DISP_STOCKPROP_BACKCOLOR.|Valor acessível `GetBackColor`por chamada .|
|`BorderStyle`|DISP_STOCKPROP_BORDERSTYLE.|Valor acessível como `m_sBorderStyle`.|
|`Caption`|DISP_STOCKPROP_CAPTION.|Valor acessível `InternalGetText`por chamada .|
|`Enabled`|DISP_STOCKPROP_ENABLED.|Valor acessível como `m_bEnabled`.|
|`Font`|DISP_STOCKPROP_FONT.|Veja o artigo [Controles MFC ActiveX: Usando fontes](../mfc/mfc-activex-controls-using-fonts.md) para uso.|
|`ForeColor`|DISP_STOCKPROP_FORECOLOR.|Valor acessível `GetForeColor`por chamada .|
|`hWnd`|DISP_STOCKPROP_HWND|Valor acessível como `m_hWnd`.|
|`Text`|DISP_STOCKPROP_TEXT.|Valor acessível `InternalGetText`por chamada . Esta propriedade é `Caption`a mesma que, exceto pelo nome da propriedade.|
|`ReadyState`|DISP_STOCKPROP_READYSTATE|Valor acessível como `m_lReadyState` ou`GetReadyState`|

## <a name="stock-properties-and-notification"></a><a name="_core_stock_properties_and_notification"></a>Propriedades e Notificação de Estoques

A maioria das propriedades de estoque tem funções de notificação que podem ser substituídas. Por exemplo, `BackColor` sempre que a `OnBackColorChanged` propriedade é alterada, a função (uma função membro da classe de controle) é chamada. A implementação `COleControl`padrão `InvalidateControl`(in) chamadas . Anular essa função se você quiser tomar ações adicionais em resposta a esta situação.

## <a name="color-properties"></a><a name="_core_color_properties"></a>Propriedades de cores

Você pode usar `ForeColor` `BackColor` o estoque e propriedades, ou suas próprias propriedades de cor personalizadas, ao pintar o controle. Para usar uma propriedade de cores, ligue para a função [COleControl::TranslateColor](../mfc/reference/colecontrol-class.md#translatecolor) member. Os parâmetros desta função são o valor da propriedade de cores e uma alça de paleta opcional. O valor de retorno é um valor **COLORREF** que pode `SetTextColor` `CreateSolidBrush`ser passado para funções GDI, como e .

Os valores de `ForeColor` `BackColor` cor para o estoque `GetForeColor` e `GetBackColor` propriedades são acessados ligando para a função ou para a função, respectivamente.

O exemplo a seguir demonstra o uso dessas duas propriedades de cor ao pintar um controle. Ele inicializa uma variável **COLORREF** temporária `CBrush` e `TranslateColor`um objeto `ForeColor` com chamadas para: um usando a propriedade e outro usando a `BackColor` propriedade. Um `CBrush` objeto temporário é então usado para pintar o retângulo do `ForeColor` controle, e a cor do texto é definida usando a propriedade.

[!code-cpp[NVC_MFC_AxUI#24](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_3.cpp)]

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
