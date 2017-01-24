---
title: "Controles ActiveX MFC: usando associa&#231;&#227;o de dados em um controle ActiveX | Microsoft Docs"
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
  - "bindable"
  - "requestedit"
  - "defaultbind"
  - "displaybind"
  - "dispid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles associados [C++], MFC ActiveX"
  - "controles [MFC], associação de dados"
  - "associação de dados [C++], Controles ActiveX MFC"
  - "controles de dados associados [C++], Controles ActiveX MFC"
  - "Controles ActiveX MFC, associação de dados"
ms.assetid: 476b590a-bf2a-498a-81b7-dd476bd346f1
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: usando associa&#231;&#227;o de dados em um controle ActiveX
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um dos usos mais avançados de controles ActiveX é a associação de dados, que permite que uma propriedade do controle se associa com um campo específico em um base de dados.  Quando um usuário modifica dados nesta propriedade associada, o controle notifica o base de dados e solicitará que o campo de registro seja atualizado.  O base de dados notifica o controle de êxito ou a falha da solicitação.  
  
 Este artigo abrange o lado do controle da tarefa.  Implementar as interações de associação de dados com o base de dados é responsabilidade do contêiner do controle.  Como você gerencia as interações de base de dados do contêiner está além do escopo desta documentação.  Como você se prepara o controle para a associação de dados é explicado no restante deste artigo.  
  
 ![Controle associado a dados](../mfc/media/vc374v1.png "vc374V1")  
Diagrama conceitual de um controle associada a dados  
  
 A classe de `COleControl` fornece duas funções de membro que fazem a associação de dados em processo fácil para implementar.  A primeira função, [BoundPropertyRequestEdit](../Topic/COleControl::BoundPropertyRequestEdit.md), é usada para solicitar permissão para alterar o valor da propriedade.  [BoundPropertyChanged](../Topic/COleControl::BoundPropertyChanged.md), a segunda função, é chamado depois que o valor da propriedade tiver sido modificado com êxito.  
  
 Este artigo abrange os seguintes tópicos:  
  
