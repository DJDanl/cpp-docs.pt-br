---
title: _outp, _outpw, _outpd
ms.date: 11/04/2016
apiname:
- _outpd
- _outp
- _outpw
apilocation:
- msvcrt.dll
- msvcr100.dll
- msvcr120.dll
- msvcr90.dll
- msvcr110_clr0400.dll
- msvcr110.dll
- msvcr80.dll
apitype: DLLExport
f1_keywords:
- _outpw
- _outpd
- _outp
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
ms.openlocfilehash: 1a507f4115a48372706590eb61f9e3e77a0e3548
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57752058"
---
# <a name="outp-outpw-outpd"></a>_outp, _outpw, _outpd

Saídas, em uma porta, um byte (`_outp`), uma palavra (`_outpw`) ou uma palavra dupla (`_outpd`).

> [!IMPORTANT]
>  Essas funções estão obsoletas. A partir do Visual Studio 2015, elas não estão disponíveis no CRT.

> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```

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

#### <a name="parameters"></a>Parâmetros
*port*<br/>
Número da porta.

*databyte, dataword*<br/>
Valores de saída.

## <a name="return-value"></a>Valor de retorno

As funções retornam a saída de dados. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

As funções `_outp`, `_outpw` e `_outpd` gravam um byte, uma palavra e uma palavra dupla, respectivamente, para a porta de saída especificada. O argumento *port* pode ser qualquer inteiro sem sinal no intervalo de 0 a 65.535, *databyte* pode ser qualquer inteiro no intervalo de 0 a 255 e *dataword* pode ser qualquer valor no intervalo de um inteiro, um inteiro curto sem sinal e um inteiro longo sem sinal, respectivamente.

Como essas funções gravam diretamente em uma porta de E/S, não é possível usá-las no código do usuário. Para obter informações sobre o uso de portas de E/S nesses sistemas operacionais, pesquise por “Serial Communications in Win32” (Comunicação Serial no Win32) no MSDN.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_outp`|\<conio.h>|
|`_outpw`|\<conio.h>|
|`_outpd`|\<conio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[E/S de porta e console](../c-runtime-library/console-and-port-i-o.md)<br/>
[_inp, _inpw, _inpd](../c-runtime-library/inp-inpw-inpd.md)
