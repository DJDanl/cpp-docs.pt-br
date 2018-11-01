---
title: Evitando as exceções geradas por objetos COM criados com - clr
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], CLR shutdown exceptions
- /clr compiler option [C++], CLR shutdown exceptions
- mixed assemblies [C++], CLR shutdown exceptions
- /clr compiler option [C++], COM objects
- interoperability [C++], CLR shutdown exceptions
- CLR shutdown exceptions [C++]
ms.assetid: 41249d83-4b51-4e46-866f-27f475f2498c
ms.openlocfilehash: 23af1d8b48a6579b8cc20261691c1f090dc858a2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633434"
---
# <a name="avoiding-exceptions-on-clr-shutdown-when-consuming-com-objects-built-with-clr"></a>Evitando exceções no desligamento do CLR durante o consumo dos objetos COM criados com /clr

Depois que o common language runtime (CLR) entra em modo de desligamento, funções nativas têm acesso limitado aos serviços CLR. Ao tentar chamar a versão em um objeto COM é compilado com **/clr**, o CLR fará a transição para código nativo e, em seguida, faz a transição de volta em código gerenciado para a chamada de IUnknown:: Release (que é definida no código gerenciado) de serviço. O CLR impede que a chamada para o código gerenciado, pois ele está no modo de desligamento.

Para resolver esse problema, certifique-se de que os destruidores chamados de métodos de versão contêm somente código nativo.

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)