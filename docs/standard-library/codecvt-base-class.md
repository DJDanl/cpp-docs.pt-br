---
title: Classe codecvt_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- xlocale/std::codecvt_base
dev_langs:
- C++
helpviewer_keywords:
- codecvt_base class
ms.assetid: 7e95c083-91b4-4b3f-8918-0d4ea244a040
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2b3d1ae1c2bae5c4ce0ab4c7cb6ecadec194f5f9
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
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
 A classe descreve uma enumeração comum a todas as especializações da classe de modelo [codecvt](../standard-library/codecvt-class.md). O resultado da enumeração descreve os possíveis valores de retornos de [do_in](../standard-library/codecvt-class.md#do_in) ou [do_out](../standard-library/codecvt-class.md#do_out):  
  
- **ok** se a conversão entre codificações de caracteres internos e externos for bem-sucedida.  
  
- **partial** se a fonte for insuficiente ou se o destino não for grande o suficiente para que a conversão seja bem-sucedida.  
  
- **error** se a sequência de origem estiver mal formada.  
  
- **noconv** se a função não realizar nenhuma conversão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)



