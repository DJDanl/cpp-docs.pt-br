---
title: 'Como: Adicionar DLL nativo ao Cache de Assembly Global'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- DLLs [C++], native
- GAC (global assembly cache), loading native DLLs
- native DLLs [C++]
ms.assetid: 25e8d78a-b197-4269-b4e9-237a544ab3c8
ms.openlocfilehash: b4b886dfef3185c1b3084ed02abcef1ad2630c11
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222792"
---
# <a name="how-to-add-native-dll-to-global-assembly-cache"></a>Como: Adicionar DLL nativo ao Cache de Assembly Global

Você pode colocar uma DLL nativa (não COM) no Cache de Assembly Global.

## <a name="example"></a>Exemplo

**/ASSEMBLYLINKRESOURCE** permite que você inserir uma DLL nativa em um assembly.

Para obter mais informações, consulte [/ASSEMBLYLINKRESOURCE (Link para Recurso do .NET Framework)](../build/reference/assemblylinkresource-link-to-dotnet-framework-resource.md).

```
/ASSEMBLYLINKRESOURCE:MyComponent.dll
```

## <a name="see-also"></a>Consulte também

[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)
