---
title: Erro fatal C1055
ms.date: 11/04/2016
f1_keywords:
- C1055
helpviewer_keywords:
- C1055
ms.assetid: a9fb9190-d7eb-4d5f-b1a2-a41e584a28c1
ms.openlocfilehash: e6df4870d7af49c369be7e513791955599c48326
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62390640"
---
# <a name="fatal-error-c1055"></a>Erro fatal C1055

limite do compilador: sem chaves

O arquivo de origem contém muitos símbolos. O compilador ficou sem as chaves de hash para a tabela de símbolo.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Divida o arquivo de origem em arquivos menores.

1. Elimine arquivos de cabeçalho desnecessários.

1. Reutilize variáveis temporárias e globais, em vez de criar novos.