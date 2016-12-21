---
title: "Exce&#231;&#245;es C++ sem tratamento | Microsoft Docs"
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
  - "tratamento de exceção de C++, exceções não tratadas"
  - "palavra-chave catch [C++], manipulador não encontrado"
  - "manipuladores de eventos, exceções não tratadas"
  - "exceções, não tratado"
  - "exceções não tratadas"
ms.assetid: 13f09c53-9254-4407-9db9-14e730e047cc
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#245;es C++ sem tratamento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se um manipulador correspondente \(ou o manipulador **catch** de reticências\) não for encontrado para a exceção atual, a função predefinida de tempo de execução `terminate` será chamada. \(Você também pode chamar explicitamente `terminate` em qualquer um dos manipuladores.\) A ação padrão de `terminate` é chamar `abort`.  Se você quiser que `terminate` chame outra função em seu programa antes de sair do aplicativo, chame a função `set_terminate` com o nome da função a ser chamada como seu único argumento.  Você pode chamar `set_terminate` em qualquer momento do programa.  A rotina `terminate` sempre chama a função last especificada como um argumento para `set_terminate`.  
  
## Exemplo  
 O exemplo a seguir gera uma exceção `char *`, mas não contém um manipulador designado para capturar exceções de tipo `char *`.  A chamada para `set_terminate` instrui `terminate` a chamar `term_func`.  
  
```  
// exceptions_Unhandled_Exceptions.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
void term_func() {  
   cout << "term_func was called by terminate." << endl;  
   exit( -1 );  
}  
int main() {  
   try  
   {  
      set_terminate( term_func );  
      throw "Out of memory!"; // No catch handler for this exception  
   }  
   catch( int )  
   {  
      cout << "Integer exception raised." << endl;  
   }  
   return 0;  
}  
```  
  
## Saída  
  
```  
term_func was called by terminate.  
```  
  
 A função `term_func` deve encerrar o programa ou o thread atual, idealmente chamando `exit`.  Caso contrário, retorna para seu chamador, `abort` é chamado.  
  
## Consulte também  
 [Tratamento de exceções C\+\+](../cpp/cpp-exception-handling.md)