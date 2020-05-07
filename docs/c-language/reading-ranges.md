---
title: Intervalos de leitura
ms.date: 11/04/2016
ms.assetid: 99de29ce-ab14-46f4-97e1-2081fd996b53
ms.openlocfilehash: 86bb24647084d8bdc452960bab631587c2413276
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64343143"
---
# <a name="reading-ranges"></a>Intervalos de leitura

**ANSI 4.9.6.2** A interpretação de um caractere de sublinhado (–) que não é o primeiro nem o último caractere da scanlist para % [conversão na função `fscanf`

A linha a seguir

```
fscanf( fileptr, "%[A-Z]", strptr);
```

lê qualquer número de caracteres de A a Z para a cadeia de caracteres para a qual `strptr` aponta.

## <a name="see-also"></a>Confira também

[Funções de biblioteca](../c-language/library-functions.md)
