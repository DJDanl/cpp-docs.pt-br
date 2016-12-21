---
title: "Classe messages | Microsoft Docs"
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
  - "messages"
  - "xlocmes/std::messages"
  - "std.messages"
  - "std::messages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe messages"
ms.assetid: c4c71f40-4f24-48ab-9f7c-daccd8d5bd83
caps.latest.revision: 18
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe messages
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para recuperar mensagens localizadas em um catálogo de mensagens internacionalizadas de uma determinada localidade.  
  
 No momento, enquanto a classe de mensagens é implementada, não há nenhuma mensagem.  
  
## Sintaxe  
  
```  
template <class CharType>  
   class messages : public messages_base;  
```  
  
#### Parâmetros  
 `CharType`  
 O tipo usado em um programa para codificar caracteres em uma localidade.  
  
## Comentários  
 Assim como acontece com qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo em **ID**  
  
 Esta faceta basicamente abre um catálogo de mensagens definido na classe base messages\_base, recupera as informações necessárias e fecha o catálogo.  
  
### Construtores  
  
|||  
|-|-|  
|[messages](../Topic/messages::messages.md)|A função de construtor de faceta de mensagem.|  
  
### Typedefs  
  
|||  
|-|-|  
|[char\_type](../Topic/messages::char_type.md)|Um tipo de caractere que é usado exibir mensagens.|  
|[STRING\_TYPE](../Topic/messages::string_type.md)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[close](../Topic/messages::close.md)|Fecha o catálogo de mensagens.|  
|[do\_close](../Topic/messages::do_close.md)|Uma função virtual chamada para perder o catálogo de mensagens.|  
|[do\_get](../Topic/messages::do_get.md)|Uma função virtual chamada para recuperar o catálogo de mensagens.|  
|[do\_open](../Topic/messages::do_open.md)|Uma função virtual chamada para abrir o catálogo de mensagens.|  
|[get](../Topic/messages::get.md)|Recupera o catálogo de mensagens.|  
|[open](../Topic/messages::open.md)|Abre o catálogo de mensagens.|  
  
## Requisitos  
 **Cabeçalho:** \< local \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<locale\>](../standard-library/locale.md)   
 [Classe messages\_base](../Topic/messages_base%20Class.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)