---
title: 'Controles ActiveX MFC: adicionando propriedades personalizadas'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], properties
- properties [MFC], custom
ms.assetid: 85af5167-74c7-427b-b8f3-e0d7b73942e5
ms.openlocfilehash: 805fffcc6cafe92df91af6b01bb53240a0d70f51
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230487"
---
# <a name="mfc-activex-controls-adding-custom-properties"></a>Controles ActiveX MFC: adicionando propriedades personalizadas

As propriedades personalizadas diferem das propriedades de estoque nas propriedades personalizadas que ainda não foram implementadas pela `COleControl` classe. Uma propriedade personalizada é usada para expor um determinado Estado ou aparência de um controle ActiveX para um programador usando o controle.

Este artigo descreve como adicionar uma propriedade personalizada ao controle ActiveX usando o assistente para adicionar propriedade e explica as modificações de código resultantes. Os tópicos incluem:

- [Usando o assistente para adicionar propriedade para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property)

- [Adicionar alterações do assistente de propriedade para propriedades personalizadas](#_core_classwizard_changes_for_custom_properties)

As propriedades personalizadas são fornecidas em quatro variedades de implementação: variável de membro, variável de membro com a notificação, métodos get/set e parametrizado.

- Implementação de variável de membro

   Essa implementação representa o estado da propriedade como uma variável de membro na classe de controle. Use a implementação da variável de membro quando não for importante saber quando o valor da propriedade é alterado. Dos três tipos, essa implementação cria a menor quantidade de código de suporte para a propriedade. A macro de entrada do mapa de expedição para implementação da variável de membro é [DISP_PROPERTY](reference/dispatch-maps.md#disp_property).

- Variável de membro com implementação de notificação

   Essa implementação consiste em uma variável de membro e uma função de notificação criada pelo Assistente para adicionar propriedade. A função de notificação é chamada automaticamente pelo Framework depois que o valor da propriedade é alterado. Use a variável de membro com a implementação de notificação quando precisar ser notificado depois que um valor de propriedade for alterado. Essa implementação requer mais tempo porque requer uma chamada de função. A macro de entrada do mapa de expedição para esta implementação é [DISP_PROPERTY_NOTIFY](reference/dispatch-maps.md#disp_property_notify).

- Implementação de métodos get/set

   Essa implementação consiste em um par de funções de membro na classe Control. A implementação dos métodos get/set chama automaticamente a função obter membro quando o usuário do controle solicita o valor atual da propriedade e a função de membro set quando o usuário do controle solicita que a propriedade seja alterada. Use essa implementação quando você precisar calcular o valor de uma propriedade durante o tempo de execução, validar um valor passado pelo usuário do controle antes de alterar a propriedade real ou implementar um tipo de propriedade somente leitura ou somente gravação. A macro de entrada do mapa de expedição para esta implementação é [DISP_PROPERTY_EX](reference/dispatch-maps.md#disp_property_ex). A seção a seguir, [usando o assistente para adicionar propriedade para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property), usa a propriedade personalizada CircleOffset para demonstrar essa implementação.

- Implementação com parâmetros

   A implementação com parâmetros tem suporte pelo Assistente para adicionar propriedade. Uma propriedade parametrizada (às vezes chamada de matriz de propriedade) pode ser usada para acessar um conjunto de valores por meio de uma única propriedade do seu controle. A macro de entrada do mapa de expedição para esta implementação é DISP_PROPERTY_PARAM. Para obter mais informações sobre como implementar esse tipo, consulte [implementando uma propriedade parametrizada](mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: Tópicos avançados.

## <a name="using-the-add-property-wizard-to-add-a-custom-property"></a><a name="_core_using_classwizard_to_add_a_custom_property"></a>Usando o assistente para adicionar propriedade para adicionar uma propriedade personalizada

O procedimento a seguir demonstra como adicionar uma propriedade personalizada, CircleOffset, que usa a implementação de métodos get/set. A propriedade personalizada CircleOffset permite que o usuário do controle desloque o círculo do centro do retângulo delimitador do controle. O procedimento para adicionar propriedades personalizadas com uma implementação diferente de métodos get/set é muito semelhante.

Esse mesmo procedimento também pode ser usado para adicionar outras propriedades personalizadas que você desejar. Substitua o nome da propriedade personalizada pelo nome e parâmetros da propriedade CircleOffset.

#### <a name="to-add-the-circleoffset-custom-property-using-the-add-property-wizard"></a>Para adicionar a propriedade personalizada CircleOffset usando o assistente para adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o [Assistente para adicionar Propriedade](../ide/names-add-property-wizard.md).

1. Na caixa **nome da propriedade** , digite *CircleOffset*.

1. Para **tipo de implementação**, clique em **obter/definir métodos**.

1. Na caixa **tipo de propriedade** , selecione **`short`** .

1. Digite nomes exclusivos para suas funções Get e Set ou aceite os nomes padrão.

1. Clique em **Concluir**.

## <a name="add-property-wizard-changes-for-custom-properties"></a><a name="_core_classwizard_changes_for_custom_properties"></a>Adicionar alterações do assistente de propriedade para propriedades personalizadas

Quando você adiciona a propriedade personalizada CircleOffset, o assistente para adicionar propriedade faz alterações no cabeçalho (. H) e a implementação (. CPP) dos arquivos da classe Control.

As linhas a seguir são adicionadas ao. Arquivo H para declarar duas funções chamadas `GetCircleOffset` e `SetCircleOffset` :

[!code-cpp[NVC_MFC_AxUI#25](codesnippet/cpp/mfc-activex-controls-adding-custom-properties_1.h)]

A linha a seguir é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#26](codesnippet/cpp/mfc-activex-controls-adding-custom-properties_2.idl)]

Essa linha atribui a propriedade CircleOffset um número de ID específico, obtido da posição do método na lista de métodos e propriedades do assistente para adicionar propriedade.

Além disso, a linha a seguir é adicionada ao mapa de expedição (no. Arquivo CPP da classe Control) para mapear a propriedade CircleOffset para as duas funções de manipulador do controle:

[!code-cpp[NVC_MFC_AxUI#27](codesnippet/cpp/mfc-activex-controls-adding-custom-properties_3.cpp)]

Por fim, as implementações `GetCircleOffset` das `SetCircleOffset` funções e são adicionadas ao final do controle. Arquivo CPP. Na maioria dos casos, você modificará a função Get para retornar o valor da propriedade. A função Set normalmente conterá o código que deve ser executado antes ou depois da alteração da propriedade.

[!code-cpp[NVC_MFC_AxUI#28](codesnippet/cpp/mfc-activex-controls-adding-custom-properties_4.cpp)]

Observe que o assistente para adicionar propriedade adiciona automaticamente uma chamada, para [SetModifiedFlag](reference/colecontrol-class.md#setmodifiedflag), ao corpo da função Set. Chamar essa função marca o controle como modificado. Se um controle tiver sido modificado, seu novo estado será salvo quando o contêiner for salvo. Essa função deve ser chamada sempre que uma propriedade, salva como parte do estado persistente do controle, altera o valor.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: Propriedades](mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
