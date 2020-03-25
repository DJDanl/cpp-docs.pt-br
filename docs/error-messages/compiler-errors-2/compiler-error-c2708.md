---
title: Erro do compilador C2708
ms.date: 11/04/2016
f1_keywords:
- C2708
helpviewer_keywords:
- C2708
ms.assetid: d52d3088-1141-42f4-829c-74755a7fcc3a
ms.openlocfilehash: a1d3379a0da42c5aabd38cffbf6f6a3f340ef3b9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80202365"
---
# <a name="compiler-error-c2708"></a>Erro do compilador C2708

' identifier ': o comprimento dos parâmetros reais em bytes difere da chamada ou da referência anterior

Uma função [__stdcall](../../cpp/stdcall.md) deve ser precedida por um protótipo. Caso contrário, o compilador interpretará a primeira chamada para a função como um protótipo e esse erro ocorrerá quando o compilador encontrar uma chamada que não corresponde.

Para corrigir esse erro, adicione um protótipo de função.
