---
title: Erro do compilador C2338
ms.date: 11/04/2016
f1_keywords:
- C2338
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
ms.openlocfilehash: 2a76ecaf78b117b0c1acabd9fcd50c9ae0f73b98
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51332056"
---
# <a name="compiler-error-c2338"></a>Erro do compilador C2338

> *mensagem de erro*

Esse erro pode ser causado por um `static_assert` erro durante a compilação. A mensagem é fornecida pelo `static_assert` parâmetros.

Essa mensagem de erro também pode ser gerada por provedores externos para o compilador. Na maioria dos casos, esses erros são relatados por um provedor de atributo DLL, como ATLPROV. Algumas formas comuns dessa mensagem incluem:

- '*atributo*' provedor de atributo Atl: erro ATL*número* *mensagem*

- Uso incorreto do atributo '*atributo*'

- '*uso*': formato incorreto para o atributo 'uso'

Esses erros geralmente são irrecuperáveis e podem ser seguidos por um erro fatal do compilador.

Para corrigir esses problemas, corrija o uso do atributo. Por exemplo, em alguns casos, os parâmetros de atributo devem ser declarados antes que possam ser usados. Se for fornecido um número de erro do ATL, verifique a documentação para esse erro para obter informações mais específicas.
