---
title: "Controles ActiveX MFC: usando imagens em um controle ActiveX | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "LPPICTUREDISP"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "CLSID_CPicturePropPage"
  - "Controles ActiveX MFC, figuras"
  - "Método OnDraw"
  - "Método OnDraw, Controles ActiveX MFC"
  - "Método OnResetState"
ms.assetid: 2e49735c-21b9-4442-bb3d-c82ef258eec9
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: usando imagens em um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve o tipo mais comum de imagem e como implementá\-la no controle ActiveX.  Os tópicos incluem:  
  
-   [Visão geral de propriedades personalizadas da imagem](#_core_overview_of_custom_picture_properties)  
  
-   [Implementando uma propriedade personalizada da imagem no controle ActiveX](#_core_implementing_a_custom_picture_property_in_your_activex_control)  
  
-   [Adições ao projeto de controle](#_core_additions_to_your_control_project)  
  
##  <a name="_core_overview_of_custom_picture_properties"></a> Visão geral de propriedades personalizadas da imagem  
 Um tipo de imagem é um de um grupo de tipos comuns a alguns controles ActiveX.  O tipo da imagem trata metarquivos, bitmaps, ou ícones e permite que o usuário especifica uma imagem a ser exibida em um controle ActiveX.  As propriedades personalizadas da imagem são implementadas usando um objeto de imagem e obtenção\/definem as funções que permitem o acesso de usuário à propriedade do controle da imagem.  Os usuários do controle acessam a propriedade personalizada de imagem usando a página de propriedades de estoque da imagem.  
  
 Além do tipo imagem padrão, os tipos de fonte e cor também estão disponíveis.  Para obter mais informações sobre como usar a fonte padrão digite no controle ActiveX, consulte o artigo [Controles ActiveX MFC: Usando fontes](../mfc/mfc-activex-controls-using-fonts.md).  
  
 As classes do controle ActiveX fornecem vários componentes que você pode usar para implementar a propriedade da imagem no controle.  Esses componentes incluem:  
  
-   A classe de [CPictureHolder](../mfc/reference/cpictureholder-class.md) .  
  
     Esta classe fornece acesso fácil ao objeto de imagem e a funcionalidade do item exibido pela propriedade personalizada da imagem.  
  
-   O suporte para as propriedades de tipo **LPPICTUREDISP**, implementadas com obtém ou define funções.  
  
     Usando a exibição da classe você pode adicionar rapidamente uma propriedade personalizada, ou propriedades, que da suporte ao tipo da imagem.  Para obter mais informações sobre como adicionar propriedades do controle ActiveX exibição com a classe, consulte o artigo [Controles ActiveX MFC: Propriedades](../mfc/mfc-activex-controls-properties.md).  
  
-   Uma página de propriedades que manipula a propriedade ou as propriedades da imagem de um controle.  
  
     Esta página de propriedades é parte de um grupo de páginas de propriedades de estoque disponível para os controles ActiveX.  Para obter mais informações sobre as páginas de propriedades do controle ActiveX, consulte o artigo [Controles ActiveX MFC: Usando as páginas de propriedades de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
##  <a name="_core_implementing_a_custom_picture_property_in_your_activex_control"></a> Implementando uma propriedade personalizada da imagem no controle ActiveX  
 Quando concluir as etapas descritas nesta seção, o controle pode exibir as imagens escolhidas pelo usuário.  O usuário pode alterar a imagem exibida usando uma página de propriedades que mostra a imagem atual e tem um botão de procura que permite ao usuário diferentes imagens selecione.  
  
 Uma propriedade personalizada da imagem é implementada usando um processo semelhante ao do usado implementando outras propriedades, a principal diferença é que a propriedade personalizada deve dar suporte a um tipo de imagem.  Como o item da propriedade da imagem deve ser desenhado pelo controle ActiveX, um número de adições e alterações devem ser feitas à propriedade antes que possa ser totalmente implementada.  
  
 Para implementar uma propriedade personalizada da imagem, você deve fazer o seguinte:  
  
-   [Adicionar código ao projeto de controle](#_core_additions_to_your_control_project).  
  
     Uma ID padrão da página de propriedades da imagem, um membro de dados do tipo `CPictureHolder`, e uma propriedade personalizada do tipo **LPPICTUREDISP** com uma implementação obter\/cluster devem ser adicionados.  
  
-   [Modificar várias funções em sua classe de controle](#_core_modifications_to_your_control_project).  
  
     Essas alterações serão feitas para várias funções que são responsáveis pelo desenho do controle ActiveX.  
  
##  <a name="_core_additions_to_your_control_project"></a> Adições ao projeto de controle  
 Para adicionar a ID da página de propriedades da página de propriedades padrão da imagem, insira a seguinte linha depois que a macro de `BEGIN_PROPPAGEIDS` no arquivo de implementação de controle \(.CPP\):  
  
 [!code-cpp[NVC_MFC_AxPic#1](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_1.cpp)]  
  
 Você deve também incrementar o parâmetro de contagem de seu macro de `BEGIN_PROPPAGEIDS` por um.  A linha a seguir ilustra esta:  
  
 [!code-cpp[NVC_MFC_AxPic#2](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_2.cpp)]  
  
 Para adicionar o membro de dados de `CPictureHolder` a classe de controle, insira a seguinte linha na seção protegida de declaração da classe de controle no arquivo de cabeçalho de controle \(. H\):  
  
 [!code-cpp[NVC_MFC_AxPic#3](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_3.h)]  
  
 Não é necessário nomear o membro de dados `m_pic`; qualquer nome será suficiente.  
  
 Em seguida, adicione uma propriedade personalizada que da suporte a um tipo de imagem:  
  
#### Para adicionar uma propriedade personalizada de imagem usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, escolha **Adicionar** e depois **Adicionar Propriedade**.  
  
5.  Na caixa de **Nome da propriedade** , digite o nome da propriedade.  Por exemplo, propósitos de `ControlPicture` são usadas neste procedimento.  
  
6.  Na caixa de **Tipo de propriedade** , **IPictureDisp\*** selecione para o tipo de propriedade.  
  
7.  Para **Tipo de Implementação**, clique **Get\/Set Methods**.  
  
8.  Os nomes exclusivos do seu e definem ou obtêm funções aceitam nomes padrão. \(Neste exemplo, os nomes padrão `GetControlPicture` e em `SetControlPicture` é usado.\)  
  
9. Clique em **Concluir**.  
  
 O assistente da propriedade adicionar adiciona o código a seguir entre os comentários do mapa de distribuição no cabeçalho de controle \(. H\) arquivo:  
  
 [!code-cpp[NVC_MFC_AxPic#4](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_4.h)]  
  
 Além disso, o seguinte código foi inserido no mapa de expedição do arquivo de implementação de controle \(.CPP\):  
  
 [!code-cpp[NVC_MFC_AxPic#5](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_5.cpp)]  
  
 O assistente para adicionar propriedade também adiciona as duas funções de stub no arquivo de implementação de controle:  
  
 [!code-cpp[NVC_MFC_AxPic#6](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_6.cpp)]  
  
> [!NOTE]
>  Os nomes da classe e de função de controle pode ser diferente do exemplo anterior.  
  
###  <a name="_core_modifications_to_your_control_project"></a> Alterações no projeto de controle  
 Depois que você executou as adições necessárias ao controle do, você precisa modificar várias funções que afetam a renderização do controle ActiveX.  Essas funções, `OnResetState`, `OnDraw`as funções, e obter\/conjunto de uma propriedade personalizada da imagem, ficam localizadas no arquivo de implementação do controle. \(Observe que neste exemplo a classe do controle é chamada `CSampleCtrl`, o membro de dados de `CPictureHolder` é chamada `m_pic`, e o nome da propriedade personalizada da imagem é `ControlPicture`.\)  
  
 Na função de `OnResetState` de controle, adicione a seguinte linha opcional depois da chamada a `COleControl::OnResetState`:  
  
 [!code-cpp[NVC_MFC_AxPic#7](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_7.cpp)]  
  
 Isso define a imagem do controle para uma imagem em branco.  
  
 Para desenhar a imagem corretamente, faça uma chamada a [CPictureHolder::Render](../Topic/CPictureHolder::Render.md) na função de `OnDraw` do controle.  Modifique a função para ser semelhante ao seguinte exemplo:  
  
 [!code-cpp[NVC_MFC_AxPic#8](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_8.cpp)]  
  
 A função obter da propriedade personalizada da imagem de controle, adicione a seguinte linha:  
  
 [!code-cpp[NVC_MFC_AxPic#9](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_9.cpp)]  
  
 Na função de conjunto da propriedade personalizada da imagem de controle, adicione as seguintes linhas:  
  
 [!code-cpp[NVC_MFC_AxPic#10](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_10.cpp)]  
  
 A propriedade da imagem deve ser feita persistente de forma que as informações adicionada em tempo de design aparece em tempo de execução.  Adicione a seguinte linha a `COleControl`\- função derivado de `DoPropExchange` da classe:  
  
 [!code-cpp[NVC_MFC_AxPic#11](../mfc/codesnippet/CPP/mfc-activex-controls-using-pictures-in-an-activex-control_11.cpp)]  
  
> [!NOTE]
>  Os nomes da classe e de função pode ser diferente do exemplo anterior.  
  
 Depois de concluir as alterações, recriar seu projeto inserir a nova funcionalidade da propriedade personalizada de imagem e usar o contêiner de teste para testar a nova propriedade.  Consulte [Propriedades e eventos de teste com contêineres de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter mais informações sobre como acessar o contêiner de teste.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: usando fontes](../mfc/mfc-activex-controls-using-fonts.md)   
 [Controles ActiveX MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)