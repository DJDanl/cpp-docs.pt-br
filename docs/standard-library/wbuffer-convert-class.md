---
title: Classe wbuffer_convert | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- xlocmon/stdext::cvt::wbuffer_convert
dev_langs:
- C++
helpviewer_keywords:
- wbuffer_convert class
ms.assetid: 4a56f9bf-4138-4612-b516-525fea401358
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e0153bf7d40dbd4290900d15b6e68d84d0c07869
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="wbufferconvert-class"></a>Classe wbuffer_convert
Descreve um buffer de fluxo que controla a transmissão de elementos de/para um buffer de fluxo de bytes.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Codecvt, class Elem = wchar_t, class Traits = std::char_traits<Elem>>
class wbuffer_convert
 : public std::basic_streambuf<Elem, Traits>
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Codecvt`|A faceta de [locale](../standard-library/locale-class.md) que representa o objeto de conversão.|  
|`Elem`|O tipo de elemento de caractere largo.|  
|`Traits`|As características associadas a *Elem*.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `_Elem`, cujas características dos caracteres são descritas pela classe `Traits`, de/para um buffer de fluxo de bytes do tipo `std::streambuf`.  
  
 A conversão entre uma sequência de valores `Elem` e as sequências multibyte é executada por um objeto da classe `Codecvt<Elem, char, std::mbstate_t>`, que atende aos requisitos da faceta de conversão de código padrão `std::codecvt<Elem, char, std::mbstate_t>`.  
  
 Um objeto desta classe de modelo armazena:  
  
-   Um ponteiro para o buffer de fluxo de bytes subjacente  
  
-   Um ponteiro para o objeto de conversão alocado (que é liberado quando [wbuffer_convert](../standard-library/wbuffer-convert-class.md)
