---
title: 'Controles ActiveX MFC: Páginas de propriedade | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DDP_ functions [MFC]
- MFC ActiveX controls [MFC], properties
- property pages [MFC], MFC ActiveX controls
- DoDataExchange method [MFC]
- OLEIVERB_PROPERTIES
- CPropertyPageDialog class [MFC]
- MFC ActiveX controls [MFC], property pages
ms.assetid: 1506f87a-9fd6-4505-8380-0dbc9636230e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 23f8aaf1e485d7ba38a561639f81b36d494a98f2
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36930427"
---
# <a name="mfc-activex-controls-property-pages"></a>Controles ActiveX MFC: páginas de propriedade
Páginas de propriedades permitem que um usuário de controle ActiveX exibir e alterar as propriedades do controle ActiveX. Essas propriedades são acessadas por meio de invocação de uma caixa de diálogo de propriedades de controle, que contém uma ou mais páginas de propriedade que fornecem uma interface gráfica personalizada para exibir e editar as propriedades do controle.  
  
 Páginas de propriedades do controle ActiveX são exibidas de duas maneiras:  
  
-   Quando verbo de propriedades do controle (**OLEIVERB_PROPERTIES**) é chamado, o controle abre uma caixa de diálogo de propriedades restrita que contém as páginas de propriedades do controle.  
  
-   O contêiner pode exibir sua própria caixa de diálogo sem janela restrita que mostra as páginas de propriedade do controle selecionado.  
  
 A caixa de diálogo de propriedades (ilustrada na figura a seguir) consiste em uma área para exibir a página de propriedades atual, as guias para alternar entre páginas de propriedade e uma coleção de botões que realizar tarefas comuns, como fechar a caixa de diálogo de página de propriedade Cancelar todas as alterações feitas ou aplicar imediatamente as alterações para o controle ActiveX.  
  
 ![Caixa de diálogo de propriedades para Circ3](../mfc/media/vc373i1.gif "vc373i1")  
Caixa de diálogo de propriedades  
  
 Este artigo aborda os tópicos relacionados ao uso de páginas de propriedades em um controle ActiveX. Elas incluem:  
  
