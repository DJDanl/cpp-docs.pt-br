---
title: Classe overflow_error | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: stdexcept/std::overflow_error
dev_langs: C++
helpviewer_keywords: overflow_error class
ms.assetid: bae7128d-e36b-4a45-84f1-2f89da441d20
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ee50fe7189d8a6507ff1e148b4cead5e2f97db67
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="overflowerror-class"></a>Classe overflow_error
A classe serve como a classe base para todas as exceções geradas para relatar um estouro aritmético.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class overflow_error : public runtime_error {  
public:  
    explicit overflow_error(const string& message);

    explicit overflow_error(const char *message);

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por [what](../standard-library/exception-class.md) é uma cópia de **message**`.`[data](../standard-library/basic-string-class.md#data).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// overflow_error.cpp  
// compile with: /EHsc /GR  
#include <bitset>  
#include <iostream>  
  
using namespace std;  
  
int main( )  
{  
   try   
   {  
      bitset< 33 > bitset;  
      bitset[32] = 1;  
      bitset[0] = 1;  
      unsigned long x = bitset.to_ulong( );  
   }  
   catch ( exception &e )   
   {  
      cerr << "Caught " << e.what( ) << endl;  
      cerr << "Type " << typeid( e ).name( ) << endl;  
   };  
}  
\* Output:   
Caught bitset<N> overflow  
Type class std::overflow_error  
*\  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<stdexcept>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Classe runtime_error](../standard-library/runtime-error-class.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

