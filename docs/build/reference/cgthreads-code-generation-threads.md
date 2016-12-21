---
title: "/cgthreads (threads geradoras de c&#243;digo) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/cgthreads"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opç;ão do compilador /cgthreads (C++)"
  - "cgthreads"
  - "Opç;ão do compilador cgthreads (C++)"
  - "Opç;ão do compilador -cgthreads (C++)"
ms.assetid: 64bc768c-6caa-4baf-9dea-7cfa1ffb01c2
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /cgthreads (threads geradoras de c&#243;digo)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o número de threads cl.exe usados para otimização e geração de código.  
  
## Sintaxe  
  
```  
/cgthreads[1-8]  
```  
  
## Argumentos  
 número  
 O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.  
  
## Comentários  
 A opção **\/cgthreads** especifica o número máximo de threads que o cl.exe usa em paralelo para as fases de otimização e geração de código da compilação.  Observe que não pode haver espaço entre **\/cgthreads** e o argumento `number`.  Por padrão, cl.exe usa quatro threads, como se **\/cgthreads4** fosse especificado.  Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação.  Essa opção é especificamente útil quando combinada a [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md).  
  
 É possível especificar diversos níveis de paralelismo para uma compilação.  O comutador **\/maxcpucount** de msbuild.exe especifica quantos processos MSBuild podem ser executados em paralelo.  O sinalizador do compilador [\/MP \(compilar com vários processos\)](../../build/reference/mp-build-with-multiple-processes.md) especifica quantos processos cl.exe podem compilar os arquivos de origem ao mesmo tempo.  A opção **\/cgthreads** especifica o número de threads usado para cada processo do cl.exe.  Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente.  Para obter mais informações sobre como compilar projetos em paralelo, consulte [Criando vários projetos paralelamente](../Topic/Building%20Multiple%20Projects%20in%20Parallel%20with%20MSBuild.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **Propriedades de Configuração**, **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir **\/cgthreads**`N`, em que `N` é um valor entre 1 e 8 e clique em **OK**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)