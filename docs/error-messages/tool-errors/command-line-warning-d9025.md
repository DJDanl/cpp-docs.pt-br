---
title: Linha de comando D9025 de aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- D9025
dev_langs:
- C++
helpviewer_keywords:
- D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 822d1ac0cc1e6b3e728d43b816e7a0a15eee9958
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46063681"
---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)

substituindo a opção ' 1' com 'option2'

O *option1* opção foi especificada, mas, em seguida, foi substituída pelo *option2*. O *option2* opção foi usada.

Se duas opções especificam diretivas incompatíveis ou contraditórias, a diretiva especificada ou implícita na opção mais à direita na linha de comando é usada.

Se você recebe esse aviso durante a compilação do ambiente de desenvolvimento e não estiver certo de onde as opções conflitantes vêm, considere o seguinte:

- Uma opção pode ser especificada no código ou nas configurações de projeto do projeto. Se você examinar o compilador [páginas de propriedades de linha de comando](../../ide/command-line-property-pages.md) e você vê as opções em conflito na **todas as opções** e em seguida, as opções são definidas nas páginas de propriedades do projeto, caso contrário, as opções de campo são definidas no código-fonte.

     Se as opções são definidas nas páginas de propriedades do projeto, procure na página de propriedade de pré-processador do compilador (com o nó do projeto selecionado no Gerenciador de soluções).  Se você não vir a opção definida lá, verifique as configurações de página de propriedades de pré-processador para cada arquivo de código de origem (no Gerenciador de soluções) se não for adicionado lá.

     Se as opções são definidas no código, ele poderia ser definido no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo pré-processado ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.