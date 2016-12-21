---
title: "Erros em potencial passando por objetos CRT em limites de DLL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "conflitos de DLL [C++]"
ms.assetid: c217ffd2-5d9a-4678-a1df-62a637a96460
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erros em potencial passando por objetos CRT em limites de DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você passa o tempo de execução de 2.0 management objects \(CRT\) C como os identificadores de arquivo, as localidades, e as variáveis de ambiente dentro ou fora de uma DLL \(chamadas de função pelo limite da DLL\), o pode ocorrer um comportamento inesperado se a DLL, bem como os arquivos que chamam na DLL, usam diferentes cópias das bibliotecas de CRT.  
  
 Um problema relacionado pode ocorrer quando você atribui a memória \(explicitamente com `new` ou `malloc`, ou implicitamente com `strdup`, `strstreambuf::str`, e assim por diante\) e passa um ponteiro por meio de um limite da DLL seja liberado.  Isso pode causar uma violação de acesso de memória ou pilha dano se a DLL e seus usuários usam diferentes cópias das bibliotecas de CRT.  
  
 Outro sintoma esse problema pode ser um erro na janela saída durante a depuração como:  
  
 HEAP \[\]: Endereço inválido especificado a RtlValidateHeap \(\#, \#\)  
  
## Causas  
 Cada cópia da biblioteca de CRT tem um estado separado e distinto.  Como tal, o CRT objetos como os identificadores de arquivo, variáveis de ambiente, e as localidades só são válidos para a cópia de CRT onde esses objetos são atribuídos ou conjunto de mídias.  Quando uma DLL e seus usuários usam diferentes cópias da biblioteca de CRT, você não pode passar esses objetos de CRT pelo limite da DLL e esperá\-los serem selecionadas corretamente no outro lado.  
  
 Além disso, para cada cópia da biblioteca de CRT tem seu próprio gerenciador de heap, atribuindo a memória em uma biblioteca de CRT e passar o ponteiro por meio de um limite da DLL a ser liberada por uma cópia diferente da biblioteca de CRT é uma causa potencial de corrupção do heap.  
  
 Se você criar seu DLL de modo que transmite objetos de CRT pelo limite ou aloca memória e aguarda a liberação de fora da DLL, você restringe os usuários do DLL para usar a mesma cópia da biblioteca de CRT que o DLL.  A DLL e seus usuários usarem a mesma cópia da biblioteca de CRT somente se ambos são vinculados à mesma versão da DLL de CRT.  Esse pode ser um problema se você combina os aplicativos criados com Visual C\+\+ 5.0 com DLL criados pelo Visual C\+\+ 4,1 ou anterior.  Como a versão da DLL de biblioteca de CRT usada pelo Visual C\+\+ 4,1 é msvcrt40.dll e aquele usado pelo Visual 5,0 é msvcrt.dll, você não pode criar seu aplicativo usar a mesma cópia da biblioteca de CRT que esses DLL.  
  
 Porém, há uma exceção.  Na versão em inglês dos EUA. U. e em outras versões localizadas do Windows 2000, como alemão, francês, e o Tcheco, uma versão do encaminhador de msvcrt40.dll \(versão 4,20\) é enviada.  No resultado, mesmo que o DLL seja vinculado com msvcrt40.dll e o usuário é vinculado a msvcrt.dll, você ainda estiver usando a mesma cópia da biblioteca de CRT porque todas as chamadas feitas a msvcrt40.dll serão encaminhados a msvcrt.dll.  
  
 No entanto esta versão do encaminhador de msvcrt40.dll não está disponível em algumas versões localizadas do Windows 2000, como japonês, coreano, o e o chinês.  Assim, se o aplicativo foi projetado para esses sistemas operacionais, é necessário um obtém uma versão atualizada da DLL que não confie em msvcrt40.dll ou altera seu aplicativo não confiar em usar a mesma cópia das bibliotecas de CRT.  Se você desenvolveu o DLL, significa recriá\-lo com o Visual C\+\+ 4,2 ou posterior.  Se for uma DLL de terceiros, você precisa contate o fornecedor para uma atualização.  
  
 Observe que essa versão da DLL do encaminhador de msvcrt40.dll \(versão 4,20\) não pode ser redistribuída.  
  
## Exemplo  
  
### Descrição  
 Esse exemplo passa um identificador de arquivo por meio de um limite da DLL.  
  
 A DLL e o arquivo são compilados com \/MD, o que compartilha uma única cópia de CRT.  
  
 Se você recria com \/MT de modo que usem cópias separadas de CRT, execute o test1Main.exe resultante leva a uma violação de acesso.  
  
### Código  
  
```  
// test1Dll.cpp  
// compile with: /MD /LD  
#include <stdio.h>  
__declspec(dllexport) void writeFile(FILE *stream)  
{  
   char   s[] = "this is a string\n";  
   fprintf( stream, "%s", s );  
   fclose( stream );  
}  
```  
  
### Código  
  
```  
// test1Main.cpp  
// compile with: /MD test1dll.lib  
#include <stdio.h>  
#include <process.h>  
void writeFile(FILE *stream);  
  
int main(void)  
{  
   FILE  * stream;  
   errno_t err = fopen_s( &stream, "fprintf.out", "w" );  
   writeFile(stream);  
   system( "type fprintf.out" );  
}  
```  
  
### Saída  
  
```  
this is a string  
```  
  
## Exemplo  
  
### Descrição  
 Esse exemplo passa variáveis de ambiente por meio de um limite da DLL.  
  
### Código  
  
```  
// test2Dll.cpp  
// compile with: /MT /LD  
#include <stdio.h>  
#include <stdlib.h>  
  
__declspec(dllexport) void readEnv()  
{  
   char *libvar;  
   size_t libvarsize;  
  
   /* Get the value of the MYLIB environment variable. */   
   _dupenv_s( &libvar, &libvarsize, "MYLIB" );  
  
   if( libvar != NULL )  
      printf( "New MYLIB variable is: %s\n", libvar);  
   else  
      printf( "MYLIB has not been set.\n");  
   free( libvar );  
}  
```  
  
### Código  
  
```  
// test2Main.cpp  
// compile with: /MT /link test2dll.lib  
#include <stdlib.h>  
#include <stdio.h>  
  
void readEnv();  
  
int main( void )  
{  
   _putenv( "MYLIB=c:\\mylib;c:\\yourlib" );  
   readEnv();  
}  
```  
  
### Saída  
  
```  
MYLIB has not been set.  
```  
  
 Se a DLL e o arquivo são compilados com \/MD de forma que apenas uma cópia de CRT é usada, o programa for executado com êxito e gerenciar a seguinte saída:  
  
```  
New MYLIB variable is: c:\mylib;c:\yourlib  
```  
  
## Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)