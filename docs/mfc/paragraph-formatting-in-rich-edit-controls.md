---
title: Formatação de parágrafo em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- rich edit controls [MFC], paragraph formatting in
- paragraph formatting in CRichEditCtrl [MFC]
- CRichEditCtrl class [MFC], paragraph formatting in
- formatting [MFC], paragraphs
ms.assetid: 0df2e4c9-2074-4e41-b913-87cb8c1b4d43
ms.openlocfilehash: 0988e7940c8d8947b86e97a35d71586f8f5c316a
ms.sourcegitcommit: 46d24d6e70c03e05484923d9efc6ed5150e96a64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2019
ms.locfileid: "68916368"
---
# <a name="paragraph-formatting-in-rich-edit-controls"></a>Formatação de parágrafo em controles de edição avançada

Você pode usar funções de membro do[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)(controle de edição rico) para formatar parágrafos e recuperar informações de formatação. Os atributos de formatação de parágrafo incluem alinhamento, tabulações, recuos e numeração.

Você pode aplicar a formatação de parágrafo usando a função de membro [SetParaFormat](../mfc/reference/cricheditctrl-class.md#setparaformat) . Para determinar a formatação de parágrafo atual para o texto selecionado, use a função de membro [GetParaFormat](../mfc/reference/cricheditctrl-class.md#getparaformat) . A estrutura [paraformativa](/windows/desktop/api/richedit/ns-richedit-paraformat) é usada com essas funções de membro para especificar atributos de parágrafo. Um dos membros importantes de PARAFORMAT é *dwMask*. No `SetParaFormat`, *dwMask* especifica quais atributos de parágrafo serão definidos por essa chamada de função. `GetParaFormat`relata os atributos do primeiro parágrafo na seleção; *dwMask* especifica os atributos que são consistentes durante a seleção.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
