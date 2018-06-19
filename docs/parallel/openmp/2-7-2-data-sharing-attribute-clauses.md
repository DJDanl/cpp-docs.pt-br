---
title: 2.7.2 atributo de compartilhamento de dados cláusulas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 47347d3c-18bd-441f-99cf-7737564c417f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ecc6efac6e3d7356e51dc0ec57009ca9e5a71890
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33691893"
---
# <a name="272-data-sharing-attribute-clauses"></a>2.7.2 Cláusulas de atributo de compartilhamento de dados
Várias diretivas aceitam cláusulas que permitem que um usuário controlar os atributos de compartilhamento de variáveis para a duração da região. Compartilhamento cláusulas de atributo se aplica somente a variáveis na extensão de léxica da diretiva na qual a cláusula é exibida. Nem todas as cláusulas a seguir são permitidas em todas as diretivas. A lista de cláusulas que são válidos em uma determinada diretiva são descritos com a diretiva.  
  
 Se uma variável é visível quando um paralelo ou construção de compartilhamento de trabalho for encontrada e a variável não for especificada em uma cláusula de atributo compartilhamento ou **threadprivate** diretiva, em seguida, a variável é compartilhada. Variáveis estáticas declaradas dentro a extensão dinâmica de uma região parallel são compartilhadas. Heap de memória alocada (por exemplo, usando **malloc** em C ou C++ ou **novo** operador em C++) é compartilhado. (O ponteiro de memória, no entanto, pode ser privada ou compartilhado.) Variáveis com duração de armazenamento automático declarada dentro a extensão dinâmica de uma região parallel são privadas.  
  
 A maioria das cláusulas de aceita um *lista variável* argumento, que é uma lista separada por vírgulas de variáveis que estão visíveis. Se uma variável referenciada em uma cláusula de compartilhamento de dados de atributo tem um tipo derivado de um modelo e existem outras referências a essa variável no programa, o comportamento será indefinido.  
  
 Todas as variáveis que aparecem em cláusulas de diretiva devem ser visíveis. As cláusulas podem ser repetidas, conforme necessário, mas nenhuma variável pode ser especificado mais de uma cláusula, exceto pelo fato de uma variável pode ser especificada em ambos um **firstprivate** e um **lastprivate** cláusula.  
  
 As seções a seguir descrevem as cláusulas de compartilhamento de dados de atributo:  
  
-   **privada**, [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25.  
  
-   **firstprivate**, [seção 2.7.2.2](../../parallel/openmp/2-7-2-2-firstprivate.md) na página 26.  
  
-   **lastprivate**, [seção 2.7.2.3](../../parallel/openmp/2-7-2-3-lastprivate.md) na página 27.  
  
-   **compartilhado**, [seção 2.7.2.4](../../parallel/openmp/2-7-2-4-shared.md) na página 27.  
  
-   **padrão**, [seção 2.7.2.5](../../parallel/openmp/2-7-2-5-default.md) na página 28.  
  
-   **redução**, [seção 2.7.2.6](../../parallel/openmp/2-7-2-6-reduction.md) na página 28.  
  
-   **copyin**, [seção 2.7.2.7](../../parallel/openmp/2-7-2-7-copyin.md) página 31.  
  
-   **copyprivate**, [seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32.