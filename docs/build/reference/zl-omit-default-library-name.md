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
ms.openlocfilehash: 8a5aede89e2b37655b67144a9882f1de9b7a4bf8
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57414792"
---
# <a name="zl-omit-default-library-name"></a>/Zl (omitir nome da biblioteca padrão)

Omite o nome da biblioteca padrão C em tempo de execução do arquivo. obj. Por padrão, o compilador coloca o nome da biblioteca no arquivo .obj para direcionar o vinculador à biblioteca correta.

## <a name="syntax"></a>Sintaxe

```
/Zl
```

## <a name="remarks"></a>Comentários

Para obter mais informações sobre a biblioteca padrão, consulte [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).

Você pode usar **/Zl** para compilar os arquivos. obj que você planeja colocar em uma biblioteca. Embora a omitir o nome da biblioteca salva apenas uma pequena quantidade de espaço para um arquivo. obj único, o espaço total salvado é significativo em uma biblioteca que contém muitos módulos de objeto.

Essa opção é uma opção avançada. Essa opção remove determinado suporte de biblioteca de tempo de execução C que pode ser exigida pelo seu aplicativo, resultando em erros de tempo de vinculação, se seu aplicativo depende desse suporte. Se você usar essa opção, você deve fornecer os componentes necessários de alguma outra forma.

Use [/NODEFAULTLIB (ignorar bibliotecas)](../../build/reference/nodefaultlib-ignore-libraries.md). para direcionar o vinculador para ignorar as referências da biblioteca em todos os arquivos. obj.

Para obter mais informações, consulte [Recursos da biblioteca CRT](../../c-runtime-library/crt-library-features.md).

Ao compilar com **/Zl**, `_VC_NODEFAULTLIB` está definido.  Por exemplo:

```
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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **omitir os nomes de bibliotecas padrão** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitDefaultLibName%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
