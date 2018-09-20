---
title: 'Controles ActiveX MFC: Adicionando propriedades de estoque | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- BackColor property [MFC]
- properties [MFC], adding stock
- ForeColor property [MFC]
- MFC ActiveX controls [MFC], properties
- foreground colors, ActiveX controls
- foreground colors [MFC]
ms.assetid: 8b98c8c5-5b69-4366-87bf-0e61e6668ecb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4100dc14a25a744e5c28ffd1b16119408d800656
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404508"
---
# <a name="mfc-activex-controls-adding-stock-properties"></a>Controles ActiveX MFC: adicionando propriedades de estoque

Propriedades de estoque diferem das propriedades personalizadas em que eles já são implementados pela classe `COleControl`. `COleControl` contém funções de membro predefinidas que oferecem suporte a propriedades comuns para o controle. Algumas propriedades comuns incluem a legenda do controle e as cores de primeiro plano e plano de fundo. Para obter informações sobre outras propriedades de estoque, consulte [Stock propriedades suportadas pelo Assistente para adicionar propriedade](#_core_stock_properties_supported_by_classwizard) mais adiante neste artigo. As entradas de mapa de expedição para propriedades sempre são prefixadas por DISP_STOCKPROP de estoque.

Este artigo descreve como adicionar uma propriedade de estoque (nesse caso, legenda) para um controle ActiveX usando o Assistente para adicionar propriedade e explica as modificações de código resultante. Os tópicos incluem:

- [Usando o Assistente para adicionar propriedade para adicionar uma propriedade de estoque](#_core_using_classwizard_to_add_a_stock_property)

- [Adicione as alterações do Assistente de propriedade para propriedades de estoque](#_core_classwizard_changes_for_stock_properties)

- [Propriedades de estoque com suporte pelo Assistente para adicionar propriedade](#_core_stock_properties_supported_by_classwizard)

- [Notificação e propriedades de estoque](#_core_stock_properties_and_notification)

- [Propriedades de cor](#_core_color_properties)

    > [!NOTE]
    >  Controles personalizados do Visual Basic normalmente têm as propriedades, como a parte superior, esquerda, largura, altura, alinhar, marca, nome, TabIndex, parada de tabulação e pai. Contêineres de controle ActiveX, no entanto, serão responsáveis por implementar essas propriedades de controle e, portanto, os controles ActiveX devem não dar suporte a essas propriedades.

##  <a name="_core_using_classwizard_to_add_a_stock_property"></a> Usando o Assistente para adicionar propriedade para adicionar uma propriedade de estoque

Adicionando propriedades de estoque exige menos código do que Adicionando propriedades personalizadas, porque o suporte para a propriedade é tratada automaticamente pelo `COleControl`. O procedimento a seguir demonstra como adicionar a propriedade Caption de estoque para a estrutura de controle ActiveX e também pode ser usado para adicionar outras propriedades de estoque. Substitua o nome de propriedade de estoque selecionado para a legenda.

#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade Caption ações usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

     Isso abre o [Assistente para adicionar de propriedade](../ide/names-add-property-wizard.md).

1. No **nome da propriedade** , clique em **legenda**.

1. Clique em **Finalizar**.

##  <a name="_core_classwizard_changes_for_stock_properties"></a> Adicione as alterações do Assistente de propriedade para propriedades de estoque

Porque `COleControl` dá suporte a propriedades de estoque, o Assistente para adicionar propriedade não altera a declaração de classe de qualquer forma, ele adiciona a propriedade para o mapa de expedição. O Assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, que está localizado na implementação (. Arquivo CPP):

[!code-cpp[NVC_MFC_AxUI#22](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_1.cpp)]

A linha a seguir é adicionada à descrição da interface do seu controle (. Arquivo IDL):

[!code-cpp[NVC_MFC_AxUI#23](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_2.idl)]

Essa linha atribui a propriedade Caption de uma ID específica. Observe que a propriedade é associável e solicita permissão do banco de dados antes de modificar o valor.

Isso torna a propriedade Caption disponível para os usuários do seu controle. Para usar o valor de uma propriedade de estoque, acessar uma variável de membro ou uma função de membro do `COleControl` classe base. Para obter mais informações sobre essas funções de membro e variáveis de membro, consulte a próxima seção, estoque propriedades suportadas pelo Assistente de adição de propriedade.

##  <a name="_core_stock_properties_supported_by_classwizard"></a> Estoque de propriedades compatíveis com o Assistente para adicionar propriedade

O `COleControl` classe fornece nove propriedades de estoque. Você pode adicionar as propriedades desejadas usando o Assistente para adicionar propriedade.

|Propriedade|Entrada de mapa de expedição|Como acessar o valor|
|--------------|------------------------|-------------------------|
|`Appearance`|(DISP_STOCKPROP_APPEARANCE)|Valor acessível como `m_sAppearance`.|
|`BackColor`|(DISP_STOCKPROP_BACKCOLOR)|Valor acessível por meio da chamada `GetBackColor`.|
|`BorderStyle`|(DISP_STOCKPROP_BORDERSTYLE)|Valor acessível como `m_sBorderStyle`.|
|`Caption`|(DISP_STOCKPROP_CAPTION)|Valor acessível por meio da chamada `InternalGetText`.|
|`Enabled`|(DISP_STOCKPROP_ENABLED)|Valor acessível como `m_bEnabled`.|
|`Font`|(DISP_STOCKPROP_FONT)|Consulte o artigo [controles ActiveX MFC: usando fontes](../mfc/mfc-activex-controls-using-fonts.md) para uso.|
|`ForeColor`|(DISP_STOCKPROP_FORECOLOR)|Valor acessível por meio da chamada `GetForeColor`.|
|`hWnd`|(DISP_STOCKPROP_HWND)|Valor acessível como `m_hWnd`.|
|`Text`|(DISP_STOCKPROP_TEXT)|Valor acessível por meio da chamada `InternalGetText`. Essa propriedade é o mesmo que `Caption`, exceto para o nome da propriedade.|
|`ReadyState`|DISP_STOCKPROP_READYSTATE()|Valor acessível como `m_lReadyState` ou `GetReadyState`|

##  <a name="_core_stock_properties_and_notification"></a> Notificação e propriedades de estoque

A maioria das propriedades de estoque têm funções de notificação que podem ser substituídas. Por exemplo, sempre que o `BackColor` propriedade for alterada, o `OnBackColorChanged` é chamada de função (uma função de membro de classe de controle). A implementação padrão (no `COleControl`) chama `InvalidateControl`. Substitua essa função se você quiser executar ações adicionais em resposta a essa situação.

##  <a name="_core_color_properties"></a> Propriedades de cor

Você pode usar o estoque `ForeColor` e `BackColor` propriedades ou suas próprias propriedades de cor personalizada, quando o controle de pintura. Para usar uma propriedade de cor, chame o [COleControl::TranslateColor](../mfc/reference/colecontrol-class.md#translatecolor) função de membro. Os parâmetros dessa função são o valor da propriedade de cor e um identificador opcional paleta. O valor retornado é um **COLORREF** funções de valor que pode ser passado para GDI, como `SetTextColor` e `CreateSolidBrush`.

Os valores de cor para a ação `ForeColor` e `BackColor` propriedades são acessadas chamando o `GetForeColor` ou o `GetBackColor` funcionar, respectivamente.

O exemplo a seguir demonstra como usar essas propriedades de duas cores ao pintar um controle. Ele inicializa um temporário **COLORREF** variável e uma `CBrush` objeto com chamadas para `TranslateColor`: usando o `ForeColor` propriedade e outra usando o `BackColor` propriedade. Um temporário `CBrush` objeto é usado para pintar o retângulo de controle e a cor do texto é definida usando o `ForeColor` propriedade.

[!code-cpp[NVC_MFC_AxUI#24](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_3.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
