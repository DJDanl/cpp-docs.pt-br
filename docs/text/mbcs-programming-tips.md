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
ms.openlocfilehash: ac4ed378640942dbe33490d618cec7289125b0c8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46418782"
---
# <a name="mbcs-programming-tips"></a>Dicas de programação MBCS

Durante o desenvolvimento, você deve usar a codificação de caractere Unicode para todas as cadeias de caracteres que os usuários finais podem possivelmente ver. MBCS é uma tecnologia herdada que foi substituída por Unicode. Esta seção fornece dicas para desenvolvedores que devem manter programas existentes que usam MBCS e onde não é prático converter em Unicode. O conselho se aplica a aplicativos escritos sem o MFC e aplicativos MFC. Os tópicos incluem:

- [Aviso de programação MBCS geral](../text/general-mbcs-programming-advice.md)

- [Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)

- [Índices de byte](../text/byte-indices.md)

- [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)

- [Atribuição de caractere](../text/character-assignment.md)

- [Comparação de caracteres](../text/character-comparison.md)

- [Estouro de buffer](../text/buffer-overflow.md)

## <a name="see-also"></a>Consulte também

[Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)