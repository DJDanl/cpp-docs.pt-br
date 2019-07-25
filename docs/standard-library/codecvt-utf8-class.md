---
title: codecvt_utf8
ms.date: 11/04/2016
f1_keywords:
- codecvt/std::codecvt_utf8
helpviewer_keywords:
- codecvt_utf8 class
ms.assetid: 2a87478f-e2d4-4b8d-ad9c-00add01d1bb0
ms.openlocfilehash: dcbb34c300d7c15f89c4a882275be0efd68359dc
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458709"
---
# <a name="codecvtutf8"></a>codecvt_utf8

Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-8.

```cpp
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf8 : public std::codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

*Elem*\
O tipo de elemento de caractere largo.

*Maxcode*\
O número máximo de caracteres da faceta de localidade.

*Moda*\
Informações de configuração para a faceta de localidade.

## <a name="remarks"></a>Comentários

O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.

## <a name="requirements"></a>Requisitos

Cabeçalho: \<codecvt >

Namespace: std
