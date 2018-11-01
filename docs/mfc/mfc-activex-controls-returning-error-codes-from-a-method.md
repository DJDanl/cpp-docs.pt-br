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
ms.openlocfilehash: 8c5fe88cf952337a7d070eae7a5da149a8e905bd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50676480"
---
# <a name="mfc-activex-controls-returning-error-codes-from-a-method"></a>Controles ActiveX MFC: retornando códigos de erro a partir de um método

Este artigo descreve como retornar códigos de erro de um método de controle ActiveX.

Para indicar que ocorreu um erro dentro de um método, você deve usar o [COleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror) função de membro, o que leva um SCODE (código de status) como um parâmetro. Você pode usar um SCODE predefinido ou definir um de seus próprios.

> [!NOTE]
>  `ThrowError` deve ser usado apenas como um meio de retornar um erro de dentro Get da propriedade ou Set function ou um método de automação. Essas são as únicas vezes que o manipulador de exceção apropriado será presentes na pilha.

Funções auxiliares existem para os mais comuns predefinidos SCODEs, tais como [COleControl::SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported), [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported), e [COleControl::SetNotPermitted](../mfc/reference/colecontrol-class.md#setnotpermitted).

Para obter uma lista de predefinidos SCODEs e instruções sobre como definir SCODEs personalizados, consulte a seção [Manipulando erros em seu controle de ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: tópicos avançados.

Para obter mais informações sobre o relatório de exceções em outras áreas do seu código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [Manipulando erros em seu controle de ActiveX](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: tópicos avançados.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

