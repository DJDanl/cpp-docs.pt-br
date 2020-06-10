---
title: 'Controles ActiveX MFC: implementação da propriedade avançada'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
ms.assetid: ec2e6759-5a8e-41d8-a275-99af8ff6f32e
ms.openlocfilehash: f5abef4db2f9c6d375428c0b0fd313198ce6283f
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621224"
---
# <a name="mfc-activex-controls-advanced-property-implementation"></a>Controles ActiveX MFC: implementação da propriedade avançada

Este artigo descreve os tópicos relacionados à implementação de propriedades avançadas em um controle ActiveX.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

- [Propriedades somente leitura e somente gravação](#_core_read2donly_and_write2donly_properties)

- [Retornando códigos de erro de uma propriedade](#_core_returning_error_codes_from_a_property)

## <a name="read-only-and-write-only-properties"></a><a name="_core_read2donly_and_write2donly_properties"></a>Propriedades somente leitura e somente gravação

O assistente para adicionar propriedade fornece um método rápido e fácil para implementar propriedades somente leitura ou somente gravação para o controle.

#### <a name="to-implement-a-read-only-or-write-only-property"></a>Para implementar uma propriedade somente leitura ou somente gravação

1. Carregue o projeto do seu controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar Propriedade**.

   Isso abre o [Assistente para adicionar Propriedade](../ide/names-add-property-wizard.md).

1. Na caixa **nome da propriedade** , digite o nome da propriedade.

1. Para **tipo de implementação**, clique em **obter/definir métodos**.

1. Na caixa **tipo de propriedade** , selecione o tipo adequado para a propriedade.

1. Se você quiser uma propriedade somente leitura, limpe o definir nome da função. Se você quiser uma propriedade somente gravação, limpe o nome da função Get.

1. Clique em **Concluir**.

Quando você faz isso, o assistente para adicionar propriedade insere a função `SetNotSupported` ou `GetNotSupported` na entrada do mapa de expedição no lugar de um conjunto normal ou uma função Get.

Se você quiser alterar uma propriedade existente para somente leitura ou somente gravação, poderá editar o mapa de expedição manualmente e remover o conjunto desnecessário ou obter a função da classe de controle.

Se você quiser que uma propriedade seja condicionalmente somente leitura ou somente gravação (por exemplo, somente quando o controle estiver operando em um modo específico), você poderá fornecer a função Set ou Get, como normal, e chamar a `SetNotSupported` `GetNotSupported` função or quando for apropriado. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#29](codesnippet/cpp/mfc-activex-controls-advanced-property-implementation_1.cpp)]

Este exemplo de código chama `SetNotSupported` se o `m_bReadOnlyMode` membro de dados é **verdadeiro**. Se for **false**, a propriedade será definida como o novo valor.

## <a name="returning-error-codes-from-a-property"></a><a name="_core_returning_error_codes_from_a_property"></a>Retornando códigos de erro de uma propriedade

Para indicar que ocorreu um erro ao tentar obter ou definir uma propriedade, use a `COleControl::ThrowError` função, que usa um SCODE (código de status) como um parâmetro. Você pode usar um SCODE predefinido ou definir um de seus próprios. Para obter uma lista de SCODEs predefinidas e instruções para definir SCODEs personalizados, consulte [tratamento de erros em seu controle ActiveX](mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: Tópicos avançados.

Existem funções auxiliares para os SCODEs predefinidos mais comuns, como [COleControl:: SetNotSupported](reference/colecontrol-class.md#setnotsupported), [COleControl:: GetNotSupported](reference/colecontrol-class.md#getnotsupported)e [COleControl:: SetNotPermitted](reference/colecontrol-class.md#setnotpermitted).

> [!NOTE]
> `ThrowError`destina-se a ser usado apenas como um meio de retornar um erro de dentro de uma função Get ou set de uma propriedade ou um método de automação. Essas são as únicas vezes que o manipulador de exceção apropriado estará presente na pilha.

Para obter mais informações sobre como relatar exceções em outras áreas do código, consulte [COleControl:: FireError](reference/colecontrol-class.md#fireerror) e a seção [Manipulando erros em seu controle ActiveX](mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: Tópicos avançados.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](mfc-activex-controls-methods.md)<br/>
[Classe COleControl](reference/colecontrol-class.md)
