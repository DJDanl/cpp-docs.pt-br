---
title: Classe codecvt_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- codecvt_base
- xlocale/std::codecvt_base
dev_langs:
- C++
helpviewer_keywords:
- codecvt_base class
ms.assetid: 7e95c083-91b4-4b3f-8918-0d4ea244a040
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9d50fcc70039320b3a0ac99df279cdd79e336fa2
ms.lasthandoff: 02/25/2017

---
# <a name="codecvtbase-class"></a>Classe codecvt_base
Uma classe base da classe codecvt usada para definir um tipo de enumeração referenciado como **result**, usado como o tipo de retorno para as funções membro de faceta para indicar o resultado de uma conversão.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class codecvt_base : public locale::facet {
public:
    enum result {ok, partial, error, noconv};
    codecvt_base( size_t _Refs = 0);
    bool always_noconv() const;
    int max_length() const;
    int encoding() const;
    ~codecvt_base()

protected:
    virtual bool do_always_noconv() const;
    virtual int do_max_length() const;
    virtual int do_encoding() const;
};
```  
  
## <a name="remarks"></a>Comentários  
 A classe descreve uma enumeração comum a todas as especializações da classe de modelo [codecvt](../standard-library/codecvt-class.md). O resultado da enumeração descreve os possíveis valores de retornos de [do_in](../standard-library/codecvt-class.md#codecvt__do_in) ou [do_out](../standard-library/codecvt-class.md#codecvt__do_out):  
  
- **ok** se a conversão entre codificações de caracteres internos e externos for bem-sucedida.  
  
- **partial** se a fonte for insuficiente ou se o destino não for grande o suficiente para que a conversão seja bem-sucedida.  
  
- **error** se a sequência de origem estiver mal formada.  
  
- **noconv** se a função não realizar nenhuma conversão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)




