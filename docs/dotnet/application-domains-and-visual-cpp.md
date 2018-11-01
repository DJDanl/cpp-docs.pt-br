---
title: Domínios de aplicativo e Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- interop [C++], application domains
- application domains [C++], C++
- /clr compiler option [C++], application domains
- interoperability [C++], application domains
- mixed assemblies [C++], application domains
ms.assetid: 75a08efc-9b02-40ba-99b7-dcbd71010bbf
ms.openlocfilehash: 2296654e6935bc40f301226b184cf34f77cb126d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539263"
---
# <a name="application-domains-and-visual-c"></a>Domínios de aplicativo e do Visual C++

Se você tiver um `__clrcall` função virtual, seja por domínio de aplicativo (appdomain) vtable. Se você criar um objeto em um appdomain, você só pode chamar a função virtual de dentro do appdomain. No modo misto (**/clr**) por processo vtables será necessário se seu tipo não tem nenhum `__clrcall` funções virtuais. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter mais informações, consulte:

- [appdomain](../cpp/appdomain.md)

- [__clrcall](../cpp/clrcall.md)

- [process](../cpp/process.md)

## <a name="see-also"></a>Consulte também

- [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)