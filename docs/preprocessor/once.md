---
title: Pragma once
ms.date: 08/29/2019
f1_keywords:
- vc-pragma.once
- once_CPP
helpviewer_keywords:
- once pragma
- pragmas, once
ms.assetid: c7517556-6403-4b16-8898-f2aa0a6f685f
ms.openlocfilehash: 643ad83b672f7b632925383972751a966256eb41
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220541"
---
# <a name="once-pragma"></a>Pragma once

Especifica que o compilador inclui o arquivo de cabeçalho apenas uma vez, ao compilar um arquivo de código-fonte.

## <a name="syntax"></a>Sintaxe

> **#pragma uma vez**

## <a name="remarks"></a>Comentários

O uso de `#pragma once` pode reduzir os tempos de compilação, pois o compilador não abrirá e lerá o arquivo novamente `#include` após o primeiro do arquivo na unidade de tradução. Ele é chamado de *otimização de vários inclusão*. Ele tem um efeito semelhante ao idioma *include Guard* , que usa definições de macro de pré-processador para evitar várias inclusões do conteúdo do arquivo. Ele também ajuda a evitar violações de *uma regra de definição*, o requisito de que todos os modelos, tipos, funções e objetos não tenham mais de uma definição em seu código.

Por exemplo:

```cpp
// header.h
#pragma once
// Code placed here is included only once per translation unit
```

Recomendamos a `#pragma once` diretiva para o novo código, pois ele não polui o namespace global com um símbolo de pré-processador. Ele requer menos digitação, tem menos distração e não pode causar *colisões de símbolo*, erros causados quando arquivos de cabeçalho diferentes usam o mesmo símbolo de pré-processador que o valor de proteção. Ele não faz parte do C++ padrão, mas é implementado de portalmente por vários compiladores comuns.

Não há vantagem de usar ambos os idiomas include Guard e `#pragma once` no mesmo arquivo. O compilador reconhece o idioma de proteção de inclusão e implementa a otimização de vários inclusão da mesma maneira que `#pragma once` a diretiva se nenhum código de comentário ou diretiva de pré-processamento vier antes ou depois da forma padrão do idioma:

```cpp
// header.h
// Demonstration of the #include guard idiom.
// Note that the defined symbol can be arbitrary.
#ifndef HEADER_H_     // equivalently, #if !defined HEADER_H_
#define HEADER_H_
// Code placed here is included only once per translation unit
#endif // HEADER_H_
```

Recomendamos o idioma de proteção de inclusão quando o código deve ser portátil para compiladores que `#pragma once` não implementam a diretiva, para manter a consistência com o código existente ou quando a otimização de vários inclusões é impossível. Ele pode ocorrer em projetos complexos quando o alias do sistema de arquivos ou os caminhos de inclusão com alias impedem que o compilador identifique arquivos include idênticos por caminho canônico.

Tenha cuidado para não usar `#pragma once` ou o idioma de proteção include nos arquivos de cabeçalho projetados para serem incluídos várias vezes, que usam símbolos de pré-processador para controlar seus efeitos. Para obter um exemplo desse design, consulte o \<arquivo de cabeçalho > Assert. h. Além disso, tenha cuidado para gerenciar seus caminhos de inclusão para evitar a criação de vários caminhos para arquivos incluídos, o que pode anular a otimização de `#pragma once`vários inclusão para ambos, incluindo proteções e.

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
