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
ms.openlocfilehash: 16c02bb58681ecb241d3552f57e0b05f2d6711b4
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80208791"
---
# <a name="application-domains-and-visual-c"></a>Domínios de aplicativo e Visual C++

Se você tiver uma função virtual `__clrcall`, a vtable será por domínio de aplicativo (AppDomain). Se você criar um objeto em um AppDomain, só poderá chamar a função virtual de dentro desse AppDomain. No modo misto ( **/CLR**), você terá vtables por processo se o seu tipo não tiver nenhuma `__clrcall` funções virtuais. As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Para obter mais informações, consulte:

- [appdomain](../cpp/appdomain.md)

- [__clrcall](../cpp/clrcall.md)

- [process](../cpp/process.md)

## <a name="see-also"></a>Confira também

- [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)
