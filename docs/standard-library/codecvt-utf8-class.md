---
title: codecvt_utf8
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_utf8
helpviewer_keywords:
- codecvt_utf8 class
ms.assetid: 2a87478f-e2d4-4b8d-ad9c-00add01d1bb0
ms.openlocfilehash: 3e3ddeccac2c18eedb96746f1c442c6b42349783
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50626987"
---
# <a name="codecvtutf8"></a>codecvt_utf8

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-8.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf8 : public std::codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

*Elem*<br/>
O tipo de elemento de caractere largo.

*Maxcode*<br/>
O número máximo de caracteres da faceta de localidade.

*Modo*<br/>
Informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: \<codecvt > \

Namespace: std
