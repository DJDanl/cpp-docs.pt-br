---
title: Classe ctype_byname | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xlocale/std::ctype_byname
- std::ctype_byname
- ctype_byname
- std.ctype_byname
dev_langs:
- C++
helpviewer_keywords:
- ctype_byname class
ms.assetid: a5cec021-a1f8-425f-8757-08e6f064b604
caps.latest.revision: 22
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 591ad03b2c5a2d2cd085c13f2f5ca8a6918974ba
ms.lasthandoff: 02/25/2017

---
# <a name="ctypebyname-class"></a>Classe ctype_byname
A classe de modelo derivada descreve um objeto que pode servir como uma faceta ctype de determinada localidade, permitindo a classificação e conversão de caracteres entre maiúsculas e minúsculas, assim como entre conjuntos de caracteres especificados de localidade e nativos.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class _Elem>
class ctype_byname : public ctype<_Elem>
{
public:
    explicit ctype_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit ctype_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual __CLR_OR_THIS_CALL ~ctype_byname();

};
```  
  
## <a name="remarks"></a>Comentários  
 Seu comportamento é determinado pela localidade nomeada `_Locname`. Cada construtor inicializa seu objeto base com [ctype](../standard-library/ctype-class.md)\<CharType>( `_Refs`) ou o equivalente da classe base `ctype<char>`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




