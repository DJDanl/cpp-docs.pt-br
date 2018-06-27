---
title: 'Controles ActiveX MFC: Retornando códigos de erro de um método | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], error codes
- SetNotSupported method, using
- errors [MFC], ActiveX control error codes
- GetNotSupported method [MFC]
- FireError method [MFC]
- SCODE, MFC ActiveX controls
- ThrowError method [MFC]
ms.assetid: 771fb9c9-2413-4dcc-b386-7bc4c4adeafd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bdcd18a80b430a0a8576effaaa46215dd5eb9600
ms.sourcegitcommit: 060f381fe0807107ec26c18b46d3fcb859d8d2e7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/25/2018
ms.locfileid: "36927913"
---
# <a name="mfc-activex-controls-returning-error-codes-from-a-method"></a>Controles ActiveX MFC: retornando códigos de erro a partir de um método
Este artigo descreve como retornar códigos de erro de um método de controle ActiveX.  
  
 Para indicar que ocorreu um erro dentro de um método, você deve usar o [COleControl::ThrowError](../mfc/reference/colecontrol-class.md#throwerror) função de membro, o que leva um SCODE (código de status) como um parâmetro. Você pode usar um SCODE predefinido ou definir seu próprio.  
  
> [!NOTE]
>  `ThrowError` deve ser usado apenas como um meio de retornar um erro de dentro Get da propriedade ou Set função ou um método de automação. Esses são os únicos vezes que o manipulador de exceção apropriada será presentes na pilha.  
  
 Funções auxiliares existem para o mais comum predefinidas SCODEs, como [COleControl::SetNotSupported](../mfc/reference/colecontrol-class.md#setnotsupported), [COleControl::GetNotSupported](../mfc/reference/colecontrol-class.md#getnotsupported), e [COleControl::SetNotPermitted](../mfc/reference/colecontrol-class.md#setnotpermitted).  
  
 Para obter uma lista de predefinidos SCODEs e instruções sobre como definir SCODEs personalizados, consulte a seção [tratamento de erros no controle ActiveX do seu](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: tópicos avançados.  
  
 Para obter mais informações sobre relatórios de exceções em outras áreas do seu código, consulte [COleControl::FireError](../mfc/reference/colecontrol-class.md#fireerror) e a seção [tratamento de erros no controle ActiveX do seu](../mfc/mfc-activex-controls-advanced-topics.md) em controles ActiveX: tópicos avançados.  
  
## <a name="see-also"></a>Consulte também  
 [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

