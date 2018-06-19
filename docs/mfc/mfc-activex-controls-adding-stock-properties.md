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
ms.openlocfilehash: c51a2efba3c89b4e216fec96459b14c3d0c637d8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33357553"
---
# <a name="mfc-activex-controls-adding-stock-properties"></a>Controles ActiveX MFC: adicionando propriedades de estoque
Propriedades de estoque são diferentes de propriedades personalizadas em que eles já são implementados pela classe `COleControl`. `COleControl` contém funções de membro predefinidas que oferecem suporte a propriedades comuns para o controle. Algumas propriedades comuns incluem a legenda do controle e as cores de primeiro plano e plano de fundo. Para obter informações sobre outras propriedades de estoque, consulte [suporte a propriedades de estoque, o Assistente para adicionar propriedade](#_core_stock_properties_supported_by_classwizard) posteriormente neste artigo. As entradas de mapa de expedição de propriedades de estoque sempre são prefixadas por **DISP_STOCKPROP**.  
  
 Este artigo descreve como adicionar uma propriedade de estoque (nesse caso, legenda) para um controle ActiveX usando o Assistente para adicionar propriedade e explica as modificações de código resultante. Os tópicos incluem:  
  
-   [Usando o Assistente para adicionar propriedade para adicionar uma propriedade de estoque](#_core_using_classwizard_to_add_a_stock_property)  
  
-   [Adicione as alterações do Assistente de propriedade para propriedades de estoque](#_core_classwizard_changes_for_stock_properties)  
  
-   [Propriedades de estoque suportadas pelo Assistente para adicionar propriedade](#_core_stock_properties_supported_by_classwizard)  
  
-   [Notificação e propriedades de estoque](#_core_stock_properties_and_notification)  
  
-   [Propriedades de cor](#_core_color_properties)  
  
    > [!NOTE]
    >  Controles personalizados do Visual Basic normalmente têm propriedades como superior, esquerda, largura, altura, alinhar, marca, nome, TabIndex, parada de tabulação e pai. Contêineres de controle ActiveX, no entanto, serão responsáveis por implementar essas propriedades de controle e, portanto, os controles ActiveX devem não dar suporte a essas propriedades.  
  
##  <a name="_core_using_classwizard_to_add_a_stock_property"></a> Usando o Assistente para adicionar propriedade para adicionar uma propriedade de estoque  
 Adicionando propriedades de estoque requer menos código que Adicionando propriedades personalizadas porque o suporte para a propriedade é tratada automaticamente pelo `COleControl`. O procedimento a seguir demonstra como adicionar o estoque de propriedade de legenda para uma estrutura de controle ActiveX e também pode ser usado para adicionar outras propriedades de estoque. Substitua o nome de propriedade de estoque selecionada para a legenda.  
  
#### <a name="to-add-the-stock-caption-property-using-the-add-property-wizard"></a>Para adicionar a propriedade de legenda ações usando o Assistente para adicionar propriedade  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **adicionar propriedade**.  
  
     Isso abre o [Assistente para adição de propriedade](../ide/names-add-property-wizard.md).  
  
5.  No **nome da propriedade** , clique em **legenda**.  
  
6.  Clique em **Finalizar**.  
  
##  <a name="_core_classwizard_changes_for_stock_properties"></a> Adicionar alterações do Assistente de propriedade para propriedades de estoque  
 Como `COleControl` oferece suporte a propriedades de estoque, o Assistente para adicionar propriedade não altera a declaração de classe de qualquer maneira; ele adiciona a propriedade para o mapa de expedição. O Assistente para adicionar propriedade adiciona a seguinte linha ao mapa de expedição do controle, que está localizado na implementação (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxUI#22](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_1.cpp)]  
  
 A seguinte linha é adicionada à descrição de interface do controle (. Arquivo IDL):  
  
 [!code-cpp[NVC_MFC_AxUI#23](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_2.idl)]  
  
 Essa linha atribui a propriedade de legenda uma ID específica. Observe que a propriedade é vinculável e irá solicitar a permissão do banco de dados antes de modificar o valor.  
  
 Isso torna a propriedade de legenda disponíveis para os usuários do seu controle. Para usar o valor de uma propriedade de estoque, acessar uma variável de membro ou uma função de membro de `COleControl` classe base. Para obter mais informações sobre essas variáveis de membro e funções de membro, consulte a próxima seção, suporte a propriedades de estoque, o Assistente para adicionar propriedade.  
  
##  <a name="_core_stock_properties_supported_by_classwizard"></a> Propriedades com suporte de ações do Assistente para adicionar propriedade  
 O `COleControl` classe fornece nove propriedades de estoque. Você pode adicionar as propriedades desejadas usando o Assistente para adicionar propriedade.  
  
|Propriedade|Entrada de mapa de expedição|Como acessar o valor|  
|--------------|------------------------|-------------------------|  
|**Aparência**|**(DISP_STOCKPROP_APPEARANCE)**|Valor acessível como **m_sAppearance**.|  
|`BackColor`|**(DISP_STOCKPROP_BACKCOLOR)**|Valor acessível chamando `GetBackColor`.|  
|`BorderStyle`|**(DISP_STOCKPROP_BORDERSTYLE)**|Valor acessível como **m_sBorderStyle**.|  
|**Legenda**|**(DISP_STOCKPROP_CAPTION)**|Valor acessível chamando `InternalGetText`.|  
|**Habilitado**|**(DISP_STOCKPROP_ENABLED)**|Valor acessível como **m_bEnabled**.|  
|**Fonte**|**(DISP_STOCKPROP_FONT)**|Consulte o artigo [controles ActiveX MFC: usando fontes](../mfc/mfc-activex-controls-using-fonts.md) para uso.|  
|`ForeColor`|**(DISP_STOCKPROP_FORECOLOR)**|Valor acessível chamando `GetForeColor`.|  
|**hWnd**|**(DISP_STOCKPROP_HWND)**|Valor acessível como `m_hWnd`.|  
|**Texto**|**(DISP_STOCKPROP_TEXT)**|Valor acessível chamando `InternalGetText`. Essa propriedade é o mesmo que **legenda**, exceto o nome da propriedade.|  
|**Estado de prontidão é**|**DISP_STOCKPROP_READYSTATE()**|Valor acessível como m_lReadyState ou `GetReadyState`|  
  
##  <a name="_core_stock_properties_and_notification"></a> Notificação e propriedades de estoque  
 A maioria das propriedades de estoque têm funções de notificação que podem ser substituídas. Por exemplo, sempre que o `BackColor` propriedade for alterada, o `OnBackColorChanged` é chamada de função (uma função de membro da classe de controle). A implementação padrão (em `COleControl`) chamadas `InvalidateControl`. Substitua essa função se você deseja executar ações adicionais em resposta a essa situação.  
  
##  <a name="_core_color_properties"></a> Propriedades de cor  
 Você pode usar o estoque `ForeColor` e `BackColor` propriedades ou suas próprias propriedades de cor personalizada, quando o controle de pintura. Para usar uma propriedade de cor, chame o [COleControl::TranslateColor](../mfc/reference/colecontrol-class.md#translatecolor) função de membro. Os parâmetros desta função são o valor da propriedade de cor e um identificador de paleta opcional. O valor de retorno é um **COLORREF** valor que pode ser passado para GDI funções, como `SetTextColor` e `CreateSolidBrush`.  
  
 Os valores de cor para a ação `ForeColor` e `BackColor` propriedades são acessadas chamando o `GetForeColor` ou `GetBackColor` função, respectivamente.  
  
 O exemplo a seguir demonstra como usar essas propriedades de duas cores quando pintando um controle. Inicializa um temporário **COLORREF** variável e um `CBrush` objeto com chamadas para `TranslateColor`: um usando o `ForeColor` propriedade e outra usando o `BackColor` propriedade. Um temporário `CBrush` objeto é usado para pintar o retângulo de controle e a cor do texto é definida usando o `ForeColor` propriedade.  
  
 [!code-cpp[NVC_MFC_AxUI#24](../mfc/codesnippet/cpp/mfc-activex-controls-adding-stock-properties_3.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe COleControl](../mfc/reference/colecontrol-class.md)
