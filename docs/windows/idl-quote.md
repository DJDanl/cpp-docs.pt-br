---
title: "idl_quote | Microsoft Docs"
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
  - "vc-attr.idl_quote"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "idl_quote attribute"
ms.assetid: a370e1b7-948b-4e67-9a25-58facf24e4c9
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# idl_quote
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite que você use construções IDL que não são suportadas na versão atual do Visual C\+\+ e faça com que eles passam para o arquivo. idl gerado.  
  
## Sintaxe  
  
```  
  
      [ idl_quote(  
   text  
) ]  
```  
  
#### Parâmetros  
 *texto*  
 O nome do atributo que você pretende que o compilador do Visual C\+\+ passem para o arquivo. idl gerado sem retornar um erro do compilador.  
  
## Comentários  
 Se a  **idl\_quote** atributo de C\+\+ é usado como um atributo autônomo \(com um ponto e vírgula após o colchete de fechamento\), em seguida,  *texto*  é colocado no arquivo. idl mesclado como está.  Se  **idl\_quote** é usado em um símbolo,  *texto*  é colocado dentro do bloco de atributo desse símbolo.  
  
## Exemplo  
 O código a seguir mostra como você poderia especificar um atributo sem suporte \(usando  **na**, que é suportado\) e como definir e usar uma construção. idl indefinido:  
  
```  
// cpp_attr_ref_idl_quote.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLibrary")];  
  
[export]  
struct MYFLOT {  
   int i;  
};  
  
[export]  
struct MYDUB {  
   int i;  
};  
  
[idl_quote("typedef union _S1_TYPE switch (long l1) U1_TYPE { case 1024: \  
struct MYFLOT f1; case 2048: struct MYDUB d2; } S1_TYPE;") ];  
  
typedef struct _S1_TYPE {   
   long l1;   
  
union {   
   MYFLOT f1; MYDUB d2; } U1_TYPE;   
} S1_TYPE;  
  
[uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA"), object]  
__interface IStatic{  
   HRESULT Func1([idl_quote("in")] int i);  
   HRESULT func( S1_TYPE* myStruct );  
};  
```  
  
 Este código faz com que MYFLOT e MYDUB e o  *texto* entrada a ser colocado no arquivo. idl gerado.  O  *nome* parâmetro forças  *texto* para ser colocado antes de tudo o que faz referência a  *nome* no arquivo. idl gerado.  O  *dependências* parâmetro força as definições de lista de dependência para ser colocado antes de  *texto* no arquivo. idl gerado.  
  
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
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)