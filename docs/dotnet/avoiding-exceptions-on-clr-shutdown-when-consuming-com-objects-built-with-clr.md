---
title: Evitando exceções lançadas por objetos COM criados com o clr-| Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interop [C++], CLR shutdown exceptions
- /clr compiler option [C++], CLR shutdown exceptions
- mixed assemblies [C++], CLR shutdown exceptions
- /clr compiler option [C++], COM objects
- interoperability [C++], CLR shutdown exceptions
- CLR shutdown exceptions [C++]
ms.assetid: 41249d83-4b51-4e46-866f-27f475f2498c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 0efd2af7eb4bf8a70bff983d627f802f1976c6ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="avoiding-exceptions-on-clr-shutdown-when-consuming-com-objects-built-with-clr"></a>Evitando exceções no desligamento do CLR durante o consumo dos objetos COM criados com /clr
Depois que o common language runtime (CLR) entra em modo de desligamento, funções nativas tem acesso limitado aos serviços CLR. Ao tentar chamar a versão em um objeto COM é compilado com **/clr**, o CLR fará a transição para o código nativo e, em seguida, transições de volta para o código gerenciado para atender à chamada de IUnknown:: Release (que é definida no código gerenciado). O CLR impede que a chamada no código gerenciado porque ele está em modo de desligamento.  
  
 Para resolver esse problema, certifique-se de que destruidores chamadas de métodos de versão contém somente código nativo.  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)