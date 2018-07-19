---
title: (C/C++) de manipulação de exceção estruturada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 64ff69a4ab75189dd069e774eb05266e6140ff77
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940489"
---
# <a name="structured-exception-handling-cc"></a>Tratamento de exceções estruturado (C/C++)
Ainda que o Windows e Visual C++ suportem o tratamento de exceções (SEH), recomendamos o uso do tratamento de exceções do padrão ISO C++, pois ele torna o código mais portável e flexível. Entretanto, no código existente ou em tipos específicos de programas, você ainda pode precisar do SEH.  
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
  
## <a name="grammar"></a>Gramática  
 *Try-except-Statement&lt;1* :  
  
 `__try` *instrução composta*  
  
 `__except` ( `expression` ) *instrução composta*  
  
## <a name="remarks"></a>Comentários  
 Com o SEH, é possível garantir que os recursos, como blocos e arquivos de memória, estejam corretos se a execução for finalizada inesperadamente. Você também pode lidar com problemas específicos — por exemplo, memória insuficiente — usando código estruturado e conciso que não dependem **goto** instruções ou em testes elaborados de códigos de retorno.  
  
 As instruções try-except e try-finally mencionadas neste artigo são extensões da Microsoft para a linguagem C. Elas oferecem suporte ao SEH permitindo que os aplicativos controlem um programa após os eventos que, caso contrário, finalizariam a execução. Ainda que o SEH funcione com arquivos de origem C++, ele não é projetado especificamente para C++. Se você usar SEH em um programa de C++ que você compila usando o [/EH](../build/reference/eh-exception-handling-model.md) opção — além de determinados modificadores — os destruidores de objetos locais são chamados, mas outros comportamentos de execução podem não ser o esperado. (Para obter uma ilustração, consulte o exemplo mais adiante neste artigo.) Na maioria dos casos, em vez do SEH é recomendável que você use o padrão ISO [tratamento de exceções C++](../cpp/try-throw-and-catch-statements-cpp.md), que também suporta Visual C++. Usando o tratamento de exceções C++, é possível garantir que o seu código seja mais portátil e tratar exceções de qualquer tipo.  
  
 Se você tiver os módulos de C que usam SEH, é possível misturá-los com os módulos C++ que usam o tratamento de exceções de C++. Para obter informações, consulte [diferenças de tratamento de exceção](../cpp/exception-handling-differences.md).  
  
 Existem dois mecanismos de SEH:  
  
-   [Manipuladores de exceção](../cpp/writing-an-exception-handler.md), que pode responder ou ignorar a exceção.  
  
-   [Manipuladores de terminação](../cpp/writing-a-termination-handler.md), que são chamados quando uma exceção causa o término em um bloco de código.  
  
 Esses dois tipos dos manipuladores são distintos, mas estão intimamente relacionados por meio de um processo conhecido como "desenrolamento da pilha". Quando uma exceção ocorre, o Windows procura o manipulador de exceção recentemente instalado que está atualmente ativo. O manipulador pode executar uma de três ações:  
  
-   Não reconhecer a exceção e não passar o controle para outros manipuladores.  
  
-   Reconhecer a exceção mas ignorá-la.  
  
-   Confirmar a exceção e manipulá-la.  
  
 O manipulador de exceções que reconhece a exceção pode não estar na função em execução no momento da exceção. Em alguns casos, ele pode estar em uma função muito mais alta na pilha. A função em execução no momento e quaisquer outras funções no quadro de pilhas são terminadas. Durante esse processo, a pilha é "desenrolada"; ou seja, variáveis locais das funções finalizadas — a menos que sejam **estático**— são limpas da pilha.  
  
 Como o sistema operacional desenrola a pilha, ele chama todos os manipuladores de término escritos para cada função. Usando um manipulador de término, você pode limpar os recursos que, caso contrário, permaneceriam abertos devido a um encerramento anormal. Se você tiver entrado em uma seção crítica, será possível sair no manipulador de término. Se o programa for fechar, será possível executar outras tarefas de manutenção como fechar e remover os arquivos temporários.  
  
 Para obter mais informações, consulte:  
  
-   [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)  
  
-   [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)  
  
-   [Usando tratamento de exceções estruturado com C++](../cpp/using-structured-exception-handling-with-cpp.md)  
  
## <a name="example"></a>Exemplo  
 Conforme mencionado anteriormente, os destruidores para objetos locais são chamados se você usar SEH em um programa C++ e compilá-lo usando o **/EH** opção com determinados modificadores — por exemplo, **/EHsc** e **/EHa**. No entanto, o comportamento durante a execução pode não ser o esperado se você também estiver usando exceções C++. O exemplo a seguir demonstra essas diferenças de comportamento.  
  
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
  
 Se você usar **/EHsc** para compilar esse código, mas o controle de teste local `CPPEX` é indefinido, não há nenhuma execução do `TestClass` destruidor e a saída será assim:  
  
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
  
 Se você usar **/EHa** para compilar o código, o `TestClass` destruidor é executado independentemente se a exceção foi gerada usando `std::throw` ou usando SEH para disparar a exceção (`CPPEX` definido ou não). O resultado terá a seguinte aparência:  
  
```Output  
Throwing C++ exception  
Destroying TestClass!  
Executing SEH __except block  
```  
  
 Para obter mais informações, consulte [/EH (modelo de tratamento de exceção)](../build/reference/eh-exception-handling-model.md).  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de exceções](../cpp/exception-handling-in-visual-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [\<exception>](../standard-library/exception.md)   
 [Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [(Windows) de tratamento de exceções estruturado](http://msdn.microsoft.com/library/windows/desktop/ms680657.aspx)