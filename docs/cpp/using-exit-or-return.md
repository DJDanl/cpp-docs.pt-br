---
title: "Usando sa&#237;da ou retorno | Microsoft Docs"
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
  - "Exit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função exit"
  - "palavra-chave return [C++], usando para encerramento de programa"
ms.assetid: b5136c5c-2505-4229-8691-2a1d6a98760b
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando sa&#237;da ou retorno
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você chama **exit** ou executa uma instrução `return` a partir de **main**, os objetos estáticos são destruídos na ordem inversa da inicialização.  O exemplo a seguir mostra como realizar essa inicialização e as tarefas de limpeza.  
  
## Exemplo  
  
```  
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
  
 No exemplo anterior, os objetos estáticos `sd1` e `sd2` são criados e inicializados antes da entrada em `main`.  Depois que esse programa terminar de usar a instrução `return`, `sd2` será destruído primeiro, e depois `sd1`.  O destruidor da classe `ShowData` fecha os arquivos associados a esses objetos estáticos. \(Para obter mais informações sobre inicialização, construtores e destruidores, consulte o tópico sobre [Funções membro especiais](../misc/special-member-functions-cpp.md).\)  
  
 Outra maneira de escrever o código é declarar os objetos `ShowData` com escopo de bloco, permitindo que eles sejam destruídos quando saírem do escopo:  
  
```  
int main() {  
   ShowData sd1, sd2( "hello.dat" );  
  
   sd1.Disp( "hello to default device\n" );  
   sd2.Disp( "hello to file hello.dat\n" );  
}  
```  
  
## Consulte também  
 [Considerações de término adicionais](../cpp/additional-termination-considerations.md)