---
title: "Classe exception | Microsoft Docs"
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
  - "std.exception"
  - "exception"
  - "std::exception"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe exception"
ms.assetid: 4f181f67-5888-4b50-89a6-745091ffb2fe
caps.latest.revision: 19
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe exception
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe serve como a classe base para todas as exceções lançadas por algumas expressões e a biblioteca padrão C\+\+.  
  
## Sintaxe  
  
```  
class exception {  
public:  
    exception();  
    exception(const char * const &message);  
    exception(const char * const &message, int);  
    exception(const exception &right);  
    exception& operator=(const exception &right);  
    virtual ~exception();  
    virtual const char *what() const;  
};  
```  
  
## Comentários  
 Especificamente, essa classe base é a raiz das classes padrão de exceção definidas em [\<stdexcept\>](../standard-library/stdexcept.md).  O valor da cadeia de caracteres C retornado por `what` é deixado não especificado pelo padrão, mas pode ser definida por classes derivadas dos construtores para determinadas como uma cadeia de caracteres de implementação definida C.  Nenhuma das funções de membro lançam todas as exceções.  
  
 O parâmetro de `int` permite que você especifica que nenhuma memória deve ser atribuída.  O valor de `int` é ignorado.  
  
> [!NOTE]
>  Os construtores `exception(const char * const &message)` e `exception(const char * const &message, int)` são extensões da Microsoft para a biblioteca padrão C\+\+.  
  
## Exemplo  
 Para obter exemplos de uso de classes padrão de exceção que herdam da classe de `exception` , consulte qualquer uma das classes definidas em [\<stdexcept\>](../standard-library/stdexcept.md).  
  
## Requisitos  
 exceção \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)