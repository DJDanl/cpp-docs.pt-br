---
title: COMM
ms.date: 08/30/2018
f1_keywords:
- COMM
helpviewer_keywords:
- COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
ms.openlocfilehash: 342c8acd95fd45de1a21dc298325de9a7b40b717
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179101"
---
# <a name="comm"></a>COMM

Cria uma variável pública com os atributos especificados na *definição*.

## <a name="syntax"></a>Sintaxe

> **COMM** *definição* [, *definição*]...

## <a name="remarks"></a>Comentários

Quase variáveis são alocadas pelo vinculador e não podem ser inicializadas. Isso significa que você não pode depender do local ou a sequência de tais variáveis.

Cada *definição* tem a seguinte forma:

[*langtype*] [**NEAR** &#124; **FAR**] _label_**:**_type_[**:**_count_]

Opcional *langtype* define as convenções de nomenclatura para o nome que segue. Ela substitui qualquer idioma especificado pelo **. MODELO** diretiva. Opcional **NEAR** ou **EXTREMO** substituir o modelo de memória atual. O *rótulo* é o nome da variável. O *tipo* pode ser qualquer especificador de tipo ([bytes](../../assembler/masm/byte-masm.md), [WORD](../../assembler/masm/word.md)e assim por diante) ou um inteiro que especifica o número de bytes. Opcional *contagem* Especifica o número de elementos no objeto de dados declarado; o padrão é um.

## <a name="example"></a>Exemplo

Este exemplo cria uma matriz de elementos de 512 bytes:

```asm
COMM FAR ByteArray:BYTE:512
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>
