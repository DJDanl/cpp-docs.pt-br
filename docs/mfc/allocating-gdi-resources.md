---
title: Alocando recursos GDI
ms.date: 11/04/2016
helpviewer_keywords:
- resources [MFC], printing
- GDI objects [MFC], allocating during printing
- printing [MFC], allocating GDI resources
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
ms.openlocfilehash: d637d524d37dc466e15aed3b571cccf24c18216d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50505701"
---
# <a name="allocating-gdi-resources"></a>Alocando recursos GDI

Este artigo explica como alocar e desalocar os objetos de interface (GDI) do Windows gráficos dispositivo necessários para a impressão.

> [!NOTE]
>  Para obter mais informações, consulte a documentação do SDK de GDI+ em: [ https://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/GDIPlus/GDIPlus.asp ](https://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/gdiplus/gdiplus.asp).

Suponha que você precisa usar determinadas fontes, canetas ou outros objetos GDI para impressão, mas não para a exibição de tela. Devido à memória de que necessitam, é ineficiente para alocar esses objetos quando o aplicativo é iniciado. Quando o aplicativo não estiver imprimindo um documento, essa memória poderá ser necessária para outras finalidades. É melhor alocá-los quando a impressão começará e, em seguida, excluí-los durante a impressão termina.

Para alocar esses objetos GDI, substituir os [OnBeginPrinting](../mfc/reference/cview-class.md#onbeginprinting) função de membro. Essa função é adequada para essa finalidade por dois motivos: a estrutura chama essa função uma vez no início de cada trabalho de impressão e, ao contrário [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting), essa função tem acesso para o [CDC](../mfc/reference/cdc-class.md) objeto que representa o driver de dispositivo de impressora. Você pode armazenar esses objetos para uso durante o trabalho de impressão, definindo as variáveis de membro em sua classe de exibição que apontam para objetos GDI (por exemplo, `CFont *` membros e assim por diante).

Para usar os objetos GDI que você criou, selecione-as no contexto de dispositivo de impressora na [OnPrint](../mfc/reference/cview-class.md#onprint) função de membro. Se você precisar de diferentes objetos GDI para diferentes páginas do documento, você pode examinar a `m_nCurPage` membro a [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura e selecione o objeto GDI adequadamente. Se você precisar de um objeto GDI para várias páginas consecutivas, Windows exige que você selecione-lo no contexto de dispositivo sempre `OnPrint` é chamado.

Para desalocar esses objetos GDI, substituir os [OnEndPrinting](../mfc/reference/cview-class.md#onendprinting) função de membro. O framework chama esta função no final de cada trabalho de impressão, oferecendo a oportunidade para desalocar os objetos GDI específicos de impressão antes do aplicativo retorna para outras tarefas.

## <a name="see-also"></a>Consulte também

[Imprimindo](../mfc/printing.md)<br/>
[Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)

