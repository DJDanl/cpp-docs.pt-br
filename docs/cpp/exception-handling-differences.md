---
title: Diferenças de tratamento de exceções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: dafb3c41bd490e7c123e1aefe9ccaa04a4e6b233
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942244"
---
# <a name="exception-handling-differences"></a>Diferenças de tratamento de exceções
A principal diferença entre o tratamento de exceções estruturado e tratamento de exceções C++ é que as ofertas de modelo em tipos de tratamento de exceções de C++, enquanto o C modelo de tratamento de exceções estruturado lida com exceções de um tipo — especificamente,  **int sem sinal**. Ou seja, as exceções de C são identificadas por um valor inteiro sem sinal, enquanto as exceções de C++ são identificadas pelo tipo de dados. Quando uma exceção é gerada em C, cada manipulador possível executa um filtro que examina o contexto da exceção de C e determine se aceitará a exceção, a transmitirá para algum outro manipulador, ou a ignorará. Quando uma exceção é gerada em C++, ela pode ser de qualquer tipo.  
  
 Uma segunda diferença é que o modelo de tratamento de exceções estruturado de C é chamado de "assíncrono", onde as exceções ocorrem secundariamente ao fluxo de controle normal. O mecanismo de tratamento de exceções de C++ é totalmente "síncrono", o que significa que as exceções ocorrem apenas quando são geradas.  
  
 Se uma exceção de C é gerada em um programa C++, ele pode ser tratado por um manipulador de exceção estruturada com o filtro associado ou por um C++ **catch** manipulador, seja qual estiver dinamicamente mais próxima do contexto de exceção. Por exemplo, o programa de C++ a seguir gera uma exceção dentro de um C++ **tente** contexto:  
  
## <a name="example"></a>Exemplo  
  
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
  
##  <a name="_core_c_exception_wrapper_class"></a> Classe de Wrapper de exceção de C  
 Um exemplo simples com o mostrado acima, a exceção de C pode ser capturada somente por um sinal de reticências (**...** ) **catch** manipulador. Nenhuma informação sobre o tipo ou a natureza de exceção é comunicada ao manipulador. Ainda que este método funcione, em alguns casos pode ser necessário definir uma transformação entre os dois modelos de tratamento de exceções para que cada exceção de C seja associada a uma classe específica. Para fazer isso, você pode definir a classe da exceção de C como "wrapper", que pode ser usada ou derivada de para atribuir um tipo específico da classe a uma exceção de C. Ao fazer isso, cada exceção de C pode ser tratada por um C++ **catch** manipulador mais separadamente do que no exemplo anterior.  
  
 Sua classe wrapper pode ter uma interface que consiste em algumas funções de membro que determinam o valor de exceção, e que acessam informações estendidas de contexto de exceção fornecidas pelo modelo da exceção de C. Você também pode ser conveniente definir um construtor padrão e um construtor que aceita uma **unsigned int** argumento (para fornecer para a representação de exceção subjacente do C) e um construtor de cópia bit a bit. O seguinte é uma possível implementação da classe wrapper de exceção do C:  
  
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
  
 Para usar essa classe, você instala uma função personalizada de tradução da exceção de C, chamada pelo mecanismo interno de tratamento de exceções sempre que uma exceção de C é lançada. Dentro de sua função de conversão, você pode gerar qualquer exceção digitada (talvez uma `SE_Exception` tipo ou um tipo de classe derivado `SE_Exception`) que pode ser capturada por um C++ correspondente apropriado **catch** manipulador. A função de tradução só pode retornar, o que indica que ela não conseguiu tratar a exceção. Se a própria função de conversão gera uma exceção de C [encerrar](../c-runtime-library/reference/terminate-crt.md) é chamado.  
  
 Para especificar uma função personalizada de tradução, chame o [set_se_translator](../c-runtime-library/reference/set-se-translator.md) função com o nome da sua função de conversão como seu único argumento. A função de tradução que você escreve é chamada uma vez para cada invocação de função na pilha que tem **tente** blocos. Não há nenhuma função de conversão padrão; Se você não especificar uma chamando `_set_se_translator`, a exceção de C só pode ser capturada por um sinal de reticências **catch** manipulador.  
  
## <a name="example"></a>Exemplo  
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
 [Combinação de exceções C (estruturadas) e C++](../cpp/mixing-c-structured-and-cpp-exceptions.md)