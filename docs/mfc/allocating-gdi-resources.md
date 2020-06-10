---
title: Alocando recursos GDI
ms.date: 06/03/2019
helpviewer_keywords:
- resources [MFC], printing
- GDI objects [MFC], allocating during printing
- printing [MFC], allocating GDI resources
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
ms.openlocfilehash: f0cadac5320a8c6e91eb3b1989d1fb3c0c701eb0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623242"
---
# <a name="allocating-gdi-resources"></a>Alocando recursos GDI

Este artigo explica como alocar e desalocar os objetos da interface de dispositivo de gráficos do Windows (GDI) necessários para impressão.

> [!NOTE]
> Para obter mais informações, consulte a [documentação do SDK do GDI+](/windows/win32/gdiplus/-gdiplus-gdi-start).

Suponha que você precise usar determinadas fontes, canetas ou outros objetos GDI para impressão, mas não para exibição de tela. Devido à memória que eles precisam, é ineficiente alocar esses objetos quando o aplicativo é iniciado. Quando o aplicativo não está imprimindo um documento, essa memória pode ser necessária para outras finalidades. É melhor alocá-los quando a impressão começa e, em seguida, excluí-los quando a impressão termina.

Para alocar esses objetos GDI, substitua a função membro [OnBeginPrinting](reference/cview-class.md#onbeginprinting) . Essa função é bem adequada para essa finalidade por dois motivos: a estrutura chama essa função uma vez no início de cada trabalho de impressão e, ao contrário de [OnPreparePrinting](reference/cview-class.md#onprepareprinting), essa função tem acesso ao objeto [CDC](reference/cdc-class.md) que representa o driver de dispositivo de impressora. Você pode armazenar esses objetos para uso durante o trabalho de impressão Definindo variáveis de membro na classe View que apontam para objetos GDI (por exemplo, `CFont *` Membros e assim por diante).

Para usar os objetos GDI que você criou, selecione-os no contexto do dispositivo de impressora na função de membro [OnPrint](reference/cview-class.md#onprint) . Se você precisar de objetos GDI diferentes para páginas diferentes do documento, poderá examinar o `m_nCurPage` membro da estrutura [CPrintInfo](reference/cprintinfo-structure.md) e selecionar o objeto GDI adequadamente. Se você precisar de um objeto GDI para várias páginas consecutivas, o Windows exigirá que você a selecione no contexto do dispositivo cada vez que `OnPrint` for chamado.

Para desalocar esses objetos GDI, substitua a função membro [OnEndPrinting](reference/cview-class.md#onendprinting) . A estrutura chama essa função no final de cada trabalho de impressão, dando a você a oportunidade de desalocar objetos GDI específicos de impressão antes que o aplicativo retorne a outras tarefas.

## <a name="see-also"></a>Consulte também

[Impressão](printing.md)<br/>
[Como a impressão padrão é feita](how-default-printing-is-done.md)
