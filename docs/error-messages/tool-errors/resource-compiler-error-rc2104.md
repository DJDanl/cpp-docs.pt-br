---
title: Erro RC2104 (compilador de recurso)
ms.date: 11/04/2016
f1_keywords:
- RC2104
helpviewer_keywords:
- RC2104
ms.assetid: 792a3bd8-cb4c-4817-b288-4ce37082b582
ms.openlocfilehash: 6ac1786e795c0c8ed57af2d341f43b8ba39229c4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62346555"
---
# <a name="resource-compiler-error-rc2104"></a>Erro RC2104 (compilador de recurso)

palavra-chave ou a nome da chave indefinido: chave

A palavra-chave especificada ou o nome da chave não está definido.

Este erro geralmente é causado por um erro de digitação na definição do recurso ou no arquivo de cabeçalho incluído. Também pode ser causado por um arquivo de cabeçalho ausente.

Para corrigir o problema, localize o arquivo de cabeçalho que deve conter o nome da chave ou a palavra-chave definida e verifique se ele está incluído em seu arquivo de recurso, e se o nome da chave ou a palavra-chave está escrito corretamente. Se o projeto foi criado com um cabeçalho pré-compilado e você subsequentemente o removeu, certifique-se de que o arquivo de recurso ainda inclui quaisquer cabeçalhos necessários.

Para verificar se as palavras-chave definidas e nomes de chave em seu arquivo de recurso, no Visual Studio, abra o **exibição de recurso** janela — na barra de menus, escolha **exibição**, **exibição recursos**— e em seguida, abra o menu de atalho para o arquivo. RC e escolha **símbolos de recurso** para exibir a lista de símbolos definidos. Para modificar os cabeçalhos incluídos, abra o menu de atalho para o arquivo. RC e escolha **inclui recursos**.

Se você encontrar esta mensagem:

```
undefined keyword or key name: MFT_STRING
```

Abra \MCL\MFC\Include\AfxRes.h e adicione esta diretiva de inclusão:

```
#include <winresrc.h>
```