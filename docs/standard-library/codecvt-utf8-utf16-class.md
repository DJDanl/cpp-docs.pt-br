---
title: codecvt_utf8_utf16 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- codecvt/std::cvt_utf8_utf16
dev_langs:
- C++
helpviewer_keywords:
- codecvt_utf8_utf16 class
ms.assetid: 4c12c881-5dba-4e39-b338-0b9caff5af29
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c0d3df3a6d9727722758f6af8b1dae2619b6bd0c
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="codecvtutf8utf16"></a>codecvt_utf8_utf16

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UTF-16 e um fluxo de bytes codificado como UTF-8.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf8_utf16 : public _STD codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

`Elem` O tipo de elemento de caractere largo.
`Maxcode` O número máximo de caracteres para a faceta de localidade.
`Mode` Informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: <codecvt> Namespace: std
