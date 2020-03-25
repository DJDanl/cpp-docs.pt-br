---
title: Erro fatal C1002
ms.date: 11/04/2016
f1_keywords:
- C1002
helpviewer_keywords:
- C1002
ms.assetid: bd6d274a-c7b4-43af-8bf2-23c5e442aa22
ms.openlocfilehash: 78edf886f34665f996497abe323a0ea5d3800c2d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80204926"
---
# <a name="fatal-error-c1002"></a>Erro fatal C1002

o compilador está sem espaço de heap na passagem 2

O compilador ficou sem espaço de memória dinâmica durante seu segundo passo, provavelmente devido a um programa com muitos símbolos ou expressões complexas.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Divida o arquivo de origem em vários arquivos menores.

1. Quebre expressões em subexpressões menores.

1. Remova outros programas ou drivers que consomem memória.
