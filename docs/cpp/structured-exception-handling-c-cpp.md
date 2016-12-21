---
title: "Tratamento de exce&#231;&#245;es estruturado (C/C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção de C++, manipuladores de exceção"
  - "tratamento de exceção de C++, manipuladores de encerramento"
  - "tratamento estruturado de exceções"
  - "manipuladores de encerramento, tratando exceções em C++"
  - "palavra-chave try-catch [C++], manipuladores de exceção"
  - "palavra-chave try-catch [C++], manipuladores de encerramento"
ms.assetid: dd3b647d-c269-43a8-aab9-ad1458712976
caps.latest.revision: 14
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tratamento de exce&#231;&#245;es estruturado (C/C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ainda que o Windows e Visual C\+\+ suportem o tratamento de exceções \(SEH\), recomendamos o uso do tratamento de exceções do padrão ISO C\+\+, pois ele torna o código mais portável e flexível.  Entretanto, no código existente ou em tipos específicos de programas, você ainda pode precisar do SEH.  
  
## Específico da Microsoft  
  
## Gramática  
 *try\-except\-statement* :  
  
 `__try` *compound\-statement*  
  
 `__except` \( `expression` \) *compound\-statement*  
  
## Comentários  
 Com o SEH, é possível garantir que os recursos, como blocos e arquivos de memória, estejam corretos se a execução for finalizada inesperadamente.  Você também pode controlar problemas específicos como, por exemplo, memória insuficiente, usando um código estruturado e conciso que não confia em instruções `goto` ou em testes elaborados de códigos de retorno.  
  
 As instruções try\-except e try\-finally mencionadas neste artigo são extensões da Microsoft para a linguagem C.  Elas oferecem suporte ao SEH permitindo que os aplicativos controlem um programa após os eventos que, caso contrário, finalizariam a execução.  Ainda que o SEH funcione com arquivos de origem C\+\+, ele não é projetado especificamente para C\+\+.  Se você usar o SEH em um programa C\+\+ compilado com o uso da opção [\/EH](../build/reference/eh-exception-handling-model.md), além de determinados modificadores, os destruidores de objetos locais são chamados, mas outros comportamentos de execução podem não ser os esperados.  \(Para obter uma ilustração, consulte o exemplo mais adiante neste artigo.\) Na maioria dos casos, em vez do SEH, nós recomendamos que você use o padrão ISO de [Manipulação de exceção C\+\+](../cpp/try-throw-and-catch-statements-cpp.md), ao qual o Visual C\+\+ também oferece suporte.  Usando o tratamento de exceções C\+\+, é possível garantir que o seu código seja mais portátil e tratar exceções de qualquer tipo.  
  
 Se você tiver os módulos de C que usam SEH, é possível misturá\-los com os módulos C\+\+ que usam o tratamento de exceções de C\+\+.  Para obter informações, consulte [Diferenças de tratamento de exceções](../cpp/exception-handling-differences.md).  
  
 Existem dois mecanismos de SEH:  
  
-   [Manipuladores de exceção](../cpp/writing-an-exception-handler.md), que podem responder a ou ignorar a exceção.  
  
-   [Manipuladores de término](../cpp/writing-a-termination-handler.md), que são chamados quando uma exceção causa o término em um bloco de código.  
  
 Esses dois tipos dos manipuladores são distintos, mas estão intimamente relacionados por meio de um processo conhecido como "desenrolamento da pilha". Quando uma exceção ocorre, o Windows procura o manipulador de exceção recentemente instalado que está atualmente ativo.  O manipulador pode executar uma de três ações:  
  
-   Não reconhecer a exceção e não passar o controle para outros manipuladores.  
  
-   Reconhecer a exceção mas ignorá\-la.  
  
