---
title: codecvt_utf16 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: codecvt/std::codecvt_utf16
dev_langs: C++
helpviewer_keywords: codecvt_utf16 class
ms.assetid: a9897f98-f84d-4db6-90ad-858b2727570c
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e6d7746369c5ecb559cae3b787b8bbf2f475ba28
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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