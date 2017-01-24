---
title: "idl_module | Microsoft Docs"
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
  - "vc-attr.idl_module"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "idl_module attribute"
ms.assetid: 3578b337-e38a-4334-b747-15404c02dbc0
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# idl_module
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um ponto de entrada em um arquivo. dll.  
  
## Sintaxe  
  
```  
  
      [ idl_module (   
   name=module_name,   
   dllname=dll,   
   uuid="uuid",   
   helpstring="help text",   
   helpstringcontext=helpcontextID,   
   helpcontext=helpcontext,   
   hidden,   
   restricted  
) ]  
function declaration  
```  
  
#### Parâmetros  
 **name**  
 Um nome definido pelo usuário para o bloco de código que será exibido no arquivo. idl.  
  
 **dllname** \(opcional\)  
 O arquivo. dll que contém a exportação.  
  
 `uuid`\(opcional\)  
 Uma ID exclusiva.  
  
 **HelpString** \(opcional\)  
 Uma seqüência de caracteres usada para descrever a biblioteca de tipos.  
  
 **helpstringcontext** \(opcional\)  
 A identificação de um tópico da Ajuda em um arquivo. hlp ou. chm.  
  
 **HelpContext** \(opcional\)  
 A identificação ajuda para esta biblioteca de tipos.  
  
 **oculto** \(opcional\)  
 Um parâmetro que impede que a biblioteca seja exibido.  Consulte o  [oculto](http://msdn.microsoft.com/library/windows/desktop/aa366861) atributo MIDL para obter mais informações.  
  
 ***restrito***  \(opcional\)  
 Os membros da biblioteca não podem ser chamados arbitrariamente.  Consulte o  [restritos](http://msdn.microsoft.com/library/windows/desktop/aa367157) atributo MIDL para obter mais informações.  
  
 *declaração de função*  
 A função que você irá definir.  
  
## Comentários  
 O `idl_module` atributo C\+\+ permite que você especifique o ponto de entrada em um arquivo. dll, que permite que você importar um arquivo. dll.  
  
 O  **idl\_module**  atributo tem funcionalidade semelhante do  [módulo](http://msdn.microsoft.com/library/windows/desktop/aa367099) atributo MIDL.  
  
 Você pode exportar qualquer coisa a partir de um objeto COM que você pode exportar a partir de um arquivo. dll, colocando um ponto de entrada DLL no bloco de biblioteca de um arquivo. idl.  
  
 O deve usar `idl_module` em duas etapas.  Primeiro, você deve definir um par nome\/DLL.  Em seguida, quando você usa `idl_module` para especificar um ponto de entrada, especifique o nome e os atributos adicionais.  
  
## Exemplo  
 O código a seguir mostra como usar o `idl_module` atributo:  
  
```  
// cpp_attr_ref_idl_module.cpp  
// compile with: /LD  
[idl_quote("midl_pragma warning(disable:2461)")];  
[module(name="MyLibrary"), idl_module(name="MyLib", dllname="xxx.dll")];  
[idl_module(name="MyLib"), entry(4), usesgetlasterror]  
void FuncName(int i);  
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
 [entry](../windows/entry.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)