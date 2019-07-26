---
title: codecvt_utf16
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_utf16
helpviewer_keywords:
- codecvt_utf16 class
ms.assetid: a9897f98-f84d-4db6-90ad-858b2727570c
ms.openlocfilehash: ca66a3273567a8d30a982211a6e977c129b00f5f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459719"
---
# <a name="codecvtutf16"></a>codecvt_utf16

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE ou UTF-16BE.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf16 : public std::codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

*Elem*\
O tipo de elemento de caractere largo.

*Maxcode*\
O número máximo de caracteres da faceta de localidade.

*Moda*\
Informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

Essa classe de modelo é convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE, se o modo & little_endian ou UTF-16BE caso contrário.

O fluxo de bytes deve ser gravado em um arquivo binário. Ele pode ser corrompido se gravado em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: \<codecvt >

Namespace: std