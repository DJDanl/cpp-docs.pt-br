---
title: "Evitando exceções lançadas por objetos COM criados com o clr-| Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- interop [C++], CLR shutdown exceptions
- /clr compiler option [C++], CLR shutdown exceptions
- mixed assemblies [C++], CLR shutdown exceptions
- /clr compiler option [C++], COM objects
- interoperability [C++], CLR shutdown exceptions
- CLR shutdown exceptions [C++]
ms.assetid: 41249d83-4b51-4e46-866f-27f475f2498c
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 287c9831f8c604272b37ac85528d66fe640de557
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="avoiding-exceptions-on-clr-shutdown-when-consuming-com-objects-built-with-clr"></a>Evitando exceções no desligamento do CLR durante o consumo dos objetos COM criados com /clr
Depois que o common language runtime (CLR) entra em modo de desligamento, funções nativas tem acesso limitado aos serviços CLR. Ao tentar chamar a versão em um objeto COM é compilado com **/clr**, o CLR fará a transição para o código nativo e, em seguida, transições de volta para o código gerenciado para atender à chamada de IUnknown:: Release (que é definida no código gerenciado). O CLR impede que a chamada no código gerenciado porque ele está em modo de desligamento.  
  
 Para resolver esse problema, certifique-se de que destruidores chamadas de métodos de versão contém somente código nativo.  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)