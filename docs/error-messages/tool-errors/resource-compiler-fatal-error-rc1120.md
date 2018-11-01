---
title: Erro fatal RC1120 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC1120
helpviewer_keywords:
- RC1120
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
ms.openlocfilehash: eff46ddee118c3355e548c73220b407db0561e36
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614910"
---
# <a name="resource-compiler-fatal-error-rc1120"></a>Erro fatal RC1120 (compilador de recurso)

sem memória, bytes de números de necessário

O compilador de recurso insuficiente de armazenamento para os itens que ele armazena em seu heap. Normalmente, esse é o resultado de ter muitos símbolos.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Aumente o espaço de arquivo de permuta do Windows. Para obter mais informações sobre como aumentar o espaço de arquivo de permuta, consulte memória virtual na Ajuda do Windows.

1. Eliminar desnecessário incluir arquivos, especialmente desnecessários `#define`s protótipos de função.

1. Dividir o arquivo atual em dois ou mais arquivos e compilá-los separadamente.

1. Remova outros programas ou drivers em execução no sistema, o que poderia estar consumindo quantidades significativas de memória.