---
title: codecvt_utf8_utf16 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- codecvt_utf8_utf16
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5187996fc377bca8633360082d07f7ec8a68ee57
ms.openlocfilehash: e628eb145b52cd3ab9b1e36770363c34099c6cb4
ms.lasthandoff: 02/25/2017

---
# <a name="codecvtutf8utf16"></a>codecvt_utf8_utf16
Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UTF-16 e um fluxo de bytes codificado como UTF-8.

```
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf8_utf16 : public _STD codecvt<Elem, char, StateType>
```

## <a name="parameters"></a>Parâmetros

`Elem`  
O tipo de elemento de caractere largo.  
`Maxcode`  
O número máximo de caracteres da faceta de localidade.  
`Mode`  
Informações de configuração para a faceta de localidade.  

## <a name="remarks"></a>Comentários

O fluxo de bytes pode ser gravado em um arquivo binário ou em um arquivo de texto.  

## <a name="requirements"></a>Requisitos

Cabeçalho: <codecvt> Namespace: std

