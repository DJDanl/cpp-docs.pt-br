---
title: Instrução try-except
description: A referência do Microsoft C++ ao __try e __except instruções de manipulação de exceção estruturada.
ms.date: 04/03/2020
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
ms.openlocfilehash: d0471bbd50e07fccbf160e9e866de4c545cdeb7e
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825764"
---
# <a name="try-except-statement"></a>Instrução try-except

A instrução **try-Except** é uma extensão da Microsoft que dá suporte à manipulação de exceção estruturada nas linguagens C e C++. Essa extensão é **específica da Microsoft**.

## <a name="syntax"></a>Sintaxe

> **\_\_Tente**\
> {\
> &nbsp;&nbsp;&nbsp;&nbsp;código protegido \
> }\
> Except ( *expressão* ) \ ** \_ \_**
> {\
> &nbsp;&nbsp;&nbsp;&nbsp;código do manipulador de exceção \
> }

## <a name="remarks"></a>Comentários

A instrução **try-Except** é uma extensão da Microsoft para as linguagens C e C++. Ele permite que os aplicativos de destino tenham controle quando ocorrem eventos que normalmente encerram a execução do programa. Esses eventos são chamados de *exceções estruturadas*ou *exceções* de forma abreviada. O mecanismo que lida com essas exceções é chamado de SEH ( *manipulação de exceção estruturada* ).

Para obter informações relacionadas, consulte a [instrução try-finally](../cpp/try-finally-statement.md).

As exceções podem ser baseadas em hardware ou em software. A manipulação de exceção estruturada é útil mesmo quando os aplicativos não podem se recuperar completamente de exceções de hardware ou software. O SEH torna possível exibir informações de erro e interceptar o estado interno do aplicativo para ajudar a diagnosticar o problema. Ele é especialmente útil para problemas intermitentes que não são fáceis de reproduzir.

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, ele não foi projetado especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas em C++, recomendamos que você use as instruções de manipulação de exceção C++ nativas: [try, catch e throw](../cpp/try-throw-and-catch-statements-cpp.md) .

A instrução composta após a cláusula **__try** é o *corpo* ou a seção *protegida* . A expressão de **__except** também é conhecida como a expressão de *filtro* . Seu valor determina como a exceção é tratada. A instrução composta após a cláusula **__except** é o manipulador de exceção. O manipulador Especifica as ações a serem executadas se uma exceção for gerada durante a execução da seção Body. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. Se nenhuma exceção ocorrer durante a execução da seção protegida, a execução continuará na instrução após a cláusula de **__except** .

1. Se ocorrer uma exceção durante a execução da seção protegida ou, em qualquer rotina, a seção protegida chamar, a expressão de **__except** será avaliada. Há três valores possíveis:

   - `EXCEPTION_CONTINUE_EXECUTION`(-1) Exceção descartada. Continue a execução no ponto onde ocorreu a exceção.

   - `EXCEPTION_CONTINUE_SEARCH`(0) a exceção não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.

   - `EXCEPTION_EXECUTE_HANDLER`(1) a exceção é reconhecida. Transfira o controle para o manipulador de exceção executando a instrução **__except** composta e continue a execução após o bloco de **__except** .

A expressão **__except** é avaliada como uma expressão C. Ele é limitado a um único valor, ao operador de expressão condicional ou ao operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

Cada aplicativo pode ter seu próprio manipulador de exceção.

Não é válido pular para uma instrução **__try** , mas é válido para saltar de uma. O manipulador de exceção não será chamado se um processo for encerrado no meio da execução de uma instrução **try-Except** .

Para compatibilidade com versões anteriores, **_try**, **_except**e **_leave** são sinônimos de **__try**, **__except**e **__leave** , a menos que a opção do compilador [ \(/za desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

### <a name="the-__leave-keyword"></a>A palavra-chave __leave

A palavra-chave **__leave** só é válida na seção protegida de uma instrução **try-Except** e seu efeito é ir para o final da seção protegida. A execução continua na primeira instrução após o manipulador de exceção.

Uma instrução **goto** também pode sair da seção protegida e não degrada o desempenho como faz em uma instrução **try-finally** . Isso porque o desenrolamento de pilha não ocorre. No entanto, recomendamos que você use a palavra-chave **__leave** em vez de uma instrução **goto** . O motivo é que você tem menos probabilidade de fazer um erro de programação se a seção protegida for grande ou complexa.

### <a name="structured-exception-handling-intrinsic-functions"></a>Funções intrínsecas da manipulação de exceção estruturada

A manipulação de exceção estruturada fornece duas funções intrínsecas que estão disponíveis para uso com a instrução **try-Except** : [GetExceptionCode](/windows/win32/Debug/getexceptioncode) e [GetExceptionInformation](/windows/win32/Debug/getexceptioninformation).

`GetExceptionCode`Retorna o código (um número inteiro de 32 bits) da exceção.

A função `GetExceptionInformation` intrínseca retorna um ponteiro para uma estrutura de [EXCEPTION_POINTERS](/windows/win32/api/winnt/ns-winnt-exception_pointers) que contém informações adicionais sobre a exceção. Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware. A estrutura é a seguinte:

```cpp
typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
```

Os tipos `PEXCEPTION_RECORD` de ponteiro `PCONTEXT` e \<são definidos no arquivo include Winnt. h> e `_EXCEPTION_RECORD` e `_CONTEXT` são definidos no arquivo \<de inclusão Excpt. h>

Você pode usar `GetExceptionCode` dentro do manipulador de exceção. No entanto, você `GetExceptionInformation` pode usar somente dentro da expressão de filtro de exceção. As informações apontadas são geralmente na pilha e não estão mais disponíveis quando o controle é transferido para o manipulador de exceção.

A função intrínseca [AbnormalTermination](/windows/win32/Debug/abnormaltermination) está disponível dentro de um manipulador de encerramento. Retornará 0 se o corpo da instrução **try-finally terminar em** sequência. Em todos os outros casos, retorna 1.

\<Excpt. h> define alguns nomes alternativos para esses intrínsecos:

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

## <a name="see-also"></a>Confira também

[Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)<br/>
[Manipulação de exceção estruturada (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
