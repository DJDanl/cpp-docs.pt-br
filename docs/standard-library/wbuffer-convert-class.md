---
title: Classe wbuffer_convert | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xlocmon/stdext::cvt::wbuffer_convert
dev_langs: C++
helpviewer_keywords: wbuffer_convert class
ms.assetid: 4a56f9bf-4138-4612-b516-525fea401358
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cee0951401c43cb72d58bf7e9e61e4f4a89d6675
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
