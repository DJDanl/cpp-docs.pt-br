---
title: Importando dados usando __declspec(dllimport)
ms.date: 11/04/2016
helpviewer_keywords:
- importing data [C++]
- dllimport attribute [C++], data imports
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: 0ae70b39-87c7-4181-8be9-e786e0db60b0
ms.openlocfilehash: c9dce798572a91bcb9721f022393abb669970131
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440450"
---
# <a name="importing-data-using-__declspecdllimport"></a>Importando dados usando __declspec(dllimport)

No caso de dados, o uso de **__declspec (dllimport)** é um item de conveniência que remove uma camada de indireção. Ao importar dados de uma DLL, você ainda precisa passar pela tabela de endereços de importação. Antes de **__declspec (dllimport)**, isso significava que você tinha que se lembrar de fazer um nível extra de indireção ao acessar dados exportados da dll:

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

Quando você marca os dados como **__declspec (dllimport)**, o compilador gera automaticamente o código de indireção para você. Você não precisa mais se preocupar com as etapas acima. Como mencionado anteriormente, não use a declaração de **__declspec (dllimport)** nos dados ao COMPILAR a dll. As funções dentro da DLL não usam a tabela de endereços de importação para acessar o objeto de dados; Portanto, você não terá o nível extra de indireção presente.

Para exportar os dados automaticamente da DLL, use esta declaração:

```
__declspec(dllexport) ULONG ulDataInDLL;
```

## <a name="see-also"></a>Confira também

[Importando para um aplicativo](importing-into-an-application.md)
