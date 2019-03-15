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
ms.openlocfilehash: bc7a6cc596f138daa373042abca51642c24cf737
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57822321"
---
# <a name="compiler-controlled-link-options"></a>Opções LINK controladas por compilador

O compilador CL chama automaticamente o LINK, a menos que você especifique a opção /c. CL fornece algum controle sobre o vinculador por meio de argumentos e opções de linha de comando. A tabela a seguir resume os recursos na CL que afetam a vinculação.

|Especificação de CL|Ação de CL que afeta o LINK|
|----------------------|---------------------------------|
|Qualquer extensão de nome de arquivo diferente. c,. cxx,. cpp ou. def|Passa um nome de arquivo como entrada para o LINK|
|*filename*.def|Passa /DEF:*filename*. def|
|/F*number*|Passos /STACK:*número*|
|/Fd*filename*|Passa /PDB:*filename*|
|/Fe*filename*|Passa /out:*filename*|
|/Fm*filename*|Passos /MAP:*filename*|
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

Para obter mais informações, consulte [opções do compilador MSVC](compiler-options.md).

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
