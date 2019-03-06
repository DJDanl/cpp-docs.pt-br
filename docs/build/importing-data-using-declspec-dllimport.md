---
title: Importando dados usando __declspec(dllimport)
ms.date: 11/04/2016
f1_keywords:
- dllimport
helpviewer_keywords:
- importing data [C++]
- dllimport attribute [C++], data imports
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: 0ae70b39-87c7-4181-8be9-e786e0db60b0
ms.openlocfilehash: 7f4b9dcf7358e8301562fb5e856b9a3fd1cb42cd
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57419591"
---
# <a name="importing-data-using-declspecdllimport"></a>Importando dados usando __declspec(dllimport)

No caso de dados, usando **__declspec(dllimport)** é um item de conveniência que remove uma camada de indireção. Quando você importa dados de uma DLL, você precisa percorrer a tabela de endereços de importação. Antes de **__declspec(dllimport)**, isso significava que você tinha que não se esqueça de fazer um nível extra de indireção ao acessar dados exportadas da DLL:

```
// project.h
#ifdef _DLL   // If accessing the data from inside the DLL
   ULONG ulDataInDll;

#else         // If accessing the data from outside the DLL
   ULONG *ulDataInDll;
#endif
```

Você poderia, em seguida, exportar os dados no seu. Arquivo DEF:

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

Quando você marca os dados como **__declspec(dllimport)**, o compilador gera automaticamente o código de indireção para você. Você não precisa se preocupar sobre as etapas acima. Conforme mencionado anteriormente, não use **__declspec(dllimport)** declaração sobre os dados ao criar a DLL. Funções dentro da DLL não usam a tabela de endereços de importação para acessar o objeto de dados; Portanto, você não terá o nível extra de indireção presente.

Para exportar os dados automaticamente da DLL, use essa declaração:

```
__declspec(dllexport) ULONG ulDataInDLL;
```

## <a name="see-also"></a>Consulte também

[Importando para um aplicativo](../build/importing-into-an-application.md)
