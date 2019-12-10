---
title: inp, _inp, inpw, _inpw, _inpd
description: Descreve as funções INP, _inp, inpw, _inpd _inpw e removidas obsoletas da Microsoft C Runtime Library (CRT).
ms.date: 12/09/2019
api_name:
- inp
- inpw
- _inp
- _inpw
- _inpd
api_location:
- msvcrt.dll
- msvcr120.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
- msvcr100.dll
- msvcr90.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- inp
- inpw
- _inp
- _inpw
- _inpd
helpviewer_keywords:
- inp function
- inpw function
- ports, I/O routines
- inpd function
- _inp function
- _inpd function
- I/O [CRT], port
- _inpw function
ms.assetid: 5d9c2e38-fc85-4294-86d5-7282cc02d1b3
ms.openlocfilehash: 48e0e58d2886c5a8bb90a86c81cb785d364666e8
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988717"
---
# <a name="inp-_inp-inpw-_inpw-_inpd"></a>inp, _inp, inpw, _inpw, _inpd

Entradas, de uma porta, um byte (`inp`, `_inp`), uma palavra (`inpw`, `_inpw`) ou uma palavra dupla (`_inpd`).

> [!IMPORTANT]
> Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT.  
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```cpp
int _inp(
   unsigned short port
);
unsigned short _inpw(
   unsigned short port
);
unsigned long _inpd(
   unsigned short port
);
```

### <a name="parameters"></a>Parâmetros

\ de *porta*
Número da porta de E/S.

## <a name="return-value"></a>Valor retornado

As funções retornam o byte, a palavra, ou as palavras duplas lidas de `port`. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

As funções `_inp`, `_inpw` e `_inpd` leem um byte, uma palavra e uma palavra dupla, respectivamente, da porta de entrada especificada. O valor de entrada pode ser qualquer inteiro curto sem sinal no intervalo de 0 a 65.535.

Como essas funções leem diretamente de uma porta de E/S, não é possível usá-las no código do usuário.

Os nomes `inp` e `inpw` são nomes mais antigos e preteridos para as funções `_inp` e `_inpw`. Para obter mais informações, consulte [nomes de funções POSIX](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names).

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_inp`|\<conio.h>|
|`_inpw`|\<conio.h>|
|`_inpd`|\<conio.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../c-runtime-library/console-and-port-i-o.md)\
[Arq, outpw, _outp, _outpw, _outpd](../c-runtime-library/outp-outpw-outpd.md)
