---
title: Aviso RC4093 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC4093
helpviewer_keywords:
- RC4093
ms.assetid: 3c61b4a4-b418-465b-a4fd-cb1ff0adb8dd
ms.openlocfilehash: 29d24f1e380f5c531e170e5dc23cf5c77eefb874
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182286"
---
# <a name="resource-compiler-warning-rc4093"></a>Aviso RC4093 (compilador de recurso)

nova linha sem escape na constante de caractere no código inativo

A expressão constante de uma diretiva de pré-processador `#if`, `#elif`, **#ifdef**ou **#ifndef** avaliada como zero, tornando o código que segue inativo. Dentro desse código inativo, um caractere de nova linha aparece dentro de um conjunto de aspas simples ou duplas.

Todo o texto até a próxima marca de aspas duplas foi considerado dentro de uma constante de caractere.
