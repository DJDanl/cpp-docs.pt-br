---
title: "/CGTHREADS (threads compiladoras) | Microsoft Docs"
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
  - "Opç;ão de vinculador /CGTHREADS"
  - "Opç;ão de vinculador CGTHREADS"
  - "Opç;ão de vinculador -CGTHREADS"
ms.assetid: 4b52cfdb-3702-470b-9580-fabeb1417488
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /CGTHREADS (threads compiladoras)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Defina quantos threads cl.exe devem ser usados na otimização e na geração de códigos quando a geração de código vínculo\-tempo for especificada.  
  
## Sintaxe  
  
```  
/CGTHREADS:[1-8]  
```  
  
## Arguments  
 número  
 O máximo de threads que podem ser usados por cl.exe, no intervalo de 1 a 8.  
  
## Comentários  
 A opção **\/CGTHREADS** especifica o máximo de threads usados por cl.exe em paralelo nas fases de otimização e geração de código da compilação quando a geração de código vínculo\-tempo \([\/LTCG](../../build/reference/ltcg-link-time-code-generation.md)\) é especificada.  Por padrão, cl.exe usa quatro threads, como se  fosse especificado.  Se houver mais núcleos de processadores disponíveis, um valor de `number` maior poderá melhorar os tempos de compilação.  
  
 É possível especificar diversos níveis de paralelismo para uma compilação.  O comutador **\/maxcpucount** de msbuild.exe especifica quantos processos MSBuild podem ser executados em paralelo.  O sinalizador do compilador [\/MP \(compilar com vários processos\)](../../build/reference/mp-build-with-multiple-processes.md) especifica quantos processos cl.exe podem compilar os arquivos de origem ao mesmo tempo.  A opção [\/cgthreads](../../build/reference/cgthreads-code-generation-threads.md) do compilador especifica quantos threads são usados para cada processo cl.exe.  Como o processador só pode executar uma quantidade certa de threads ao mesmo tempo devido à presença dos núcleos do processador, especificar valores altos para todas essas opções ao mesmo tempo não é útil e pode ser contraproducente.  Para obter mais informações sobre como compilar projetos em paralelo, consulte [Criando vários projetos paralelamente](../Topic/Building%20Multiple%20Projects%20in%20Parallel%20with%20MSBuild.md).  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **Propriedades de Configuração**, **Vinculador**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modifique a propriedade **Opções Adicionais** para incluir **\/CGTHREADS:**`number`, onde `number` é um valor de 1 a 8 e clique em **OK**.  
  
### Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)