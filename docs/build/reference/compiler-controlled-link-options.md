---
title: Opções LINK controladas por compilador
ms.date: 11/04/2016
helpviewer_keywords:
- LINK tool [C++], compiler-controlled options
- linker [C++], CL compiler control
- linking [C++], affected by CL features
- cl.exe compiler [C++], features that affect linking
- cl.exe compiler [C++], controlling linker
ms.assetid: e4c03896-c99c-4599-8502-e0f4bebe69d0
ms.openlocfilehash: f631d0ebbbd9e60fe5d54aac6fb158461d3f4d38
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440100"
---
# <a name="compiler-controlled-link-options"></a>Opções LINK controladas por compilador

O compilador CL chama o LINK automaticamente, a menos que você especifique a opção/c. O CL fornece algum controle sobre o vinculador por meio de opções de linha de comando e argumentos. A tabela a seguir resume os recursos do CL que afetam a vinculação.

|Especificação CL|Ação CL que afeta o LINK|
|----------------------|---------------------------------|
|Qualquer extensão de nome de arquivo diferente de. c,. cxx,. cpp ou. def|Passa um nome de arquivo como entrada para vincular|
|*nome do arquivo*. def|Passa/DEF:*filename*. def|
|/F*número*|Passa/STACK:*número*|
|*Nome de arquivo* /FD|Passa/PDB:*nome de arquivo*|
|*Nome de arquivo* /FE|Passa/OUT:*filename*|
|*Nome de arquivo* /FM|Passa/MAP:*nome de arquivo*|
|/Gy|Cria funções empacotadas (COMDATs); habilita a vinculação no nível de função|
|/LD|Passa/DLL|
|/LDd|Passa/DLL|
|/link|Passa o restante da linha de comando para vincular|
|/MD ou/MT|Coloca um nome de biblioteca padrão no arquivo. obj|
|/MDd ou/MTd|Coloca um nome de biblioteca padrão no arquivo. obj. Define o símbolo **_DEBUG**|
|/nologo|Passagens/NOLOGO|
|/Zd|Passa/DEBUG|
|/Zi ou/Z7|Passa/DEBUG|
|/Zl|Omite o nome de biblioteca padrão do arquivo. obj|

Para obter mais informações, consulte [Opções do compilador do MSVC](compiler-options.md).

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
