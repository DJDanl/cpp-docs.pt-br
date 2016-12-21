---
title: "Controles ActiveX MFC: usando fontes | Microsoft Docs"
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
  - "OnFontChanged"
  - "HeadingFont"
  - "InternalFont"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "fontes, Controles ActiveX"
  - "Método GetFont"
  - "Propriedade HeadingFont"
  - "Método InternalFont"
  - "Classe IPropertyNotifySink"
  - "Controles ActiveX MFC, fontes"
  - "notificações, fontes de controle ActiveX MFC"
  - "Método OnDraw, Controles ActiveX MFC"
  - "Método OnFontChanged"
  - "Método SelectStockFont"
  - "Método SetFont"
  - "Propriedade Stock Font"
ms.assetid: 7c51d602-3f5a-481d-84d1-a5d8a3a71761
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: usando fontes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se o controle ActiveX exibe o texto, você pode permitir que o usuário de controle modificar a aparência do texto modificação de uma propriedade da fonte.  As propriedades da fonte são implementadas como objetos de fonte e pode ser um de dois tipos: estoque ou personalizada.  As propriedades de estoque de fonte são as propriedades preimplemented de fonte que você pode adicionar usando o assistente para adicionar a propriedade.  As propriedades da fonte personalizado não preimplemented e o desenvolvedor de controle determina o comportamento e o uso da propriedade.  
  
 Este artigo abrange os seguintes tópicos:  
  
