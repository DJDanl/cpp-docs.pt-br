---
title: codecvt_utf16 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- codecvt/std::codecvt_utf16
dev_langs:
- C++
helpviewer_keywords:
- codecvt_utf16 class
ms.assetid: a9897f98-f84d-4db6-90ad-858b2727570c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 93113e64e9b6a72f40557d063f83724c5ff8da62
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33841060"
---
# <a name="codecvtutf16"></a>codecvt_utf16

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE ou UTF-16BE.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf16 : public std::codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

`Elem` O tipo de elemento de caractere largo.
`Maxcode` O número máximo de caracteres para a faceta de localidade.
`Mode` Informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

Essa classe de modelo é convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE, se o modo & little_endian ou UTF-16BE caso contrário.

O fluxo de bytes deve ser gravado em um arquivo binário. Ele pode ser corrompido se gravado em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: \<codecvt> Namespace: std