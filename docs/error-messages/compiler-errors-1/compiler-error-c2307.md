---
title: Erro do compilador C2307
ms.date: 11/04/2016
f1_keywords:
- C2307
helpviewer_keywords:
- C2307
ms.assetid: ce6c8033-a673-4679-9883-bedec36ae385
ms.openlocfilehash: 5be197e61e48e47db70e8f23c7ef5b9ade22b1ef
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62303587"
---
# <a name="compiler-error-c2307"></a>Erro do compilador C2307

pragma 'pragma' deve estar fora da função se compilação incremental estiver habilitada

Você deve colocar o `data_seg` pragma entre as funções se você estiver usando a compilação incremental.