---
title: "Comparação de recursos mistos, puros e verificáveis (C++ /CLI CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ac5e094dd252ec908f352bcc1b19c923513debfb
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="mixed-pure-and-verifiable-feature-comparison-ccli"></a>Comparação de funcionalidades mistas, puras e verificáveis (C++/CLI)
Este tópico compara recursos entre os diferentes **/clr** modos de compilação. Para obter mais informações, consulte [/clr (compilação de Common Language Runtime)](../build/reference/clr-common-language-runtime-compilation.md).  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
## <a name="feature-comparison"></a>Comparação de recursos  
  
|Recurso|Misto (/ clr)|Puro (/ clr: pure)|Segurança (/: Safe)|Informações relacionadas|  
|-------------|---------------------|-------------------------|-------------------------|-------------------------|  
|Biblioteca CRT|Com suporte|preterido||[Rotinas de tempo de execução por categoria](../c-runtime-library/run-time-routines-by-category.md)|  
|MFC/ATL|Com suporte|||[Aplicativos de Desktop do MFC](../mfc/mfc-desktop-applications.md) &#124; [Visão geral da classe](../atl/atl-class-overview.md)|  
|Funções não gerenciadas|Com suporte|||[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)|  
|Dados não gerenciados|Com suporte|preterido||[Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)|  
|Chamado de funções não gerenciadas|Com suporte||||  
|Dá suporte a chamar funções não gerenciadas|Com suporte|preterido|preterido|[Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)|  
|Dá suporte a reflexão|DLLs somente|preterido|preterido|[Reflexão (C++/CLI)](../dotnet/reflection-cpp-cli.md)|  
  
## <a name="see-also"></a>Consulte também  
 [Código puro e verificável (C++/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md)