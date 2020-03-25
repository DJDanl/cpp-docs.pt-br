---
title: Erro RW2001 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RW2001
helpviewer_keywords:
- RW2001
ms.assetid: 963bdc7d-6ebe-4378-8bbc-47dfcf5d330c
ms.openlocfilehash: 900bfed9d57af0f6f5dd8fac19380bb7c382addc
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190736"
---
# <a name="resource-compiler-error-rw2001"></a>Erro RW2001 (compilador de recurso)

Diretiva inválida no arquivo RC pré-processado

O arquivo RC contém uma diretiva **#pragma** .

Use a diretiva de pré-processador de **#ifndef** com a constante **RC_INVOKED** que o compilador de recursos define quando processa um arquivo de inclusão. Coloque a diretiva **#pragma** dentro de um bloco de código que não é processado quando a constante de **RC_INVOKED** é definida. O código no bloco é processado somente pelo compilador C/C++ e não pelo compilador de recurso. O código de exemplo a seguir demonstra essa técnica:

```
#ifndef RC_INVOKED
#pragma pack(2)  // C/C++ only, ignored by Resource Compiler
#endif
```

A diretiva de pré-processador de **#pragma** não tem nenhum significado em um. Arquivo RC. A diretiva de pré-processador de **#include** é usada com frequência em um. O arquivo RC para incluir um arquivo de cabeçalho (um arquivo de cabeçalho personalizado baseado em projeto ou um arquivo de cabeçalho padrão fornecido pela Microsoft com um de seus produtos). Alguns desses incluem arquivos contêm a diretiva **#pragma** . Como um arquivo de cabeçalho pode incluir um ou mais arquivos de cabeçalho, o arquivo que contém a diretiva de **#pragma** incorreta pode não ser imediatamente óbvio.

A técnica de **RC_INVOKED #ifndef** pode controlar a inclusão de arquivos de cabeçalho em arquivos de cabeçalho baseados em projeto.
