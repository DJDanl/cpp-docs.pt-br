---
title: Importando dados usando __declspec(dllimport) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- dllimport
dev_langs:
- C++
helpviewer_keywords:
- importing data [C++]
- dllimport attribute [C++], data imports
- __declspec(dllimport) keyword [C++]
- importing DLLs [C++], __declspec(dllimport)
ms.assetid: 0ae70b39-87c7-4181-8be9-e786e0db60b0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a024d7488eb1683f40548839ab843da1e56f65e8
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710210"
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