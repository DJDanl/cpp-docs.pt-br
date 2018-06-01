---
title: Misto (gerenciados e nativos) Assemblies | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- interop [C++], mixed assemblies
- /clr compiler option [C++], mixed assemblies
- managed code [C++], interoperability
- interoperability [C++], mixed assemblies
- mixed DLL loading [C++]
- mixed assemblies [C++], about mixed assemblies
- assemblies [C++], mixed
- mixed assemblies [C++]
- native code [C++], .NET interoperatibility
ms.assetid: 4299dfce-392f-4933-8bf0-5da2f0d1c282
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 469e0429408e1b8afed65889539202650cd28413
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34704783"
---
# <a name="mixed-native-and-managed-assemblies"></a>Assemblies mistos (nativos e gerenciados)

Assemblies mistos são capazes de conter instruções de máquina não gerenciada e instruções da MSIL. Isso permite que eles chamar e ser chamado pelos componentes do .NET, enquanto mantém a compatibilidade com os componentes que não são totalmente gerenciados. Usando assemblies mistos, os desenvolvedores poderão criar aplicativos que usam uma combinação de recursos gerenciados e não gerenciados. Isso torna assemblies mistos ideal para migrar aplicativos existentes do Visual C++ para a plataforma .NET.

Por exemplo, um aplicativo existente que consistam inteiramente de funções não gerenciadas pode ser colocado na plataforma .NET recompilando apenas um módulo com o **/clr** opção de compilador. Esse módulo, em seguida, é possível usar os recursos do .NET, mas permanece compatível com o restante do aplicativo. Dessa forma, um aplicativo pode ser convertido para a plataforma .NET de forma gradual, parte por parte. Também é possível decidir entre gerenciados e compilação em uma base por função de função dentro do mesmo arquivo (consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md)).

Visual C++ só oferece suporte à geração de assemblies gerenciados mistos usando o **/clr** opção de compilador. O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017. Se você precisar de assemblies gerenciados puros ou verificáveis, é recomendável que criá-los usando c#.

A geração de três tipos distintos de assemblies gerenciados com suporte de versões anteriores do conjunto de ferramentas de compilador Visual C++: misto, puro e verificável. O último dois são discutidos em [puro e código verificável (C + + CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md).

## <a name="in-this-section"></a>Nesta seção

[Como: migrar para /clr](../dotnet/how-to-migrate-to-clr.md)<br/>
Descreve as etapas recomendadas para introduzir ou atualizar a funcionalidade do .NET em seu aplicativo.

[Como: compilar MFC e ATL código usando /clr](../dotnet/how-to-compile-mfc-and-atl-code-by-using-clr.md)<br/>
Descreve como compilar os programas existentes MFC e ATL para direcionar o Common Language Runtime.

[Inicialização de assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md)<br/>
Descreve o problema de "bloqueio do carregador" e soluções.

[Suporte de biblioteca para assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)<br/>
Discute como usar bibliotecas nativas em **/clr** compilações.

[Considerações sobre desempenho](../dotnet/performance-considerations-for-interop-cpp.md)<br/>
Descreve as implicações de desempenho de assemblies mistos e realização de marshaling de dados.

[Domínios de aplicativo e Visual C++](../dotnet/application-domains-and-visual-cpp.md)<br/>
Discute o suporte do Visual C++ para domínios de aplicativo.

[Conversão dupla](../dotnet/double-thunking-cpp.md)<br/>
Discute as implicações de desempenho de um ponto de entrada nativo para uma função gerenciada.

[Evitando exceções no CLR desligamento ao consumo dos objetos COM criados com /clr](../dotnet/avoiding-exceptions-on-clr-shutdown-when-consuming-com-objects-built-with-clr.md)<br/>
Discute como obter o desligamento de um aplicativo gerenciado que consome um objeto COM compilado com **/clr**.

[Como criar um aplicativo parcialmente confiável removendo a dependência da DLL da biblioteca CRT](../dotnet/create-a-partially-trusted-application.md)<br/>
Discute como criar um aplicativo de Common Language Runtime parcialmente confiável usando o Visual C++, removendo a dependência no msvcm90.dll.

Para obter mais informações sobre diretrizes de codificação para assemblies mistos, consulte o artigo do MSDN [uma visão geral de gerenciado/não gerenciado interoperabilidade de código](https://msdn.microsoft.com/en-us/library/ms973872.aspx).

## <a name="see-also"></a>Consulte também

- [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)
