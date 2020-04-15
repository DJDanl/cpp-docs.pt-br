---
title: _callnewh
ms.date: 4/2/2020
api_name:
- _callnewh
- _o__callnewh
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _callnewh
helpviewer_keywords:
- _callnewh
ms.assetid: 4dcb73e9-6384-4d12-a973-a8807d4de7a8
ms.openlocfilehash: d93de7f963a370810ed3b30af04d6d602abf6313
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333657"
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

*Tamanho*<br/>
A quantidade de memória que o [novo operador](../../cpp/new-operator-cpp.md) tentou alocar.

## <a name="return-value"></a>Valor retornado

|Valor|Descrição|
|-----------|-----------------|
|0|Falha: nenhum novo manipulador está instalado ou nenhum novo manipulador está ativo.|
|1|Sucesso: o novo manipulador está instalado e ativo. A alocação de memória pode ser repetida.|

## <a name="exceptions"></a>Exceções

Essa função gerará [bad_alloc](../../standard-library/bad-alloc-class.md) se o *novo manipulador* não puder ser localizado.

## <a name="remarks"></a>Comentários

O *novo manipulador* será chamado se o [novo operador](../../cpp/new-operator-cpp.md) falhar em alocar memória com sucesso. O novo manipulador pode então iniciar alguma ação apropriada, como liberar a memória, para que as alocações subsequentes tenham sucesso.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_callnewh|internal.h|

## <a name="see-also"></a>Confira também

[_set_new_handler](set-new-handler.md)<br/>
[_set_new_mode](set-new-mode.md)<br/>
