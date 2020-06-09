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
ms.openlocfilehash: 1f7564d750b476ac3f57656f3392e0801652e5d5
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615512"
---
# <a name="mfc-activex-controls-returning-error-codes-from-a-method"></a>Controles ActiveX MFC: retornando códigos de erro a partir de um método

Este artigo descreve como retornar códigos de erro de um método de controle ActiveX.

Para indicar que ocorreu um erro dentro de um método, você deve usar a função de membro [COleControl:: ThrowError](reference/colecontrol-class.md#throwerror) , que usa um SCODE (código de status) como um parâmetro. Você pode usar um SCODE predefinido ou definir um de seus próprios.

> [!NOTE]
> `ThrowError`destina-se a ser usado apenas como um meio de retornar um erro de dentro de uma função Get ou set de uma propriedade ou um método de automação. Essas são as únicas vezes que o manipulador de exceção apropriado estará presente na pilha.

Existem funções auxiliares para os SCODEs predefinidos mais comuns, como [COleControl:: SetNotSupported](reference/colecontrol-class.md#setnotsupported), [COleControl:: GetNotSupported](reference/colecontrol-class.md#getnotsupported)e [COleControl:: SetNotPermitted](reference/colecontrol-class.md#setnotpermitted).

Para obter uma lista de SCODEs predefinidas e instruções sobre como definir SCODEs personalizados, consulte a seção [Manipulando erros no controle ActiveX](mfc-activex-controls-advanced-topics.md) em controles ActiveX: Tópicos avançados.

Para obter mais informações sobre como relatar exceções em outras áreas do seu código, consulte [COleControl:: FireError](reference/colecontrol-class.md#fireerror) e a seção [Manipulando erros no controle ActiveX](mfc-activex-controls-advanced-topics.md) em controles ActiveX: Tópicos avançados.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
