---
title: Registrador da ATL e Backus Nauer formam sintaxe (BNF) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- BNF notation
- Backus Nauer Form (BNF) syntax
ms.assetid: 994bbef0-9077-4aa8-bdfe-b7e830af9acc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 01d364313420c0a950f8eba222e3ae020fbd86cf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="understanding-backus-nauer-form-bnf-syntax"></a>Noções básicas sobre a sintaxe de formulário (BNF) Backus Nauer
Os scripts usados pelo registrador de ATL são descritos neste tópico usando a sintaxe BNF, que usa a notação mostrada na tabela a seguir.  
  
|Convenção/símbolo|Significado|  
|------------------------|-------------|  
|`::=`|Equivalente|  
|`&#124;`|OU|  
|`X+`|Um ou mais `X`s.|  
|`[X]`|`X` é opcional. Opcionais delimitadores são indicados por `[]`.|  
|Qualquer **negrito** texto|Uma cadeia de caracteres literal.|  
|Qualquer *em itálico* texto|Como construir a cadeia de caracteres literal.|  
  
 Conforme indicado na tabela anterior, os scripts do registrador usam literais de cadeia de caracteres. Esses valores são texto real que deve aparecer no script. A tabela a seguir descreve os literais de cadeia de caracteres usados em um script de registrador da ATL.  
  
|Literal de cadeia de caracteres|Ação|  
|--------------------|------------|  
|**ForceRemove**|Remove completamente a próxima chave (se houver) e, em seguida, cria-lo novamente.|  
|**NoRemove**|Não remova a próxima chave durante o cancelamento de registro.|  
|**Val**|Especifica que `<Key Name>` é, na verdade, um valor nomeado.|  
|**Excluir**|Exclui a próxima chave durante o registro.|  
|**s**|Especifica que o próximo valor é uma cadeia de caracteres (**REG_SZ**).|  
|**d**|Especifica que o próximo valor é um **DWORD** (**REG_DWORD**).|  
|**m**|Especifica que o próximo valor é uma múltipla de comprimento fixo (**REG_MULTI_SZ**).|  
|**b**|Especifica que o próximo valor é um valor binário (**REG_BINARY**).|  
  
## <a name="bnf-syntax-examples"></a>Exemplos de sintaxe BNF  
 Aqui estão alguns exemplos de sintaxe para ajudá-lo a entender o funcionam de notação e cadeia de caracteres literais em um script de registrador da ATL.  
  
### <a name="syntax-example-1"></a>Sintaxe de exemplo 1  
  
```  
<registry expression> ::= <Add Key>  
```  
  
 Especifica que `registry expression` é equivalente a `Add Key`.  
  
### <a name="syntax-example-2"></a>Exemplo de sintaxe 2  
  
```  
<registry expression> ::= <Add Key> | <Delete Key>  
```  
  
 Especifica que `registry expression` é equivalente a uma `Add Key` ou `Delete Key`.  
  
### <a name="syntax-example-3"></a>Exemplo de sintaxe 3  
  
```  
<Key Name> ::= '<AlphaNumeric>+'  
```  
  
 Especifica que `Key Name` é equivalente a um ou mais `AlphaNumerics`.  
  
### <a name="syntax-example-4"></a>Exemplo de sintaxe 4  
  
```  
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>  
```  
  
 Especifica que `Add Key` é equivalente a `Key Name`e que os literais de cadeia de caracteres, `ForceRemove`, `NoRemove`, e `val`, são opcionais.  
  
### <a name="syntax-example-5"></a>Exemplo de sintaxe 5  
  
```  
<AlphaNumeric> ::= any character not NULL, that is, ASCII 0  
```  
  
 Especifica que `AlphaNumeric` é equivalente a qualquer caractere não-nulo.  
  
### <a name="syntax-example-6"></a>Exemplo de sintaxe 6  
  
```  
val 'testmulti' = m 'String 1\0String 2\0'  
```  
  
 Especifica que o nome da chave `testmulti` é composto de um valor de cadeias de caracteres múltiplas de `String 1` e `String 2`.  
  
### <a name="syntax-example-7"></a>Exemplo de sintaxe 7  
  
```  
val 'testhex' = d '&H55'  
```  
  
 Especifica que o nome da chave `testhex` é um **DWORD** valor definido como 55 hexadecimal (85 decimal). Observe que segue este formato de **& H** notação como encontrada na especificação de Visual Basic.  
  
## <a name="see-also"></a>Consulte também  
 [Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

