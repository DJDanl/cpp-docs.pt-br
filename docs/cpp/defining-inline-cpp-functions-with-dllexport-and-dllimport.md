---
title: Definindo funções embutidas do C++ com dllexport e dllimport
ms.date: 11/04/2016
helpviewer_keywords:
- inline functions [C++], defining
- functions [C++], defining inline
- dllimport attribute [C++], inline functions
- dllexport attribute [C++], inline functions
ms.assetid: 3b48678b-e7b8-4eda-bb46-b5d34dcf7817
ms.openlocfilehash: 88fbb497aab4d794d3ef84a902a72c4e044e51de
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857561"
---
# <a name="defining-inline-c-functions-with-dllexport-and-dllimport"></a>Definindo funções embutidas do C++ com dllexport e dllimport

**Seção específica da Microsoft**

Você pode definir como embutido uma função com o atributo **dllexport** . Nesse caso, a função sempre é instanciada e exportada, mesmo se qualquer módulo no programa fizer referência à função. Presume-se que a função seja importada por outro programa.

Você também pode definir como embutida uma função declarada com o atributo **dllimport**. Nesse caso, a função pode ser expandida (sujeito às especificações de /Ob), mas nunca instanciada. Em particular, se o endereço de uma função importada embutida for usado, o endereço da função que reside na DLL será retornado. Esse comportamento é o mesmo que usar o endereço de uma função importada não embutida.

Essas regras se aplicam às funções embutidas cujas definições aparecem dentro de uma definição de classe. Além disso, os dados locais estáticos e as cadeias de caracteres em funções embutidas mantêm as mesmas identidades entre a DLL e o cliente como em um único programa (isto é, um arquivo executável sem uma interface de DLL).

Tenha cuidado ao fornecer funções embutidas importadas. Por exemplo, se você atualizar a DLL, não suponha que o cliente não usará a versão modificada da DLL. Para garantir que você esteja carregando a versão apropriada da DLL, recompile o cliente da DLL também.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[dllexport, dllimport](../cpp/dllexport-dllimport.md)