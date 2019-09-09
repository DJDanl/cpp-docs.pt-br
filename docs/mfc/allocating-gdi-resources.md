---
title: Alocando recursos GDI
ms.date: 06/03/2019
helpviewer_keywords:
- resources [MFC], printing
- GDI objects [MFC], allocating during printing
- printing [MFC], allocating GDI resources
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
ms.openlocfilehash: 672a9a2ce103ae7f53f61ae955f77276eb1d2945
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509282"
---
# <a name="allocating-gdi-resources"></a>Alocando recursos GDI

Este artigo explica como alocar e desalocar os objetos da interface de dispositivo de gráficos do Windows (GDI) necessários para impressão.

> [!NOTE]
>  Para obter mais informações, consulte a [documentação do SDK do GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

Suponha que você precise usar determinadas fontes, canetas ou outros objetos GDI para impressão, mas não para exibição de tela. Devido à memória que eles precisam, é ineficiente alocar esses objetos quando o aplicativo é iniciado. Quando o aplicativo não está imprimindo um documento, essa memória pode ser necessária para outras finalidades. É melhor alocá-los quando a impressão começa e, em seguida, excluí-los quando a impressão termina.

Para alocar esses objetos GDI, substitua a função membro [OnBeginPrinting](../mfc/reference/cview-class.md#onbeginprinting) . Essa função é bem adequada para essa finalidade por dois motivos: a estrutura chama essa função uma vez no início de cada trabalho de impressão e, ao contrário de [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting), essa função tem acesso ao objeto [CDC](../mfc/reference/cdc-class.md) que representa o dispositivo de impressora Driver. Você pode armazenar esses objetos para uso durante o trabalho de impressão Definindo variáveis de membro na classe View que apontam para objetos GDI (por exemplo `CFont *` , membros e assim por diante).

Para usar os objetos GDI que você criou, selecione-os no contexto do dispositivo de impressora na função de membro [OnPrint](../mfc/reference/cview-class.md#onprint) . Se você precisar de objetos GDI diferentes para páginas diferentes do documento, poderá examinar o `m_nCurPage` membro da estrutura [CPrintInfo](../mfc/reference/cprintinfo-structure.md) e selecionar o objeto GDI adequadamente. Se você precisar de um objeto GDI para várias páginas consecutivas, o Windows exigirá que você a selecione no contexto `OnPrint` do dispositivo cada vez que for chamado.

Para desalocar esses objetos GDI, substitua a função membro [OnEndPrinting](../mfc/reference/cview-class.md#onendprinting) . A estrutura chama essa função no final de cada trabalho de impressão, dando a você a oportunidade de desalocar objetos GDI específicos de impressão antes que o aplicativo retorne a outras tarefas.

## <a name="see-also"></a>Consulte também

[Imprimindo](../mfc/printing.md)<br/>
[Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)
