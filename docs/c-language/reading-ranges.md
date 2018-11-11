---
title: Intervalos de leitura
ms.date: 11/04/2016
ms.assetid: 99de29ce-ab14-46f4-97e1-2081fd996b53
ms.openlocfilehash: b5c6a6baf43b8786fbd0301e4b89ea856d839606
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50604094"
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