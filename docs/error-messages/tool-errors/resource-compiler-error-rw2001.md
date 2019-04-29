---
title: Erro RW2001 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW2001
helpviewer_keywords:
- RW2001
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
ms.openlocfilehash: 4d298cdd9d96c55f283ce7f0e2ba04dd664941f8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62226498"
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