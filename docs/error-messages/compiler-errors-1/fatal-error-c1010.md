---
title: Erro fatal C1010 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1010
dev_langs:
- C++
helpviewer_keywords:
- C1010
ms.assetid: dfd035f1-a7a2-40bc-bc92-dc4d7f456767
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bf8af35b28cfa02bd2723ff3c78db04a27cc39ba
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1010"></a>Erro fatal C1010
fim de arquivo inesperado durante a procura de cabeçalho pré-compilado. Você esqueceu de adicionar ' #include nome ' à sua fonte?  
  
 Um arquivo de inclusão especificado com [/Yu](../../build/reference/yu-use-precompiled-header-file.md) não estiver listado no arquivo de origem.  Essa opção é habilitada por padrão na maioria dos tipos de projeto do Visual C++ e "Stdafx. h" é o padrão incluem o arquivo especificado por essa opção.  
  
 No ambiente do Visual Studio, use um dos seguintes métodos para resolver esse erro:  
  
-   Se você não usar cabeçalhos pré-compilados em seu projeto, defina o **cabeçalho pré-compilado criar/usar** propriedade dos arquivos de origem para **não cabeçalhos pré-compilados usando**. Para definir essa opção de compilador, siga estas etapas:  
  
    1.  No painel de Gerenciador de soluções do projeto, clique no nome do projeto e, em seguida, clique em **propriedades**.  
  
    2.  No painel esquerdo, clique no **C/C++** pasta.  
  
    3.  Clique o **cabeçalhos pré-compilados** nó.  
  
    4.  No painel direito, clique em **criar/usar cabeçalho de pré-compilado**e, em seguida, clique em **não usar cabeçalhos pré-compilados**.  
  
-   Certifique-se de excluído, renomeado ou removido do arquivo de cabeçalho não inadvertidamente (por padrão, Stdafx. h) do projeto atual. Esse arquivo também deve ser incluído antes de qualquer outro código nos arquivos de origem usando **#include "Stdafx. h"**. (Esse arquivo de cabeçalho é especificado como **criar/usar PCH através de arquivo** propriedade de projeto)