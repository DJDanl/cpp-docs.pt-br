---
title: Arq, outpw, _outp, _outpw, _outpd
description: Descreve as funções obsoletas e removidas arq, outpw, _outp, _outpw e _outpd da biblioteca de tempo de execução do Microsoft C (CRT).
ms.date: 12/09/2019
api_name:
- _outpd
- _outp
- _outpw
- outp
- outpw
api_location:
- msvcrt.dll
- msvcr100.dll
- msvcr120.dll
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _outpw
- _outpd
- _outp
- outp
- outpw
- outpd
helpviewer_keywords:
- outpw function
- words
- _outpd function
- outpd function
- outp function
- ports, writing bytes at
- bytes, writing to ports
- words, writing to ports
- double words
- double words, writing to ports
- _outpw function
- _outp function
ms.assetid: c200fe22-41f6-46fd-b0be-ebb805b35181
ms.openlocfilehash: 03d3df0bae9c2fa3cdd107f3c0de65105077c401
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988379"
---
# <a name="outp-outpw-_outp-_outpw-_outpd"></a>Arq, outpw, _outp, _outpw, _outpd

Saídas, em uma porta, um byte (`outp`, `_outp`), uma palavra (`outpw`, `_outpw`) ou uma palavra dupla (`_outpd`).

> [!IMPORTANT]
> Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT.  
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```cpp
int _outp(
   unsigned short port,
   int databyte
);
unsigned short _outpw(
   unsigned short port,
   unsigned short dataword
);
unsigned long _outpd(
   unsigned short port,
   unsigned long dataword
);
```

### <a name="parameters"></a>Parâmetros

\ de *porta*
Número da porta.

*databyte,\ de dataword*
Valores de saída.

## <a name="return-value"></a>Valor retornado

As funções retornam a saída de dados. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

As funções `_outp`, `_outpw` e `_outpd` gravam um byte, uma palavra e uma palavra dupla, respectivamente, para a porta de saída especificada. O argumento *port* pode ser qualquer inteiro sem sinal no intervalo de 0 a 65.535, *databyte* pode ser qualquer inteiro no intervalo de 0 a 255 e *dataword* pode ser qualquer valor no intervalo de um inteiro, um inteiro curto sem sinal e um inteiro longo sem sinal, respectivamente.

Como essas funções gravam diretamente em uma porta de E/S, não é possível usá-las no código do usuário. Para obter informações sobre o uso de portas de E/S nesses sistemas operacionais, pesquise por “Serial Communications in Win32” (Comunicação Serial no Win32) no MSDN.

Os nomes `outp` e `outpw` são nomes mais antigos e preteridos para as funções `_outp` e `_outpw`. Para obter mais informações, consulte [nomes de funções POSIX](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names).

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_outp`|\<conio.h>|
|`_outpw`|\<conio.h>|
|`_outpd`|\<conio.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../c-runtime-library/console-and-port-i-o.md)\
[inp, inpw, _inp, _inpw, _inpd](../c-runtime-library/inp-inpw-inpd.md)
