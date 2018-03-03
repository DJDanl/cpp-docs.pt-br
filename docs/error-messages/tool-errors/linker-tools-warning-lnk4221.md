---
title: Aviso LNK4221 das ferramentas de vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4221
dev_langs:
- C++
helpviewer_keywords:
- LNK4221
ms.assetid: 8e2eb2de-9532-4b85-908a-8c9ff5c4cccb
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a3fb348ebb05b7af40821b4f3968a920c2e9e773
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-warning-lnk4221"></a>Aviso LNK4221 (Ferramentas de Vinculador)
Esse arquivo de objeto não define nenhum dos símbolos anteriormente indefinidos, portanto ele não será usado por nenhuma operação de vínculo que consuma esta biblioteca  
  
 Considere os seguintes trechos de código de dois.  
  
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
  
 Para compilar os arquivos e criar dois arquivos de objeto, execute **cl /c a.cpp b.cpp** em um prompt de comando. Se você vincular os arquivos de objeto executando **link /lib /out:test.lib a.obj b.obj**, você receberá o aviso LNK4221. Se você vincular os objetos executando **link /lib /out:test.lib b.obj a.obj**, você não receberá um aviso.  
  
 Nenhum aviso é emitido na segunda situação porque o vinculador opera de forma no último primeiro a sair (UEPS). No primeiro cenário, b.obj é processada antes a.obj e a.obj não tem novos símbolos para adicionar. Instrui o vinculador para processar a.obj pela primeira vez, você pode evitar o aviso.  
  
 Uma causa comum desse erro é quando dois arquivos de origem especificam a opção [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome de arquivo de cabeçalho especificado no **cabeçalho pré-compilado** campo. Uma causa comum desse problema lida com Stdafx. h, como, por padrão, Stdafx inclui Stdafx. h e não adiciona qualquer símbolo de novo. Se outro arquivo de origem inclui Stdafx. h com **/Yc** e o arquivo. obj associado é processado antes stdafx.obj, o vinculador gerará LNK4221.  
  
 Uma maneira de resolver esse problema é certificar-se que cada cabeçalho pré-compilado, há apenas um arquivo de origem que inclui-lo com **/Yc**. Todos os outros arquivos de origem devem usar cabeçalhos pré-compilados. Para obter mais informações sobre como alterar essa configuração, consulte [/Yu (usar pré-compilado arquivo de cabeçalho)](../../build/reference/yu-use-precompiled-header-file.md).