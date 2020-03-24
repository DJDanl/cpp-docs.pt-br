---
title: Decoração do nome
ms.date: 04/22/2019
helpviewer_keywords:
- name decoration [C++]
- names [C++], decorated
- decorated names, calling conventions
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
ms.openlocfilehash: cc00c971eac2a089ccec5bd9eab594bdf4e8348e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173511"
---
# <a name="name-decoration"></a>Decoração do nome

A decoração de nome geralmente C++ se refere a convenções de nomenclatura, mas também pode ser aplicada a um número de casos C. Por padrão, C++ o usa o nome da função, os parâmetros e o tipo de retorno para criar um nome de vinculador para a função. Considere a seguinte declaração de função:

`void CALLTYPE test(void);`

A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.

|Convenção de chamada|arquivo de `extern "C"` ou `.c`|`.cpp`, `.cxx` ou `/TP`|
|------------------------|---------------------------|------------------------|
|Convenção de nomenclatura C (`__cdecl`)|`_test`|`?test@@ZAXXZ`|
|Convenção de nomenclatura de chamada rápida (`__fastcall`)|`@test@0`|`?test@@YIXXZ`|
|Convenção de nomenclatura de chamada padrão (`__stdcall`)|`_test@0`|`?test@@YGXXZ`|
|Convenção de nomenclatura de chamada de vetor (`__vectorcall`)|`test@@0`|`?test@@YQXXZ`|

Use `extern "C"` para chamar uma função C de C++. `extern "C"` força o uso da Convenção de nomenclatura C para funções que C++ não são de classe. Lembre-se das opções de compilador **/TC** ou **/TP**, que dizem ao compilador para ignorar a extensão de nome de arquivo e compilar C++o arquivo como C ou, respectivamente. Essas opções podem causar nomes de vinculadores que você não espera.

Ter protótipos de função que têm parâmetros incompatíveis também pode causar esse erro. Decoração de nome incorpora os parâmetros de uma função no nome da função decorada final. Chamar uma função com os tipos de parâmetro que não correspondem àquelas na declaração de função também pode causar LNK2001.

Atualmente, não há padrões para C++ nomear entre fornecedores de compilador ou mesmo entre versões diferentes de um compilador. A vinculação de arquivos de objeto compilados por outros compiladores pode não produzir o mesmo esquema de nomenclatura e pode causar externas não resolvidas.

## <a name="see-also"></a>Confira também

[Erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md)
