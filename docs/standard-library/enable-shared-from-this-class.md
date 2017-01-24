---
title: "Classe enable_shared_from_this | Microsoft Docs"
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
  - "tr1.enable_shared_from_this"
  - "enable_shared_from_this"
  - "std.tr1.enable_shared_from_this"
  - "memory/std::tr1::enable_shared_from_this"
  - "std::tr1::enable_shared_from_this"
  - "tr1::enable_shared_from_this"
  - "std.enable_shared_from_this"
  - "memory/std::enable_shared_from_this"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe enable_shared_from_this"
  - "Classe enable_shared_from_this [TR1]"
ms.assetid: 9237603d-22e2-421f-b070-838ac006baf5
caps.latest.revision: 22
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe enable_shared_from_this
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Ajuda a gerar um `shared_ptr`.  
  
## Sintaxe  
  
```  
template<class Ty>  
    class enable_shared_from_this {  
public:  
    shared_ptr<Ty> shared_from_this();  
    shared_ptr<const Ty> shared_from_this() const;  
  
protected:  
    enable_shared_from_this();  
    enable_shared_from_this(const enable_shared_from_this&);  
    enable_shared_from_this& operator=(const enable_shared_from_this&);  
    ~enable_shared_from_this();  
    };  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo controlado pelo ponteiro compartilhado.  
  
## Comentários  
 Objetos derivados de `enable_shared_from_this` pode usar o `shared_from_this` métodos nas funções de membro para criar [shared\_ptr](../standard-library/shared-ptr-class.md) proprietários da instância que compartilham a propriedade com existentes `shared_ptr` proprietários. Caso contrário, se você criar um novo `shared_ptr` usando `this`, ele é diferente do existente `shared_ptr` proprietários, o que podem levar a referências de inválido ou fazer com que o objeto a ser excluído mais de uma vez.  
  
 Os construtores, o destruidor e o operador de atribuição são protegidos para evitar o uso indevido acidental. O tipo de argumento de modelo `Ty` deve ser do tipo da classe derivada.  
  
 Para obter um exemplo de uso, consulte [enable\_shared\_from\_this::shared\_from\_this](../Topic/enable_shared_from_this::shared_from_this.md).  
  
## Requisitos  
 **Cabeçalho:** \< memória \>  
  
 **Namespace:** std  
  
## Consulte também  
 [enable\_shared\_from\_this::shared\_from\_this](../Topic/enable_shared_from_this::shared_from_this.md)   
 [Classe shared\_ptr](../standard-library/shared-ptr-class.md)