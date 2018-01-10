---
title: "Código puro e verificável (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "31"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7bcaabb9f0a696a5eb7b01c4bd78757681e4e6a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="pure-and-verifiable-code-ccli"></a>Código puro e verificável (C++/CLI)
Para programação .NET, o Visual C++ oferece suporte à criação de três tipos distintos de aplicativos e componentes: mistos, puros e verificáveis. Todos os três estão disponíveis por meio de [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md) opção de compilador.  
  
## <a name="remarks"></a>Comentários  
 Para obter mais informações sobre assemblies verificáveis, consulte:  
  
-   [Comparação de funcionalidades mistas, puras e verificáveis (C++/CLI)](../dotnet/mixed-pure-and-verifiable-feature-comparison-cpp-cli.md)  
  
-   [Como: migrar para /clr: pure (C + + CLI)](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md)  
  
-   [Como criar projetos C++ verificáveis (C++/CLI)](../dotnet/how-to-create-verifiable-cpp-projects-cpp-cli.md)  
  
-   [Como: migrar para /CLR: Safe (C + + CLI)](../dotnet/how-to-migrate-to-clr-safe-cpp-cli.md)  
  
-   [Usando assemblies verificáveis com SQL Server (C++/CLI)](../dotnet/using-verifiable-assemblies-with-sql-server-cpp-cli.md)  
  
-   [Práticas Recomendadas de segurança](../security/security-best-practices-for-cpp.md)  
  
-   [Convertendo projetos do modo misto em linguagem intermediária pura](../dotnet/converting-projects-from-mixed-mode-to-pure-intermediate-language.md)  
  
## <a name="mixed-clr"></a>Misto (/ clr)  
 Misto assemblies (compilado com **/clr**), contém ambos não gerenciado e gerenciados partes, possibilitando o uso de recursos do .NET, mas ainda contêm código não gerenciado. Isso permite que aplicativos e componentes a serem atualizados para usar recursos do .NET sem a necessidade de que o projeto inteiro ser reescrito. Usando o Visual C++ misturar código gerenciado e, dessa maneira é chamada de interoperabilidade C++. Para obter mais informações, consulte [Assemblies misto (nativo e gerenciado)](../dotnet/mixed-native-and-managed-assemblies.md) e [nativo e interoperabilidade .NET](../dotnet/native-and-dotnet-interoperability.md).  
  
## <a name="pure-clrpure"></a>Puro (/ clr: pure)  
 Assemblies puros (compilado com **/clr: pure**) pode conter ambos os tipos de dados nativos e gerenciados, mas são gerenciados somente funções. Assim como os assemblies mistos, puros assemblies permitem interoperabilidade com DLLs nativas por meio de P/Invoke (consulte [usando PInvoke explícito em C++ (atributo DllImport)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)), mas os recursos de interoperabilidade C++ não estão disponíveis. Além disso, os assemblies puros não é possível exportar funções que podem ser chamadas de funções nativas, pois os pontos de entrada em um assembly puro, use o [clrcall](../cpp/clrcall.md) convenção de chamada.  
  
### <a name="advantages-of-clrpure"></a>Vantagens de /clr: pure  
  
-   Melhor desempenho: Como assemblies puros contêm MSIL somente, não existem funções nativas e, portanto, nenhuma transição gerenciado/não gerenciado é necessárias. (Chamadas de função feitas por meio de P/Invoke são uma exceção a essa regra.)  
  
-   Reconhecimento de AppDomain: Funções gerenciadas e tipos de dados CLR existem dentro de `Application Domains`, que afeta sua acessibilidade e visibilidade. Assemblies puros estão cientes de domínio ( declspec ([appdomain](../cpp/appdomain.md)) indicado para cada tipo) para acessar seus tipos e a funcionalidade de outros componentes do .NET é mais fácil e seguro. Como resultado, assemblies puros mais facilmente interoperam com outros componentes do .NET que assemblies mistos.  
  
-   Carregamento de disco não: assemblies puros podem ser carregados na memória e até mesmo em fluxo. Isso é essencial para o uso de assemblies .NET como procedimentos armazenados. Isso é diferente de assemblies mistos, que, devido a uma dependência no Windows, carregando mecanismos, deve existir no disco para executar.  
  
