---
title: once | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.once
- once_CPP
dev_langs:
- C++
helpviewer_keywords:
- once pragma
- pragmas, once
ms.assetid: c7517556-6403-4b16-8898-f2aa0a6f685f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9f0aea1700feaad1c286386f17a5008514282d52
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="once"></a>uma vez
Especifica que o arquivo será incluído (aberto) apenas uma vez pelo compilador ao compilar um arquivo de código-fonte.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma once  
  
```  
  
## <a name="remarks"></a>Comentários  
 O uso de `#pragma once` pode reduzir os tempos de compilação, o compilador não abrir e ler o arquivo após a primeira #include do arquivo na unidade de tradução. Isso é conhecido como *otimização de incluir vários*. Ele tem um efeito semelhante para o *#include guard* idioma, que usa as definições de macro de pré-processador para impedir que vários inclusão do conteúdo do arquivo. Isso também ajuda a impedir violações de *regra de definição de um*— o requisito de que todos os modelos, tipos, funções e objetos tem não mais de uma definição em seu código.  
  
 Por exemplo:  
  
```  
// header.h  
#pragma once  
// Code placed here is included only once per translation unit  
  
```  
  
 É recomendável a `#pragma once` diretiva para o novo código porque ele não poluir o namespace global com um símbolo do pré-processador. Ele requer menos digitação, menos causa uma distração e não pode causar colisões de símbolo — erros causados quando os arquivos de cabeçalho diferente de usam o símbolo do pré-processador mesmo como o valor de proteção. Não é parte do C++ padrão, mas é implementado portably por alguns compiladores comuns.  
  
 Não há nenhuma vantagem em usar tanto o #include protetor de idioma e `#pragma once` no mesmo arquivo. O compilador reconhece o #include protetor de idioma e implementa o múltiplo incluem otimização da mesma forma que o `#pragma once` diretiva se nenhum código de comentário não ou diretiva de pré-processador vem antes ou depois do formulário padrão do idioma:  
  
```  
// header.h  
// Demonstration of the #include guard idiom.  
// Note that the defined symbol can be arbitrary.  
#ifndef HEADER_H_     // equivalently, #if !defined HEADER_H_  
#define HEADER_H_  
// Code placed here is included only once per translation unit  
#endif // HEADER_H_  
  
```  
  
 É recomendável a #include protetor idioma ao código deve ser portáteis para compiladores que não implementam a `#pragma once` diretiva, para manter a consistência com o código existente, ou quando a incluir vários otimização é impossível. Isso pode ocorrer em projetos complexos ao alias de sistema de arquivo ou um alias incluir caminhos impedem o compilador de identificar idêntico incluir arquivos pelo caminho canônico.  
  
 Tenha cuidado para não usar `#pragma once` ou #include protetor de idioma em arquivos de cabeçalho que são projetados para ser incluída várias vezes, usando símbolos de pré-processamento para controlar seus efeitos. Para obter um exemplo desse design, consulte o \<assert.h > arquivo de cabeçalho. Além disso, tenha cuidado para gerenciar incluir caminhos para evitar a criação de vários caminhos para arquivos incluídos, que podem anular a incluir vários de otimização para ambos #include protege e `#pragma once`.  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)