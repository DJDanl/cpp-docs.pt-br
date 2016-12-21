---
title: "_chdrive | Microsoft Docs"
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
  - "_chdrive"
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
  - "chdrive"
  - "_chdrive"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _chdrive"
  - "Função chdrive"
  - "unidades, alterando"
ms.assetid: 212a1a4b-4fa8-444e-9677-7fca4c8c47e3
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _chdrive
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera a unidade de trabalho atual.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _chdrive(   
   int drive   
);  
```  
  
#### Parâmetros  
 `drive`  
 Um número inteiro de 1 a 26 que especifica a unidade de trabalho atual \(1\=A, 2\=B e assim por diante\).  
  
## Valor de retorno  
 Zero \(0\) se a unidade atual foi alterada trabalhando com êxito; se não, \-1.  
  
## Comentários  
 Se `drive` não estiver no intervalo de 1 a 26, o manipulador de parâmetro inválido é chamado conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função **\_chdrive** retorna \-1, `errno` é definido como `EACCES` e `_doserrno` é definido como `ERROR_INVALID_DRIVE`.  
  
 A função **\_chdrive** não é thread\-safe porque ela depende da função **SetCurrentDirectory**, que é thread\-safe.  Para usar com segurança **\_chdrive** em um aplicativo multi\-threaded, você deve fornecer sua sincronização de threads.  Para obter mais informações, vá para [Biblioteca MSDN](http://go.microsoft.com/fwlink/?LinkID=150542), em seguida, pesquise por **SetCurrentDirectory**.  
  
 A função **\_chdrive** altera somente a unidade de trabalho atual, **\_chdir** altera o diretório de trabalho atual.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|**\_chdrive**|\<direct.h\>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Consulte o exemplo de [\_getdrive](../../c-runtime-library/reference/getdrive.md).  
  
## Equivalência do .NET Framework  
 [System::Environment::CurrentDirectory](https://msdn.microsoft.com/en-us/library/system.environment.currentdirectory.aspx)  
  
## Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [\_chdir, \_wchdir](../Topic/_chdir,%20_wchdir.md)   
 [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [\_getcwd, \_wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [\_getdrive](../../c-runtime-library/reference/getdrive.md)   
 [\_mkdir, \_wmkdir](../Topic/_mkdir,%20_wmkdir.md)   
 [\_rmdir, \_wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)