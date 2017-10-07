---
title: "Tente-exceto instrução | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _abnormal_termination_cpp
- _exception_code_cpp
- EXCEPTION_CONTINUE_SEARCH
- _exception_info
- __except
- EXCEPTION_CONTINUE_EXECUTION
- _exception_code
- __except_cpp
- _exception_info_cpp
- EXCEPTION_EXECUTE_HANDLER
- _abnormal_termination
dev_langs:
- C++
helpviewer_keywords:
- __try keyword [C++]
- EXCEPTION_CONTINUE_EXECUTION macro
- EXCEPTION_CONTINUE_SEARCH macro
- EXCEPTION_EXECUTE_HANDLER macro
- GetExceptionCode function
- try-catch keyword [C++], try-except keyword [C++]
- _exception_code keyword [C++]
- try-except keyword [C++]
- _exception_info keyword [C++]
- _abnormal_termination keyword [C++]
ms.assetid: 30d60071-ea49-4bfb-a8e6-7a420de66381
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: e7a9b4aebd0ae60feeedc64644d3e50b8859f7cf
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="try-except-statement"></a>Instrução try-except
**Seção específica da Microsoft**  
  
 A sintaxe a seguir descreve a instrução try-except:  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
## <a name="remarks"></a>Comentários  
 O **tente-exceto** instrução é uma extensão da Microsoft para C e linguagens C++ que permite que aplicativos de destino obter controlam quando ocorrem os eventos que normalmente terminar a execução do programa. Esses eventos são denominados exceções, e o mecanismo que lida com exceções é chamado de manipulação de exceção estruturada.  
  
 Para obter informações relacionadas, consulte o [instrução try-finally](../cpp/try-finally-statement.md).  
  
 As exceções podem ser baseadas em hardware ou software. Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.  
  
> [!NOTE]
>  A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em C++, é recomendável que você use o mecanismo de tratamento de exceção C++ ([try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) instruções).  
  
 A instrução composta após a cláusula `__try` é o corpo ou a seção protegida. A instrução composta após a cláusula `__except` é o manipulador de exceções. O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução do corpo da seção protegida. A execução procede da seguinte maneira:  
  
1.  A seção protegida é executada.  
  
2.  Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula `__except`.  
  
3.  Se ocorrer uma exceção durante a execução da seção protegida ou qualquer rotina chama a seção protegida, o `__except` *expressão* (chamado de *filtro* expressão) é avaliada e o valor Determina como a exceção é manipulada. Há três valores:  
  
     **EXCEPTION_CONTINUE_EXECUTION (-1)** exceção é descartada. Continue a execução no ponto onde ocorreu a exceção.  
  
     **EXCEPTION_CONTINUE_SEARCH (0)** exceção não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.  
  
     **EXCEPTION_EXECUTE_HANDLER (1)** exceção é reconhecida. Transfere o controle para o manipulador de exceção executando a instrução composta `__except` e continua a execução após o bloco `__except`.  
  
 Porque o _**exceto** expressão é avaliada como uma expressão de C, ele é limitado a um único valor, o operador de expressão condicional ou o operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.  
  
 Cada aplicativo pode ter seu próprio manipulador de exceção.  
  
 Isso não é válido para ir para uma instrução `__try`, mas é válido para sair de uma. O manipulador de exceção não é chamado, se um processo é finalizado no meio da execução de um **tente-exceto** instrução.  
  
 Para obter mais informações, consulte o artigo Q315937 da Base de Dados de Conhecimento: Como interceptar um estouro de pilha em um aplicativo do Visual C++.  
  
## <a name="the-leave-keyword"></a>A palavra-chave __leave  
 A palavra-chave `__leave` é válida somente na seção protegida de uma instrução `try-except`, e seu efeito é ir diretamente para o final da seção protegida. A execução continua na primeira instrução após o manipulador de exceção.  
  
 Uma instrução `goto` também pode sair da seção protegida, e isso não afeta o desempenho como em uma instrução `try-finally`, pois o desenrolar da pilha não ocorre. Entretanto, recomendamos que você use a palavra-chave `__leave` em vez de uma instrução `goto`, pois é menos provável que você cometa um erro de programação se a seção protegida for grande ou complexa.  
  
### <a name="structured-exception-handling-intrinsic-functions"></a>Funções intrínsecas da manipulação de exceção estruturada  
 Tratamento estruturado de exceções fornece duas funções intrínsecas que estão disponíveis para uso com o **tente-exceto** instrução: **GetExceptionCode** e **GetExceptionInformation**.  
  
 **GetExceptionCode** retorna o código (um inteiro de 32 bits) da exceção.  
  
 A função intrínseca **GetExceptionInformation** retorna um ponteiro para uma estrutura que contém informações adicionais sobre a exceção. Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware. A estrutura é a seguinte:  
  
```  
struct _EXCEPTION_POINTERS {  
      EXCEPTION_RECORD *ExceptionRecord,  
      CONTEXT *ContextRecord }  
```  
  
 Tipos de ponteiro _**EXCEPTION_RECORD** e \_ **contexto** são definidos no arquivo de inclusão EXCPT. H.  
  
 Você pode usar **GetExceptionCode** dentro do manipulador de exceção. No entanto, você pode usar **GetExceptionInformation** somente dentro de expressão de filtro de exceção. As informações para as quais ele aponta ficam normalmente na pilha e não estarão mais disponíveis quando o controle for transferido para o manipulador de exceção.  
  
 A função intrínseca **AbnormalTermination** está disponível dentro de um manipulador de término. Retornará 0 se o corpo da instrução `try-finally` terminar em sequência. Em todos os outros casos, retorna 1.  
  
 EXCPT.H define nomes alternativos para estes intrínsecos:  
  
 **GetExceptionCode** é equivalente a exception_code  
  
 **GetExceptionInformation** é equivalente a exception_info  
  
 **AbnormalTermination** é equivalente a abnormal_termination  
  
## <a name="example"></a>Exemplo  
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
  
 `int* p = 0x00000000;   // pointer to NULL`  
  
 `puts("hello");`  
  
 `__try{`  
  
 `puts("in try");`  
  
 `__try{`  
  
 `puts("in try");`  
  
 `*p = 13;    // causes an access violation exception;`  
  
 `}__finally{`  
  
 `puts("in finally. termination: ");`  
  
 `puts(AbnormalTermination() ? "\tabnormal" : "\tnormal");`  
  
 `}`  
  
 `}__except(filter(GetExceptionCode(), GetExceptionInformation())){`  
  
 `puts("in except");`  
  
 `}`  
  
 `puts("world");`  
  
 `}`  
  
## <a name="output"></a>Saída  
  
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
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)   
 [(C/C++) de tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
