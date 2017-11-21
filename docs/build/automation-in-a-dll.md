---
title: "Automação em uma DLL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- DLLs [C++], Automation
- Automation [C++], DLLs
ms.assetid: 2728ecd1-14e2-4ae0-a946-e749e11dbb74
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 69b5d723da2ac67de3c381b6a5bc09645c1f4341
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="automation-in-a-dll"></a>Automação em um DLL
Quando você escolhe a opção de automação no Assistente de DLL do MFC, o assistente fornece o seguinte:  
  
-   Uma linguagem de descrição do objeto de início (. Arquivos ODL)  
  
-   Uma diretiva de inclusão no arquivo Stdafx. h para Afxole.h  
  
-   Uma implementação de `DllGetClassObject` função, que chama o **AfxDllGetClassObject** função  
  
-   Uma implementação de `DllCanUnloadNow` função, que chama o **AfxDllCanUnloadNow** função  
  
-   Uma implementação de `DllRegisterServer` função, que chama o [COleObjectFactory::UpdateRegistryAll](../mfc/reference/coleobjectfactory-class.md#updateregistryall) função  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)