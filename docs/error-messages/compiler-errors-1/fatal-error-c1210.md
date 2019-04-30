---
title: Erro fatal C1210
ms.date: 11/04/2016
f1_keywords:
- C1210
helpviewer_keywords:
- C1210
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
ms.openlocfilehash: a90ca3e3b55642f1a6cd847997b83e4b7db46818
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385843"
---
# <a name="fatal-error-c1210"></a>Erro fatal C1210

> /CLR: pure e /CLR: safe não são suportados pela versão do tempo de execução instalado

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

C1210 ocorre quando você tem um compilador para a versão atual, mas um common language runtime de uma versão anterior.

Algumas funcionalidades do compilador podem não funcionar em uma versão anterior do tempo de execução.

Para resolver C1210 instale a versão common language runtime que é destinado para uso com o compilador.