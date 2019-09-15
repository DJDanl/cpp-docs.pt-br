---
title: _callnewh
ms.date: 11/04/2016
api_name:
- _callnewh
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
- api-ms-win-crt-heap-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _callnewh
helpviewer_keywords:
- _callnewh
ms.assetid: 4dcb73e9-6384-4d12-a973-a8807d4de7a8
ms.openlocfilehash: 3e14450538807b164897c335f7e37d82d8562314
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939390"
---
# <a name="_callnewh"></a>_callnewh

Chama o *novo manipulador* atualmente instalado.

## <a name="syntax"></a>Sintaxe

```cpp
int _callnewh(
   size_t size
   )
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
A quantidade de memória que o [novo operador](../../cpp/new-operator-cpp.md) tentou alocar.

## <a name="return-value"></a>Valor de retorno

|Valor|Descrição|
|-----------|-----------------|
|0|Failure Não há um novo manipulador instalado ou nenhum novo manipulador está ativo.|
|1|Êxito O novo manipulador é instalado e ativo. A alocação de memória pode ser repetida.|

## <a name="exceptions"></a>Exceções

Essa função gerará [bad_alloc](../../standard-library/bad-alloc-class.md) se o *novo manipulador* não puder ser localizado.

## <a name="remarks"></a>Comentários

O *novo manipulador* será chamado se o [novo operador](../../cpp/new-operator-cpp.md) falhar em alocar memória com sucesso. O novo manipulador pode então iniciar alguma ação apropriada, como liberar a memória, para que as alocações subsequentes tenham sucesso.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_callnewh|internal.h|

## <a name="see-also"></a>Consulte também

[_set_new_handler](set-new-handler.md)<br/>
[_set_new_mode](set-new-mode.md)<br/>
