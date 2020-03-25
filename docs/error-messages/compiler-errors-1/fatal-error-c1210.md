---
title: Erro fatal C1210
ms.date: 11/04/2016
f1_keywords:
- C1210
helpviewer_keywords:
- C1210
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
ms.openlocfilehash: 50bafa522c931c909b5ce163a78305ffc028765a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203379"
---
# <a name="fatal-error-c1210"></a>Erro fatal C1210

> /CLR: Pure e/CLR: safe não são suportados pela versão do tempo de execução instalada

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

C1210 ocorre quando você tem um compilador para a versão atual, mas uma Common Language Runtime de uma versão anterior.

Algumas funcionalidades do compilador podem não funcionar em uma versão anterior do tempo de execução.

Para resolver o C1210, instale a versão Common Language Runtime destinada ao uso com seu compilador.
