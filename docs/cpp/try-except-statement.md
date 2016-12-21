---
title: "Instru&#231;&#227;o try-except | Microsoft Docs"
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
  - "_abnormal_termination_cpp"
  - "_exception_code_cpp"
  - "EXCEPTION_CONTINUE_SEARCH"
  - "_exception_info"
  - "__except"
  - "EXCEPTION_CONTINUE_EXECUTION"
  - "_exception_code"
  - "__except_cpp"
  - "_exception_info_cpp"
  - "EXCEPTION_EXECUTE_HANDLER"
  - "_abnormal_termination"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __try [C++]"
  - "Palavra-chave _abnormal_termination [C++]"
  - "Palavra-chave _exception_code [C++]"
  - "Palavra-chave _exception_info [C++]"
  - "Macro EXCEPTION_CONTINUE_EXECUTION"
  - "Macro EXCEPTION_CONTINUE_SEARCH"
  - "Macro EXCEPTION_EXECUTE_HANDLER"
  - "Função GetExceptionCode"
  - "palavra-chave try-catch [C++], palavra-chave try-except [C++]"
  - "palavra-chave try-except [C++]"
ms.assetid: 30d60071-ea49-4bfb-a8e6-7a420de66381
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o try-except
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 A sintaxe a seguir descreve a instrução try\-except:  
  
## Sintaxe  
  
```  
  
      __try   
{  
   // guarded code  
}  
__except ( expression )  
{  
   // exception handler code  
}  
```  
  
## Comentários  
 A instrução **try\-except** é uma extensão da Microsoft para as linguagens C e C\+\+ que permite que os aplicativos de destino assumam o controle quando ocorrem eventos que normalmente interrompem a execução do programa.  Esses eventos são denominados exceções, e o mecanismo que lida com exceções é chamado de manipulação de exceção estruturada.  
  
 Para obter informações relacionadas, consulte [instrução try\-finally](../cpp/try-finally-statement.md).  
  
 As exceções podem ser baseadas em hardware ou software.  Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema.  Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.  
  
> [!NOTE]
>  A manipulação de exceção estruturada funciona com Win32 para arquivos de código\-fonte em C e C\+\+.  No entanto, não é projetada especificamente para C\+\+.  Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C\+\+.  Além disso, a manipulação de exceção de C\+\+ é mais flexível, pois pode tratar exceções de qualquer tipo.  Para programas C\+\+, é recomendável usar o mecanismo de manipulação de exceção de C\+\+ \(instruções [try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md)\).  
  
 A instrução composta após a cláusula `__try` é o corpo ou a seção protegida.  A instrução composta após a cláusula `__except` é o manipulador de exceções.  O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução do corpo da seção protegida.  A execução procede da seguinte maneira:  
  
1.  A seção protegida é executada.  
  
2.  Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula `__except`.  
  
3.  Se uma exceção ocorrer durante a execução de uma seção protegida ou em qualquer rotina chamada pela seção protegida, a *expressão* `__except` \(chamada expressão *filter*\) será avaliada e o valor determinará como a exceção será tratada.  Há três valores:  
  
     **EXCEPTION\_CONTINUE\_EXECUTION \(–1\)** A exceção é descartada.  Continue a execução no ponto onde ocorreu a exceção.  
  
     **EXCEPTION\_CONTINUE\_SEARCH \(0\)** A exceção não é reconhecida.  Continue a procurar manipuladores na pilha, primeiro os que contêm as instruções **try\-except**, depois os que têm a próxima precedência mais alta.  
  
     **EXCEPTION\_EXECUTE\_HANDLER \(1\)** A exceção é reconhecida.  Transfere o controle para o manipulador de exceção executando a instrução composta `__except` e continua a execução após o bloco `__except`.  
  
 Como a expressão \_\_**except** é avaliada como uma expressão C, ela é limitada a um único valor, ao operador de expressão condicional ou ao operador vírgula.  Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.  
  
 Cada aplicativo pode ter seu próprio manipulador de exceção.  
  
 Isso não é válido para ir para uma instrução `__try`, mas é válido para sair de uma.  O manipulador de exceção não é chamado se um processo é encerrado no meio da execução de uma instrução **try\-except**.  
  
 Para obter mais informações, consulte o artigo Q315937 da Base de Dados de Conhecimento: Como interceptar um estouro de pilha em um aplicativo do Visual C\+\+.  
  
