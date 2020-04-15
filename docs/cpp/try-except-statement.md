---
title: Instrução try-except
description: A referência do Microsoft C++ às declarações de manipulação de exceção __try e __except estruturadas.
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
ms.openlocfilehash: 132edf7cc9819637fafa3947686972d311924b99
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366231"
---
# <a name="try-except-statement"></a>Instrução try-except

A declaração **try-except** é uma extensão da Microsoft que suporta o manuseio estruturado de exceções nos idiomas C e C++. Esta extensão é **específica da Microsoft.**

## <a name="syntax"></a>Sintaxe

> **\_\_Tentar**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código guardado<br/>
> }<br/>
> exceto *(expressão)* ** \_ \_**<br/>
> {<br/>
> &nbsp;&nbsp;&nbsp;&nbsp;código manipulador de exceção<br/>
> }

## <a name="remarks"></a>Comentários

A declaração **try-except** é uma extensão da Microsoft para os idiomas C e C++. Ele permite que os aplicativos-alvo ganhem controle quando ocorrem eventos que normalmente encerram a execução do programa. Tais eventos são chamados *de exceções estruturadas,* ou *exceções* para abreviar. O mecanismo que lida com essas exceções é chamado *de tratamento estruturado de exceções* (SEH).

Para obter informações relacionadas, consulte a [declaração try-finally](../cpp/try-finally-statement.md).

As exceções podem ser baseadas em hardware ou baseadas em software. O manuseio estruturado de exceções é útil mesmo quando os aplicativos não podem se recuperar completamente das exceções de hardware ou software. O SEH possibilita a exibição de informações de erro e prende o estado interno do aplicativo para ajudar a diagnosticar o problema. É especialmente útil para problemas intermitentes que não são fáceis de reproduzir.

> [!NOTE]
> A manipulação de exceção estruturada funciona com Win32 para arquivos de código-fonte em C e C++. No entanto, não foi projetado especificamente para C++. Você pode garantir que o código seja mais portátil usando a manipulação de exceção de C++. Além disso, a manipulação de exceção de C++ é mais flexível, pois pode tratar exceções de qualquer tipo. Para programas C++, recomendamos que você use o manuseio de exceção C++ nativo: [tente, pegue e lance](../cpp/try-throw-and-catch-statements-cpp.md) declarações.

A declaração composta após a cláusula **de __try** é o *corpo* ou a seção *protegida.* A expressão **__except** também é conhecida como expressão do *filtro.* Seu valor determina como a exceção é tratada. A declaração composta após a cláusula **de __except** é o manipulador de exceção. O manipulador especifica as ações a serem tomadas se uma exceção for levantada durante a execução da seção do corpo. A execução procede da seguinte maneira:

1. A seção protegida é executada.

1. Se nenhuma exceção ocorrer durante a execução da seção vigiada, a execução continua na declaração após a cláusula **__except.**

1. Se ocorrer uma exceção durante a execução da seção vigiada, ou em qualquer rotina a seção vigiada chamar, a **__except** expressão é avaliada. Há três valores possíveis:

   - `EXCEPTION_CONTINUE_EXECUTION`(-1) A exceção está descartada. Continue a execução no ponto onde ocorreu a exceção.

   - `EXCEPTION_CONTINUE_SEARCH`(0) A exceção não é reconhecida. Continue pesquisando manipuladores na pilha; primeiro os que contêm as instruções **try-except**, depois os que têm a próxima precedência mais alta.

   - `EXCEPTION_EXECUTE_HANDLER`(1) A exceção é reconhecida. Transfira o controle para o manipulador de exceção executando a **declaração** composta __except e, em seguida, continue a execução após o **bloqueio __except.**

A expressão **__except** é avaliada como uma expressão C. Está limitado a um único valor, o operador de expressão condicional, ou o operador de vírgula. Se um processamento mais extenso for necessário, a expressão poderá chamar uma rotina que retorne um dos três valores listados acima.

Cada aplicativo pode ter seu próprio manipulador de exceção.

Não é válido pular em uma declaração **__try,** mas válida para saltar de uma. O manipulador de exceção não é chamado se um processo for encerrado no meio da execução de uma **declaração de try-except.**

Para compatibilidade com as versões anteriores, **_try,** **_except**e **_leave** são sinônimos de **__try,** **__except**e **__leave,** a menos que a opção de compilação [/Za \(Disable extensões de idioma)](../build/reference/za-ze-disable-language-extensions.md) seja especificada.

### <a name="the-__leave-keyword"></a>A palavra-chave __leave

A **palavra-chave __leave** é válida apenas dentro da seção protegida de uma declaração de **try-except,** e seu efeito é saltar para o final da seção protegida. A execução continua na primeira instrução após o manipulador de exceção.

Uma declaração **goto** também pode saltar para fora da seção vigiada, e não degrada o desempenho como faz em uma declaração **try-finally.** Isso porque o desenrolar da pilha não ocorre. No entanto, recomendamos que você use a **palavra-chave __leave** em vez de uma declaração **goto.** A razão é porque é menos provável que você cometa um erro de programação se a seção protegida for grande ou complexa.

### <a name="structured-exception-handling-intrinsic-functions"></a>Funções intrínsecas da manipulação de exceção estruturada

O tratamento estruturado de exceções fornece duas funções intrínsecas que estão disponíveis para uso com a declaração **try-except:** [GetExceptionCode](/windows/win32/Debug/getexceptioncode) e [GetExceptionInformation](/windows/win32/Debug/getexceptioninformation).

`GetExceptionCode`retorna o código (um inteiro de 32 bits) da exceção.

A função `GetExceptionInformation` intrínseca retorna um ponteiro para uma estrutura [EXCEPTION_POINTERS](/windows/win32/api/winnt/ns-winnt-exception_pointers) contendo informações adicionais sobre a exceção. Por esse ponteiro, você pode acessar qual era o estado do computador no momento em que ocorreu uma exceção de hardware. A estrutura é a seguinte:

```cpp
typedef struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
```

Os tipos `PEXCEPTION_RECORD` `PCONTEXT` de ponteiro e \<são definidos no `_EXCEPTION_RECORD` arquivo `_CONTEXT` winnt.h \<> e são definidos no arquivo excpt.h>

Você pode `GetExceptionCode` usar dentro do manipulador de exceção. No entanto, `GetExceptionInformation` você só pode usar dentro da expressão do filtro de exceção. As informações que ele aponta estão geralmente na pilha e não estão mais disponíveis quando o controle é transferido para o manipulador de exceção.

A função intrínseca [AbnormalTermination](/windows/win32/Debug/abnormaltermination) está disponível dentro de um manipulador de terminação. Ele retorna 0 se o corpo da declaração **try-finally** terminar sequencialmente. Em todos os outros casos, retorna 1.

\<excpt.h> define alguns nomes alternativos para estes intrínsecos:

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
[Tratamento estruturado de exceções (C/C++)](../cpp/structured-exception-handling-c-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
