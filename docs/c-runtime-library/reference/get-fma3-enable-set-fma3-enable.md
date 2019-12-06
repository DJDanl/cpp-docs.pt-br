---
title: _get_FMA3_enable, _set_FMA3_enable
ms.date: 04/05/2018
api_name:
- _get_FMA3_enable
- _set_FMA3_enable
api_location:
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
- math/_get_FMA3_enable
- math/_set_FMA3_enable
helpviewer_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
ms.assetid: 4c1dc4bc-e86b-451b-9211-5a2ba6c98ee4
ms.openlocfilehash: dee75bf5b16b5fe5b619444f7f2736010bb42a84
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857796"
---
# <a name="_get_fma3_enable-_set_fma3_enable"></a>_get_FMA3_enable, _set_FMA3_enable

Obtém ou define um sinalizador que especifica se as funções da biblioteca de pontos flutuantes matemáticas do transcendental usam instruções FMA3 no código compilado para plataformas x64.

## <a name="syntax"></a>Sintaxe

```C
int _set_FMA3_enable(int flag);
int _get_FMA3_enable();
```

### <a name="parameters"></a>Parâmetros

*flag*<br/>
Defina como 1 para habilitar as implementações de FMA3 das funções da biblioteca de pontos flutuantes matemáticas do transcendental em plataformas x64, ou como 0 para usar as implementações que não usam instruções FMA3.

## <a name="return-value"></a>Valor retornado

Um valor diferente de zero se as implementações de FMA3 das funções da biblioteca de pontos flutuantes matemáticas do transcendental estiverem habilitadas. Caso contrário, zero.

## <a name="remarks"></a>Comentários

Use a função **_set_FMA3_enable** para habilitar ou desabilitar o uso de instruções FMA3 nas funções de ponto flutuante de matemática transcendental na biblioteca CRT. O valor de retorno reflete a implementação em uso após a alteração. Se a CPU não oferecer suporte a instruções FMA3, essa função não poderá habilitá-las na biblioteca e o valor de retorno será zero. Use **_get_FMA3_enable** para obter o estado atual da biblioteca. Por padrão, em plataformas x64, o código de inicialização CRT detecta se a CPU dá suporte a instruções FMA3 e habilita ou desabilita as implementações de FMA3 na biblioteca.

Como as implementações de FMA3 usam algoritmos diferentes, pequenas diferenças no resultado de computações podem ser observadas quando as implementações de FMA3 são habilitadas ou desabilitadas, ou entre computadores que não dão suporte a FMA3. Para obter mais informações, consulte [problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md).

## <a name="requirements"></a>Requisitos do

As funções **_set_FMA3_enable** e **_get_FMA3_enable** só estão disponíveis nas versões x64 do CRT.

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_FMA3_enable**, **_get_FMA3_enable**| C: \<math.h><br />C++: \<cmath > ou \<Math. h >|

As funções **_set_FMA3_enable** e **_get_FMA3_enable** são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md)<br/>
