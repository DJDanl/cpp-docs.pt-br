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
- tlb files [C++]
- MIDL
- MIDL, linker output
- IDL files [C++]
- building type libraries and .idl files
- .tlb files [C++]
- .idl files [C++]
- type libraries, linker options for building
ms.assetid: 04997b5f-bf2c-46ec-b868-c4adebbef5f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2fc148478433106eabdb2bc57ef7bb6c91d13601
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44315282"
---
# <a name="building-an-attributed-program"></a>Compilando um programa atribuído

Depois de você colocar atributos do Visual C++ em seu código-fonte, convém fazer com que o compilador do Visual C++ para produzir um arquivo de biblioteca e. IDL do tipo para você. As seguinte opções de vinculador ajudam você a criar arquivos. tlb e. idl:

- [/IDLOUT](../build/reference/idlout-name-midl-output-files.md)

- [/IGNOREIDL](../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)

- [/ MIDL](../build/reference/midl-specify-midl-command-line-options.md)

- [/TLBOUT](../build/reference/tlbout-name-dot-tlb-file.md)

Alguns projetos contêm vários arquivos. idl independentes. Eles são usados para produzir dois ou mais arquivos. tlb e, opcionalmente, associá-las no bloco de recurso. Esse cenário não é suportado no Visual C++.

Além disso, o vinculador do Visual C++ produzirá todas as informações de atributo relacionados de IDL para um único arquivo MIDL. Não haverá nenhuma maneira de gerar duas bibliotecas de tipo de um único projeto.

## <a name="see-also"></a>Consulte também

[Conceitos](../windows/attributed-programming-concepts.md)