-   Reflexão: Não é possível refletir sobre executáveis misto, enquanto assemblies puros fornecem suporte completo de reflexão. Para obter mais informações, consulte [reflexão (C + + CLI)](../dotnet/reflection-cpp-cli.md).  
  
-   Host Controllability: Como assemblies puros contêm apenas MSIL, eles se comportam mais previsível e flexível que misto módulos (assemblies) quando usados em aplicativos que hospedam o CLR e modificar seu comportamento padrão.  
  
### <a name="limitations-of-clrpure"></a>Limitações de /clr: pure  
 Esta seção aborda os recursos atualmente não há suportados **/clr: pure**.  
  
-   Assemblies puros não podem ser chamados por funções não gerenciadas. Portanto assemblies puros não podem implementar interfaces COM ou expor retornos de chamada nativos. Assemblies puros não é possível exportar funções por meio de dllexport ou. Arquivos DEF. Além disso, funções declaradas com o \__clrcall convenção não pode ser importada por meio de \__declspec(dllimport). Funções em um módulo nativo podem ser chamadas de um assembly puro, mas assemblies puros não podem expor funções que pode ser chamado nativo, para que expor a funcionalidade em um assembly puro deve ser feito por meio de funções gerenciadas em um conjunto misto. Consulte [como: migrar para /clr: pure (C + + CLI)](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md) para obter mais informações.  
  
-   Não há suporte para bibliotecas ATL e MFC pela compilação de modo simples no Visual C++.  
  
-   . Netmodules puro não são aceitos como entrada para o vinculador do Visual C++. No entanto, arquivos. obj puro são aceitos pelo vinculador, e arquivos. obj contêm um subconjunto das informações contidas no netmodules. Consulte [. netmodule arquivos como entrada de vinculador](../build/reference/netmodule-files-as-linker-input.md) para obter mais informações.  
  
-   Suporte de COM do compilador (#import) não é suportado, porque isso introduziria instruções não gerenciadas no assembly puro.  
  
-   Opções de alinhamento e tratamento de exceções não são ajustáveis para assemblies puros de ponto flutuante. Como resultado, __declspec(align) não pode ser usado. Isso apresenta alguns arquivos de cabeçalho, como fpieee.h, incompatível com /clr: pure.  
  
-   A função GetLastError no PSDK pode dar a um comportamento indefinido ao compilar com **/clr: pure**.  
  
## <a name="verifiable-clrsafe"></a>Verificáveis (/: Safe)  
 O **/CLR: safe** opção de compilador gera assemblies verificáveis, como aqueles escritos em Visual Basic e c#, em conformidade com os requisitos que permitem que o common language runtime (CLR) para garantir que o código não viola atual configurações de segurança. Por exemplo, se as configurações de segurança proíbem um componente de gravação em disco, o CLR pode determinar se um componente verificável atende a esse critério antes de executar qualquer código. Não há nenhum suporte de CRT para assemblies verificáveis. (O suporte de CRT está disponível para assemblies puros através de uma versão de MSIL puro da biblioteca de tempo de execução do C).  
  
 Assemblies verificáveis oferecem estas vantagens sobre assemblies puros e mistos:  
  
-   Aumentar a segurança.  
  
-   Algumas situações exigem (componentes do SQL, por exemplo).  
  
-   Cada vez mais exigirá versões futuras do Windows, componentes e aplicativos a ser verificado.  
  
 Uma desvantagem é que os recursos de interoperabilidade C++ não estão disponíveis. Assemblies verificáveis não podem conter funções não gerenciadas ou tipos de dados nativos, mesmo se eles não são referenciados pelo código gerenciado.  
  
 Apesar do uso da palavra "safe", compilando aplicativos com **/CLR: safe** significa que não há nenhum bugs; significa apenas que o CLR pode verificar as configurações de segurança em tempo de execução.  
  
 Independentemente do tipo de assembly, chamadas de assemblies gerenciados para DLLs nativas por meio de P/Invoke serão compilados, mas podem falhar em tempo de execução dependendo das configurações de segurança.  
  
> [!NOTE]
>  Há um cenário de codificação que passará o compilador, mas que resultará em um assembly não verificado: chamar uma função virtual por meio de uma instância de objeto usando o operador de resolução do escopo.  Por exemplo: `MyObj -> A::VirtualFunction();`.  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)