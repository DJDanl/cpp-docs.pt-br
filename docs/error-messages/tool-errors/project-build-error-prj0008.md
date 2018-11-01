---
title: Erro de Build PRJ0008 no Projeto
ms.date: 11/04/2016
f1_keywords:
- PRJ0008
helpviewer_keywords:
- PRJ0008
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
ms.openlocfilehash: 696b77e9906b231a680027a3faaf23e53d8fb6e9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50525891"
---
# <a name="project-build-error-prj0008"></a>Erro de Build PRJ0008 no Projeto

Não foi possível excluir o arquivo 'arquivo'.

**Certifique-se de que o arquivo não está aberto por outro processo e não está protegido contra gravação.**

Durante uma recompilação ou limpo, o Visual C++ exclui todos os arquivos de saída e intermediários conhecidos para a compilação, bem como todos os arquivos que atende às especificações de curinga na **extensões para excluir na limpeza** propriedade no [geral Página de propriedades de configurações de configuração](../../ide/general-property-page-project.md).

Você verá esse erro se o Visual C++ não é possível excluir um arquivo. Para resolver o erro, verifique o arquivo e seu diretório gravável para o usuário que faz a compilação.