---
title: "Sintaxe da linha de comando do compilador | Microsoft Docs"
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
  - "Compilador cl.exe, sintaxe de linha de comando"
  - "sintaxe, linha de comando do compilador CL"
ms.assetid: acba2c1c-0803-4a3a-af25-63e849b930a2
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Sintaxe da linha de comando do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A linha de comando de CL use a seguinte sintaxe:  
  
```  
CL [option...] file... [option | file]... [lib...] [@command-file] [/link link-opt...]  
```  
  
 A tabela a seguir descreve a entrada para o comando de CL.  
  
|Entrada|Significado|  
|-------------|-----------------|  
|*opção*|Um ou mais [Opções de CL](../../build/reference/compiler-options.md).  Observe que todas as opções se aplicam a todos os arquivos de origem especificado.  As opções são especificadas por uma barra \(\/\) ou por um traço \(–\).  Se uma opção usa um argumento, a descrição da opção documenta se um espaço é permitido entre a opção e os argumentos.  Os nomes da opção \(exceto a opção \/HELP\) diferenciam maiúsculas de minúsculas.  Consulte [Ordem de opções de CL](../../build/reference/order-of-cl-options.md) para obter mais informações.|  
|`file`|O nome de um ou mais arquivos de origem, arquivos de .obj, ou de bibliotecas.  CL O cria arquivos de origem e transfere os nomes dos arquivos e de bibliotecas de .obj ao vinculador.  Consulte [Sintaxe do nome de arquivo do CL](../../build/reference/cl-filename-syntax.md) para obter mais informações.|  
|*biblioteca*|Um ou mais nomes de biblioteca.  O CL passa esses nomes ao vinculador.|  
|*comando\-Arquivo*|Um arquivo que contém várias opções e nomes de arquivo.  Consulte [Arquivos de comando de CL](../../build/reference/cl-command-files.md) para obter mais informações.|  
|*aceitar link\-*|Um ou mais [opções do vinculador](../../build/reference/linker-options.md).  Essas opções CL O passa para o vinculador.|  
  
 Você pode especificar qualquer número de opções, nomes de arquivo, e os nomes de biblioteca, como o número de caracteres na linha de comando que não exceda 1024, o limite determinadas pelo sistema operacional.  
  
 Para obter informações sobre o valor de retorno de cl.exe, consulte [Valor de retorno de cl.exe](../../build/reference/return-value-of-cl-exe.md) .  
  
> [!NOTE]
>  O limite de entrada da linha de comando de 1024 caracteres não há garantia de que o mesmo em versões futuras do windows.  
  
## Consulte também  
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)