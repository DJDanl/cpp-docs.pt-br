---
title: "Classe underflow_error | Microsoft Docs"
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
  - "stdexcept/std::underflow_error"
  - "underflow_error"
  - "std.underflow_error"
  - "std::underflow_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe underflow_error"
ms.assetid: d632f1f9-9c6c-4954-b96b-03041bfab22d
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe underflow_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe serve como a classe base para todas as exceções geradas para relatar um estouro aritmético.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class underflow_error : public runtime_error {  
public:  
    explicit underflow_error(const string& message);

    explicit underflow_error(const char *message);

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por [que](../standard-library/exception-class1.md) é uma cópia do **mensagem**`.`[dados](../standard-library/basic-string-class.md#basic_string__data).  
  
## <a name="example"></a>Exemplo  
  
```  
// underflow_error.cpp  
// compile with: /EHsc /GR  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
   try   
   {  
      throw underflow_error( "The number's a bit small, captain!" );  
   }  
   catch ( exception &e ) {  
      cerr << "Caught: " << e.what( ) << endl;  
      cerr << "Type: " << typeid( e ).name( ) << endl;  
   };  
}  
\* Output:   
Caught: The number's a bit small, captain!  
Type: class std::underflow_error  
*\  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< stdexcept>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [\< stdexcept> membros](http://msdn.microsoft.com/pt-br/7b6b0a73-916e-44aa-9a3f-f5b6b3ce98e6)   
 [Classe runtime_error](../Topic/runtime_error%20Class.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

