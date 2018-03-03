---
title: "Dicas de programação MBCS | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _mbcs
dev_langs:
- C++
helpviewer_keywords:
- programming [C++], MBCS
- character sets [C++], multibyte
- MBCS [C++], programming
- multibyte characters [C++]
ms.assetid: d8ad36b8-917f-474e-8adb-69462adecd17
caps.latest.revision: 
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1dc9c5dfd0dafe96e2d37b789b64c8215aa454e3
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mbcs-programming-tips"></a>Dicas de programação MBCS
No desenvolvimento de novo, você deve usar a codificação de caracteres Unicode para todas as cadeias de caracteres que os usuários finais possivelmente pode ver. MBCS é uma tecnologia herdada foi substituída por Unicode. Esta seção fornece dicas para desenvolvedores que devem manter os programas existentes que usam MBCS e onde não é prático converter em Unicode. O aviso se aplica a aplicativos MFC e aplicativos escritos sem MFC. Os tópicos incluem:  
  
-   [Aviso de programação MBCS geral](../text/general-mbcs-programming-advice.md)  
  
-   [Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)  
  
-   [Índices de byte](../text/byte-indices.md)  
  
-   [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)  
  
-   [Atribuição de caractere](../text/character-assignment.md)  
  
-   [Comparação de caracteres](../text/character-comparison.md)  
  
-   [Estouro de buffer](../text/buffer-overflow.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)