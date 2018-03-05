---
title: _execute_onexit_table, _initialize_onexit_table, _register_onexit_function | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _execute_onexit_table
- _initialize_onexit_table
- _register_onexit_function
apilocation:
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _execute_onexit_table
- process/_execute_onexit_table
- _initialize_onexit_table
- process/_initialize_onexit_table
- _register_onexit_function
- process/_register_onexit_function
dev_langs:
- C++
helpviewer_keywords:
- _execute_onexit_table function
- _initialize_onexit_table function
- _register_onexit_function function
ms.assetid: ad9e4149-d4ad-4fdf-aaaf-cf786fcb4473
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d2aa296c04d81fcdea2000ab8e2dbc1ae5523673
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="executeonexittable-initializeonexittable-registeronexitfunction"></a>_execute_onexit_table, _initialize_onexit_table, _register_onexit_function
Gerencia as rotinas que serão chamadas no tempo de saída.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 [inout] `table`  
 Ponteiro para a tabela de função onexit.  
  
 [in] `function`  
 Ponteiro para uma função para adicionar à tabela de função onexit.  
  
## <a name="return-value"></a>Valor retornado  
 Se for bem-sucedido, retornará 0. Caso contrário, retornará um valor negativo.  
  
## <a name="remarks"></a>Comentários  
 Essas funções são detalhes da implementação de infraestrutura usada para dar suporte ao tempo de execução C e não devem ser chamadas diretamente no seu código. O tempo de execução C usa uma *tabela de função onexit* para representar a sequência das funções registradas por chamadas para `atexit`, `at_quick_exit` e `_onexit`. A estrutura de dados de tabela de função onexit é um detalhe de implementação opaco do tempo de execução C; a ordem e o significado de seus membros de dados podem ser alterados. Eles não devem ser examinados pelo código externo.  
  
 A função `_initialize_onexit_table` inicializa a tabela de função onexit para seu valor inicial.  Essa função deve ser chamada antes que a tabela de função onexit seja passada para `_register_onexit_function` ou `_execute_onexit_table`.  
  
 A função `_register_onexit_function` acrescenta uma função ao final da tabela de função onexit.  
  
 A função `_execute_onexit_table` executa todas as funções na tabela de função onexit, limpa a tabela e, em seguida, retorna. Após uma chamada para `_execute_onexit_table`, a tabela fica em um estado inválido. Ela deve ser reinicializada por uma chamada para `_initialize_onexit_table` antes de ser usada novamente.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_initialize_onexit_table function`, `_register_onexit_function`, `_execute_onexit_table`|C, C++: \<process.h>|  
  
 As funções `_initialize_onexit_table`, `_register_onexit_function` e `_execute_onexit_table` são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [atexit](../c-runtime-library/reference/atexit.md)   
 [exit, _Exit, _exit](../c-runtime-library/reference/exit-exit-exit.md)   
 [_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md)