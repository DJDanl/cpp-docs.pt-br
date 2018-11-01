---
title: Erro fatal C1091
ms.date: 11/04/2016
f1_keywords:
- C1091
helpviewer_keywords:
- C1091
ms.assetid: 812d4201-9154-48b0-b9af-5959c082ca33
ms.openlocfilehash: 9758d4b779f4727012041da60632bcea8ce18d42
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50624949"
---
# <a name="fatal-error-c1091"></a>Erro fatal C1091

limite do compilador: cadeia de caracteres excede bytes 'length' de comprimento

Uma constante de cadeia de caracteres excedeu o limite atual de comprimento de cadeias de caracteres.

Você talvez queira dividir a cadeia de caracteres estática em variáveis de dois (ou mais) e usar [strcpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md) para unir o resultado como parte da declaração ou durante o tempo de execução.