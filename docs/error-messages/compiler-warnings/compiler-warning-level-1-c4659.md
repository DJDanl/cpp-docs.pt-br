---
title: Aviso do compilador (nível 1) C4659
ms.date: 11/04/2016
f1_keywords:
- C4659
helpviewer_keywords:
- C4659
ms.assetid: e29ba8db-7917-43f6-8e34-868b752279ae
ms.openlocfilehash: 1766cb285fa33d384d57e89c7243fc35022ae006
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175630"
---
# <a name="compiler-warning-level-1-c4659"></a>Aviso do compilador (nível 1) C4659

\#pragma ' pragma ': o uso do segmento reservado ' Segment ' tem comportamento indefinido; use #pragma Comment (linker,...)

A opção. drectve foi usada para passar uma opção para o vinculador. Em vez disso, use o [Comentário](../../preprocessor/comment-c-cpp.md) pragma para passar uma opção de vinculador.

```cpp
// C4659.cpp
// compile with: /W1 /LD
#pragma code_seg(".drectve")   // C4659
```
