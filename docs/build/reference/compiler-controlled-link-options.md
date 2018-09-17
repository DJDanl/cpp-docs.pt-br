---
title: Opções LINK controladas por compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- link
dev_langs:
- C++
helpviewer_keywords:
- LINK tool [C++], compiler-controlled options
- linker [C++], CL compiler control
- linking [C++], affected by CL features
- cl.exe compiler [C++], features that affect linking
- cl.exe compiler [C++], controlling linker
ms.assetid: e4c03896-c99c-4599-8502-e0f4bebe69d0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ee952fe5152d98aa33c4ef7e98f8a2eb3ef077be
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726421"
---
# <a name="compiler-controlled-link-options"></a>Opções LINK controladas por compilador

O compilador CL chama automaticamente o LINK, a menos que você especifique a opção /c. CL fornece algum controle sobre o vinculador por meio de argumentos e opções de linha de comando. A tabela a seguir resume os recursos na CL que afetam a vinculação.

|Especificação de CL|Ação de CL que afeta o LINK|
|----------------------|---------------------------------|
|Qualquer extensão de nome de arquivo diferente. c,. cxx,. cpp ou. def|Passa um nome de arquivo como entrada para o LINK|
|*nome do arquivo*. def|Passa /DEF:*filename*. def|
|/F*número*|Passos /STACK:*número*|
|/FD*filename*|Passa /PDB:*filename*|
|/FE*nome de arquivo*|Passa /out:*filename*|
|/FM*nome de arquivo*|Passos /MAP:*filename*|
|/Gy|Cria funções empacotadas (COMDATs); Habilita vinculação em nível de função|
|/LD|Passa /DLL|
|/LDd|Passa /DLL|
|/link|Passa o restante da linha de comando link|
|/MD ou /MT|Coloca um nome de biblioteca padrão no arquivo. obj|
|/MDd ou /MTd|Coloca um nome de biblioteca padrão no arquivo. obj. Define o símbolo **Debug**|
|/nologo|Passa /NOLOGO|
|/Zd|Passa /DEBUG|
|/Zi ou/Z7|Passa /DEBUG|
|/Zl|Omite o nome da biblioteca padrão do arquivo. obj|

Para obter mais informações, consulte [Opções do compilador](../../build/reference/compiler-options.md).

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)