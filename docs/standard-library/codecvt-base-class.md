---
title: "Classe codecvt_base | Microsoft Docs"
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
  - "codecvt_base"
  - "xlocale/std::codecvt_base"
  - "std.codecvt_base"
  - "std::codecvt_base"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe codecvt_base"
ms.assetid: 7e95c083-91b4-4b3f-8918-0d4ea244a040
caps.latest.revision: 21
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe codecvt_base
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma classe base da classe de codecvt que é usada para definir um tipo de enumeração referenciado como **result**, usado como o tipo de retorno para funções de membro da faceta indica o resultado de uma conversão.  
  
## Sintaxe  
  
```  
class codecvt_base : public locale::facet {  
public:  
    enum result {ok, partial, error, noconv};  
    codecvt_base(  
        size_t _Refs = 0  
);  
    bool always_noconv() const;  
    int max_length() const;  
    int encoding() const;  
    ~codecvt_base()  
protected:  
    virtual bool do_always_noconv() const;  
    virtual int do_max_length() const;  
    virtual int do_encoding() const;  
};  
```  
  
## Comentários  
 A classe descreve um conjunto comum da enumeração para todas as especializações da classe [codecvt](../standard-library/codecvt-class.md)do modelo.  O resultado da enumeração descreve os valores de retorno possíveis de [do\_in](../Topic/codecvt::do_in.md) ou de [do\_out](../Topic/codecvt::do_out.md):  
  
-   **ok** se a conversão entre codificações de caracteres internas e externos tem êxito.  
  
-   **partial** se o destino não seja grande o suficiente para que a conversão tenha êxito.  
  
-   **error** se a sequência de origem é errado formado.  
  
-   **noconv** se a função não executa nenhuma conversão.  
  
## Requisitos  
 Localidade \<de**Header:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)