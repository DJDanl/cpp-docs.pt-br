---
title: "Classe basic_iostream | Microsoft Docs"
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
  - "istream/std::basic_iostream"
  - "std.basic_iostream"
  - "basic_iostream"
  - "std::basic_iostream"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe basic_iostream"
ms.assetid: 294b680b-eb49-4066-8db2-6d52dac9d6e3
caps.latest.revision: 22
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe basic_iostream
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe de fluxo que pode fazer ambos de entrada e saída.  
  
## Sintaxe  
  
```  
template <class Elem, class Tr = char_traits<Elem> >  
    class basic_iostream : public basic_istream<Elem, Tr>,  
        public basic_ostream<Elem, Tr>  
{  
public:  
    explicit basic_iostream(basic_streambuf<Elem, Tr> *_Strbuf);  
    virtual ~basic_iostream();  
};  
```  
  
## Comentários  
 A classe de modelo descreve um objeto que controla as inserções, por meio de sua classe base[basic\_ostream](../Topic/basic_ostream%20Class.md)\<`Elem``Tr`\>, extrações, por meio de sua classe base e[basic\_istream](../Topic/basic_istream%20Class.md)\<`Elem``Tr`\>.  Os dois objetos compartilham uma classe base virtual comum[basic\_ios](../Topic/basic_ios%20Class.md)\<`Elem``Tr`\>.  Eles também gerenciam um buffer de fluxo comuns, com elementos do tipo`Elem`cujas características de caractere são determinadas pela classe`Tr`.  O construtor inicializa suas classes base por meio de`basic_istream`\(**strbuf**\) e`basic_ostream`\(**strbuf**\).  
  
### Construtores  
  
|||  
|-|-|  
|[basic\_iostream](../Topic/basic_iostream::basic_iostream.md)|Crie um objeto `basic_iostream`.|  
  
### Funções membro  
  
|||  
|-|-|  
|[swap](../Topic/basic_iostream::swap.md)|Troca o conteúdo fornecido`basic_iostream`objeto para o conteúdo deste objeto.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=](../Topic/basic_iostream::operator=.md)|Atribui o valor de uma`basic_iostream`objeto para este objeto.  Isso é uma atribuição de movimentação que envolvem um`rvalue`que não deixar uma cópia.|  
  
## Requisitos  
 **Cabeçalho:**\< istream \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação iostream](../Topic/iostream%20Programming.md)   
 [Convenções iostreams](../standard-library/iostreams-conventions.md)