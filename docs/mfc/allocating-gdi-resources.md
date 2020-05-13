---
title: Alocando recursos GDI
ms.date: 06/03/2019
helpviewer_keywords:
- resources [MFC], printing
- GDI objects [MFC], allocating during printing
- printing [MFC], allocating GDI resources
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
ms.openlocfilehash: 149aefeade6f99c294b12bfb294cdf1addb9e5e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370844"
---
# <a name="allocating-gdi-resources"></a>Alocando recursos GDI

Este artigo explica como alocar e desalocar os objetos GDI (Windows Graphics Device Interface, interface de dispositivo gráfico do Windows) necessários para impressão.

> [!NOTE]
> Para obter mais informações, consulte a [documentação GDI+ SDK](/windows/win32/gdiplus/-gdiplus-gdi-start).

Suponha que você precise usar certas fontes, canetas ou outros objetos GDI para impressão, mas não para exibição de tela. Devido à memória que eles precisam, é ineficiente alocar esses objetos quando o aplicativo é iniciado. Quando o aplicativo não está imprimindo um documento, essa memória pode ser necessária para outros fins. É melhor alocá-los quando a impressão começa e, em seguida, excluí-los quando a impressão termina.

Para alocar esses objetos GDI, anule a função de membro [OnBeginPrinting.](../mfc/reference/cview-class.md#onbeginprinting) Esta função é adequada para este propósito por duas razões: a estrutura chama essa função uma vez no início de cada trabalho de impressão e, ao contrário do [OnPreparePrinting,](../mfc/reference/cview-class.md#onprepareprinting)esta função tem acesso ao objeto [CDC](../mfc/reference/cdc-class.md) representando o driver do dispositivo da impressora. Você pode armazenar esses objetos para uso durante o trabalho de impressão definindo variáveis `CFont *` de membro em sua classe de exibição que apontam para objetos GDI (por exemplo, membros e assim por diante).

Para usar os objetos GDI criados, selecione-os no contexto do dispositivo da impressora na função [membro OnPrint.](../mfc/reference/cview-class.md#onprint) Se você precisar de diferentes objetos GDI para `m_nCurPage` diferentes páginas do documento, você pode examinar o membro da estrutura [CPrintInfo](../mfc/reference/cprintinfo-structure.md) e selecionar o objeto GDI de acordo. Se você precisar de um objeto GDI por várias páginas consecutivas, o Windows exige que você o selecione no contexto do dispositivo cada vez `OnPrint` que é chamado.

Para desalocar esses objetos GDI, anule a função de membro [OnEndPrinting.](../mfc/reference/cview-class.md#onendprinting) O framework chama essa função no final de cada trabalho de impressão, dando-lhe a oportunidade de desalocar objetos GDI específicos de impressão antes que o aplicativo retorne a outras tarefas.

## <a name="see-also"></a>Confira também

[Imprimindo](../mfc/printing.md)<br/>
[Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)
