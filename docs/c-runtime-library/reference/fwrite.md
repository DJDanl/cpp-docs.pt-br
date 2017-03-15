---
title: fwrite | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fwrite
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fwrite
dev_langs:
- C++
helpviewer_keywords:
- streams, writing data to
- fwrite function
ms.assetid: 7afacf3a-72d7-4a50-ba2e-bea1ab9f4124
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: d7c61e8d7b201b2ff5cc0c23378e545e41642445
ms.lasthandoff: 02/25/2017

---
# <a name="fwrite"></a>fwrite
Grava dados em um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
size_t fwrite(  
   const void *buffer,  
   size_t size,  
   size_t count,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `buffer`  
 Ponteiro para os dados a serem gravados.  
  
 `size`  
 Tamanho do item, em bytes.  
  
 `count`  
 Máximo de itens a serem gravados.  
  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 `fwrite` retorna quantos itens são gravados, o que pode ser menor que `count` em caso de erro. Além disso, em caso de erro, não será possível determinar o indicador de posição do arquivo. Se `stream` ou `buffer` for um ponteiro nulo ou se for especificado um número ímpar de bytes a serem gravados no modo Unicode, a função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essa função define `errno` como `EINVAL` e retorna 0.  
  
## <a name="remarks"></a>Comentários  
 A função `fwrite` grava até `count` itens, com `size` de comprimento cada um, de `buffer` até o`stream` de saída. O ponteiro do arquivo associado a `stream` (se houver) é incrementado pela quantidade de bytes gravados. Se `stream` for aberto no modo de texto, cada avanço de linha será substituído por um par carro de retorno de avanço de linha. A substituição não interfere no valor retornado.  
  
 Quando `stream` é aberto no modo de conversão Unicode (por exemplo, se `stream` for aberto com a chamada de `fopen` e o uso de um parâmetro de modo que inclua `ccs=UNICODE`, `ccs=UTF-16LE` ou `ccs=UTF-8`, ou se o modo for alterado para um modo de conversão de Unicode com o uso de `_setmode` e um parâmetro de modo que inclua `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT`)`buffer` é interpretado como ponteiro para uma matriz de `wchar_t` que contém dados UTF-16. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.  
  
 Como essa função bloqueia o thread da chamada, ela é thread-safe. Para uma versão sem bloqueio, consulte `_fwrite_nolock`.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fwrite`|\<stdio.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [thread](../../c-runtime-library/reference/fread.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::IO::FileStream::Write](https://msdn.microsoft.com/en-us/library/system.io.filestream.write.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)   
 [fread](../../c-runtime-library/reference/fread.md)   
 [_fwrite_nolock](../../c-runtime-library/reference/fwrite-nolock.md)   
 [_write](../../c-runtime-library/reference/write.md)
