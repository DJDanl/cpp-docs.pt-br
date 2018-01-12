---
title: _findnext, _findnext32, _findnext32i64, _findnext64, _findnext64i32, _findnexti64, _wfindnext, _wfindnext32, _wfindnext32i64, _wfindnext64, _wfindnext64i32, _wfindnexti64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wfindnext
- _findnext
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- findnext
- _wfindnext32i64
- _tfindnext64i32
- findnext32
- findnext32i64
- wfindnext64i32
- _wfindnext
- tfindnext64
- findnexti64
- _findnexti64
- _tfindnexti64
- _findnext64i32
- tfindnexti64
- tfindnext32
- _wfindnext64i32
- findnext64i32
- _findnext
- _tfindnext32i64
- _wfindnext64
- wfindnext
- wfindnext32
- tfindnext32i64
- _findnext64
- _tfindnext64
- _wfindnext32
- findnext64
- _findnext32i64
- tfindnext
- wfindnexti64
- tfindnext64i32
- _tfindnext32
- wfindnext32i64
- wfindnext64
- _wfindnexti64
- _tfindnext
- _findnext32
dev_langs: C++
helpviewer_keywords:
- _wfindnexti64 function
- _tfindnext32 function
- wfindnexti64 function
- _wfindnext32i64 function
- findnext32i64 function
- tfindnext64i32 function
- _tfindnext64i32 function
- _findnext function
- findnext64i32 function
- _tfindnext function
- findnext32 function
- tfindnext32 function
- _findnext32 function
- _tfindnext32i64 function
- _wfindnext function
- tfindnext function
- _findnext64 function
- findnext64 function
- _findnext64i32 function
- wfindnext32i64 function
- findnext function
- wfindnext32 function
- _wfindnext64i32 function
- findnexti64 function
- _wfindnext64 function
- _findnext32i64 function
- _findnexti64 function
- _tfindnext64 function
- wfindnext64i32 function
- tfindnexti64 function
- wfindnext64 function
- wfindnext function
- tfindnext64 function
- _wfindnext32 function
- tfindnext32i64 function
- _tfindnexti64 function
ms.assetid: 75d97188-5add-4698-a46c-4c492378f0f8
caps.latest.revision: "17"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6fbb76781c04afb1de970cde3d233d54909b64a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="findnext-findnext32-findnext32i64-findnext64-findnext64i32-findnexti64-wfindnext-wfindnext32-wfindnext32i64-wfindnext64-wfindnext64i32-wfindnexti64"></a>_findnext, _findnext32, _findnext32i64, _findnext64, _findnext64i32, _findnexti64, _wfindnext, _wfindnext32, _wfindnext32i64, _wfindnext64, _wfindnext64i32, _wfindnexti64
Localize o próximo nome, se houver, que corresponde ao argumento `filespec` em uma chamada anterior a [_findfirst](../../c-runtime-library/reference/findfirst-functions.md) e altere o conteúdo da estrutura `fileinfo` adequadamente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _findnext(  
   intptr_t handle,  
   struct _finddata_t *fileinfo   
);  
int _findnext32(  
   intptr_t handle,  
   struct _finddata32_t *fileinfo   
);  
int _findnext64(  
   intptr_t handle,  
   struct __finddata64_t *fileinfo   
);  
int _findnexti64(  
   intptr_t handle,  
   struct __finddatai64_t *fileinfo   
);  
int _findnext32i64(  
   intptr_t handle,  
   struct _finddata32i64_t *fileinfo   
);  
int _findnext64i32(  
   intptr_t handle,  
   struct _finddata64i32_t *fileinfo   
);  
int _wfindnext(  
   intptr_t handle,  
   struct _wfinddata_t *fileinfo   
);  
int _wfindnext32(  
   intptr_t handle,  
   struct _wfinddata32_t *fileinfo   
);  
int _wfindnext64(  
   intptr_t handle,  
   struct _wfinddata64_t *fileinfo   
);  
int _wfindnexti64(  
   intptr_t handle,  
   struct _wfinddatai64_t *fileinfo   
);  
int _wfindnext32i64(  
   intptr_t handle,  
   struct _wfinddatai64_t *fileinfo   
);  
int _wfindnext64i32(  
   intptr_t handle,  
   struct _wfinddata64i32_t *fileinfo   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `handle`  
 Identificador de pesquisa retornado por uma chamada anterior a `_findfirst`.  
  
 `fileinfo`  
 Buffer de informações do arquivo.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, retornará 0. Caso contrário, retornará -1 e define `errno` para um valor que indica a natureza da falha. Os possíveis códigos de erro são mostrados na tabela a seguir.  
  
 `EINVAL`  
 Parâmetro inválido: `fileinfo` era `NULL`. Ou o sistema operacional retornou um erro inesperado.  
  
 `ENOENT`  
 Não foi possível encontrar mais arquivos correspondentes.  
  
 `ENOMEM`  
 Não há memória suficiente ou o tamanho do nome do arquivo ultrapassou `MAX_PATH`.  
  
 Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
## <a name="remarks"></a>Comentários  
 Você deve chamar [_findclose](../../c-runtime-library/reference/findclose.md) após terminar de usar a função `_findfirst` ou `_findnext` (ou qualquer variante). Isso libera recursos usados por essas funções em seu aplicativo.  
  
 As variações dessas funções com o prefixo `w` são versões de caractere largo; caso contrário, elas são idênticas às funções de byte único correspondentes.  
  
 Variações dessas funções dão suporte a tipos de hora de 32 ou de 64 bits e a tamanhos de arquivo de 32 ou de 64 bits. O primeiro sufixo numérico (`32` ou `64`) indica o tamanho do tipo de hora usado; o segundo sufixo é `i32` ou `i64`, que indica se o tamanho do arquivo é representado como um inteiro de 32 ou de 64 bits. Para obter informações sobre quais versões dão suporte a tamanhos de arquivo e tipos de hora de 32 e de 64 bits, consulte a tabela a seguir. As variações que usam um tipo de hora de 64 bits permitem que as datas de criação de arquivos sejam expressas até 23:59:59 de 31 de dezembro de 3000, no horário UTC; enquanto as que usam tipos de hora de 32 bits representam apenas datas até 23:59:59 de 18 de janeiro de 2038, no horário UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.  
  
 A menos que você tenha um motivo específico para usar as versões que especificam o tamanho da hora explicitamente, use `_findnext` ou `_wfindnext`. Se precisar dar suporte a tamanhos de arquivos de mais de 3 GB, use `_findnexti64` ou `_wfindnexti64`. Todas essas funções usam o tipo de hora de 64 bits. Nas versões anteriores, elas usavam um tipo de hora de 32 bits. Se esta alteração prejudicar algum aplicativo, você poderá definir `_USE_32BIT_TIME_T` para obter o comportamento antigo. Se `_USE_32BIT_TIME_T` for definido, `_findnext`, `_finnexti64` e suas versões Unicode correspondentes usarão uma hora de 32 bits.  
  
### <a name="time-type-and-file-length-type-variations-of-findnext"></a>Variações de tipo de hora e tipo de tamanho de arquivo de _findnext  
  
|Funções|`_USE_32BIT_TIME_T` definido?|Tipo de hora|Tipo de tamanho de arquivo|  
|---------------|----------------------------------|---------------|----------------------|  
|`_findnext`, `_wfindnext`|Não definido|64 bits|32 bits|  
|`_findnext`, `_wfindnext`|Definido|32 bits|32 bits|  
|`_findnext32`, `_wfindnext32`|Não afetado pela definição de macro|32 bits|32 bits|  
|`_findnext64`, `_wfindnext64`|Não afetado pela definição de macro|64 bits|64 bits|  
|`_findnexti64`, `_wfindnexti64`|Não definido|64 bits|64 bits|  
|`_findnexti64`, `_wfindnexti64`|Definido|32 bits|64 bits|  
|`_findnext32i64`, `_wfindnext32i64`|Não afetado pela definição de macro|32 bits|64 bits|  
|`_findnext64i32`, `_wfindnext64i32`|Não afetado pela definição de macro|64 bits|32 bits|  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tfindnext`|`_findnext`|`_findnext`|`_wfindnext`|  
|`_tfindnext32`|`_findnext32`|`_findnext32`|`_wfindnext32`|  
|`_tfindnext64`|`_findnext64`|`_findnext64`|`_wfindnext64`|  
|`_tfindnexti64`|`_findnexti64`|`_findnexti64`|`_wfindnexti64`|  
|`_tfindnext32i64`|`_findnext32i64`|`_findnext32i64`|`_wfindnext32i64`|  
|`_tfindnext64i32`|`_findnext64i32`|`_findnext64i32`|`_wfindnext64i32`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_findnext`|\<io.h>|  
|`_findnext32`|\<io.h>|  
|`_findnext64`|\<io.h>|  
|`_findnexti64`|\<io.h>|  
|`_findnext32i64`|\<io.h>|  
|`_findnext64i32`|\<io.h>|  
|`_wfindnext`|\<io.h> ou \<wchar.h>|  
|`_wfindnext32`|\<io.h> ou \<wchar.h>|  
|`_wfindnext64`|\<io.h> ou \<wchar.h>|  
|`_wfindnexti64`|\<io.h> ou \<wchar.h>|  
|`_wfindnext32i64`|\<io.h> ou \<wchar.h>|  
|`_wfindnext64i32`|\<io.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas do sistema](../../c-runtime-library/system-calls.md)   
 [Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md)