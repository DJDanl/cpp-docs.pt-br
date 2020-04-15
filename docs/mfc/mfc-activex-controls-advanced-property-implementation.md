---
title: 'Controles ActiveX MFC: implementação da propriedade avançada'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
ms.assetid: ec2e6759-5a8e-41d8-a275-99af8ff6f32e
ms.openlocfilehash: d4f1265e6540e9f84bdb680e7948a4e308d31bb0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364646"
---
# <a name="mfc-activex-controls-advanced-property-implementation"></a>Controles ActiveX MFC: implementação da propriedade avançada

Este artigo descreve tópicos relacionados à implementação de propriedades avançadas em um controle ActiveX.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

- [Propriedades somente leitura e somente gravação](#_core_read2donly_and_write2donly_properties)

- [Retornando códigos de erro de uma propriedade](#_core_returning_error_codes_from_a_property)

## <a name="read-only-and-write-only-properties"></a><a name="_core_read2donly_and_write2donly_properties"></a>Propriedades somente leitura e somente gravação

O Assistente de propriedade adicionar fornece um método rápido e fácil para implementar propriedades somente leitura ou somente gravação para o controle.

#### <a name="to-implement-a-read-only-or-write-only-property"></a>Para implementar uma propriedade somente leitura ou somente gravação

1. Carregue o projeto do seu controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar propriedade**.

   Isso abre o [Assistente adicionar propriedade](../ide/names-add-property-wizard.md).

1. Na caixa Nome da **propriedade,** digite o nome da sua propriedade.

1. Para **o tipo de implementação,** clique em **Métodos de entrada/conjunto**.

1. Na caixa **Tipo de propriedade,** selecione o tipo apropriado para a propriedade.

1. Se você quiser uma propriedade somente leitura, limpe o nome da função Definir. Se você quiser uma propriedade somente para gravação, limpe o nome da função Obter.

1. Clique em **Concluir**.

Quando você faz isso, o Assistente `SetNotSupported` adicionar `GetNotSupported` propriedade insere a função ou na entrada do mapa de despacho no lugar de uma função normal De conjunto ou obter.

Se você quiser alterar uma propriedade existente para ser somente leitura ou somente gravação, você pode editar o mapa de despacho manualmente e remover a função 'Definir ou Obter' desnecessária da classe de controle.

Se você quiser que uma propriedade seja apenas leitura condicional ou somente gravação (por exemplo, somente quando seu controle estiver operando em `SetNotSupported` um `GetNotSupported` determinado modo), você pode fornecer a função Definir ou Obter, normalmente, e chamar ou funcionar quando apropriado. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#29](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-property-implementation_1.cpp)]

Esta amostra `SetNotSupported` de `m_bReadOnlyMode` código chama se o membro de dados for **TRUE**. Se **FALSE**, então a propriedade é definida para o novo valor.

## <a name="returning-error-codes-from-a-property"></a><a name="_core_returning_error_codes_from_a_property"></a>Retornando códigos de erro de uma propriedade

Para indicar que ocorreu um erro ao tentar obter ou `COleControl::ThrowError` definir uma propriedade, use a função, que toma um SCODE (código de status) como parâmetro. Você pode usar um SCODE predefinido ou definir um dos seus. Para obter uma lista de SCODEs predefinidos e instruções para definir SCODEs personalizados, consulte [Erros de manuseio no seu controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) no artigo Controles ActiveX: Tópicos Avançados.

As funções do ajudante existem para os SCODEs mais comuns predefinidos, tais como [COleControl::SetNotSupported,](../mfc/reference/colecontrol-class.md#setnotsupported) [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported)e [COleControl::SetNotAllowed](../mfc/reference/colecontrol-class.md#setnotpermitted).

> [!NOTE]
> `ThrowError`destina-se a ser usado apenas como um meio de retornar um erro de dentro da função Get ou Set de uma propriedade ou de um método de automação. Estas são as únicas vezes em que o manipulador de exceção apropriado estará presente na pilha.

Para obter mais informações sobre exceções de relatórios em outras áreas do código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [Erros de manuseio no seu controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) no artigo ActiveX Controls: Advanced Topics.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
