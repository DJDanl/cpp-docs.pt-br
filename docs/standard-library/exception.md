---
title: "&lt;exception&gt; | Microsoft Docs"
ms.custom: ""
ms.date: "12/09/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "<exception>"
  - "std::<exception>"
  - "std.<exception>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho exception"
ms.assetid: 28900768-5dd7-4834-b907-5e37ab3407db
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;exception&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Define vários tipos e funções relacionados ao tratamento de exceções. O tratamento de exceções é usado em situações nas quais o sistema pode se recuperar de um erro. Ele fornece um meio de o controle ser retornado de uma função para o programa. O objetivo de incorporar o tratamento de exceções é aumentar a robustez do programa e, ao mesmo tempo, fornecer um meio de se recuperar de um erro de maneira organizada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <exception>  
  
```  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[exception_ptr](../Topic/%3Cexception%3E%20typedefs.md#exception_ptr)|Um tipo que descreve um ponteiro para uma exceção.|  
|[terminate_handler](../Topic/%3Cexception%3E%20typedefs.md#terminate_handler)|Um tipo que descreve um ponteiro para uma função adequada para uso como um `terminate_handler`.|  
|[unexpected_handler](../Topic/%3Cexception%3E%20typedefs.md#unexpected_handler)|Um tipo que descreve um ponteiro para uma função adequada para uso como um `unexpected_handler`.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[current_exception](../Topic/%3Cexception%3E%20functions.md#current_exception)|Obtém um ponteiro para a exceção atual.|  
|[get_terminate](../Topic/%3Cexception%3E%20functions.md#get_terminate)|Obtém a função `terminate_handler` atual.|  
|[get_unexpected](../Topic/%3Cexception%3E%20functions.md#get_unexpected)|Obtém a função `unexpected_handler` atual.|  
|[make_exception_ptr](../Topic/%3Cexception%3E%20functions.md#make_exception_ptr)|Cria um objeto `exception_ptr` que mantém uma cópia de uma exceção.|  
|[rethrow_exception](../Topic/%3Cexception%3E%20functions.md#rethrow_exception)|Lança uma exceção passada como um parâmetro.|  
|[set_terminate](../Topic/%3Cexception%3E%20functions.md#set_terminate)|Estabelece um novo `terminate_handler` a ser chamado na finalização do programa.|  
|[set_unexpected](../Topic/%3Cexception%3E%20functions.md#set_unexpected)|Estabelece um novo `unexpected_handler` a ser chamado quando uma exceção inesperada é encontrada.|  
|[encerrar](../Topic/%3Cexception%3E%20functions.md#terminate)|Chama um manipulador de finalização.|  
|[uncaught_exception](../Topic/%3Cexception%3E%20functions.md#uncaught_exception)|Retorna **true** somente se uma exceção lançada está sendo processada no momento.|  
|[inesperado](../Topic/%3Cexception%3E%20functions.md#unexpected)|Chama um manipulador inesperado.|  
  
### <a name="classes"></a>Classes  
  
|||  
|-|-|  
|[Classe bad_exception](../standard-library/bad-exception-class.md)|A classe descreve uma exceção que pode ser lançada de um `unexpected_handler`.|  
|[Classe Exception](Exception%20Class.xml)|A classe atua como a classe base de todas as exceções lançadas por determinadas expressões e pela Biblioteca Padrão do C++.|  
  
## <a name="see-also"></a>Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)   
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

