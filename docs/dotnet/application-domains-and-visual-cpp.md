---
title: "Domínios do aplicativo e do Visual C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- interop [C++], application domains
- application domains [C++], C++
- /clr compiler option [C++], application domains
- interoperability [C++], application domains
- mixed assemblies [C++], application domains
ms.assetid: 75a08efc-9b02-40ba-99b7-dcbd71010bbf
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: a66731b9645458441f1c3e1f211c74be698e7231
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="application-domains-and-visual-c"></a>Domínios de aplicativo e Visual C++
Se você tiver um `__clrcall` função virtual, o vtable será por domínio de aplicativo (appdomain). Se você criar um objeto em um appdomain, você só pode chamar a função virtual de dentro do appdomain. Todas as funções definidas no **/clr: pure** compilandos usam o `__clrcall` convenção de chamada. Portanto, todos os vtables definidos no **/clr: pure** compilandos são por appdomain. No modo misto (**/clr**) será necessário por processo vtables se seu tipo não tiver nenhuma `__clrcall` funções virtuais. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 Para saber mais, veja  
  
-   [appdomain](../cpp/appdomain.md)  
  
-   [__clrcall](../cpp/clrcall.md)  
  
-   [Como: migrar para /clr: pure (C + + CLI)](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md)  
  
-   [process](../cpp/process.md)  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)