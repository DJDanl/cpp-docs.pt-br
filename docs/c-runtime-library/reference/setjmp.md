---
title: "setjmp | Microsoft Docs"
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
  - "setjmp"
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
  - "setjmp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "programas [C++], salvando Estados"
  - "estado atual"
  - "Função setjmp"
ms.assetid: 684a8b27-e8eb-455b-b4a8-733ca1cbd7d2
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# setjmp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Salva o estado atual do programa.  
  
## Sintaxe  
  
```  
int setjmp(  
   jmp_buf env   
);  
```  
  
#### Parâmetros  
 `env`  
 Variável na qual o ambiente é armazenado.  
  
## Valor de retorno  
 Retorna 0 depois de salvar o ambiente de pilha.  Se `setjmp` retorna no resultado de uma chamada de `longjmp` , retorna o argumento de `value` de `longjmp`, ou se o argumento de `value` de `longjmp` for 0, retornará 1. `setjmp` de.  Não há nenhum retorno de erro.  
  
## Comentários  
 A função de `setjmp` salva um ambiente da pilha, que você pode restaurar subsequentemente, usando `longjmp`.  Quando usado junto, `setjmp` e `longjmp` fornecem um modo de executar um local não `goto`.  Normalmente são usados para transmitir o controle de execução para o código de tratamento de erro ou de recuperação em uma rotina chamado anteriormente sem usar a chamada normal ou as convenções de retorno.  
  
 Uma chamada para `setjmp` salva o ambiente atual da pilha em `env`.  Uma chamada subsequente a `longjmp` restaura o controle ao ambiente e retorna o ponto imediatamente depois da chamada de `setjmp` correspondente.  Todas as variáveis \(exceto variáveis do registro\) acessíveis ao controle pull rotina contêm os valores que tinham `longjmp` quando foi chamado.  
  
 Não é possível usar `setjmp` para ignorar nativos no código gerenciado.  
  
 **Observação** `setjmp` e `longjmp` não dão suporte a semântica do objeto C\+\+.  Em programas C\+\+, use o mecanismo de controle de exceções das linguagens C\+\+.  
  
 Para obter mais informações, consulte [Usando o setjmp e o longjmp](../../cpp/using-setjmp-longjmp.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`setjmp`|\<setjmp.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
 Consulte o exemplo de [\_fpreset](../../c-runtime-library/reference/fpreset.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [longjmp](../../c-runtime-library/reference/longjmp.md)   
 [\_setjmp3](../../c-runtime-library/setjmp3.md)