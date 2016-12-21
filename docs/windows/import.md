---
title: "import | Microsoft Docs"
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
  - "vc-attr.import"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "import attribute"
ms.assetid: ebf07cae-39fb-4047-8b57-54af0a9a83de
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# import
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica outro arquivo. idl, odl ou cabeçalho que contém definições que você deseja fazer referência a partir de seu principal IDL.  
  
## Sintaxe  
  
```  
  
      [ import(  
   idl_file  
) ];  
```  
  
#### Parâmetros  
 `idl_file`  
 O nome de um arquivo. idl ser importada para a biblioteca de tipos do projeto atual.  
  
## Comentários  
 O  **Importar** C\+\+ atributo faz com que uma `#import` instrução deve ser colocada abaixo de `import "docobj.idl"` declaração no arquivo. idl gerado.  O  **Importar** atributo tem a mesma funcionalidade que o  [Importar](http://msdn.microsoft.com/library/windows/desktop/aa367047) atributo MIDL.  
  
 O  **Importar** atributo apenas insere o arquivo especificado no arquivo. idl que será gerado pelo projeto. o  **Importar** atributo não podem ser chamados de construções no arquivo especificado de código\-fonte em seu projeto.  Para chamar as construções no arquivo especificado de código\-fonte em seu projeto, use  [\# Import](../Topic/%23import%20Directive%20\(C++\).md) e o `embedded_idl` atributo ou você pode incluir o arquivo. h para o `idl_file`, se existe um arquivo. h.  
  
## Exemplo  
 O código a seguir:  
  
```  
// cpp_attr_ref_import.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[import(import.idl)];  
```  
  
 produz o seguinte código no arquivo. idl gerado:  
  
```  
import "docobj.idl";  
import "import.idl";  
  
[ uuid(EED3644C-8488-3ECD-BA97-147DB3CDB499), version(1.0) ]  
library MyLib {  
   importlib("stdole2.tlb");  
   importlib("olepro32.dll");  
...  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Em qualquer lugar|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [importidl](../windows/importidl.md)   
 [importlib](../windows/importlib.md)   
 [include](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)