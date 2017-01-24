---
title: "_execute_onexit_table, _initialize_onexit_table, _register_onexit_function | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_execute_onexit_table"
  - "_initialize_onexit_table"
  - "_register_onexit_function"
apilocation: 
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_execute_onexit_table"
  - "process/_execute_onexit_table"
  - "_initialize_onexit_table"
  - "process/_initialize_onexit_table"
  - "_register_onexit_function"
  - "process/_register_onexit_function"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função _execute_onexit_table"
  - "função _initialize_onexit_table"
  - "função _register_onexit_function"
ms.assetid: ad9e4149-d4ad-4fdf-aaaf-cf786fcb4473
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _execute_onexit_table, _initialize_onexit_table, _register_onexit_function
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Gerencia as rotinas de ser chamado em tempo de saída.  
  
## Sintaxe  
  
```  
int _initialize_onexit_table(  
    _onexit_table_t* table  
    );  
  
int _register_onexit_function(  
    _onexit_table_t* table,  
    _onexit_t        function  
    );  
  
int _execute_onexit_table(  
    _onexit_table_t* table  
    );  
```  
  
#### Parâmetros  
 \[entrada\/saída\] `table`  
 Ponteiro para a tabela de função onexit.  
  
 \[in\] `function`  
 Ponteiro para uma função para adicionar à tabela de função onexit.  
  
## Valor de retorno  
 Se for bem\-sucedido, retornará 0. Caso contrário, retornará um valor negativo.  
  
## Comentários  
 Essas funções são detalhes de implementação de infra\-estrutura usada para dar suporte ao tempo de execução C e não devem ser chamados diretamente no seu código. O tempo de execução C usa um *tabela de função onexit* para representar a sequência das funções registradas por chamadas para `atexit`, `at_quick_exit`, e `_onexit`. A estrutura de dados de tabela de função onexit é um detalhe de implementação opaco do tempo de execução C; a ordem e o significado de seus membros de dados podem ser alteradas. Eles não devem ser examinados pelo código externo.  
  
 O `_initialize_onexit_table` função inicializa a tabela de função onexit para seu valor inicial.  Essa função deve ser chamada antes que a tabela de função onexit é passada como `_register_onexit_function` ou `_execute_onexit_table`.  
  
 O `_register_onexit_function` função acrescenta uma função ao final da tabela de função onexit.  
  
 O `_execute_onexit_table` função executa todas as funções na tabela de função onexit, limpa a tabela e, em seguida, retorna. Após uma chamada para `_execute_onexit_table`, a tabela está em um estado inválido; ele deve ser reinicializado por uma chamada a `_initialize_onexit_table` antes de ser usado novamente.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_initialize_onexit_table function`, `_register_onexit_function`, `_execute_onexit_table`|C, C\+\+: \< process.h \>|  
  
 O `_initialize_onexit_table`, `_register_onexit_function`, e `_execute_onexit_table` funções são específicas da Microsoft. Para informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [atexit](../c-runtime-library/reference/atexit.md)   
 [sair, Exit, Exit](../c-runtime-library/reference/exit-exit-exit.md)   
 [\_onexit, \_onexit\_m](../c-runtime-library/reference/onexit-onexit-m.md)