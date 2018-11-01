---
title: 2.7.2 Cláusulas de atributo de compartilhamento de dados
ms.date: 11/04/2016
ms.assetid: 47347d3c-18bd-441f-99cf-7737564c417f
ms.openlocfilehash: 4c9209a4d627c6212087b621b223a3fb81b48ce3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559647"
---
# <a name="272-data-sharing-attribute-clauses"></a>2.7.2 Cláusulas de atributo de compartilhamento de dados

Várias diretivas aceitam as cláusulas que permitem que um usuário controlar os atributos de compartilhamento de variáveis para a duração da região. Cláusulas de atributo de compartilhamento se aplicam somente a variáveis na extensão de léxico da diretiva na qual a cláusula é exibida. Nem todas as cláusulas a seguir são permitidas em todas as diretivas. A lista de cláusulas que são válidos em uma determinada diretiva são descritas com a diretiva.

Se uma variável é visível quando um paralelo ou construção de compartilhamento de trabalho for encontrada e a variável não for especificada em uma cláusula de atributo de compartilhamento ou **threadprivate** diretiva, em seguida, a variável é compartilhada. Variáveis estáticas declaradas dentro de extensão dinâmica de uma região paralela são compartilhadas. A memória alocado do heap (por exemplo, usando **malloc ()** em C ou C++ ou o **novos** operador em C++) é compartilhado. (O ponteiro para essa memória, no entanto, pode ser particulares ou compartilhados.) Variáveis com duração de armazenamento automático declarada dentro de extensão dinâmica de uma região paralela são privadas.

A maioria das cláusulas de aceita um *lista variável* argumento, que é uma lista separada por vírgulas de variáveis que são visíveis. Se uma variável é referenciada em uma cláusula de compartilhamento de dados de atributo tem um tipo derivado de um modelo e existem outras referências a essa variável no programa, o comportamento será indefinido.

Todas as variáveis que aparecem em cláusulas de diretiva devem estar visíveis. As cláusulas podem ser repetidas, conforme necessário, mas nenhuma variável pode ser especificado mais de uma cláusula, exceto pelo fato de uma variável pode ser especificada em ambos um **firstprivate** e uma **lastprivate** cláusula.

As seções a seguir descrevem as cláusulas de atributo de compartilhamento de dados:

- **privado**, [seção 2.7.2.1](../../parallel/openmp/2-7-2-1-private.md) na página 25.

- **firstprivate**, [seção 2.7.2.2](../../parallel/openmp/2-7-2-2-firstprivate.md) na página 26.

- **lastprivate**, [seção 2.7.2.3](../../parallel/openmp/2-7-2-3-lastprivate.md) na página 27.

- **compartilhado**, [seção 2.7.2.4](../../parallel/openmp/2-7-2-4-shared.md) na página 27.

- **padrão**, [seção 2.7.2.5](../../parallel/openmp/2-7-2-5-default.md) na página 28.

- **redução**, [seção 2.7.2.6](../../parallel/openmp/2-7-2-6-reduction.md) na página 28.

- **copyin**, [seção 2.7.2.7](../../parallel/openmp/2-7-2-7-copyin.md) página 31.

- **copyprivate**, [seção 2.7.2.8](../../parallel/openmp/2-7-2-8-copyprivate.md) na página 32.