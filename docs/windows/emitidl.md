---
title: "emitidl | Microsoft Docs"
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
  - "vc-attr.emitidl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "emitidl attribute"
ms.assetid: 85b80c56-578e-4392-ac03-8443c74ebb7d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# emitidl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Determina se todos os atributos IDL subseqüentes serão processados e colocados no arquivo. idl gerado.  
  
## Sintaxe  
  
```  
  
      [ emitidl([boolean],  
   defaultimports=[boolean]  
) ] ;  
```  
  
#### Parâmetros  
 `boolean`  
 Possible values: **true**, **false**, **forced**, **restricted**, **push**, or **pop**.  
  
-   Se  **true**, os atributos de categoria IDL encontrados em um arquivo de código fonte serão colocados no arquivo. idl gerado.  Esta é a configuração padrão para  **emitidl**.  
  
-   Se  **false**, os atributos de categoria IDL encontrados em um arquivo de código fonte não serão colocados no arquivo. idl gerado.  
  
-   Se  **restritos**, permite que atributos IDL estar no arquivo sem uma  [módulo de](../windows/module-cpp.md) atributo.  O compilador não irá gerar um arquivo. idl.  
  
-   Se  **forçada**, substitui um subseqüentes  **restritos**  atributo, que requer um arquivo tenha um  **módulo** atributo se houver IDL atributos no arquivo.  
  
-   **envio**  permite que você salve o atual  **emitidl**  as configurações para interna  **emitidl**  pilha, e  **pop**  permite que você definir  **emitidl**  para o valor que está na parte superior de internos  **emitidl**  pilha.  
  
 **defaultimports** *\=* `boolean` \(opcional\)  
 -   Se `boolean` é  **true**, docObj. idl serão importados para o arquivo. idl gerado.  Além disso, se um arquivo. idl com o mesmo nome de um. h arquivo que você `#include` em sua fonte de código está localizado no mesmo diretório que o arquivo. h, então o arquivo. idl gerado irá conter uma instrução de importação para esse arquivo. idl.  
  
-   Se `boolean` é  **false**, docObj. idl não serão importados para o arquivo. idl gerado.  Você precisará importar explicitamente. idl arquivos com  [Importar](../windows/import.md).  
  
## Comentários  
 Após a  **emitidl** atributo C\+\+ é encontrado em um arquivo de código fonte, os atributos de categoria IDL serão colocados no arquivo. idl gerado.  Se não houver nenhum  **emitidl** atributo, atributos IDL no arquivo de código de origem será a saída para o arquivo. idl gerado.  
  
 É possível ter vários  **emitidl** atributos em um arquivo de código fonte.  Se `[emitidl(false)];` é encontrado em um arquivo sem uma subseqüente `[emitidl(true)];`, e em seguida, serão processados sem atributos no arquivo. idl gerado.  
  
 Cada vez que o compilador encontra um novo arquivo,  **emitidl** implicitamente é definido como  **true**.  
  
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
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)