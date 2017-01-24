---
title: "Classe is_trivially_copyable | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "is_trivially_copyable"
  - "std.is_trivially_copyable"
  - "std::is_trivially_copyable"
  - "type_traits/std::is_trivially_copyable"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_trivially_copyable"
ms.assetid: 89a53bf8-036c-4108-91e1-fe34adbde8b3
caps.latest.revision: 12
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_copyable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo for um tipo facilmente copiado.  
  
## Sintaxe  
  
```  
template<class T>  
    struct is_trivially_copyable;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é um tipo facilmente copiado, de outra forma, manterá false. Tipos facilmente copiados não tem nenhum destruidores, operações de movimentação ou operações de cópia não triviais. Geralmente, uma operação de cópia é considerada trivial se ele pode ser implementado como uma cópia bit a bit. Tipos internos e matrizes de tipos facilmente copiados são facilmente copiados.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)