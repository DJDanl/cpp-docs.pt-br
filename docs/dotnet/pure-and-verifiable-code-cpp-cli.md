---
title: Código puro e verificável (C++/CLI)
ms.date: 11/04/2016
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
ms.openlocfilehash: 66f3b5a33791d20297cde6e6223ba65189a99682
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384708"
---
# <a name="pure-and-verifiable-code-ccli"></a>Código puro e verificável (C++ /CLI CLI)

Para a programação do .NET, Visual C++ no Visual Studio 2017 oferece suporte à criação de assemblies mistos usando o [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador. O **/clr: pure** e **/CLR: safe** opções são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017. Se seu código precisa ser seguro ou verificável, recomendamos que você portá-lo para C#.

## <a name="mixed-clr"></a>Misto (/ clr)

Assemblies mistos (compilado com **/clr**), contêm ambos não gerenciados e partes gerenciadas, tornando possível para que eles possam usar os recursos do .NET, mas ainda contêm código nativo. Isso permite que aplicativos e componentes a ser atualizado usar recursos do .NET sem a necessidade de que todo o projeto ser reescrito. Usando o Visual C++ de combinar código gerenciado e nativo dessa maneira é chamado de interoperabilidade C++. Para obter mais informações, consulte [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md) e [nativo e interoperabilidade do .NET](../dotnet/native-and-dotnet-interoperability.md).

Chamadas feitas de assemblies gerenciados para DLLs nativas via P/Invoke serão compilado, mas podem falhar em tempo de execução dependendo das configurações de segurança.

Há um cenário de codificação que passará o compilador, mas o que resultará em um assembly não verificável: chamar uma função virtual por meio de uma instância do objeto usando o operador de resolução de escopo.  Por exemplo: `MyObj -> A::VirtualFunction();`.

## <a name="see-also"></a>Consulte também

- [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
