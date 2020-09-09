---
title: Importando dados usando __declspec(dllimport)
description: Como usar __declspec (dllimport) para importar dados de DLL.
ms.date: 09/03/2020
helpviewer_keywords:
- importing data [C++]
- dllimport attribute [C++], data imports
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: 0ae70b39-87c7-4181-8be9-e786e0db60b0
ms.openlocfilehash: cb9850306d6e73b88e2926a6f068ae21f8d32530
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609113"
---
# <a name="importing-data-using-__declspecdllimport"></a>Importando dados usando `__declspec(dllimport)`

No caso dos dados, o uso do **`__declspec(dllimport)`** é um item de conveniência que remove uma camada de indireção. Ao importar dados de uma DLL, você ainda precisa passar pela tabela de endereços de importação. Antes **`__declspec(dllimport)`** disso, isso significava que você tinha de se lembrar de fazer um nível extra de indireção ao acessar dados exportados da dll:

```C
// project.h
// Define PROJECT_EXPORTS when building your DLL
#ifdef PROJECT_EXPORTS   // If accessing the data from inside the DLL
   ULONG ulDataInDll;

#else         // If accessing the data from outside the DLL
   ULONG *ulDataInDll;
#endif
```

Em seguida, você exportaria os dados no seu. Arquivo DEF:

```DEF
// project.def
LIBRARY project
EXPORTS
   ulDataInDll   CONSTANT
```

e acessá-lo fora da DLL:

```C
if (*ulDataInDll == 0L)
{
   // Do stuff here
}
```

Quando você marca os dados como **`__declspec(dllimport)`** , o compilador gera automaticamente o código de indireção para você. Você não precisa mais se preocupar com as etapas acima. Como mencionado anteriormente, não use **`__declspec(dllimport)`** a declaração nos dados ao compilar a dll. As funções dentro da DLL não usam a tabela de endereços de importação para acessar o objeto de dados; Portanto, você não terá o nível extra de indireção presente.

Para exportar os dados automaticamente da DLL, use esta declaração:

```C
// project.h
// Define PROJECT_EXPORTS when building your DLL
#ifdef PROJECT_EXPORTS   // If accessing the data from inside the DLL
   __declspec(dllexport) ULONG ulDataInDLL;

#else         // If accessing the data from outside the DLL
   __declspec(dllimport) ULONG ulDataInDLL;
#endif
```

## <a name="see-also"></a>Confira também

[Importando para um aplicativo](importing-into-an-application.md)
