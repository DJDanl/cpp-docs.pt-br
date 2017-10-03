---
title: Classe runtime_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdexcept/std::runtime_error
dev_langs:
- C++
helpviewer_keywords:
- runtime_error class
ms.assetid: 4d0227bf-847b-45a2-a320-2351ebf98368
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: fffdedc184df2de8956341015345bf2f6fb16e80
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="runtimeerror-class"></a>Classe runtime_error
A classe serve como classe base para todas as exceções geradas para relatar erros supostamente detectáveis somente durante a execução do programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class runtime_error : public exception {  
public:  
    explicit runtime_error(const string& message);

    explicit runtime_error(const char *message);

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado pela [Classe exception](../standard-library/exception-class.md) é uma cópia de **message**`.`[data](../standard-library/basic-string-class.md#data).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// runtime_error.cpp  
// compile with: /EHsc /GR  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
// runtime_error  
   try   
   {  
      locale loc( "test" );  
   }  
   catch ( exception &e )   
   {  
      cerr << "Caught " << e.what( ) << endl;  
      cerr << "Type " << typeid( e ).name( ) << endl;  
   };  
}  
\* Output:   
Caught bad locale name  
Type class std::runtime_error  
*\  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<stdexcept>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[Classe exception](../standard-library/exception-class.md)

    
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


