---
title: 'Controles ActiveX MFC: usando associação de dados em um controle ActiveX'
ms.date: 11/19/2018
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
ms.openlocfilehash: 3f16ea3ad77c676695a9d5ca6e2deb10637de455
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621179"
---
# <a name="mfc-activex-controls-using-data-binding-in-an-activex-control"></a>Controles ActiveX MFC: usando associação de dados em um controle ActiveX

Um dos usos mais poderosos dos controles ActiveX é a vinculação de dados, que permite que uma propriedade do controle seja associada a um campo específico em um banco de dados. Quando um usuário modifica dados nessa propriedade associada, o controle notifica o banco e solicita que o campo de registro seja atualizado. Em seguida, o banco de dados notifica o controle do êxito ou da falha da solicitação.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Este artigo aborda o lado do controle da sua tarefa. A implementação das interações de associação de dados com o banco de dado é responsabilidade do contêiner de controle. A maneira como você gerencia as interações de banco de dados em seu contêiner está além do escopo desta documentação. A maneira como você prepara o controle para a vinculação de dados é explicada no restante deste artigo.

![Diagrama conceitual de um controle associado a&#45;de dados](../mfc/media/vc374v1.gif "Diagrama conceitual de um controle associado a&#45;de dados") <br/>
Diagrama conceitual de um controle vinculado a dados

A `COleControl` classe fornece duas funções de membro que tornam a vinculação de dados um processo fácil de implementar. A primeira função, [BoundPropertyRequestEdit](reference/colecontrol-class.md#boundpropertyrequestedit), é usada para solicitar permissão para alterar o valor da propriedade. [BoundPropertyChanged](reference/colecontrol-class.md#boundpropertychanged), a segunda função, é chamada depois que o valor da propriedade tiver sido alterado com êxito.

Este artigo aborda os seguintes tópicos:

- [Criando uma propriedade de estoque acoplável](#vchowcreatingbindablestockproperty)

- [Criando um método Get/Set acoplável](#vchowcreatingbindablegetsetmethod)

## <a name="creating-a-bindable-stock-property"></a><a name="vchowcreatingbindablestockproperty"></a>Criando uma propriedade de estoque acoplável

É possível criar uma propriedade Stock associada a dados, embora seja mais provável que você queira um [método Get/Set acoplável](#vchowcreatingbindablegetsetmethod).

> [!NOTE]
> As propriedades de ações têm os `bindable` `requestedit` atributos e por padrão.

#### <a name="to-add-a-bindable-stock-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de estoque ligável usando o assistente para adicionar propriedade

1. Inicie um projeto usando o [Assistente de controle ActiveX do MFC](reference/mfc-activex-control-wizard.md).

1. Clique com o botão direito do mouse no nó da interface do seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

1. Selecione uma das entradas na lista suspensa **nome da propriedade** . Por exemplo, você pode selecionar **texto**.

   Como o **texto** é uma propriedade de estoque, os atributos **vinculáveis** e **requestedit** já estão marcados.

1. Marque as seguintes caixas de seleção na guia **atributos IDL** : **displaybind** e **defaultbind** para adicionar os atributos à definição de propriedade no projeto. Arquivo IDL. Esses atributos tornam o controle visível para o usuário e tornam a propriedade Stock a propriedade vinculável padrão.

Neste ponto, o controle pode exibir dados de uma fonte de dados, mas o usuário não poderá atualizar os campos de dados. Se você quiser que seu controle também seja capaz de atualizar dados, altere a `OnOcmCommand` função [OnOcmCommand](mfc-activex-controls-subclassing-a-windows-control.md) para ter a seguinte aparência:

[!code-cpp[NVC_MFC_AxData#1](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

Agora você pode criar o projeto, que registrará o controle. Quando você insere o controle em uma caixa de diálogo, as propriedades de **campo de dados** e **fonte de dados** foram adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.

## <a name="creating-a-bindable-getset-method"></a><a name="vchowcreatingbindablegetsetmethod"></a>Criando um método Get/Set acoplável

Além de um método Get/Set vinculado a dados, você também pode criar uma [propriedade de estoque ligável](#vchowcreatingbindablestockproperty).

> [!NOTE]
> Esse procedimento pressupõe que você tenha um projeto de controle ActiveX que subfaz uma subclasse de um controle do Windows.

#### <a name="to-add-a-bindable-getset-method-using-the-add-property-wizard"></a>Para adicionar um método Get/Set acoplável usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Na página **configurações de controle** , selecione uma classe de janela para o controle para subclasse. Por exemplo, você pode querer subclasse de um controle de edição.

1. Carregue o projeto do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

1. Digite o nome da propriedade na caixa **nome da propriedade** . Use `MyProp` para este exemplo.

1. Selecione um tipo de dados na caixa de listagem suspensa **tipo de propriedade** . Use **Short** para este exemplo.

1. Para **tipo de implementação**, clique em **obter/definir métodos**.

1. Marque as seguintes caixas de seleção na guia atributos IDL: **vinculável**, **requestedit**, **displaybind**e **defaultbind** para adicionar os atributos à definição de propriedade no projeto. Arquivo IDL. Esses atributos tornam o controle visível para o usuário e tornam a propriedade Stock a propriedade vinculável padrão.

1. Clique em **Concluir**.

1. Modifique o corpo da `SetMyProp` função para que ela contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#2](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_2.cpp)]

1. O parâmetro passado para as `BoundPropertyChanged` `BoundPropertyRequestEdit` funções e é o DispID da propriedade, que é o parâmetro passado para o atributo ID () da propriedade no. Arquivo IDL.

1. Modifique a função [OnOcmCommand](mfc-activex-controls-subclassing-a-windows-control.md) para que ela contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#1](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

1. Modifique a `OnDraw` função para que ela contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#3](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_3.cpp)]

1. Para a seção pública do arquivo de cabeçalho o arquivo de cabeçalho para sua classe de controle, adicione as seguintes definições (construtores) para variáveis de membro:

   [!code-cpp[NVC_MFC_AxData#4](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_4.h)]

1. Faça a seguinte linha na última linha da `DoPropExchange` função:

   [!code-cpp[NVC_MFC_AxData#5](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_5.cpp)]

1. Modifique a `OnResetState` função para que ela contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#6](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_6.cpp)]

1. Modifique a `GetMyProp` função para que ela contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#7](codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_7.cpp)]

Agora você pode criar o projeto, que registrará o controle. Quando você insere o controle em uma caixa de diálogo, as propriedades de **campo de dados** e **fonte de dados** foram adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
