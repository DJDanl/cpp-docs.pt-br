---
title: 'Controles ActiveX MFC: adicionando propriedades personalizadas'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], properties
- properties [MFC], custom
ms.assetid: 85af5167-74c7-427b-b8f3-e0d7b73942e5
ms.openlocfilehash: 00f7a879582bca562ce626fe224206094fd19bc7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364695"
---
# <a name="mfc-activex-controls-adding-custom-properties"></a>Controles ActiveX MFC: adicionando propriedades personalizadas

As propriedades personalizadas diferem das propriedades de estoque, na medida em que as propriedades personalizadas ainda não são implementadas pela `COleControl` classe. Uma propriedade personalizada é usada para expor um certo estado ou aparência de um controle ActiveX a um programador usando o controle.

Este artigo descreve como adicionar uma propriedade personalizada ao controle ActiveX usando o Assistente de Adicionar Propriedade e explica as modificações de código resultantes. Os tópicos incluem:

- [Usando o Assistente de adicionar propriedade para adicionar uma propriedade personalizada](#_core_using_classwizard_to_add_a_custom_property)

- [Adicionar alterações do Assistente de Propriedade para propriedades personalizadas](#_core_classwizard_changes_for_custom_properties)

As propriedades personalizadas vêm em quatro variedades de implementação: Variável de membro, Variável de Membro com Notificação, Métodos get/set e parametrizadas.

- Implementação variável de membro

   Esta implementação representa o estado da propriedade como uma variável membro na classe de controle. Use a implementação da Variável de Membro quando não for importante saber quando o valor da propriedade muda. Dos três tipos, essa implementação cria a menor quantidade de código de suporte para a propriedade. A macro de entrada do mapa de despacho para implementação de variáveis de membro é [DISP_PROPERTY](../mfc/reference/dispatch-maps.md#disp_property).

- Variável de membro com implementação de notificação

   Essa implementação consiste em uma variável de membro e uma função de notificação criada pelo Assistente de Adicionar propriedade. A função de notificação é automaticamente chamada pelo framework após a alteração do valor do imóvel. Use a variável membro com implementação de notificação quando precisar ser notificada após a alteração de um valor de propriedade. Esta implementação requer mais tempo porque requer uma chamada de função. A macro de entrada do mapa de despacho para esta implementação é [DISP_PROPERTY_NOTIFY](../mfc/reference/dispatch-maps.md#disp_property_notify).

- Implementação de métodos get/set

   Esta implementação consiste em um par de funções de membro na classe de controle. A implementação Métodos Get/Set chama automaticamente a função Obter membro quando o usuário do controle solicita o valor atual da propriedade e a função Definir membro quando o usuário do controle solicita que a propriedade seja alterada. Use essa implementação quando precisar calcular o valor de um imóvel durante o tempo de execução, validar um valor passado pelo usuário do controle antes de alterar a propriedade real ou implementar um tipo de propriedade somente leitura ou gravação. A macro de entrada do mapa de despacho para esta implementação é [DISP_PROPERTY_EX](../mfc/reference/dispatch-maps.md#disp_property_ex). A seção a seguir, [Usando o Assistente adicionar propriedade para adicionar uma propriedade personalizada,](#_core_using_classwizard_to_add_a_custom_property)usa a propriedade personalizada CircleOffset para demonstrar essa implementação.

- Implementação parametrizada

   A implementação parametrizada é suportada pelo Assistente de Adicionar Propriedades. Uma propriedade parametrizada (às vezes chamada de matriz de propriedades) pode ser usada para acessar um conjunto de valores através de uma única propriedade do seu controle. A macro de entrada do mapa de despacho para esta implementação é DISP_PROPERTY_PARAM. Para obter mais informações sobre a implementação desse tipo, consulte [Implementando uma Propriedade Parametrizada](../mfc/mfc-activex-controls-advanced-topics.md) no artigo ActiveX Controls: Advanced Topics.

## <a name="using-the-add-property-wizard-to-add-a-custom-property"></a><a name="_core_using_classwizard_to_add_a_custom_property"></a>Usando o assistente de adicionar propriedade para adicionar uma propriedade personalizada

O procedimento a seguir demonstra a adição de uma propriedade personalizada, circleoffset, que usa a implementação Métodos Get/Set. A propriedade personalizada CircleOffset permite que o usuário do controle compense o círculo a partir do centro do retângulo delimitador do controle. O procedimento para adicionar propriedades personalizadas com uma implementação diferente dos Métodos Get/Set é muito semelhante.

Este mesmo procedimento também pode ser usado para adicionar outras propriedades personalizadas desejadas. Substitua o nome da propriedade personalizada pelo nome e parâmetros da propriedade CircleOffset.

#### <a name="to-add-the-circleoffset-custom-property-using-the-add-property-wizard"></a>Para adicionar a propriedade personalizada CircleOffset usando o Assistente adicionar propriedade

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o [Assistente adicionar propriedade](../ide/names-add-property-wizard.md).

1. Na **caixa Nome** da propriedade, *digite CircleOffset*.

1. Para **o tipo de implementação,** clique em **Métodos de entrada/conjunto**.

1. Na caixa **Tipo de propriedade,** selecione **curto**.

1. Digite nomes exclusivos para suas funções Get and Set ou aceite os nomes padrão.

1. Clique em **Concluir**.

## <a name="add-property-wizard-changes-for-custom-properties"></a><a name="_core_classwizard_changes_for_custom_properties"></a>Adicionar alterações do assistente de propriedade para propriedades personalizadas

Quando você adiciona a propriedade personalizada CircleOffset, o Assistente adicionar propriedades faz alterações no cabeçalho (. H) e a implementação (. CPP) arquivos da classe de controle.

As seguintes linhas são adicionadas ao . Arquivo H para declarar `GetCircleOffset` duas `SetCircleOffset`funções chamadas e:

[!code-cpp[NVC_MFC_AxUI#25](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_1.h)]

A linha a seguir é adicionada ao seu controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#26](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_2.idl)]

Esta linha atribui à propriedade CircleOffset um número de ID específico, retirado da posição do método na lista de métodos e propriedades do Assistente de Propriedade adicionar.

Além disso, a linha a seguir é adicionada ao mapa de despacho (no . Arquivo CPP da classe de controle) para mapear a propriedade CircleOffset para as duas funções do manipulador do controle:

[!code-cpp[NVC_MFC_AxUI#27](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_3.cpp)]

Finalmente, as implementações `GetCircleOffset` `SetCircleOffset` e funções são adicionadas ao fim do controle. Arquivo CPP. Na maioria dos casos, você modificará a função Get para devolver o valor da propriedade. A função Definir geralmente conterá código que deve ser executado antes ou depois das alterações de propriedade.

[!code-cpp[NVC_MFC_AxUI#28](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-properties_4.cpp)]

Observe que o Assistente adicionar propriedades adiciona automaticamente uma chamada ao [SetModifiedFlag](../mfc/reference/colecontrol-class.md#setmodifiedflag), ao corpo da função Definir. Chamar esta função marca o controle como modificado. Se um controle tiver sido modificado, seu novo estado será salvo quando o contêiner for salvo. Essa função deve ser chamada sempre que uma propriedade, salva como parte do estado persistente do controle, mudar de valor.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
