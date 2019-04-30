---
title: Erro fatal C1054
ms.date: 11/04/2016
f1_keywords:
- C1054
helpviewer_keywords:
- C1054
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
ms.openlocfilehash: 0bfd0c03378b1a9c616a014ac96153b3ab04af9d
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64344792"
---
# <a name="fatal-error-c1054"></a>Erro fatal C1054

limite do compilador: inicializadores com aninhamento muito profundo

O código excede o limite de aninhamento inicializadores (10 a 15 níveis, dependendo da combinação de tipos que está sendo inicializado).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Simplifique os tipos de dados que está sendo inicializados para reduzir o aninhamento.

1. Inicialize variáveis em instruções separadas depois da declaração.