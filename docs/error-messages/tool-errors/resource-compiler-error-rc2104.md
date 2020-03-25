---
title: Erro RC2104 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2104
helpviewer_keywords:
- RC2104
ms.assetid: 792a3bd8-cb4c-4817-b288-4ce37082b582
ms.openlocfilehash: d4a06f88e4a73da6b711d108a1f79c14fae0907c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80191633"
---
# <a name="resource-compiler-error-rc2104"></a>Erro RC2104 (compilador de recurso)

palavra-chave ou a nome da chave indefinido: chave

A palavra-chave especificada ou o nome da chave não está definido.

Este erro geralmente é causado por um erro de digitação na definição do recurso ou no arquivo de cabeçalho incluído. Também pode ser causado por um arquivo de cabeçalho ausente.

Para corrigir o problema, localize o arquivo de cabeçalho que deve conter o nome da chave ou a palavra-chave definida e verifique se ele está incluído em seu arquivo de recurso, e se o nome da chave ou a palavra-chave está escrito corretamente. Se o projeto foi criado com um cabeçalho pré-compilado e você subsequentemente o removeu, certifique-se de que o arquivo de recurso ainda inclui quaisquer cabeçalhos necessários.

Para verificar as palavras-chave definidas e os nomes de chaves em seu arquivo de recurso, no Visual Studio, abra a janela **modo de exibição de recursos** — na barra de menus, escolha **Exibir**, **modo de exibição de recursos**— e abra o menu de atalho para o arquivo. rc e escolha **símbolos de recurso** para exibir a lista de símbolos definidos. Para modificar os cabeçalhos incluídos, abra o menu de atalho do arquivo. rc e escolha **recursos incluir**.

Se você encontrar esta mensagem:

```
undefined keyword or key name: MFT_STRING
```

Abra \MCL\MFC\Include\AfxRes.h e adicione esta diretiva de inclusão:

```
#include <winresrc.h>
```
