---
title: "/Zc:implicitNoexcept (especificadores de exce&#231;&#227;o impl&#237;citos) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/Zc:implicitNoexcept"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "/Zc:implicitNoexcept"
  - "Zc:implicitNoexcept"
  - "-Zc:implicitNoexcept"
ms.assetid: 71807652-6f9d-436b-899e-f52daa6f500b
caps.latest.revision: 8
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /Zc:implicitNoexcept (especificadores de exce&#231;&#227;o impl&#237;citos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando o **\/Zc:implicitNoexcept** opção for especificada, o compilador adiciona implícito [noexcept](../Topic/noexcept%20\(C++\).md) especificador de exceção para funções de membro especial definida pelo compilador e destruidores definidos pelo usuário e deallocators.  Por padrão, **\/Zc:implicitNoexcept** está habilitado em conformidade com o ISO C\+\+ 11 padrão.  Desativação dessa opção desativa implícita `noexcept` destruidores definidos pelo usuário e dealloacators e funções de membro especial definida pelo compilador.  
  
## Sintaxe  
  
```vb  
/Zc:implicitNoexcept[-]  
```  
  
#### Parâmetros  
  
## Comentários  
 Por padrão e se **\/Zc:implicitNoexcept** for especificado, o compilador seguirá a seção 15.4 da ISO C\+\+ 11 padrão e adiciona implicitamente uma `noexcept` especificador de exceção para cada função de membro especial declarado implicitamente ou explicitamente usadas como padrão, o construtor padrão, construtor de cópia, movimentação construtor, destruidor, operador de atribuição de cópia ou operador de atribuição de movimentação — e cada função de destruidor ou deallocator definida pelo usuário.  Um deallocator definida pelo usuário tem implícito `noexcept(true)` especificador de exceção.  Para os destruidores definidos pelo usuário, o especificador de exceção implícita é `noexcept(true)` a menos que uma classe de membro independente ou classe base tem um destruidor não é `noexcept(true)`.  Para funções de membro especial geradas pelo compilador, se qualquer função invocada diretamente por essa função é efetivamente `noexcept(false)`, o especificador de exceção implícita é `noexcept(false)`.  Caso contrário, o especificador de exceção implícita é `noexcept(true)`.  
  
 O compilador não gera um especificador de exceção implícita para funções declaradas usando explícita `noexcept` ou `throw` especificadores ou `__declspec(nothrow)` atributo.  
  
 Se a opção é desativada, especificando **\/Zc:implicitNoexcept\-**, sem especificadores de exceção implícitas são geradas pelo compilador.  Esse comportamento é o mesmo que o Visual Studio 2013, onde os destruidores e deallocators que não tinham especificadores de exceção poderia ter `throw` instruções.  Por padrão e quando **\/Zc:implicitNoexcept** for especificado, se um `throw` declaração é encontrada em tempo de execução em uma função com implícito `noexcept(true)` especificador, ele faz com que uma chamada imediata de `std::terminate`, e o comportamento normal de desenrolamento de manipuladores de exceção não é garantido.  Para ajudar a identificar esta situação, o compilador gera [Aviso do compilador \(nível 1\) C4297](../Topic/Compiler%20Warning%20\(level%201\)%20C4297.md).  Se o `throw` é intencional, é recomendável alterar sua declaração de função para ter explícito `noexcept(false)` especificador em vez de usar **\/Zc:implicitNoexcept\-**.  
  
 Este exemplo mostra como um destruidor definido pelo usuário que não tem nenhum especificador explícitas de exceção se comporta quando o **\/Zc:implicitNoexcept** opção é definida ou desabilitada.  Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 implicitNoexcept.cpp`.  Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:implicitNoexcept-implicitNoexcept.cpp`.  
  
```  
// implicitNoexcept.cpp  
// Compile by using: cl /EHsc /W4 implicitNoexcept.cpp  
// Compile by using: cl /EHsc /W4 /Zc:implicitNoexcept- implicitNoexcept.cpp  
  
#include <iostream>  
#include <cstdlib>      // for std::exit, EXIT_FAILURE, EXIT_SUCCESS  
#include <exception>    // for std::set_terminate  
  
void my_terminate()  
{  
    std::cout << "Unexpected throw caused std::terminate" << std::endl;  
    std::cout << "Exit returning EXIT_FAILURE" << std::endl;  
    std::exit(EXIT_FAILURE);  
}  
  
struct A {  
    // Explicit noexcept overrides implicit exception specification  
    ~A() noexcept(false) {  
        throw 1;  
    }  
};  
  
struct B : public A {  
    // Compiler-generated ~B() definition inherits noexcept(false)  
    ~B() = default;  
};  
  
struct C {  
    // By default, the compiler generates an implicit noexcept(true)  
    // specifier for this user-defined destructor. To enable it to  
    // throw an exception, use an explicit noexcept(false) specifier,  
    // or compile by using /Zc:implicitNoexcept-  
    ~C() {    
        throw 1; // C4297, calls std::terminate() at run time  
    }  
};  
  
struct D : public C {  
    // This destructor gets the implicit specifier of its base.  
    ~D() = default;  
};  
  
int main()  
{  
    std::set_terminate(my_terminate);  
  
    try  
    {  
        {  
            B b;   
        }  
    }  
    catch (...)  
    {  
        // exception should reach here in all cases  
        std::cout << "~B Exception caught" << std::endl;  
    }  
    try  
    {  
        {  
            D d;  
        }  
    }  
    catch (...)  
    {  
        // exception should not reach here if /Zc:implicitNoexcept  
        std::cout << "~D Exception caught" << std::endl;  
    }  
    std::cout << "Exit returning EXIT_SUCCESS" << std::endl;  
    return EXIT_SUCCESS;  
}  
  
```  
  
 Quando compilado usando a configuração padrão **\/Zc:implicitNoexcept**, o exemplo gera esta saída:  
  
  **~ Exceção de B**  
**Throw inesperado causado std::terminate**  
**Sair retornando EXIT\_FAILURE** Quando compilado usando a configuração **\/Zc:implicitNoexcept\-**, o exemplo gera esta saída:  
  
  **~ Exceção de B**  
**~ D exceção capturada**  
**Sair retornando EXIT\_SUCCESS** Para obter mais informações sobre problemas de conformidade no Visual C\+\+, consulte [Comportamento não padrão](../Topic/Nonstandard%20Behavior.md).  
  
### Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto.  Para obter detalhes, consulte [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione a pasta **C\/C\+\+**.  
  
3.  Selecione a página de propriedades de **Linha de Comando**.  
  
4.  Modificar o **Opções adicionais** propriedade incluir **\/Zc:implicitNoexcept** ou **\/Zc:implicitNoexcept\-** e, em seguida, escolha **OK**.  
  
## Consulte também  
 [\/Zc \(conformidade\)](../../build/reference/zc-conformance.md)   
 [noexcept](../Topic/noexcept%20\(C++\).md)   
 [Especificações de exceção \(lançar\)](../../cpp/exception-specifications-throw-cpp.md)   
 [terminate](../Topic/terminate%20\(%3Cexception%3E\).md)