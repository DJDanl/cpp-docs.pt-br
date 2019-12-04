---
title: Erro fatal C1071
ms.date: 11/04/2016
f1_keywords:
- C1071
helpviewer_keywords:
- C1071
ms.assetid: 489f1786-370e-4ecd-af67-538fe6e5bd4e
ms.openlocfilehash: 2f39359d55b5564c6379c84f07e942cf3484e011
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74747404"
---
# <a name="fatal-error-c1071"></a>Erro fatal C1071

fim inesperado de arquivo encontrado no comentário

O compilador atingiu o final do arquivo durante a verificação de um comentário.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Terminador de comentário ausente (*/).

1. Caractere de linhagem ausente após um comentário na última linha de um arquivo de origem.

O exemplo a seguir gera C1071:

```cpp
// C1071.cpp
int main() {
}

/* this comment is fine */
/* forgot the closing tag        // C1071
```
