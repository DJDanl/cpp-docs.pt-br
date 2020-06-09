---
title: Formatação de parágrafo em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- rich edit controls [MFC], paragraph formatting in
- paragraph formatting in CRichEditCtrl [MFC]
- CRichEditCtrl class [MFC], paragraph formatting in
- formatting [MFC], paragraphs
ms.assetid: 0df2e4c9-2074-4e41-b913-87cb8c1b4d43
ms.openlocfilehash: e23976e64b3c9a4a76e5b05c90d0ad033b62657a
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615329"
---
# <a name="paragraph-formatting-in-rich-edit-controls"></a>Formatação de parágrafo em controles de edição avançada

Você pode usar funções de membro do[CRichEditCtrl](reference/cricheditctrl-class.md)(controle de edição rico) para formatar parágrafos e recuperar informações de formatação. Os atributos de formatação de parágrafo incluem alinhamento, tabulações, recuos e numeração.

Você pode aplicar a formatação de parágrafo usando a função de membro [SetParaFormat](reference/cricheditctrl-class.md#setparaformat) . Para determinar a formatação de parágrafo atual para o texto selecionado, use a função de membro [GetParaFormat](reference/cricheditctrl-class.md#getparaformat) . A estrutura [PARAformativa](/windows/win32/api/richedit/ns-richedit-paraformat) é usada com essas funções de membro para especificar atributos de parágrafo. Um dos membros importantes de **PARAformat** é *dwMask*. No `SetParaFormat` , *dwMask* especifica quais atributos de parágrafo serão definidos por essa chamada de função. `GetParaFormat`relata os atributos do primeiro parágrafo na seleção; *dwMask* especifica os atributos que são consistentes durante a seleção.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
