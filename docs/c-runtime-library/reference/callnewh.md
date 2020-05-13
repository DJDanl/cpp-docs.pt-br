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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _callnewh
helpviewer_keywords:
- _callnewh
ms.assetid: 4dcb73e9-6384-4d12-a973-a8807d4de7a8
ms.openlocfilehash: 3990d4b15c25cfd6c753c2b1d44c112971ff59af
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82918793"
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

## <a name="return-value"></a>Valor retornado

|Valor|Descrição|
|-----------|-----------------|
|0|Falha: nenhum novo manipulador está instalado ou nenhum novo manipulador está ativo.|
|1|Sucesso: o novo manipulador está instalado e ativo. A alocação de memória pode ser repetida.|

## <a name="exceptions"></a>Exceções

Essa função gerará [bad_alloc](../../standard-library/bad-alloc-class.md) se o *novo manipulador* não puder ser localizado.

## <a name="remarks"></a>Comentários

O *novo manipulador* será chamado se o [novo operador](../../cpp/new-operator-cpp.md) falhar em alocar memória com sucesso. O novo manipulador pode então iniciar alguma ação apropriada, como liberar a memória, para que as alocações subsequentes tenham sucesso.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|_callnewh|internal.h|

## <a name="see-also"></a>Consulte também

[_set_new_handler](set-new-handler.md)<br/>
[_set_new_mode](set-new-mode.md)<br/>
