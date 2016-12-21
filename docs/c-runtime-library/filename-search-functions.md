---
title: "Fun&#231;&#245;es de pesquisa de nome de arquivo | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr100.dll"
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
apitype: "DLLExport"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "nomes de arquivo [C++], procurando por"
  - "Função _find"
  - "Função wfind"
  - "Função find"
  - "Função _wfind"
ms.assetid: 2bc2f8ef-44e4-4271-b3e8-666d36fde828
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es de pesquisa de nome de arquivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas funções pesquisam por e fecha procura nomes de arquivo especificados:  
  
-   [\_findnext, \_wfindnext](../Topic/_findnext,%20_findnext32,%20_findnext32i64,%20_findnext64,%20_findnext64i32,%20_findnexti64,%20_wfindnext,%20_wfindnext32,%20_wfindnext32i64,%20_wfindnext64,%20_wfindnext64i32,%20_wfindnexti64.md)  
  
-   [\_findfirst, \_wfindfirst](../Topic/_findfirst,%20_findfirst32,%20_findfirst32i64,%20_findfirst64,%20_findfirst64i32,%20_findfirsti64,%20_wfindfirst,%20_wfindfirst32,%20_wfindfirst32i64,%20_wfindfirst64,%20_wfindfirst64i32,%20_wfindfirsti64.md)  
  
-   [\_findclose](../c-runtime-library/reference/findclose.md)  
  
## Comentários  
 A função de `_findfirst` fornece informações sobre a primeira instância de um nome de arquivo que corresponda ao arquivo especificado no argumento de `filespec` .  Você pode usar em `filespec` qualquer combinação de caracteres curinga que tem suporte pelo sistema operacional do host.  
  
 As informações do arquivo de retorno de funções em uma estrutura de`finddata_t` \_, que é definida em IO.h.  As várias funções da família usam muitas variações na estrutura de `_finddata_t` .  A estrutura básica de `_finddata_t` inclui os seguintes elementos:  
  
 `unsigned attrib`  
 Atributo de Arquivo.  
  
 `time_t time_create`  
 Hora de criação do arquivo \(– 1L para sistemas de arquivos FAT\).  Essas vezes são armazenadas em formato UTC.  Para converter para hora local, use [localtime\_s](../c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s.md).  
  
 `time_t time_access`  
 Hora do acesso ao arquivo o último \(– 1L para sistemas de arquivos FAT\).  Essas vezes são armazenadas em formato UTC.  Para converter para hora local, use `localtime_s`.  
  
 `time_t time_write`  
 Hora da última gravação arquivamento.  Essas vezes são armazenadas em formato UTC.  Para converter para hora local, use `localtime_s`.  
  
 `_fsize_t size`  
 Comprimento do arquivo em bytes.  
  
 `char name`\[ `_MAX_PATH`\]  
 Nome com terminação nula do arquivo ou diretório correspondente, sem o caminho.  
  
 Em sistemas de arquivos que não dão suporte à criação e hora do último de um arquivo, como o sistema GORDO, `time_create` e os campos de `time_access` é sempre – 1L.  
  
 `_MAX_PATH` é definido em Stdlib.h como 260 bytes.  
  
 Você não pode especificar atributos de destino \(como `_A_RDONLY`\) para limitar a operação de localização.  Esses atributos são retornados no campo de `attrib` da estrutura de `_finddata_t` e podem ter os seguintes valores \(definidas em IO.h\).  Os usuários não devem confiar em que esses são os únicos valores possíveis para o campo de `attrib` .  
  
 `_A_ARCH`  
 Arquivo morto.  Defina sempre que o arquivo for alterado e limpo pelo comando de **BACKUP** .  Valor: 0x20.  
  
 `_A_HIDDEN`  
 Arquivo oculto.  Visto normalmente não com o comando de DIR, a menos que você use a opção de **\/AH** .  Retorna informações sobre arquivos normais e arquivos com esse atributo.  Valor: 0x02.  
  
 `_A_NORMAL`  
 Normal.  Arquivo não tem nenhum outro atributo definido e pode ser lida ou gravada sem à restrição.  Valor: 0x00.  
  
 `_A_RDONLY`  
 Somente leitura.  Arquivo não pode ser aberto para gravação e um arquivo com o mesmo nome não pode ser criado.  Valor: 0x01.  
  
 `_A_SUBDIR`  
 Subdiretório.  Valor: 0x10.  
  
 `_A_SYSTEM`  
 Sistema de arquivos  Consultado não normalmente com o comando de **DIR** , a menos que a opção de **\/A** ou de **\/A:S** é usada.  Valor: 0x04.  
  
 `_findnext` acha o nome seguir, se houver, que corresponde ao argumento de `filespec` especificado em uma chamada anterior a `_findfirst`.  O argumento de `fileinfo` deve apontar para uma estrutura inicializada pela chamada anterior a `_findfirst`.  Se for encontrada uma correspondência, o conteúdo da estrutura de `fileinfo` serão modificados conforme descrito anteriormente.  Caso contrário, será deixada inalterado.  `_findclose` fecha o identificador especificado da pesquisa e libera todos os recursos associados para `_findfirst` e `_findnext`.  O identificador retornado por `_findfirst` ou por `_findnext` deve primeiro ser passada a `_findclose`, antes que as operações de alteração, como excluir, possam ser executadas nos diretórios que formam os caminhos passados a ele.  
  
 Você pode aninhar funções de `_find` .  Por exemplo, se uma chamada a `_findfirst` ou a `_findnext` localiza o arquivo que é um subdiretório, uma nova pesquisa pode ser iniciada com outra chamada para `_findfirst` ou a `_findnext`.  
  
 `_wfindfirst` e `_wfindnext` são versões de ampla caractere de `_findfirst` e de `_findnext`.  O argumento da estrutura das versões de ampla caractere tem o tipo de dados `_wfinddata_t` , que é definido em IO.h e em Wchar.h.  Os campos desse tipo de dados são iguais aos do tipo de dados de `_finddata_t` , exceto que `_wfinddata_t` no campo nome é do tipo `wchar_t` em vez do tipo `char`.  Se não `_wfindfirst` e `_wfindnext` se comportam idêntica a `_findfirst` e a `_findnext`.  
  
 `_findfirst` e `_findnext` usam o tipo de 64 bits de tempo.  Se você deve usar o tipo de 32 bits antigo tempo, você pode definir `_USE_32BIT_TIME_T`.  As versões dessas funções que têm o sufixo de `32` em seus nomes usam o tipo de 32 bits de tempo, e esses com o uso do sufixo de `64` o tipo de 64 bits de tempo.  
  
 Funções `_findfirst32i64`, `_findnext32i64`, `_wfindfirst32i64`, e `_wfindnext32i64` também se comporta idêntica as versões de 32 bits do tipo de tempo dessas funções a não ser que usem e retorna comprimentos de 64 bits de arquivo.  Função `_findfirst64i32`, `_findnext64i32`, `_wfindfirst64i32`, e o usode `_wfindnext64i32`o tipo de 64 bits de tempo mas usam comprimentos de 32 bits de arquivo.  Essas variações apropriados do uso de funções de `_finddata_t` nos campos que têm tipos diferentes para o tempo e o tamanho do arquivo.  
  
 `_finddata_t` é realmente uma macro que é avaliada para `_finddata64i32_t` \(ou a `_finddata32_t` se `_USE_32BIT_TIME_T` é definido\).  A tabela a seguir resume as variações em `_finddata_t`:  
  
