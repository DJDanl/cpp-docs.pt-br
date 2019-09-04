---
title: Macros e C++
ms.date: 08/29/2019
helpviewer_keywords:
- macros, C++
- macros
ms.assetid: 83a344c1-73c9-4ace-8b93-cccfb62c6133
ms.openlocfilehash: 8a86fb81544af91d4e844fb08b7948a589976e04
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220804"
---
# <a name="macros-and-c"></a>Macros e C++

C++oferece novos recursos, alguns dos quais suplantar aqueles oferecidos pelo pré-processador ANSI C. Esses novos recursos aprimoram a segurança do tipo e a previsibilidade da linguagem:

- No C++, os objetos declarados como **const** podem ser usados em expressões constantes. Ele permite que os programas declarem constantes que têm informações de tipo e valor. Eles podem declarar enumerações que podem ser exibidas de uma janela simbólica com o depurador. Quando você usa a `#define` diretiva de pré-processador para definir constantes, ela não é tão precisa e não é de tipo seguro. Nenhum armazenamento é alocado para um objeto **const** , a menos que o programa contenha uma expressão que aceite seu endereço.

- O recurso da função integrada C++ substitui macros de tipo de função. As vantagens de usar funções integradas sobre as macros são:

  - Segurança de tipo. As funções integradas estão sujeitas à mesma verificação de tipo que as funções normais. As macros não são de tipo seguro.

  - Corrija a manipulação de argumentos que têm efeitos colaterais. As funções embutidas avaliam as expressões fornecidas como argumentos antes de o corpo da função ser inserido. Portanto, não há nenhuma chance de que uma expressão com efeitos colaterais não seja segura.

Para obter mais informações sobre funções embutidas, consulte [inline, \___inline, _forceinline](../cpp/inline-functions-cpp.md).

Para compatibilidade com versões anteriores, todas as instalações de pré-processadores que existiam em ANSI C e nas especificações anteriores do C++ são preservadas para o Microsoft C++.

## <a name="see-also"></a>Consulte também

[Macros predefinidas](../preprocessor/predefined-macros.md)\
[Macros (C/C++)](../preprocessor/macros-c-cpp.md)
