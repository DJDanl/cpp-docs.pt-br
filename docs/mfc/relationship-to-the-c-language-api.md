---
title: "Relação com a API da linguagem C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.mfc
dev_langs: C++
helpviewer_keywords:
- books [MFC], about MFC and Windows SDK
- books [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- Windows API [MFC], and MFC
ms.assetid: 334e8efc-f3cc-4018-bc2e-02908b2a39fe
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 26458242ab6afcf69d6e70065ba70e31f0adbe74
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="relationship-to-the-c-language-api"></a>Relacionamento com a API da linguagem C
A única característica que define a biblioteca Microsoft Foundation Class (MFC) além de outras bibliotecas de classe do Windows é o mapeamento muito próxima à API do Windows escritos na linguagem C. Além disso, você geralmente pode misturar chamadas para a biblioteca de classes livremente com chamadas diretas a API do Windows. Esse acesso direto não, no entanto, significa que as classes são uma substituição completa para essa API. Os desenvolvedores ainda ocasionalmente devem fazer chamadas diretas para algumas funções do Windows, como [SetCursor](http://msdn.microsoft.com/library/windows/desktop/ms648393) e [GetSystemMetrics](http://msdn.microsoft.com/library/windows/desktop/ms724385), por exemplo. Uma função do Windows é encapsulada por uma função de membro de classe somente quando há uma vantagem óbvia para fazer isso.  
  
 Porque às vezes você precisa fazer chamadas de função nativas do Windows, você deve ter acesso a documentação da API do Windows de linguagem C. Esta documentação é incluída com o Microsoft Visual C++.  
  
> [!NOTE]
>  Para obter uma visão geral de como funciona a estrutura de biblioteca MFC, consulte [usando as Classes para escrever aplicativos para Windows](../mfc/using-the-classes-to-write-applications-for-windows.md).  
  
## <a name="see-also"></a>Consulte também  
 [Filosofia de design da classe geral](../mfc/general-class-design-philosophy.md)
