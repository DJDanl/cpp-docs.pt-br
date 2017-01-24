---
title: "longjmp | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "longjmp"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "longjmp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função longjmp"
  - "restaurando o ambiente da pilha e a localidade de execução"
ms.assetid: 0e13670a-5130-45c1-ad69-6862505b7a2f
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# longjmp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Ambiente de pilha e restaurações localidade de execução.  
  
## Sintaxe  
  
```  
  
      void longjmp(  
   jmp_buf env,  
   int value   
);  
```  
  
#### Parâmetros  
 `env`  
 Variável na qual o ambiente é armazenado.  
  
 *valor*  
 Valor a ser retornado na chamada de `setjmp` .  
  
## Comentários  
 A função de `longjmp` restaurar uma localidade de ambiente e execução de pilha salva anteriormente em `env` por `setjmp`.  `setjmp` e `longjmp` fornecem um modo de executar `goto`nonlocal; normalmente são usados para transmitir o controle de execução para o código de tratamento de erro ou de recuperação em uma rotina anteriormente chamado sem usar as convenções normais de chamada e as de retorno.  
  
 Uma chamada para `setjmp` faz com que o ambiente atual da pilha a ser salvo em `env`.  Uma chamada subsequente a `longjmp` restaura o controle ao ambiente e retorna o ponto imediatamente depois da chamada de `setjmp` correspondente.  Resumos de execução como se tivesse sido *o valor* retornado apenas pela chamada de `setjmp` .  Os valores de todas as variáveis \(exceto variáveis do registro\) que é acessível ao controle pull rotina contêm os valores que tinham `longjmp` quando foi chamado.  Os valores de variáveis do registro serão imprevisíveis.  O valor retornado por `setjmp` deve ser diferente de zero.  Se *o valor* é passado como 0, o valor 1 será substituído no retorno real.  
  
 Chame `longjmp` antes da função que retorna `setjmp` chamado; se os resultados não são imprevisíveis.  
  
 Observe as seguintes limitações ao usar `longjmp`:  
  
-   Não suponha que os valores de variáveis do registro permanecerá os mesmos.  Os valores de variáveis do registro em `setjmp` chamando rotina não podem ser restaurados os valores apropriados após `longjmp` é executado.  
  
-   Não use `longjmp` ao controle de transferência fora de uma rotina de manipulação interrupção\- a menos que a interrupção é causada por uma exceção de ponto flutuante.  Nesse caso, um programa pode retornar de um manipulador de interrupção através de `longjmp` se reinicializa primeiro o pacote de matemática de ponto flutuante chamando `_fpreset`.  
  
     **Note** tenha cuidado ao usar `setjmp` e `longjmp` em programas C\+\+.  Como essas funções não oferecem suporte à semântica do objeto C\+\+, é mais seguro usar o mecanismo de controle de exceções das linguagens C\+\+.  
  
 Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`longjmp`|\<setjmp.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 Consulte o exemplo de [\_fpreset](../../c-runtime-library/reference/fpreset.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [setjmp](../../c-runtime-library/reference/setjmp.md)