---
title: Definições e declarações (C)
ms.date: 11/04/2016
helpviewer_keywords:
- export functions
ms.assetid: d150395a-89d4-4298-9ac4-08f84fe1261c
ms.openlocfilehash: 0e39832f942eb1473be913112fde1d37ddf05674
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226360"
---
# <a name="definitions-and-declarations-c"></a>Definições e declarações (C)

**Específico da Microsoft**

A interface DLL refere-se a todos os itens (funções e dados) que são conhecidos por serem exportados por algum programa no sistema; ou seja, todos os itens que são declarados como **`dllimport`** ou `dllexport` . Todas as declarações incluídas na interface DLL devem especificar o **`dllimport`** atributo ou `dllexport` . No entanto, a definição pode especificar apenas o atributo `dllexport`. Por exemplo, a definição de função a seguir gera um erro de compilador:

```
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

DllImport int func()    /* Error; dllimport prohibited in */
                        /* definition. */
{
   return 1;
}
```

Este código também gera um erro:

```
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

DllImport int i = 10;      /* Error; this is a definition. */
```

No entanto, esta é uma sintaxe correta:

```
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

DllExport int i = 10;      /* Okay: this is an export definition. */
```

O uso de `dllexport` implica uma definição, enquanto **`dllimport`** implica uma declaração. Você deve usar a **`extern`** palavra-chave WITH `dllexport` para forçar uma declaração; caso contrário, uma definição é implícita.

```
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

extern DllImport int k;   /* These are correct and imply */
Dllimport int j;          /* a declaration. */
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)
