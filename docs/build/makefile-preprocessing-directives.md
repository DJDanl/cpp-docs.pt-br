---
title: "Diretivas de pr&#233;-processamento de makefile | Microsoft Docs"
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
  - "!UNDEF"
  - "!INCLUDE"
  - "!IFNDEF"
  - "!MESSAGE"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Diretiva !CMDSWITCHES"
  - "Diretiva !ELSE"
  - "Diretiva !ELSEIF"
  - "Diretiva !ELSEIFDEF"
  - "Diretiva !ELSEIFNDEF"
  - "Diretiva !ENDIF"
  - "Diretiva !ERROR"
  - "Diretiva !IF"
  - "Diretiva !IFDEF"
  - "Diretiva !IFNDEF"
  - "Diretiva !INCLUDE"
  - "Diretiva !MESSAGE"
  - "Diretiva !UNDEF"
  - "diretiva CMDSWITCHES"
  - "Diretivas (), pré-processamento de makefile"
  - "diretiva ELSE"
  - "diretiva ELSEIF"
  - "diretiva ELSEIFDEF"
  - "diretiva ELSEIFNDEF"
  - "diretiva ENDIF"
  - "diretiva ERROR"
  - "diretiva IF"
  - "diretiva IFDEF"
  - "diretiva IFNDEF"
  - "diretiva INCLUDE"
  - "makefiles, pré-processando diretivas"
  - "diretiva MESSAGE"
  - "programa NMAKE, expressões"
  - "programa NMAKE, diretivas de pré-processador"
  - "pré-processando diretivas, makefiles"
  - "diretiva UNDEF"
ms.assetid: bcedeccb-d981-469d-b9e8-ab5d097fd8c2
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Diretivas de pr&#233;-processamento de makefile
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As políticas de pré\-processamento não diferenciam maiúsculas de minúsculas.  O ponto inicial de exclamação \(\!\) deve aparecer no início da linha.  Zero ou mais espaços ou guias podem aparecer após o ponto de exclamação, para recuo.  
  
 **\!CMDSWITCHES**  
 {**\+**&#124; *opção de***–**}…  Gerencie cada ON ou OFF listado *opção* .  Espaços ou guias devem aparecer antes do operador \+ ou \-; nenhum podem aparecer entre o operador e o [letras da opção](../Topic/NMAKE%20Options.md).  As letras não diferenciam maiúsculas de minúsculas e são especificadas sem uma barra \(\/\).  Para ativar algumas opções e outro fora do, use especificações separadas de **\!CMDSWITCHES**.  
  
 Somente \/D, \/I, \/N, \/S e podem ser usados em um makefile.  Em Tools.ini, todas as opções são permitidas exceto \/F, \/HELP, \/NOLOGO, \/X, e.?\/  As alterações especificadas em um bloco de descrição não entram em vigor até o bloco seguir a descrição.  Essa política atualiza **MAKEFLAGS**; as alterações são herdadas durante a recursão **MAKEFLAGS** se for especificado.  
  
 *texto de* **\!ERRO**  
 Exibe *o texto* do erro U1050, então é interrompida NMAKE, mesmo se \/K, \/I, **.IGNORE**, **\!CMDSWITCHES**, ou o modificador de comando de traço \(–\) são usados.  Espaços ou guias antes *de texto* são ignorados.  
  
 *texto de* **\!MENSAGEM**  
 Exibe o *texto* para a saída padrão.  Espaços ou guias antes *de texto* são ignorados.  
  
 *nome do arquivo*de**\!INCLUDE\<**\[\] \[ **\>**\]  
 Lê *o nome de arquivo* como um makefile, então continua com o makefile atual.  NMAKE procurar pelo *nome do primeiro arquivo* no diretório especificado ou atual, então recursivamente pelos diretórios de todos os makefiles pai, então, se *o nome do arquivo* está incluído por colchetes angulares \(\< \>\), nos diretórios especificados pela macro de **INCLUDE** , que é definido inicialmente a variável de ambiente INCLUDE.  Útil passar configurações de **.SUFFIXES** , **.PRECIOUS**, e regras de inferência a makefiles recursivos.  
  
 **\!IF**  `constantexpression`  
 Instruções de processos entre **\!IF** e **\!ELSE** próximo ou `!ENDIF` se `constantexpression` é avaliada como um valor diferente de zero.  
  
 *macroname de* **\!IFDEF**  
 Instruções de processos entre `!IFDEF` e **\!ELSE** próximo ou `!ENDIF` se *o macroname* é definido.  Uma macro nulo é considerado ser definido.  
  
 *macroname de* **\!IFNDEF**  
 Instruções de processos entre **\!IFNDEF** e **\!ELSE** próximo ou `!ENDIF` se *o macroname* não é definido.  
  
 **\!ELSE**\[*constantexpression de* **IF** &#124;*Macroname de***IFDEF** &#124;*Macroname de***IFNDEF** \]  
 Instruções de processos entre **\!ELSE** e `!ENDIF` seguir se **\!IF**anterior, `!IFDEF`, ou instrução de **\!IFNDEF** avaliada como zero.  As palavras\-chave opcionais especificam um controle adicional de pré\-processamento.  
  
 **\!ELSEIF**  
 Sinônimo para **\!ELSE IF**.  
  
 **\!ELSEIFDEF**  
 Sinônimo para **\!ELSE IFDEF**.  
  
 **\!ELSEIFNDEF**  
 Sinônimo para **\!ELSE IFNDEF**.  
  
 `!ENDIF`  
 Marca o fim de **\!IF**, de `!IFDEF`, ou do bloco de **\!IFNDEF** .  Todo o texto depois de `!ENDIF` na mesma linha é ignorado.  
  
 *macroname de* **\!UNDEF**  
 Undefines o *macroname*.  
  
## Consulte também  
 [Pré\-processamento de makefile](../Topic/Makefile%20Preprocessing.md)