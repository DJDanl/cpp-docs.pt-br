---
title: "Aviso LNK4221 (Ferramentas de Vinculador) | Microsoft Docs"
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
  - "LNK4221"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK4221"
ms.assetid: 8e2eb2de-9532-4b85-908a-8c9ff5c4cccb
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso LNK4221 (Ferramentas de Vinculador)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esse arquivo de objeto não define nenhum símbolos públicos anteriormente indeterminados, assim que não serão usados por nenhuma operação de link que consumir essa biblioteca  
  
 Considere os dois seguintes trechos de código.  
  
```  
// a.cpp  
#include <atlbase.h>  
```  
  
```  
// b.cpp  
#include <atlbase.h>  
int function()  
{  
   return 0;  
}  
  
```  
  
 Para criar os arquivos e criar dois arquivos de objeto, execute **cl \/c a.cpp b.cpp** em um prompt de comando.  Se você vincular os arquivos de objeto executando **link \/lib \/out:test.lib a.obj b.obj**, você receberá o aviso LNK4221.  Se você vincular os objetos executando **link \/lib \/out:test.lib b.obj a.obj**, você não receberá um aviso.  
  
 Nenhum aviso é emitido no segundo cenário porque o vinculador opera na última na primeira em expansão maneira de \(LIFO\).  No primeiro cenário, b.obj é processado antes da.obj, e a.obj não tem nenhum novo símbolo a ser adicionado.  Instruindo o vinculador para processar primeiro a.obj, você pode impedir o aviso.  
  
 Uma causa comum para esse erro quando dois arquivos de origem especifique a opção [\/Yc \(criar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome do arquivo de cabeçalho especificado no campo de **cabeçalho pré\-compilado** .  Uma causa mais comum desse problema trata o stdafx.h desde que, por padrão, stdafx.cpp inclui stdafx.h e não adiciona nenhum novo símbolos.  Se outro arquivo de origem inclui stdafx.h com **\/Yc** e o arquivo associado de .obj é processado antes de stdafx.obj, o vinculador lançará LNK4221.  
  
 Uma forma de resolver esse problema é certificar\-se de que para cada cabeçalho pré\-compilado, há apenas um arquivo de origem que inclui o com **\/Yc**.  Todos os arquivos de origem demais devem usar cabeçalhos pré\-compilados.  Para obter mais informações sobre como alterar essa configuração, consulte [\/Yu \(usar arquivo de cabeçalho pré\-compilado\)](../../build/reference/yu-use-precompiled-header-file.md).