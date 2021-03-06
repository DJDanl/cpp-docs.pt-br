---
title: _fpclass, _fpclassf
ms.date: 4/2/2020
api_name:
- _fpclass
- _fpclassf
- _o__fpclass
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
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fpclass
- _fpclass
- _fpclassf
- math/_fpclass
- float/_fpclass
- math/_fpclassf
helpviewer_keywords:
- fpclass function
- floating-point numbers, IEEE representation
- _fpclass function
- _fpclassf function
ms.assetid: 2774872d-3543-446f-bc72-db85f8b95a6b
ms.openlocfilehash: a6591d9348739d27831785a05f4a602aacdd4d0c
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82914842"
---
# <a name="_fpclass-_fpclassf"></a>_fpclass, _fpclassf

Retorna um valor que indica a classificação de ponto flutuante do argumento.

## <a name="syntax"></a>Sintaxe

```C
int _fpclass(
   double x
);

int _fpclassf(
   float x
); /* x64 only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante a ser testado.

## <a name="return-value"></a>Valor retornado

As funções **_fpclass** e **_fpclassf** retornam um valor inteiro que indica a classificação de ponto flutuante do argumento *x*. A classificação pode ter um dos valores a seguir, definidos em \<float.>.

|Valor|Descrição|
|-----------|-----------------|
|**_FPCLASS_SNAN**|Sinalização de NaN|
|**_FPCLASS_QNAN**|NaN silencioso|
|**_FPCLASS_NINF**|Infinito negativo (-INF)|
|**_FPCLASS_NN**|Negativo normalizado diferente de zero|
|**_FPCLASS_ND**|Negativo desnormalizado|
|**_FPCLASS_NZ**|Zero negativo (-0)|
|**_FPCLASS_PZ**|0 positivo (+0)|
|**_FPCLASS_PD**|Positivo desnormalizado|
|**_FPCLASS_PN**|Positivo normalizado diferente de zero|
|**_FPCLASS_PINF**|Infinito positivo (+INF)|

## <a name="remarks"></a>Comentários

As funções **_fpclass** e **_fpclassf** são específicas da Microsoft. Elas são semelhantes a [fpclassify](fpclassify.md), mas retornam informações mais detalhadas sobre o argumento. A função **_fpclassf** só estará disponível quando compilada para a plataforma x64.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fpclass**, **_fpclassf**|\<float.h>|

Para obter mais informações sobre compatibilidade e conformidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[isnan, _isnan, _isnanf](isnan-isnan-isnanf.md)<br/>
[fpclassify](fpclassify.md)<br/>
