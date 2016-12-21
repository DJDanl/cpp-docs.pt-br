---
title: "_rmdir, _wrmdir | Microsoft Docs"
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
  - "_wrmdir"
  - "_rmdir"
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
  - "api-ms-win-crt-filesystem-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "trmdir"
  - "_trmdir"
  - "wrmdir"
  - "_rmdir"
  - "_wrmdir"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _rmdir"
  - "Função _trmdir"
  - "Função _wrmdir"
  - "diretórios [C++], excluindo"
  - "diretórios [C++], removendo"
  - "Função rmdir"
  - "Função trmdir"
  - "Função wrmdir"
ms.assetid: 652c2a5a-b0ac-4493-864e-1edf484333c5
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _rmdir, _wrmdir
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Exclui um Diretório.  
  
## Sintaxe  
  
```  
  
      int _rmdir(  
   const char *dirname   
);  
int _wrmdir(  
   const wchar_t *dirname   
);  
```  
  
#### Parâmetros  
 `dirname`  
 Caminho do diretório a ser removido.  
  
## Valor de retorno  
 Cada uma dessas funções retornará 0 se o diretório é excluído com êxito.  Um valor de retorno – 1 indica que ocorreu um erro e `errno` são definidos como um dos seguintes valores:  
  
 **ENOTEMPTY**  
 O caminho especificado não é um diretório, o diretório não estiver vazia, o diretório é o diretório de trabalho atual ou o diretório raiz.  
  
 `ENOENT`  
 O caminho é inválido.  
  
 **EACCES**  
 Um programa tem um identificador aberto no diretório.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_rmdir` exclui o diretório especificado por `dirname`.  O diretório deve estar vazia, e não deve ser o diretório de trabalho atual ou o diretório raiz.  
  
 `_wrmdir` é uma versão de caractere longo de `_rmdir`; o argumento `dirname` para `_wrmdir` é uma cadeia de caractere longo.  Caso contrário, `_wrmdir` e `_rmdir`, ao contrário, se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_trmdir`|`_rmdir`|`_rmdir`|`_wrmdir`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_rmdir`|\<direct.h\>|  
|`_wrmdir`|\<direct.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 Consulte o exemplo de [\_mkdir](../Topic/_mkdir,%20_wmkdir.md).  
  
## Equivalência do .NET Framework  
 [System::IO::Directory::Delete](https://msdn.microsoft.com/en-us/library/system.io.directory.delete.aspx)  
  
## Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [\_chdir, \_wchdir](../Topic/_chdir,%20_wchdir.md)   
 [\_mkdir, \_wmkdir](../Topic/_mkdir,%20_wmkdir.md)