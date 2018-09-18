---
title: Decoração de nome | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
dev_langs:
- C++
helpviewer_keywords:
- name decoration [C++]
- names [C++], decorated
- decorated names, calling conventions
ms.assetid: 8327a27b-bb4f-49f2-8218-b851b9d2a463
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fa493a886509a85cc45c14f003ff07886c435280
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46036027"
---
# <a name="name-decoration"></a>Decoração do nome

Decoração de nome geralmente se refere a convenções de nomenclatura do C++, mas pode aplicar a um número de casos de C também. Por padrão, o C++ usa o nome da função, parâmetros e tipo de retorno para criar um nome de vinculador para a função. Considere a seguinte função:

```
void CALLTYPE test(void)
```

A tabela a seguir mostra o nome do vinculador para várias convenções de chamada.

|Convenção de chamada|arquivo de extern "C" ou o. c|. cpp,. cxx ou /TP|
|------------------------|---------------------------|------------------------|
|Convenção de nomenclatura de C (`__cdecl`)|`_test`|`?test@@ZAXXZ`|
|Convenção de nomenclatura fastcall (`__fastcall`)|`@test@0`|`?test@@YIXXZ`|
|Convenção de nomenclatura padrão de chamada (`__stdcall`)|`_test@0`|`?test@@YGXXZ`|
|Convenção de nomenclatura Vectorcall (`__vectorcall`)|`test@@0`|`?test@@YQXXZ`|

Use extern "C" para chamar uma função de C do C++. Extern "C" força o uso da convenção de nomenclatura de C para funções de C++ não classe. Lembre-se de comutadores de compilador **/Tc** ou **/Tp**, que diz ao compilador para ignorar a extensão de nome de arquivo e compile o arquivo como C ou C++, respectivamente. Essas opções podem causar nomes que você não espera.

Ter protótipos de função que têm parâmetros incompatíveis também pode causar esse erro. Decoração de nome incorpora o nome decorado de função final os parâmetros de uma função. Chamar uma função com os tipos de parâmetro que não correspondem na declaração de função também pode causar LNK2001.

Atualmente, há um padrão de nomenclatura entre fornecedores de compilador ou até mesmo entre diferentes versões de um compilador de C++. Arquivos de objeto compilados com outros compiladores de vinculação, portanto, talvez não produza o mesmo esquema de nomenclatura e, portanto, faz com que externos não resolvidos.

## <a name="see-also"></a>Consulte também

[Erro das ferramentas de vinculador LNK2001](../../error-messages/tool-errors/linker-tools-error-lnk2001.md)