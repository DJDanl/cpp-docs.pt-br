---
title: Expansão de curinga
ms.date: 11/04/2016
f1_keywords:
- _setargv
helpviewer_keywords:
- asterisk wildcard
- _setargv function
- command line [C++], processing arguments
- command line [C++], wildcards
- command-line wildcards
- question mark, wildcard
ms.assetid: 1a543398-607b-4404-93d1-45d290bde638
ms.openlocfilehash: 1fdea297bb45a06a08bde4f63f90eabef6ddb539
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857171"
---
# <a name="wildcard-expansion"></a>Expansão de curinga

**Seção específica da Microsoft**

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Os argumentos de linha de comando são manipulados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de caracteres largos), que por padrão não expande curingas em cadeias de caracteres separadas na matriz de cadeia `argv`. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)