-   [Implementando a página de propriedade padrão para um controle ActiveX](#_core_implementing_the_default_property_page)  
  
-   [Adicionando controles a uma página de propriedades](#_core_adding_controls_to_a_property_page)  
  
-   [Personalizando a função DoDataExchange](#_core_customizing_the_dodataexchange_function)  
  
 Para obter mais informações sobre como usar páginas de propriedade em um controle ActiveX, consulte os seguintes artigos:  
  
-   [Controles ActiveX do MFC: adicionando outra página de propriedades personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)  
  
-   [Controles ActiveX do MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
 Para obter informações sobre o uso de folhas de propriedades em um aplicativo MFC que não seja um controle ActiveX, consulte [folhas de propriedade](../mfc/property-sheets-mfc.md).  
  
##  <a name="_core_implementing_the_default_property_page"></a> Implementando a página de propriedade padrão  
 Se você usar o Assistente de controle ActiveX para criar seu projeto de controle, o Assistente de controle ActiveX fornece uma classe de página de propriedade padrão para o controle é derivado de [COlePropertyPage classe](../mfc/reference/colepropertypage-class.md). Inicialmente, essa página de propriedade estiver em branco, mas você pode adicionar qualquer controle de caixa de diálogo ou o conjunto de controles a ele. Como o Assistente de controle ActiveX cria a classe de página apenas uma propriedade por padrão, as classes de página de propriedades adicionais (derivado também `COlePropertyPage`) deve ser criada usando o modo de exibição de classe. Para obter mais informações sobre esse procedimento, consulte [controles ActiveX MFC: adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md).  
  
 Implementando uma propriedade de página (nesse caso, o padrão) é um processo de três etapas:  
  
#### <a name="to-implement-a-property-page"></a>Para implementar uma página de propriedades  
  
1.  Adicionar um `COlePropertyPage`-classe derivada para o projeto de controle. Se o projeto foi criado usando o Assistente de controle ActiveX (como neste caso), a classe de página de propriedade padrão já existe.  
  
2.  Use o editor de caixa de diálogo para adicionar os controles para o modelo de página de propriedade.  
  
3.  Personalizar o `DoDataExchange` função do `COlePropertyPage`-derivado da classe para trocar valores entre o controle de página de propriedade e o controle ActiveX.  
  
 Por exemplo finalidades, os procedimentos a seguir usam um controle simples (chamado "Exemplo"). Exemplo foi criado usando o Assistente de controle ActiveX e contém apenas a propriedade de legenda estoque.  
  
##  <a name="_core_adding_controls_to_a_property_page"></a> Adicionando controles a uma página de propriedades  
  
#### <a name="to-add-controls-to-a-property-page"></a>Para adicionar controles a uma página de propriedades  
  
1.  Com o projeto de controle é aberto, abra a exibição de recursos.  
  
2.  Clique duas vezes o **diálogo** ícone directory.  
  
3.  Abra a caixa de diálogo IDD_PROPPAGE_SAMPLE.  
  
     O Assistente de controle ActiveX anexa o nome do projeto para o final da caixa de diálogo ID, nesse caso, exemplo.  
  
4.  Arraste e solte o controle selecionado da caixa de ferramentas para a área de caixa de diálogo.  
  
5.  Neste exemplo, um texto de rótulo de controle "legenda:" e um controle de caixa de edição com um identificador IDC_CAPTION são suficientes.  
  
6.  Clique em **salvar** na barra de ferramentas para salvar suas alterações.  
  
 Agora que a interface do usuário tiver sido modificada, você precisa vincular a caixa de edição com a propriedade de legenda. Isso é feito na seção a seguir, editando o `CSamplePropPage::DoDataExchange` função.  
  
##  <a name="_core_customizing_the_dodataexchange_function"></a> Personalizando a função DoDataExchange  
 A página de propriedades [CWnd::DoDataExchange](../mfc/reference/cwnd-class.md#dodataexchange) função permite vincular valores de propriedade de página com os valores reais das propriedades no controle. Para estabelecer links, você deve mapear os campos de página de propriedade apropriado para suas propriedades de controle do respectivos.  
  
 Esses mapeamentos são implementados usando a página de propriedade **DDP _** funções. O **DDP _** funções funcionam como o **DDX_** funções usadas em MFC caixas de diálogo padrão, com uma exceção. A referência a uma variável de membro, além de **DDP _** funções usam o nome da propriedade de controle. Esta é uma entrada típica no `DoDataExchange` função para uma página de propriedades.  
  
 [!code-cpp[NVC_MFC_AxUI#31](../mfc/codesnippet/cpp/mfc-activex-controls-property-pages_1.cpp)]  
  
 Essa função associa a página de propriedades *m_caption* variável de membro com a legenda, usando o `DDP_TEXT` função.  
  
 Depois de ter o controle de página de propriedade inserido, você precisa estabelecer um vínculo entre o controle de página de propriedade, IDC_CAPTION e a propriedade de controle, legenda, usando o `DDP_Text` funcionar conforme descrito acima.  
  
 [Páginas de propriedade](../mfc/reference/property-pages-mfc.md) estão disponíveis para outros tipos de controle de caixa de diálogo, como caixas de seleção, botões de opção e caixas de listagem. A tabela a seguir lista o conjunto inteiro de página de propriedades **DDP _** funções e seus objetivos:  
  
### <a name="property-page-functions"></a>Página de propriedades de funções  
  
|Nome da função|Use esta função para vincular|  
|-------------------|-------------------------------|  
|`DDP_CBIndex`|Índice da cadeia de caracteres selecionado em uma caixa de combinação com uma propriedade de controle.|  
|`DDP_CBString`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade de controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa coincidi-la completamente.|  
|`DDP_CBStringExact`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade de controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|  
|`DDP_Check`|Uma caixa de seleção com uma propriedade de controle.|  
|`DDP_LBIndex`|Índice da cadeia de caracteres selecionado em uma caixa de listagem com uma propriedade de controle.|  
|`DDP_LBString`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade de controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa coincidi-la completamente.|  
|`DDP_LBStringExact`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade de controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|  
|`DDP_Radio`|Um botão de opção com uma propriedade de controle.|  
|`DDP_Text`|Texto com uma propriedade de controle.|  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)   
 [Classe COlePropertyPage](../mfc/reference/colepropertypage-class.md)
