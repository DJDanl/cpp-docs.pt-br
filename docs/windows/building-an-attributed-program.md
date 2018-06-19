---
title: Compilando um programa atribuído | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9d87f95b456e3f99598f48e6ffa8ad29806aa168
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33862271"
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