## A palavra\-chave \_\_leave  
 A palavra\-chave `__leave` é válida somente na seção protegida de uma instrução `try-except`, e seu efeito é ir diretamente para o final da seção protegida.  A execução continua na primeira instrução após o manipulador de exceção.  
  
 Uma instrução `goto` também pode sair da seção protegida, e isso não afeta o desempenho como em uma instrução `try-finally`, pois o desenrolar da pilha não ocorre.  Entretanto, recomendamos que você use a palavra\-chave `__leave` em vez de uma instrução `goto`, pois é menos provável que você cometa um erro de programação se a seção protegida for grande ou complexa.  
  
### Funções intrínsecas da manipulação de exceção estruturada  
 A manipulação de exceção estruturada fornece duas funções intrínsecas que estão disponíveis para uso na instrução **try\-except**: **GetExceptionCode** e **GetExceptionInformation**.  
  
 **GetExceptionCode** retorna o código \(um inteiro de 32 bits\) da exceção.  
  
 A função intrínseca **GetExceptionInformation** retorna um ponteiro para uma estrutura que contém informações adicionais sobre a exceção.  Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware.  A estrutura é a seguinte:  
  
```  
struct _EXCEPTION_POINTERS {  
      EXCEPTION_RECORD *ExceptionRecord,  
      CONTEXT *ContextRecord }  
```  
  
 Os tipos de ponteiros \_**EXCEPTION\_RECORD** e \_**CONTEXT** são definidos no arquivo de inclusão .EXCPT.H.  
  
 Você pode usar **GetExceptionCode** dentro do manipulador de exceção.  Porém, você pode usar **GetExceptionInformation** somente na expressão de filtro de exceção.  As informações para as quais ele aponta ficam normalmente na pilha e não estarão mais disponíveis quando o controle for transferido para o manipulador de exceção.  
  
 A função intrínseca **AbnormalTermination** está disponível dentro de um manipulador de término.  Retornará 0 se o corpo da instrução `try-finally` terminar em sequência.  Em todos os outros casos, retorna 1.  
  
 EXCPT.H define nomes alternativos para estes intrínsecos:  
  
 **GetExceptionCode** é equivalente a \_exception\_code  
  
 **GetExceptionInformation** é equivalente a \_exception\_info  
  
 **AbnormalTermination** é equivalente a \_abnormal\_termination  
  
## Exemplo  
 `// exceptions_try_except_Statement.cpp`  
  
 `// Example of try-except and try-finally statements`  
  
 `#include <stdio.h>`  
  
 `#include <windows.h> // for EXCEPTION_ACCESS_VIOLATION`  
  
 `#include <excpt.h>`  
  
 `int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep) {`  
  
 `puts("in filter.");`  
  
 `if (code == EXCEPTION_ACCESS_VIOLATION) {`  
  
 `puts("caught AV as expected.");`  
  
 `return EXCEPTION_EXECUTE_HANDLER;`  
  
 `}`  
  
 `else {`  
  
 `puts("didn't catch AV, unexpected.");`  
  
 `return EXCEPTION_CONTINUE_SEARCH;`  
  
 `};`  
  
 `}`  
  
 `int main()`  
  
 `{`  
  
 `int* p = 0x00000000;   // pointer to NULL`  
  
 `puts("hello");`  
  
 `__try{`  
  
 `puts("in try");`  
  
 `__try{`  
  
 `puts("in try");`  
  
 `*p = 13;    // causes an access violation exception;`  
  
 `}__finally{`  
  
 `puts("in finally. termination: ");`  
  
 `puts(AbnormalTermination() ? "\tabnormal" : "\tnormal");`  
  
 `}`  
  
 `}__except(filter(GetExceptionCode(), GetExceptionInformation())){`  
  
 `puts("in except");`  
  
 `}`  
  
 `puts("world");`  
  
 `}`  
  
## Saída  
  
```  
hello  
in try  
in try  
in filter.  
caught AV as expected.  
in finally. termination:  
        abnormal  
in except  
world  
```  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)