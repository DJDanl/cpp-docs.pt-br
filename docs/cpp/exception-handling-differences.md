---
title: Tratar exceções estruturadas no C++
description: Como lidar com exceções estruturadas usando C++ o modelo de tratamento de exceções.
ms.date: 09/19/2019
helpviewer_keywords:
- structured exception handling [C++], vs. C++ exception handling
- structured exception handling [C++], vs. unstructured
- exceptions [C++], wrapper class
- C++ exception handling [C++], vs. structured exception handling
- wrapper classes [C++], C exception
ms.assetid: f21d1944-4810-468e-b02a-9f77da4138c9
ms.openlocfilehash: 0c0e458f576325034d77676d247020adedfa33e5
ms.sourcegitcommit: f907b15f50a6b945d0b87c03af0050946157d701
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/20/2019
ms.locfileid: "71158737"
---
# <a name="handle-structured-exceptions-in-c"></a>Tratar exceções estruturadas no C++

A principal diferença entre o tratamento de exceção estruturado (SEH C++ ) e o tratamento de C++ exceções é que o modelo de tratamento de exceções lida em tipos, enquanto o modelo de manipulação de exceção estruturada C lida com exceções de um tipo; especificamente, o **int não assinado**. Ou seja, as exceções de C são identificadas por um valor inteiro sem sinal, enquanto as exceções de C++ são identificadas pelo tipo de dados. Quando uma exceção estruturada é gerada em C, cada manipulador possível executa um filtro que examina o contexto de exceção C e determina se deve aceitar a exceção, passá-la para algum outro manipulador ou ignorá-la. Quando uma exceção é gerada em C++, ela pode ser de qualquer tipo.

Uma segunda diferença é que o modelo de manipulação de exceção estruturada C é conhecido como *assíncrono*, porque as exceções ocorrem secundários no fluxo de controle normal. O C++ mecanismo de tratamento de exceção é totalmente *síncrono*, o que significa que as exceções ocorrem somente quando são geradas.

Quando você usa a opção de compilador [o/EHs ou/EHsc](../build/reference/eh-exception-handling-model.md) , C++ nenhum manipulador de exceção lida com exceções estruturadas. Essas exceções são tratadas apenas por manipuladores de exceção estruturados **__except** ou manipuladores de encerramento estruturado **__finally** . Para obter informações, consulte [manipulação de exceção estruturadaC++(C/)](structured-exception-handling-c-cpp.md).

Na opção de compilador [/EHA](../build/reference/eh-exception-handling-model.md) , se uma exceção C for gerada em um C++ programa, ela poderá ser tratada por um manipulador de exceção estruturado com seu filtro associado ou C++ por um manipulador **Catch** , o que for mais próximo da exceção noticioso. Por exemplo, este programa C++ de exemplo gera uma exceção C dentro C++ de um contexto **try** :

## <a name="example---catch-a-c-exception-in-a-c-catch-block"></a>Exemplo – capturar uma exceção de C em C++ um bloco catch

```cpp
// exceptions_Exception_Handling_Differences.cpp
// compile with: /EHa
#include <iostream>

using namespace std;
void SEHFunc( void );

int main() {
   try {
      SEHFunc();
   }
   catch( ... ) {
      cout << "Caught a C exception."<< endl;
   }
}

void SEHFunc() {
   __try {
      int x, y = 0;
      x = 5 / y;
   }
   __finally {
      cout << "In finally." << endl;
   }
}
```

```Output
In finally.
Caught a C exception.
```

## <a name="c-exception-wrapper-classes"></a>Classes de wrapper de exceção C

Em um exemplo simples como o mostrado acima, a exceção C só pode ser capturada por uma elipse ( **...** ) manipulador **Catch** . Nenhuma informação sobre o tipo ou a natureza de exceção é comunicada ao manipulador. Embora esse método funcione, em alguns casos, talvez você queira definir uma transformação entre os dois modelos de manipulação de exceção para que cada exceção C seja associada a uma classe específica. Para transformar uma, você pode definir uma classe "wrapper" de exceção C, que pode ser usada ou derivada de para atribuir um tipo de classe específico a uma exceção de C. Ao fazer isso, cada exceção de C pode ser tratada separadamente por um C++ manipulador **Catch** específico, em vez de todos eles em um único manipulador.

