---
title: Possíveis erros ao passar objetos CRT por limites de DLL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- DLL conflicts [C++]
ms.assetid: c217ffd2-5d9a-4678-a1df-62a637a96460
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5fc211f47ca7d5c64ee068707f49620cd5e646f6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32391253"
---
# <a name="potential-errors-passing-crt-objects-across-dll-boundaries"></a>Erros em potencial passando por objetos CRT em limites de DLL
Quando você passa objetos CRT (Tempo de execução de C), como identificadores de arquivos, localidades e variáveis do ambiente de ou para uma DLL (chamadas de função além do limite da DLL), pode ocorrer um comportamento inesperado se a DLL, bem como os arquivos chamando a DLL, usar cópias diferentes das bibliotecas de CRT.  
  
 Um problema relacionado pode ocorrer ao alocar memória (explicitamente com `new` ou `malloc`, ou implicitamente com `strdup`, `strstreambuf::str` etc.) e depois passar um ponteiro além do limite da DLL para ser liberado. Isso pode causar uma violação de acesso da memória ou corrupção de heap se a DLL e seus usuários usarem cópias diferentes das bibliotecas CRT.  
  
 Outro sintoma desse problema pode ser um erro na janela de saída durante a depuração, por exemplo:  
  
 HEAP[]: endereço inválido especificado para RtlValidateHeap(#,#)  
  
## <a name="causes"></a>Causas  
 Cada cópia da biblioteca de CRT tem um estado separado e distinto, mantido no armazenamento local de thread por seu aplicativo ou DLL. Dessa forma, objetos CRT, como identificadores de arquivos, variáveis de ambiente e localidades, só serão válidos para a cópia do CRT no aplicativo ou DLL em que esses objetos estiverem alocados ou definidos. Quando uma DLL e seus clientes de aplicativo usam cópias diferentes da biblioteca de CRT, não é possível passar esses objetos CRT além do limite da DLL e esperar que eles sejam recebidos corretamente do outro lado. Isso vale particularmente para as versões de CRT anteriores ao CRT Universal no Visual Studio 2015 e posterior. Havia uma biblioteca de CRT específica de versão para cada versão do Visual Studio, compilada com o Visual C++ 2013 ou anterior. Os detalhes da implementação interna do CRT, por exemplo, suas estruturas de dados e convenções de nomenclatura, eram diferentes em cada versão. Nunca houve suporte à vinculação dinâmica do código compilado para uma versão do CRT com outra versão da DLL do CRT, embora isso pudesse funcionar ocasionalmente, mais por sorte do que por design.  
  
 Além disso, como cada cópia da biblioteca de CRT tem seu próprio gerenciador de heap, a alocação de memória em uma biblioteca de CRT e a passagem do ponteiro por um limite de DLL para ser liberado por outra cópia da biblioteca de CRT é uma possível causa de corrupção de heap. Se você criar sua DLL para que ela passe objetos CRT além do limite, ou aloque memória e espere a liberação fora da DLL, você restringe os clientes de aplicativo da DLL a usar a mesma cópia da biblioteca de CRT que a DLL. A DLL e seus clientes normalmente usam a mesma cópia da biblioteca de CRT somente se estiverem vinculados no momento do carregamento à mesma versão da DLL do CRT. Como a versão da DLL da biblioteca CRT Universal usada pelo Visual Studio 2015 e posterior no Windows 10 agora é um componente do Windows implantado centralmente, ucrtbase.dll, é a mesma para aplicativos compilados com o Visual Studio 2015 e versões posteriores. No entanto, mesmo quando o código CRT seja idêntico, não é possível fornecer memória alocada em um heap para um componente que usa um heap diferente.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Este exemplo passa um identificador de arquivo por um limite de DLL.  
  
 A DLL e o arquivo .exe são criados com /MD, portanto, eles compartilham uma única cópia do CRT.  
  
 Se você recompilar com /MT para que usem cópias separadas do CRT, a execução do test1Main.exe resultante pode gerar uma violação de acesso.  
  
```cpp  
// test1Dll.cpp  
// compile with: cl /EHsc /W4 /MD /LD test1Dll.cpp  
#include <stdio.h>  
__declspec(dllexport) void writeFile(FILE *stream)  
{  
   char   s[] = "this is a string\n";  
   fprintf( stream, "%s", s );  
   fclose( stream );  
}  
```  
  
```cpp  
// test1Main.cpp  
// compile with: cl /EHsc /W4 /MD test1Main.cpp test1Dll.lib  
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
  
```Output  
this is a string  
```  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Este exemplo passa as variáveis de ambiente por um limite de DLL.  
  
```cpp  
// test2Dll.cpp  
// compile with: cl /EHsc /W4 /MT /LD test2Dll.cpp  
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
  
```cpp  
// test2Main.cpp  
// compile with: cl /EHsc /W4 /MT test2Main.cpp test2dll.lib   
#include <stdlib.h>  
#include <stdio.h>  
  
void readEnv();  
  
int main( void )  
{  
   _putenv( "MYLIB=c:\\mylib;c:\\yourlib" );  
   readEnv();  
}  
```  
  
```Output  
MYLIB has not been set.  
```  
  
 Se a DLL e o arquivo .exe forem compilados com /MD para que apenas uma cópia do CRT seja usada, o programa será executado com êxito e produzirá a seguinte saída:  
  
```  
New MYLIB variable is: c:\mylib;c:\yourlib  
```  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)