-   [Criando uma propriedade de estoque Bindable](#vchowcreatingbindablestockproperty)  
  
-   [Criando um Bindable obter\/define o método](#vchowcreatingbindablegetsetmethod)  
  
##  <a name="vchowcreatingbindablestockproperty"></a> Criando uma propriedade de estoque Bindable  
 É possível criar uma propriedade de estoque associada a dados, embora seja mais provável que devem [bindable obter\/define o método](#vchowcreatingbindablegetsetmethod).  
  
> [!NOTE]
>  As propriedades de estoque têm os atributos de **bindable** e de **requestedit** por padrão.  
  
#### Para adicionar uma propriedade de estoque bindable usando o assistente para adicionar propriedade  
  
1.  Inicie um projeto do usando [Assistente de controle ActiveX de MFC](../mfc/reference/mfc-activex-control-wizard.md).  
  
2.  Clique com o botão direito do mouse no nó da interface para o controle.  
  
     Isso abre o menu de atalho.  
  
3.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
4.  Selecione uma das entradas na lista suspensa de **PropriedadeNome** .  Por exemplo, você pode selecionar **Texto**.  
  
     Como **Texto** é uma propriedade de estoque, os atributos de **bindable** e de **requestedit** são verificados nele.  
  
5.  Selecione as seguintes caixas de seleção da guia de **IDL Attributes** : **displaybind** e **defaultbind** para adicionar atributos à definição da propriedade em .IDL arquivo de projeto.  Esses atributos fazem o controle visíveis ao usuário e fazem à propriedade de estoque a propriedade bindable padrão.  
  
 Neste momento, o controle pode exibir dados de uma fonte de dados, mas o usuário não poderá atualizar campos de dados.  Se você deseja que o controle também para poder atualizar dados, altere a função de `OnOcmCommand`[OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) para saber como segue:  
  
 [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]  
  
 Agora você pode criar o projeto, que registrará o controle.  Quando você insere o controle em uma caixa de diálogo, as propriedades de **Campo de dados** e de **Fonte de dados** terão sido adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.  
  
##  <a name="vchowcreatingbindablegetsetmethod"></a> Criando um Bindable obter\/define o método  
 Além de um associada a dados obter\/define o método, você também pode criar [propriedade de estoque bindable](#vchowcreatingbindablestockproperty).  
  
> [!NOTE]
>  Esse procedimento supõe que você tenha um projeto do controle ActiveX que controlam as subclasses o windows.  
  
#### Para adicionar um bindable consiga\/define o método usando o assistente para adicionar propriedade  
  
1.  Carregar o projeto do controle.  
  
2.  Na página de **Control Settings** , selecione uma classe da janela para o controle à subclasse.  Por exemplo, você talvez queira encerrar a subclasse um controle de EDIÇÃO.  
  
3.  Carregar o projeto do controle.  
  
4.  Clique com o botão direito do mouse no nó da interface para o controle.  
  
     Isso abre o menu de atalho.  
  
5.  No menu de atalho, clique **Adicionar** e clique em **Adicionar Propriedade**.  
  
6.  Digite o nome da propriedade na caixa de **Nome da propriedade** .  Use `MyProp` para este exemplo.  
  
7.  Selecione um tipo de dados na caixa de listagem suspensa de **Tipo de propriedade** .  Use **short** para este exemplo.  
  
8.  Para **Tipo de Implementação**, clique **Get\/Set Methods**.  
  
9. Selecione as seguintes caixas de seleção na guia de atributos de IDL: **bindable**, **requestedit**, **displaybind**, e **defaultbind** para adicionar atributos à definição da propriedade em .IDL arquivo de projeto.  Esses atributos fazem o controle visíveis ao usuário e fazem à propriedade de estoque a propriedade bindable padrão.  
  
10. Clique em **Concluir**.  
  
11. Modifique o corpo da função de `SetMyProp` de modo que contém o seguinte código:  
  
     [!code-cpp[NVC_MFC_AxData#2](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_2.cpp)]  
  
12. O parâmetro passado às funções de `BoundPropertyChanged` e de `BoundPropertyRequestEdit` é o dispid de propriedade, que é o parâmetro passado ao atributo id \(\) da propriedade no arquivo de .IDL.  
  
13. Modifique a função de [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) assim que contém o seguinte código:  
  
     [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]  
  
14. Modifique a função de `OnDraw` de modo que contém o seguinte código:  
  
     [!code-cpp[NVC_MFC_AxData#3](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_3.cpp)]  
  
15. A seção pública do arquivo de cabeçalho o arquivo de cabeçalho para a sua classe de controle, adicione as seguintes definições \(construtores\) para variáveis de membro:  
  
     [!code-cpp[NVC_MFC_AxData#4](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_4.h)]  
  
16. Tornar a seguinte linha à última linha em `DoPropExchange` para funcionar:  
  
     [!code-cpp[NVC_MFC_AxData#5](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_5.cpp)]  
  
17. Modifique a função de `OnResetState` de modo que contém o seguinte código:  
  
     [!code-cpp[NVC_MFC_AxData#6](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_6.cpp)]  
  
18. Modifique a função de `GetMyProp` de modo que contém o seguinte código:  
  
     [!code-cpp[NVC_MFC_AxData#7](../mfc/codesnippet/CPP/mfc-activex-controls-using-data-binding-in-an-activex-control_7.cpp)]  
  
 Agora você pode criar o projeto, que registrará o controle.  Quando você insere o controle em uma caixa de diálogo, as propriedades de **Campo de dados** e de **Fonte de dados** terão sido adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)   
 [Controles de dados associados \(ADO e RDO\)](../Topic/Data-Bound%20Controls%20\(ADO%20and%20RDO\).md)