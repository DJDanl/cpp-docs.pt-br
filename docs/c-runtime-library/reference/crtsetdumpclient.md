---
title: "_CrtSetDumpClient | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_CrtSetDumpClient"
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
apitype: "DLLExport"
f1_keywords: 
  - "_CrtSetDumpClient"
  - "CrtSetDumpClient"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtSetDumpClient"
  - "Função CrtSetDumpClient"
ms.assetid: f3dd06d0-c331-4a12-b68d-25378d112033
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtSetDumpClient
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Instala uma função de aplicativo definida para despejar blocos de memória do tipo de `_CLIENT_BLOCK` \(versão de depuração somente\).  
  
## Sintaxe  
  
```  
  
      _CRT_DUMP_CLIENT _CrtSetDumpClient(   
   _CRT_DUMP_CLIENT dumpClient   
);  
```  
  
#### Parâmetros  
 `dumpClient`  
 Nova função definida pelo cliente de despejo de memória para conectar no processo de despejo de memória de depuração de tempo de execução C.  
  
## Valor de retorno  
 Retorna a função definida anteriormente de despejo do bloco de cliente.  
  
## Comentários  
 A função de `_CrtSetDumpClient` permite que o aplicativo conectar sua própria função para despejar os objetos armazenados em blocos de memória de `_CLIENT_BLOCK` no processo de despejo de memória de depuração de tempo de execução C.  No resultado, todas as vezes em uma função de despejo de depuração como [\_CrtMemDumpAllObjectsSince](../Topic/_CrtMemDumpAllObjectsSince.md) ou [\_CrtDumpMemoryLeaks](../../c-runtime-library/reference/crtdumpmemoryleaks.md) for um bloco de memória de `_CLIENT_BLOCK` , a função de despejo de aplicativo é chamada também.  `_CrtSetDumpClient` fornece um aplicativo com um método fácil para detectar possíveis vazamentos de memória e validar ou relatar o conteúdo dos dados armazenados em blocos de `_CLIENT_BLOCK` .  Quando [\_DEBUG](../Topic/_DEBUG.md) não for definido, as chamadas para `_CrtSetDumpClient` serão removidos durante pré\-processamento.  
  
 A função de `_CrtSetDumpClient` instalar a nova função de aplicativo definida de despejo especificada em `dumpClient` e retorna a função definida anteriormente de despejo.  Um exemplo de uma função de despejo do bloco de cliente é a seguinte:  
  
```  
void DumpClientFunction( void *userPortion, size_t blockSize );  
```  
  
 O argumento de `userPortion` é um ponteiro para o início da parte de dados de usuário do bloco de memória e `blockSize` especifica o tamanho do bloco de memória alocado em bytes.  A função de despejo do bloco do cliente deve retornar `void`.  O ponteiro da função de despejo do cliente que é passada a `_CrtSetDumpClient` é do tipo `_CRT_DUMP_CLIENT`, conforme definido em Crtdbg.h:  
  
```  
typedef void (__cdecl *_CRT_DUMP_CLIENT)( void *, size_t );  
```  
  
 Para obter mais informações sobre as funções que operam em blocos de memória do tipo de `_CLIENT_BLOCK` , consulte [Funções de gancho do bloco de clientes](../Topic/Client%20Block%20Hook%20Functions.md).  A função de [\_CrtReportBlockType](../Topic/_CrtReportBlockType.md) pode ser usada para retornar informações sobre tipos e subtipos do bloco.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtSetDumpClient`|\<crtdbg.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Versões de depuração das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md) somente.  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)   
 [\_CrtReportBlockType](../Topic/_CrtReportBlockType.md)   
 [\_CrtGetDumpClient](../../c-runtime-library/reference/crtgetdumpclient.md)