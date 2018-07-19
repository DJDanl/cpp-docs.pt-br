---
title: codecvt_utf8_utf16 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- codecvt/std::cvt_utf8_utf16
dev_langs:
- C++
helpviewer_keywords:
- codecvt_utf8_utf16 class
ms.assetid: 4c12c881-5dba-4e39-b338-0b9caff5af29
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 545fda08a027b1610f82d17c89ae98241ee5502b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38958124"
---
# <a name="codecvtutf8utf16"></a>codecvt_utf8_utf16

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UTF-16 e um fluxo de bytes codificado como UTF-8.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf8_utf16 : public _STD codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

*Elem* o tipo de elemento de caractere largo.
*Maxcode* o número máximo de caracteres para a faceta de localidade.
*Modo* informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: <codecvt> Namespace: std
