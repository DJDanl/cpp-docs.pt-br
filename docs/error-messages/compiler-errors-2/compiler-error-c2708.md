---
title: Erro do compilador C2708
ms.date: 11/04/2016
f1_keywords:
- C2708
helpviewer_keywords:
- C2708
ms.assetid: d52d3088-1141-42f4-829c-74755a7fcc3a
ms.openlocfilehash: a128613cabb201142c29b833959924dbf8a6e0ba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50460067"
---
# <a name="compiler-error-c2708"></a>Erro do compilador C2708

'identifier': comprimento em bytes de parâmetros reais difere da chamada anterior ou referência

Um [stdcall](../../cpp/stdcall.md) função deve ser precedida por um protótipo. Caso contrário, o compilador interpreta a primeira chamada para a função como um protótipo e esse erro ocorre quando o compilador encontra uma chamada que não corresponde.

Para corrigir esse erro adicione um protótipo de função.