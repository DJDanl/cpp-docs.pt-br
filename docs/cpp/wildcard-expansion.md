---
title: Expansão de curinga | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _setargv
dev_langs:
- C++
helpviewer_keywords:
- asterisk wildcard
- _setargv function
- command line [C++], processing arguments
- command line [C++], wildcards
- command-line wildcards
- question mark, wildcard
ms.assetid: 1a543398-607b-4404-93d1-45d290bde638
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cac6b61176b1559ea5810dc061638642926b3969
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46077068"
---
# <a name="wildcard-expansion"></a>Expansão de curinga

## <a name="microsoft-specific"></a>Específico da Microsoft

Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.

Argumentos de linha de comando são tratados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de caractere largo), que, por padrão, não expande curingas em cadeias de caracteres separadas no `argv` matriz de cadeia de caracteres. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[main: inicialização do programa](../cpp/main-program-startup.md)