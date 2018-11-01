---
title: Erro do compilador C2338
ms.date: 11/04/2016
f1_keywords:
- C2338
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
ms.openlocfilehash: 4ca3feb2a71efa60229afdbf918109a5d5d59cad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539584"
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
