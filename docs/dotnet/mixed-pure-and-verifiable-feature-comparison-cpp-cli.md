---
title: Comparação de recursos mistos, puros e verificáveis (C++ /CLI CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 8cb1b2ba71277415fd1ba5124f6120cc2f2c995d
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704705"
---
# <a name="mixed-pure-and-verifiable-feature-comparison-ccli"></a>Comparação de recursos mistos, puros e verificáveis (C++ /CLI CLI)

Este tópico compara recursos entre os diferentes **/clr** modos de compilação. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md).

> [!IMPORTANT]
> O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

## <a name="feature-comparison"></a>Comparação de recursos

|Recurso|Misto (/ clr)|Puro (/ clr: pure)|Segurança (/: Safe)|Informações relacionadas|
|-------------|---------------------|-------------------------|-------------------------|-------------------------|
|Biblioteca CRT|Com suporte|preterido||[Rotinas de tempo de execução C universais por categoria](../c-runtime-library/run-time-routines-by-category.md)|
|ATL/MFC|Com suporte|||[Aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md) &#124; [visão geral da classe](../atl/atl-class-overview.md)|
|Funções não gerenciadas|Com suporte|||[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)|
|Dados não gerenciados|Com suporte|preterido||[Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)|
|Chamado de funções não gerenciadas|Com suporte||||
|Dá suporte a chamar funções não gerenciadas|Com suporte|preterido|preterido|[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)|
|Dá suporte a reflexão|DLLs somente|preterido|preterido|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|

## <a name="see-also"></a>Consulte também

- [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)