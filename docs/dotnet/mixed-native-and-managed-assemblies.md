---
title: Assemblies mistos (nativos e gerenciados)
ms.date: 09/18/2018
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
ms.openlocfilehash: 11bdfc98c64b2612129e10c002c68ee243bec7da
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311621"
---
# <a name="mixed-native-and-managed-assemblies"></a>Assemblies mistos (nativos e gerenciados)

Os assemblies mistos são capazes de conter instruções de máquina não gerenciadas e instruções MSIL. Isso permite que eles chamem e sejam chamados por componentes do .NET, mantendo a compatibilidade com C++ bibliotecas nativas. Usando assemblies mistos, os desenvolvedores podem criar aplicativos usando uma combinação de .NET C++ e código nativo.

Por exemplo, uma biblioteca existente que consiste inteiramente em código C++ nativo pode ser trazida para a plataforma .net recompilando apenas um módulo com a opção de compilador **/CLR** . Esse módulo é então capaz de usar os recursos do .NET, mas permanece compatível com o restante do aplicativo. É possível decidir até mesmo entre a compilação gerenciada e a nativa em uma base função a função dentro do mesmo arquivo (consulte [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md)).

O C++ Visual dá suporte apenas à geração de assemblies gerenciados mistos usando a opção de compilador **/CLR** . As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017. Se você precisar de assemblies gerenciados puros ou verificáveis, recomendamos criá- C#los usando o.

As versões anteriores do conjunto C++ de ferramentas de compilador da Microsoft suportavam a geração de três tipos distintos de assemblies gerenciados: misto, puro e verificável. Os dois últimos são discutidos em [código puro e verificávelC++(/CLI)](../dotnet/pure-and-verifiable-code-cpp-cli.md).

## <a name="in-this-section"></a>Nesta seção

[Como: Migrar para/CLR](../dotnet/how-to-migrate-to-clr.md)<br/>
Descreve as etapas recomendadas para introduzir ou atualizar a funcionalidade do .NET em seu aplicativo.

[Como: Compilar o MFC e o código ATL usando o/CLR](../dotnet/how-to-compile-mfc-and-atl-code-by-using-clr.md)<br/>
Discute como compilar os programas MFC e ATL existentes para direcionar o Common Language Runtime.

[Inicialização de assemblies mistos](../dotnet/initialization-of-mixed-assemblies.md)<br/>
Descreve o problema e as soluções de "bloqueio de carregador".

[Suporte de biblioteca para assemblies mistos](../dotnet/library-support-for-mixed-assemblies.md)<br/>
Discute como usar bibliotecas nativas em compilações **/CLR** .

[Considerações sobre desempenho](../dotnet/performance-considerations-for-interop-cpp.md)<br/>
Descreve as implicações de desempenho de assemblies mistos e marshaling de dados.

[Domínios de aplicativo e Visual C++](../dotnet/application-domains-and-visual-cpp.md)<br/>
Discute o suporte C++ Visual para domínios de aplicativo.

[Conversão dupla](../dotnet/double-thunking-cpp.md)<br/>
Discute as implicações de desempenho de um ponto de entrada nativo para uma função gerenciada.

[Evitando exceções no desligamento CLR ao consumir objetos COM criados com/CLR](../dotnet/avoiding-exceptions-on-clr-shutdown-when-consuming-com-objects-built-with-clr.md)<br/>
Discute como garantir o desligamento apropriado de um aplicativo gerenciado que consome um objeto COM compilado com **/CLR**.

[Como: criar um aplicativo parcialmente confiável, removendo a dependência da DLL da biblioteca CRT](../dotnet/create-a-partially-trusted-application.md)<br/>
Discute como criar um aplicativo de tempo de execução de linguagem comum parcialmente confiável C++ usando Visual Removendo dependência em msvcm90. dll.

Para obter mais informações sobre as diretrizes de codificação para assemblies mistos, consulte o artigo do MSDN [uma visão geral da interoperabilidade de código gerenciado/não](/previous-versions/dotnet/articles/ms973872(v=msdn.10))gerenciado.

## <a name="see-also"></a>Consulte também

- [Interoperabilidade entre .NET e nativo](../dotnet/native-and-dotnet-interoperability.md)
