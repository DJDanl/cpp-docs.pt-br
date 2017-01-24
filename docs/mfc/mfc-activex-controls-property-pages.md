---
title: "Controles ActiveX MFC: p&#225;ginas de propriedade | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CPropertyPageDialog"
  - "Funções DDP_"
  - "Método DoDataExchange"
  - "Controles ActiveX MFC, propriedades"
  - "Controles ActiveX MFC, páginas de propriedade"
  - "OLEIVERB_PROPERTIES"
  - "páginas de propriedade, Controles ActiveX MFC"
ms.assetid: 1506f87a-9fd6-4505-8380-0dbc9636230e
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: p&#225;ginas de propriedade
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As páginas de propriedades permitem que um usuário do controle ActiveX exibir e modificar propriedades do controle ActiveX.  Essas propriedades são acessadas invocando uma caixa de diálogo propriedades de controle, que contém uma ou mais páginas de propriedades personalizada, que fornecem uma interface gráfica para exibir e editar as propriedades do controle.  
  
 As páginas de propriedades do controle ActiveX são exibidas em duas maneiras:  
  
-   Quando o verbo de propriedades de controle \(**OLEIVERB\_PROPERTIES**\) é chamado, o controle abre uma caixa de diálogo modal da propriedade que contém as páginas de propriedades do controle.  
  
-   O contêiner pode exibir a própria caixa de diálogo modeless que mostra as páginas de propriedades do controle selecionado.  
  
 A caixa de diálogo de propriedades \(ilustrada na figura a seguir\) consiste em uma área para exibir a página de propriedades atual, guias para alternar entre páginas de propriedades, e uma coleção dos botões que executam tarefas comuns como fechar a caixa de diálogo da página de propriedades, cancelando todas as alterações feitas, ou aplicando imediatamente qualquer alteração no controle ActiveX.  
  
 ![Caixa de diálogo de propriedades de Circ3](../mfc/media/vc373i1.png "vc373I1")  
Caixa de diálogo propriedades  
  
 Este artigo abrange os tópicos a seguir relacionados ao usar páginas de propriedades em um controle ActiveX.  Eles incluem:  
  