|Estrutura|Tipo de tempo|Tipo de tamanho de arquivo|  
|---------------|-------------------|--------------------------------|  
|`_finddata_t`, `_wfinddata_t`|`__time64_t`|`_fsize_t`|  
|`_finddata32_t`, `_wfinddata32_t`|`__time32_t`|`_fsize_t`|  
|`__finddata64_t`, `__wfinddata64_t`|`__time64_t`|`__int64`|  
|`_finddata32i64_t`, `_wfinddata32i64_t`|`__time32_t`|`__int64`|  
|`_finddata64i32_t`, `_wfinddata64i32_t`|`__time64_t`|`_fsize_t`|  
  
 `_fsize_t` é `typedef` para `unsigned long` \(32 bits\).  
  
## Exemplo  
  
```  
// crt_find.c  
// This program uses the 32-bit _find functions to print  
// a list of all files (and their attributes) with a .C extension  
// in the current directory.  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
  
int main( void )  
{  
   struct _finddata_t c_file;  
   intptr_t hFile;  
  
   // Find first .c file in current directory   
   if( (hFile = _findfirst( "*.c", &c_file )) == -1L )  
      printf( "No *.c files in current directory!\n" );  
   else  
   {  
      printf( "Listing of .c files\n\n" );  
      printf( "RDO HID SYS ARC  FILE         DATE %25c SIZE\n", ' ' );  
      printf( "--- --- --- ---  ----         ---- %25c ----\n", ' ' );  
      do {  
         char buffer[30];  
         printf( ( c_file.attrib & _A_RDONLY ) ? " Y  " : " N  " );  
         printf( ( c_file.attrib & _A_HIDDEN ) ? " Y  " : " N  " );  
         printf( ( c_file.attrib & _A_SYSTEM ) ? " Y  " : " N  " );  
         printf( ( c_file.attrib & _A_ARCH )   ? " Y  " : " N  " );  
         ctime_s( buffer, _countof(buffer), &c_file.time_write );  
         printf( " %-12s %.24s  %9ld\n",  
            c_file.name, buffer, c_file.size );  
      } while( _findnext( hFile, &c_file ) == 0 );  
      _findclose( hFile );  
   }  
}  
```  
  
  **Listagem de arquivos de .c**  
**RDO ESCONDEU DATE SIZE DATABASE FROM SYSTEM ARC FILE**  
**\-\-\- \-\-\- \-\-\- \-\-\-  \-\-\-\-         \-\-\-\-                           \-\-\-\-**  
 **N N Em Y blah.c quarta\-feira 13 de fevereiro de 09: 21:42 2002 1715**  
 **N N Em Y test.c quarta\-feira 6 de fevereiro de 14: 30:44 2002 312**   
## Consulte também  
 [Chamadas do sistema](../Topic/System%20Calls.md)