---
title: "Instru&#231;&#227;o try-except (C) | Microsoft Docs"
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
  - "__except"
  - "try"
  - "__try"
  - "except"
  - "__except_cpp"
  - "__try_cpp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Palavra-chave __except [C]"
  - "Palavra-chave __except [C], em try-except"
  - "Palavra-chave __try [C]"
  - "tratamento estruturado de exceções, try-except"
  - "palavra-chave try-catch [C]"
  - "palavra-chave try-catch [C], palavra-chave try-except [C]"
  - "palavra-chave try-except [C]"
ms.assetid: f76db9d1-fc78-417f-b71f-18e545fc01c3
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o try-except (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A instrução **try\-except** é uma extensão da Microsoft para a linguagem C que permite que os aplicativos assumam o controle de um programa quando correm eventos que normalmente interrompem a execução.  Esses eventos são denominados exceções, e o mecanismo que lida com exceções é chamado de manipulação de exceção estruturada.  
  
 As exceções podem ser baseadas em hardware ou software.  Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema.  Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.  
  
## Sintaxe  
 *try\-except\-statement*:  
 **\_\_try**  *compound\-statement*  
  
 **\_\_except \(**  *expression*  **\)**  *compound\-statement*  
  
 A instrução composta após a cláusula `__try` é a seção protegida.  A instrução composta após a cláusula `__except` é o manipulador de exceções.  O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução da seção protegida.  A execução procede da seguinte maneira:  
  
1.  A seção protegida é executada.  
  
2.  Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula `__except`.  
  
3.  Se uma exceção ocorrer durante a execução de uma seção protegida ou em qualquer rotina chamada pela seção protegida, a expressão `__except` será avaliada e o valor retornado determinará como a exceção será tratada.  Há três valores:  
  
     `EXCEPTION_CONTINUE_SEARCH` A exceção não é reconhecida.  Continue a procurar manipuladores na pilha, primeiro os que contêm as instruções **try\-except**, depois os que têm a próxima precedência mais alta.  
  
     `EXCEPTION_CONTINUE_EXECUTION` A exceção é reconhecida mas é ignorada.  Continue a execução no ponto onde ocorreu a exceção.  
  
     `EXCEPTION_EXECUTE_HANDLER` A exceção é reconhecida.  Transfere o controle para o manipulador de exceção executando a instrução composta `__except` e continua a execução no ponto de execução da exceção.  
  
 Como a expressão `__except` é avaliada como uma expressão C, ela é limitada a um único valor, o operador de expressão condicional ou ao operador vírgula.  Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.  
  
> [!NOTE]
>  A manipulação de exceção estruturada funciona com arquivos de código\-fonte em C e C\+\+.  No entanto, não é projetada especificamente para C\+\+.  Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C\+\+.  Além disso, o mecanismo de tratamento de exceções de C\+\+ é muito mais flexível, pois pode tratar exceções de qualquer tipo.  
  
> [!NOTE]
>  Para programas C\+\+, o tratamento de exceção de C\+\+ deve ser usado em vez de manipulação de exceção estruturada.  Para obter mais informações, consulte [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md) na *Referência da linguagem C\+\+*.  
  
 Cada rotina em um aplicativo pode ter seu próprio manipulador de exceção.  A expressão `__except` é executada no escopo do corpo de `__try`.  Isso significa que ela tem acesso a todas as variáveis locais declarados lá.  
  
 A palavra\-chave `__leave` é válida dentro de um bloco de instruções **try\-except**.  O efeito de `__leave` é ignorar ao final do bloco de **try\-except**.  A execução é retomada após o término do manipulador de exceção.  Embora uma instrução `goto` possa ser usada para alcançar o mesmo resultado, uma instrução `goto` causa o desenrolar da pilha.  A instrução `__leave` é mais eficiente porque não envolve o desenrolar da pilha.  
  
 Sair de uma instrução **try\-except** usando a função de tempo de execução `longjmp` é considerado um encerramento anormal.  Não é permitido ir para uma instrução `__try`, mas é permitido sair de uma.  O manipulador de exceção não é chamado se um processo for interrompido no meio da execução de uma instrução **try\-except**.  
  
## Exemplo  
 O exemplo a seguir é um manipulador de exceções e um manipulador de término.  Consulte [A instrução try\-final](../c-language/try-finally-statement-c.md) para obter mais informações sobre manipuladores de término.  
  
```  
.  
.  
.  
puts("hello");  
__try{  
   puts("in try");  
   __try{  
      puts("in try");  
      RAISE_AN_EXCEPTION();  
   }__finally{  
      puts("in finally");  
   }  
}__except( puts("in filter"), EXCEPTION_EXECUTE_HANDLER ){  
   puts("in except");  
}  
puts("world");  
```  
  
 Este é o resultado do exemplo, com o comentário adicionado à direita:  
  
```  
hello  
in try              /* fall into try                     */  
in try              /* fall into nested try                */  
in filter           /* execute filter; returns 1 so accept  */  
in finally          /* unwind nested finally                */  
in except           /* transfer control to selected handler */  
world               /* flow out of handler                  */  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Instrução try\-except](../cpp/try-except-statement.md)