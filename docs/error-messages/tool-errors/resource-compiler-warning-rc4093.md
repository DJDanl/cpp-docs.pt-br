---
title: Aviso RC4093 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC4093
helpviewer_keywords:
- RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
ms.openlocfilehash: 23bf436e6e8338f89bc576564181c84715028332
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62346204"
---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)

sem escape newline em constante de caractere no código inativo

A expressão de constante de um `#if`, `#elif`, **#ifdef**, ou **#ifndef** diretiva de pré-processador foi avaliada como zero, tornando o código que segue inativo. Dentro desse código inativo, um caractere de nova linha aparecia dentro de um conjunto de aspas simples ou duplas.

Todo o texto até a próxima marca de aspas duplas foi considerado dentro de uma constante de caractere.