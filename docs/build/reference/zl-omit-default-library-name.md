---
title: /Zl (omitir nome da biblioteca padrão)
ms.date: 11/04/2016
f1_keywords:
- /zi
- VC.Project.VCCLCompilerTool.OmitDefaultLibName
helpviewer_keywords:
- -Zl compiler option [C++]
- ZI compiler option
- Omit Default Library Name compiler option
- /Zl compiler option [C++]
- default libraries, omitting names
ms.assetid: b27d39d0-44d6-498c-84ae-27c1326fee59
ms.openlocfilehash: 1bcb90dbf071253dc0561845e3bd713dc42d5aef
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988561"
---
# <a name="zl-omit-default-library-name"></a>/Zl (omitir nome da biblioteca padrão)

Omite o nome padrão da biblioteca de tempo de execução do C do arquivo. obj. Por padrão, o compilador coloca o nome da biblioteca no arquivo .obj para direcionar o vinculador à biblioteca correta.

## <a name="syntax"></a>Sintaxe

```
/Zl
```

## <a name="remarks"></a>Comentários

Para obter mais informações sobre a biblioteca padrão, consulte [usar biblioteca de tempo de execução](md-mt-ld-use-run-time-library.md).

Você pode usar o **/zl** para compilar arquivos. obj que você planeja colocar em uma biblioteca. Embora a omissão do nome da biblioteca Economize apenas uma pequena quantidade de espaço para um único arquivo. obj, o espaço total economizado é significativo em uma biblioteca que contém muitos módulos de objeto.

Essa opção é uma opção avançada. Definir essa opção remove determinados suporte à biblioteca de tempo de execução C que podem ser exigidos pelo seu aplicativo, resultando em erros de tempo de vinculação se seu aplicativo depende desse suporte. Se você usar essa opção, deverá fornecer os componentes necessários de alguma outra maneira.

Use [/NODEFAULTLIB (ignorar bibliotecas)](nodefaultlib-ignore-libraries.md). para direcionar o vinculador para ignorar referências de biblioteca em todos os arquivos. obj.

Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

Ao compilar com **/zl**, `_VC_NODEFAULTLIB` é definido.  Por exemplo:

```cpp
// vc_nodefaultlib.cpp
// compile with: /Zl
void Test() {
   #ifdef _VC_NODEFAULTLIB
      int i;
   #endif

   int i;   // C2086
}
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades **avançado** .

1. Modifique a propriedade **omitir nomes de biblioteca padrão** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitDefaultLibName%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
