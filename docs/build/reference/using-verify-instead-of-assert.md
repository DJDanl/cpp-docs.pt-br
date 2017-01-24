---
title: "Usando VERIFY em vez de ASSERT | Microsoft Docs"
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
  - "assert"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "instruções ASSERT"
  - "declarações, depuração"
  - "declarações, instruções ASSERT de solucionando problemas"
  - "depuração [MFC], instruções ASSERT"
  - "declarações de depuração"
  - "macro VERIFY"
ms.assetid: 4c46397b-3fb1-49c1-a09b-41a72fae3797
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Usando VERIFY em vez de ASSERT
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Suponha que quando você executa a versão de depuração do seu aplicativo MFC, não há nenhum problema.  No entanto, a versão lançada do mesmo aplicativo falhar, retornará resultados incorretos, e\/ou exibe algum outro comportamento anormal.  
  
 Esse problema pode ser causado quando você coloca o código importante em uma instrução AFIRMAR para verificar que seja executado corretamente.  Como AFIRMAR as instruções são comentadas out em uma compilação da versão de um programa MFC, o código não executam em uma compilação da versão.  
  
 Se você estiver usando AFIRMAR para confirmar que uma chamada de função teve êxito, considere usar [VERIFY](../Topic/VERIFY.md) em vez disso.  A macro restrição CHECK avalia seus próprios argumentos em construções de depuração e da versão do aplicativo.  
  
 Outra técnica preferida é atribuir o valor de retorno da função a uma variável temporária e depois testar a variável em uma instrução AFIRMAR.  
  
 Examine o seguinte fragmento de código:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
ASSERT(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
 Esse código for executado perfeitamente em uma versão de depuração de um aplicativo de MFC.  Se a chamada a `calloc( )` falhar, uma mensagem de diagnóstico que inclua o arquivo e o número da linha é exibida.  No entanto, em uma compilação de varejo de um aplicativo de MFC:  
  
-   a chamada para `calloc( )` nunca ocorrer, deixando `buf` não inicializadas, ou  
  
-   copia`strcpy_s( )` “`Hello, World`” em uma parte aleatório de memória, possivelmente falhando o aplicativo ou fazendo com que o sistema pare de responder, ou  
  
-   `free()` tenta liberar a memória que nunca foi atribuído.  
  
 Para usar AFIRMAR corretamente, o exemplo de código deve ser alterado para o seguinte:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
buf = (char *) calloc(sizeOfBuffer, sizeof(char) );  
ASSERT( buf != NULL );  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
 Ou, você pode usar VERIFICA em vez de:  
  
```  
enum {  
    sizeOfBuffer = 20  
};  
char *buf;  
VERIFY(buf = (char *) calloc(sizeOfBuffer, sizeof(char) ));  
strcpy_s( buf, sizeOfBuffer, "Hello, World" );  
free( buf );  
```  
  
## Consulte também  
 [Corrigindo problemas de compilação da versão](../../build/reference/fixing-release-build-problems.md)