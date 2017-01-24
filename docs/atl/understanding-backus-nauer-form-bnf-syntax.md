---
title: "Sintaxe no&#231;&#245;es b&#225;sicas sobre (BNF) do formul&#225;rio de Backus Nauer | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Sintaxe de (BNF) do formulário de Backus Nauer"
  - "Notação de BNF"
ms.assetid: 994bbef0-9077-4aa8-bdfe-b7e830af9acc
caps.latest.revision: 15
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sintaxe no&#231;&#245;es b&#225;sicas sobre (BNF) do formul&#225;rio de Backus Nauer
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os scripts usados pelo escrivão de ATL são descritos em este tópico usando a sintaxe de BNF, que usa notação mostrada na tabela.  
  
|Convenção\/símbolo|Significado|  
|------------------------|-----------------|  
|`::=`|Equivalente|  
|`&#124;`|OU|  
|`X+`|Um ou mais `X`S.|  
|`[X]`|`X` é opcional.  Os delimitadores opcionais são denotados por `[]`.|  
|Texto em **negrito**|Um literal de cadeia de caracteres.|  
|Texto *em itálico*|Como construir o literal de cadeia de caracteres.|  
  
 Conforme indicado na tabela anterior, os scripts de escrivão usando literais de cadeia de caracteres.  Esses valores são o texto real que deve aparecer no script.  A tabela a seguir descreve os literais de cadeia de caracteres usados em um script de escrivão de ATL.  
  
|Cadeia de caracteres literal|Ação|  
|----------------------------------|----------|  
|**ForceRemove**|Remove completamente a próxima chave \(se existir\) e recreia\-a em.|  
|**NoRemove**|Não remove a próxima chave durante Unregister.|  
|**val**|Especifica que `<Key Name>` é realmente um valor chamado.|  
|**Excluir**|Exclui a próxima chave durante o registro.|  
|**\-S\-**|Especifica que o valor seguir é uma cadeia de caracteres \(**REG\_SZ**\).|  
|**d**|Especifica que o valor seguir é **DWORD** \(**REG\_DWORD**\).|  
|**m**|Especifica que o valor seguir é multistring \(**REG\_MULTI\_SZ**\).|  
|**b**|Especifica que o valor seguir é um valor binário \(**REG\_BINARY**\).|  
  
## Exemplos de sintaxe de BNF  
 Eis alguns exemplos de sintaxe para ajudar você a entender como os literais de notação e de cadeia de caracteres trabalham em um script de escrivão de ATL.  
  
### Exemplo de sintaxe 1  
  
```  
<registry expression> ::= <Add Key>  
```  
  
 especifica que `registry expression` é equivalente a `Add Key`.  
  
### Exemplo de sintaxe 2  
  
```  
<registry expression> ::= <Add Key> | <Delete Key>  
```  
  
 especifica que `registry expression` é equivalente a `Add Key` ou a `Delete Key`.  
  
### Exemplo de sintaxe 3  
  
```  
<Key Name> ::= '<AlphaNumeric>+'  
```  
  
 especifica que `Key Name` é equivalente a um ou mais `AlphaNumerics`.  
  
### Exemplo de sintaxe 4  
  
```  
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>  
```  
  
 especifica que `Add Key` é equivalente a `Key Name`, e que os literais de cadeia de caracteres, `ForceRemove`, `NoRemove`, e `val`, são opcionais.  
  
### Exemplo de sintaxe 5  
  
```  
<AlphaNumeric> ::= any character not NULL, that is, ASCII 0  
```  
  
 especifica que `AlphaNumeric` é equivalente a qualquer caractere não\-nulo.  
  
### Exemplo de sintaxe 6  
  
```  
val 'testmulti' = m 'String 1\0String 2\0'  
```  
  
 especifica que o nome da chave `testmulti` é um valor multistring composta de `String 1` e de `String 2`.  
  
### Exemplo de sintaxe 7  
  
```  
val 'testhex' = d '&H55'  
```  
  
 especifica que o nome da chave `testhex` é um valor de **DWORD** definido como 55 dígitos hexadecimais \(85\).  Observe esse formato aderem à notação de **&H** como estabelecida na especificação do Visual Basic.  
  
## Consulte também  
 [Criando scripts de escrivão](../Topic/Creating%20Registrar%20Scripts.md)