---
title: Aviso do compilador (níveis 1 e 4) C4115
ms.date: 11/04/2016
f1_keywords:
- C4115
helpviewer_keywords:
- C4115
ms.assetid: f3f94e72-fc49-4d09-b3e7-23d68e61152f
ms.openlocfilehash: 7e39e8c837d94776a804da2bf38643b453edb949
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198036"
---
# <a name="compiler-warning-levels-1-and-4-c4115"></a>Aviso do compilador (níveis 1 e 4) C4115

' type ': definição de tipo nomeado entre parênteses

O símbolo fornecido é usado para definir uma estrutura, União ou tipo enumerado dentro de uma expressão entre parênteses. O escopo da definição pode ser inesperado.

Em uma chamada de função C, a definição tem escopo global. Em uma C++ chamada, a definição tem o mesmo escopo que a função que está sendo chamada.

Esse aviso também pode ser causado por declaradores dentro de parênteses (como protótipos) que não são expressões de parênteses.

Este é um aviso de nível 1 com C++ programas e programas C compilados sob compatibilidade com ANSI (/Za). Caso contrário, será o nível 3.
