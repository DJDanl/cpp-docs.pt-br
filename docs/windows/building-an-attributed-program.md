---
title: "Compilando um programa atribuído | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- tlb files
- MIDL
- MIDL, linker output
- IDL files
- tlb files, building attributed programs
- .tlb files, building attributed programs
- IDL files, building
- attributes [C++], building type libraries and .idl files
- .tlb files
- .idl files, building
- type libraries, linker options for building
ms.assetid: 04997b5f-bf2c-46ec-b868-c4adebbef5f4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e3e39bbd2b630d35942c1c5107041b2fbadf7549
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="building-an-attributed-program"></a>Compilando um programa atribuído
Depois de você colocar atributos do Visual C++ em seu código-fonte, convém fazer com que o compilador do Visual C++ para produzir um arquivo. idl e biblioteca de tipo para você. Opções de vinculador a seguir ajudam a criar arquivos. tlb e. idl:  
  
-   [/IDLOUT](../build/reference/idlout-name-midl-output-files.md)  
  
-   [/IGNOREIDL](../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)  
  
-   [/ MIDL](../build/reference/midl-specify-midl-command-line-options.md)  
  
-   [/TLBOUT](../build/reference/tlbout-name-dot-tlb-file.md)  
  
 Alguns projetos contêm vários arquivos. idl independentes. Eles são usados para produzir dois ou mais arquivos. tlb e, opcionalmente, associá-las no bloco de recurso. Esse cenário não é suportado atualmente no Visual C++.  
  
 Além disso, o vinculador do Visual C++ mostrará todas as informações de atributo IDL relacionados em um único arquivo MIDL. Não haverá nenhuma maneira de gerar duas bibliotecas de tipo de um único projeto.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../windows/attributed-programming-concepts.md)