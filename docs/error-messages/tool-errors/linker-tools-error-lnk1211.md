---
title: Ferramentas de vinculador LNK1211 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1211
dev_langs:
- C++
helpviewer_keywords:
- LNK1211
ms.assetid: 607400eb-4180-4892-817f-eedfa628af61
caps.latest.revision: 8
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
ms.openlocfilehash: 7f898d9c5f3a2034d99234b70b6a7925d680b7fa
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1211"></a>Erro das Ferramentas de Vinculador LNK1211
informações de tipo pré-compilado não encontradas. 'filename' não vinculado ou substituído  
  
 O arquivo de objeto fornecido, compilado com [/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando LINK ou foi substituído.  
  
 Se você estiver criando uma biblioteca de depuração que usa cabeçalhos pré-compilados e se você especificar /Yc e [/Z7](../../build/reference/z7-zi-zi-debug-information-format.md), Visual C++ gera um arquivo de objeto pré-compilado que contém informações de depuração de CodeView. O erro ocorre somente quando você armazena o arquivo de objeto pré-compilado em uma biblioteca, use a biblioteca para criar uma imagem executável e os arquivos de objeto referenciadas não possuem transitivas referências para qualquer uma das funções que define o arquivo de objeto pré-compilado.  
  
 Há dois métodos para contornar essa situação:  
  
-   Especifique o [/Yd](../../build/reference/yd-place-debug-information-in-object-file.md) opção de compilador para adicionar as informações de CodeView do cabeçalho pré-compilado para cada módulo do objeto. Esse método é menos desejável porque geralmente produz módulos de objeto grande que podem aumentar o tempo necessário para vincular o aplicativo.  
  
-   Especifique [/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) e passar o nome de qualquer cadeia de caracteres arbitrária, quando você cria um arquivo de cabeçalho pré-compilado que não contém quaisquer definições de função. Isso instrui o compilador para criar um símbolo no arquivo de objeto pré-compilado e a emissão de uma referência a esse símbolo em cada arquivo de objeto que usou o arquivo de cabeçalho pré-compilado que está associado com o arquivo de objeto pré-compilado.  
  
 Quando você compila um módulo com **/Yc** e **/Yl**, o compilador cria um símbolo semelhante a `__@@_PchSym_@00@...@symbol_name`, onde as reticências (...) representa uma cadeia de caracteres gerados pelo compilador e o armazena no módulo de objeto. Qualquer arquivo de origem que você compila com esse cabeçalho pré-compilado refere-se ao símbolo especificado, que faz com que o vinculador a incluir o módulo de objeto e suas informações de depuração da biblioteca.  
  
 Para obter mais informações sobre esse erro, consulte a Base de dados de Conhecimento artigo Q102697 PRB: criar erros usando pré-compilados cabeçalho na biblioteca de depuração.
