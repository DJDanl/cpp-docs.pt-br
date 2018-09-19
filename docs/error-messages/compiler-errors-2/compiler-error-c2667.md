---
title: Erro do compilador C2667 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2667
dev_langs:
- C++
helpviewer_keywords:
- C2667
ms.assetid: 3c91d9d1-18fa-4e0d-a9ba-984d38980ca3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5d6d14cf04ae399b10cbaa393d9e9fcc7133f274
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46095242"
---
# <a name="compiler-error-c2667"></a>Erro do compilador C2667

'function': nenhuma das sobrecargas número possui uma conversão melhor

Uma chamada de função sobrecarregada é ambígua e não pode ser resolvida.

A conversão necessária para corresponder aos parâmetros na chamada de função para uma das funções sobrecarregadas reais deve ser estritamente melhor do que as conversões necessárias por todas as outras funções sobrecarregadas.

Consulte o artigo da Base de dados de Conhecimento Q240869 para obter mais informações sobre ordenação parcial de modelos de função.