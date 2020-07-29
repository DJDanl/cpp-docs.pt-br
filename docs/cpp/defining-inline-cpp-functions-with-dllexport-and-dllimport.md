---
title: Definindo funções embutidas do C++ com dllexport e dllimport
ms.date: 11/04/2016
helpviewer_keywords:
- inline functions [C++], defining
- functions [C++], defining inline
- dllimport attribute [C++], inline functions
- dllexport attribute [C++], inline functions
ms.assetid: 3b48678b-e7b8-4eda-bb46-b5d34dcf7817
ms.openlocfilehash: cf3c73e21834391d894a2924f78f6e6143c3a2b6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221712"
---
# <a name="defining-inline-c-functions-with-dllexport-and-dllimport"></a>Definindo funções embutidas do C++ com dllexport e dllimport

**Específico da Microsoft**

Você pode definir como embutido uma função com o **`dllexport`** atributo. Nesse caso, a função sempre é instanciada e exportada, mesmo se qualquer módulo no programa fizer referência à função. Presume-se que a função seja importada por outro programa.

Você também pode definir como embutida uma função declarada com o **`dllimport`** atributo. Nesse caso, a função pode ser expandida (sujeito às especificações de /Ob), mas nunca instanciada. Em particular, se o endereço de uma função importada embutida for usado, o endereço da função que reside na DLL será retornado. Esse comportamento é o mesmo que usar o endereço de uma função importada não embutida.

Essas regras se aplicam às funções embutidas cujas definições aparecem dentro de uma definição de classe. Além disso, os dados locais estáticos e as cadeias de caracteres em funções embutidas mantêm as mesmas identidades entre a DLL e o cliente como em um único programa (isto é, um arquivo executável sem uma interface de DLL).

Tenha cuidado ao fornecer funções embutidas importadas. Por exemplo, se você atualizar a DLL, não suponha que o cliente não usará a versão modificada da DLL. Para garantir que você esteja carregando a versão apropriada da DLL, recompile o cliente da DLL também.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)
