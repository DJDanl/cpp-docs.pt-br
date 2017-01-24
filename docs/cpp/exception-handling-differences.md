---
title: "Diferen&#231;as de tratamento de exce&#231;&#245;es | Microsoft Docs"
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
  - "tratamento de exceção de C++, s. tratamento estruturado de exceções"
  - "exceções, classe wrapper"
  - "tratamento estruturado de exceções, vs. tratamento de exceção C++"
  - "tratamento estruturado de exceções, vs. não estruturado"
  - "classes wrapper, exceção C"
ms.assetid: f21d1944-4810-468e-b02a-9f77da4138c9
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Diferen&#231;as de tratamento de exce&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A principal diferença entre o tratamento de exceções estruturado e o tratamento de exceções de C\+\+ é que o modelo do tratamento de exceções de C\+\+ lida com tipos, enquanto o modelo de tratamento de exceções estruturado do C lida exceções de um tipo — especificamente, `unsigned int`.  Ou seja, as exceções de C são identificadas por um valor inteiro sem sinal, enquanto as exceções de C\+\+ são identificadas pelo tipo de dados.  Quando uma exceção é gerada em C, cada manipulador possível executa um filtro que examina o contexto da exceção de C e determine se aceitará a exceção, a transmitirá para algum outro manipulador, ou a ignorará.  Quando uma exceção é gerada em C\+\+, ela pode ser de qualquer tipo.  
  
 Uma segunda diferença é que o modelo de tratamento de exceções estruturado de C é chamado de "assíncrono", onde as exceções ocorrem secundariamente ao fluxo de controle normal.  O mecanismo de tratamento de exceções de C\+\+ é totalmente "síncrono", o que significa que as exceções ocorrem apenas quando são geradas.  
  
 Se a exceção de C é gerada em um programa C\/C\+\+, pode ser tratada por um manipulador de exceções estruturado com o filtro associado ou por um manipulador de **catch** de C\+\+, seja qual estiver dinamicamente mais próximo ao contexto da exceção.  Por exemplo, o seguinte programa de C\+\+ gera uma exceção dentro de um contexto **try** de C\+\+:  
  
## Exemplo  
  
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
  
  **In finally.**  
**Caught a C exception.**   
##  <a name="_core_c_exception_wrapper_class"></a> Classe de wrapper exceção de C  
 Em um exemplo simples como o acima, a exceção de C pode ser capturada somente por um manipulador de **catch** de reticências \(**...**\).  Nenhuma informação sobre o tipo ou a natureza de exceção é comunicada ao manipulador.  Ainda que este método funcione, em alguns casos pode ser necessário definir uma transformação entre os dois modelos de tratamento de exceções para que cada exceção de C seja associada a uma classe específica.  Para fazer isso, você pode definir a classe da exceção de C como "wrapper", que pode ser usada ou derivada de para atribuir um tipo específico da classe a uma exceção de C.  Ao fazer isso, cada exceção de C pode ser tratada pelo manipulador **catch** de C\+\+, mais separadamente do que no exemplo anterior.  
  
 Sua classe wrapper pode ter uma interface que consiste em algumas funções de membro que determinam o valor de exceção, e que acessam informações estendidas de contexto de exceção fornecidas pelo modelo da exceção de C.  Você também pode desejar definir um construtor padrão e um construtor que aceite um argumento `unsigned int` \(para fornecer para a representação subjacente da exceção de C\) e um construtor de cópia bit a bit.  O seguinte é uma possível implementação da classe wrapper de exceção do C:  
  
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
  
 Para usar essa classe, você instala uma função personalizada de tradução da exceção de C, chamada pelo mecanismo interno de tratamento de exceções sempre que uma exceção de C é lançada.  Dentro de sua função de tradução, você pode gerar qualquer exceção digitada \(talvez um tipo `SE_Exception`, ou um tipo de classe derivada de `SE_Exception`\) que possa ser capturada por um manipulador de correspondência C\+\+ **catch** adequado.  A função de tradução só pode retornar, o que indica que ela não conseguiu tratar a exceção.  Se a própria função de conversão criar uma exceção de C, [terminate](../c-runtime-library/reference/terminate-crt.md) é chamado.  
  
 Para especificar uma função personalizada de tradução, chame a função de [\_set\_se\_translator](../c-runtime-library/reference/set-se-translator.md) com o nome da função de translação como seu único argumento.  A função de tradução que você grava é chamada uma vez para cada invocação de função na pilha que tem blocos **try**.  Não há nenhuma função padrão de tradução; se você não especificar uma chamando `_set_se_translator`, a exceção de C só pode ser capturada por um manipulador de **catch** de reticências.  
  
## Exemplo  
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
  
  **In trans\_func.**  
**In finally**  
**Caught a \_\_try exception with SE\_Exception.**  
**nSE \= 0xc0000094**   
## Consulte também  
 [Combinando C \(estrutura\) e exceções de C\+\+](../Topic/Mixing%20C%20\(Structured\)%20and%20C++%20Exceptions.md)