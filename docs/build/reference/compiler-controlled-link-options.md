---
title: Opções LINK controladas por compilador
ms.date: 11/04/2016
f1_keywords:
- link
helpviewer_keywords:
- LINK tool [C++], compiler-controlled options
- linker [C++], CL compiler control
- linking [C++], affected by CL features
- cl.exe compiler [C++], features that affect linking
- cl.exe compiler [C++], controlling linker
ms.assetid: e4c03896-c99c-4599-8502-e0f4bebe69d0
ms.openlocfilehash: 21d0baccaf74fc08bb110b0ae9f8b7dc108abd6b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50561558"
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