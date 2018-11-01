---
title: Como adicionar DLL nativo ao cache de assembly global
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- DLLs [C++], native
- GAC (global assembly cache), loading native DLLs
- native DLLs [C++]
ms.assetid: 25e8d78a-b197-4269-b4e9-237a544ab3c8
ms.openlocfilehash: 1b11ebfae704ca1529113a00b463df728c85fe60
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641357"
---
# <a name="how-to-add-native-dll-to-global-assembly-cache"></a>Como adicionar DLL nativo ao cache de assembly global

Você pode colocar uma DLL nativa (não COM) no Cache de Assembly Global.

## <a name="example"></a>Exemplo

**/ASSEMBLYLINKRESOURCE** permite que você inserir uma DLL nativa em um assembly.

Para obter mais informações, consulte [/ASSEMBLYLINKRESOURCE (Link para Recurso do .NET Framework)](../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md).

```
/ASSEMBLYLINKRESOURCE:MyComponent.dll
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)