---
title: "C&#243;digo puro e verific&#225;vel (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - ".NET Framework [C++], código puro e verificável"
  - "Opção de compilador /clr [C++], assemblies mistos"
  - "Opção de compilador /clr [C++], assemblies puros"
  - "Opção de compilador /clr [C++], assemblies verificáveis"
  - "assemblies [C++], código misto"
  - "assemblies [C++], código puro"
  - "assemblies [C++], código verificável"
  - "assemblies mistos [C++]"
  - "assemblies mistos [C++], sobre assemblies mistos"
  - "MSIL puro [C++]"
  - "MSIL puro [C++], sobre código puro"
  - "assemblies verificáveis [C++]"
  - "assemblies verificáveis [C++], sobre assemblies verificáveis"
  - "código fortemente tipado verificável [C++]"
ms.assetid: 9050e110-fa11-4356-b56c-665187ff871c
caps.latest.revision: 31
caps.handback.revision: 31
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# C&#243;digo puro e verific&#225;vel (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para programação .NET, Visual C\+\+ da suporte à criação dos três tipos distintos de componentes e de aplicativos: misto, puro, e verificável.  Todos os três estão disponíveis com a opção do compilador de [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md) .  
  
## Comentários  
 Para obter mais informações sobre assemblies verificáveis, consulte:  
  
-   [Comparação de recursos mistos, puros e verificáveis](../dotnet/mixed-pure-and-verifiable-feature-comparison-cpp-cli.md)  
  
-   [Como migrar para \/clr:pure](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md)  
  
-   [Como criar projetos C\+\+ verificáveis](../dotnet/how-to-create-verifiable-cpp-projects-cpp-cli.md)  
  
-   [Como migrar para \/clr:safe](../dotnet/how-to-migrate-to-clr-safe-cpp-cli.md)  
  
-   [Usando assemblies verificáveis com SQL Server \(C\+\+\/CLI\)](../Topic/Using%20Verifiable%20Assemblies%20with%20SQL%20Server%20\(C++-CLI\).md)  
  
-   [Práticas recomendadas de segurança](../top/security-best-practices-for-cpp.md)  
  
-   [Convertendo projetos do modo misto em linguagem intermediária pura](../dotnet/converting-projects-from-mixed-mode-to-pure-intermediate-language.md)  
  
## Misto \(\/clr\)  
 Os assemblies compilados com **\/clr**mistos \(\), contêm as partes não gerenciado e gerenciados, tornando possível para que usem recursos do .NET, mas ainda contêm código não gerenciado.  Isso permite que os aplicativos e os componentes sejam atualizados para usar os recursos do .NET sem exigir que o projeto inteiro seja recriado.  Usando o Visual C\+\+ gerenciado para mesclar e o código não gerenciado é chamado dessa maneira C\+\+ Interoperabilidade.  Para obter mais informações, consulte [Assemblies mistos \(nativos e gerenciados\)](../Topic/Mixed%20\(Native%20and%20Managed\)%20Assemblies.md) e [Nativo e interoperabilidade .NET](../Topic/Native%20and%20.NET%20Interoperability.md).  
  
## Puro \(\/clr:pure\)  
 Os assemblies compilados com **\/clr:pure**simples \(\) podem conter tipos nativos e de dados gerenciados, mas somente funções gerenciadas.  Como os assemblies mistos, os assemblies permitem puro o interoperabilidade com os DLL nativos com P\/Invoke \(consulte [Usando PInvoke explícito em C\+\+ \(atributo DllImport\)](../dotnet/using-explicit-pinvoke-in-cpp-dllimport-attribute.md)\), mas os recursos de Interoperabilidade C\+\+ não estão disponíveis.  Além disso, os assemblies simples não podem exportar as funções acessíveis a partir das funções nativos como pontos de entrada em um puro uso do assembly [\_\_clrcall](../cpp/clrcall.md) que chama a convenção.  
  
### Vantagens de \/clr:pure  
  
-   Melhor desempenho: Como os assemblies simples contêm apenas MSIL, não há nenhuma função nativos e, consequentemente nenhuma transição gerenciado\/não gerenciado é necessária. \(As chamadas de função feitas com P\/Invoke é uma exceção a essa regra.\)  
  
-   Reconhecimento de Appdomain: As funções gerenciadas e os tipos de dados CLR existem dentro de `Application Domains`, o que afeta sua visibilidade e acessibilidade.  Os assemblies são simples domínio \(atentos que \_\_declspec \([appdomain](../Topic/appdomain.md)\) é indicado para cada tipo\) assim que o acesso a seus tipos e funcionalidade de outros componentes do .NET é mais fácil e mais segura.  No, os assemblies puro interoperam com mais facilidade com outros componentes do .NET que os assemblies mistos.  
  
