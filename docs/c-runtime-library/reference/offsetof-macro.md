---
title: Macro offsetof
ms.date: 11/04/2016
api_location:
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- offsetof
helpviewer_keywords:
- structure members, offset
- offsetof macro
ms.assetid: f3b4eb16-a882-4d38-afc9-eebd976a7352
ms.openlocfilehash: 278fca89046fcfc98e8c3ff726918cb4319e4ab0
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70951257"
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

*memberName*<br/>
Nome do membro na estrutura de dados pai para o qual determinar o deslocamento.

## <a name="return-value"></a>Valor de retorno

**offsetof** retorna o deslocamento em bytes do membro especificado do início de sua estrutura de dados pai. É indefinido para campos de bits.

## <a name="remarks"></a>Comentários

A macro **offsetof** retorna o deslocamento em bytes de *MemberName* do início da estrutura especificada por *structName* como um valor do tipo **size_t**. Você pode especificar tipos com a palavra-chave **struct** .

> [!NOTE]
> **offsetof** não é uma função e não pode ser descrito usando um protótipo C.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**offsetof**|\<stddef.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
