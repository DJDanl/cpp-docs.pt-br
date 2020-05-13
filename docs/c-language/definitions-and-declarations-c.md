---
title: Definições e declarações (C)
ms.date: 11/04/2016
helpviewer_keywords:
- export functions
ms.assetid: d150395a-89d4-4298-9ac4-08f84fe1261c
ms.openlocfilehash: 8723c3f09a5e9a8eecf0e552c9f5a7fd9b7f6c68
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62234352"
---
# <a name="definitions-and-declarations-c"></a>Definições e declarações (C)

**Específico da Microsoft**

A interface da DLL refere-se a todos os itens (funções e dados) que sabidamente são exportados por algum programa no sistema; ou seja, todos os itens que são declarados como **dllimport** ou `dllexport`. Todas as declarações incluídas na interface da DLL devem especificar o atributo **dllimport** ou `dllexport`. No entanto, a definição pode especificar apenas o atributo `dllexport`. Por exemplo, a definição de função a seguir gera um erro de compilador:

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

O uso de `dllexport` implica uma definição, enquanto **dllimport** implica uma declaração. Você deve usar a palavra-chave `extern` com `dllexport` para forçar uma declaração; caso contrário, uma definição é implícita.

```
#define DllImport   __declspec( dllimport )
#define DllExport   __declspec( dllexport )

extern DllImport int k;   /* These are correct and imply */
Dllimport int j;          /* a declaration. */
```

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Funções de importação e exportação de DLL](../c-language/dll-import-and-export-functions.md)
