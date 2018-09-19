---
title: Erro fatal C1091 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1091
dev_langs:
- C++
helpviewer_keywords:
- C1091
ms.assetid: 812d4201-9154-48b0-b9af-5959c082ca33
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e93c2e6c26f8704e700465fb706867129847a460
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46104226"
---
# <a name="fatal-error-c1091"></a>Erro fatal C1091

limite do compilador: cadeia de caracteres excede bytes 'length' de comprimento

Uma constante de cadeia de caracteres excedeu o limite atual de comprimento de cadeias de caracteres.

Você talvez queira dividir a cadeia de caracteres estática em variáveis de dois (ou mais) e usar [strcpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md) para unir o resultado como parte da declaração ou durante o tempo de execução.