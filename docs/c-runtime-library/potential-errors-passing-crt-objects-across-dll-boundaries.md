---
title: Erros em potencial passando por objetos CRT em limites de DLL
description: Uma visão geral dos possíveis problemas que você pode ter ao passar objetos do Microsoft C Runtime em um limite de DLL (biblioteca de vínculo dinâmico).
ms.date: 11/04/2016
ms.topic: conceptual
helpviewer_keywords:
- DLL conflicts [C++]
ms.assetid: c217ffd2-5d9a-4678-a1df-62a637a96460
ms.openlocfilehash: f6d831ac8b86be8a6669e8ee6c66da64507d129f
ms.sourcegitcommit: 9451db8480992017c46f9d2df23fb17b503bbe74
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2020
ms.locfileid: "91590180"
---
# <a name="potential-errors-passing-crt-objects-across-dll-boundaries"></a>Erros em potencial passando por objetos CRT em limites de DLL

Quando você passa objetos CRT (tempo de execução) do C, como identificadores de arquivo, localidades e variáveis de ambiente dentro ou fora de uma DLL por meio de chamadas de função entre o limite de DLL, pode ocorrer um comportamento inesperado se a DLL ou quaisquer arquivos que chamam a DLL usarem cópias diferentes das bibliotecas CRT.

Um problema relacionado pode ocorrer quando você aloca memória (explicitamente com `new` ou `malloc` , ou implicitamente com `strdup` , `strstreambuf::str` e assim por diante) e passa um ponteiro por um limite de dll onde é liberado. Isso pode causar uma violação de acesso à memória, ou corrupção de heap, se a DLL e seus consumidores estiverem usando cópias diferentes das bibliotecas CRT.

Outro sintoma desse problema é um erro na janela de saída durante a depuração, como `HEAP[]: Invalid Address specified to RtlValidateHeap(#,#)`

## <a name="causes"></a>Causas

Cada cópia da biblioteca de CRT tem um estado separado e distinto, mantido no armazenamento local de thread por seu aplicativo ou DLL.

Objetos CRT, como identificadores de arquivo, variáveis de ambiente e localidades, são válidos somente para a cópia do CRT no aplicativo ou DLL em que esses objetos foram alocados ou definidos. Quando uma DLL e seus clientes usam cópias diferentes da biblioteca CRT, você não pode passar esses objetos CRT pelo limite de DLL e esperar que eles sejam usados corretamente no outro lado. Isso é verdadeiro para versões do CRT antes do CRT universal no Visual Studio 2015 e posterior.

Havia uma biblioteca de CRT específica de versão para cada versão do Visual Studio, compilada com o Visual Studio 2013 ou anterior. Os detalhes de implementação interna do CRT, como estruturas de dados e convenções de nomenclatura, foram diferentes em cada versão. O código de vinculação dinâmica que foi compilado para uma versão do CRT para uma versão diferente da DLL do CRT nunca foi suportado. Ocasionalmente, ele funcionaria, mas devido à sorte, e não ao design.

Como cada cópia da biblioteca CRT tem seu próprio Gerenciador de heap, Alocando memória em uma biblioteca CRT e passando o ponteiro por um limite de DLL para ser liberado por uma cópia diferente da biblioteca CRT, pode causar corrupção de heap. Se você projetar sua DLL para que ela passe objetos CRT pelo limite da DLL ou aloque memória e espere que ela seja liberada fora da DLL, os clientes da DLL deverão usar a mesma cópia da biblioteca do CRT como a DLL.

A DLL e seus clientes normalmente usam a mesma cópia da biblioteca de CRT somente se estiverem vinculados no momento do carregamento à mesma versão da DLL do CRT. Como a versão de DLL da biblioteca CRT universal usada pelo Visual Studio 2015 e posterior no Windows 10, agora é um componente do Windows implantado centralmente (ucrtbase.dll), é o mesmo para aplicativos criados com o Visual Studio 2015 e versões posteriores. No entanto, mesmo quando o código CRT é idêntico, você não pode fornecer memória alocada em um heap para um componente que usa um heap diferente.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Este exemplo passa um identificador de arquivo por um limite de DLL.

Os arquivos DLL e. exe são criados com o `/MD` , para que eles compartilhem uma única cópia do CRT.

Se você recriar `/MT` o com o para que eles usem cópias separadas do CRT, a execução do **test1Main.exe** resultante resultará em uma violação de acesso.

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

Se o arquivo DLL e. exe forem criados com o `/MD` para que apenas uma cópia do CRT seja usada, o programa será executado com êxito e produzirá a seguinte saída:

```
New MYLIB variable is: c:\mylib;c:\yourlib
```

## <a name="see-also"></a>Confira também

[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
