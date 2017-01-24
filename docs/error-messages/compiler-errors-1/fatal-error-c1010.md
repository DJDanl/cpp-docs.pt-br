---
title: "Erro fatal C1010 | Microsoft Docs"
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
  - "C1010"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1010"
ms.assetid: dfd035f1-a7a2-40bc-bc92-dc4d7f456767
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1010
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

fim de arquivo inesperado ao procurar o cabeçalho pré\-compilado.Você esqueceu adicionar o nome \#include” à sua origem?  
  
 Um arquivo incluir especificado com [\/Yu](../../build/reference/yu-use-precompiled-header-file.md) não é listado no arquivo de origem.  Essa opção é habilitada por padrão na maioria dos tipos de projeto do Visual C\+\+ e “stdafx.h” é o padrão inclui o arquivo especificado por essa opção.  
  
 No ambiente do Visual Studio, use um dos seguintes métodos para resolver este erro:  
  
-   Se você não usar cabeçalhos pré\-compiladas em seu projeto, defina a propriedade de **Create\/Use Precompiled Header** dos arquivos de origem a **Não Usar Cabeçalhos Pré\-Compilados**.  Para definir esta opção do compilador, siga estas etapas:  
  
    1.  No painel do Solution Explorer do projeto, clique com o botão direito do mouse no nome de projeto, e clique em **Propriedades**.  
  
    2.  No painel esquerdo, clique na pasta de **C\/C\+\+** .  
  
    3.  Clique no nó de **Cabeçalhos Pré\-Compilados** .  
  
    4.  No painel direito, clique em **Create\/Use Precompiled Header**, e clique em **Não Usar Cabeçalhos Pré\-Compilados**.  
  
-   Certifique\-se de ter excluído inadvertidamente, não arquivo de cabeçalho renomear ou ser descartado \(por padrão, stdafx.h\) do projeto atual.  Esse arquivo também precisa ser incluído antes de qualquer outro código em seus arquivos de origem usando **\#include "stdafx.h"**. \(Esse arquivo de cabeçalho for especificado como propriedades do projeto **Create\/Use PCH Through File** \)