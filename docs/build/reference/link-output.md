---
title: "Sa&#237;da LINK | Microsoft Docs"
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
  - "link"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Arquivos .ilk"
  - "DLLs [C++], como saída de vinculador"
  - "arquivos executáveis [C++], como saída de vinculador"
  - "Arquivos  [C++], LINK"
  - "arquivos ILK"
  - "importar bibliotecas [C++], criando"
  - "ferramenta LINK [C++], arquivo de mapa"
  - "ferramenta LINK [C++], saída"
  - "vinculador [C++], arquivos de saída"
  - "arquivos de mapa [C++]"
  - "arquivos de mapa [C++], saída LINK"
  - "arquivos de saída [C++], vinculador"
ms.assetid: a98b557c-1947-447a-be1f-616fb45a9580
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sa&#237;da LINK
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A saída do link incluem arquivos, DLL, mapfiles, e mensagens de .exe.  
  
##  <a name="_core_output_files"></a> Arquivos de saída  
 O arquivo de saída padrão de LINK é um arquivo .exe.  Se a opção de [\/DLL](../../build/reference/dll-build-a-dll.md) for especificada, o LINK criar um arquivo .dll.  Você pode controlar o nome do arquivo de saída com a opção de [Nome do arquivo de saída \(\/OUT\)](../../build/reference/out-output-file-name.md) .  
  
 No modo incremental, o LINK cria um arquivo de .ilk a informações de status de suspensão para as construções incrementais posteriores do programa.  Para obter detalhes sobre arquivos de .ilk, consulte [arquivos de .ilk](../../build/reference/dot-ilk-files-as-linker-input.md).  Para obter mais informações sobre como vincular incremental, consulte a opção de [Vincular incremental \(\/INCREMENTAL\)](../../build/reference/incremental-link-incrementally.md) .  
  
 Quando o LINK criar um programa que contém a exportações \(normalmente uma DLL\), o também cria um arquivo de .lib, a menos que um arquivo de .exp é usado na compilação.  Você pode controlar o nome do arquivo de biblioteca de importação com a opção de [\/IMPLIB](../Topic/-IMPLIB%20\(Name%20Import%20Library\).md) .  
  
 Se a opção de [Gerencia Mapfile \(\/MAP\)](../../build/reference/map-generate-mapfile.md) for especificada, o LINK cria um mapfile.  
  
 Se a opção de [Gerencia as informações de depuração \(\/DEBUG\)](../../build/reference/debug-generate-debug-info.md) for especificada, o cria um LINK PDB para conter informações de depuração para o programa.  
  
##  <a name="_core_other_output"></a> Outras saída  
 Quando você digita `link` sem nenhuma outra entrada da linha de comando, o LINK exibe uma instrução de uso que resume as opções.  
  
 O LINK exibe uma mensagem de direitos autorais e da versão e a entrada de comando\- Arquivo de duplica, a menos que a opção de [Suprima a faixa de inicialização \(\/NOLOGO\)](../../build/reference/nologo-suppress-startup-banner-linker.md) é usada.  
  
 Você pode usar a opção de [Mensagens de progresso de impressão \(\/VERBOSE\)](../../build/reference/verbose-print-progress-messages.md) exibir detalhes adicionais sobre a construção.  
  
 LINK emite o erro e mensagens de aviso no formato LNK*nnnn*.  Esses prefixo de erro e intervalo de números também são usadas pelo LIB, por DUMPBIN, e por EDITBIN.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)