---
title: Diretivas para o pré-processador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: adc6251e-cf6b-4508-bdbb-55f446c838d3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f1ddecf1e205cc9a6d7f09a27fbf243417540e49
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46033557"
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

## <a name="see-also"></a>Consulte também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)