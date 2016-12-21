---
title: "Como migrar para /clr:pure (C++/CLI) | Microsoft Docs"
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
  - "Opção de compilador /clr [C++], Migrando para /clr:pure"
  - "migração [C++], MSIL puro"
  - "MSIL puro [C++], movimentando para"
ms.assetid: 5ffb1184-2095-4ade-84aa-4fa6324bc764
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como migrar para /clr:pure (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico discute assuntos provavelmente para ocorrer ao migrar a MSIL puro usando **\/clr:pure** \(consulte [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md) para obter mais informações\).  Este tópico pressupõe que o código que está sendo migrado é seguido atualmente como assembly misto usando a opção de **\/clr** , como o caminho de migração de código não gerenciado a MSIL pure não é direto.  Para código não gerenciado, consulte [Como migrar para \/clr](../dotnet/how-to-migrate-to-clr.md) antes de tentar migrar a MSIL puro.  
  
## Alterações básicas  
 MSIL puro é composto de instruções de MSIL, assim que o código que contém as funções que não podem ser expressas em MSIL impedirá a compilação.  Isso inclui as funções definidas como a utilização de convenções de chamada diferentes de [\_\_clrcall](../cpp/clrcall.md). \(Não as funções de \_\_clrcall podem ser chamadas em um componente puro de MSIL, mas não ser definidas.\)  
  
 Para assegurar que nenhum erro de tempo de execução, você deve habilitar o aviso C4412.  Habilitar C4412 adicionando `#pragma warning (default : 4412)` a cada compiland que você cria com **\/clr:pure** e que transmite tipos de C\+\+ e da IJW \(**\/clr\)** ou código nativo.  Consulte [Aviso do compilador \(nível 2\) C4412](../Topic/Compiler%20Warning%20\(level%202\)%20C4412.md) para maiores informações.  
  
## Considerações arquitetônicas  
 Algumas limitações dos assemblies puros de MSIL listados em [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md) têm implicações de alto nível para a criação do aplicativo e a estratégia de migração.  Especialmente, ao contrário dos assemblies mistos, os assemblies puros de MSIL não apreciam compatibilidade total com módulos não gerenciado.  
  
 Os assemblies puros de MSIL podem chamar funções não gerenciados, mas não podem ser chamados por funções não gerenciado.  No resultado, MSIL puro é um candidato melhor o código de cliente que usa funções não gerenciados do que para o código do servidor usado por funções não gerenciado.  Se a funcionalidade contida em um assembly puro de MSIL deve ser usada por funções não gerenciado, um assembly misto deve ser usado como uma camada da interface.  
  
 Aplicativos que usam ATL ou o MFC não é bons candidatos para a migração a MSIL puro, porque essas bibliotecas não têm suporte nesta versão.  Também, [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)] contém os arquivos de cabeçalho que não criam em **\/clr:pure**.  
  
 Quando os assemblies puros de MSIL podem chamar funções não gerenciado, esse recurso está limitada às funções simples do C \- estilo.  O uso de um APIs não gerenciado mais complexos é provável que requeira uma funcionalidade não gerenciados ser exposto na forma de uma interface COM, ou um assembly do tipo misto que pode atuar como uma interface entre o MSIL puro os componentes e não gerenciado.  Usar uma camada mista de assembly é a única maneira de usar funções não gerenciado que usam funções de retorno de chamada, por exemplo, para um assembly pure não é capaz de fornecer uma função acessível nativo para uso como um retorno de chamada.  
  
## Domínios de aplicativo e convenções de chamada  
 Embora seja possível para assemblies puros de MSIL use a funcionalidade não gerenciado, as funções e os dados estáticos são tratados de modo diferente.  Em assemblies puro, as funções são implementadas com [\_\_clrcall](../cpp/clrcall.md) chamando a convenção, e os dados são estáticos armazenado domínio do aplicativo.  Isso é diferente do padrão para assemblies não gerenciado e mistos, que usam [\_\_cdecl](../Topic/__cdecl.md) que chama a convenção para funções e armazenam dados estáticos em uma base pelo processo.  
  
 Dentro do contexto de puro opções de MSIL \(e código verificável compilado com \/clr:safe\) essas são transparentes, porque [\_\_clrcall](../cpp/clrcall.md) é a convenção chamando padrão de CLR, e os domínios de aplicativo são o escopo nativo para dados estáticos e globais em aplicativos .NET.  No entanto, ao fazer interface com componentes não gerenciado ou mistos, o tratamento de diferentes das funções e os dados globais podem causar problemas.  
  
 Por exemplo, se um componente puro de MSIL deve chamar funções em uma DLL não gerenciado ou misto, um arquivo de cabeçalho para a DLL será usado para criar o assembly puro.  No entanto, a menos que a convenção de chamada para cada função no cabeçalho é declarado explicitamente, serão todas assumido como [\_\_clrcall](../cpp/clrcall.md).  Isso causará posteriormente falhas de tempo de execução, como essas funções são implementadas provavelmente com a convenção de [\_\_cdecl](../Topic/__cdecl.md) .  As funções no arquivo de cabeçalho não gerenciado podem ser marcadas explicitamente como [\_\_cdecl](../Topic/__cdecl.md), ou o código\-fonte inteiro da DLL deve ser recompilado em **\/clr:pure**.  
  
 Da mesma forma, os ponteiros de função são assumidos para apontar para [\_\_clrcall](../cpp/clrcall.md) funções na compilação de **\/clr:pure** .  Eles também deverão ser explicitamente anotados com a convenção correta de chamada.  
  
 Para obter mais informações, consulte [Domínios de aplicativo e Visual C\+\+](../dotnet/application-domains-and-visual-cpp.md).  
  
## Vinculando restrições  
 O vinculador Visual C\+\+ não tentará vincular arquivos combinados e puros de OBJ, porque o escopo de armazenamento e as convenções chamar são diferentes.  
  
## Consulte também  
 [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md)