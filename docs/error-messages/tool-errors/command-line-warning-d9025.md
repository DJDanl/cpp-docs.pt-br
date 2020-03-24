---
title: Aviso D9025 (linha de comando)
ms.date: 11/04/2016
f1_keywords:
- D9025
helpviewer_keywords:
- D9025
ms.assetid: 6edff72c-1508-46c2-99f4-0e4b3c5e60c9
ms.openlocfilehash: 4afd4d4dc07ffaae6038c025ee371278ebbebea6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80196710"
---
# <a name="command-line-warning-d9025"></a>Aviso D9025 (linha de comando)

substituindo ' opção 1 ' por ' opção 2 '

A opção *opção 1* foi especificada, mas foi substituída por *opção 2*. A opção *opção 2* foi usada.

Se duas opções especificarem diretivas contraditórias ou incompatíveis, a diretiva especificada ou implícita na opção mais distante à direita na linha de comando será usada.

Se você receber esse aviso ao compilar do ambiente de desenvolvimento e não tiver certeza de onde as opções conflitantes são provenientes, considere o seguinte:

- Uma opção pode ser especificada no código ou nas configurações do projeto do projeto. Se você examinar as [páginas de propriedades de linha de comando](../../build/reference/command-line-property-pages.md) do compilador e se vir as opções conflitantes no campo todas as **Opções** , as opções serão definidas nas páginas de propriedades do projeto, caso contrário, as opções serão definidas no código-fonte.

   Se as opções forem definidas nas páginas de propriedades do projeto, examine a página de propriedades do pré-processador do compilador (com o nó do projeto selecionado na Gerenciador de Soluções).  Se você não vir a opção definida lá, verifique as configurações da página de propriedades do pré-processador de cada arquivo de código-fonte (em Gerenciador de Soluções) para ter certeza de que ele não foi adicionado lá.

   Se as opções estiverem definidas no código, ele poderá ser definido no código ou nos cabeçalhos do Windows.  Você pode tentar criar um arquivo pré-processado ([/p](../../build/reference/p-preprocess-to-a-file.md)) e pesquisá-lo para o símbolo.
