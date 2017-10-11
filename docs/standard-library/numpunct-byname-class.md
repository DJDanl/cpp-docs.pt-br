---
title: Classe numpunct_byname | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xlocnum/std::numpunct_byname
dev_langs:
- C++
helpviewer_keywords:
- numpunct_byname class
ms.assetid: 18412924-e085-4771-b5e9-7a200cbdd7c0
caps.latest.revision: 24
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: fb424b3c9ec367ef8349a944bb86528fda806a5d
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="numpunctbyname-class"></a>Classe numpunct_byname
A classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta `numpunct` de uma determinada localidade, permitindo a formatação e pontuação de expressões numéricas e boolianas.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class CharType>
class numpunct_byname : public numpunct<Elem> {
public:
    explicit numpunct_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit numpunct_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~numpunct_byname();

 };
```  
  
## <a name="remarks"></a>Comentários  
 Seu comportamento é determinado pela localidade [nomeada](../standard-library/locale-class.md#name) `_Locname`. O construtor inicializa seu objeto base com [numpunct](../standard-library/numpunct-class.md#numpunct)\<CharType>( `_Refs`).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




