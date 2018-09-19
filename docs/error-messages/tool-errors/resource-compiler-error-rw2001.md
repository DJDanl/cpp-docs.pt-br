---
title: RW2001 de erro do compilador de recurso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- RW2001
dev_langs:
- C++
helpviewer_keywords:
- RW2001
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f401ce7c9a96cfeecf195b8872a704b8b1291939
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46114976"
---
# <a name="resource-compiler-error-rw2001"></a>Erro RW2001 (compilador de recurso)

Diretiva inválida no arquivo RC pré-processado

O arquivo RC contém um **#pragma** diretiva.

Use o **#ifndef** diretiva de pré-processador com a **RC_INVOKED** constante que o compilador de recurso define quando ele processa um arquivo de inclusão. Local do **#pragma** diretiva dentro de um bloco de código que não é processado quando o **RC_INVOKED** constante é definida. Código no bloco é processado apenas pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:

```
#ifndef RC_INVOKED
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler
#endif
```

O **#pragma** diretiva de pré-processador não tem nenhum significado um. Arquivo RC. O **#include** diretiva de pré-processador é usada frequentemente em um. Arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado no projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Alguns deles incluem arquivos contêm o **#pragma** diretiva. Como um arquivo de cabeçalho pode incluir um ou mais outros arquivos de cabeçalho, o arquivo que contém problemático **#pragma** diretiva pode não ser imediatamente óbvia.

O **#ifndef RC_INVOKED** técnica pode controlar, incluindo arquivos de cabeçalho nos arquivos de cabeçalho baseada em projeto.