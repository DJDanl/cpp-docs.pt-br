---
title: Instrução try-except
ms.date: 10/09/2018
f1_keywords:
- _abnormal_termination_cpp
- _exception_code_cpp
- _exception_info
- __except
- _except
- _exception_code
- __except_cpp
- _exception_info_cpp
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
ms.openlocfilehash: 7d3a92aa8c6d1f77a1795eabde0ae1e575bb5770
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79444120"
---
# <a name="try-except-statement"></a>Instrução try-except

**Seção específica da Microsoft**

A instrução **try-Except** é uma extensão da Microsoft para o C C++ e idiomas que dão suporte à manipulação de exceção estruturada.

## <a name="syntax"></a>Sintaxe

> **\_\_tentar**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;código &nbsp;//protegido<br/>
> }<br/>
> **\_\_exceto** ( *expressão* )<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;o código de manipulador de exceção &nbsp;//<br/>
> }

## <a name="remarks"></a>Comentários

A instrução **try-Except** é uma extensão da Microsoft para a C C++ e linguagens que permite aos aplicativos de destino obter controle quando os eventos que normalmente encerram a execução do programa ocorrem. Esses eventos são chamados de *exceções*, e o mecanismo que lida com exceções é chamado de SEH ( *manipulação de exceção estruturada* ).

Para obter informações relacionadas, consulte a [instrução try-finally](../cpp/try-finally-statement.md).

As exceções podem ser baseadas em hardware ou software. Mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software, a manipulação de exceção estruturada permite exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Isso é especialmente útil para os problemas intermitentes que não podem ser reproduzidos facilmente.

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não é projetada especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para C++ programas, é recomendável que você use o C++ mecanismo de tratamento de exceções (instruções[try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) ).

A instrução composta após a cláusula **__try** é o corpo ou a seção protegida. A instrução composta após a cláusula **__except** é o manipulador de exceção. O manipulador especifica um conjunto de ações a ser executado se uma exceção for gerada durante a execução do corpo da seção protegida. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula de **__except** .

1. Se ocorrer uma exceção durante a execução da seção protegida ou em qualquer rotina que a seção protegida chamar, a *expressão* de **__except** (chamada de expressão de *filtro* ) será avaliada e o valor determinará como a exceção será tratada. Há três valores possíveis:

   - A exceção EXCEPTION_CONTINUE_EXECUTION (-1) é ignorada. Continue a execução no ponto onde ocorreu a exceção.

   - A exceção EXCEPTION_CONTINUE_SEARCH (0) não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.

   - EXCEPTION_EXECUTE_HANDLER (1) exceção é reconhecida. Transfira o controle para o manipulador de exceção executando a instrução **__except** composta e continue a execução após o bloco de **__except** .

Como a expressão de **__except** é avaliada como uma expressão C, ela é limitada a um único valor, ao operador de expressão condicional ou ao operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

Cada aplicativo pode ter seu próprio manipulador de exceção.

Não é válido pular para uma instrução **__try** , mas é válido para saltar de uma. O manipulador de exceção não será chamado se um processo for encerrado no meio da execução de uma instrução **try-Except** .

Para a compatibilidade com versões anteriores, **_try**, **_except**e **_leave** são sinônimos de **__try**, **__except**e **__Leave** , a menos que a opção do compilador [/za \(desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

### <a name="the-__leave-keyword"></a>A palavra-chave __leave

A palavra-chave **__leave** só é válida na seção protegida de uma instrução **try-Except** e seu efeito é ir para o final da seção protegida. A execução continua na primeira instrução após o manipulador de exceção.

Uma instrução **goto** também pode sair da seção protegida e não degrada o desempenho da mesma forma que em uma instrução **try-finally** porque o desenrolamento de pilha não ocorre. No entanto, recomendamos que você use a palavra-chave **__leave** em vez de uma instrução **goto** porque é menos provável que você faça um erro de programação se a seção protegida for grande ou complexa.

### <a name="structured-exception-handling-intrinsic-functions"></a>Funções intrínsecas da manipulação de exceção estruturada

A manipulação de exceção estruturada fornece duas funções intrínsecas que estão disponíveis para uso com a instrução **try-Except** : `GetExceptionCode` e `GetExceptionInformation`.

`GetExceptionCode` retorna o código (um inteiro de 32 bits) da exceção.

A função intrínseca `GetExceptionInformation` retorna um ponteiro para uma estrutura que contém informações adicionais sobre a exceção. Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware. A estrutura é a seguinte:

```cpp
typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
```

Os tipos de ponteiro `PEXCEPTION_RECORD` e `PCONTEXT` são definidos no arquivo de inclusão \<Winnt. h > e `_EXCEPTION_RECORD` e `_CONTEXT` são definidos no arquivo de inclusão \<Excpt. h >

Você pode usar `GetExceptionCode` dentro do manipulador de exceção. No entanto, você pode usar `GetExceptionInformation` apenas dentro da expressão de filtro de exceção. As informações para as quais ele aponta ficam normalmente na pilha e não estarão mais disponíveis quando o controle for transferido para o manipulador de exceção.

A função intrínseca `AbnormalTermination` está disponível dentro de um manipulador de encerramento. Retornará 0 se o corpo da instrução **try-finally terminar em** sequência. Em todos os outros casos, retorna 1.

Excpt. h define alguns nomes alternativos para esses intrínsecos:

`GetExceptionCode` equivale a `_exception_code`

`GetExceptionInformation` equivale a `_exception_info`

`AbnormalTermination` equivale a `_abnormal_termination`

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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

### <a name="output"></a>Saída

```Output
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

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Tratamento de exceções estruturado (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
