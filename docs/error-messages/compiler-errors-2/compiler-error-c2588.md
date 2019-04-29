---
title: Erro do compilador C2588
ms.date: 11/04/2016
f1_keywords:
- C2588
helpviewer_keywords:
- C2588
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
ms.openlocfilehash: 15f9ba62751d9b3cb17ab56659310292dab41adf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350446"
---
# <a name="compiler-error-c2588"></a>Erro do compilador C2588

':: ~ identificador ': destruidor global ilegal

O destruidor é definido para algo diferente de uma classe, estrutura ou união. Isso não é permitido.

Esse erro pode ser causado por uma classe ausente, uma estrutura ou um nome de união no lado esquerdo da resolução de escopo (`::`) operador.

O exemplo a seguir gera C2588:

```
// C2588.cpp
~F();   // C2588
```