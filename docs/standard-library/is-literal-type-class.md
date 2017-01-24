---
title: "Classe is_literal_type | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "is_literal_type"
  - "std.is_literal_type"
  - "std::is_literal_type"
  - "type_traits/std::is_literal_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_literal_type"
ms.assetid: a03a4ebb-ee66-48d6-91bb-41cf72b2401f
caps.latest.revision: 12
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_literal_type
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo pode ser usado como um `constexpr` variável ou ser construído, usado pelo ou retornado de `constexpr` funções.  
  
## Sintaxe  
  
```  
template <class T>  
    struct is_literal_type;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é um *tipo literal*, caso contrário, manterá false. Um tipo de literal é `void`, um tipo escalar, um tipo de referência, uma matriz de tipo literal ou um tipo de classe literal. Um tipo de classe literal é um tipo de classe que tem um destruidor trivial, é um tipo de agregação ou tem pelo menos um não\-mover, copiar não `constexpr` construtor e todas as suas classes base e membros de dados não estáticos são tipos de literal não\-volátil. Embora o tipo de um literal é sempre um tipo literal, o conceito de um tipo literal inclui tudo o que o compilador pode avaliar como uma `constexpr` em tempo de compilação.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)