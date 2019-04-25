---
title: Erro fatal C1071
ms.date: 11/04/2016
f1_keywords:
- C1071
helpviewer_keywords:
- C1071
ms.assetid: 489f1786-370e-4ecd-af67-538fe6e5bd4e
ms.openlocfilehash: 8fe6b0f3bb1253f72c97f29070ba81cdbdf80508
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166653"
---
# <a name="fatal-error-c1071"></a>Erro fatal C1071

fim de arquivo inesperado encontrado no comentário

O compilador atingiu o fim do arquivo ao examinar um comentário.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Falta o terminador de comentário (* /).

1. Caractere de nova linha ausente após um comentário na última linha de um arquivo de origem.

O exemplo a seguir gera C1071:

```
// C1071.cpp
int main() {
}

/* this comment is fine */
/* forgot the closing tag        // C1071
```