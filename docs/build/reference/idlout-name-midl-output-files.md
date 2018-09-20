---
title: -IDLOUT (nomear arquivos de saída MIDL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /idlout
- VC.Project.VCLinkerTool.MergedIDLBaseFileName
dev_langs:
- C++
helpviewer_keywords:
- MIDL, output file names
- .idl files, path
- MIDL
- /IDLOUT linker option
- IDL files, path
- -IDLOUT linker option
- IDLOUT linker option
ms.assetid: 10d00a6a-85b4-4de1-8732-e422c6931509
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ef4f8b418edcdb903fa8f807cb5e08d63eaeeed
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46441623"
---
# <a name="idlout-name-midl-output-files"></a>/IDLOUT (nomear arquivos de saída MIDL)

```
/IDLOUT:[path\]filename
```

## <a name="parameters"></a>Parâmetros

*path*<br/>
Uma especificação de caminho absoluto ou relativo. Ao especificar um caminho, você afeta apenas o local de um arquivo. idl; todos os outros arquivos são colocados no diretório do projeto.

*filename*<br/>
Especifica o nome do arquivo. idl criado pelo compilador MIDL. Nenhuma extensão de arquivo é considerado; especificar *filename*. idl, se você quiser que uma extensão. idl.

## <a name="remarks"></a>Comentários

A opção /IDLOUT Especifica o nome e extensão de arquivo. idl.

O compilador MIDL é chamado pelo vinculador do Visual C++, ao vincular projetos que têm o [módulo](../../windows/module-cpp.md) atributo.

/IDLOUT também especifica os nomes de arquivo dos outros arquivos de saída associados com o compilador MIDL:

- *nome do arquivo*. tlb

- *nome do arquivo*_p.c

- *nome do arquivo*_i.c

- *nome do arquivo*. h

*nome do arquivo* é o parâmetro que você passa para /IDLOUT. Se [/TLBOUT](../../build/reference/tlbout-name-dot-tlb-file.md) for especificado, o arquivo. tlb obterá seu nome de /TLBOUT *filename*.

Se você especificar nem /IDLOUT nem /TLBOUT, o vinculador criará vc70.tlb, vc70.idl, vc70_p.c, vc70_i.c e vc70.h.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **IDL incorporado** página de propriedades.

1. Modificar a **mesclar nome do arquivo Base IDL** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MergedIDLBaseFileName%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)<br/>
[/IGNOREIDL (não processar atributos em MIDL)](../../build/reference/ignoreidl-don-t-process-attributes-into-midl.md)<br/>
[/MIDL (especificar opções de linha de comando de MIDL)](../../build/reference/midl-specify-midl-command-line-options.md)<br/>
[Compilando um programa atribuído](../../windows/building-an-attributed-program.md)