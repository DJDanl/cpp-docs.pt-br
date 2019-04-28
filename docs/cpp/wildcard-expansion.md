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
ms.openlocfilehash: 2d495f94f2e3fb7b88d235edc7b98f8e90775393
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62209509"
---
# <a name="wildcard-expansion"></a>Expansão de curinga

## <a name="microsoft-specific"></a>Específico da Microsoft

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Argumentos de linha de comando são tratados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de caractere largo), que, por padrão, não expande curingas em cadeias de caracteres separadas no `argv` matriz de cadeia de caracteres. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização de programa](../cpp/main-program-startup.md)