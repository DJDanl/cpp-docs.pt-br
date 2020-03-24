---
title: Erro fatal RC1120 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC1120
helpviewer_keywords:
- RC1120
ms.assetid: 4e462931-e42e-42e3-8bfc-847677194286
ms.openlocfilehash: 855a76ff63145695a7063944701d7acc684e0084
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80173004"
---
# <a name="resource-compiler-fatal-error-rc1120"></a>Erro fatal RC1120 (compilador de recurso)

memória insuficiente, bytes de número necessários

O compilador de recursos ficou sem armazenamento para os itens que ele armazena em seu heap. Geralmente, esse é o resultado de ter muitos símbolos.

### <a name="to-fix-by-using-the-following-possible-solutions"></a>Para corrigir usando as seguintes soluções possíveis

1. Aumente o espaço do arquivo de permuta do Windows. Para obter mais informações sobre como aumentar o espaço do arquivo de permuta, consulte a ajuda da memória virtual no Windows.

1. Elimine arquivos de inclusão desnecessários, especialmente desnecessários `#define`s e protótipos de função.

1. Dividir o arquivo atual em dois ou mais arquivos e compilá-los separadamente.

1. Remova outros programas ou drivers em execução no sistema, o que pode estar consumindo quantidades significativas de memória.
