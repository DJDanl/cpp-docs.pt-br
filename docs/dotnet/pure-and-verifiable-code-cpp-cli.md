---
title: Código puro e verificável (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- /clr compiler option [C++], verifiable assemblies
- /clr compiler option [C++], mixed assemblies
- pure MSIL [C++]
- verifiable assemblies [C++]
- verifiably type-safe code [C++]
- /clr compiler option [C++], pure assemblies
- .NET Framework [C++], pure and verifiable code
- assemblies [C++], mixed code
- verifiable assemblies [C++], about verifiable assemblies
- mixed assemblies [C++], about mixed assemblies
- pure MSIL [C++], about pure code
- assemblies [C++], verifiable code
- mixed assemblies [C++]
- assemblies [C++], pure code
ms.assetid: 9050e110-fa11-4356-b56c-665187ff871c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 453bb40e94c1d345adbe22f8792b59d1e584499a
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "34704822"
---
# <a name="pure-and-verifiable-code-ccli"></a>Código puro e verificável (C + + CLI)

Para a programação do .NET, o Visual C++ no Visual Studio de 2017 suporta a criação de assemblies mistos usando o [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O **/clr: pure** e **: safe** opções são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017. Se seu código precisa ser seguro ou verificável, é recomendável que você a porta para c#.

## <a name="mixed-clr"></a>Misto (/ clr)

Misto assemblies (compilado com **/clr**), contém ambos não gerenciado e gerenciados partes, possibilitando o uso de recursos do .NET, mas ainda contêm código nativo. Isso permite que aplicativos e componentes a serem atualizados para usar recursos do .NET sem a necessidade de que o projeto inteiro ser reescrito. Usando o Visual C++ misturar código gerenciado e nativo dessa maneira é chamada de interoperabilidade C++. Para obter mais informações, consulte [Assemblies misto (nativo e gerenciado)](../dotnet/mixed-native-and-managed-assemblies.md) e [nativo e interoperabilidade .NET](../dotnet/native-and-dotnet-interoperability.md).

Chamadas de assemblies gerenciados para DLLs nativas por meio de P/Invoke serão compilados, mas podem falhar em tempo de execução dependendo das configurações de segurança.

Há um cenário de codificação que passará o compilador, mas que resultará em um assembly não verificado: chamar uma função virtual por meio de uma instância de objeto usando o operador de resolução do escopo.  Por exemplo: `MyObj -> A::VirtualFunction();`.

## <a name="see-also"></a>Consulte também

- [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

