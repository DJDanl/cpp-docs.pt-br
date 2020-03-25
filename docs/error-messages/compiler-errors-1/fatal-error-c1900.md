---
title: Erro fatal C1900
ms.date: 11/04/2016
f1_keywords:
- C1900
helpviewer_keywords:
- C1900
ms.assetid: 3aaa583b-4c1a-45de-aa34-527d806f2cb5
ms.openlocfilehash: 6a802928315126b72397ba6e8cc61b66f46deb41
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202834"
---
# <a name="fatal-error-c1900"></a>Erro fatal C1900

> Incompatibilidade de Il entre '*Tool1*' versão '*Número1*' e '*tool2*' versão '*número2*'

As ferramentas executadas em vários passos do compilador não correspondem. *núm1* e *núm2* referem-se às datas nos arquivos. Por exemplo, na etapa 1, o front-end do compilador é executado (c1.dll) e na etapa 2, o back-end do compilador é executado (c2.dll). As datas nos arquivos devem ser correspondentes.

Para corrigir esse problema, certifique-se de que todas as atualizações foram aplicadas ao Visual Studio. Se o problema persistir, use **programas e recursos** no painel de controle do Windows para reparar ou reinstalar o Visual Studio.
