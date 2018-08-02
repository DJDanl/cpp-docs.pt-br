---
title: Usando saída ou retorno | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- Exit
dev_langs:
- C++
helpviewer_keywords:
- exit function
- return keyword [C++], using for program termination
ms.assetid: b5136c5c-2505-4229-8691-2a1d6a98760b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 47fb8ff09fc50557283a0f4e8ef0e159bc900e86
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39460939"
---
# <a name="using-exit-or-return"></a>Usando saída ou retorno
Quando você chama **saia** ou execute uma **retornar** instrução from `main`, objetos estáticos são destruídos na ordem inversa da inicialização. O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.  
  
## <a name="example"></a>Exemplo  
  
```cpp 
// using_exit_or_return1.cpp  
#include <stdio.h>  
class ShowData {  
public:  
   // Constructor opens a file.  
   ShowData( const char *szDev ) {  
   errno_t err;  
      err = fopen_s(&OutputDev, szDev, "w" );  
   }  
  
   // Destructor closes the file.  
   ~ShowData() { fclose( OutputDev ); }  
  
   // Disp function shows a string on the output device.  
   void Disp( char *szData ) {   
      fputs( szData, OutputDev );  
   }  
private:  
   FILE *OutputDev;  
};  
  
//  Define a static object of type ShowData. The output device  
//   selected is "CON" -- the standard output device.  
ShowData sd1 = "CON";  
  
//  Define another static object of type ShowData. The output  
//   is directed to a file called "HELLO.DAT"  
ShowData sd2 = "hello.dat";  
  
int main() {  
   sd1.Disp( "hello to default device\n" );  
   sd2.Disp( "hello to file hello.dat\n" );  
}  
```  
  
 No exemplo anterior, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada em `main`. Depois que esse programa terminar de usar o **retornar** instrução, primeiro `sd2` é destruído e, em seguida, `sd1`. O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos.   
  
 Outra maneira de escrever o código é declarar os objetos `ShowData` com escopo de bloco, permitindo que eles sejam destruídos quando saírem do escopo:  
  
```cpp 
int main() {  
   ShowData sd1, sd2( "hello.dat" );  
  
   sd1.Disp( "hello to default device\n" );  
   sd2.Disp( "hello to file hello.dat\n" );  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)