---
title: "Classe bad_exception | Microsoft Docs"
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
  - "std.bad_exception"
  - "bad_exception"
  - "std::bad_exception"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe bad_exception"
ms.assetid: 5ae2c4ef-c7ad-4469-8a9e-a773e86bb000
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe bad_exception
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe descreve uma exceção pode ser lançada a partir de um manipulador inesperado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class bad_exception    : public exception {};  
```  
  
## <a name="remarks"></a>Comentários  
 [inesperado](../Topic/%3Cexception%3E%20functions.md#unexpected) lançará um `bad_exception` em vez de encerrar ou em vez de chamar outra função especificada com [set_unexpected](../Topic/%3Cexception%3E%20functions.md#set_unexpected) se `bad_exception` está incluído na lista de lançamento de uma função.  
  
 O valor retornado por **que** é uma cadeia de caracteres C definido pela implementação. Nenhuma das funções de membro lançar exceções.  
  
 Para obter uma lista de membros herdados pelo `bad_exception` de classe, consulte [classe exception](../standard-library/exception-class1.md).  
  
## <a name="example"></a>Exemplo  
 Consulte [set_unexpected](../Topic/%3Cexception%3E%20functions.md#set_unexpected) para obter um exemplo do uso de [inesperado](../Topic/%3Cexception%3E%20functions.md#unexpected) Lançando um `bad_exception`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< exceção>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
[Classe Exception](../standard-library/exception-class1.md)
 [segurança de segmento na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

