---
title: Erro M6203 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6203
dev_langs:
- C++
helpviewer_keywords:
- M6203
ms.assetid: bd7fdd1c-83e4-4d6a-901e-10a0308bf5be
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d8474c91802b4756207676c466fdd28d66d911b3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46022663"
---
# <a name="math-error-m6203"></a>Erro M6203 (Math)

'function': erro de overflow

O resultado da função fornecida era muito grande para ser representado.

Esse erro chama o `_matherr` função com o nome da função, seus argumentos e o tipo de erro. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.