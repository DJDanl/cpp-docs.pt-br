---
title: Erro do compilador C2338
ms.date: 11/04/2016
f1_keywords:
- C2338
helpviewer_keywords:
- C2338
ms.assetid: 49bba575-1de4-4963-86c6-ce3226a2ba51
ms.openlocfilehash: c92a95b97cb4c57d3ad5cfbf8fe1d9980d5362cd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221205"
---
# <a name="compiler-error-c2338"></a>Erro do compilador C2338

> *Mensagem de erro*

Esse erro pode ser causado por um **`static_assert`** erro durante a compilação. A mensagem é fornecida pelos **`static_assert`** parâmetros.

Essa mensagem de erro também pode ser gerada por provedores externos para o compilador. Na maioria dos casos, esses erros são relatados por uma DLL de provedor de atributo, como ATLPROV. Algumas formas comuns dessa mensagem incluem:

- Provedor de atributo ATL '*Attribute*': erro de *mensagem* de*número* ATL

- Uso incorreto do atributo '*Attribute*'

- '*Usage*': formato incorreto para o atributo ' Usage '

Esses erros geralmente são irrecuperáveis e podem ser seguidos por um erro fatal do compilador.

Para corrigir esses problemas, corrija o uso do atributo. Por exemplo, em alguns casos, os parâmetros de atributo devem ser declarados antes que possam ser usados. Se um número de erro ATL for fornecido, verifique a documentação desse erro para obter informações mais específicas.
