---
title: COMM | Microsoft Docs
ms.custom: ''
ms.date: 05/22/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- COMM
dev_langs:
- C++
helpviewer_keywords:
- COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1df6c729ab130a7ff38d7f7cf83224e7425e7dba
ms.sourcegitcommit: da7b7533d1a4dc141cc0f09149e4e4196f2fe329
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/23/2018
ms.locfileid: "34463017"
---
# <a name="comm"></a>COMM

Cria uma variável pública com os atributos especificados no *definição*.

## <a name="syntax"></a>Sintaxe

> **Comunicação** *definição* [, *definição*]...

## <a name="remarks"></a>Comentários

Variáveis pública são alocados pelo vinculador e não podem ser inicializados. Isso significa que você não pode depender do local ou uma sequência de tais variáveis.

Cada *definição* tem a seguinte forma:

[*langtype*] [**NEAR** &#124; **EXTREMO**] _rótulo_**:**_tipo_[**:**_contagem_]

Opcional *langtype* define as convenções de nomenclatura para o nome que segue. Ela substitui qualquer idioma especificado pelo **. MODELO** diretiva. Opcional **NEAR** ou **EXTREMO** substituir o modelo de memória atual. O *rótulo* é o nome da variável. O *tipo* pode ser qualquer especificador de tipo ([bytes](../../assembler/masm/byte-masm.md), [WORD](../../assembler/masm/word.md), e assim por diante) ou um inteiro que especifica o número de bytes. Opcional *contagem* Especifica o número de elementos no objeto de dados declarado; o padrão é um.

## <a name="example"></a>Exemplo

Este exemplo cria uma matriz de elementos de 512 bytes:

```masm
COMM FAR ByteArray:BYTE:512
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)
