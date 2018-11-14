---
title: 'Controles ActiveX MFC: usando associação de dados em um controle ActiveX'
ms.date: 09/12/2018
f1_keywords:
- bindable
- requestedit
- defaultbind
- displaybind
- dispid
helpviewer_keywords:
- MFC ActiveX controls [MFC], data binding
- data binding [MFC], MFC ActiveX controls
- data-bound controls [MFC], MFC ActiveX controls
- controls [MFC], data binding
- bound controls [MFC], MFC ActiveX
ms.assetid: 476b590a-bf2a-498a-81b7-dd476bd346f1
ms.openlocfilehash: 9efac8ba0889d648def622ca045b9398c8eeef11
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51518483"
---
# <a name="mfc-activex-controls-using-data-binding-in-an-activex-control"></a>Controles ActiveX MFC: usando associação de dados em um controle ActiveX

Um dos usos mais poderosos de controles ActiveX é vinculação de dados, que permite que uma propriedade do controle a ser associado a um campo específico em um banco de dados. Quando um usuário modifica dados nessa propriedade associada, o controle notifica o banco de dados e solicitações que o campo de registro sejam atualizados. O banco de dados, em seguida, notifica o controle do sucesso ou falha da solicitação.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Este artigo aborda o lado de controle da sua tarefa. Implementar as interações de associação de dados com o banco de dados é de responsabilidade do contêiner de controle. Como gerenciar as interações de banco de dados em seu contêiner está além do escopo desta documentação. Como você prepara o controle de vinculação de dados é explicado no restante deste artigo.

![Diagrama conceitual de um dado&#45;controle de limite](../mfc/media/vc374v1.gif "vc374v1") diagrama conceitual de um controle associado a dados

O `COleControl` classe fornece duas funções de membro que tornam um processo fácil implementar de vinculação de dados. A primeira função, [BoundPropertyRequestEdit](../mfc/reference/colecontrol-class.md#boundpropertyrequestedit), é usado para solicitar permissão para alterar o valor da propriedade. [BoundPropertyChanged](../mfc/reference/colecontrol-class.md#boundpropertychanged), a segunda função, é chamado depois que o valor da propriedade foi alterado com êxito.

Este artigo aborda os seguintes tópicos:

- [Criação de uma propriedade de estoque associável](#vchowcreatingbindablestockproperty)

- [Criando um método Get/Set associável](#vchowcreatingbindablegetsetmethod)

##  <a name="vchowcreatingbindablestockproperty"></a> Criação de uma propriedade de estoque associável

É possível criar uma propriedade de estoque de associação de dados, embora seja mais provável que você desejará um [método get/set associável](#vchowcreatingbindablegetsetmethod).

> [!NOTE]
> Propriedades de estoque têm o `bindable` e `requestedit` atributos por padrão.

#### <a name="to-add-a-bindable-stock-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de estoque vinculável usando o Assistente para adicionar propriedade

1. Iniciar um projeto usando o [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md).

1. Clique com botão direito no nó de interface para o seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

1. Selecione uma das entradas do **nome da propriedade** lista suspensa. Por exemplo, você pode selecionar **texto**.

   Porque **texto** é uma propriedade de estoque, o **associável** e **requestedit** atributos já são verificados.

1. Selecione as seguintes caixas de seleção do **atributos de IDL** guia: **displaybind** e **defaultbind** para adicionar os atributos à definição da propriedade do projeto. Arquivo IDL. Esses atributos tornar o controle visível para o usuário e verifique a propriedade de estoque a propriedade associável padrão.

Neste ponto, seu controle pode exibir dados de uma fonte de dados, mas o usuário não será capaz de atualizar os campos de dados. Se você quiser que o controle também ser capaz de atualizar dados, alterar o `OnOcmCommand` [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) função para ter a seguinte aparência:

[!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

Agora você pode compilar o projeto, que registrará o controle. Quando você insere o controle em uma caixa de diálogo, o **campo de dados** e **fonte de dados** propriedades serão adicionadas e agora você pode selecionar uma fonte de dados e o campo a ser exibido no controle.

##  <a name="vchowcreatingbindablegetsetmethod"></a> Criando um método Get/Set associável

Além de uma associação de dados get/set de método, você também pode criar uma [propriedade de estoque associável](#vchowcreatingbindablestockproperty).

> [!NOTE]
> Este procedimento pressupõe que você tem um controle ActiveX que pode efetuar subclasses de projeto a um controle do Windows.

#### <a name="to-add-a-bindable-getset-method-using-the-add-property-wizard"></a>Para adicionar um método get/set vinculáveis usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. Sobre o **configurações de controle** , selecione uma classe de janela para o controle para a subclasse. Por exemplo, você talvez queira subclasse um controle de edição.

1. Carregar o projeto do seu controle.

1. Clique com botão direito no nó de interface para o seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

1. Digite o nome da propriedade a **nome da propriedade** caixa. Use `MyProp` para este exemplo.

1. Selecione um tipo de dados do **tipo de propriedade** caixa de listagem suspensa. Use **curto** para este exemplo.

1. Para **tipo de implementação**, clique em **métodos Get/Set**.

1. Selecione as seguintes caixas de seleção na guia atributos IDL: **associável**, **requestedit**, **displaybind**, e **defaultbind** adicionar os atributos para a definição da propriedade do projeto. Arquivo IDL. Esses atributos tornar o controle visível para o usuário e verifique a propriedade de estoque a propriedade associável padrão.

1. Clique em **Finalizar**.

1. Modificar o corpo do `SetMyProp` função para que ele contém o código a seguir:

   [!code-cpp[NVC_MFC_AxData#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_2.cpp)]

1. O parâmetro passado para o `BoundPropertyChanged` e `BoundPropertyRequestEdit` funções é o dispid da propriedade, que é o parâmetro passado para o atributo de ID () para a propriedade na. Arquivo IDL.

1. Modificar a [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) funcionar de modo que ele contém o código a seguir:

   [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

1. Modificar o `OnDraw` função para que ele contém o código a seguir:

   [!code-cpp[NVC_MFC_AxData#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_3.cpp)]

1. Na seção pública do arquivo de cabeçalho do arquivo de cabeçalho para sua classe de controle, adicione as seguintes definições (construtores) para as variáveis de membro:

   [!code-cpp[NVC_MFC_AxData#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_4.h)]

1. Verifique a seguinte linha na última linha a `DoPropExchange` função:

   [!code-cpp[NVC_MFC_AxData#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_5.cpp)]

1. Modificar o `OnResetState` função para que ele contém o código a seguir:

   [!code-cpp[NVC_MFC_AxData#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_6.cpp)]

1. Modificar o `GetMyProp` função para que ele contém o código a seguir:

   [!code-cpp[NVC_MFC_AxData#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_7.cpp)]

Agora você pode compilar o projeto, que registrará o controle. Quando você insere o controle em uma caixa de diálogo, o **campo de dados** e **fonte de dados** propriedades serão adicionadas e agora você pode selecionar uma fonte de dados e o campo a ser exibido no controle.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

