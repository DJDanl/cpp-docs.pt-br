---
title: Tratamento de exceções estruturado (C/C++)
description: Uma visão geral da manipulação de exceção estruturada no Microsoft C/C++.
ms.date: 08/24/2020
helpviewer_keywords:
- termination handlers [C++], handling exceptions in C++
- structured exception handling [C++]
- try-catch keyword [C++], exception handlers
- C++ exception handling, termination handlers
- try-catch keyword [C++], termination handlers
- C++ exception handling, exception handlers
ms.assetid: dd3b647d-c269-43a8-aab9-ad1458712976
ms.openlocfilehash: 142e89bc82adbe7938e8825029908e814df6055c
ms.sourcegitcommit: efc8c32205c9d610f40597556273a64306dec15d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/26/2020
ms.locfileid: "88898633"
---
# <a name="structured-exception-handling-cc"></a>Tratamento de exceções estruturado (C/C++)

O SEH (manipulação de exceção estruturada) é uma extensão da Microsoft para C para lidar com determinadas situações de código excepcionais, como falhas de hardware, normalmente. Embora o Windows e o Microsoft C++ ofereçam suporte a SEH, recomendamos que você use a manipulação de exceção de C++ padrão ISO. Ele torna seu código mais portátil e flexível. No entanto, para manter o código existente ou para determinados tipos de programas, você ainda pode precisar usar SEH.

**Específico da Microsoft:**

## <a name="grammar"></a>Gramática

> *`try-except-statement`* :<br/>
> &emsp;**`__try`** *`compound-statement`* **`__except`** **`(`** *`expression`* **`)`** *`compound-statement`*
>
> *`try-finally-statement`* :<br/>
> &emsp;**`__try`** *`compound-statement`* **`__finally`** *`compound-statement`*

## <a name="remarks"></a>Comentários

Com o SEH, você pode garantir que os recursos, como arquivos e blocos de memória, sejam liberados corretamente se a execução for encerrada inesperadamente. Você também pode lidar com problemas específicos — por exemplo, memória insuficiente — usando código estruturado conciso que não depende de **`goto`** instruções ou testes elaborados de códigos de retorno.

As `try-except` `try-finally` instruções e mencionadas neste artigo são extensões da Microsoft para a linguagem C. Elas oferecem suporte ao SEH permitindo que os aplicativos controlem um programa após os eventos que, caso contrário, finalizariam a execução. Ainda que o SEH funcione com arquivos de origem C++, ele não é projetado especificamente para C++. Se você usar o SEH em um programa C++ que você compilar usando a opção [ `/EHa` ou `/EHsc` ](../build/reference/eh-exception-handling-model.md) , os destruidores para objetos locais serão chamados, mas outro comportamento de execução poderá não ser o esperado. Para obter uma ilustração, consulte o exemplo mais adiante neste artigo. Na maioria dos casos, em vez de SEH, recomendamos que você use a [manipulação de exceção de c++](../cpp/try-throw-and-catch-statements-cpp.md)padrão ISO, que o compilador do Microsoft C++ também suporta. Usando o tratamento de exceções C++, é possível garantir que o seu código seja mais portátil e tratar exceções de qualquer tipo.

Se você tiver código C que usa SEH, poderá misturá-lo com o código C++ que usa a manipulação de exceção do C++. Para obter informações, consulte [manipular exceções estruturadas em C++](../cpp/exception-handling-differences.md).

Existem dois mecanismos de SEH:

- [Manipuladores de exceção](../cpp/writing-an-exception-handler.md), ou **`__except`** blocos, que podem responder ou ignorar a exceção.

- [Manipuladores de encerramento](../cpp/writing-a-termination-handler.md)ou **`__finally`** blocos, que são sempre chamados, se uma exceção causa encerramento ou não.

Esses dois tipos de manipuladores são distintos, mas estão fortemente relacionados por meio de um processo conhecido como *desenrolar a pilha*. Quando ocorre uma exceção estruturada, o Windows procura o manipulador de exceção instalado mais recentemente que está ativo no momento. O manipulador pode executar uma de três ações:

- Não reconhecer a exceção e não passar o controle para outros manipuladores.

- Reconhecer a exceção mas ignorá-la.

- Confirmar a exceção e manipulá-la.

O manipulador de exceções que reconhece a exceção pode não estar na função em execução no momento da exceção. Ele pode estar em uma função muito maior na pilha. A função em execução no momento e quaisquer outras funções no quadro de pilhas são terminadas. Durante esse processo, a pilha é *rebobinada*. Ou seja, variáveis locais não estáticas de funções encerradas são limpas da pilha.

Como o sistema operacional desenrola a pilha, ele chama todos os manipuladores de término escritos para cada função. Usando um manipulador de encerramento, você limpa os recursos que, de outra forma, permanecerão abertos devido a um encerramento anormal. Se você tiver inserido uma seção crítica, poderá encerrá-la no manipulador de encerramento. Quando o programa for desligado, você poderá realizar outras tarefas de manutenção, como fechar e remover arquivos temporários.

## <a name="next-steps"></a>Próximas etapas

- [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)

- [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)

- [Tratar exceções estruturadas no C++](../cpp/exception-handling-differences.md)

## <a name="example"></a>Exemplo

Como mencionado anteriormente, os destruidores para objetos locais são chamados se você usar o SEH em um programa C++ e compilá-lo usando a **`/EHa`** **`/EHsc`** opção ou. No entanto, o comportamento durante a execução pode não ser o esperado se você também estiver usando exceções C++. Este exemplo demonstra essas diferenças comportamentais.

```cpp
#include <stdio.h>
#include <Windows.h>
#include <exception>

class TestClass
{
public:
    ~TestClass()
    {
        printf("Destroying TestClass!\r\n");
    }
};

__declspec(noinline) void TestCPPEX()
{
#ifdef CPPEX
    printf("Throwing C++ exception\r\n");
    throw std::exception("");
#else
    printf("Triggering SEH exception\r\n");
    volatile int *pInt = 0x00000000;
    *pInt = 20;
#endif
}

__declspec(noinline) void TestExceptions()
{
    TestClass d;
    TestCPPEX();
}

int main()
{
    __try
    {
        TestExceptions();
    }
    __except(EXCEPTION_EXECUTE_HANDLER)
    {
        printf("Executing SEH __except block\r\n");
    }

    return 0;
}
```

Se você usar **`/EHsc`** o para compilar esse código, mas a macro de controle de teste local `CPPEX` estiver indefinida, o `TestClass` destruidor não será executado. A saída se parece com esta:

```Output
Triggering SEH exception
Executing SEH __except block
```

Se você usar **`/EHsc`** o para compilar o código e `CPPEX` for definido usando `/DCPPEX` (para que uma exceção de C++ seja lançada), o `TestClass` destruidor será executado e a saída terá esta aparência:

```Output
Throwing C++ exception
Destroying TestClass!
Executing SEH __except block
```

Se você usar **`/EHa`** o para compilar o código, o `TestClass` destruidor executará se a exceção foi gerada usando `std::throw` ou usando Seh para disparar a exceção. Ou seja, se `CPPEX` é definido ou não. A saída se parece com esta:

```Output
Throwing C++ exception
Destroying TestClass!
Executing SEH __except block
```

Para obter mais informações, consulte [ `/EH` (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md).

**ENCERRAR específico da Microsoft**

## <a name="see-also"></a>Confira também

[Tratamento de exceção](../cpp/exception-handling-in-visual-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[`<exception>`](../standard-library/exception.md)<br/>
[Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md)<br/>
[Manipulação de exceção estruturada (Windows)](/windows/win32/debug/structured-exception-handling)
