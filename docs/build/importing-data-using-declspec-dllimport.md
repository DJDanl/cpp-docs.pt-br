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
ms.openlocfilehash: b9877c5a229c3cabcb7703dd2617d1d57e3512f0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368506"
---
# <a name="importing-data-using-declspecdllimport"></a>Importando dados usando __declspec(dllimport)
No caso de dados, usando **__declspec(dllimport)** é um item de conveniência que remove uma camada de indireção. Quando você importa dados de uma DLL, você ainda precisa percorrer a tabela de endereço de importação. Antes de **__declspec(dllimport)**, isso significa que você precisava Lembre-se de fazer um nível extra de indireção ao acessar dados exportados da DLL:  
  
```  
// project.h  
#ifdef _DLL   // If accessing the data from inside the DLL  
   ULONG ulDataInDll;  
  
#else         // If accessing the data from outside the DLL  
   ULONG *ulDataInDll;  
#endif  
```  
  
 Você pode salvar os dados no seu. Arquivo de definição:  
  
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
  
 Quando você marca os dados como **__declspec(dllimport)**, o compilador gera o código de indireção automaticamente para você. Você não precisa se preocupar sobre as etapas acima. Como mencionado anteriormente, não use **__declspec(dllimport)** declaração nos dados durante a criação da DLL. Funções de DLL não usam a tabela de endereço de importação para acessar o objeto de dados; Portanto, você não terá o nível extra de indireção presente.  
  
 Para exportar os dados automaticamente da DLL, use essa declaração:  
  
```  
__declspec(dllexport) ULONG ulDataInDLL;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Importando para um aplicativo](../build/importing-into-an-application.md)