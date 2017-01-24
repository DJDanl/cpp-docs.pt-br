---
title: "Classe system_error | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "system_error/std::system_error"
  - "std.system_error"
  - "std::system_error"
  - "system_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe system_error"
ms.assetid: 2eeaacbb-8a4a-4ad7-943a-997901a77f32
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe system_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa a classe base para todas as exceções geradas para relatar um erro de sistema de nível inferior.  
  
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
 O valor retornado por `what` na classe [exceção](../standard-library/exception-class1.md) é construído com `_Message` e o objeto armazenado do tipo [error_code](../standard-library/error-code-class.md) (tanto `code` ou `error_code(_Errval, _Errcat)`).  
  
 A função de membro `code` retorna armazenado [error_code](../standard-library/error-code-class.md) objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< system_error >  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\< system_error >](../standard-library/system-error.md)

