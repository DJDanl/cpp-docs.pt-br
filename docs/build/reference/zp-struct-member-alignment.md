---
title: /Zp (alinhamento de membro do Struct)
ms.date: 12/17/2018
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
ms.openlocfilehash: d1821d8dc5eab202a918893a1e7895151629b551
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53627521"
---
# <a name="zp-struct-member-alignment"></a>/Zp (alinhamento de membro do Struct)

Controla como os membros de uma estrutura são empacotados na memória e especifica o empacotamento mesmo para todas as estruturas em um módulo.

## <a name="syntax"></a>Sintaxe

> **/ZP**[**1**|**2**|**4**|**8** | **16**]

## <a name="remarks"></a>Comentários

Quando você especifica o **/Zp**_n_ opção, cada membro da estrutura depois do primeiro é armazenado no tamanho do tipo de membro ou *n*-limites de bytes (em que *n* é 1, 2, 4, 8 ou 16), o que for menor.

Os valores de remessa disponíveis são descritos na tabela a seguir:

|/ZP argumento|Efeito|
|-|-|
|1|Empacota estruturas em limites de 1 byte. Mesmo que **/Zp**.|
|2|Empacota estruturas em limites de 2 bytes.|
|4|Empacota estruturas em limites de 4 bytes.|
|8|Empacota estruturas em limites de 8 bytes (padrão).|
|16| Empacota estruturas em limites de 16 bytes.|

Você não deve usar essa opção, a menos que você tenha requisitos de alinhamento específico.

> [!WARNING]
> Suponha que os cabeçalhos de C++ no SDK do Windows **/zp8** de remessa. Memória corrupção pode ocorrer se o **/Zp** configuração é alterada quando o uso de cabeçalhos do SDK do Windows.

Você também pode usar [pack](../../preprocessor/pack.md) a empacotamento de estrutura de controle. Para obter mais informações sobre alinhamento, consulte:

- [align](../../cpp/align-cpp.md)

- [Operador __alignof](../../cpp/alignof-operator.md)

- [__unaligned](../../cpp/unaligned.md)

- [Exemplos de alinhamento da estrutura](../../build/x64-software-conventions.md#examples-of-structure-alignment) (específico para x64)

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** > **geração de código** página de propriedades.

1. Modificar a **alinhamento de membro de Struct** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StructMemberAlignment%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do Compilador](../../build/reference/compiler-options.md)
- [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
