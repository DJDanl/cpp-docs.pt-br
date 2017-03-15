---
title: "rename (#import) | Microsoft Docs"
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
  - "Rename"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "atributo rename"
ms.assetid: 5c5c6153-1087-4b7b-87fb-fc59b90b9975
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# rename (#import)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico do C\+\+**  
  
 Soluciona os problemas de colisão de nome.  
  
## Sintaxe  
  
```  
rename("OldName","NewName")  
```  
  
#### Parâmetros  
 `OldName`  
 Nome antigo na biblioteca de tipos.  
  
 `NewName`  
 Nome a ser usado em vez do nome antigo.  
  
## Comentários  
 Se esse atributo for especificado, o compilador substituirá todas as ocorrências de *OldName* em uma biblioteca de tipos pelo *NewName* fornecido pelo usuário nos arquivos de cabeçalho resultantes.  
  
 Esse atributo pode ser usado quando um nome na biblioteca de tipos coincide com uma definição de macro nos arquivos de cabeçalho do sistema.  Se essa situação não for resolvida, vários erros de sintaxe serão gerados, como [C2059 de erro do compilador](../Topic/Compiler%20Error%20C2059.md) e [Erro do Compilador C2061](../error-messages/compiler-errors-1/compiler-error-c2061.md).  
  
> [!NOTE]
>  A substituição é para um nome usado na biblioteca de tipos, e não para um nome usado no arquivo de cabeçalho resultante.  
  
 Por exemplo, suponha que exista uma propriedade chamada `MyParent` em uma biblioteca de tipos, e uma macro `GetMyParent` seja definida em um arquivo de cabeçalho e usada antes de `#import`.  Como `GetMyParent` é o nome padrão de uma função de wrapper para a propriedade de tratamento de erros **get**, ocorrerá uma colisão de nomes.  Para contornar o problema, use o seguinte atributo na instrução `#import`:  
  
```  
rename("MyParent","MyParentX")  
```  
  
 que altera o nome `MyParent` na biblioteca de tipos.  Uma tentativa de alterar o nome do wrapper `GetMyParent` falhará:  
  
```  
rename("GetMyParent","GetMyParentX")  
```  
  
 Isso acontece porque o nome `GetMyParent` ocorre apenas no arquivo de cabeçalho resultante da biblioteca de tipos.  
  
 **FIM de Específico do C\+\+**  
  
## Consulte também  
 [Atributos \#import](../preprocessor/hash-import-attributes-cpp.md)   
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)