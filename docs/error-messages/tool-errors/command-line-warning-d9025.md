---
title: Aviso D9025 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9025
helpviewer_keywords:
- D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
ms.openlocfilehash: fb9ab3152efe565501e91fbad5ebb279c4396968
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652420"
---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)

substituindo a opção ' 1' com 'option2'

O *option1* opção foi especificada, mas, em seguida, foi substituída pelo *option2*. O *option2* opção foi usada.

Se duas opções especificam diretivas incompatíveis ou contraditórias, a diretiva especificada ou implícita na opção mais à direita na linha de comando é usada.

Se você recebe esse aviso durante a compilação do ambiente de desenvolvimento e não estiver certo de onde as opções conflitantes vêm, considere o seguinte:

- Uma opção pode ser especificada no código ou nas configurações de projeto do projeto. Se você examinar o compilador [páginas de propriedades de linha de comando](../../ide/command-line-property-pages.md) e você vê as opções em conflito na **todas as opções** e em seguida, as opções são definidas nas páginas de propriedades do projeto, caso contrário, as opções de campo são definidas no código-fonte.

   Se as opções são definidas nas páginas de propriedades do projeto, procure na página de propriedade de pré-processador do compilador (com o nó do projeto selecionado no Gerenciador de soluções).  Se você não vir a opção definida lá, verifique as configurações de página de propriedades de pré-processador para cada arquivo de código de origem (no Gerenciador de soluções) se não for adicionado lá.

   Se as opções são definidas no código, ele poderia ser definido no código ou nos cabeçalhos do windows.  Você pode tentar criar um arquivo pré-processado ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.