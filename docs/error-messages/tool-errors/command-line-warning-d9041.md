---
title: Aviso D9041 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9041
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
ms.openlocfilehash: 2311c61c4d661d58302308f06b08971f94cdacab
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816302"
---
# <a name="command-line-warning-d9041"></a>Aviso D9041 (linha de comando)

valor inválido 'value' para '/ opção'; Supondo que o 'valor'; Adicione ' /ANALYZE ' às opções de linha de comando quando especificar este aviso

Um número de aviso de análise de código foi adicionado para o **/wd**, **/we**, **/wo**, ou **/wl** opção de linha de comando sem especificar também o **/ANALYZE** opção de linha de comando. Para corrigir esse erro, adicione a **/ANALYZE** opção de linha de comando, ou remover o número de aviso inválido de apropriado **/w** opção de linha de comando.

## <a name="example"></a>Exemplo

O exemplo de linha de comando a seguir gera o aviso D9041:

```
cl /EHsc /LD /wd6001 filename.cpp
```

Para corrigir o aviso, adicione a **/ANALYZE** opção de linha de comando. Se **/ANALYZE** não é compatível com sua versão do compilador, remova o número de aviso inválido da **/wd** opção.

## <a name="see-also"></a>Consulte também

[Erros de linha de comando D8000 a D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)<br/>
[Opções do compilador MSVC](../../build/reference/compiler-options.md)