---
title: "/FS (For&#231;ar grava&#231;&#245;es PDB s&#237;ncronas) | Microsoft Docs"
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
  - "/FS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador -FS (C++)"
  - "Opção de compilador /FS (C++)"
ms.assetid: b2caaffe-f6e1-4963-b068-648f06b105e0
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /FS (For&#231;ar grava&#231;&#245;es PDB s&#237;ncronas)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Impõe a gravação no base de dados \(PDB\) do programa arquivo criado por [\/Zi](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) ou por [\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md)— a ser serializado com MSPDBSRV.EXE.  
  
## Sintaxe  
  
```  
/FS  
```  
  
## Comentários  
 Por padrão, quando **\/Zi** ou **\/ZI** é especificado, os arquivos PDB de bloqueios do compilador para gravar informações de tipo e informações de depuração do token.  Isso pode reduzir significativamente o tempo que leva o compilador para gerar as informações de tipo quando o número de tipos é grande.  Se outro processo bloqueia temporariamente para o arquivo PDB o exemplo, as gravações por programa de um anti\- vírus pelo compilador podem falhar e um erro fatal poderá ocorrer.  O problema também poderá ocorrer quando várias cópias de cl.exe acessam o arquivo PDB mesmo por exemplo, se sua solução tiver independente os projetos que usam os mesmos diretórios intermediários ou diretórios de saída e construções de paralela estão habilitados.  A opção do compilador de **\/FS** impede que o compilador impede o arquivo PDB e força gravações para atravessar MSPDBSRV.EXE, que serializa o acesso.  Isto pode causar compilações significativamente mais longo, e não evita que todos os erros que podem ocorrer quando várias instâncias de cl.exe acessam o arquivo PDB ao mesmo tempo.  Recomendamos que você altere sua solução de forma que os projetos independentes gravem locais separados intermediários e de saída, ou que você faça um dos projetos dependente no outro para forçar o projeto cria serializado.  
  
 A opção de [\/MP](../../build/reference/mp-build-with-multiple-processes.md) habilita **\/FS** por padrão.  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades **Linha de Comando** .  
  
4.  Modifique a propriedade de **Opções Adicionais** para incluir `/FS` e escolha em **OK**.  
  
### Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)