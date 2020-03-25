---
title: Erro do compilador C3251
ms.date: 11/04/2016
f1_keywords:
- C3251
helpviewer_keywords:
- C3251
ms.assetid: 541c163e-5ee9-457c-a1e5-da860788b10d
ms.openlocfilehash: 52f7766601a06385577a0093883b85d9432d1a89
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201468"
---
# <a name="compiler-error-c3251"></a>Erro do compilador C3251

Não é possível invocar o método de classe base em uma instância de tipo de valor

O erro a seguir ocorre porque `GetClass` é um membro de `Microsoft.Runtime.Object`, não de `Microsoft.Runtime.Integer4`.
