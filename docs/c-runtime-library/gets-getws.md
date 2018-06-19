---
title: gets, _getws | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
apiname:
- _getws
- gets
apilocation:
- msvcr80.dll
- msvcr90.dll
- msvcr120.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcrt.dll
- msvcr100.dll
apitype: DLLExport
f1_keywords:
- _getts
- gets
- _getws
dev_langs:
- C++
helpviewer_keywords:
- getws function
- getts function
- _getws function
- lines, getting
- streams, getting lines
- _getts function
- gets function
- standard input, reading from
ms.assetid: 1ec2dd4b-f801-48ea-97c2-892590f16024
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a597ad1a72f903d08e848727045e05bf014879b1
ms.sourcegitcommit: 6e3cf8df676d59119ce88bf5321d063cf479108c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/22/2018
ms.locfileid: "34450631"
---
# <a name="gets-getws"></a>gets, _getws
Obtém uma linha do fluxo `stdin`. Estão disponíveis versões mais seguras dessas funções; consulte [gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md).  
  
> [!IMPORTANT]
>  Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT. As versões seguras dessas funções, gets_s e _getws_s, ainda estão disponíveis. Para obter informações sobre essas funções alternativas, consulte [gets_s, _getws_s](../c-runtime-library/reference/gets-s-getws-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *gets(   
   char *buffer   
);  
wchar_t *_getws(   
   wchar_t *buffer   
);  
template <size_t size>  
char *gets(   
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
wchar_t *_getws(   
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Local de armazenamento para a cadeia de caracteres de entrada.  
  
## <a name="return-value"></a>Valor retornado  
 Retorna o argumento se for bem-sucedido. Um ponteiro **NULL** indica uma condição de erro ou de fim do arquivo. Use [ferror](../c-runtime-library/reference/ferror.md) ou [feof](../c-runtime-library/reference/feof.md) para determinar qual das condições ocorreu. Se `buffer` for **NULL**, essas funções invocarão o manipulador de um parâmetro inválido, conforme descrito em [Validação de parâmetro](../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **NULL** e definirão errno como `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A função `gets` lê uma linha do fluxo de entrada padrão `stdin` e a armazena em `buffer`. A linha consiste em todos os caracteres até e incluindo o primeiro caractere de nova linha ('\n'). `gets`, então, substitui o caractere de nova linha por um caractere nulo ('\0') antes de retornar a linha. Por sua vez, a função `fgets` retém o caractere de nova linha. `_getws` é uma versão de caractere largo de `gets`; seu argumento e o valor retornado são cadeias de caracteres largos.  
  
> [!IMPORTANT]
>  Como não há uma maneira de limitar o número de caracteres lidos por gets, entradas não confiáveis podem facilmente causar estouros de buffer. Use `fgets` em seu lugar.  
  
 No C++, essas funções têm sobrecargas de modelo que invocam os equivalentes mais novos e seguros dessas funções. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_getts`|`gets`|`gets`|`_getws`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`gets`|\<stdio.h>|  
|`_getws`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_gets.c  
// compile with: /WX /W3  
  
#include <stdio.h>  
  
int main( void )  
{  
   char line[21]; // room for 20 chars + '\0'  
   gets( line );  // C4996  
   // Danger: No way to limit input to 20 chars.  
   // Consider using gets_s instead.  
   printf( "The line entered was: %s\n", line );  
}  
```  
  
 Observe que uma entrada com mais de 20 caracteres saturará o buffer de linha e provavelmente fará com que o programa falhe.  
  
```Output  
  
Hello there!The line entered was: Hello there!  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../c-runtime-library/stream-i-o.md)   
 [fgets, fgetws](../c-runtime-library/reference/fgets-fgetws.md)   
 [fputs, fputws](../c-runtime-library/reference/fputs-fputws.md)   
 [puts, _putws](../c-runtime-library/reference/puts-putws.md)