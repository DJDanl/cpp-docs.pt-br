---
title: Aviso do compilador (nível 4) C4611
ms.date: 11/04/2016
f1_keywords:
- C4611
helpviewer_keywords:
- C4611
ms.assetid: bd90d0a6-75f9-4e97-968d-dda6773e9fd8
ms.openlocfilehash: 7de4cdf0eacb1b9848a4350f1d223da1fd47d1fc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198296"
---
# <a name="compiler-warning-level-4-c4611"></a>Aviso do compilador (nível 4) C4611

a interação entre a ' função C++ ' e a destruição de objeto não é portátil

Em algumas plataformas, as funções que incluem o **Catch** podem C++ não dar suporte à semântica de objeto de destruição quando fora do escopo.

Para evitar um comportamento inesperado, evite usar funções **Catch** nas que têm construtores e destruidores.

Este aviso é emitido apenas uma vez; consulte o [aviso de pragma](../../preprocessor/warning.md).
