---
title: "Classe logic_error | Microsoft Docs"
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
  - "stdexcept/std::logic_error"
  - "std::logic_error"
  - "logic_error"
  - "std.logic_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe logic_error"
ms.assetid: b290d73d-94e1-4288-af86-2bb5d71f677a
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe logic_error
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe serve como a classe base para todas as exceções geradas para relatar erros supostamente detectáveis antes de executa o programa, como violações de pré-condições lógicas.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class logic_error : public exception {  
public:  
    explicit logic_error(const string& message);

    explicit logic_error(const char *message);

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por [que](../standard-library/exception-class1.md) é uma cópia do **mensagem**`.`[dados](../standard-library/basic-string-class.md#basic_string__data).  
  
## <a name="example"></a>Exemplo  
  
```  
// logic_error.cpp  
// compile with: /EHsc /GR  
#include <iostream>  
using namespace std;  
  
int main( )  
{  
   try   
   {  
      throw logic_error( "logic error" );  
   }  
   catch ( exception &e )   
   {  
      cerr << "Caught: " << e.what( ) << endl;  
      cerr << "Type: " << typeid( e ).name( ) << endl;  
   };  
}  
```  
  
 **Saída**  
  
```  
Caught: logic error  
Type: class std::logic_error  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< stdexcept>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[Classe Exception](../standard-library/exception-class1.md)  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

