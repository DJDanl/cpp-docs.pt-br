---
title: "export | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.export"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "export attribute"
ms.assetid: 70b3e848-fad6-4e09-8c72-be60ca72a4df
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# export
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Faz com que uma estrutura de dados sejam colocados no arquivo. idl.  
  
## Sintaxe  
  
```  
  
[export]  
  
```  
  
## Comentários  
 O  **Exportar** o atributo de C\+\+ faz com que uma estrutura de dados sejam colocados no arquivo. idl e estejam disponíveis na biblioteca de tipos em um formato compatível com o binário que o torna disponível para uso com qualquer linguagem.  
  
 Não é possível aplicar o  **Exportar** atributo para uma classe, mesmo que a classe tem somente os membros públicos \(o equivalente a uma `struct`\).  
  
 Se você exportar sem nome `enum`s ou `struct`s, eles receberão nomes que começam com  **\_\_unnamed***x*, onde  *x* é um número seqüencial.  
  
 As definições de tipo válidas para exportação são tipos base, estruturas, uniões, enums ou digite identificadores.  Consulte  [typedef](http://msdn.microsoft.com/library/windows/desktop/aa367287) para obter mais informações.  
  
## Exemplo  
 O código a seguir mostra como usar o  **Exportar** atributo:  
  
```  
// cpp_attr_ref_export.cpp  
// compile with: /LD  
[module(name="MyLibrary")];  
  
[export]  
struct MyStruct {  
   int i;  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**union**, `typedef`, `enum`, `struct`, or`interface`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)