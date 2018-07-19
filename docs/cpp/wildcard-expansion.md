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
ms.openlocfilehash: 7f4de54cbbe978534a42dcb9cbfa677eb1597aa5
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939130"
---
# <a name="wildcard-expansion"></a>Expansão de curinga
## <a name="microsoft-specific"></a>Específico da Microsoft  
 Você pode usar caracteres curinga — o ponto de interrogação (?) e o asterisco (*) — para especificar argumentos de nome de arquivo e caminho na linha de comando.  
  
 Argumentos de linha de comando são tratados por uma rotina chamada `_setargv` (ou `_wsetargv` no ambiente de caractere largo), que, por padrão, não expande curingas em cadeias de caracteres separadas no `argv` matriz de cadeia de caracteres. Para obter mais informações sobre como habilitar a expansão de curinga, consulte [expandindo argumentos curinga](../c-language/expanding-wildcard-arguments.md).  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [main: inicialização do programa](../cpp/main-program-startup.md)