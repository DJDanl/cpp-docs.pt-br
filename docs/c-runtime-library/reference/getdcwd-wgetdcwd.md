---
title: "_getdcwd, _wgetdcwd | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_getdcwd"
  - "_wgetdcwd"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "wgetdcwd"
  - "getdcwd"
  - "_getdcwd"
  - "tgetdcwd"
  - "_wgetdcwd"
  - "_tgetdcwd"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função wgetdcwd"
  - "diretório de trabalho"
  - "Função getdcwd"
  - "Função _getdcwd"
  - "Função _wgetdcwd"
  - "diretório de trabalho atual"
  - "diretórios [C++] atuais trabalhando"
ms.assetid: 184152f5-c7b0-495b-918d-f9a6adc178bd
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getdcwd, _wgetdcwd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o caminho completo do diretório de trabalho atual na unidade especificada.  
  
## Sintaxe  
  
```  
char *_getdcwd(   
   int drive,  
   char *buffer,  
   int maxlen   
);  
wchar_t *_wgetdcwd(   
   int drive,  
   wchar_t *buffer,  
   int maxlen   
);  
```  
  
#### Parâmetros  
 `drive`  
 Um inteiro positivo que especifica a unidade \(0 \= unidade padrão, 1 \= A, 2 \= B e assim por diante\).  
  
 Se a unidade especificada não estiver disponível, ou o tipo de unidade \(por exemplo, removível e fixo, CD\-ROM, disco de RAM ou unidade de rede\) não puder ser determinado, o manipulador de parâmetro inválido, que é descrito no [Validação do parâmetro](../../c-runtime-library/parameter-validation.md), é invocado.  
  
 `buffer`  
 Local de armazenamento para o caminho, ou **nulo**.  
  
 Se **nulo** for especificado, esta função aloca um buffer pelo menos `maxlen` tamanho usando **malloc**, e o valor de retorno de `_getdcwd` é um ponteiro para o buffer alocado. O buffer pode ser liberado chamando `free` e passando o ponteiro.  
  
 `maxlen`  
 Um inteiro positivo diferente de zero que especifica o comprimento máximo do caminho, em caracteres: `char` para `_getdcwd` e `wchar_t` para `_wgetdcwd`.  
  
 Se `maxlen` não for maior que zero, o manipulador de parâmetro inválido, que é descrito no [Validação do parâmetro](../../c-runtime-library/parameter-validation.md), é invocado.  
  
## Valor de retorno  
 Ponteiro para uma cadeia de caracteres que representa o caminho completo do diretório de trabalho atual na unidade especificada, ou `NULL`, que indica um erro.  
  
 Se `buffer` for especificado como `NULL` e não há memória suficiente para alocar `maxlen` caracteres, ocorrerá um erro e `errno` é definido como `ENOMEM`. Se o comprimento do caminho, que inclui o caractere de terminação nula, exceder `maxlen`, ocorrerá um erro e `errno` é definido como `ERANGE`. Para obter mais informações sobre esses códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `_getdcwd` função obtém o caminho completo do diretório de trabalho atual na unidade especificada e a armazena em `buffer`. Se o diretório de trabalho atual é definido como a raiz, a cadeia de caracteres termina com uma barra invertida \(\\\). Se o diretório de trabalho atual é definido como um diretório que não seja a raiz, a cadeia de caracteres termina com o nome do diretório e não com uma barra invertida.  
  
 `_wgetdcwd` é uma versão de caractere largo de `_getdcwd`, e sua `buffer` parâmetro e valor de retorno são cadeias de caracteres largos. Caso contrário, `_wgetdcwd` e `_getdcwd` se comportam de forma idêntica.  
  
 Essa função é thread\-safe, embora ele depende **GetFullPathName**, que é não thread\-safe. No entanto, você pode violar thread\-safe se seu aplicativo multithread chama essa função dois e **GetFullPathName**. Para obter mais informações, vá para [biblioteca MSDN](http://go.microsoft.com/fwlink/?LinkID=150542) e procure por **GetFullPathName**.  
  
 A versão dessa função que tem o `_nolock` sufixo se comporta de forma idêntica para essa função exceto que ele não é thread\-safe e não está protegido contra interferência por outros threads. Para obter mais informações, consulte [\_getdcwd\_nolock, \_wgetdcwd\_nolock](../../c-runtime-library/reference/getdcwd-nolock-wgetdcwd-nolock.md).  
  
 Quando `_DEBUG` e `_CRTDBG_MAP_ALLOC` são definidas, as chamadas para `_getdcwd` e `_wgetdcwd` são substituídos por chamadas para `_getdcwd_dbg` e `_wgetdcwd_dbg` para que você pode depurar as alocações de memória. Para obter mais informações, consulte[\_getdcwd\_dbg, \_wgetdcwd\_dbg](../../c-runtime-library/reference/getdcwd-dbg-wgetdcwd-dbg.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tgetdcwd`|`_getdcwd`|`_getdcwd`|`_wgetdcwd`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getdcwd`|\< Direct. h \>|  
|`_wgetdcwd`|\< Direct. h \> ou \< WCHAR \>|  
  
 Para obter informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Consulte o exemplo em [\_getdrive](../../c-runtime-library/reference/getdrive.md).  
  
## Equivalência do .NET Framework  
 [System::Environment::CurrentDirectory](https://msdn.microsoft.com/en-us/library/system.environment.currentdirectory.aspx)  
  
## Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [\_chdir, \_wchdir](../Topic/_chdir,%20_wchdir.md)   
 [\_getcwd, \_wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [\_getdrive](../../c-runtime-library/reference/getdrive.md)   
 [\_mkdir, \_wmkdir](../Topic/_mkdir,%20_wmkdir.md)   
 [\_rmdir, \_wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)