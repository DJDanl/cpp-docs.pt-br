---
title: Erro de Build PRJ0008 do projeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- PRJ0008
dev_langs:
- C++
helpviewer_keywords:
- PRJ0008
ms.assetid: 6bf7f17a-d2a8-4826-99c7-d600d846952f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d7c24634a845423de590228af01cb9f4779e37ab
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46062781"
---
# <a name="project-build-error-prj0008"></a>Erro de Build PRJ0008 no Projeto

Não foi possível excluir o arquivo 'arquivo'.

**Certifique-se de que o arquivo não está aberto por outro processo e não está protegido contra gravação.**

Durante uma recompilação ou limpo, o Visual C++ exclui todos os arquivos de saída e intermediários conhecidos para a compilação, bem como todos os arquivos que atende às especificações de curinga na **extensões para excluir na limpeza** propriedade no [geral Página de propriedades de configurações de configuração](../../ide/general-property-page-project.md).

Você verá esse erro se o Visual C++ não é possível excluir um arquivo. Para resolver o erro, verifique o arquivo e seu diretório gravável para o usuário que faz a compilação.