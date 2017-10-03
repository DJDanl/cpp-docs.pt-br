---
title: codecvt_utf16 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- codecvt/std::codecvt_utf16
dev_langs:
- C++
helpviewer_keywords:
- codecvt_utf16 class
ms.assetid: a9897f98-f84d-4db6-90ad-858b2727570c
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 68b6b058d6962758a3b3e42fcde943699820fa12
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="codecvtutf16"></a>codecvt_utf16
Representa uma faceta de [localidade](../standard-library/locale-class.md) convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE ou UTF-16BE.

```
template<class Elem, unsigned long Maxcode = 0x10ffff, codecvt_mode Mode = (codecvt_mode)0>
class codecvt_utf16 : public std::codecvt<Elem, char, StateType>
```
## <a name="parameters"></a>Parâmetros
`Elem`  
O tipo de elemento de caractere largo.  
`Maxcode`  
O número máximo de caracteres da faceta de localidade.  
`Mode`  
Informações de configuração para a faceta de localidade.  

## <a name="remarks"></a>Comentários
Essa classe de modelo é convertida entre caracteres largos codificados como UCS-2 ou UCS-4 e um fluxo de bytes codificado como UTF-16LE, se o modo & little_endian ou UTF-16BE caso contrário.

O fluxo de bytes deve ser gravado em um arquivo binário. Ele pode ser corrompido se gravado em um arquivo de texto.

## <a name="requirements"></a>Requisitos
Cabeçalho: \<codecvt> Namespace: std