-   Carga que não seja disco: Os assemblies puros de memória podem ser carregados e passado mesmo.  Isso é essencial para usar assemblies do .NET como procedimentos armazenados.  Isso difere de assemblies mistos, que devido a uma dependência no windows que carregam mecanismos, deve existir no disco para executar.  
  
-   Reflexão: Não é possível refletir sobre executáveis mistos, enquanto os assemblies puro fornecem suporte completo de reflexão.  Para obter mais informações, consulte [Reflexão](../dotnet/reflection-cpp-cli.md).  
  
-   Controllability de host: Como os assemblies simples contêm apenas MSIL, se comportam de maneira previsível e mais flexìvel dos assemblies mistos quando usados em aplicativos que hospedam CLR e alteram o comportamento padrão.  
  
### Restrições de \/clr:pure  
 Essa seção abrange os recursos com suporte não atualmente por **\/clr:pure**.  
  
-   Os assemblies simples não podem ser chamados por funções não gerenciado.  Como consequência os assemblies simples não podem implementar interfaces COM ou retornos de chamada da possibilidade nativo.  Os assemblies simples não podem exportar funções pelo \_\_declspec \(dllexport\) ou dos arquivos de .DEF.  Além disso, as funções declaradas com a convenção de \_\_clrcall não podem ser importadas pelo dllimport \_\_declspec \(\).  As funções em um módulo nativo podem ser chamadas de um assembly puro, mas os assemblies simples não podem expor funções acessíveis nativo, portanto expor a funcionalidade em um assembly puro deve ser feita com as funções gerenciadas em um assembly misto.  Consulte [Como migrar para \/clr:pure](../dotnet/how-to-migrate-to-clr-pure-cpp-cli.md) para maiores informações.  
  
-   As bibliotecas de ATL e de MFC não são suportadas pela compilação pura do modo no Visual C\+\+.  
  
-   .netmodules Simples não são aceitos como entrada para o vinculador Visual C\+\+.  No entanto, arquivos simples de .obj são aceitos pelo vinculador, e os arquivos de .obj contêm um superconjunto de informações contidas em netmodules.  Consulte [Arquivos .netmodule como entrada de vinculador](../Topic/.netmodule%20Files%20as%20Linker%20Input.md) para maiores informações.  
  
-   O suporte do COM o compilador \(\#import\) não é suportado, pois esse introduziria instruções não gerenciada no assembly puro.  
  
-   As opções de ponto flutuante para o alinhamento exceções gerais e a manipulação não são ajustáveis para assemblies puro.  No resultado, \_\_declspec \(alinhar\) não pode ser usado.  Isso renderiza alguns arquivos de cabeçalho, como fpieee.h, incompatível com \/clr:pure.  
  
-   A função de GetLastError em PSDK pode resultar em comportamento indefinido durante a criação com **\/clr:pure**.  
  
## Verificável \(\/clr:safe\)  
 A opção do compilador de **\/clr:safe** gerenciar os assemblies verificáveis, como aquelas gravadas no Visual Basic e no C\#, conformando\-se aos requisitos que permitem que Common Language Runtime \(CLR\) garanta que o código não violar atuais configurações de segurança.  Por exemplo, se as configurações de segurança proíbem um componente de gravação no disco, CLR puder determinar se um componente verificável encontrar esse critério antes de executar um de código.  Não há suporte para os assemblies de CRT verificáveis. \(Suporte de CRT está disponível para assemblies puro por uma versão pura de MSIL da biblioteca de tempo de execução C\).  
  
 Os assemblies verificáveis oferecem essas vantagens sobre assemblies simples e mixed:  
  
-   Segurança emitido.  
  
-   Algumas situações exigem\-na \(componentes do SQL, por exemplo\).  
  
-   As versões futuras do windows requerem cada vez mais componentes e aplicativos ser verificáveis.  
  
 Uma desvantagem é que os recursos de interoperabilidade C\+\+ não estão disponíveis.  Os assemblies verificáveis não podem conter nenhuma função não gerenciado ou tipos de dados nativos, mesmo que elas não sejam referenciadas pelo código gerenciado.  
  
 Independentemente do uso de palavras “segura”, criar aplicativos com **\/clr:safe** não significa que não há bugs; significa que apenas CLR pode verificar as configurações de segurança em tempo de execução.  
  
 Independentemente do tipo de assembly, as chamadas feitas de assemblies gerenciados a DLL nativos via P\/Invoke serão mais, mas podem falhar em tempo de execução dependendo das configurações de segurança.  
  
> [!NOTE]
>  Há um cenário codificando que transmitirão o compilador mas que resultará em um assembly não controlável: chamando uma função virtual por meio de um objeto que usa o operador de resolução de escopo.  Por exemplo: `MyObj -> A::VirtualFunction();`.  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)