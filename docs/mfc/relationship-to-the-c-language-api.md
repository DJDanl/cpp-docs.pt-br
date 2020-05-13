---
title: Relacionamento com a API da linguagem C
ms.date: 11/04/2016
helpviewer_keywords:
- books [MFC], about MFC and Windows SDK
- books [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- Windows API [MFC], and MFC
ms.assetid: 334e8efc-f3cc-4018-bc2e-02908b2a39fe
ms.openlocfilehash: 1fbd4d332f5ade1cb9415448b138ac5bc838307d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372823"
---
# <a name="relationship-to-the-c-language-api"></a>Relacionamento com a API da linguagem C

A única característica que diferencia a Biblioteca Microsoft Foundation Class (MFC) de outras bibliotecas de classe para Windows é o mapeamento muito próximo da API do Windows escrita no idioma C. Além disso, você geralmente pode misturar chamadas para a biblioteca de classes livremente com chamadas diretas para a API do Windows. Esse acesso direto, no entanto, não implica que as classes sejam um substituto completo para essa API. Os desenvolvedores ainda devem ocasionalmente fazer chamadas diretas para algumas funções do Windows, como [SetCursor](/windows/win32/api/winuser/nf-winuser-setcursor) e [GetSystemMetrics,](/windows/win32/api/winuser/nf-winuser-getsystemmetrics)por exemplo. Uma função do Windows é wrapped por uma função de membro de classe somente quando há uma clara vantagem em fazê-lo.

Como às vezes você precisa fazer chamadas de função nativas do Windows, você deve ter acesso à documentação da API do Windows em c. Esta documentação está incluída no Microsoft Visual C++.

> [!NOTE]
> Para obter uma visão geral de como a estrutura da Biblioteca MFC funciona, consulte [Usando as classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).

## <a name="see-also"></a>Confira também

[Filosofia de design da classe geral](../mfc/general-class-design-philosophy.md)
