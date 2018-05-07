---
title: 'Controles ActiveX MFC: Usando imagens em um controle ActiveX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- LPPICTUREDISP
dev_langs:
- C++
helpviewer_keywords:
- OnDraw method, MFC ActiveX controls
- MFC ActiveX controls [MFC], pictures
- OnDraw method [MFC]
- OnResetState method [MFC]
- CLSID_CPicturePropPage [MFC]
ms.assetid: 2e49735c-21b9-4442-bb3d-c82ef258eec9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 313cbe53189a4a6e9b87b1723a166de83f56df05
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-activex-controls-using-pictures-in-an-activex-control"></a>Controles ActiveX MFC: usando imagens em um controle ActiveX
Este artigo descreve o tipo de imagem comuns e como implementá-la em seu controle ActiveX. Os tópicos incluem:  
  
-   [Visão geral das propriedades da imagem personalizada](#_core_overview_of_custom_picture_properties)  
  
-   [Implementando uma propriedade de imagem personalizada em seu controle ActiveX](#_core_implementing_a_custom_picture_property_in_your_activex_control)  
  
-   [Adições ao seu projeto de controle](#_core_additions_to_your_control_project)  
  
##  <a name="_core_overview_of_custom_picture_properties"></a> Visão geral das propriedades da imagem personalizada  
 Um tipo de imagem é um de um grupo de tipos comuns a alguns controles ActiveX. O tipo de imagem trata metarquivos, bitmaps e ícones e permite que o usuário especifique uma imagem a ser exibida em um controle ActiveX. Propriedades personalizadas da imagem são implementadas usando um objeto de imagem e funções de Get/Set que permitem o acesso de usuário de controle para a propriedade de imagem. Usuários de controle de acesso a propriedade de imagem personalizada usando o página de propriedades de imagem de estoque.  
  
 Além do tipo de imagem padrão, os tipos de fontes e cores também estão disponíveis. Para obter mais informações sobre como usar o tipo de fonte padrão do seu controle ActiveX, consulte o artigo [controles ActiveX MFC: usando fontes](../mfc/mfc-activex-controls-using-fonts.md).  
  
 As classes de controle ActiveX fornecem vários componentes que você pode usar para implementar a propriedade de imagem dentro do controle. Esses componentes incluem:  
  
-   O [CPictureHolder](../mfc/reference/cpictureholder-class.md) classe.  
  
     Essa classe fornece acesso fácil para o objeto de imagem e a funcionalidade do item exibido pela propriedade imagem personalizada.  
  
-   Suporte para propriedades de tipo **LPPICTUREDISP**, implementado com funções de Get/Set.  
  
     Usando o modo de exibição de classe que você pode adicionar rapidamente uma propriedade personalizada ou propriedades, que suporta o tipo de imagem. Para obter mais informações sobre como adicionar propriedades do controle ActiveX com o modo de exibição de classe, consulte o artigo [controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md).  
  
-   Uma página de propriedades que manipula a imagem ou mais propriedades do controle.  
  
     Esta página de propriedades é parte de um grupo de páginas de propriedade de estoque disponíveis para controles ActiveX. Para obter mais informações sobre páginas de propriedades do controle ActiveX, consulte o artigo [controles ActiveX MFC: usando páginas de propriedades de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)  
  
##  <a name="_core_implementing_a_custom_picture_property_in_your_activex_control"></a> Implementando uma propriedade de imagem personalizada em seu controle ActiveX  
 Quando você tiver concluído as etapas descritas nesta seção, o controle pode exibir imagens escolhidas pelo usuário. O usuário pode alterar a imagem exibida usando uma página de propriedade que mostra a imagem atual e tem um botão de procura que permite que o usuário selecionados imagens diferentes.  
  
 Uma propriedade de imagem personalizada é implementada usando um processo semelhante àquela usada para implementar outras propriedades, a principal diferença é que a propriedade personalizada deve oferecer suporte a um tipo de imagem. Porque o item da propriedade de imagem deve ser desenhado pelo controle ActiveX, um número de adições e modificações deve ser feito para a propriedade antes que ele pode ser totalmente implementado.  
  
 Para implementar uma propriedade de imagem personalizada, você deve fazer o seguinte:  
  
-   [Adicione código ao seu projeto de controle](#_core_additions_to_your_control_project).  
  
     Uma padrão imagem propriedade ID de página, um membro de dados do tipo `CPictureHolder`e uma propriedade personalizada de tipo **LPPICTUREDISP** com um Get/Set implementação deve ser adicionada.  
  
-   [Modificar várias funções em sua classe de controle](#_core_modifications_to_your_control_project).  
  
     Essas modificações serão feitas para várias funções que são responsáveis pelo desenho do controle ActiveX.  
  
##  <a name="_core_additions_to_your_control_project"></a> Adições ao seu projeto de controle  
 Para adicionar a ID de página de propriedade para a página de propriedades de imagem padrão, insira a linha a seguir após o `BEGIN_PROPPAGEIDS` macro no arquivo de implementação de controle (. CPP):  
  
 [!code-cpp[NVC_MFC_AxPic#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_1.cpp)]  
  
 Você também deve incrementar o parâmetro de contagem de seu `BEGIN_PROPPAGEIDS` macro por um. A linha a seguir ilustra isso:  
  
 [!code-cpp[NVC_MFC_AxPic#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_2.cpp)]  
  
 Para adicionar o `CPictureHolder` membro de dados para a classe de controle, insira a linha a seguir na seção protegida da declaração de classe do controle no arquivo de controle de cabeçalho (. H):  
  
 [!code-cpp[NVC_MFC_AxPic#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_3.h)]  
  
 Não é necessário nomear o membro de dados `m_pic`; qualquer nome será suficiente.  
  
 Em seguida, adicione uma propriedade personalizada que dá suporte a um tipo de imagem:  
  
#### <a name="to-add-a-custom-picture-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de imagem personalizada usando o Assistente para adicionar propriedade  
  
1.  Carregar projeto do controle.  
  
2.  No modo de exibição de classe, expanda o nó de biblioteca de seu controle.  
  
3.  Para abrir o menu de atalho, clique com botão direito no nó de interface de seu controle (o segundo nó do nó de biblioteca).  
  
4.  No menu de atalho, escolha **adicionar** e **adicionar propriedade**.  
  
5.  No **nome da propriedade** , digite o nome da propriedade. Para fins de exemplo, `ControlPicture` é usado neste procedimento.  
  
6.  No **tipo de propriedade** selecione **IPictureDisp\***  para o tipo de propriedade.  
  
7.  Para **o tipo de implementação**, clique em **métodos Get/Set**.  
  
8.  Digite nomes exclusivos para o Get e definir funções ou aceite os nomes padrão. (Neste exemplo, os nomes padrão `GetControlPicture` e `SetControlPicture` são usados.)  
  
9. Clique em **Finalizar**.  
  
 O Assistente para adicionar propriedade adiciona o código a seguir entre os comentários de mapa de expedição no cabeçalho de controle (. H) arquivo:  
  
 [!code-cpp[NVC_MFC_AxPic#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_4.h)]  
  
 Além disso, o código a seguir foi inserido no mapa de expedição da implementação do controle (. Arquivo CPP):  
  
 [!code-cpp[NVC_MFC_AxPic#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_5.cpp)]  
  
 O Assistente para adicionar propriedade também adiciona as seguintes funções de dois stub no arquivo de implementação de controle:  
  
 [!code-cpp[NVC_MFC_AxPic#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_6.cpp)]  
  
> [!NOTE]
>  Os nomes de classe e a função de controle podem ser diferentes do exemplo acima.  
  
###  <a name="_core_modifications_to_your_control_project"></a> Modificações ao seu projeto de controle  
 Depois de ter feito as inclusões necessárias ao seu projeto de controle, você precisa modificar várias funções que afetam a renderização do controle ActiveX. Essas funções, `OnResetState`, `OnDraw`, e as funções Get/Set de uma propriedade de imagem personalizada, estão localizados no arquivo de implementação de controle. (Observe que, neste exemplo de classe de controle é chamado `CSampleCtrl`, o `CPictureHolder` é chamado de membro de dados `m_pic`, e o nome de propriedade de imagem personalizada é `ControlPicture`.)  
  
 No controle `OnResetState` funcionar, adicione a seguinte linha opcional após a chamada a `COleControl::OnResetState`:  
  
 [!code-cpp[NVC_MFC_AxPic#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_7.cpp)]  
  
 Isso define a imagem do controle a uma imagem em branco.  
  
 Para desenhar a imagem corretamente, fazer uma chamada para [CPictureHolder::Render](../mfc/reference/cpictureholder-class.md#render) no controle `OnDraw` função. Modificar a função para se parecer com o exemplo a seguir:  
  
 [!code-cpp[NVC_MFC_AxPic#8](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_8.cpp)]  
  
 A função Get da propriedade de imagem personalizada do controle, adicione a seguinte linha:  
  
 [!code-cpp[NVC_MFC_AxPic#9](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_9.cpp)]  
  
 Na função de conjunto de propriedades de imagem personalizada do controle, adicione as seguintes linhas:  
  
 [!code-cpp[NVC_MFC_AxPic#10](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_10.cpp)]  
  
 A propriedade de imagem deve ser feita persistente para que as informações adicionadas em tempo de design serão exibido em tempo de execução. Adicione a seguinte linha para o `COleControl`-derivado da classe `DoPropExchange` função:  
  
 [!code-cpp[NVC_MFC_AxPic#11](../mfc/codesnippet/cpp/mfc-activex-controls-using-pictures-in-an-activex-control_11.cpp)]  
  
> [!NOTE]
>  Os nomes de classe e a função podem ser diferentes do exemplo acima.  
  
 Depois de concluir as modificações, recompile o projeto para incorporar a nova funcionalidade da propriedade de imagem personalizada e use o contêiner de teste para testar a nova propriedade. Consulte [testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: Usando fontes](../mfc/mfc-activex-controls-using-fonts.md)   
 [Controles ActiveX do MFC: páginas de propriedade](../mfc/mfc-activex-controls-property-pages.md)

