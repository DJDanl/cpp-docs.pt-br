---
title: "Erro das Ferramentas de Vinculador LNK1211 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK1211"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1211"
ms.assetid: 607400eb-4180-4892-817f-eedfa628af61
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1211
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

pré\-compilado informações de tipo não encontrada; “nome de arquivo” não vinculado ou não substituído  
  
 O arquivo de objeto fornecido, compilado com [\/Yc](../../build/reference/yc-create-precompiled-header-file.md), não foi especificado no comando de LINK ou foi substituído.  
  
 Se você estiver criando uma biblioteca de depuração que use cabeçalhos pré\-compilados e se você especificar \/Yc e [\/Z7](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md), Visual C\+\+ gerencie um arquivo de objeto pré\-compilado que contém informações de depuração de CodeView.  O erro ocorre somente quando você armazena o arquivo de objeto pré\-compilado em uma biblioteca, usa a biblioteca para criar uma imagem executável, e os arquivos de objeto que são referenciados não têm nenhuma referência transitiva a algumas das funções que o arquivo de objeto pré\-compilado define o.  
  
 Há dois métodos para solucionar essa situação:  
  
-   Especificar a opção de compilador de [\/Yd](../../build/reference/yd-place-debug-information-in-object-file.md) adicionar informações de CodeView de cabeçalho pré\-compilado a cada módulo de objeto.  Esse método é desejável menos como gerenciar normalmente os módulos de objeto grandes que podem aumentar o tempo necessário para vincular o aplicativo.  
  
-   Especifique [\/Yl](../../build/reference/yl-inject-pch-reference-for-debug-library.md) e passe o nome de qualquer cadeia de caracteres arbitrária, quando você cria um arquivo de cabeçalho pré\-compilado que não contém nenhuma definições de função.  Isso direciona o compilador para criar um símbolo no arquivo de objeto pré\-compilado e para emitir uma referência para esse símbolo em cada arquivo de objeto que usou o arquivo de cabeçalho pré\-compilado associado ao arquivo de objeto pré\-compilado.  
  
 Quando você cria um módulo com **\/Yc** e **\/Yl**, o compilador cria um símbolo semelhante a `__@@_PchSym_@00@...@symbol_name`, onde as reticências \(...\) representam uma cadeia de caracteres de versão completo gerado, e o coloca no módulo de objeto.  Qualquer arquivo de origem que você compile com este cabeçalho pré\-compilado se refere ao símbolo especificado, que faz com que o vinculador inclui o módulo de objeto e suas informações de depuração da biblioteca.  
  
 Para obter mais informações sobre este erro, consulte o artigo da Base de Dados de Conhecimento Q102697 PRB: Erros de compilação usando o cabeçalho pré\-compilado em biblioteca de depuração.