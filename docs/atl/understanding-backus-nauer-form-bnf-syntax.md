---
title: Registrador da ATL e Backus Nauer formulário de sintaxe (BNF) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- BNF notation
- Backus Nauer Form (BNF) syntax
ms.assetid: 994bbef0-9077-4aa8-bdfe-b7e830af9acc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9acb054c7d991e2d9e98df3ce9bba8c7093f281a
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43761476"
---
# <a name="understanding-backus-nauer-form-bnf-syntax"></a>Noções básicas sobre a sintaxe do Backus Nauer Form (BNF)

Os scripts usados pelo registrador de ATL são descritos neste tópico usando a sintaxe BNF, que usa a notação mostrada na tabela a seguir.

|Convenção/símbolo|Significado|
|------------------------|-------------|
|::=|Equivalente|
|&#124;|OU|
|X +|Um ou mais Xs.|
|[X]|X é opcional. Delimitadores opcionais são indicadas por \[].|
|Qualquer **negrito** texto|Uma cadeia de caracteres literal.|
|Qualquer *itálico* texto|Como construir a cadeia de caracteres literal.|

Conforme indicado na tabela anterior, scripts do registrador usam literais de cadeia de caracteres. Esses valores são texto real que deve aparecer no seu script. A tabela a seguir descreve os literais de cadeia de caracteres usados em um script de registrador da ATL.

|Literal de cadeia de caracteres|Ação|
|--------------------|------------|
|**ForceRemove**|Remove completamente a próxima chave (se houver) e, em seguida, cria-lo novamente.|
|**NoRemove**|Não remove a próxima chave durante o cancelamento de registro.|
|**Val**|Especifica que `<Key Name>` é, na verdade, um valor nomeado.|
|**Excluir**|Exclui a próxima chave durante o registro.|
|**s**|Especifica que o próximo valor é uma cadeia de caracteres (REG_SZ).|
|**d**|Especifica que o próximo valor DWORD (REG_DWORD).|
|**m**|Especifica que o próximo valor é uma cadeia de caracteres múltipla (REG_MULTI_SZ).|
|**b**|Especifica que o próximo valor é um valor binário (REG_BINARY).|

## <a name="bnf-syntax-examples"></a>Exemplos de sintaxe BNF

Aqui estão alguns exemplos de sintaxe para ajudá-lo a entender como os literais de cadeia de caracteres de notação funcionam em um script de registrador da ATL.

### <a name="syntax-example-1"></a>Exemplo de sintaxe 1

```  
<registry expression> ::= <Add Key>  
```

Especifica que `registry expression` é equivalente a `Add Key`.

### <a name="syntax-example-2"></a>Exemplo de sintaxe 2

```  
<registry expression> ::= <Add Key> | <Delete Key>  
```

Especifica que `registry expression` é equivalente ao tipo `Add Key` ou `Delete Key`.

### <a name="syntax-example-3"></a>Exemplo de sintaxe 3

```  
<Key Name> ::= '<AlphaNumeric>+'  
```

Especifica que `Key Name` é equivalente a um ou mais `AlphaNumerics`.

### <a name="syntax-example-4"></a>Exemplo de sintaxe 4

```  
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>  
```

Especifica que `Add Key` é equivalente a `Key Name`e que os literais de cadeia de caracteres `ForceRemove`, `NoRemove`, e `val`, são opcionais.

### <a name="syntax-example-5"></a>Exemplo de sintaxe 5

```  
<AlphaNumeric> ::= any character not NULL, that is, ASCII 0  
```

Especifica que `AlphaNumeric` é equivalente a qualquer caractere não-nulo.

### <a name="syntax-example-6"></a>Exemplo de sintaxe 6

```  
val 'testmulti' = m 'String 1\0String 2\0'  
```

Especifica que o nome da chave `testmulti` é um valor de cadeia de caracteres múltiplas composto `String 1` e `String 2`.

### <a name="syntax-example-7"></a>Exemplo de sintaxe 7

```  
val 'testhex' = d '&H55'  
```

Especifica que o nome da chave `testhex` é um valor DWORD definido como 55 hexadecimal (85 decimal). Observação neste formato segue o **& H** notação como encontrado na especificação do Visual Basic.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)

