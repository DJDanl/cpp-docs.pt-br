---
title: Comparação de funcionalidades mistas, puras e verificáveis (C + + / CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- safe assemblies [C++], vs. pure
- mixed assemblies [C++], vs. pure
- safe assemblies [C++], vs. mixed
- pure MSIL [C++]
- verifiable assemblies [C++]
- pure MSIL [C++], vs. safe
- pure MSIL [C++], vs. mixed
- pure MSIL [C++], compared to mixed and safe
- verifiable assemblies [C++], vs. mixed
- mixed assemblies [C++], vs. safe
- verifiable assemblies [C++], vs. pure
- pure assemblies [C++]
- safe assemblies [C++]
- mixed assemblies [C++]
ms.assetid: 3f7a82ba-0e69-4927-ba0c-fbc3160e4394
ms.openlocfilehash: 81fcf986ee68f5f8f64c8070bb992fa1cda1683b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50482063"
---
# <a name="mixed-pure-and-verifiable-feature-comparison-ccli"></a>Comparação de funcionalidades mistas, puras e verificáveis (C + + / CLI)

Este tópico compara recursos entre as diferentes **/clr** modos de compilação. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md).

> [!IMPORTANT]
> O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

## <a name="feature-comparison"></a>Comparação entre recursos

|Recurso|Misto (/ clr)|Puro (/ clr: pure)|Segurança (/ /CLR: Safe)|Informações relacionadas|
|-------------|---------------------|-------------------------|-------------------------|-------------------------|
|Biblioteca de CRT|Com suporte|preterido||[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)|
|MFC/ATL|Com suporte|||[Aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md) &#124; [visão geral de classe](../atl/atl-class-overview.md)|
|Funções não gerenciadas|Com suporte|||[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)|
|Dados não gerenciados|Com suporte|preterido||[Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)|
|Pode ser chamado de funções não gerenciadas|Com suporte||||
|Dá suporte a chamar funções não gerenciadas|Com suporte|preterido|preterido|[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)|
|Dá suporte à reflexão|DLLs somente|preterido|preterido|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|

## <a name="see-also"></a>Consulte também

- [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)