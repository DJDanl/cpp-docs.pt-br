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
ms.openlocfilehash: c78e670303bde68299725e18c6f588f5e410a971
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234296"
---
# <a name="zp-struct-member-alignment"></a>/Zp (alinhamento de membro do Struct)

Controla como os membros de uma estrutura são empacotados na memória e especifica o mesmo empacotamento para todas as estruturas em um módulo.

## <a name="syntax"></a>Sintaxe

> **`/Zp`**[**`1`**|**`2`**|**`4`**|**`8`**|**`16`**]

## <a name="remarks"></a>Comentários

A **`/ZpN`** opção informa ao compilador onde armazenar cada membro da estrutura. O compilador armazena os membros após o primeiro em um limite que é menor do que o tamanho do tipo de membro ou de um limite de *N*bytes.

Os valores de embalagem disponíveis são descritos na tabela a seguir:

|Argumento/ZP|Efeito|
|-|-|
|1|Empacota estruturas em limites de 1 byte. O mesmo que **`/Zp`** .|
|2|Empacota estruturas em limites de 2 bytes.|
|4|Empacota estruturas em limites de 4 bytes.|
|8|Empacota estruturas em limites de 8 bytes (padrão para x86, ARM e ARM64).|
|16| Empacota estruturas em limites de 16 bytes (padrão para x64).|

Não use essa opção, a menos que você tenha requisitos de alinhamento específicos.

> [!WARNING]
> Os cabeçalhos do C++ no conjunto de SDK do Windows e assumem o **`/Zp8`** empacotamento internamente. A corrupção de memória pode ocorrer se a **`/Zp`** configuração for alterada dentro dos cabeçalhos de SDK do Windows. Os cabeçalhos não são afetados por nenhuma **`/Zp`** opção definida na linha de comando.

Você também pode usar o [`pack`](../../preprocessor/pack.md) para controlar a embalagem da estrutura. Para obter mais informações sobre alinhamento, consulte:

- [`align`](../../cpp/align-cpp.md)

- [`alignof`Operador](../../cpp/alignof-operator.md)

- [`__unaligned`](../../cpp/unaligned.md)

- [`/ALIGN`(Alinhamento de seção)](align-section-alignment.md)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração**de  >  geração de código**C/C++**  >  **Code Generation** .

1. Modifique a propriedade de **alinhamento do Membro struct** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StructMemberAlignment%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md) \
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
