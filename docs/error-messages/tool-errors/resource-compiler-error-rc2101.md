---
title: RC2101 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RC2101
dev_langs:
- C++
helpviewer_keywords:
- RC2101
ms.assetid: 580f9d74-162f-41e9-9438-ddbe3457c359
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 196806e6d2767c889ae96d239af69113c542ba6c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46034753"
---
# <a name="resource-compiler-error-rc2101"></a>Erro RC2101 (compilador de recurso)

Diretiva inválida no arquivo RC pré-processado

O arquivo de compilador de recurso contém um **#pragma** diretiva.

Use o **#ifndef** diretiva de pré-processador com a constante RC_INVOKED que o compilador de recurso define quando ele processa um arquivo de inclusão. Coloque o **#pragma** diretiva dentro de um bloco de código que não é processado quando a constante RC_INVOKED é definida. Código no bloco é processado apenas pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:

```
#ifndef RC_INVOKED
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler
#endif
```

O **#pragma** diretiva de pré-processador não tem nenhum significado um. Arquivo RC. O **#include** diretiva de pré-processador é usada frequentemente em um. Arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado no projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Alguns deles incluem arquivos contêm o **#pragma** diretiva. Como um arquivo de cabeçalho pode incluir um ou mais outros arquivos de cabeçalho, o arquivo que contém problemático **#pragma** diretiva pode não ser imediatamente óbvia.

O **#ifndef** técnica RC_INVOKED pode controlar, incluindo arquivos de cabeçalho nos arquivos de cabeçalho baseada em projeto.