-   Confirmar a exceção e manipulá\-la.  
  
 O manipulador de exceções que reconhece a exceção pode não estar na função em execução no momento da exceção.  Em alguns casos, ele pode estar em uma função muito mais alta na pilha.  A função em execução no momento e quaisquer outras funções no quadro de pilhas são terminadas.  Durante esse processo, a pilha é "desenrolada"; ou seja, as variáveis locais das funções finalizadas \(a menos que sejam `static`\) são limpas da pilha.  
  
 Como o sistema operacional desenrola a pilha, ele chama todos os manipuladores de término escritos para cada função.  Usando um manipulador de término, você pode limpar os recursos que, caso contrário, permaneceriam abertos devido a um encerramento anormal.  Se você tiver entrado em uma seção crítica, será possível sair no manipulador de término.  Se o programa for fechar, será possível executar outras tarefas de manutenção como fechar e remover os arquivos temporários.  
  
 Para obter mais informações, consulte:  
  
-   [Escrevendo um manipulador de exceção](../cpp/writing-an-exception-handler.md)  
  
-   [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)  
  
-   [Usando tratamento de exceções estruturado com C\+\+](../Topic/Using%20Structured%20Exception%20Handling%20with%20C++.md)  
  
## Exemplo  
 Conforme mencionado anteriormente, os destruidores de objetos locais são chamados se você usar SEH em um programa C\/C\+\+ e compilar usando a opção **\/EH** com determinados modificadores, como, por exemplo, **\/EHsc** e **\/EHa**.  No entanto, o comportamento durante a execução pode não ser o esperado se você também estiver usando exceções C\+\+.  O exemplo a seguir demonstra essas diferenças de comportamento.  
  
```cpp  
#include <stdio.h>  
#include <Windows.h>  
#include <exception>  
  
class TestClass  
{  
public:  
    ~TestClass()  
    {  
        printf("Destroying TestClass!\r\n");  
    }  
};  
  
__declspec(noinline) void TestCPPEX()  
{  
#ifdef CPPEX  
    printf("Throwing C++ exception\r\n");  
    throw std::exception("");  
#else  
    printf("Triggering SEH exception\r\n");  
    volatile int *pInt = 0x00000000;  
    *pInt = 20;  
#endif  
}  
  
__declspec(noinline) void TestExceptions()  
{  
    TestClass d;  
    TestCPPEX();  
}  
  
int main()  
{  
    __try  
    {  
        TestExceptions();  
    }  
    __except(EXCEPTION_EXECUTE_HANDLER)  
    {  
        printf("Executing SEH __except block\r\n");  
    }  
  
    return 0;  
}  
  
```  
  
 Se você usar **\/EHsc** para compilar esse código mas o controle de teste local `CPPEX` for indefinido, não haverá exceções de destruidor `TestClass` e a resposta terá esta aparência:  
  
  **Disparo de exceção de SEH**  
**Execução do bloco \_\_except de SEH** Se você usar **\/EHsc** para compilar o código e `CPPEX` for definido usando `/DCPPEX` \(de forma que a exceção C\+\+ seja lançada\), o destruidor `TestClass` será executado e o resultado terá esta aparência:  
  
  **Lançamento de uma exceção C\+\+**  
**Destruição de TestClass\!  Execução do bloco \_\_except de SEH**  Se você usar **\/EHa** para compilar o código, o destruidor `TestClass` será executado independente do lançamento da exceção usando `std::throw` ou usando SEH para disparar a exceção \(`CPPEX` definido ou não\).  O resultado terá a seguinte aparência:  
  
  **Lançamento de uma exceção C\+\+**  
**Destruição de TestClass\!  Execução do bloco \_\_except de SEH**  Para obter mais informações, consulte [\/EH \(modelo de tratamento de exceções\)](../build/reference/eh-exception-handling-model.md).  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Tratamento de Exceção](../cpp/exception-handling-in-visual-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [\<exception\>](../standard-library/exception.md)   
 [Erros e tratamento de exceções](../cpp/errors-and-exception-handling-modern-cpp.md)   
 [Structured Exception Handling \(Windows\)](http://msdn.microsoft.com/library/windows/desktop/ms680657.aspx)