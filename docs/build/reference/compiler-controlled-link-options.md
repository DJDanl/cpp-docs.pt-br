---
title: "Opções LINK controladas por compilador | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: link
dev_langs: C++
helpviewer_keywords:
- LINK tool [C++], compiler-controlled options
- linker [C++], CL compiler control
- linking [C++], affected by CL features
- cl.exe compiler [C++], features that affect linking
- cl.exe compiler [C++], controlling linker
ms.assetid: e4c03896-c99c-4599-8502-e0f4bebe69d0
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: cc899fc7f1fc8c1805648e72e14ef13853841c90
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-controlled-link-options"></a>Opções LINK controladas por compilador
O compilador CL chama automaticamente o LINK, a menos que você especificar a opção /c. CL fornece algum controle sobre o vinculador por meio de opções de linha de comando e argumentos. A tabela a seguir resume os recursos CL que afetam a vinculação.  
  
|Especificação de CL|Ação de CL que afeta o LINK|  
|----------------------|---------------------------------|  
|Qualquer extensão de nome de arquivo diferente. c,. cxx,. cpp ou. def|Passa um nome de arquivo como entrada para o LINK|  
|*nome do arquivo*. def|Passa /DEF:*filename*. def|  
|/F*número*|Passa /STACK:*número*|  
|/FD*filename*|Passa /PDB:*filename*|  
|/FE*nome de arquivo*|Passa /out:*filename*|  
|/FM*nome de arquivo*|Passa /MAP:*filename*|  
|/Gy|Cria funções empacotadas (COMDATs); Habilita vínculo em nível de função|  
|/LD|Passa /DLL|  
|/LDd|Passa /DLL|  
|/link|Passa o restante da linha de comando link|  
|/MD ou /MT|Coloca um nome de biblioteca padrão no arquivo. obj|  
|/MDd ou /MTd|Insere um nome de biblioteca padrão no arquivo. obj. Define o símbolo **Debug**|  
|/nologo|Passa /NOLOGO|  
|/Zd|Passa /DEBUG|  
|/Zi ou /Z7|Passa /DEBUG|  
|/Zl|Omite o nome da biblioteca padrão do arquivo. obj|  
  
 Para obter mais informações, consulte [Opções do compilador](../../build/reference/compiler-options.md).  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)