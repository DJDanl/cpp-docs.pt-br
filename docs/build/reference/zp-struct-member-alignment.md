---
title: /Zp (alinhamento de membro do Struct)
ms.date: 04/04/2019
f1_keywords:
- /zp
- VC.Project.VCCLCompilerTool.StructMemberAlignment
- VC.Project.VCCLWCECompilerTool.StructMemberAlignment
helpviewer_keywords:
- Struct Member Alignment compiler option
- Zp compiler option
- /Zp compiler option [C++]
- -Zp compiler option [C++]
ms.assetid: 5242f656-ed9b-48a3-bc73-cfcf3ed2520f
ms.openlocfilehash: d76cd93c7af4228bff8f73fa3bcbf40fa149b0be
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315905"
---
# <a name="zp-struct-member-alignment"></a>/Zp (alinhamento de membro do Struct)

Controla como os membros de uma estrutura são empacotados na memória e especifica o empacotamento mesmo para todas as estruturas em um módulo.

## <a name="syntax"></a>Sintaxe

> **/Zp**[**1**|**2**|**4**|**8**|**16**]

## <a name="remarks"></a>Comentários

O **/Zp**_n_ opção informa ao compilador onde armazenar cada membro da estrutura. O compilador armazena membros após o primeiro em um limite que for menor do tamanho do tipo de membro, ou um *n*-limite de bytes.

Os valores de remessa disponíveis são descritos na tabela a seguir:

|/ZP argumento|Efeito|
|-|-|
|1|Empacota estruturas em limites de 1 byte. Mesmo que **/Zp**.|
|2|Empacota estruturas em limites de 2 bytes.|
|4|Empacota estruturas em limites de 4 bytes.|
|8|Empacota estruturas em limites de 8 bytes (o padrão para x86, ARM e ARM64).|
|16| Empacota estruturas em limites de 16 bytes (o padrão para x64).|

Não use essa opção, a menos que você tenha requisitos de alinhamento específico.

> [!WARNING]
> Cabeçalhos de C++ no SDK do Windows definida e supor **/zp8** internamente de remessa. Memória corrupção pode ocorrer se o **/Zp** for alterada dentro os cabeçalhos do SDK do Windows. Os cabeçalhos não são afetados por qualquer **/Zp** opção definida na linha de comando.

Você também pode usar [pack](../../preprocessor/pack.md) a empacotamento de estrutura de controle. Para obter mais informações sobre alinhamento, consulte:

- [align](../../cpp/align-cpp.md)

- [Operador __alignof](../../cpp/alignof-operator.md)

- [__unaligned](../../cpp/unaligned.md)

- [/ALIGN (alinhamento da seção)](align-section-alignment.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **geração de código** página de propriedades.

1. Modificar a **alinhamento de membro de Struct** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StructMemberAlignment%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md) \
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
