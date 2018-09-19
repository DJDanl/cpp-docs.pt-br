---
title: Tratar exceções estruturadas em C++ | Microsoft Docs
ms.custom: ''
ms.date: 08/14/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- structured exception handling [C++], vs. C++ exception handling
- structured exception handling [C++], vs. unstructured
- exceptions [C++], wrapper class
- C++ exception handling [C++], vs. structured exception handling
- wrapper classes [C++], C exception
ms.assetid: f21d1944-4810-468e-b02a-9f77da4138c9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48acd13aced14bfd8acbeb4c306a5749010636d7
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46086026"
---
# <a name="handle-structured-exceptions-in-c"></a>Tratar exceções estruturadas em C++

A principal diferença entre C estruturadas (SEH) de tratamento de exceções e tratamento de exceções C++ é que as ofertas de modelo em tipos de tratamento de exceções de C++, enquanto o C modelo de tratamento de exceções estruturado lida com exceções de um tipo; Especificamente, **unsigned int**. Ou seja, as exceções de C são identificadas por um valor inteiro sem sinal, enquanto as exceções de C++ são identificadas pelo tipo de dados. Quando uma exceção estruturada é gerada em C, cada manipulador possível executa um filtro que examina o contexto de exceção de C e determine se aceitará a exceção, passá-lo para outro manipulador ou ignorá-lo. Quando uma exceção é gerada em C++, ela pode ser de qualquer tipo.

Uma segunda diferença é que o modelo de tratamento de exceção estruturada de C é conhecido como *assíncrona*, porque as exceções ocorrem secundariamente ao fluxo de controle normal. O mecanismo de tratamento de exceções de C++ é totalmente *síncrona*, que significa que as exceções ocorrem apenas quando são geradas.

Quando você usa o [/EHs ou /EHsc](../build/reference/eh-exception-handling-model.md) opção de compilador, nenhum manipuladores de exceção C++ exceções identificador estruturado. Essas exceções são tratadas somente pelo **__catch** estruturado de manipuladores de exceção ou **Finally** estruturado manipuladores de término. Para obter informações, consulte [tratamento de exceções estruturado (C/C++)](structured-exception-handling-c-cpp.md).

Sob o [/EHa](../build/reference/eh-exception-handling-model.md) opção de compilador, se uma exceção de C é gerada em um programa C++, ele pode ser tratado por um manipulador de exceção estruturada com o filtro associado ou por um C++ **catch** manipulador, o que for dinamicamente mais próxima do contexto de exceção. Por exemplo, o programa de C++ a seguir gera uma exceção dentro de um C++ **tente** contexto:

## <a name="example---catch-a-c-exception-in-a-c-catch-block"></a>Exemplo – Catch bloco catch de uma exceção de C em um C++

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

## <a name="c-exception-wrapper-classes"></a>Classes de wrapper de exceção de C

Um exemplo simples com o mostrado acima, a exceção de C pode ser capturada somente por um sinal de reticências (**...** ) **catch** manipulador. Nenhuma informação sobre o tipo ou a natureza de exceção é comunicada ao manipulador. Embora esse método funcione, em alguns casos você talvez queira definir uma transformação entre os modelos de tratamento de exceção de dois para que cada exceção de C seja associada uma classe específica. Para fazer isso, você pode definir a classe da exceção de C como "wrapper", que pode ser usada ou derivada de para atribuir um tipo específico da classe a uma exceção de C. Ao fazer isso, a cada exceção de C pode ser tratada separadamente por um C++ específicas **catch** manipulador, em vez de todos eles em um único manipulador.

Sua classe wrapper pode ter uma interface que consiste em algumas funções de membro que determinam o valor de exceção, e que acessam informações estendidas de contexto de exceção fornecidas pelo modelo da exceção de C. Você também pode ser conveniente definir um construtor padrão e um construtor que aceita uma **unsigned int** argumento (para fornecer para a representação de exceção subjacente do C) e um construtor de cópia bit a bit. Aqui está uma possível implementação de uma classe de wrapper de exceção de C:

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

Para usar essa classe, instale uma função de conversão de exceção C personalizada que é chamada pela cada vez que uma exceção de C é gerada do mecanismo de tratamento de exceção interna. Dentro de sua função de conversão, você pode gerar qualquer exceção digitada (talvez uma `SE_Exception` tipo ou um tipo de classe derivado `SE_Exception`) que pode ser capturada por um C++ correspondente apropriado **catch** manipulador. A função de tradução só pode retornar, o que indica que ela não conseguiu tratar a exceção. Se a própria função de conversão gera uma exceção de C [encerrar](../c-runtime-library/reference/terminate-crt.md) é chamado.

Para especificar uma função personalizada de tradução, chame o [set_se_translator](../c-runtime-library/reference/set-se-translator.md) função com o nome da sua função de conversão como seu único argumento. A função de tradução que você escreve é chamada uma vez para cada invocação de função na pilha que tem **tente** blocos. Não há nenhuma função de conversão padrão; Se você não especificar uma chamando **set_se_translator**, a exceção de C só pode ser capturada por um sinal de reticências **catch** manipulador.

## <a name="example---use-a-custom-translation-function"></a>Exemplo - usar uma função personalizada de tradução

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

[Combinando C (estruturada) e exceções do C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)
