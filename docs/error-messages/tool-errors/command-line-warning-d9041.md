---
title: Aviso D9041 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9041
helpviewer_keywords:
- D9041
ms.assetid: ada8815f-4246-4e25-b57d-a7f16fa107cc
ms.openlocfilehash: 7c685a1ca3195ad4ab52bab8b5d32b1a51534b24
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196569"
---
# <a name="command-line-warning-d9041"></a>Aviso D9041 (linha de comando)

valor inválido ' value ' para '/Option '; assumindo ' value '; Adicionar '/ANALYZE ' às opções de linha de comando ao especificar este aviso

Um número de aviso da análise de código foi adicionado à opção de linha de comando **/WD**, **/We**, **/wo**ou **/WL** sem especificar também a opção de linha de comando **/Analyze** . Para corrigir esse erro, adicione a opção de linha de comando **/Analyze** ou remova o número de aviso inválido da opção de linha de comando **/w** apropriada.

## <a name="example"></a>Exemplo

O exemplo de linha de comando a seguir gera o aviso D9041:

```
cl /EHsc /LD /wd6001 filename.cpp
```

Para corrigir o aviso, adicione a opção de linha de comando **/Analyze** . Se **/Analyze** não for suportado em sua versão do compilador, remova o número de aviso inválido da opção **/WD** .

## <a name="see-also"></a>Confira também

[Erros de linha de comando D8000 a D9999](../../error-messages/tool-errors/command-line-errors-d8000-through-d9999.md)<br/>
[Opções do compilador MSVC](../../build/reference/compiler-options.md)
