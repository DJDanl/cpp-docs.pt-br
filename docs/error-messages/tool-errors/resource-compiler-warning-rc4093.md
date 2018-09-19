---
title: RC4093 de aviso do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC4093
dev_langs:
- C++
helpviewer_keywords:
- RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9b1ca04b17ebdb9d48bc94032482caf48ad4aa00
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46111557"
---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)

sem escape newline em constante de caractere no código inativo

A expressão de constante de um `#if`, `#elif`, **#ifdef**, ou **#ifndef** diretiva de pré-processador foi avaliada como zero, tornando o código que segue inativo. Dentro desse código inativo, um caractere de nova linha aparecia dentro de um conjunto de aspas simples ou duplas.

Todo o texto até a próxima marca de aspas duplas foi considerado dentro de uma constante de caractere.