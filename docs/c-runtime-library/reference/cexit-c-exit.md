---
title: "_cexit, _c_exit | Microsoft Docs"
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
  - "_c_exit"
  - "_cexit"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_cexit"
  - "c_exit"
  - "_c_exit"
  - "cexit"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _c_exit"
  - "Função _cexit"
  - "Função c_exit"
  - "Função cexit"
  - "operações de limpeza durante processos"
ms.assetid: f3072045-9924-4b1a-9fef-b0dcd6d12663
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _cexit, _c_exit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Executa operações de limpeza e retorna sem finalizar o processo.  
  
## Sintaxe  
  
```  
void _cexit( void );  
void _c_exit( void );  
```  
  
## Comentários  
 As chamadas de função de `_cexit` , no último no, primeiro em expansão ordem de \(LIFO\), as funções inscritas por `atexit` e por `_onexit`.  Em `_cexit` libera todos os buffers de E\/S e fecha todas fluxos abertos antes de retornar.  `_c_exit` é o mesmo que `_exit` mas retorna ao processo de chamada sem processar `atexit` ou `_onexit` ou liberar buffers de fluxo.  O comportamento de `exit`,de`_exit`, de `_cexit`, e de `_c_exit` é mostrado na tabela a seguir.  
  
|Função|Comportamento|  
|------------|-------------------|  
|`exit`|Executa procedimentos de término completo da biblioteca de C, encerra o processo, e o será encerrado com o código de status fornecido.|  
|`_exit`|Executa procedimentos rápidos de término da biblioteca de C, encerra o processo, e o será encerrado com o código de status fornecido.|  
|`_cexit`|Executa procedimentos de término completo da biblioteca de C e retorna ao chamador, mas não encerra o processo.|  
|`_c_exit`|Executa procedimentos rápidos de término da biblioteca de C e retorna ao chamador, mas não encerra o processo.|  
  
 Quando você chama as funções de `_cexit` ou de `_c_exit` , os destruidores para todos os objetos temporários ou automática que existem na hora da chamada não serão chamados.  Um objeto automática é um objeto que é definido em uma função em que o objeto não é declarada para ser estático.  Um objeto temporário é um objeto criado pelo compilador.  Para destruir um objeto automático antes de chamar `_cexit` ou `_c_exit`, chamar explicitamente o destruidor para o objeto, como segue:  
  
```  
myObject.myClass::~myClass( );  
```  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_cexit`|\<process.h\>|  
|`_c_exit`|\<process.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Equivalência do .NET Framework  
 [System::Diagnostics::Process::CloseMainWindow](https://msdn.microsoft.com/en-us/library/system.diagnostics.process.closemainwindow.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [abort](../../c-runtime-library/reference/abort.md)   
 [atexit](../../c-runtime-library/reference/atexit.md)   
 [Funções \_exec, \_wexec](../../c-runtime-library/exec-wexec-functions.md)   
 [sair, Exit, Exit](../../c-runtime-library/reference/exit-exit-exit.md)   
 [\_onexit, \_onexit\_m](../../c-runtime-library/reference/onexit-onexit-m.md)   
 [Funções \_spawn, \_wspawn](../Topic/_spawn,%20_wspawn%20Functions.md)   
 [system, \_wsystem](../../c-runtime-library/reference/system-wsystem.md)