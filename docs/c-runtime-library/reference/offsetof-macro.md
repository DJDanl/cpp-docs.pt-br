---
title: Macro offsetof | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
apitype: DLLExport
f1_keywords:
- offsetof
dev_langs:
- C++
helpviewer_keywords:
- structure members, offset
- offsetof macro
ms.assetid: f3b4eb16-a882-4d38-afc9-eebd976a7352
caps.latest.revision: 10
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 686de81ecfd4216f3011c93d3bf9be1bfdc55365
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="offsetof-macro"></a>Macro offsetof

Recupera o deslocamento de um membro do início de sua estrutura pai.

## <a name="syntax"></a>Sintaxe

```C
size_t offsetof(
   structName,
   memberName
);
```

### <a name="parameters"></a>Parâmetros

*structName*<br/>
Nome da estrutura de dados pai.

*Nome do membro*<br/>
Nome do membro na estrutura de dados pai para o qual determinar o deslocamento.

## <a name="return-value"></a>Valor de retorno

**offsetof** retorna o deslocamento em bytes, do membro especificado do início de sua estrutura de dados pai. É indefinido para campos de bits.

## <a name="remarks"></a>Comentários

O **offsetof** macro retorna o deslocamento em bytes de *memberName* desde o início da estrutura especificado por *structName* como um valor do tipo **size_ t**. Você pode especificar os tipos com o **struct** palavra-chave.

> [!NOTE]
> **offsetof** não é uma função e não pode ser descrita usando um protótipo de C.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**offsetof**|\<stddef.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
