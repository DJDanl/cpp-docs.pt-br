---
title: Lendo intervalos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 99de29ce-ab14-46f4-97e1-2081fd996b53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 76530dfdac917dfbde50bc3fb1b17a3c31178729
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46030229"
---
# <a name="reading-ranges"></a>Intervalos de leitura

**ANSI 4.9.6.2** A interpretação de um caractere de sublinhado (–) que não é o primeiro nem o último caractere da scanlist para % [conversão na função `fscanf`

A linha a seguir

```
fscanf( fileptr, "%[A-Z]", strptr);
```

lê qualquer número de caracteres de A a Z para a cadeia de caracteres para a qual `strptr` aponta.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)