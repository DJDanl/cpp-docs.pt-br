---
title: Aviso LNK4221 das ferramentas de vinculador | Documentos do Microsoft
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
caps.latest.revision: 12
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
ms.openlocfilehash: 61c2489a34a7debde6f3d9f99df452c7e882b8da
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4221"></a>Aviso LNK4221 (Ferramentas de Vinculador)
Este objeto não define nenhum dos símbolos anteriormente indefinidos, portanto ele não será utilizado em nenhuma operação de vínculo que consuma esta biblioteca  
  
 Considere os seguintes dois trechos de código.  
  
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
  
 Para compilar os arquivos e crie dois arquivos de objeto, execute **cl /c a.cpp b.cpp** em um prompt de comando. Se você vincular os arquivos de objeto executando **link/lib /out:test.lib a.obj b.obj**, você receberá um aviso LNK4221. Se você vincular os objetos, executando **link/lib /out:test.lib b.obj a.obj**, você não receberá um aviso.  
  
 Nenhum aviso é emitido no segundo cenário porque o vinculador opera de maneira último a entrar primeiro a sair (UEPS). No primeiro cenário, b.obj será processado antes de a.obj e a.obj não tem novos símbolos para adicionar. Instruindo o vinculador processar a.obj pela primeira vez, você pode evitar o aviso.  
  
 Uma causa comum desse erro é quando dois arquivos de origem especificam a opção [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome de arquivo de cabeçalho especificado no **cabeçalho pré-compilado** campo. Uma causa comum desse problema lida com Stdafx. h, já que, por padrão, Stdafx inclui Stdafx. h e não adiciona qualquer novo símbolos. Se outro arquivo de origem inclui Stdafx. h com **/Yc** e o arquivo. obj associado será processado antes de stdafx.obj, o vinculador lança LNK4221.  
  
 Uma maneira de resolver esse problema é certificar-se que cada cabeçalho pré-compilado, há apenas um arquivo de origem que inclui com **/Yc**. Todos os outros arquivos de origem devem usar cabeçalhos pré-compilados. Para obter mais informações sobre como alterar essa configuração, consulte [/Yu (usar pré-compilados arquivo de cabeçalho)](../../build/reference/yu-use-precompiled-header-file.md).
