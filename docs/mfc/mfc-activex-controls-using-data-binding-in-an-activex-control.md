---
title: 'Controles ActiveX MFC: Usando associação de dados em um controle ActiveX | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- bindable
- requestedit
- defaultbind
- displaybind
- dispid
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], data binding
- data binding [MFC], MFC ActiveX controls
- data-bound controls [MFC], MFC ActiveX controls
- controls [MFC], data binding
- bound controls [MFC], MFC ActiveX
ms.assetid: 476b590a-bf2a-498a-81b7-dd476bd346f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 267d47b7e061e3bde39b199cd948ba9875dea16b
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36929725"
---
# <a name="mfc-activex-controls-using-data-binding-in-an-activex-control"></a>Controles ActiveX MFC: usando associação de dados em um controle ActiveX
Um dos usos mais eficientes dos controles ActiveX é associação de dados, que permite que uma propriedade do controle a ser associado a um campo específico em um banco de dados. Quando um usuário modifica dados nessa propriedade associada, o controle notifica o banco de dados e as solicitações que o campo de registro sejam atualizados. O banco de dados, em seguida, notifica o controle do sucesso ou falha da solicitação.  
  
 Este artigo aborda o lado de controle de sua tarefa. Implementar as interações de associação de dados com o banco de dados é de responsabilidade do contêiner de controle. Como você gerencia as interações do banco de dados em seu contêiner está além do escopo desta documentação. Como preparar o controle de associação de dados é explicado no restante deste artigo.  
  
 ![Diagrama conceitual de um dado&#45;controle acoplado](../mfc/media/vc374v1.gif "vc374v1")  
Diagrama conceitual de um controle associado a dados  
  
 O `COleControl` classe fornece duas funções de membro que fazem um processo fácil de implementar de associação de dados. A primeira função, [BoundPropertyRequestEdit](../mfc/reference/colecontrol-class.md#boundpropertyrequestedit), é usado para solicitar permissão para alterar o valor da propriedade. [BoundPropertyChanged](../mfc/reference/colecontrol-class.md#boundpropertychanged), a segunda função, é chamado depois que o valor da propriedade foi alterado com êxito.  
  
 Este artigo aborda os seguintes tópicos:  
  
-   [Criar uma propriedade de estoque vinculável](#vchowcreatingbindablestockproperty)  
  
-   [Criando um método Get/Set vinculáveis](#vchowcreatingbindablegetsetmethod)  
  
##  <a name="vchowcreatingbindablestockproperty"></a> Criar uma propriedade de estoque vinculável  
 É possível criar uma propriedade de estoque de associação de dados, embora é mais provável que você queira um [método associável get/set](#vchowcreatingbindablegetsetmethod).  
  
> [!NOTE]
>  Propriedades de estoque tem o `bindable` e `requestedit` atributos por padrão.  
  
#### <a name="to-add-a-bindable-stock-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de estoque vinculável usando o Assistente para adicionar propriedade  
  
1.  Iniciar um projeto usando o [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md).  
  
2.  Clique com botão direito no nó de interface de seu controle.  
  
     Isso abre o menu de atalho.  
  
3.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **adicionar propriedade**.  
  
4.  Selecione uma das entradas do **nome da propriedade** lista suspensa. Por exemplo, você pode selecionar **texto**.  
  
     Porque **texto** é uma propriedade de estoque, o **associável** e **requestedit** atributos já estão marcados.  
  
5.  Selecione as seguintes caixas de seleção do **atributos IDL** guia: **displaybind** e **defaultbind** para adicionar os atributos para a definição de propriedade do projeto. Arquivo IDL. Esses atributos Verifique o controle visíveis para o usuário e a propriedade de estoque a propriedade associável padrão.  
  
 Neste ponto, o controle pode exibir dados de uma fonte de dados, mas o usuário não poderá atualizar campos de dados. Se você desejar que o controle também seja capaz de atualizar dados, alterar o `OnOcmCommand` [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) função para ter a seguinte aparência:  
  
 [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]  
  
 Agora você pode compilar o projeto, o que registrar o controle. Quando você insere o controle em uma caixa de diálogo, o **campo de dados** e **fonte de dados** propriedades serão adicionadas e agora você pode selecionar uma fonte de dados e o campo a ser exibido no controle.  
  
##  <a name="vchowcreatingbindablegetsetmethod"></a> Criando um método Get/Set vinculáveis  
 Além de uma associação de dados get/set método, você também pode criar um [propriedade de estoque associável](#vchowcreatingbindablestockproperty).  
  
> [!NOTE]
>  Este procedimento pressupõe que você tem um controle ActiveX que as subclasses de projeto a um controle do Windows.  
  
#### <a name="to-add-a-bindable-getset-method-using-the-add-property-wizard"></a>Para adicionar um método get/set vinculáveis usando o Assistente para adicionar propriedade  
  
1.  Carregar projeto do controle.  
  
2.  No **configurações de controle** , selecione uma classe de janela para o controle para subclasse. Por exemplo, você talvez queira subclasse um controle de edição.  
  
3.  Carregar projeto do controle.  
  
4.  Clique com botão direito no nó de interface de seu controle.  
  
     Isso abre o menu de atalho.  
  
5.  No menu de atalho, clique em **adicionar** e, em seguida, clique em **adicionar propriedade**.  
  
6.  Digite o nome da propriedade de **nome da propriedade** caixa. Use `MyProp` para este exemplo.  
  
7.  Selecione um tipo de dados de **tipo de propriedade** caixa de listagem suspensa. Use **curto** para este exemplo.  
  
8.  Para **o tipo de implementação**, clique em **métodos Get/Set**.  
  
9. Selecione as seguintes caixas de seleção na guia atributos IDL: **associável**, **requestedit**, **displaybind**, e **defaultbind** para adicionar os atributos para a definição de propriedade do projeto. Arquivo IDL. Esses atributos Verifique o controle visíveis para o usuário e a propriedade de estoque a propriedade associável padrão.  
  
10. Clique em **Finalizar**.  
  
11. Modifique o corpo do `SetMyProp` função para que ele contém o código a seguir:  
  
     [!code-cpp[NVC_MFC_AxData#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_2.cpp)]  
  
12. O parâmetro passado para o `BoundPropertyChanged` e `BoundPropertyRequestEdit` funções é dispid da propriedade, que é o parâmetro passado para o atributo de ID () para a propriedade no. Arquivo IDL.  
  
13. Modificar o [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) funcionar, portanto, contém o código a seguir:  
  
     [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]  
  
14. Modificar o `OnDraw` função para que ele contém o código a seguir:  
  
     [!code-cpp[NVC_MFC_AxData#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_3.cpp)]  
  
15. Para a seção pública do arquivo de cabeçalho do arquivo de cabeçalho para a sua classe de controle, adicione as seguintes definições (construtores) para variáveis de membro:  
  
     [!code-cpp[NVC_MFC_AxData#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_4.h)]  
  
16. Verifique a linha a seguir na última linha a `DoPropExchange` função:  
  
     [!code-cpp[NVC_MFC_AxData#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_5.cpp)]  
  
17. Modificar o `OnResetState` função para que ele contém o código a seguir:  
  
     [!code-cpp[NVC_MFC_AxData#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_6.cpp)]  
  
18. Modificar o `GetMyProp` função para que ele contém o código a seguir:  
  
     [!code-cpp[NVC_MFC_AxData#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_7.cpp)]  
  
 Agora você pode compilar o projeto, o que registrar o controle. Quando você insere o controle em uma caixa de diálogo, o **campo de dados** e **fonte de dados** propriedades serão adicionadas e agora você pode selecionar uma fonte de dados e o campo a ser exibido no controle.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)   