Sua classe wrapper pode ter uma interface que consiste em algumas funções de membro que determinam o valor de exceção, e que acessam informações estendidas de contexto de exceção fornecidas pelo modelo da exceção de C. Você também pode querer definir um construtor padrão e um construtor que aceite um argumento **int não assinado** (para fornecer a representação de exceção de C subjacente) e um construtor de cópia bit-a-bit. Aqui está uma possível implementação de uma classe de wrapper de exceção C:

```cpp
// exceptions_Exception_Handling_Differences2.cpp
// compile with: /c
class SE_Exception {
private:
   SE_Exception() {}
   SE_Exception( SE_Exception& ) {}
   unsigned int nSE;
public:
   SE_Exception( unsigned int n ) : nSE( n ) {}
   ~SE_Exception() {}
   unsigned int getSeNumber() {
      return nSE;
   }
};
```

Para usar essa classe, instale uma função de tradução de exceção C personalizada que é chamada pelo mecanismo de manipulação de exceção interna sempre que uma exceção C é lançada. Dentro de sua função de conversão, você pode lançar qualquer exceção tipada `SE_Exception` (talvez um tipo ou um tipo de `SE_Exception`classe derivado de) que possa ser capturado por C++ um manipulador **Catch** correspondente apropriado. Em vez disso, a função translation pode retornar, o que indica que ela não trata a exceção. Se a própria função de conversão gerar uma exceção C, [Terminate](../c-runtime-library/reference/terminate-crt.md) será chamado.

Para especificar uma função de tradução personalizada, chame a função [_set_se_translator](../c-runtime-library/reference/set-se-translator.md) com o nome da sua função de tradução como seu único argumento. A função de tradução que você escreve é chamada uma vez para cada invocação de função na pilha que tem blocos **try** . Não há nenhuma função de tradução padrão; Se você não especificar um chamando **_set_se_translator**, a exceção C só poderá ser detectada por um manipulador **Catch** de reticências.

## <a name="example---use-a-custom-translation-function"></a>Exemplo – usar uma função de tradução personalizada

Por exemplo, o código a seguir instala uma função personalizada de tradução e gerará a exceção de C que é envolvida pela classe `SE_Exception`:

```cpp
// exceptions_Exception_Handling_Differences3.cpp
// compile with: /EHa
#include <stdio.h>
#include <eh.h>
#include <windows.h>

class SE_Exception {
private:
   SE_Exception() {}
   unsigned int nSE;
public:
   SE_Exception( SE_Exception& e) : nSE(e.nSE) {}
   SE_Exception(unsigned int n) : nSE(n) {}
   ~SE_Exception() {}
   unsigned int getSeNumber() { return nSE; }
};

void SEFunc() {
    __try {
        int x, y = 0;
        x = 5 / y;
    }
    __finally {
        printf_s( "In finally\n" );
    }
}

void trans_func( unsigned int u, _EXCEPTION_POINTERS* pExp ) {
    printf_s( "In trans_func.\n" );
    throw SE_Exception( u );
}

int main() {
    _set_se_translator( trans_func );
    try {
        SEFunc();
    }
    catch( SE_Exception e ) {
        printf_s( "Caught a __try exception with SE_Exception.\n" );
        printf_s( "nSE = 0x%x\n", e.getSeNumber() );
    }
}
```

```Output
In trans_func.
In finally
Caught a __try exception with SE_Exception.
nSE = 0xc0000094
```

## <a name="see-also"></a>Consulte também

[Misturando C (estruturado C++ ) e exceções](../cpp/mixing-c-structured-and-cpp-exceptions.md)
