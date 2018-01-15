---
title: Classe time_get_byname | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: xloctime/std::time_get_byname
dev_langs: C++
helpviewer_keywords: time_get_byname class
ms.assetid: 6e54153e-da40-4bb9-a942-1a6ce57b30c9
caps.latest.revision: "25"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 37fc7d81148b0829d8e4b58552cca808e30ae618
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="timegetbyname-class"></a>Classe time_get_byname
A classe de modelo derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_get`\<CharType, InputIterator>.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Elem, class InputIterator =
    istreambuf_iterator<CharType, char_traits<CharType>>>
class time_get_byname : public time_get<CharType, InputIterator>
{
public:
    explicit time_get_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit time_get_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~time_get_byname()
};
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_Locname`  
 Uma localidade nomeada.  
  
 `_Refs`  
 Uma contagem de referência inicial.  
  
## <a name="requirements"></a>Requisitos  
 Seu comportamento é determinado pela localidade nomeada `_Locname`. Cada construtor inicializa seu objeto base com [time_get](../standard-library/time-get-class.md#time_get)\<CharType, InputIterator>( `_Refs`).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



