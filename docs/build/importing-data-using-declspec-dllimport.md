---
title: Importando dados usando __declspec(dllimport)
ms.date: 11/04/2016
helpviewer_keywords:
- importing data [C++]
- dllimport attribute [C++], data imports
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: 0ae70b39-87c7-4181-8be9-e786e0db60b0
ms.openlocfilehash: 341912b53301c3a11df4285167d66c8c1493d2fd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223987"
---
# <a name="importing-data-using-__declspecdllimport"></a>Importando dados usando __declspec(dllimport)

No caso dos dados, o uso do **`__declspec(dllimport)`** é um item de conveniência que remove uma camada de indireção. Ao importar dados de uma DLL, você ainda precisa passar pela tabela de endereços de importação. Antes **`__declspec(dllimport)`** disso, isso significava que você tinha de se lembrar de fazer um nível extra de indireção ao acessar dados exportados da dll:

```
// project.h
#ifdef _DLL   // If accessing the data from inside the DLL
   ULONG ulDataInDll;

#else         // If accessing the data from outside the DLL
   ULONG *ulDataInDll;
#endif
```

Em seguida, você exportaria os dados no seu. Arquivo DEF:

```
// project.def
LIBRARY project
EXPORTS
   ulDataInDll   CONSTANT
```

e acessá-lo fora da DLL:

```
if (*ulDataInDll == 0L)
{
   // Do stuff here
}
```

Quando você marca os dados como **`__declspec(dllimport)`** , o compilador gera automaticamente o código de indireção para você. Você não precisa mais se preocupar com as etapas acima. Como mencionado anteriormente, não use **`__declspec(dllimport)`** a declaração nos dados ao compilar a dll. As funções dentro da DLL não usam a tabela de endereços de importação para acessar o objeto de dados; Portanto, você não terá o nível extra de indireção presente.

Para exportar os dados automaticamente da DLL, use esta declaração:

```
__declspec(dllexport) ULONG ulDataInDLL;
```

## <a name="see-also"></a>Confira também

[Importando para um aplicativo](importing-into-an-application.md)
