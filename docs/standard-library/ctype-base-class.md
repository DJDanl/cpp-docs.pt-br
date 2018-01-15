---
title: Classe ctype_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: locale/std::ctype_base
dev_langs: C++
helpviewer_keywords: ctype_base class
ms.assetid: ccffe891-d7ab-4d22-baf8-8eb6d438a96d
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 83f467f8d06956678795bf97fed60fe9f22c32f1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ctypebase-class"></a>Classe ctype_base
A classe serve como uma classe base para facetas da classe de modelo [ctype](../standard-library/ctype-class.md). Uma classe base da classe ctype que é usada para definir tipos de enumeração usados para classificar ou testar caracteres individualmente ou dentro de intervalos inteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```
struct ctype_base : public locale::facet
{
    enum
 {
    alnum,
 alpha,
    cntrl,
 digit,
    graph,
 lower,
    print,
 punct,
    space,
 upper,
    xdigit
 };
    typedef short mask;
    ctype_base(
 size_t _Refs = 0);

 ~ctype_base();

};
```  
  
## <a name="remarks"></a>Comentários  
 Define uma máscara de enumeração. Cada constante de enumeração caracteriza uma maneira diferente de classificar caracteres, conforme definido pelas funções com nomes semelhantes declaradas no cabeçalho \<ctype.h>. As constantes são:  
  
- **space** (função [isspace](../standard-library/locale-functions.md#isspace))  
  
- **print** (função [isprint](../standard-library/locale-functions.md#isprint))  
  
- **cntrl** (função [iscntrl](../standard-library/locale-functions.md#iscntrl))  
  
- **upper** (função [isupper](../standard-library/locale-functions.md#isupper))  
  
- **lower** (função [islower](../standard-library/locale-functions.md#islower))  
  
- **digit** (função [isdigit](../standard-library/locale-functions.md#isdigit))  
  
- **punct** (função [ispunct](../standard-library/locale-functions.md#ispunct))  
  
- **xdigit** (função [isxdigit](../standard-library/locale-functions.md#isxdigit))  
  
- **alpha** (função [isalpha](../standard-library/locale-functions.md#isalpha))  
  
- **alnum** (função [isalnum](../standard-library/locale-functions.md#isalnum))  
  
- **graph** (função [isgraph](../standard-library/locale-functions.md#isgraph))  
  
 É possível caracterizar uma combinação de classificações pelo uso de OR nessas constantes. Em particular, é sempre true que **alnum** = = ( **alpha** &#124; **dígitos** \) e **gráfico** \= \= \( **alnum** &#124; **pontuação**).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



