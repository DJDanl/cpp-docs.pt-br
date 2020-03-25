---
title: Erro fatal C1091
ms.date: 11/04/2016
f1_keywords:
- C1091
helpviewer_keywords:
- C1091
ms.assetid: 812d4201-9154-48b0-b9af-5959c082ca33
ms.openlocfilehash: 76492be7abab6deb740f1670b85274b8c296c783
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80203886"
---
# <a name="fatal-error-c1091"></a>Erro fatal C1091

limite do compilador: a cadeia de caracteres excede ' comprimento ' bytes de comprimento

Uma constante de cadeia de caracteres excedeu o limite atual no comprimento de cadeias de caracteres.

Talvez você queira dividir a cadeia de caracteres estática em duas (ou mais) variáveis e usar [strcpy_s](../../c-runtime-library/reference/strcpy-s-wcscpy-s-mbscpy-s.md) para unir o resultado como parte da declaração ou durante o tempo de execução.
