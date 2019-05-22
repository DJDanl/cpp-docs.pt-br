---
title: Registrador da ATL e sintaxe BNF (forma de Backus-Naur)
ms.date: 05/14/2019
helpviewer_keywords:
- BNF notation
- Backus-Naur form (BNF) syntax
ms.assetid: 994bbef0-9077-4aa8-bdfe-b7e830af9acc
ms.openlocfilehash: 77f0fa6fef8e517e5714d1da6c61d0e310e0718c
ms.sourcegitcommit: fc1de63a39f7fcbfe2234e3f372b5e1c6a286087
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/15/2019
ms.locfileid: "65709176"
---
# <a name="understanding-backus-naur-form-bnf-syntax"></a>Noções básicas sobre a sintaxe BNF (forma de Backus-Naur)

Os scripts usados pelo Registrador da ATL são descritos neste tópico usando a sintaxe BNF, que usa a notação mostrada na tabela a seguir.

|Convenção/símbolo|Significado|
|------------------------|-------------|
|::=|Equivalente|
|&#124;|OU|
|X+|Um ou mais Xs.|
|\[X]|X é opcional. Delimitadores opcionais são indicados por \[].|
|Qualquer texto em **negrito**|Um literal de cadeia de caracteres.|
|Qualquer texto em *itálico*|Como construir o literal de cadeia de caracteres.|

Conforme indicado na tabela anterior, os scripts do registrador usam literais de cadeia de caracteres. Esses valores são texto real que devem ser exibidos em seu script. A tabela a seguir descreve os literais de cadeia de caracteres usados em um script do Registrador da ATL.

|Literal de cadeia de caracteres|Ação|
|--------------------|------------|
|**ForceRemove**|Remove completamente a próxima chave (se existir) e, em seguida, a recria.|
|**NoRemove**|Não remove a próxima chave durante o Cancelamento do registro.|
|**val**|Especifica que `<Key Name>` é realmente um valor nomeado.|
|**Excluir**|Exclui a próxima chave durante o Registro.|
|**s**|Especifica que o próximo valor é uma cadeia de caracteres (REG_SZ).|
|**d**|Específica que o próximo valor é um DWORD (REG_DWORD).|
|**m**|Especifica que o próximo valor é uma cadeia de caracteres múltipla (REG_MULTI_SZ).|
|**b**|Especifica que o próximo valor é um valor binário (REG_BINARY).|

## <a name="bnf-syntax-examples"></a>Exemplos de sintaxe BNF

Veja alguns exemplos de sintaxe para ajudá-lo a entender como a notação e os literais de cadeia de caracteres funcionam em um script do Registrador da ATL.

### <a name="syntax-example-1"></a>Exemplo de Sintaxe 1

```
<registry expression> ::= <Add Key>
```

especifica que `registry expression` é equivalente a `Add Key`.

### <a name="syntax-example-2"></a>Exemplo de Sintaxe 2

```
<registry expression> ::= <Add Key> | <Delete Key>
```

especifica que `registry expression` é equivalente a `Add Key` ou a `Delete Key`.

### <a name="syntax-example-3"></a>Exemplo de Sintaxe 3

```
<Key Name> ::= '<AlphaNumeric>+'
```

especifica que `Key Name` é equivalente a um ou mais `AlphaNumerics`.

### <a name="syntax-example-4"></a>Exemplo de Sintaxe 4

```
<Add Key> ::= [ForceRemove | NoRemove | val]<Key Name>
```

especifica que `Add Key` é equivalente a `Key Name` e que os literais de cadeia de caracteres, `ForceRemove`, `NoRemove` e `val`, são opcionais.

### <a name="syntax-example-5"></a>Exemplo de Sintaxe 5

```
<AlphaNumeric> ::= any character not NULL, that is, ASCII 0
```

especifica que `AlphaNumeric` é equivalente a qualquer caractere diferente de NULL.

### <a name="syntax-example-6"></a>Exemplo de Sintaxe 6

```
val 'testmulti' = m 'String 1\0String 2\0'
```

especifica que o nome da chave `testmulti` é um valor de cadeia de caracteres múltipla composta por `String 1` e `String 2`.

### <a name="syntax-example-7"></a>Exemplo de Sintaxe 7

```
val 'testhex' = d '&H55'
```

especifica que o nome da chave `testhex` é um valor DWORD definido como hexadecimal 55 (decimal 85). Observe que este formato segue a notação **&H**, conforme encontrado na especificação do Visual Basic.

## <a name="see-also"></a>Consulte também

[Criando scripts do Registrador](../atl/creating-registrar-scripts.md)
