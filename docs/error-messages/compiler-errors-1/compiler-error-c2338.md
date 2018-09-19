---
title: Erro do compilador C2338 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2338
dev_langs:
- C++
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 77bc98afdad36e0505abb58ee06ec1c7e7654ae5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46071569"
---
# <a name="compiler-error-c2338"></a>Erro do compilador C2338

> *mensagem de erro*

Esse erro pode ser causado por um `static_assert` erro durante a compilação. A mensagem é fornecida pelo `static_assert` parâmetros.

Essa mensagem de erro também pode ser gerada por provedores externos para o compilador. Na maioria dos casos, esses erros são relatados por um provedor de atributo DLL, como ATLPROV. Algumas formas comuns dessa mensagem incluem:

> '*atributo*' provedor de atributo Atl: erro ATL*número* *mensagem*

> Uso incorreto do atributo '*atributo*'

> '*uso*': formato incorreto para o atributo 'uso'

Esses erros geralmente são irrecuperáveis e podem ser seguidos por um erro fatal do compilador.

Para corrigir esses problemas, corrija o uso do atributo. Por exemplo, em alguns casos, os parâmetros de atributo devem ser declarados antes que possam ser usados. Se for fornecido um número de erro do ATL, verifique a documentação para esse erro para obter informações mais específicas.
