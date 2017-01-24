---
title: "Instru&#231;&#227;o switch (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "default"
  - "default_cpp"
  - "switch"
  - "switch_cpp"
  - "case"
  - "case_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave case [C++], em instruções switch"
  - "palavra-chave default [C++]"
  - "palavra-chave switch [C++]"
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o switch (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.  
  
## Sintaxe  
  
```  
  
      switch ( expression )  
   case constant-expression : statement  
   [default  : statement]  
```  
  
## Comentários  
 A expressão *expression* deve ser de um tipo integral ou de um tipo de classe para o qual haja uma conversão inequívoca em um tipo integral.  A promoção da integral é executada conforme descrito em [Promoções de integral](../misc/integral-promotions.md).  
  
 O corpo da instrução `switch` consiste em uma série de rótulos **case** e um rótulo **default** opcional.  Duas expressões de constantes em instruções **case** não podem ser avaliadas com o mesmo valor.  O rótulo **default** só pode aparecer uma vez.  As instruções rotuladas não são requisitos sintáticos, mas a instrução `switch` fica sem sentido sem elas.   A instrução default não precisa vir no final; ela pode aparecer em qualquer lugar no corpo da instrução switch.  Um rótulo case ou default só pode aparecer dentro de uma instrução switch.  
  
 Em cada rótulo **case**, *constant\-expression* é convertida no tipo de *expression* e comparada com *expression* para verificar se há igualdade.  O controle passa para a instrução na qual **case** *constant\-expression* corresponde ao valor de *expression*.  O comportamento resultante é mostrado na tabela a seguir.  
  
### Comportamento da instrução switch  
  
|Condição|Ação|  
|--------------|----------|  
|O valor convertido corresponde ao da expressão de controle promovida.|O controle é transferido para a instrução após esse rótulo.|  
|Nenhuma das constantes corresponde às constantes nos rótulos **case**; um rótulo **default** está presente.|O controle é transferido para o rótulo **default**.|  
|Nenhuma das constantes corresponde às constantes nos rótulos **case**; um rótulo **default** não está presente.|O controle é transferido para a instrução após a instrução `switch`.|  
  
 Se uma expressão correspondente for encontrada, o controle não será impedido pelos rótulos **case** ou **default** subsequentes.  A instrução [break](../cpp/break-statement-cpp.md) é usada para parar a execução e transferir o controle para a instrução após a instrução `switch`.  Sem uma instrução **break**, cada instrução desde o rótulo **case** correspondido até o final da `switch`, incluindo o **default**, é executada.  Por exemplo:  
  
```  
// switch_statement1.cpp  
#include <stdio.h>  
  
int main() {  
   char *buffer = "Any character stream";  
   int capa, lettera, nota;  
   char c;  
   capa = lettera = nota = 0;  
  
   while ( c = *buffer++ )   // Walks buffer until NULL  
   {  
      switch ( c )  
      {  
         case 'A':  
            capa++;  
            break;  
         case 'a':  
            lettera++;  
            break;  
         default:  
            nota++;  
      }  
   }  
   printf_s( "\nUppercase a: %d\nLowercase a: %d\nTotal: %d\n",  
      capa, lettera, (capa + lettera + nota) );  
}  
```  
  
 No exemplo acima, `capa` será incrementado se `c` for `A` maiúsculo.  A instrução `break` após `capa++` termina a execução do corpo da instrução `switch` e passa o controle para o loop `while`.  Sem a instrução `break`, `lettera` e `nota` também seriam incrementados.  A instrução `break` para `case 'a'` cumpre finalidade semelhante.  Se `c` for `a` minúsculo, `lettera` será incrementado e a instrução `break` terminará o corpo da instrução `switch`.  Se `c` não for `a` nem `A`, a instrução `default` será executada.  
  
 Um bloco interno de uma instrução `switch` pode conter definições com inicializações, desde que elas sejam acessíveis, isto é, não sejam ignoradas por todos os caminhos de execução possíveis.  Os nomes introduzidos por meio dessas declarações têm escopo local.  Por exemplo:  
  
```  
// switch_statement2.cpp  
// C2360 expected  
#include <iostream>  
using namespace std;  
int main(int argc, char *argv[])  
{  
   switch( tolower( *argv[1] ) )  
   {  
       // Error. Unreachable declaration.  
       char szChEntered[] = "Character entered was: ";  
  
   case 'a' :  
       {  
       // Declaration of szChEntered OK. Local scope.  
       char szChEntered[] = "Character entered was: ";  
       cout << szChEntered << "a\n";  
       }  
       break;  
  
   case 'b' :  
       // Value of szChEntered undefined.  
       cout << szChEntered << "b\n";  
       break;  
  
   default:  
       // Value of szChEntered undefined.  
       cout << szChEntered << "neither a nor b\n";  
       break;  
   }  
}  
```  
  
 Uma instrução `switch` pode estar aninhada.  Nesses casos, os rótulos **case** ou **default** são associados à instrução `switch` mais próxima que os inclui.  
  
## Específico da Microsoft  
 O Microsoft C não limita o número de valores de case em uma instrução `switch`.  O número é limitado somente pela memória disponível.  O ANSI C requer que pelo menos 257 rótulos case sejam permitidos em uma instrução `switch`.  
  
 O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas.  Use a opção de compilador [\/Za](../build/reference/za-ze-disable-language-extensions.md) para desabilitar essas extensões.  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [\(NOTINBUILD\) Using Labels in the case Statement](http://msdn.microsoft.com/pt-br/a6ff057d-1aee-42ed-a28d-ee6a565b3197)