---
title: _findfirst, _findfirst32, _findfirst32i64, _findfirst64, _findfirst64i32, _findfirsti64, _wfindfirst, _wfindfirst32, _wfindfirst32i64, _wfindfirst64, _wfindfirst64i32, _wfindfirsti64 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _findfirst
- _wfindfirst
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
- findfirst32i64
- wfindfirst32i64
- tfindfirst64
- _findfirst64i32
- _wfindfirst32i64
- _wfindfirsti64
- wfindfirst
- _tfindfirsti64
- findfirst32
- _tfindfirst32
- _findfirsti64
- findfirst
- wfindfirst64
- wfindfirst32
- tfindfirst32
- _wfindfirst64i32
- findfirst64i32
- tfindfirst64i32
- _wfindfirst
- findfirsti64
- _findfirst32i64
- wfindfirst64i32
- _wfindfirst32
- _findfirst32
- _tfindfirst32i64
- tfindfirst
- _tfindfirst64i32
- findfirst64
- _tfindfirst
- _findfirst64
- _tfindfirst64
- tfindfirst32i64
- _findfirst
- _wfindfirst64
dev_langs:
- C++
helpviewer_keywords:
- _tfindfirst64 function
- _wfindfirst64i32 function
- _wfindfirst32i64 function
- wfindfirst32 function
- _findfirst function
- wfindfirst64 function
- _wfindfirst function
- _findfirst64i32 function
- wfindfirst function
- _findfirst64 function
- tfindfirst32 function
- _tfindfirst64i32 function
- findfirst function
- findfirst32i64 function
- tfindfirst64 function
- _tfindfirst32 function
- tfindfirst32i64 function
- tfindfirst64i32 function
- _wfindfirsti64 function
- _findfirst32i64 function
- findfirst32 function
- findfirsti64 function
- findfirst64i32 function
- tfindfirsti64 function
- tfindfirst function
- _wfindfirst32 function
- wfindfirsti64 function
- _tfindfirsti64 function
- _tfindfirst function
- _tfindfirst32i64 function
- findfirst64 function
- _findfirst32 function
- _findfirsti64 function
- wfindfirst32i64 function
- wfindfirst64i32 function
- _wfindfirst64 function
ms.assetid: 9bb46d1a-b946-47de-845a-a0b109a33ead
caps.latest.revision: 25
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: baf853db4fe1a23ee726423a052604a0db8764c9
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="findfirst-findfirst32-findfirst32i64-findfirst64-findfirst64i32-findfirsti64-wfindfirst-wfindfirst32-wfindfirst32i64-wfindfirst64-wfindfirst64i32-wfindfirsti64"></a>_findfirst, _findfirst32, _findfirst32i64, _findfirst64, _findfirst64i32, _findfirsti64, _wfindfirst, _wfindfirst32, _wfindfirst32i64, _wfindfirst64, _wfindfirst64i32, _wfindfirsti64
Forneça informações sobre a primeira instância de um nome de arquivo que corresponde ao arquivo especificado no argumento `filespec`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _findfirst(  
   const char *filespec,  
   struct _finddata_t *fileinfo   
);  
intptr_t _findfirst32(  
   const char *filespec,  
   struct _finddata32_t *fileinfo   
);  
intptr_t _findfirst64(  
   const char *filespec,  
   struct _finddata64_t *fileinfo   
);  
intptr_t _findfirsti64(  
   const char *filespec,  
   struct _finddatai64_t *fileinfo   
);  
intptr_t _findfirst32i64(  
   const char *filespec,  
   struct _finddata32i64_t *fileinfo   
);  
intptr_t _findfirst64i32(  
   const char *filespec,  
   struct _finddata64i32_t *fileinfo   
);  
intptr_t _wfindfirst(  
   const wchar_t *filespec,  
   struct _wfinddata_t *fileinfo   
);  
intptr_t _wfindfirst32(  
   const wchar_t *filespec,  
   struct _wfinddata32_t *fileinfo   
);  
intptr_t _wfindfirst64(  
   const wchar_t *filespec,  
   struct _wfinddata64_t *fileinfo   
);  
intptr_t _wfindfirsti64(  
   const wchar_t *filespec,  
   struct _wfinddatai64_t *fileinfo   
);  
intptr_t _wfindfirst32i64(  
   const wchar_t *filespec,  
   struct _wfinddata32i64_t *fileinfo   
);  
intptr_t _wfindfirst64i32(  
   const wchar_t *filespec,  
   struct _wfinddata64i32_t *fileinfo   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filespec`  
 Especificação de arquivo de destino (pode incluir caracteres curinga).  
  
 `fileinfo`  
 Buffer de informações do arquivo.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, `_findfirst` retornará um identificador de pesquisa exclusivo que identifica o arquivo ou o grupo de arquivos que corresponde à especificação `filespec`, que pode ser usada em uma chamada posterior para [_findnext](../../c-runtime-library/reference/findnext-functions.md) ou `_findclose`. Caso contrário, `_findfirst` retorna -1 e define `errno` para um dos valores a seguir.  
  
 `EINVAL`  
 Parâmetro inválido: `filespec` ou `fileinfo` era `NULL`. Ou o sistema operacional retornou um erro inesperado.  
  
 `ENOENT`  
 Especificação de arquivo que não pôde ser correspondida.  
  
 `ENOMEM`  
 Memória insuficiente.  
  
 `EINVAL`  
 Especificação de nome de arquivo inválida ou o nome de arquivo fornecido era maior que `MAX_PATH`.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
## <a name="remarks"></a>Comentários  
 Você deve chamar [_findclose](../../c-runtime-library/reference/findclose.md) após terminar de usar a função `_findfirst` ou `_findnext` (ou qualquer variante). Isso libera recursos usados por essas funções em seu aplicativo.  
  
 As variações dessas funções que têm o prefixo `w` são versões de caractere largo; caso contrário, elas são idênticas às funções de byte único correspondentes.  
  
 Variações dessas funções dão suporte a tipos de hora de 32 ou de 64 bits e a tamanhos de arquivo de 32 ou de 64 bits. O primeiro sufixo numérico (`32` ou `64`) indica o tamanho do tipo de hora; o segundo sufixo é `i32` ou `i64`, que indica se o tamanho do arquivo é representado como um inteiro de 32 ou de 64 bits. Para obter informações sobre quais versões dão suporte a tamanhos de arquivo e tipos de hora de 32 e de 64 bits, consulte a tabela a seguir. O sufixo `i32` ou `i64` é omitido se for igual ao tamanho do tipo de hora, de modo que `_findfirst64` também dá suporte a tamanhos de arquivo de 64 bits e `_findfirst32` dá suporte apenas a tamanhos de arquivos de 32 bits.  
  
 Essas funções usam várias formas da estrutura `_finddata_t` para o parâmetro `fileinfo`. Para obter mais informações sobre a estrutura, consulte [Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md).  
  
 As variações que usam um tipo de hora de 64 bits permitem que as datas de criação de arquivo sejam expressas até 23:59:59 de 31 de dezembro de 3000, no horário UTC. As que usam tipos de hora de 32 bits representam datas somente até 23:59:59 de 18 de janeiro de 2038, no horário UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.  
  
 A menos que você tenha um motivo específico para usar as versões que especificam o tamanho da hora explicitamente, use `_findfirst` ou `_wfindfirst`. Se precisar dar suporte a tamanhos de arquivos de mais de 3 GB, use `_findfirsti64` ou `_wfindfirsti64`. Todas essas funções usam o tipo de hora de 64 bits. Em versões anteriores, elas usavam um tipo de hora de 32 bits. Se esta alteração prejudicar algum aplicativo, você poderá definir `_USE_32BIT_TIME_T` para voltar para o comportamento antigo. Se `_USE_32BIT_TIME_T` for definido, `_findfirst`, `_finfirsti64` e suas versões Unicode correspondentes usarão uma hora de 32 bits.  
  
### <a name="time-type-and-file-length-type-variations-of-findfirst"></a>Variações de tipo de hora e tipo de tamanho de arquivo de _findfirst  
  
|Funções|`_USE_32BIT_TIME_T` definido?|Tipo de hora|Tipo de tamanho de arquivo|  
|---------------|----------------------------------|---------------|----------------------|  
|`_findfirst`, `_wfindfirst`|Não definido|64 bits|32 bits|  
|`_findfirst`, `_wfindfirst`|Definido|32 bits|32 bits|  
|`_findfirst32`, `_wfindfirst32`|Não afetado pela definição de macro|32 bits|32 bits|  
|`_findfirst64`, `_wfindfirst64`|Não afetado pela definição de macro|64 bits|64 bits|  
|`_findfirsti64`, `_wfindfirsti64`|Não definido|64 bits|64 bits|  
|`_findfirsti64`, `_wfindfirsti64`|Definido|32 bits|64 bits|  
|`_findfirst32i64`, `_wfindfirst32i64`|Não afetado pela definição de macro|32 bits|64 bits|  
|`_findfirst64i32`, `_wfindfirst64i32`|Não afetado pela definição de macro|64 bits|32 bits|  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tfindfirst`|`_findfirst`|`_findfirst`|`_wfindfirst`|  
|`_tfindfirst32`|`_findfirst32`|`_findfirst32`|`_wfindfirst32`|  
|`_tfindfirst64`|`_findfirst64`|`_findfirst64`|`_wfindfirst64`|  
|`_tfindfirsti64`|`_findfirsti64`|`_findfirsti64`|`_wfindfirsti64`|  
|`_tfindfirst32i64`|`_findfirst32i64`|`_findfirst32i64`|`_wfindfirst32i64`|  
|`_tfindfirst64i32`|`_findfirst64i32`|`_findfirst64i32`|`_wfindfirst64i32`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_findfirst`|\<io.h>|  
|`_findfirst32`|\<io.h>|  
|`_findfirst64`|\<io.h>|  
|`_findfirsti64`|\<io.h>|  
|`_findfirst32i64`|\<io.h>|  
|`_findfirst64i32`|\<io.h>|  
|`_wfindfirst`|\<io.h> ou \<wchar.h>|  
|`_wfindfirst32`|\<io.h> ou \<wchar.h>|  
|`_wfindfirst64`|\<io.h> ou \<wchar.h>|  
|`_wfindfirsti64`|\<io.h> ou \<wchar.h>|  
|`_wfindfirst32i64`|\<io.h> ou \<wchar.h>|  
|`_wfindfirst64i32`|\<io.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Chamadas do sistema](../../c-runtime-library/system-calls.md)   
 [Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md)
