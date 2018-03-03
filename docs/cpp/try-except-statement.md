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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 24be4e7fd6b4dc95d9964e69943a94ecad947a47
ms.sourcegitcommit: 9a0a287d6940591523af959ebdac5affa36220da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/25/2018
---
# <a name="try-except-statement"></a>Instrução try-except

**Seção específica da Microsoft**  
O **tente-exceto** instrução é uma extensão da Microsoft para C e linguagens C++ que dá suporte ao tratamento estruturado de exceções.  

## <a name="syntax"></a>Sintaxe  
  
> **__try**   
> {  
>    código protegido  
> }  
> **__except** ( *expression* )  
> {  
>    código de manipulador de exceção  
> }  

## <a name="remarks"></a>Comentários

O **tente-exceto** instrução é uma extensão da Microsoft para C e linguagens C++ que permite que aplicativos de destino obter controlam quando ocorrem os eventos que normalmente terminar a execução do programa. Esses eventos são chamados *exceções*, e o mecanismo que lida com exceções é chamado *tratamento estruturado de exceções* (SEH).

Para obter informações relacionadas, consulte o [instrução try-finally](../cpp/try-finally-statement.md).

As exceções podem ser baseadas em hardware ou software. Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em C++, é recomendável que você use o mecanismo de tratamento de exceção C++ ([try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) instruções).

A instrução composta após a cláusula `__try` é o corpo ou a seção protegida. A instrução composta após a cláusula `__except` é o manipulador de exceções. O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução do corpo da seção protegida. A execução procede da seguinte maneira:

1. A seção protegida é executada.

2. Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula `__except`.  

3. Se ocorrer uma exceção durante a execução da seção protegida ou qualquer rotina chama a seção protegida, o `__except` *expressão* (chamado de *filtro* expressão) é avaliada e o valor Determina como a exceção é manipulada. Há três valores:

   **EXCEPTION_CONTINUE_EXECUTION (-1)** exceção é descartada. Continue a execução no ponto onde ocorreu a exceção.

   **EXCEPTION_CONTINUE_SEARCH (0)** exceção não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.

   **EXCEPTION_EXECUTE_HANDLER (1)** exceção é reconhecida. Transfere o controle para o manipulador de exceção executando a instrução composta `__except` e continua a execução após o bloco `__except`.

Como a expressão `__except` é avaliada como uma expressão C, ela é limitada a um único valor, o operador de expressão condicional ou ao operador vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

Cada aplicativo pode ter seu próprio manipulador de exceção.

Isso não é válido para ir para uma instrução `__try`, mas é válido para sair de uma. O manipulador de exceção não é chamado, se um processo é finalizado no meio da execução de um **tente-exceto** instrução.  
  
Para obter mais informações, consulte o artigo Q315937 da Base de Dados de Conhecimento: Como interceptar um estouro de pilha em um aplicativo do Visual C++.  
  
## <a name="the-leave-keyword"></a>A palavra-chave __leave

O `__leave` palavra-chave é válido somente dentro da seção protegida de uma **tente-exceto** é a instrução e seu efeito ir até o final da seção protegida. A execução continua na primeira instrução após o manipulador de exceção.

Um `goto` instrução também pode ir na seção protegidos, e ela não prejudicar o desempenho, como em um **try-finally** instrução porque o desenrolamento de pilha não ocorrerá. Entretanto, recomendamos que você use a palavra-chave `__leave` em vez de uma instrução `goto`, pois é menos provável que você cometa um erro de programação se a seção protegida for grande ou complexa.

### <a name="structured-exception-handling-intrinsic-functions"></a>Funções intrínsecas da manipulação de exceção estruturada

Tratamento estruturado de exceções fornece duas funções intrínsecas que estão disponíveis para uso com o **tente-exceto** instrução: `GetExceptionCode` e `GetExceptionInformation`.

`GetExceptionCode`Retorna o código (um inteiro de 32 bits) da exceção.

A função intrínseca `GetExceptionInformation` retorna um ponteiro para uma estrutura que contém informações adicionais sobre a exceção. Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware. A estrutura é a seguinte:

```cpp  
typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS; 
```  

Os tipos de ponteiro `PEXCEPTION_RECORD` e `PCONTEXT` são definidos no arquivo de inclusão \<Winnt. h >, e `_EXCEPTION_RECORD` e `_CONTEXT` são definidos no arquivo de inclusão \<excpt.h >

Você pode usar `GetExceptionCode` dentro do manipulador de exceção. No entanto, você pode usar `GetExceptionInformation` somente dentro de expressão de filtro de exceção. As informações para as quais ele aponta ficam normalmente na pilha e não estarão mais disponíveis quando o controle for transferido para o manipulador de exceção.

A função intrínseca `AbnormalTermination` está disponível dentro de um manipulador de término. Retorna 0 se o corpo do **try-finally** instrução finaliza sequencialmente. Em todos os outros casos, retorna 1.

excpt.h define alguns nomes alternativos para esses intrínsecos:

`GetExceptionCode` equivale a `_exception_code`

 `GetExceptionInformation` equivale a `_exception_info`

 `AbnormalTermination` equivale a `_abnormal_termination`
  
## <a name="example"></a>Exemplo

```cpp
// exceptions_try_except_Statement.cpp
// Example of try-except and try-finally statements
#include <stdio.h>
#include <windows.h> // for EXCEPTION_ACCESS_VIOLATION
#include <excpt.h>

int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{
    puts("in filter.");
    if (code == EXCEPTION_ACCESS_VIOLATION)
    {
        puts("caught AV as expected.");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    else
    {
        puts("didn't catch AV, unexpected.");
        return EXCEPTION_CONTINUE_SEARCH;
    };
}

int main()
{
    int* p = 0x00000000;   // pointer to NULL
    puts("hello");
    __try
    {
        puts("in try");
        __try
        {
            puts("in try");
            *p = 13;    // causes an access violation exception;
        }
        __finally
        {
            puts("in finally. termination: ");
            puts(AbnormalTermination() ? "\tabnormal" : "\tnormal");
        }
    }
    __except(filter(GetExceptionCode(), GetExceptionInformation()))
    {
        puts("in except");
    }
    puts("world");
}
```
  
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
