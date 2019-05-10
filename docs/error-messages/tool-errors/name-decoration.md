---
title: Decoração do nome
ms.date: 04/22/2019
helpviewer_keywords:
- name decoration [C++]
- names [C++], decorated
- decorated names, calling conventions
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
ms.openlocfilehash: d1557f53a07a544ff4f9e5a63f905e6854fb74ce
ms.sourcegitcommit: 283cb64fd7958a6b7fbf0cd8534de99ac8d408eb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2019
ms.locfileid: "64857165"
---
# <a name="name-decoration"></a>Decoração do nome

Decoração de nome geralmente se refere a convenções de nomenclatura do C++, mas pode aplicar a um número de casos de C também. Por padrão, o C++ usa o nome da função, parâmetros e tipo de retorno para criar um nome de vinculador para a função. Considere a seguinte declaração de função:

`void CALLTYPE test(void);`

A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.

|Convenção de chamada|`extern "C"` ou `.c` arquivo|`.cpp`, `.cxx` ou `/TP`|
|------------------------|---------------------------|------------------------|
|Convenção de nomenclatura de C (`__cdecl`)|`_test`|`?test@@ZAXXZ`|
|Convenção de nomenclatura de chamada rápida (`__fastcall`)|`@test@0`|`?test@@YIXXZ`|
|Convenção de nomenclatura de chamada padrão (`__stdcall`)|`_test@0`|`?test@@YGXXZ`|
|Convenção de nomenclatura de chamada de vetor (`__vectorcall`)|`test@@0`|`?test@@YQXXZ`|

Use `extern "C"` para chamar uma função de C do C++. `extern "C"` força o uso da convenção de nomenclatura de C para diferente de classe C++ funções. Lembre-se de comutadores de compilador **/Tc** ou **/Tp**, que diz ao compilador para ignorar a extensão de nome de arquivo e compile o arquivo como C ou C++, respectivamente. Essas opções podem causar nomes de vinculador, que você não espera.

Ter protótipos de função que têm parâmetros incompatíveis também pode causar esse erro. Decoração de nome incorpora o nome decorado de função final os parâmetros de uma função. Chamar uma função com os tipos de parâmetro que não coincidem com a declaração de função também pode causar LNK2001.

Atualmente, não há nenhum padrão para C++ entre fornecedores de compilador ou até mesmo entre diferentes versões de um compilador de nomenclatura. Vinculação de arquivos de objeto compilados por outros compiladores pode não produzir o mesmo esquema de nomenclatura e pode causar externos não resolvidos.

## <a name="see-also"></a>Consulte também

[Erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md)