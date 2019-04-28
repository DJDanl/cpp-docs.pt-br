---
title: Erro do compilador C2439
ms.date: 11/04/2016
f1_keywords:
- C2439
helpviewer_keywords:
- C2439
ms.assetid: 3c5dbe5c-b7d3-4bb0-8619-92f6e280461e
ms.openlocfilehash: f71112d3f37f3e4d1a4f41bade95726d7aa0a0bc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62311721"
---
# <a name="compiler-error-c2439"></a>Erro do compilador C2439

'identifier': membro não pôde ser inicializado

Uma classe, estrutura ou membro de união não pode ser inicializado.

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. Tentando inicializar uma estrutura ou classe base indireta.

1. Tentando inicializar um membro herdado de uma classe ou estrutura. Um membro herdado deve ser inicializado pelo construtor de classe ou estrutura.