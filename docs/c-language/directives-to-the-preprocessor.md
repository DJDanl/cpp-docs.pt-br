---
title: Diretivas para o pré-processador
ms.date: 11/04/2016
ms.assetid: adc6251e-cf6b-4508-bdbb-55f446c838d3
ms.openlocfilehash: 520d181c3a58ee2c626678a3afd9126f1ef183cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234134"
---
# <a name="directives-to-the-preprocessor"></a>Diretivas para o pré-processador

Uma "política" instrui o pré-processador C a realizar uma ação específica no texto do programa antes da compilação. As [Diretivas para o pré-processador](../preprocessor/preprocessor-directives.md) são totalmente descritas na *Referência de pré-processador*. Este exemplo usa a política de pré-processador `#define`:

```
#define MAX 100
```

Esta instrução determina que o compilador substitua cada ocorrência de `MAX` por `100` antes da compilação. As políticas de pré-processador do compilador C são:

|#define|#endif|#ifdef|#line|
|--------------|-------------|-------------|------------|
|`#elif`|`#error`|**#ifndef**|**#pragma**|
|`#else`|`#if`|`#include`|`#undef`|

## <a name="see-also"></a>Confira também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)
