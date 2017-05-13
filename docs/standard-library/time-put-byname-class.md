---
title: Classe time_put_byname | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- time_put_byname
- xloctime/std::time_put_byname
dev_langs:
- C++
helpviewer_keywords:
- time_put_byname class
ms.assetid: e08c2348-64d2-4ace-98b1-1496e14c7b1a
caps.latest.revision: 25
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: a21c91fba99623ae7c97ef1455278617746fc310
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="timeputbyname-class"></a>Classe time_put_byname
A classe de modelo derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put`\< CharType, OutputIterator >.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class CharType, class OutIt = ostreambuf_iterator<CharType, char_traits<CharType>>>
class time_put_byname : public time_put<CharType, OutputIterator>
{
public:
    explicit time_put_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit time_put_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~time_put_byname();

};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Locname`  
 Um nome de localidade.  
  
 `_Refs`  
 Uma contagem de referência inicial.  
  
## <a name="remarks"></a>Comentários  
 Seu comportamento é determinado pela localidade [nomeada](../standard-library/locale-class.md#name) `_Locname`. Cada construtor inicializa seu objeto base com [time_put](../standard-library/time-put-class.md#time_put)\<CharType, OutputIterator>( `_Refs`).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




