---
title: _get_FMA3_enable, _set_FMA3_enable
ms.date: 04/05/2018
apiname:
- _get_FMA3_enable
- _set_FMA3_enable
apilocation:
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
- math/_get_FMA3_enable
- math/_set_FMA3_enable
helpviewer_keywords:
- _get_FMA3_enable
- _set_FMA3_enable
ms.assetid: 4c1dc4bc-e86b-451b-9211-5a2ba6c98ee4
ms.openlocfilehash: 19eabc3b5a11246d5b0056bdafbb169e2a7de9f2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62332189"
---
# <a name="getfma3enable-setfma3enable"></a>_get_FMA3_enable, _set_FMA3_enable

Obtém ou define um sinalizador que especifica se as funções de ponto flutuante de biblioteca de matemática transcendental usam instruções FMA3 em código compilado para X64 plataformas.

## <a name="syntax"></a>Sintaxe

```C
int _set_FMA3_enable(int flag);
int _get_FMA3_enable();
```

### <a name="parameters"></a>Parâmetros

*flag*<br/>
Definido como 1 para habilitar as implementações de FMA3 das funções de ponto flutuante biblioteca Matemática transcendental em X64 plataformas, ou 0 para usar as implementações que não usam instruções FMA3.

## <a name="return-value"></a>Valor de retorno

Um valor diferente de zero, se as implementações de FMA3 das funções de ponto flutuante biblioteca Matemática transcendental estiverem habilitadas. Caso contrário, zero.

## <a name="remarks"></a>Comentários

Use o **_set_FMA3_enable** função para habilitar ou desabilitar o uso de instruções FMA3 em funções de ponto flutuante transcendental matemática na biblioteca do CRT. O valor retornado reflete a implementação em uso após a alteração. Se a CPU não oferece suporte a instruções FMA3, essa função não é possível habilitá-los na biblioteca e o valor retornado será zero. Use **_get_FMA3_enable** para obter o estado atual da biblioteca. Por padrão, em X64 plataformas, o código de inicialização do CRT detecta se a CPU dá suporte a instruções FMA3 e habilita ou desabilita as implementações de FMA3 na biblioteca.

Como as implementações de FMA3 usam algoritmos diferentes, pequenas diferenças no resultado de computações talvez observável quando as implementações de FMA3 estão habilitadas ou desabilitadas, ou entre computadores que ou não dão suporte a FMA3. Para obter mais informações, consulte [problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md).

## <a name="requirements"></a>Requisitos

O **_set_FMA3_enable** e **_get_FMA3_enable** funções só estão disponíveis no X64 versões do CRT.

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_FMA3_enable**, **_get_FMA3_enable**| C: \<math.h><br />C++: \<cmath > ou \<Math. h >|

O **_set_FMA3_enable** e **_get_FMA3_enable** funções são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Problemas de migração de ponto flutuante](../../porting/floating-point-migration-issues.md)<br/>
