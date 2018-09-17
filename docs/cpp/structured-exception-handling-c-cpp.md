---
title: (C/C++) de manipulação de exceção estruturada | Microsoft Docs
ms.custom: ''
ms.date: 08/14/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- termination handlers [C++], handling exceptions in C++
- structured exception handling [C++]
- try-catch keyword [C++], exception handlers
- C++ exception handling, termination handlers
- try-catch keyword [C++], termination handlers
- C++ exception handling, exception handlers
ms.assetid: dd3b647d-c269-43a8-aab9-ad1458712976
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 861cb216dba1e8b3d451d6120dba897e06ba910a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713176"
---
# <a name="structured-exception-handling-cc"></a>Tratamento de exceções estruturado (C/C++)

Manipulação de exceção estruturada (SEH) é uma extensão da Microsoft para C para lidar com certas situações excepcionais de código, como falhas de hardware, normalmente. Embora o Windows e Visual C++ ofereçam suporte para SEH, recomendamos que você use o tratamento de exceções C++ padrão ISO, pois ele torna seu código mais portável e flexível. No entanto, para manter o código existente ou para tipos específicos de programas, você ainda pode precisar usar o SEH.

**Específico da Microsoft:**

## <a name="grammar"></a>Gramática

*Try-except-Statement&lt;1* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Try** *compound-statement* **EXCEPT** **(** *expressão* **)** *instrução composta*

*try-finally-statement* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**Try** *compound-statement* **Finally** *instrução composta*

## <a name="remarks"></a>Comentários

Com o SEH, é possível garantir que recursos como blocos de memória e os arquivos sejam liberados corretamente se a execução for finalizada inesperadamente. Você também pode lidar com problemas específicos — por exemplo, memória insuficiente — usando código estruturado e conciso que não dependem **goto** instruções ou em testes elaborados de códigos de retorno.

As instruções try-except e try-finally mencionadas neste artigo são extensões da Microsoft para a linguagem C. Elas oferecem suporte ao SEH permitindo que os aplicativos controlem um programa após os eventos que, caso contrário, finalizariam a execução. Ainda que o SEH funcione com arquivos de origem C++, ele não é projetado especificamente para C++. Se você usar SEH em um programa de C++ que você compila usando o [/EHa ou /EHsc](../build/reference/eh-exception-handling-model.md) opção, os destruidores para objetos locais são chamados, mas outros comportamentos de execução podem não ser o esperado. Para obter uma ilustração, consulte o exemplo mais adiante neste artigo. Na maioria dos casos, em vez do SEH é recomendável que você use o padrão ISO [tratamento de exceções C++](../cpp/try-throw-and-catch-statements-cpp.md), que também suporta Visual C++. Usando o tratamento de exceções C++, é possível garantir que o seu código seja mais portátil e tratar exceções de qualquer tipo.

Se você tiver código em C que usa SEH, pode combiná-lo com o código C++ que usa o tratamento de exceções C++. Para obter informações, consulte [tratar exceções estruturadas em C++](../cpp/exception-handling-differences.md).

Existem dois mecanismos de SEH:

- [Manipuladores de exceção](../cpp/writing-an-exception-handler.md), ou **EXCEPT** blocos, que podem responder a ou ignorar a exceção.

- [Manipuladores de terminação](../cpp/writing-a-termination-handler.md), ou **Finally** blocos, que sempre são chamados, se uma exceção causa o encerramento ou não.

Esses dois tipos dos manipuladores são distintos, mas estão intimamente relacionados por meio de um processo conhecido como "desenrolamento da pilha". Quando ocorre uma exceção estruturada, o Windows procura o manipulador de exceção instalado mais recentemente que está ativo no momento. O manipulador pode executar uma de três ações:

- Não reconhecer a exceção e não passar o controle para outros manipuladores.

- Reconhecer a exceção mas ignorá-la.

- Confirmar a exceção e manipulá-la.

O manipulador de exceções que reconhece a exceção pode não estar na função em execução no momento da exceção. Em alguns casos, ele pode estar em uma função muito mais alta na pilha. A função em execução no momento e quaisquer outras funções no quadro de pilhas são terminadas. Durante esse processo, a pilha é "desenrolada"; ou seja, variáveis locais de não-estático das funções finalizadas são limpas da pilha.

Como o sistema operacional desenrola a pilha, ele chama todos os manipuladores de término escritos para cada função. Usando um manipulador de término, você pode limpar os recursos que, caso contrário, permaneceriam abertos devido a um encerramento anormal. Se você inseriu uma seção crítica, você pode sair no manipulador de término. Se o programa for fechar, será possível executar outras tarefas de manutenção como fechar e remover os arquivos temporários.

## <a name="next-steps"></a>Próximas etapas

- [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)

- [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)

- [Tratar exceções estruturadas no C++](../cpp/exception-handling-differences.md)

## <a name="example"></a>Exemplo

Conforme mencionado anteriormente, os destruidores para objetos locais são chamados se você usar SEH em um programa C++ e compilá-lo usando o **/EHa** ou **/EHsc** opção. No entanto, o comportamento durante a execução pode não ser o esperado se você também estiver usando exceções C++. Este exemplo demonstra essas diferenças de comportamento.

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

Se você usar **/EHsc** para compilar esse código, mas a macro de controle de teste local `CPPEX` é indefinido, não há nenhuma execução do `TestClass` destruidor e a saída será assim:

```Output
Triggering SEH exception
Executing SEH __except block
```

Se você usar **/EHsc** para compilar o código e `CPPEX` é definida usando `/DCPPEX` (de modo que uma exceção C++ seja lançada), o `TestClass` destruidor é executado e a saída se parece com isso:

```Output
Throwing C++ exception
Destroying TestClass!
Executing SEH __except block
```

Se você usar **/EHa** para compilar o código, o `TestClass` destruidor é executado independentemente se a exceção foi gerada usando `std::throw` ou usando SEH para disparar a exceção, ou seja, se `CPPEX` definido ou não. O resultado terá a seguinte aparência:

```Output
Throwing C++ exception
Destroying TestClass!
Executing SEH __except block
```

Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)  
[Palavras-chave](../cpp/keywords-cpp.md)  
[\<exception>](../standard-library/exception.md)  
[Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)  
[(Windows) de tratamento de exceções estruturado](https://msdn.microsoft.com/library/windows/desktop/ms680657.aspx)  
