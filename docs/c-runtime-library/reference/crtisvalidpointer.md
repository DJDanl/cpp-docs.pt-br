---
title: "_CrtIsValidPointer | Microsoft Docs"
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
  - "_CrtIsValidPointer"
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
  - "CrtlsValidPointer"
  - "_CrtIsValidPointer"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _CrtIsValidPointer"
  - "Função CrtIsValidPointer"
ms.assetid: 91c35590-ea5e-450f-a15d-ad8d62ade1fa
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _CrtIsValidPointer
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Verifica se um ponteiro não é nulo.  Nas versões da biblioteca de tempo de execução do C antes do Visual Studio 2010, verifica se um intervalo de memória especificado é válido para leitura e gravação \(somente versão de depuração\).  
  
## Sintaxe  
  
```  
int _CrtIsValidPointer(   
   const void *address,  
   unsigned int size,  
   int access   
);  
```  
  
#### Parâmetros  
 endereço  
 Aponta para o início do intervalo de memória para testar a validade.  
  
 `size`  
 Tamanho do intervalo de memória especificado \(em bytes\).  
  
 acesso  
 Acessibilidade de leitura\/gravação para determinar o intervalo de memória.  
  
## Valor de retorno  
 `_CrtIsValidPointer` Retorna VERDADEIRO se o ponteiro especificado não é nulo.  Nas versões da biblioteca CRT antes do Visual Studio 2010, retorna TRUE se o intervalo de memória é válido para a operação especificada ou as operações.  Caso contrário, a função retorna FALSE.  
  
## Comentários  
 Os parâmetros de tamanho e o acesso a partir da biblioteca CRT no Visual Studio 2010, são ignorados, e `_CrtIsValidPointer` só verifica se o endereço especificado não é nulo.  Como esse teste é fácil de realizar sozinho, não recomendamos que usar essa função.  Nas versões anteriores do Visual Studio 2010, a função verifica se o intervalo de memória começando no `address` e se estende para `size` bytes é válido para a operação de acessibilidade especificadas ou as operações.  Quando `access` for definido como TRUE, o intervalo de memória é verificado para leitura e gravação.  Quando `access` for FALSE, o intervalo de memória é validado somente para leitura.  Quando [\_DEBUG](../Topic/_DEBUG.md) não está definido, as chamadas a `_CrtIsValidPointer` são removidas durante o pré\-processamento.  
  
 Como essa função retorna TRUE ou FALSE, ela pode ser informada a uma das macros de [\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) para criar um mecanismo de tratamento de erro de depuração simples.  O exemplo a seguir causa uma falha de asserção se o intervalo de memória não for válido para as operações de leitura e gravação:  
  
```  
_ASSERTE( _CrtIsValidPointer( address, size, TRUE ) );  
```  
  
 Para obter mais informações sobre como `_CrtIsValidPointer` pode ser usado com outras funções de depuração e macros, consulte [Macros para relatórios](../Topic/Macros%20for%20Reporting.md).  Para obter informações sobre como blocos de memória são alocados, inicializados e gerenciados na versão de depuração do heap de base, consulte [Detalhes da pilha de depuração CRT](../Topic/CRT%20Debug%20Heap%20Details.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_CrtIsValidPointer`|\<crtdbg.h\>|  
  
 `_CrtIsValidPointer` é uma extensão da Microsoft.  Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
 Consulte o exemplo do tópico [\_CrtIsValidHeapPointer](../../c-runtime-library/reference/crtisvalidheappointer.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Rotinas de depuração](../../c-runtime-library/debug-routines.md)