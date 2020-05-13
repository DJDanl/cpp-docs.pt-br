---
title: 'Controles ActiveX MFC: retornando códigos de erro a partir de um método'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- SetNotSupported method, using
- errors [MFC], ActiveX control error codes
- GetNotSupported method [MFC]
- FireError method [MFC]
- SCODE, MFC ActiveX controls
- ThrowError method [MFC]
ms.assetid: 771fb9c9-2413-4dcc-b386-7bc4c4adeafd
ms.openlocfilehash: 5314545a3a903158362dbfa65c4a9a1b2143e86b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364551"
---
# <a name="mfc-activex-controls-returning-error-codes-from-a-method"></a>Controles ActiveX MFC: retornando códigos de erro a partir de um método

Este artigo descreve como retornar códigos de erro de um método de controle ActiveX.

Para indicar que ocorreu um erro dentro de um método, você deve usar a função [coleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror) member, que toma um SCODE (código de status) como parâmetro. Você pode usar um SCODE predefinido ou definir um dos seus.

> [!NOTE]
> `ThrowError`destina-se a ser usado apenas como um meio de retornar um erro de dentro da função Get ou Set de uma propriedade ou de um método de automação. Estas são as únicas vezes em que o manipulador de exceção apropriado estará presente na pilha.

As funções do ajudante existem para os SCODEs mais comuns predefinidos, tais como [COleControl::SetNotSupported,](../mfc/reference/colecontrol-class.md#setnotsupported) [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported)e [COleControl::SetNotAllowed](../mfc/reference/colecontrol-class.md#setnotpermitted).

Para obter uma lista de SCODEs predefinidos e instruções sobre a definição de SCODEs personalizados, consulte a seção [Erros de manuseio no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em Controles ActiveX: Tópicos Avançados.

Para obter mais informações sobre exceções de relatórios em outras áreas do seu código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [Erros de manuseio no controle ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em Controles ActiveX: Tópicos Avançados.

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
