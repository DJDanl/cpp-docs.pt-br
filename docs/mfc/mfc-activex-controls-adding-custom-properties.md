---
title: 'Controles ActiveX MFC: Adicionando propriedades personalizadas'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], properties
- properties [MFC], custom
ms.assetid: 85af5167-74c7-427b-b8f3-e0d7b73942e5
ms.openlocfilehash: e02d5523b894f89aa93c8d2765a128920afa2353
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57284197"
---
# <a name="mfc-activex-controls-adding-custom-properties"></a>Controles ActiveX MFC: Adicionando propriedades personalizadas

Propriedades personalizadas diferem das propriedades de estoque propriedades personalizadas já não são implementadas pelo `COleControl` classe. Uma propriedade personalizada é usada para expor um determinado estado ou a aparência de um controle ActiveX para um programador usando o controle.

Este artigo descreve como adicionar uma propriedade personalizada para o controle ActiveX usando o Assistente para adicionar propriedade e explica as modificações de código resultante. Os tópicos incluem:

- [Usando o Assistente para adicionar propriedade para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property)

- [Adicione as alterações do Assistente de propriedade para propriedades personalizadas](#_core_classwizard_changes_for_custom_properties)

Propriedades personalizadas têm quatro variedades de implementação: Variável de membro, a variável de membro com a notificação de métodos Get/Set e com parâmetros.

- Implementação da variável de membro

   Essa implementação representa o estado da propriedade como uma variável de membro na classe de controle. Use a implementação de variável de membro quando não é importante saber quando o valor da propriedade muda. Dos três tipos, essa implementação cria a menor quantidade de código de suporte para a propriedade. É a macro de entrada de mapa de expedição para implementação da variável de membro [DISP_PROPERTY](../mfc/reference/dispatch-maps.md#disp_property).

- Variável de membro com a implementação de notificações

   Essa implementação consiste em uma variável de membro e uma função de notificação criado pelo Assistente de adição de propriedade. A função de notificação é chamada automaticamente pela estrutura após as alterações de valor de propriedade. Use a variável de membro com a implementação de notificações quando você precisar ser notificado depois que um valor da propriedade foi alterada. Essa implementação requer mais tempo porque ele requer uma chamada de função. A macro de entrada de mapa de expedição para esta implementação é [DISP_PROPERTY_NOTIFY](../mfc/reference/dispatch-maps.md#disp_property_notify).

- Implementação de métodos de Get/Set

   Essa implementação consiste em um par de funções de membro na classe de controle. A implementação de métodos Get/Set chama automaticamente o membro de obtenção funcionam quando o usuário do controle solicita o valor atual da propriedade e a função de membro do conjunto quando o usuário do controle solicita que a propriedade ser alterada. Use essa implementação, quando você precisa para calcular o valor de uma propriedade durante o tempo de execução, validar um valor passado pelo usuário do controle antes de alterar a propriedade real ou implementar um tipo de propriedade ou gravação somente leitura. A macro de entrada de mapa de expedição para esta implementação é [DISP_PROPERTY_EX](../mfc/reference/dispatch-maps.md#disp_property_ex). A seção a seguir, [usando o Assistente para adicionar propriedade para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property), usa a propriedade personalizada de CircleOffset para demonstrar essa implementação.

- Implementação com parâmetros

   Implementação com parâmetros é compatível com o Assistente para adicionar propriedade. Uma propriedade com parâmetros (às vezes chamada de uma matriz de propriedade) pode ser usada para acessar um conjunto de valores por meio de uma única propriedade de seu controle. A macro de entrada de mapa de expedição para esta implementação é DISP_PROPERTY_PARAM. Para obter mais informações sobre como implementar esse tipo, consulte [implementar uma propriedade com parâmetros](../mfc/mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: Tópicos avançados.

##  <a name="_core_using_classwizard_to_add_a_custom_property"></a> Usando o Assistente para adicionar propriedade para adicionar uma propriedade personalizada

O procedimento a seguir demonstra como adicionar uma propriedade personalizada, CircleOffset, que usa a implementação de métodos Get/Set. A propriedade personalizada de CircleOffset permite que o usuário do controle deslocar o círculo do centro do retângulo delimitador do controle. O procedimento para adicionar propriedades personalizadas com uma implementação diferente de métodos Get/Set é muito semelhante.

Esse mesmo procedimento também pode ser usado para adicionar outras propriedades personalizadas que você deseja. Substitua o seu nome de propriedade personalizada para o nome da propriedade CircleOffset e parâmetros.

#### <a name="to-add-the-circleoffset-custom-property-using-the-add-property-wizard"></a>Para adicionar a propriedade personalizada de CircleOffset usando o Assistente para adicionar propriedade

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

   Isso abre o [Assistente para adicionar de propriedade](../ide/names-add-property-wizard.md).

1. No **nome da propriedade** , digite *CircleOffset*.

1. Para **tipo de implementação**, clique em **métodos Get/Set**.

1. No **tipo de propriedade** caixa, selecione **curto**.

1. Digite nomes exclusivos para seu Get e definir funções, ou aceite os nomes padrão.

9. Clique em **Finalizar**.

##  <a name="_core_classwizard_changes_for_custom_properties"></a> Adicione as alterações do Assistente de propriedade para propriedades personalizadas

Quando você adiciona a propriedade personalizada de CircleOffset, o Assistente para adicionar propriedade faz alterações para o cabeçalho (. H) e a implementação (. Arquivos CPP) da classe do controle.

As seguintes linhas são adicionadas para o. Arquivo de H para declarar duas funções chamadas `GetCircleOffset` e `SetCircleOffset`:

[!code-cpp[NVC_MFC_AxUI#25](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_1.h)]

A seguinte linha é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#26](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_2.idl)]

Essa linha atribui a propriedade CircleOffset um número específico de ID, obtido da posição do método, na lista de métodos e propriedades do Assistente para adicionar propriedade.

Além disso, a seguinte linha é adicionada ao mapa de expedição (na. O arquivo CPP da classe de controle) para mapear a propriedade CircleOffset para duas funções de manipulador do controle:

[!code-cpp[NVC_MFC_AxUI#27](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_3.cpp)]

Por fim, as implementações do `GetCircleOffset` e `SetCircleOffset` funções são adicionadas ao final do controle. Arquivo CPP. Na maioria dos casos, você modificará a função Get para retornar o valor da propriedade. A função de conjunto geralmente conterá o código que deve ser executado antes ou após as alterações de propriedade.

[!code-cpp[NVC_MFC_AxUI#28](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_4.cpp)]

Observe que o Assistente para adicionar propriedade adiciona automaticamente uma chamada para [SetModifiedFlag](../mfc/reference/colecontrol-class.md#setmodifiedflag), para o corpo da função de conjunto. Chamar essa função marca o controle como modificado. Se um controle tiver sido modificado, seu novo estado será salvo quando o contêiner é salvo. Essa função deve ser chamada sempre que uma propriedade, salva como parte do estado de persistente do controle, altera o valor.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX MFC: Propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX MFC: Métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
