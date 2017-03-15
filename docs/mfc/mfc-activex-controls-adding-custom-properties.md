---
title: "Controles ActiveX MFC: adicionando propriedades personalizadas | Microsoft Docs"
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
  - "Controles ActiveX MFC, propriedades"
  - "propriedades [MFC], personalizado"
ms.assetid: 85af5167-74c7-427b-b8f3-e0d7b73942e5
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: adicionando propriedades personalizadas
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As propriedades personalizadas das propriedades de estoque naquele propriedades personalizados não são implementadas já pela classe de `COleControl` .  Uma propriedade personalizada é usada para expor qualquer estado ou aparência de um controle ActiveX para um programador que usa o controle.  
  
 Este artigo descreve como adicionar uma propriedade personalizada ao controle ActiveX usando o assistente da propriedade adicionar e explica as alterações resultantes de código.  Os tópicos incluem:  
  
-   [Usando o assistente da propriedade adicionar para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property)  
  
-   [Adicionar alterações do assistente para propriedades personalizadas](#_core_classwizard_changes_for_custom_properties)  
  
 As propriedades personalizadas vêm em quatro tipos de implementação: A variável de membro, variável de membro com notificação, obtém e define métodos, e com parâmetros.  
  
-   Implementação da variável de membro  
  
     Essa implementação representa o estado da propriedade como uma variável de membro na classe do controle.  Use a implementação variável de membro quando não é importante saber quando o valor da propriedade é alterado.  Dos três tipos, essa implementação cria menor quantidade de código de suporte da propriedade.  A macro de entrada do mapa de distribuição para a implementação variável de membro é [DISP\_PROPERTY](../Topic/DISP_PROPERTY.md).  
  
-   Variável de membro com implementação de notificação  
  
     Essa implementação consiste em uma variável de membro e em uma função de notificação criados pelo assistente para adicionar a propriedade.  A função de notificação será chamada automaticamente pela estrutura depois que o valor da propriedade é alterado.  Use a variável de membro com implementação de notificação quando você precisa ser notificado depois que um valor de propriedade é alterada.  Essa implementação requer mais tempo porque exige uma chamada de função.  A macro de entrada do mapa de distribuição para essa implementação é [DISP\_PROPERTY\_NOTIFY](../Topic/DISP_PROPERTY_NOTIFY.md).  
  
-   Obter\/define a implementação dos métodos  
  
     Essa implementação consiste em um par das funções de membro na classe do controle.  A implementação dos métodos get\/conjunto automaticamente chamar a função de membro obter quando um usuário solicita de controle o valor atual da propriedade e a função de membro definida quando as solicitações de usuário de controle que a propriedade seja alterada.  Use essa implementação quando você precisa calcular o valor de uma propriedade durante o tempo de execução, de validar um valor passado pelo usuário de controle antes de modificar a propriedade real, ou a implementação de um tipo de propriedade lido ou somente gravação.  A macro de entrada do mapa de distribuição para essa implementação é [DISP\_PROPERTY\_EX](../Topic/DISP_PROPERTY_EX.md).  A seção a seguir, [Usando o assistente da propriedade adicionar para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property), use a propriedade personalizada de CircleOffset para demonstrar essa implementação.  
  
-   Implementação com parâmetros  
  
     A implementação com parâmetros é suportada pelo assistente para adicionar a propriedade.  Uma propriedade com parâmetros \(às vezes chamada de matriz de propriedade\) pode ser usada para acessar um conjunto de valores por uma única propriedade do controle.  A macro de entrada do mapa de distribuição para essa implementação é `DISP_PROPERTY_PARAM`.  Para obter mais informações sobre a implementação desse tipo, consulte [Implementando uma propriedade com parâmetros](../mfc/mfc-activex-controls-advanced-topics.md) nos controles ActiveX de artigo: Tópicos avançados.  
  
##  <a name="_core_using_classwizard_to_add_a_custom_property"></a> Usando o assistente da propriedade adicionar para adicionar uma propriedade personalizada  
 O procedimento a seguir demonstra como adicionar uma propriedade personalizada, CircleOffset, que usa a implementação dos métodos get\/cluster.  A propriedade personalizada de CircleOffset permite que o usuário de controle com o círculo do centro do retângulo delimitador do controle.  O procedimento para adicionar propriedades personalizadas com uma implementação que não seja obtém ou define métodos é bem semelhante.  
  
 Esse mesmo procedimento também pode ser usado para adicionar outras propriedades personalizadas que você deseja.  Substituir o nome da propriedade personalizada para o nome e os parâmetros de propriedade de CircleOffset.  
  
#### Para adicionar a propriedade personalizada de CircleOffset usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na exibição da classe, expanda o nó da biblioteca do controle.  
  
3.  Clique com o botão direito do mouse no nó da interface para o controle \(o segundo nó do nó da biblioteca\) para abrir o menu de atalho.  
  
4.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
     Isso abre [Assistente de adição de propriedade](../ide/names-add-property-wizard.md).  
  
5.  Na caixa de **Nome da propriedade** , digite `CircleOffset`.  
  
6.  Para **Tipo de Implementação**, clique **Get\/Set Methods**.  
  
7.  Na caixa de **Tipo de propriedade** , **short**selecione.  
  
8.  Os nomes exclusivos do seu obtém e definem funções, ou aceitam nomes padrão.  
  
9. Clique em **Concluir**.  
  
##  <a name="_core_classwizard_changes_for_custom_properties"></a> Adicionar alterações do assistente para propriedades personalizadas  
 Quando você adiciona a propriedade personalizada de CircleOffset, o assistente da propriedade adicionar fizer alterações no cabeçalho \(. H\) e os arquivos de implementação\) \(.CPP de controle classe.  
  
 As seguintes são adicionadas linhas ao. O arquivo de H para declarar duas funções chamou `GetCircleOffset` e `SetCircleOffset`:  
  
 [!code-cpp[NVC_MFC_AxUI#25](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-properties_1.h)]  
  
 A seguinte linha é adicionada ao arquivo de .IDL do controle:  
  
 [!code-cpp[NVC_MFC_AxUI#26](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-properties_2.idl)]  
  
 Essa linha atribui à propriedade de um CircleOffset o número de identificação específico, feito na posição do método nos métodos e na lista de propriedades do assistente para adicionar a propriedade.  
  
 Além disso, a seguinte linha é adicionada ao mapa de distribuição \(no arquivo de .CPP da classe do controle\) para mapear a propriedade de CircleOffset às funções do manipulador de controle dois:  
  
 [!code-cpp[NVC_MFC_AxUI#27](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-properties_3.cpp)]  
  
 Finalmente, as implementações de `GetCircleOffset` e funções de `SetCircleOffset` são adicionadas ao final do arquivo de .CPP do controle.  Na maioria dos casos, você modificará obter a função para retornar o valor da propriedade.  A função de conjunto geral conterá o código a ser executado um antes ou depois da propriedade é alterado.  
  
 [!code-cpp[NVC_MFC_AxUI#28](../mfc/codesnippet/CPP/mfc-activex-controls-adding-custom-properties_4.cpp)]  
  
 Observe que o assistente da propriedade adicionar adiciona automaticamente uma chamada, a [SetModifiedFlag](../Topic/COleControl::SetModifiedFlag.md), ao corpo da função de conjunto.  Chamando essa função marca o controle como alterado.  Se um controle foi alterado, o novo estado será salvo quando o contêiner é salvo.  Essa função deve ser chamada sempre que uma propriedade, salva como parte do estado persistente de controle, valor de muda.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles ActiveX MFC: propriedades](../mfc/mfc-activex-controls-properties.md)   
 [Controles ActiveX MFC: métodos](../mfc/mfc-activex-controls-methods.md)   
 [Classe de COleControl](../mfc/reference/colecontrol-class.md)