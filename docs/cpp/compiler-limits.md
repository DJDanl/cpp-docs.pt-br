---
title: Limites do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- cl.exe compiler, limits for language constructs
ms.assetid: f1fa59c6-55b4-414b-80c5-3df72952160d
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 986a158ea74e56a0e52c1ffff77f83b8ede71ef5
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="compiler-limits"></a>Limites do compilador
O padrão do C++ recomenda limites para várias construções de linguagem. A lista a seguir contém casos onde o compilador do Visual C++ não implementa os limites recomendados. O primeiro número é o limite estabelecido no padrão ISO C++11 (INCITS/ISO/IEC 14882-2011[2012], Anexo B) e o segundo número é o limite implementado pelo Visual C++:  
  
-   Níveis de aninhamento de instruções compostas, estruturas de controle de iteração e seleção de controlam estruturas - padrão do C++: 256, compilador do Visual C++: depende da combinação de instruções que são aninhadas, mas geralmente entre 100 e 110.  
  
-   Parâmetros na definição de uma macropadrão do C++: 256, compilador do Visual C++: 127.  
  
-   Argumentos na invocação de uma macropadrão do C++: compilador do Visual C++ 256, 127.  
  
-   Caracteres em um caractere da cadeia de caracteres literal ou grande cadeia de caracteres literal (depois de concatenação) - standard C++: 65536, compilador do Visual C++: 65535 caracteres de byte único, incluindo o `null` terminador e 32.767 caracteres de byte duplo, incluindo o `null` terminador.  
  
-   Níveis de definições de união em um único, estrutura ou classe aninhada `struct-declaration-list` -padrão do C++: 256, compilador do Visual C++: 16.  
  
-   Inicializadores de membro em uma definição de construtor - padrão do C++: 6144, compilador do Visual C++: pelo menos 6144.  
  
-   Definir o escopo de qualificações de um identificador - C++ padrão: 256, compilador do Visual C++: 127.  
  
-   Aninhados `extern` especificações - padrão do C++: 1024, o compilador do Visual C++: 9 (sem contar o implícita `extern` especificação em escopo global ou 10, se você contar o implícita `extern` especificação no escopo global...  
  
-   Argumentos de modelo em uma declaração de modelo - padrão do C++: 1024, o compilador do Visual C++: 2046.  
  
## <a name="see-also"></a>Consulte também  
 [Comportamento não padrão](../cpp/nonstandard-behavior.md)
