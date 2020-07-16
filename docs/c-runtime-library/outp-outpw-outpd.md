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
ms.openlocfilehash: ceaaefbbe6f9debfb5ac8e1e8f5f3d1bbb36c8a8
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86404054"
---
# <a name="outp-outpw-_outp-_outpw-_outpd"></a>Arq, outpw, _outp, _outpw, _outpd

Saídas, em uma porta, um byte ( `outp` , `_outp` ), uma palavra ( `outpw` , `_outpw` ) ou uma palavra dupla ( `_outpd` ).

> [!IMPORTANT]
> Essas funções estão obsoletas. A partir do Visual Studio 2015, eles não estão disponíveis no CRT. \
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```cpp
int _outp(
   unsigned short port,
   int data_byte
);
unsigned short _outpw(
   unsigned short port,
   unsigned short data_word
);
unsigned long _outpd(
   unsigned short port,
   unsigned long data_word
);
```

### <a name="parameters"></a>Parâmetros

*Porto*\
Número da porta.

*data_byte, data_word*\
Valores de saída.

## <a name="return-value"></a>Valor Retornado

As funções retornam a saída de dados. Não há nenhum retorno de erro.

## <a name="remarks"></a>Comentários

As funções `_outp`, `_outpw` e `_outpd` gravam um byte, uma palavra e uma palavra dupla, respectivamente, para a porta de saída especificada. O argumento *Port* pode ser qualquer inteiro não assinado no intervalo de 0 a 65.535. *data_byte* pode ser qualquer número inteiro no intervalo de 0-255. *data_word* pode ser qualquer valor no intervalo de um inteiro, um inteiro curto não assinado e um inteiro longo sem sinal, respectivamente.

Como essas funções gravam diretamente em uma porta de e/s, elas não podem ser usadas no código do Windows no modo de usuário.

Para obter informações sobre como usar portas de e/s no sistema operacional Windows, consulte [comunicações seriais](https://docs.microsoft.com/previous-versions/ff802693(v=msdn.10)).

Os `outp` `outpw` nomes e são nomes mais antigos e preteridos para as `_outp` `_outpw` funções e. Para obter mais informações, consulte [nomes de funções POSIX](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md#posix-function-names).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_outp`|\<conio.h>|
|`_outpw`|\<conio.h>|
|`_outpd`|\<conio.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[E/s de porta e de console](../c-runtime-library/console-and-port-i-o.md)\
[`inp`, `inpw`, `_inp`, `_inpw`, `_inpd`](../c-runtime-library/inp-inpw-inpd.md)
