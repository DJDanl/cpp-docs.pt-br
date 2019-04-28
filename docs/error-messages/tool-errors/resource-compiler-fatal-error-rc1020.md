---
title: Erro fatal RC1020 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC1020
helpviewer_keywords:
- RC1020
ms.assetid: 3e073ebf-9136-4bf8-ac6a-3c642ed64594
ms.openlocfilehash: ac4a9d521728b22966f6d8824479d13cc7394601
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62297328"
---
# <a name="resource-compiler-fatal-error-rc1020"></a>Erro fatal RC1020 (compilador de recurso)

'#endif' inesperado

Uma `#endif` diretiva apareceu sem encontrar uma correspondência `#if`, **#ifdef**, ou **#ifndef** diretiva.

Certifique-se de que há uma correspondência `#endif` para cada `#if`, **#ifdef**, e **#ifndef** instrução.