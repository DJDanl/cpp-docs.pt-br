---
title: Dicas de programação MBCS | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d5beaab3fe1642b3988e9d0dcbf258eab02e26b7
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42610303"
---
# <a name="mbcs-programming-tips"></a>Dicas de programação MBCS
Durante o desenvolvimento, você deve usar a codificação de caractere Unicode para todas as cadeias de caracteres que os usuários finais podem possivelmente ver. MBCS é uma tecnologia herdada que foi substituída por Unicode. Esta seção fornece dicas para desenvolvedores que devem manter programas existentes que usam MBCS e onde não é prático converter em Unicode. O conselho se aplica a aplicativos escritos sem o MFC e aplicativos MFC. Os tópicos incluem:  
  
-   [Aviso de programação MBCS geral](../text/general-mbcs-programming-advice.md)  
  
-   [Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)  
  
-   [Índices de byte](../text/byte-indices.md)  
  
-   [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)  
  
-   [Atribuição de caractere](../text/character-assignment.md)  
  
-   [Comparação de caracteres](../text/character-comparison.md)  
  
-   [Estouro de buffer](../text/buffer-overflow.md)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)