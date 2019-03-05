---
title: Relacionamento com a API da linguagem C
ms.date: 11/04/2016
f1_keywords:
- vc.classes.mfc
helpviewer_keywords:
- books [MFC], about MFC and Windows SDK
- books [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- Windows API [MFC], and MFC
ms.assetid: 334e8efc-f3cc-4018-bc2e-02908b2a39fe
ms.openlocfilehash: fe83af2d05af8e3b9da8d0c62f6974b0a5410bfc
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278945"
---
# <a name="relationship-to-the-c-language-api"></a>Relacionamento com a API da linguagem C

A única característica que define a biblioteca Microsoft Foundation Class (MFC) além de outras bibliotecas de classes para Windows é o mapeamento muito próxima à API do Windows escrito na linguagem C. Além disso, você geralmente pode misturar chamadas para a biblioteca de classes livremente com chamadas diretas para a API do Windows. Esse acesso direto, no entanto, implica que as classes são uma substituição completa para que a API. Os desenvolvedores ainda, ocasionalmente, devem fazer chamadas diretas para algumas funções do Windows, como [SetCursor](/windows/desktop/api/winuser/nf-winuser-setcursor) e [GetSystemMetrics](/windows/desktop/api/winuser/nf-winuser-getsystemmetrics), por exemplo. Uma função do Windows é encapsulada por uma função de membro de classe somente quando há uma vantagem clara para fazer isso.

Porque, às vezes, você precisa fazer chamadas de função nativas do Windows, você deve ter acesso à documentação da API do Windows de linguagem C. Esta documentação é incluída com o Microsoft Visual C++.

> [!NOTE]
>  Para uma visão geral de como funciona a estrutura da biblioteca MFC, consulte [usando as Classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).

## <a name="see-also"></a>Consulte também

[Filosofia de design da classe geral](../mfc/general-class-design-philosophy.md)
