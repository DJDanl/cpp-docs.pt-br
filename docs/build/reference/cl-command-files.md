---
title: "Arquivos de comando CL | Microsoft Docs"
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
  - "cl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Compilador cl.exe, arquivos de comando"
  - "arquivos de comando"
  - "arquivos de comando, compilador CL"
ms.assetid: ec3cea06-2af0-4fe9-a94c-119c9d31b3a9
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Arquivos de comando CL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um arquivo de comando é um arquivo de texto que contém opções e nomes de arquivo que você digitaria de outra forma em [linha de comando](../../build/reference/compiler-command-line-syntax.md) ou especificaria usando [Variável de ambiente de CL](../../build/reference/cl-environment-variables.md).  O CL aceita um arquivo de comando do compilador como um argumento de variável de ambiente de CL ou na linha de comando.  Em vez de linha de comando ou da variável de ambiente de CL, um arquivo de comando permite que você use várias linhas de opções e nomes de arquivo.  
  
 As opções e os nomes de arquivo em um arquivo de comando são processados de acordo com o local de um nome de arquivo de comandos dentro da variável de ambiente de CL ou na linha de comando.  No entanto, se a opção \/link aparece no arquivo de comando, todas as opções no restante da linha são passadas ao vinculador.  Opções de linhas subsequentes no arquivo de comando e opções na linha de comando depois que a invocação do arquivo de comando é aceita ainda como opções do compilador.  Para obter mais informações sobre como a ordem de opções afeta a interpretação, consulte [Ordem de opções de CL](../../build/reference/order-of-cl-options.md).  
  
 Um arquivo de comando não deve conter o comando de CL.  Cada opção deverá iniciar e terminar na mesma linha; você não pode usar a barra invertida \(\\\) para combinar uma opção por meio de duas linhas.  
  
 Um arquivo de comando é especificado por um sinal de arroba \(@\) seguido por um nome de arquivo; o nome de arquivo pode especificar um absoluta ou um caminho relativo.  
  
 Por exemplo, se o comando estiver em um arquivo denominado RESP:  
  
```  
/Og /link LIBC.LIB  
```  
  
 e especifique o seguinte comando de CL:  
  
```  
CL /Ob2 @RESP MYAPP.C  
```  
  
 o comando para CL é a seguinte:  
  
```  
CL /Ob2 /Og MYAPP.C /link LIBC.LIB  
```  
  
 Observe que a linha de comando e que comandos de comando\- Arquivo são combinados com eficiência.  
  
## Consulte também  
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)