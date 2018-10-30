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
ms.openlocfilehash: a88fffbfc42dd6e7386ec43e55f2013f2548b6f5
ms.sourcegitcommit: a3c9e7888b8f437a170327c4c175733ad9eb0454
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2018
ms.locfileid: "50204464"
---
# <a name="mbcs-programming-tips"></a>Dicas de programação MBCS

Durante o desenvolvimento, você deve usar a codificação de caractere Unicode para todas as cadeias de caracteres que os usuários finais podem possivelmente ver. MBCS é uma tecnologia herdada que foi substituída pelo Unicode. Esta seção fornece dicas para desenvolvedores que devem manter programas existentes que usam MBCS e onde não é prático converter em Unicode. O conselho se aplica a aplicativos escritos sem o MFC e aplicativos MFC. Os tópicos incluem:

- [Aviso de programação MBCS geral](../text/general-mbcs-programming-advice.md)

- [Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)

- [Índices de byte](../text/byte-indices.md)

- [Último caractere em uma cadeia de caracteres](../text/last-character-in-a-string.md)

- [Atribuição de caractere](../text/character-assignment.md)

- [Comparação de caracteres](../text/character-comparison.md)

- [Estouro de buffer](../text/buffer-overflow.md)

## <a name="see-also"></a>Consulte também

[Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)