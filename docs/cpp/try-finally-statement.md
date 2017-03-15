---
title: "Instru&#231;&#227;o try-finally | Microsoft Docs"
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
  - "__try"
  - "__leave_cpp"
  - "__leave"
  - "__finally_cpp"
  - "__try_cpp"
  - "__finally"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __try [C++]"
  - "Palavra-chave __finally [C++]"
  - "Palavra-chave __leave [C++]"
  - "try-finally palavra-chave try-catch-chave [C++]"
  - "palavra-chave try-finally [C++]"
  - "Finally palavra-chave [C++], sintaxe de instrução try-finally"
  - "Leave palavra-chave [C++], instrução try-finally"
  - "tratamento estruturado de exceções, try-finally"
ms.assetid: 826e0347-ddfe-4f6e-a7bc-0398e0edc7c2
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o try-finally
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A sintaxe a seguir descreve o `try-finally` instrução:  
  
```  
__try {  
   // guarded code  
}  
__finally {  
   // termination code  
}  
```  
  
## Gramática  
 *try\-finally\-statement*:  
 `__try` *instrução composta*  
  
 `__finally` *instrução composta*  
  
 O `try-finally` instrução é uma extensão da Microsoft para as linguagens C e C\+\+ que permite que aplicativos de destino garantir a execução do código de limpeza quando a execução de um bloco de código é interrompida. Limpeza consiste em tarefas como desalocar memória, fechar arquivos e liberar identificadores de arquivos. O `try-finally` instrução é especialmente útil para rotinas que têm vários locais em que é feita uma verificação para um erro que poderia causar prematura retornam da rotina.  
  
 Para obter informações relacionadas e um exemplo de código, consulte [try\-except instrução](../cpp/try-except-statement.md). Para obter mais informações em geral de manipulação de exceção estruturada, consulte [Structured Exception Handling](../cpp/structured-exception-handling-c-cpp.md). Para obter mais informações sobre o tratamento de exceções em aplicativos gerenciados, consulte [tratamento de exceções em \/clr](../windows/exception-handling-cpp-component-extensions.md).  
  
> [!NOTE]
>  Exceção estruturada funciona com Win32 o tratamento de arquivos de origem de C e C\+\+. No entanto, ele não é especificamente projetado para C\+\+. Você pode garantir que seu código seja mais portátil usando o tratamento de exceções C\+\+. Além disso, o tratamento de exceções C\+\+ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas C\+\+, é recomendável que você use o mecanismo de tratamento de exceções C\+\+ \([try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) instruções\).  
  
 A instrução composta após a `__try` cláusula é a seção protegida. A instrução composta após a `__finally` cláusula é o manipulador de término. O manipulador Especifica um conjunto de ações que são executadas quando a seção protegida é finalizada, independentemente se a seção protegida ser realizada por uma exceção \(término anormal\) ou por queda padrão \(encerramento normal\).  
  
 Controle atinge um `__try` instrução execução sequencial simples \(queda\). Quando o controle entra o `__try`, seu manipulador associado fica ativo. Se o fluxo de controle atinge o final do bloco try, a execução procede da seguinte maneira:  
  
1.  O manipulador de término é invocado.  
  
2.  Quando o manipulador de término é concluído, a execução continua após o `__finally` instrução. Independentemente de como a seção protegida é encerrada \(por exemplo, via um `goto` fora do corpo protegido ou uma `return` instrução\), o manipulador de término é executado `before` o fluxo de controle sai da seção protegida.  
  
     Um **Finally** instrução não bloqueia a procura por um manipulador de exceção apropriado.  
  
 Se ocorrer uma exceção no `__try` bloco, o sistema operacional deve localizar um manipulador para a exceção ou o programa falhará. Se um manipulador for encontrado, todas os `__finally` blocos são executados e a execução é retomada no manipulador.  
  
 Por exemplo, suponha que uma série de chamadas de função vincula a função à função D, conforme mostrado na figura a seguir. Cada função tem um manipulador de encerramento. Se uma exceção é gerada na função D e tratada em um, os manipuladores de encerramento são chamados nessa ordem como o sistema desenrola a pilha: D, C, b  
  
 ![Encerramento de ordem de execução do manipulador](../cpp/media/vc38cx1.png "vc38CX1")  
Ordem de execução do manipulador de término  
  
> [!NOTE]
>  O comportamento de try\-finally é diferente de outras linguagens que suportam o uso do **Finalmente**, como c\#.  Um único `__try` pode ter, mas não ambos, de `__finally` e `__except`.  Se ambos devem ser usados em conjunto, um bloco try\-exceto a instrução deve incluir a instrução interna try\-finally.  As regras que especificam quando cada bloco é executado também são diferentes.  
  
## A palavra\-chave Leave  
 O `__leave` palavra\-chave é válido somente dentro da seção protegida de um `try-finally` instrução e seu efeito é ir para o fim da seção protegida. A execução continua na primeira instrução no manipulador de término.  
  
 Um `goto` instrução também pode sair da seção protegida, mas degrada o desempenho porque invoca o desenrolamento de pilha. O `__leave` instrução é mais eficiente porque não causa o desenrolamento de pilha.  
  
## Encerramento anormal  
 Saindo de um `try-finally` instrução usando o [longjmp](../c-runtime-library/reference/longjmp.md) função de tempo de execução é considerada um encerramento anormal. Não é possível entrar em um `__try` instrução, mas legal para sair de uma. Todos os `__finally` instruções ativas entre o ponto de partida \(encerramento normal do `__try` bloco\) e o destino \(o `__except` bloco que lida com a exceção\) deve ser executado. Isso se chama desenrolamento local.  
  
 Se um **tente** bloco é encerrado prematuramente por qualquer motivo, incluindo a saída do bloco, o sistema executa associado **Finalmente** bloco como parte do processo de desenrolamento de pilha. Nesses casos, o [AbnormalTermination](http://msdn.microsoft.com/library/windows/desktop/ms679265) função retorna TRUE se chamada dentro de **Finalmente** bloco; caso contrário, retornará FALSE.  
  
 O manipulador de término não é chamado se um processo for interrompido no meio da execução um `try-finally` instrução.  
  
 **FIM de específico da Microsoft**  
  
## Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Sintaxe do manipulador de término](http://msdn.microsoft.com/library/windows/desktop/ms681393)