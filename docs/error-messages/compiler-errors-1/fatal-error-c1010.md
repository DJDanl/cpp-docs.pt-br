---
title: Erro fatal C1010
ms.date: 08/19/2019
f1_keywords:
- C1010
helpviewer_keywords:
- C1010
ms.assetid: dfd035f1-a7a2-40bc-bc92-dc4d7f456767
ms.openlocfilehash: 35b0f60f7eb3be887598e7ffaf3e3eae74aefcff
ms.sourcegitcommit: 9d4ffb8e6e0d70520a1e1a77805785878d445b8a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/20/2019
ms.locfileid: "69630793"
---
# <a name="fatal-error-c1010"></a>Erro fatal C1010

fim de arquivo inesperado ao procurar cabeçalho pré-compilado. Você esqueceu de adicionar ' #include Name ' à sua fonte?

Um arquivo de inclusão especificado com [/Yu](../../build/reference/yu-use-precompiled-header-file.md) não está listado no arquivo de origem.  Essa opção é habilitada por padrão na maioria dos C++ tipos de projeto do Visual Studio e *PCH. h* (*stdafx. h* no Visual Studio 2017 e anterior) é o arquivo de inclusão padrão especificado por essa opção.

No ambiente do Visual Studio, use um dos seguintes métodos para resolver esse erro:

- Se você não usar cabeçalhos pré-compilados em seu projeto, defina a propriedade **Criar/usar cabeçalho pré-compilado** de arquivos de origem para **não usar cabeçalhos pré-compilados**. Para definir essa opção de compilador, siga estas etapas:

   1. No painel de Gerenciador de Soluções do projeto, clique com o botão direito do mouse no nome do projeto e clique em **Propriedades**.

   1. No painel esquerdo, clique na pasta **C/C++**  .

   1. Clique no nó **cabeçalhos pré-compilados** .

   1. No painel direito, clique em **Criar/usar cabeçalho pré-compilado**e, em seguida, clique em **não usar cabeçalhos pré-compilados**.

- Verifique se você não excluiu inadvertidamente o arquivo de cabeçalho renomeado ou removido (por padrão, stdafx. h) do projeto atual. Esse arquivo também precisa ser incluído antes de qualquer outro código em seus arquivos de origem usando **#include "stdafx. h"** . (Esse arquivo de cabeçalho é especificado como **Criar/usar PCH por meio** da propriedade de projeto de arquivo)