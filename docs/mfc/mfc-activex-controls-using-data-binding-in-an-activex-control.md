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
ms.openlocfilehash: 41ac0180242aea3143a1df2c32dc81fb18cd7dca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370788"
---
# <a name="mfc-activex-controls-using-data-binding-in-an-activex-control"></a>Controles ActiveX MFC: usando associação de dados em um controle ActiveX

Um dos usos mais poderosos dos controles ActiveX é a vinculação de dados, que permite que uma propriedade do controle se vincule a um campo específico em um banco de dados. Quando um usuário modifica dados nesta propriedade vinculada, o controle notifica o banco de dados e solicita que o campo de registro seja atualizado. O banco de dados então notifica o controle do sucesso ou falha da solicitação.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Este artigo abrange o lado de controle de sua tarefa. A implementação das interações de vinculação de dados com o banco de dados é responsabilidade do contêiner de controle. A forma como você gerencia as interações de banco de dados em seu contêiner está além do escopo desta documentação. Como você prepara o controle para vinculação de dados é explicado no resto deste artigo.

![Diagrama conceitual de um controle vinculado de dados&#45;](../mfc/media/vc374v1.gif "Diagrama conceitual de um controle vinculado de dados&#45;") <br/>
Diagrama conceitual de um controle de data-bound

A `COleControl` classe fornece duas funções de membros que tornam a vinculação de dados um processo fácil de implementar. A primeira função, [BoundPropertyRequestEdit,](../mfc/reference/colecontrol-class.md#boundpropertyrequestedit)é usada para solicitar permissão para alterar o valor da propriedade. [BoundPropertyChanged](../mfc/reference/colecontrol-class.md#boundpropertychanged), a segunda função, é chamada depois que o valor da propriedade foi alterado com sucesso.

Este artigo aborda os seguintes tópicos:

- [Criando uma propriedade de ações vinculáveis](#vchowcreatingbindablestockproperty)

- [Criando um método de get/set vinculável](#vchowcreatingbindablegetsetmethod)

## <a name="creating-a-bindable-stock-property"></a><a name="vchowcreatingbindablestockproperty"></a>Criando uma propriedade de ações vinculáveis

É possível criar uma propriedade de ações vinculada a dados, embora seja mais provável que você queira um [método de get/set vinculável](#vchowcreatingbindablegetsetmethod).

> [!NOTE]
> As propriedades `bindable` de `requestedit` estoque têm os atributos e atributos por padrão.

#### <a name="to-add-a-bindable-stock-property-using-the-add-property-wizard"></a>Para adicionar uma propriedade de estoque vinculável usando o Assistente de Adicionar Propriedade

1. Inicie um projeto usando o [MFC ActiveX Control Wizard](../mfc/reference/mfc-activex-control-wizard.md).

1. Clique com o botão direito do mouse no nó de interface para o seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

1. Selecione uma das entradas da lista de isto Nome da **propriedade.** Por exemplo, você pode selecionar **Texto**.

   Como **o Texto** é uma propriedade de estoque, os atributos **bindable** e **requestedit** já estão verificados.

1. Selecione as seguintes caixas de seleção na guia **Atributos IDL:** **displaybind** e **defaultbind** para adicionar os atributos à definição de propriedade na . Arquivo IDL. Esses atributos tornam o controle visível para o usuário e tornam a propriedade de estoque a propriedade padrão vinculável.

Neste ponto, seu controle pode exibir dados de uma fonte de dados, mas o usuário não será capaz de atualizar campos de dados. Se você quiser que seu controle também seja `OnOcmCommand` capaz de atualizar dados, altere a função [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) para parecer o seguinte:

[!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

Agora você pode construir o projeto, que registrará o controle. Quando você inserir o controle em uma caixa de diálogo, as propriedades **Campo de dados** e fonte de **dados** terão sido adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.

## <a name="creating-a-bindable-getset-method"></a><a name="vchowcreatingbindablegetsetmethod"></a>Criando um método de get/set vinculável

Além de um método de get/set vinculado a dados, você também pode criar uma [propriedade de estoque vinculável](#vchowcreatingbindablestockproperty).

> [!NOTE]
> Este procedimento pressupõe que você tenha um projeto de controle ActiveX que subclasses um controle do Windows.

#### <a name="to-add-a-bindable-getset-method-using-the-add-property-wizard"></a>Para adicionar um método de get/set vinculável usando o Assistente de Adicionar propriedades

1. Carregue o projeto do seu controle.

1. Na página **Configurações de controle,** selecione uma classe de janela para o controle para subclasse. Por exemplo, você pode querer subclassificar um controle EDIT.

1. Carregue o projeto do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle.

   Isso abre o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

1. Digite o nome da propriedade na caixa **Nome da propriedade.** Use `MyProp` para este exemplo.

1. Selecione um tipo de dados **na** caixa de lista de lista sestá-la tipo de propriedade. Use **abreviação** para este exemplo.

1. Para **o tipo de implementação,** clique em **Métodos de entrada/conjunto**.

1. Selecione as seguintes caixas de seleção na guia Atributos IDL: **bindable**, **requestedit,** **displaybind**e **defaultbind** para adicionar os atributos à definição de propriedade na . Arquivo IDL. Esses atributos tornam o controle visível para o usuário e tornam a propriedade de estoque a propriedade padrão vinculável.

1. Clique em **Concluir**.

1. Modifique o `SetMyProp` corpo da função de modo que contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#2](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_2.cpp)]

1. O parâmetro passado `BoundPropertyChanged` para `BoundPropertyRequestEdit` as funções e funções é o despid da propriedade, que é o parâmetro passado para o atributo id() para o imóvel no . Arquivo IDL.

1. Modifique a função [OnOcmCommand](../mfc/mfc-activex-controls-subclassing-a-windows-control.md) para que contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#1](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_1.cpp)]

1. Modifique `OnDraw` a função de modo que contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#3](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_3.cpp)]

1. Na seção pública do arquivo cabeçalho, o arquivo cabeçalho para sua classe de controle, adicione as seguintes definições (construtores) para variáveis de membro:

   [!code-cpp[NVC_MFC_AxData#4](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_4.h)]

1. Faça da linha a seguir `DoPropExchange` a última linha na função:

   [!code-cpp[NVC_MFC_AxData#5](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_5.cpp)]

1. Modifique `OnResetState` a função de modo que contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#6](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_6.cpp)]

1. Modifique `GetMyProp` a função de modo que contenha o seguinte código:

   [!code-cpp[NVC_MFC_AxData#7](../mfc/codesnippet/cpp/mfc-activex-controls-using-data-binding-in-an-activex-control_7.cpp)]

Agora você pode construir o projeto, que registrará o controle. Quando você inserir o controle em uma caixa de diálogo, as propriedades **Campo de dados** e fonte de **dados** terão sido adicionadas e agora você pode selecionar uma fonte de dados e um campo para exibir no controle.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
