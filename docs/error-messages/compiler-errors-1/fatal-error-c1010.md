---
title: Erro fatal C1010 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1010
dev_langs:
- C++
helpviewer_keywords:
- C1010
ms.assetid: dfd035f1-a7a2-40bc-bc92-dc4d7f456767
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 98d9e53e152ed1610674ed5ee16838ebf5419e75
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1010"></a>Erro fatal C1010
fim de arquivo inesperado durante a procura de cabeçalho pré-compilado. Você esqueceu de adicionar ' #include nome ' para a sua fonte?  
  
 Um arquivo de inclusão especificado com [/Yu](../../build/reference/yu-use-precompiled-header-file.md) não estiver listado no arquivo de origem.  Essa opção é habilitada por padrão na maioria dos tipos de projeto do Visual C++ e "Stdafx. h" é o padrão incluem o arquivo especificado por essa opção.  
  
 No ambiente do Visual Studio, use um dos seguintes métodos para resolver esse erro:  
  
-   Se você não usar cabeçalhos pré-compilados em seu projeto, defina o **cabeçalho pré-compilado criar/usar** propriedade dos arquivos de origem para **não cabeçalhos pré-compilados usando**. Para definir essa opção de compilador, siga estas etapas:  
  
    1.  No painel Solution Explorer do projeto, clique no nome do projeto e, em seguida, clique em **propriedades**.  
  
    2.  No painel esquerdo, clique o **C/C++** pasta.  
  
    3.  Clique o **cabeçalhos pré-compilados** nó.  
  
    4.  No painel direito, clique em **criar/usar cabeçalho de pré-compilados**e, em seguida, clique em **não usando pré-compilados cabeçalhos**.  
  
-   Certifique-se de excluído, renomeado ou removido do arquivo de cabeçalho não inadvertidamente (por padrão, Stdafx. h) do projeto atual. Esse arquivo também deve ser incluído antes de qualquer outro código em seus arquivos de origem usando **#include "Stdafx. h"**. (Esse arquivo de cabeçalho é especificado como **criar/usar PCH através de arquivo** propriedade de projeto)
