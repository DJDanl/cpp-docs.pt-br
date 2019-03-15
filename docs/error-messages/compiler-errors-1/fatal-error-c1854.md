---
title: Erro fatal C1854
ms.date: 11/04/2016
f1_keywords:
- C1854
helpviewer_keywords:
- C1854
ms.assetid: 8c21a9cc-1737-475c-9e57-8725cd8937c1
ms.openlocfilehash: 83eb5e01eac377b8f19a0e94dc1518e3ed557c3b
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820020"
---
# <a name="fatal-error-c1854"></a>Erro fatal C1854

> não é possível substituir informação formada durante a criação de cabeçalho pré-compilado no arquivo de objeto: '*filename*'

Você especificou o [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md) opção depois de especificar o [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) opção para o mesmo arquivo.

Para corrigir esse problema, em geral, defina apenas um arquivo em seu projeto para ser compilado usando o **/Yc** opção e defina todos os outros arquivos para compilar usando o **/Yu** opção. Para obter detalhes sobre o uso do **/Yc** opção e como defini-la no IDE do Visual Studio, consulte [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md). Para obter mais informações sobre como usar cabeçalhos pré-compilados, consulte [criando arquivos de cabeçalho pré-compilado](../../build/creating-precompiled-header-files.md).
