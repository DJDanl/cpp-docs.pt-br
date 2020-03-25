---
title: Erro fatal C1054
ms.date: 11/04/2016
f1_keywords:
- C1054
helpviewer_keywords:
- C1054
ms.assetid: 9cfb7307-b22a-4418-b7c0-2621b0ab5b1b
ms.openlocfilehash: d094d0892d43a5f9894f03538f72e59b57bad6db
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204458"
---
# <a name="fatal-error-c1054"></a>Erro fatal C1054

limite do compilador: inicializadores com aninhamento muito profundo

O código excede o limite de aninhamento em inicializadores (10-15 níveis, dependendo da combinação de tipos que estão sendo inicializados).

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Simplifique os tipos de dados que estão sendo inicializados para reduzir o aninhamento.

1. Inicialize variáveis em instruções separadas após a declaração.
