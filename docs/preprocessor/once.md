---
title: uma vez
ms.date: 11/04/2016
f1_keywords:
- vc-pragma.once
- once_CPP
helpviewer_keywords:
- once pragma
- pragmas, once
ms.assetid: c7517556-6403-4b16-8898-f2aa0a6f685f
ms.openlocfilehash: 6061fe77960aa64e2dcb39db05897ef0e7fb5f2e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62326333"
---
# <a name="once"></a>uma vez
Especifica que o arquivo será incluído (aberto) apenas uma vez pelo compilador ao compilar um arquivo de código-fonte.

## <a name="syntax"></a>Sintaxe

```
#pragma once
```

## <a name="remarks"></a>Comentários

O uso de `#pragma once` pode reduzir os tempos de compilação como o compilador não abrirá e lerá o arquivo após a primeira `#include` do arquivo na unidade de tradução. Isso é conhecido como *incluem várias de otimização*. Ele tem um efeito semelhante ao `#include guard` idioma, que usa as definições de macro de pré-processador para evitar a inclusão de vários do conteúdo do arquivo. Isso também ajuda a evitar violações do *regra de definição de um*— o requisito de que todos os modelos, tipos, funções e objetos tem não mais de uma definição em seu código.

Por exemplo:

```
// header.h
#pragma once
// Code placed here is included only once per translation unit
```

É recomendável a `#pragma once` diretiva para o novo código, porque ele não poluam o namespace global com um símbolo do pré-processador. Ele requer menos digitação, menos distração e não pode causar colisões de símbolo — erros causados quando os arquivos de cabeçalho diferente usam o símbolo do pré-processador mesmo como o valor de proteção. Não é parte do C++ padrão, mas ele é implementado forma portátil por diversos compiladores comuns.

Não há nenhuma vantagem em usar de ambos o #include idiom guard e `#pragma once` no mesmo arquivo. O compilador reconhece o #include idiom guard e implementa o múltiplo incluem a otimização da mesma forma que o `#pragma once` diretiva se nenhum código sem comentário ou a diretiva de pré-processador vem antes ou após o formato padrão da linguagem:

```
// header.h
// Demonstration of the #include guard idiom.
// Note that the defined symbol can be arbitrary.
#ifndef HEADER_H_     // equivalently, #if !defined HEADER_H_
#define HEADER_H_
// Code placed here is included only once per translation unit
#endif // HEADER_H_
```

É recomendável o `#include guard` idiom quando o código deve ser portáteis para compiladores que não implementam a `#pragma once` diretiva, para manter a consistência com o código existente, ou quando o múltiplo-include otimização é impossível. Isso pode ocorrer em projetos complexos ao alias do sistema de arquivos ou um alias incluir caminhos impedem o compilador de identificar idêntico incluir arquivos pelo caminho canônico.

Tenha cuidado para não usar `#pragma once` ou o `#include guard` idiom nos arquivos de cabeçalho que são projetados para ser incluída várias vezes, usando símbolos de pré-processador para controlar seus efeitos. Para obter um exemplo desse design, consulte o \<Assert > arquivo de cabeçalho. Também, ser cuidadoso ao gerenciar incluir caminhos para evitar a criação de vários caminhos para arquivos incluídos, o que podem anular a incluir vários de otimização para ambos `#include guard`s e `#pragma once`.

## <a name="see-also"></a>Consulte também

[Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)