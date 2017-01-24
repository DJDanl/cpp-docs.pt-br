---
title: "Usando wmain em vez main | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "wmain"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função main, vs. wmain"
  - "função wmain"
ms.assetid: 7abb1257-b85c-413a-b913-d45b1582a71d
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando wmain em vez main
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 No modelo de programação Unicode, você pode definir uma versão de caractere largo da função **main**.  Use **wmain** em vez de **main** se quiser escrever um código portátil que obedeça à especificação Unicode.  
  
 Você declara parâmetros formais para **wmain** usando um formato semelhante ao de **main**.  Em seguida, pode passar argumentos de caractere largo e, opcionalmente, um ponteiro de ambiente de caractere largo para o programa.  Os parâmetros `argv` e `envp` de **wmain** são do tipo `wchar_t*`.  
  
 Caso o seu programa use uma função **main**, o ambiente de caractere multibyte será criado pelo sistema operacional na inicialização do programa.  Uma cópia de caractere largo do ambiente será criada apenas quando necessário \(por exemplo, por uma chamada para as funções [\_wgetenv](../c-runtime-library/reference/getenv-wgetenv.md) ou [\_wputenv](../c-runtime-library/reference/putenv-wputenv.md)\).  Na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv` se um ambiente MBCS já existir, um ambiente correspondente de cadeia de caracteres largos será criado. Em seguida, a variável global `_wenviron`, uma versão de caractere largo da variável global `_environ`, apontará para esse ambiente.  Nesse momento, duas cópias do ambiente \(MBCS e Unicode\) existirão simultaneamente e serão mantidas pelo sistema operacional durante toda a vida do programa.  
  
 Da mesma forma, caso o seu programa use uma função **wmain**, um ambiente MBCS \(ASCII\) será criado na primeira chamada para `_putenv` ou `getenv`, e a variável global `_environ` apontará para ele.  
  
 Para obter mais informações sobre o ambiente MBCS, consulte o tópico sobre [conjuntos de caracteres de um byte e multibyte](../c-runtime-library/single-byte-and-multibyte-character-sets.md) na *Referência da biblioteca em tempo de execução*.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [main: inicialização do programa](../Topic/main:%20Program%20Startup.md)