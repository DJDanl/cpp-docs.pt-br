---
title: Aviso RC4005 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC4005
helpviewer_keywords:
- RC4005
ms.assetid: 71f03b4a-c9a9-415d-920f-bf2e58507f93
ms.openlocfilehash: c428fefa90cceed6a8bc9b7f6e4b95ec2db5e039
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80182403"
---
# <a name="resource-compiler-warning-rc4005"></a>Aviso RC4005 (compilador de recurso)

' identificador ': redefinição de macro

O identificador é definido duas vezes. O compilador usou a segunda definição de macro.

Esse aviso pode ser causado pela definição de uma macro na linha de comando e no código com uma diretiva `#define`. Ele também pode ser causado por macros importadas de arquivos de inclusão.

Para eliminar o aviso, remova uma das definições ou use uma diretiva de `#undef` antes da segunda definição.