-   [Implementando a página de propriedades padrão para um controle ActiveX](#_core_implementing_the_default_property_page)  
  
-   [Adicionando controles para uma página de propriedades](#_core_adding_controls_to_a_property_page)  
  
-   [Personalizando a função de DoDataExchange](#_core_customizing_the_dodataexchange_function)  
  
 Para obter mais informações sobre como usar páginas de propriedades em um controle ActiveX, consulte os artigos a seguir:  
  
-   [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md)  
  
-   [Controles ActiveX MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
 Para obter informações sobre como usar folhas de propriedades em um aplicativo de MFC diferente de um controle ActiveX, consulte [Folhas de propriedade](../mfc/property-sheets-mfc.md).  
  
##  <a name="_core_implementing_the_default_property_page"></a> Implementando a página de propriedades padrão  
 Se você usar o assistente de controle ActiveX para criar o projeto de controle, o assistente do controle ActiveX fornece uma classe padrão da página de propriedades do controle derivado de [Classe de COlePropertyPage](../mfc/reference/colepropertypage-class.md).  Inicialmente, essa página de propriedades é em branco, mas você pode adicionar qualquer controle da caixa de diálogo ou conjunto de controles.  Como o assistente de controle ActiveX cria apenas uma classe da página de propriedades por padrão, as classes de página adicionais de propriedades \(também derivadas de `COlePropertyPage`\) devem ser criadas usando a exibição da classe.  Para obter mais informações sobre esse procedimento, consulte [Controles ActiveX MFC: adicionando outra página de propriedade personalizada](../mfc/mfc-activex-controls-adding-another-custom-property-page.md).  
  
 Implementar uma página de propriedades \(nesse caso, a opção\) é um processo de três etapas:  
  
#### Para implementar uma página de propriedades  
  
1.  Adicionar `COlePropertyPage`\- classe derivada ao projeto do controle.  Se o projeto foi criado usando o assistente de controle ActiveX \(como nesse caso\), a classe padrão da página de propriedades já existe.  
  
2.  Use o editor da caixa de diálogo para adicionar todos os controles no modelo de página de propriedades.  
  
3.  Personalizar a função de `COlePropertyPage`\- classe derivada de `DoDataExchange` aos valores de troca entre o controle da página de propriedades e o controle ActiveX.  
  
 Por exemplo, propósitos dos seguintes procedimentos usam um controle simples \(denominado “exemplo”\).  O exemplo foi criado usando o assistente de controle ActiveX e só contém a propriedade de estoque da legenda.  
  
##  <a name="_core_adding_controls_to_a_property_page"></a> Adicionando controles para uma página de propriedades  
  
#### Para adicionar controles para uma página de propriedades  
  
1.  Com o projeto de controle, abra a exibição aberta de recursos.  
  
2.  Clique duas vezes no ícone do diretório de **Caixa de Diálogo** .  
  
3.  Abrir a caixa de diálogo de **IDD\_PROPPAGE\_SAMPLE** .  
  
     O assistente de controle ActiveX anexa o nome do projeto ao final da ID da caixa de diálogo, nesse caso, o exemplo.  
  
4.  Arraste e solte o controle selecionado da caixa de ferramentas na área da caixa de diálogo.  
  
5.  Para este exemplo, a legenda de um controle de rótulo do texto “: ” e um controle da caixa de edição com um identificador de **IDC\_CAPTION** é suficiente.  
  
6.  Clique **Salvar** na barra de ferramentas para salvar as alterações.  
  
 Agora que a interface do usuário foi alterada, deverá vincular a caixa de edição com a propriedade de legenda.  Isso é feito na seção a seguir editando a função de `CSamplePropPage::DoDataExchange` .  
  
##  <a name="_core_customizing_the_dodataexchange_function"></a> Personalizando a função de DoDataExchange  
 A função de [CWnd::DoDataExchange](../Topic/CWnd::DoDataExchange.md) da página de propriedades permite vincular valores da página de propriedades com os valores reais das propriedades no controle.  Para estabelecer links, você deve mapear os campos adequados da página de propriedades em suas respectivas propriedades do controle.  
  
 Esses mapeamentos são implementados usando as funções de **DDP\_** da página de propriedades.  As funções de **DDP\_** como funcionam as funções de **DDX\_** usadas em caixas de diálogo padrão de MFC, com uma exceção.  Além da referência a uma variável de membro, as funções de **DDP\_** têm o nome da propriedade do controle.  O seguinte é típica uma entrada na função de `DoDataExchange` para uma página de propriedades.  
  
 [!code-cpp[NVC_MFC_AxUI#31](../mfc/codesnippet/CPP/mfc-activex-controls-property-pages_1.cpp)]  
  
 Essa função associa a variável de membro de `m_caption` da página de propriedades com a legenda, usando a função de `DDP_TEXT` .  
  
 Depois que você tiver o controle da página de propriedades inserido, você precisa estabelecer um vínculo entre o controle da página de propriedades, `IDC_CAPTION`, e a propriedade real de controle, a legenda, usando a função de **DDP\_Text** conforme descrito acima.  
  
 [Páginas de propriedade](../mfc/reference/property-pages-mfc.md) está disponível para outros tipos de controle da caixa de diálogo, como caixas de seleção, botões de opção, as caixas de listagem.  A tabela a seguir lista o conjunto inteiro de funções de **DDP\_** da página de propriedades e suas finalidades:  
  
### Funções da página de propriedades  
  
|Nome da função|Use esta função para vincular|  
|--------------------|-----------------------------------|  
|`DDP_CBIndex`|O índice de cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade do controle.|  
|`DDP_CBString`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade do controle.  A cadeia de caracteres selecionada pode começar com as mesmas letras que o valor da propriedade mas não precisa corresponde completamente.|  
|`DDP_CBStringExact`|A cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade do controle.  A cadeia de caracteres selecionada e o valor da cadeia de caracteres de propriedade devem corresponder exatamente.|  
|`DDP_Check`|Uma caixa de seleção com uma propriedade do controle.|  
|`DDP_LBIndex`|O índice de cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade do controle.|  
|`DDP_LBString`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade do controle.  A cadeia de caracteres selecionada pode começar com as mesmas letras que o valor da propriedade mas não precisa corresponde completamente.|  
|`DDP_LBStringExact`|A cadeia de caracteres selecionada em uma caixa de listagem com uma propriedade do controle.  A cadeia de caracteres selecionada e o valor da cadeia de caracteres de propriedade devem corresponder exatamente.|  
|`DDP_Radio`|Um botão de opção com uma propriedade do controle.|  
|**DDP\_Text**|Texto com uma propriedade do controle.|  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Classe de COlePropertyPage](../mfc/reference/colepropertypage-class.md)