---
title: 'Controles ActiveX MFC: Avançado implementação da propriedade | Microsoft Docs'
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- properties [MFC], ActiveX controls
- MFC ActiveX controls [MFC], properties
ms.assetid: ec2e6759-5a8e-41d8-a275-99af8ff6f32e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4aa1116384ac9fd5212046f9a0b3354a3aa70d88
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46416078"
---
# <a name="mfc-activex-controls-advanced-property-implementation"></a>Controles ActiveX MFC: implementação da propriedade avançada

Este artigo descreve os tópicos relacionados à implementação de propriedades em um controle ActiveX avançadas.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem as ActiveX, consulte [controles ActiveX](activex-controls.md).

- [Propriedades somente leitura e somente gravação](#_core_read2donly_and_write2donly_properties)

- [Retornando códigos de erro de uma propriedade](#_core_returning_error_codes_from_a_property)

##  <a name="_core_read2donly_and_write2donly_properties"></a> Propriedades somente leitura e somente gravação

O Assistente para adicionar propriedade fornece um método rápido e fácil para implementar propriedades somente leitura ou somente gravação para o controle.

#### <a name="to-implement-a-read-only-or-write-only-property"></a>Implementar uma propriedade somente leitura ou somente gravação

1. Carregar o projeto do seu controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **adicionar propriedade**.

     Isso abre o [Assistente para adicionar de propriedade](../ide/names-add-property-wizard.md).

1. No **nome da propriedade** , digite o nome de sua propriedade.

1. Para **tipo de implementação**, clique em **métodos Get/Set**.

1. No **tipo de propriedade** , selecione o tipo apropriado para a propriedade.

1. Se você quiser uma propriedade somente leitura, desmarque o nome da função de conjunto. Se você quiser que uma propriedade somente gravação, desmarque o nome da função Get.

9. Clique em **Finalizar**.

Quando você fizer isso, o Assistente para adicionar propriedade insere a função `SetNotSupported` ou `GetNotSupported` na entrada do mapa de expedição no lugar de um normal definem ou obtêm a função.

Se você quiser alterar uma propriedade existente para ser somente leitura ou somente gravação, você pode editar o mapa de expedição manualmente e remova a função Set ou Get desnecessária da classe de controle.

Se você quiser uma propriedade a ser condicionalmente somente leitura ou somente gravação (por exemplo, somente quando o controle está operando em um determinado modo), você pode fornecer a função Set ou Get, como de costume e chamar o `SetNotSupported` ou `GetNotSupported` funcionar quando apropriado. Por exemplo:

[!code-cpp[NVC_MFC_AxUI#29](../mfc/codesnippet/cpp/mfc-activex-controls-advanced-property-implementation_1.cpp)]

Este exemplo de código chama `SetNotSupported` se o `m_bReadOnlyMode` é membro de dados **verdadeiro**. Se **falsos**, em seguida, a propriedade é definida para o novo valor.

##  <a name="_core_returning_error_codes_from_a_property"></a> Retornando códigos de erro de uma propriedade

Para indicar que ocorreu um erro durante a tentativa de obter ou definir uma propriedade, use o `COleControl::ThrowError` função, que leva um SCODE (código de status) como um parâmetro. Você pode usar um SCODE predefinido ou definir um de seus próprios. Para obter uma lista de predefinidos SCODEs e instruções para definir SCODEs personalizados, consulte [Manipulando erros em seu controle de ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) nos controles do ActiveX do artigo: tópicos avançados.

Funções auxiliares existem para os mais comuns predefinidos SCODEs, tais como [COleControl::SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported), [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported), e [COleControl::SetNotPermitted](../mfc/reference/colecontrol-class.md#setnotpermitted).

> [!NOTE]
>  `ThrowError` deve ser usado apenas como um meio de retornar um erro de dentro Get da propriedade ou Set function ou um método de automação. Essas são as únicas vezes que o manipulador de exceção apropriado será presentes na pilha.

Para obter mais informações sobre o relatório de exceções em outras áreas do código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [Manipulando erros em seu controle de ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) no artigo controles ActiveX: avançado Tópicos.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Controles ActiveX do MFC: propriedades](../mfc/mfc-activex-controls-properties.md)<br/>
[Controles ActiveX do MFC: métodos](../mfc/mfc-activex-controls-methods.md)<br/>
[Classe COleControl](../mfc/reference/colecontrol-class.md)