-   [Usando a propriedade de estoque da fonte](#_core_using_the_stock_font_property)  
  
-   [Usando propriedades da fonte personalizado no seu controle](#_core_implementing_a_custom_font_property)  
  
##  <a name="_core_using_the_stock_font_property"></a> Usando a propriedade de estoque da fonte  
 As propriedades de estoque da fonte preimplemented pela classe [COleControl](../mfc/reference/colecontrol-class.md).  Além disso, uma página de propriedades de fonte padrão também está disponível, permitindo que o usuário altere vários atributos do objeto de fonte, como seu nome, tamanho e estilo.  
  
 Acessar o objeto de fonte [GetFont](../Topic/COleControl::GetFont.md), com [SetFont](../Topic/COleControl::SetFont.md), e as funções de [InternalGetFont](../Topic/COleControl::InternalGetFont.md) de `COleControl`.  O usuário de controle de acesso no objeto de fonte de `GetFont` e `SetFont` funciona como qualquer outro obtém ou define a propriedade.  Quando o acesso ao objeto da fonte é necessário dentro de um controle, use a função de `InternalGetFont` .  
  
 Como discutido em [Controles ActiveX MFC: Propriedades](../mfc/mfc-activex-controls-properties.md), adicione as propriedades de estoque é fácil com [Assistente de adição de propriedade](../ide/names-add-property-wizard.md).  Você escolhe a propriedade da fonte, e o assistente da propriedade adicionar inserirá automaticamente a entrada de estoque da fonte da expedição do controle.  
  
#### Para adicionar a propriedade de estoque da fonte usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
     Isso abre o assistente de propriedade adicionar.  
  
5.  Na caixa de **Nome da propriedade** , clique **Fonte**.  
  
6.  Clique em **Concluir**.  
  
 O assistente da propriedade adicionar adiciona a seguinte linha no mapa da expedição de controle, localizado no arquivo de implementação da classe de controle:  
  
 [!code-cpp[NVC_MFC_AxFont#1](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_1.cpp)]  
  
 Além disso, o assistente da propriedade adicionar adiciona a seguinte linha no arquivo de controle .IDL:  
  
 [!code-cpp[NVC_MFC_AxFont#2](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_2.idl)]  
  
 A propriedade de estoque de legenda é um exemplo de uma propriedade de texto que possa ser desenhada usando as informações de estoque da propriedade da fonte.  Adicione a propriedade de estoque da legenda para controlar usa as etapas semelhantes usadas para a propriedade de estoque da fonte.  
  
#### Para adicionar a propriedade de estoque de legenda usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
     Isso abre o assistente de propriedade adicionar.  
  
5.  Na caixa de **Nome da propriedade** , clique **Legenda**.  
  
6.  Clique em **Concluir**.  
  
 O assistente da propriedade adicionar adiciona a seguinte linha no mapa da expedição de controle, localizado no arquivo de implementação da classe de controle:  
  
 [!code-cpp[NVC_MFC_AxFont#3](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_3.cpp)]  
  
##  <a name="_core_modifying_the_ondraw_function"></a> Alterando a função de OnDraw  
 A implementação padrão de `OnDraw` usa a fonte do sistema do windows para todo o texto exibido no controle.  Isso significa que você deve modificar o código de `OnDraw` selecionando o objeto de fonte no contexto do dispositivo.  Para fazer isso, chame [COleControl::SelectStockFont](../Topic/COleControl::SelectStockFont.md) e passe o contexto do dispositivo de controle, conforme mostrado no seguinte exemplo:  
  
 [!code-cpp[NVC_MFC_AxFont#4](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_4.cpp)]  
  
 Depois que a função de `OnDraw` foi modificada para usar o objeto de fonte, todo o texto dentro do controle é exibido com as características da propriedade de fonte do estoque de controle.  
  
##  <a name="_core_using_custom_font_properties_in_your_control"></a> Usando propriedades da fonte personalizado no seu controle  
 Além da propriedade de estoque da fonte, o controle ActiveX pode ter propriedades da fonte personalizado.  Para adicionar uma propriedade de fonte personalizado você deve:  
  
-   Use o assistente para adicionar a propriedade para implementar a propriedade da fonte personalizado.  
  
-   [Notificações da fonte de processamento](#_core_processing_font_notifications).  
  
-   [Implementando uma nova interface de notificação da fonte](#_core_implementing_a_new_font_notification_interface).  
  
###  <a name="_core_implementing_a_custom_font_property"></a> Implementando uma propriedade de fonte personalizado  
 Para implementar uma propriedade de fonte personalizado, use o assistente da propriedade adicionar para adicionar a propriedade para e depois fazer algumas alterações no código.  As seções a seguir descrevem como adicionar a propriedade personalizada de `HeadingFont` ao controle de exemplo.  
  
##### Para adicionar a propriedade da fonte personalizado usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
     Isso abre o assistente de propriedade adicionar.  
  
5.  Na caixa de **Nome da propriedade** , digite um nome para a propriedade.  Para esse exemplo, use **HeadingFont**.  
  
6.  Para **Tipo de Implementação**, clique **Get\/Set Methods**.  
  
7.  Na caixa de **Tipo de propriedade** , **IDispatch\*** selecione para o tipo de propriedade.  
  
8.  Clique em **Concluir**.  
  
 O assistente da propriedade adicionar cria o código para adicionar a propriedade personalizada de `HeadingFont` à classe de `CSampleCtrl` e arquivo de SAMPLE.IDL.  Como `HeadingFont` é do tipo de propriedade obter\/cluster, o assistente da propriedade adicionar altera o mapa de expedição da classe de `CSampleCtrl` para incluir uma entrada macro de `DISP_PROPERTY_EX_ID`[DISP\_PROPERTY\_EX](../Topic/DISP_PROPERTY_EX.md) :  
  
 [!code-cpp[NVC_MFC_AxFont#5](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_5.cpp)]  
  
 A macro de `DISP_PROPERTY_EX` associa o nome da propriedade de `HeadingFont` com sua classe correspondente de `CSampleCtrl` obtém e define métodos, `GetHeadingFont` e `SetHeadingFont`.  O tipo do valor da propriedade também estiver especificado; nesse caso, **VT\_FONT**.  
  
 O assistente para adicionar propriedade também adiciona uma declaração no arquivo de cabeçalho de controle \(. H\) para `GetHeadingFont` e `SetHeadingFont` funções e adiciona os modelos de função no arquivo de implementação de controle \(.CPP\):  
  
 [!code-cpp[NVC_MFC_AxFont#6](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_6.cpp)]  
  
 Finalmente, o assistente da propriedade adicionar modificar o arquivo de controle .IDL adicionando uma entrada para a propriedade de `HeadingFont` :  
  
 [!code-cpp[NVC_MFC_AxFont#7](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_7.idl)]  
  
### Alterações no código de controle  
 Agora que você adicionou a propriedade de `HeadingFont` ao controle, você deve fazer nenhuma alteração ao cabeçalho de controle e arquivos de implementação para oferecer suporte completo à nova propriedade.  
  
 No arquivo de cabeçalho de controle \(. H\), adicione a seguinte declaração de uma variável de membro protegido:  
  
 [!code-cpp[NVC_MFC_AxFont#8](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_8.h)]  
  
 No arquivo de implementação de controle \(.CPP\), faça o seguinte:  
  
-   Inicializar `m_fontHeading` no construtor de controle.  
  
     [!code-cpp[NVC_MFC_AxFont#9](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_9.cpp)]  
  
-   Declare uma estrutura de **FONTDESC** estático que contém atributos padrão da fonte.  
  
     [!code-cpp[NVC_MFC_AxFont#10](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_10.cpp)]  
  
-   Na função de membro de `DoPropExchange` de controle, adicione uma chamada à função de `PX_Font` .  Isso fornece a inicialização e a persistência da propriedade da fonte personalizado.  
  
     [!code-cpp[NVC_MFC_AxFont#11](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_11.cpp)]  
  
-   Concluir que implementa a função de membro de `GetHeadingFont` do controle.  
  
     [!code-cpp[NVC_MFC_AxFont#12](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_12.cpp)]  
  
-   Concluir que implementa a função de membro de `SetHeadingFont` do controle.  
  
     [!code-cpp[NVC_MFC_AxFont#13](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_13.cpp)]  
  
-   Modifique a função de membro de `OnDraw` de controle para definir uma variável para manter a fonte selecionada anteriormente.  
  
     [!code-cpp[NVC_MFC_AxFont#14](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_14.cpp)]  
  
-   Modifique a função de membro de `OnDraw` de controle para selecionar a fonte personalizado no contexto do dispositivo adicionando a seguinte linha onde quer que a fonte deve ser usada.  
  
     [!code-cpp[NVC_MFC_AxFont#15](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_15.cpp)]  
  
-   Modifique a função de membro de `OnDraw` de controle para selecionar a fonte anterior de novo no contexto do dispositivo adicionando a seguinte linha depois que a fonte usada.  
  
     [!code-cpp[NVC_MFC_AxFont#16](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_16.cpp)]  
  
 Depois que a propriedade da fonte personalizado foi implementada, a página de propriedades de fonte padrão deve ser implementada, permitindo que os usuários alterem controle da fonte atual do controle.  Para adicionar a ID da página de propriedades da página de propriedades de fonte padrão, insira a seguinte linha após a macro de `BEGIN_PROPPAGEIDS` :  
  
 [!code-cpp[NVC_MFC_AxFont#17](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_17.cpp)]  
  
 Você deve também incrementar o parâmetro de contagem de seu macro de `BEGIN_PROPPAGEIDS` por um.  A linha a seguir ilustra esta:  
  
 [!code-cpp[NVC_MFC_AxFont#18](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_18.cpp)]  
  
 Depois que essas alterações, recrie o projeto inteiro inserir a funcionalidade adicional.  
  
###  <a name="_core_processing_font_notifications"></a> Notificações da fonte de processamento  
 Na maioria dos casos as necessidades de controle de saber quando as características do objeto da fonte foram alteradas.  Cada objeto de fonte é capaz de fornecer notificações quando for alterada chamando uma função de membro da interface de **IFontNotification** , implementado por `COleControl`.  
  
 Se o controle usa a propriedade de estoque da fonte, as notificações são tratadas pela função de membro de `OnFontChanged` de `COleControl`.  Quando você adiciona propriedades da fonte personalizado, você pode mandá\-las usar a mesma implementação.  No exemplo na seção anterior, isto era feito transmitindo &**m\_xFontNotification** ao inicializar a variável de membro de **m\_fontHeading** .  
  
 ![Implementar várias Interfaces de objeto de fonte](../mfc/media/vc373q1.png "vc373Q1")  
Implementando várias interfaces de objeto da fonte  
  
 As linhas sólidas na figura acima mostram que ambos os objetos da fonte estiverem usando a mesma implementação de **IFontNotification**.  Isso pode causar problemas se você quisesse para distinguir que a fonte alterado.  
  
 Uma maneira de distinguir entre as notificações do objeto de fonte do controle é criar uma implementação da interface de **IFontNotification** separada para cada objeto de fonte no controle.  Essa técnica permite que você no código de desenho atualizando somente a cadeia de caracteres, ou as cadeias de caracteres, que usam a fonte recentemente alterada.  As seções a seguir demonstram as etapas necessárias para implementar interfaces separadas de notificação para uma segunda propriedade da fonte.  A segunda propriedade da fonte é usada para ser a propriedade de `HeadingFont` que foi adicionada na seção anterior.  
  
###  <a name="_core_implementing_a_new_font_notification_interface"></a> Implementando uma nova interface de notificação da fonte  
 Para distinguir as notificações de dois ou mais fontes, uma nova interface de notificação deve ser implementada para cada fonte usada no controle.  As seções a seguir descrevem como implementar uma nova interface de notificação da fonte alterando o cabeçalho de controle e os arquivos de implementação.  
  
### Adições ao cabeçalho Arquivo  
 No arquivo de cabeçalho de controle \(. H\), adiciona as seguintes linhas à declaração de classe:  
  
 [!code-cpp[NVC_MFC_AxFont#19](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_19.h)]  
  
 Isso cria uma implementação da interface de `IPropertyNotifySink` chamada `HeadingFontNotify`.  Essa nova interface contém um método chamado `OnChanged`.  
  
### Adições à implementação Arquivo  
 No código que inicializa a fonte do título \(no construtor de controle\), altere `&m_xFontNotification` a `&m_xHeadingFontNotify`.  Adicione o seguinte código:  
  
 [!code-cpp[NVC_MFC_AxFont#20](../mfc/codesnippet/CPP/mfc-activex-controls-using-fonts_20.cpp)]  
  
 Os métodos de `AddRef` e de `Release` na interface de `IPropertyNotifySink` controlam a contagem de referência do objeto do controle ActiveX.  Quando o controle obtém acesso ao ponteiro da interface, o controle `AddRef` chama para incrementar a contagem de referência.  Quando o controle é concluído com o ponteiro, chama `Release`, da mesma forma que **GlobalFree** pode ser chamado para liberar um bloco de memória global.  Quando a contagem de referência dessa interface vá para zero, a implementação da interface pode ser liberada.  Neste exemplo, a função de `QueryInterface` retorna um ponteiro para uma interface de `IPropertyNotifySink` em um objeto específico.  Esta função permite que um controle ActiveX consulta um objeto para determinar as interfaces da suporte.  
  
 Depois que essas alterações foram feitas ao seu projeto, recrie o projeto e use o contêiner de teste para testar a interface.  Consulte [Propriedades e eventos de teste com contêineres de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter mais informações sobre como acessar o contêiner de teste.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: usando imagens em um controle ActiveX](../mfc/mfc-activex-controls-using-pictures-in-an-activex-control.md)   
 [Controles ActiveX MFC: usando páginas de propriedade de estoque](../mfc/mfc-activex-controls-using-stock-property-pages.md)