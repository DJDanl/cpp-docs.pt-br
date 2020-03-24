---
title: Erro M6203 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6203
helpviewer_keywords:
- M6203
ms.assetid: bd7fdd1c-83e4-4d6a-901e-10a0308bf5be
ms.openlocfilehash: 371a6c673826c6ce71d7a0eb3b9e08d9488f53f5
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193687"
---
# <a name="math-error-m6203"></a>Erro M6203 (Math)

' function ': erro de _OVERFLOW

O resultado da função fornecido era muito grande para ser representado.

Esse erro chama a função `_matherr` com o nome da função, seus argumentos e o tipo de erro. Você pode reescrever a função `_matherr` para personalizar o tratamento de determinados erros de matemática de ponto flutuante de tempo de execução.
