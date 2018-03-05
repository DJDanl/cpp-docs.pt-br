---
title: "Diferenças de tratamento de exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 63fff00222aa083bcb392e0d71411bfcf5c0f418
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exception-handling-differences"></a>Diferenças de tratamento de exceções
A principal diferença entre o tratamento de exceções estruturado e o tratamento de exceções de C++ é que o modelo do tratamento de exceções de C++ lida com tipos, enquanto o modelo de tratamento de exceções estruturado do C lida exceções de um tipo — especificamente, `unsigned int`. Ou seja, as exceções de C são identificadas por um valor inteiro sem sinal, enquanto as exceções de C++ são identificadas pelo tipo de dados. Quando uma exceção é gerada em C, cada manipulador possível executa um filtro que examina o contexto da exceção de C e determine se aceitará a exceção, a transmitirá para algum outro manipulador, ou a ignorará. Quando uma exceção é gerada em C++, ela pode ser de qualquer tipo.  
  
 Uma segunda diferença é que o modelo de tratamento de exceções estruturado de C é chamado de "assíncrono", onde as exceções ocorrem secundariamente ao fluxo de controle normal. O mecanismo de tratamento de exceções de C++ é totalmente "síncrono", o que significa que as exceções ocorrem apenas quando são geradas.  
  
 Se uma exceção de C é gerada em um programa C++, ela pode ser tratada por um manipulador de exceções estruturado com seu filtro associado ou por um C++ **catch** manipulador, o que for dinamicamente mais perto o contexto de exceção. Por exemplo, o programa C++ a seguir gera uma exceção de C dentro de um C++ **tente** contexto:  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
##  <a name="_core_c_exception_wrapper_class"></a>Classe de invólucro de exceção C  
 Um exemplo simples como acima, a exceção de C pode ser capturada somente por um sinal de reticências (**...** ) **catch** manipulador. Nenhuma informação sobre o tipo ou a natureza de exceção é comunicada ao manipulador. Ainda que este método funcione, em alguns casos pode ser necessário definir uma transformação entre os dois modelos de tratamento de exceções para que cada exceção de C seja associada a uma classe específica. Para fazer isso, você pode definir a classe da exceção de C como "wrapper", que pode ser usada ou derivada de para atribuir um tipo específico da classe a uma exceção de C. Ao fazer isso, cada exceção C pode ser tratada por um C++ **catch** manipulador separadamente que no exemplo anterior.  
  
 Sua classe wrapper pode ter uma interface que consiste em algumas funções de membro que determinam o valor de exceção, e que acessam informações estendidas de contexto de exceção fornecidas pelo modelo da exceção de C. Você também pode desejar definir um construtor padrão e um construtor que aceite um argumento `unsigned int` (para fornecer para a representação subjacente da exceção de C) e um construtor de cópia bit a bit. O seguinte é uma possível implementação da classe wrapper de exceção do C:  
  
```  
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
  
 Para usar essa classe, você instala uma função personalizada de tradução da exceção de C, chamada pelo mecanismo interno de tratamento de exceções sempre que uma exceção de C é lançada. Dentro de sua função de conversão, você pode lançar qualquer exceção tipada (talvez um `SE_Exception` um tipo de classe ou tipo derivado de `SE_Exception`) que pode ser capturado por um C++ correspondente adequado **catch** manipulador. A função de tradução só pode retornar, o que indica que ela não conseguiu tratar a exceção. Se a própria função de conversão gera uma exceção de C, [encerrar](../c-runtime-library/reference/terminate-crt.md) é chamado.  
  
 Para especificar uma função de conversão personalizado, chame o [set_se_translator](../c-runtime-library/reference/set-se-translator.md) função com o nome da sua função de conversão como seu único argumento. A função de conversão que você escreve é chamada uma vez para cada invocação de função na pilha que tem **tente** blocos. Não há nenhuma função de conversão padrão; Se você não especificar um chamando `_set_se_translator`, a exceção de C só pode ser capturada por reticências **catch** manipulador.  
  
## <a name="example"></a>Exemplo  
 Por exemplo, o código a seguir instala uma função personalizada de tradução e gerará a exceção de C que é envolvida pela classe `SE_Exception`:  
  
```  
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