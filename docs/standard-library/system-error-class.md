---
title: Classe system_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- system_error/std::system_error
dev_langs:
- C++
helpviewer_keywords:
- system_error class
ms.assetid: 2eeaacbb-8a4a-4ad7-943a-997901a77f32
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dfa7927cf8039397f62b7510cdc4a0c84af66cf0
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="systemerror-class"></a>Classe system_error
Representa a classe base para todas as exceções geradas para relatar um erro de nível inferior do sistema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class system_error : public runtime_error {  
public:  
    explicit system_error(error_code _Errcode,
    const string& _Message = "");

    system_error(error_code _Errcode,
    const char *_Message);

    system_error(error_code::value_type _Errval,  
    const error_category& _Errcat,
    const string& _Message);

    system_error(error_code::value_type _Errval,  
    const error_category& _Errcat,
    const char *_Message);
const error_code& code() const throw();
const error_code& code() const throw();

 };  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por `what` na classe [exception](../standard-library/exception-class.md) é construído com base em `_Message` e no objeto armazenado do tipo [error_code](../standard-library/error-code-class.md) (`code` ou `error_code(_Errval, _Errcat)`).  
  
 A função membro `code` retorna o objeto [error_code](../standard-library/error-code-class.md) armazenado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<system_error>](../standard-library/system-error.md)

