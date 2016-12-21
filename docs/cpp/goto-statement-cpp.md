---
title: "Instru&#231;&#227;o goto (C++) | Microsoft Docs"
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
  - "goto_cpp"
  - "goto"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave goto [C++]"
ms.assetid: 724c5deb-2de1-42d8-8ef1-23589d9bf5ed
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o goto (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A instrução `goto` transfere o controle incondicionalmente para a instrução rotulada pelo identificador especificado.  
  
## Sintaxe  
  
```  
goto identifier;  
```  
  
## Comentários  
 A instrução rotulada designada por `identifier` deve estar na função atual.  Todos os nomes de `identifier` são membros de um namespace interno e, portanto, não interferem em outros identificadores.  
  
 Os rótulos de instrução são significativos apenas para uma instrução `goto`; caso contrário, são ignorados.  Os rótulos não podem ser redeclarados.  
  
 É um bom estilo de programação usar as instruções `break`, `continue` e `return` em vez da instrução `goto` sempre que possível.  No entanto, como a instrução `break` sai apenas de um nível de um loop, você pode ter que usar uma instrução `goto` para sair de um loop profundamente aninhado.  
  
 Para obter mais informações sobre rótulos e a instrução `goto`, consulte [Instruções rotuladas](../cpp/labeled-statements.md) e [Usando rótulos com a instrução goto](http://msdn.microsoft.com/pt-br/6cd7c31a-9822-4241-8566-f79f51be48fe).  
  
## Exemplo  
 Neste exemplo, um `goto` instrução transfere o controle para o ponto de rotulado `stop` quando `i` é igual a 3.  
  
```  
// goto_statement.cpp  
#include <stdio.h>  
int main()  
{  
    int i, j;  
  
    for ( i = 0; i < 10; i++ )  
    {  
        printf_s( "Outer loop executing. i = %d\n", i );  
        for ( j = 0; j < 2; j++ )  
        {  
            printf_s( " Inner loop executing. j = %d\n", j );  
            if ( i == 3 )  
                goto stop;  
        }  
    }  
  
    // This message does not print:   
    printf_s( "Loop exited. i = %d\n", i );  
  
    stop:   
    printf_s( "Jumped to stop. i = %d\n", i );  
}  
```  
  
  **Executando o loop externo.  i \= 0**  
 **Loop interno em execução.  j \= 0**  
 **Loop interno em execução.  j \= 1**  
**Executando o loop externo.  i \= 1**  
 **Loop interno em execução.  j \= 0**  
 **Loop interno em execução.  j \= 1**  
**Executando o loop externo.  Eu \= 2**  
 **Loop interno em execução.  j \= 0**  
 **Loop interno em execução.  j \= 1**  
**Executando o loop externo.  i \= 3**  
 **Loop interno em execução.  j \= 0**  
**Necessária para parar.  i \= 3**    
## Consulte também  
 [Instruções de salto](../cpp/jump-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)